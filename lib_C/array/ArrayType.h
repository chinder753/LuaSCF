#ifndef LUASCF_ARRAYTYPE_H
#define LUASCF_ARRAYTYPE_H

#include <complex.h>
#include <stdint.h>

#define float32     float
#define float64     double
#define float128    long double
#define complex64   float _Complex
#define complex128  double _Complex
#define complex256  long double _Complex

#define LUASCF_ARRAY_LEN_TYPE           uint64_t


#define LUASCF_ARRAY_STOR_FULL          0x00
#define LUASCF_ARRAY_STOR_PACKED        0x01
#define LUASCF_ARRAY_STOR_BAND          0x02
#define LUASCF_ARRAY_STOR_RFP           0x03



#define LUASCF_ARRAY_TYPE_UINT8         0x00
#define LUASCF_ARRAY_TYPE_UINT16        0x01
#define LUASCF_ARRAY_TYPE_UINT32        0x02
#define LUASCF_ARRAY_TYPE_UINT64        0x03

#define LUASCF_ARRAY_TYPE_INT8          0x10
#define LUASCF_ARRAY_TYPE_INT16         0x11
#define LUASCF_ARRAY_TYPE_INT32         0x12
#define LUASCF_ARRAY_TYPE_INT64         0x13

#define LUASCF_ARRAY_TYPE_FLOAT32       0x20
#define LUASCF_ARRAY_TYPE_FLOAT64       0x21
#define LUASCF_ARRAY_TYPE_FLOAT128      0x22

#define LUASCF_ARRAY_TYPE_COMPLEX64     0x30
#define LUASCF_ARRAY_TYPE_COMPLEX128    0x31
#define LUASCF_ARRAY_TYPE_COMPLEX256    0x32



//*******************//
// ARRAY TYPE DEFINE //
//*******************//

typedef struct VoidArray{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    void * ptr_values;
}VoidArray;

typedef struct Uint8Array{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    uint8_t * ptr_values;
} Uint8Array;

typedef struct Uint16Array{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    uint16_t * ptr_values;
} Uint16Array;

typedef struct Uint32Array{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    uint32_t * ptr_values;
} Uint32Array;

typedef struct Uint64Array{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    uint64_t * ptr_values;
} Uint64Array;

typedef struct Int8Array{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    int8_t * ptr_values;
} Int8Array;

typedef struct Int16Array{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    int16_t * ptr_values;
} Int16Array;

typedef struct Int32Array{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    int32_t * ptr_values;
} Int32Array;

typedef struct Int64Array{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    int64_t * ptr_values;
} Int64Array;

typedef struct Float32Array{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    float32 * ptr_values;
} Float32Array;

typedef struct Float64Array{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    float64 * ptr_values;
} Float64Array;

typedef struct Float128Array{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    float128 * ptr_values;
} Float128Array;

typedef struct Complex64Array{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    complex64 * ptr_values;
} Complex64Array;

typedef struct Complex128Array{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    complex128 * ptr_values;
} Complex128Array;

typedef struct Complex256Array{
    char dim;
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE * ptr_size;
    complex256 * ptr_values;
} Complex256Array;

//*******************//
//        END        //
//*******************//



//********************//
// MATRIX TYPE DEFINE //
//********************//
typedef struct VoidMatrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    void * ptr_values;
}VoidMatrix;

typedef struct Uint8Matrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    uint8_t * ptr_values;
} Uint8Matrix;

typedef struct Uint16Matrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    uint16_t * ptr_values;
} Uint16Matrix;

typedef struct Uint32Matrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    uint32_t * ptr_values;
} Uint32Matrix;

typedef struct Uint64Matrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    uint64_t * ptr_values;
} Uint64Matrix;

typedef struct Int8Matrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    int8_t * ptr_values;
} Int8Matrix;

typedef struct Int16Matrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    int16_t * ptr_values;
} Int16Matrix;

typedef struct Int32Matrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    int32_t * ptr_values;
} Int32Matrix;

typedef struct Int64Matrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    int64_t * ptr_values;
} Int64Matrix;

typedef struct Float32Matrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    float32 * ptr_values;
} Float32Matrix;

typedef struct Float64Matrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    float64 * ptr_values;
} Float64Matrix;

typedef struct Float128Matrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    float128 * ptr_values;
} Float128Matrix;

typedef struct Complex64Matrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    complex64 * ptr_values;
} Complex64Matrix;

typedef struct Complex128Matrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    complex128 * ptr_values;
} Complex128Matrix;

typedef struct Complex256Matrix{
    char value_type;
    char storage_type;
    LUASCF_ARRAY_LEN_TYPE len;
    LUASCF_ARRAY_LEN_TYPE size[2];
    complex256 * ptr_values;
} Complex256Matrix;

//********************//
//         END        //
//********************//


#endif //LUASCF_ARRAYTYPE_H
