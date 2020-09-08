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
#include "simage/SImageFilter.h"

/// \class SFFT
/// \brief Calculate FFT and inverse FFT on 2D or 3D images.
class SFFT_EXPORT SFFTConvolutionFilter : public SImageFilter {

public:
    SFFTConvolutionFilter();
    ~SFFTConvolutionFilter();

public:
    void setImage1(SImage* image);
    void setImage2(SImage* image);
    void run() override;

protected:
    SImage* m_image2;

};
