cmake_minimum_required(VERSION 3.26)
project(LuaSCF C)

set(CMAKE_C_STANDARD 11)

include_directories(lib_C/exblas)
include_directories(lib_C/exmath)
include_directories(lib_C/fftw)
include_directories(lib_C/libcint)
include_directories(lib_C/blas)

include_directories(/usr/local/include)
link_directories(/root/exLib/fftw-3.3.10/build)

include_directories(/root/Lua/lua-5.4.6/src)
link_directories(/root/Lua/lua-5.4.6/src)

add_library( LuaSCF
        lib_C/exblas/exblas.c
        lib_C/exblas/exblas.h
        lib_C/exmath/exmath.c
        lib_C/exmath/exmath.h
        lib_C/fftw/interface_fftw.c
        lib_C/fftw/interface_fftw.h
        lib_C/libcint/interface_libcint.c
        lib_C/libcint/interface_libcint.h
        lib_C/array/Array.c
        lib_C/array/Array.h
        lib_C/array/ArrayType.h
        lib_C/array/Matrix.c
        lib_C/array/Matrix.h
)

target_link_libraries(LuaSCF fftw3)

add_executable(test
        test/test.c
)

target_link_libraries(test LuaSCF)


###################
#####  FFTW   #####
###################
#find_library(FFTW3 REQUIRED)
#if (FFTW3_FOUND)
#    include_directories(${FFTW3_INCLUDE_DIRS})
#    link_directories(${FFTW3_LIBRARY_DIRS})
#    target_link_libraries(LuaSCF fftw3)
#else (FFTW3_FOUND)
#    message(FATAL_ERROR "can't find FFTW3")
#endif (FFTW3_FOUND)
#####   END   #####

