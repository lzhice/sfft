############################################################
#
# $Id$
#
# Copyright (c) sfft 2020
#
# AUTHOR:
# Sylvain Prigent
# 

## #################################################################
## Doxygen
## #################################################################

find_package(Doxygen QUIET)
if(${DOXYGEN_FOUND})
  set(sfft_USE_DOXYGEN 1)
endif(${DOXYGEN_FOUND})

if(${sfft_USE_OPENMP})
  find_package(OpenMP REQUIRED)
endif(${sfft_USE_OPENMP})  

## #################################################################
## libfftw3
## #################################################################

find_package (FFTW REQUIRED)
if (FFTW_FOUND)
  set (SL_INCLUDE_DIRS ${SL_INCLUDE_DIRS} ${FFTW_INCLUDE_DIR})
  set (SL_LIBRARIES ${SL_LIBRARIES} ${FFTW_LIBRARIES})
  set (SL_LIBRARIES ${SL_LIBRARIES} ${FFTW3F_THREAD_LIBRARIES})
  message(STATUS "FFTW3F found")
else (FFTW_FOUND)
  message(STATUS "FFTW3F NOT found.")
  message (FATAL_ERROR "You need fftw3f to compile this program. Please install libs and developpement headers")
endif (FFTW_FOUND)

## ##################################################################
## score
## ##################################################################
find_package (score REQUIRED)
if ( score_FOUND )
  message(STATUS "Using score")
  set (SL_INCLUDE_DIRS ${SL_INCLUDE_DIRS} ${score_INCLUDE_DIRS})
  set (SL_LIBRARY_DIRS ${SL_LIBRARY_DIRS} ${score_LIBRARY_DIRS})
  set (SL_LIBRARIES ${SL_LIBRARIES} ${score_LIBRARIES})
  message(STATUS "score_LIBRARY_DIRS=" ${score_LIBRARY_DIRS}) 
  set(simage_HAVE_score 1)
else( score_FOUND )
  message(STATUS "NOT Using score")
endif( score_FOUND )

## ##################################################################
## simage
## ##################################################################
find_package (simage REQUIRED)
if ( simage_FOUND )
  message(STATUS "Using simage")
  set (SL_INCLUDE_DIRS ${SL_INCLUDE_DIRS} ${simage_INCLUDE_DIRS})
  set (SL_LIBRARY_DIRS ${SL_LIBRARY_DIRS} ${simage_LIBRARY_DIRS})
  set (SL_LIBRARIES ${SL_LIBRARIES} ${simage_LIBRARIES})
  message(STATUS "simage_LIBRARY_DIRS=" ${simage_LIBRARY_DIRS}) 
  set(simage_HAVE_simage 1)
else( simage_FOUND )
  message(STATUS "NOT Using simage")
endif( simage_FOUND )

## #################################################################
## definitions
## #################################################################
add_definitions (${SL_DEFINITIONS})
include_directories (${SL_INCLUDE_DIRS})
link_directories(${SL_INCLUDE_DIRS})
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SL_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SL_CXX_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set (SL_INCLUDE_DIRS ${SL_INCLUDE_DIRS} CACHE STRING "include directories for spartion dependancies")
set (SL_LIBRARIES ${SL_LIBRARIES} CACHE STRING "spartion required and optional 3rd party libraries")
set (SL_DEFINITIONS ${SL_DEFINITIONS} CACHE STRING "SL_USE_XXX defines")
set (SL_C_FLAGS ${SL_C_FLAGS}  CACHE STRING "c flags for cimg")
set (SL_CXX_FLAGS ${SL_CXX_FLAGS} CACHE STRING "c++ flags for cimg")