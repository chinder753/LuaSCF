#include "Array.h"

#include <limits.h>
#include "lua.h"
#include "lauxlib.h"

#include "ArrayType.h"



size_t sizeof_array_type(char value_type){
    switch (value_type) {
        case LUASCF_ARRAY_TYPE_UINT8:       return sizeof(uint8_t);
        case LUASCF_ARRAY_TYPE_UINT16:      return sizeof(uint16_t);
        case LUASCF_ARRAY_TYPE_UINT32:      return sizeof(uint32_t);
        case LUASCF_ARRAY_TYPE_UINT64:      return sizeof(uint64_t);
        case LUASCF_ARRAY_TYPE_INT8:        return sizeof(int8_t);
        case LUASCF_ARRAY_TYPE_INT16:       return sizeof(int16_t);
        case LUASCF_ARRAY_TYPE_INT32:       return sizeof(int32_t);
        case LUASCF_ARRAY_TYPE_INT64:       return sizeof(int64_t);
        case LUASCF_ARRAY_TYPE_FLOAT32:     return sizeof(float32);
        case LUASCF_ARRAY_TYPE_FLOAT64:     return sizeof(float64);
        case LUASCF_ARRAY_TYPE_FLOAT128:    return sizeof(float128);
        case LUASCF_ARRAY_TYPE_COMPLEX64:   return sizeof(complex64);
        case LUASCF_ARRAY_TYPE_COMPLEX128:  return sizeof(complex128);
        case LUASCF_ARRAY_TYPE_COMPLEX256:  return sizeof(complex256);
        default:                            return 0;
    }
}



static int creat_array(lua_State *L){
    char value_type     = (char)luaL_checkinteger(L, 1);
    char storage_type   = (char)luaL_checkinteger(L, 2);
    char dim            = (char)luaL_checkinteger(L, 3);
    LUASCF_ARRAY_LEN_TYPE size[dim];

    LUASCF_ARRAY_LEN_TYPE length = 0;
    for(int i=0; i<dim; i++){
        size[i] = luaL_checkinteger(L, i+4);
        length *= size[i];
    }


    size_t nbytes = sizeof(VoidArray) + dim * sizeof(intptr_t);
    nbytes += length * sizeof_array_type(value_type);

/*
|------------------------------------------------------------
| Value                                Address
|------------------------------------------------------------
| dim                                |
| value_type                         |
| storage_type                       |
| len                                |
| ptr_size = size = &(size[0])       | &(array->ptr_size)
| ptr_values = values = &(values[0]) | &(array->ptr_values)
| size[0]                            | &(size[0]) = size = array->ptr_size = &(array->ptr_values) + 1
| ...                                |
| size[dim-1]                        | &(size[dim-1]) = &(array->ptr_size[dim-1])
| values[0]                          | &(values[0]) = values = array->ptr_values = &(array->ptr_size[dim])
| ...                                |
| values[len-1]                      | &(values[len-1]) = array->ptr_values[len-1]
|------------------------------------------------------------
*/
    VoidArray *array = (VoidArray *) lua_newuserdata(L, nbytes);
    array->dim = dim;
    array->value_type = value_type;
    array->storage_type = storage_type;
    array->len = length;
    array->ptr_size = (LUASCF_ARRAY_LEN_TYPE *)(&(array->ptr_values) + 1 );
    array->ptr_values = &(array->ptr_size[dim]);
    for(int i=0; i<dim; i++){
        array->ptr_size[i] = size[i];
    }

    return 1;
}
