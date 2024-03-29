/// \file SFFT.cpp
/// \brief SFFT class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "SFFT.h"
#include <fftw3.h>
#include "math.h"

#ifdef SL_USE_OPENMP
    #include "omp.h"
#endif

fftwf_complex* SFFT::fft2D(float* inArray, unsigned int sizeX, unsigned int sizeY){

    fftwf_complex* out = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * unsigned(sizeX*sizeY));
    SFFT::fft2D(inArray, out, sizeX, sizeY);
    return out;
}

void SFFT::fft2D(float* in, fftwf_complex* out, unsigned int sizeX, unsigned int sizeY){


#ifdef SL_USE_OPENMP
    fftwf_plan_with_nthreads(omp_get_max_threads());
#endif

    fftwf_plan P = fftwf_plan_dft_r2c_2d(sizeX, sizeY, in, out, FFTW_ESTIMATE);
    fftwf_execute(P);
    fftwf_destroy_plan(P);

}

void SFFT::ifft2D(fftwf_complex* in, float* out, unsigned int sizeX, unsigned int sizeY){

#ifdef SL_USE_OPENMP
    fftwf_plan_with_nthreads(omp_get_max_threads());
#endif
    fftwf_plan P = fftwf_plan_dft_c2r_2d(sizeX, sizeY, in, out, FFTW_ESTIMATE);

    fftwf_execute(P);
    fftwf_destroy_plan(P);

}

float* SFFT::ifft2D(fftwf_complex* inArray, unsigned int sizeX, unsigned int sizeY){

    float* out = new float(sizeX*sizeY);
    SFFT::ifft2D(inArray, out, sizeX, sizeY);
    return out;
}

fftwf_complex* SFFT::fft3D(float* inArray, unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ){

    fftwf_complex* out = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * unsigned(sizeX*sizeY*sizeZ));
    fftwf_plan P = fftwf_plan_dft_r2c_3d(sizeX, sizeY, sizeZ, inArray, out, FFTW_ESTIMATE);

    fftwf_execute(P);
    fftwf_destroy_plan(P);

    return out;
}

void SFFT::fft3D(float* in, fftwf_complex* out, unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ){


#ifdef SL_USE_OPENMP
    fftwf_plan_with_nthreads(omp_get_max_threads());
#endif

    fftwf_plan P = fftwf_plan_dft_r2c_3d(sizeX, sizeY, sizeZ, in, out, FFTW_ESTIMATE);

    fftwf_execute(P);
    fftwf_destroy_plan(P);

}

void SFFT::ifft3D(fftwf_complex* in, float* out, unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ){

#ifdef SL_USE_OPENMP
    fftwf_plan_with_nthreads(omp_get_max_threads());
#endif
    fftwf_plan P = fftwf_plan_dft_c2r_3d(sizeX, sizeY, sizeZ, in, out, FFTW_ESTIMATE);

    fftwf_execute(P);
    fftwf_destroy_plan(P);

}

float *SFFT::ifft3D(fftwf_complex *inArray, unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ){

    float* out = new float[ sizeX*sizeY*sizeZ];
    SFFT::ifft3D(inArray, out, sizeX, sizeY, sizeZ);
    return out;

}

float* SFFT::module(fftwf_complex* inArray, unsigned int sizeX, unsigned int sizeY){

    float* out = new float(sizeX*sizeY);
    for (unsigned int i = 0 ; i < sizeX*sizeY ; i++){
        out[i] = sqrt( pow(inArray[i][0],2) + pow(inArray[i][1],2) );
    }
    return out;
}

float* SFFT::module(fftwf_complex* inArray, unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ){

    float* out = new float(sizeX*sizeY*sizeZ);
    for (unsigned int i = 0 ; i < sizeX*sizeY*sizeZ ; i++){
        out[i] = sqrt( pow(inArray[i][0],2) + pow(inArray[i][1],2) );
    }
    return out;
}
