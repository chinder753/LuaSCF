#include "Matrix.h"

#include <limits.h>
#include <stdint.h>

#include "lua.h"
#include "lauxlib.h"

#include "Array.h"
#include "ArrayType.h"

static int creat_matrix(lua_State *L){
    LUASCF_ARRAY_LEN_TYPE size[2], length;
    char value_type     = (char)luaL_checkinteger(L, 1);
    char storage_type   = (char)luaL_checkinteger(L, 2);
    size[0] = luaL_checkinteger(L, 3);
    size[1] = luaL_checkinteger(L, 4);
    length = size[0] * size[1];

    size_t nbytes = sizeof(VoidMatrix) + length * sizeof_array_type(value_type);
    VoidMatrix *array = (VoidMatrix *) lua_newuserdata(L, nbytes);
/*
|------------------------------------------------------------
| Value                                Address
|------------------------------------------------------------
| value_type                         |
| storage_type                       |
| len                                |
| size[0]                            |
| size[1]                            |
| ptr_values                         | &(array->ptr_values)
| values[0]                          | &(values[0]) = values = array->ptr_values = &(array->ptr_values) + 1
| ...                                |
| values[len-1]                      | &(values[len-1]) = array->ptr_values[len-1]
|------------------------------------------------------------
*/
    array->value_type = value_type;
    array->storage_type = storage_type;
    array->len = length;
    array->size[0] = size[0];
    array->size[1] = size[1];
    array->ptr_values = &(array->ptr_values) + 1;

    return 1;
}
