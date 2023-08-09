#include "interface_fftw.h"

#include <fftw3.h>
#include <stdint.h>


#define fft_1d(N, IN, OUT, SIGN, FLAG)                                              \
    _Generic((IN),                                                                  \
          double * :                                                                \
            _Generic((OUT),                                                         \
                  double *       : fftw_plan_r2r_1d(N, IN, OUT, SIGN, FLAG)         \
                , fftw_complex * : fftw_plan_dft_r2c_1d(N, IN, OUT, FLAG)           \
            )                                                                       \
        , fftw_complex * :                                                          \
            _Generic((OUT),                                                         \
                  double *       : fftw_plan_dft_c2r_1d(N, IN, OUT, FLAG)           \
                , fftw_complex * : fftw_plan_dft_1d(N, IN, OUT, SIGN, FLAG)         \
            )                                                                       \
)

#define fft_2d(N, N2, IN, OUT, SIGN, FLAG)                                          \
    _Generic((IN),                                                                  \
          double * :                                                                \
            _Generic((OUT),                                                         \
                  double *       : fftw_plan_r2r_2d(N, N2, IN, OUT, SIGN, FLAG)     \
                , fftw_complex * : fftw_plan_dft_r2c_2d(N, N2, IN, OUT, FLAG)       \
            )                                                                       \
        , fftw_complex * :                                                          \
            _Generic((OUT),                                                         \
                  double *       : fftw_plan_dft_c2r_2d(N, N2, IN, OUT, FLAG)       \
                , fftw_complex * : fftw_plan_dft_2d(N, N2, IN, OUT, SIGN, FLAG)     \
            )                                                                       \
)

#define fft_3d(N, N2, N3, IN, OUT, SIGN, FLAG)                                      \
    _Generic((IN),                                                                  \
          double * :                                                                \
            _Generic((OUT),                                                         \
                  double *       : fftw_plan_r2r_3d(N, N2, N3, IN, OUT, SIGN, FLAG) \
                , fftw_complex * : fftw_plan_dft_r2c_3d(N, N2, N3, IN, OUT, FLAG)   \
            )                                                                       \
        , fftw_complex * :                                                          \
            _Generic((OUT),                                                         \
                  double *       : fftw_plan_dft_c2r_3d(N, N2, N3, IN, OUT, FLAG)   \
                , fftw_complex * : fftw_plan_dft_3d(N, N2, N3, IN, OUT, SIGN, FLAG) \
            )                                                                       \
)

#define fft_nd(RANK, N, IN, OUT, SIGN, FLAG)                                        \
    _Generic((IN),                                                                  \
          double * :                                                                \
            _Generic((OUT),                                                         \
                  double *       : fftw_plan_r2r(RANK, N, IN, OUT, SIGN, FLAG)      \
                , fftw_complex * : fftw_plan_dft_r2c(RANK, N, IN, OUT, FLAG)        \
            )                                                                       \
        , fftw_complex * :                                                          \
            _Generic((OUT),                                                         \
                  double *       : fftw_plan_dft_c2r(RANK, N, IN, OUT, FLAG)        \
                , fftw_complex * : fftw_plan_dft(RANK, N, IN, OUT, SIGN, FLAG)      \
            )                                                                       \
)
