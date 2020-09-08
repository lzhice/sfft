/// \file SFFTShortcuts.h
/// \brief SFFTShortcuts class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include <string>
#include <chrono>

#include "SFFT.h"
#include "SFFTConvolutionFilter.h"

/// \namespace SImg
/// \brief Shortut function to call modules functionalities
namespace SImg{

    SImage* fftModule(SImage* image);
    SImage* fftConvolve(SImage* image1, SImage* image2);
}
