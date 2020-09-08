/// \file SFFTShortcuts.cpp
/// \brief SFFTShortcuts class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020


#include "SFFTShortcuts.h"
#include "simage/SImageCast.h"
#include "SFFT.h"

namespace SImg {

SImage* fftModule(SImage* image){
    if (image->getSizeZ() == 1){
        SImageFloat* imageFloat = SImageCast::toFloat(image);
        fftwf_complex* imagefft = SFFT::fft2D(imageFloat->getBuffer(), imageFloat->getSizeX(), imageFloat->getSizeY());
        float* moduleBuffer = SFFT::module(imagefft, imageFloat->getSizeX(), imageFloat->getSizeY());
        fftwf_free(imagefft);
        return new SImageFloat(moduleBuffer, imageFloat->getSizeX(), imageFloat->getSizeY());
    }
    else{
        SImageFloat* imageFloat = SImageCast::toFloat(image);
        fftwf_complex* imagefft = SFFT::fft3D(imageFloat->getBuffer(), imageFloat->getSizeX(), imageFloat->getSizeY(), imageFloat->getSizeZ());
        float* moduleBuffer = SFFT::module(imagefft, imageFloat->getSizeX(), imageFloat->getSizeY(), imageFloat->getSizeZ());
        fftwf_free(imagefft);
        return new SImageFloat(moduleBuffer, imageFloat->getSizeX(), imageFloat->getSizeY(), imageFloat->getSizeZ());
    }
}

SImage* fftConvolve(SImage* image1, SImage* image2){
    SFFTConvolutionFilter filter;
    filter.setImage1(image1);
    filter.setImage2(image2);
    filter.run();
    return filter.getOutput();
}

}
