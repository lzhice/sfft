/// \file SFFTConvolutionFilter.cpp
/// \brief SFFTConvolutionFilter class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include <fftw3.h>

#include "SFFTConvolutionFilter.h"
#include "SFFT.h"
#include "score/SException.h"
#include "simage/SImageCast.h"

SFFTConvolutionFilter::SFFTConvolutionFilter() : SImageFilter(){
    m_processName = "SFFTConvolutionFilter";
    m_processPrecision = 32;
    m_processZ = true;
    m_processT = false;
    m_processC = false;
}

SFFTConvolutionFilter::~SFFTConvolutionFilter(){

}

void SFFTConvolutionFilter::setImage1(SImage* image){
    m_input = image;
}

void SFFTConvolutionFilter::setImage2(SImage* image){
    m_image2 = image;
}

void SFFTConvolutionFilter::run(){

    float* image1Buffer = SImageCast::toFloat(m_input)->getBuffer();
    float* image2Buffer = SImageCast::toFloat(m_image2)->getBuffer();
    unsigned int sx = m_input->getSizeX();
    unsigned int sy = m_input->getSizeY();
    unsigned int sz = m_input->getSizeZ();

    if ( m_image2->getSizeX() != sx || m_image2->getSizeY() != sy || m_image2->getSizeZ() != sz ){
        throw SException("SFFTConvolutionFilter: The two input images must be the same size");
    }

    if ( sz == 1){
        fftwf_complex* image1FFT = SFFT::fft2D(image1Buffer, sx, sy);
        fftwf_complex* image2FFT = SFFT::fft2D(image2Buffer, sx, sy);
        fftwf_complex* outputFFT = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * unsigned(sx*sy));
        for (unsigned int i = 0 ; i < sx*sy ; i++){
            outputFFT[i][0] = image1FFT[i][0] * image2FFT[i][0];
            outputFFT[i][1] = image1FFT[i][1] * image2FFT[i][1];
        }
        float* outBuffer = SFFT::ifft2D(outputFFT, sx, sy);
        m_output = new SImageFloat(outBuffer, sx, sy);
    }
    else{
        fftwf_complex* image1FFT = SFFT::fft3D(image1Buffer, sx, sy, sz);
        fftwf_complex* image2FFT = SFFT::fft3D(image2Buffer, sx, sy, sz);
        fftwf_complex* outputFFT = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * unsigned(sx*sy*sz));
        for (unsigned int i = 0 ; i < sx*sy*sz ; i++){
            outputFFT[i][0] = image1FFT[i][0] * image2FFT[i][0];
            outputFFT[i][1] = image1FFT[i][1] * image2FFT[i][1];
        }
        float* outBuffer = SFFT::ifft3D(outputFFT, sx, sy, sz);
        m_output = new SImageFloat(outBuffer, sx, sy, sz);
    }

}
