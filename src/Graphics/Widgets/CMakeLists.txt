#
#  For more information, please see: http://software.sci.utah.edu
#
#  The MIT License
#
#  Copyright (c) 2020 Scientific Computing and Imaging Institute,
#  University of Utah.
#
#  Permission is hereby granted, free of charge, to any person obtaining a
#  copy of this software and associated documentation files (the "Software"),
#  to deal in the Software without restriction, including without limitation
#  the rights to use, copy, modify, merge, publish, distribute, sublicense,
#  and/or sell copies of the Software, and to permit persons to whom the
#  Software is furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included
#  in all copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
#  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
#  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
#  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
#  DEALINGS IN THE SOFTWARE.
#


SET(Graphics_Widgets_SRCS
  Widget.cc
  WidgetFactory.cc
  BoundingBoxWidget.cc
  SphereWidget.cc
  CylinderWidget.cc
  ConeWidget.cc
  DiskWidget.cc
  ArrowWidget.cc
  GlyphFactory.cc
)

SET(Graphics_Widgets_HEADERS
  Widget.h
  WidgetFactory.h
  BoundingBoxWidget.h
  SphereWidget.h
  CylinderWidget.h
  ConeWidget.h
  ArrowWidget.h
  GlyphFactory.h
  WidgetParameters.h
  WidgetBuilders.h
  share.h
)

SCIRUN_ADD_LIBRARY(Graphics_Widgets
  ${Graphics_Widgets_HEADERS}
  ${Graphics_Widgets_SRCS}
)

TARGET_LINK_LIBRARIES(Graphics_Widgets
  Core_Math
  Core_Datatypes
  Core_Geometry_Primitives
  Graphics_Glyphs
  Graphics_Datatypes
  ${OPENGL_LIBRARIES}
  ${SCI_BOOST_LIBRARY}
)

IF(BUILD_SHARED_LIBS)
	ADD_DEFINITIONS(-DBUILD_Graphics_Widgets)
ENDIF(BUILD_SHARED_LIBS)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

SCIRUN_ADD_TEST_DIR(Tests)
