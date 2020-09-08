/// \file SFFT.h
/// \brief SFFT class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include <string>
#include <fftw3.h>

#include "sfftExport.h"

#include "simage/SImage.h"

/// \class SFFT
/// \brief Calculate FFT and inverse FFT on 2D or 3D images.
class SFFT_EXPORT SFFT {

public:
    static fftwf_complex* fft2D(float* inArray, unsigned int sizeX, unsigned int sizeY);
    static void fft2D(float* in, fftwf_complex* out, unsigned int sizeX, unsigned int sizeY);
    static float* ifft2D(fftwf_complex* inArray, unsigned int sizeX, unsigned int sizeY);
    static void ifft2D(fftwf_complex* in, float* out, unsigned int sizeX, unsigned int sizeY);

public:
    static fftwf_complex* fft3D(float* inArray, unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ);
    static void fft3D(float* in, fftwf_complex* out, unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ);
    static float* ifft3D(fftwf_complex* inArray, unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ);
    static void ifft3D(fftwf_complex* in, float* out, unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ);

public:
    static float* module(fftwf_complex* inArray, unsigned int sizeX, unsigned int sizeY);
    static float* module(fftwf_complex* inArray, unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ);
};
