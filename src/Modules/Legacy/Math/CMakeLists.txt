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


# CMakeLists.txt for Dataflow/Modules/Math

SET(Modules_Legacy_Math_SRCS
  #CreateScalarMatrix.cc
  AddLinkedNodesToLinearSystem.cc
  AddKnownsToLinearSystem.cc
  #RemoveZerosFromMatrix.cc
  #SortMatrix.cc
  #RemoveZeroRowsAndColumns.cc
  #AppendMatrix.cc
  BuildNoiseColumnMatrix.cc
  #CreateGeometricTransform.cc
  #ChooseMatrix.cc
  ComputeSVD.cc
  ConvertMatrixType.cc
  CollectMatrices.cc
  ReportColumnMatrixMisfit.cc
  #EvaluateLinAlgBinary.cc
  #EvaluateLinAlgUnary.cc
  EvaluateLinAlgGeneral.cc
  #ReportRootMeanSquareError.cc
  #GetColumnOrRowFromMatrix.cc
  SolveMinNormLeastSqSystem.cc
  #SolveLinearSystem.cc
  #GetSubmatrix.cc
  SetSubmatrix.cc
  #ConvertMaskVectorToMappingMatrix.cc
  #ConvertMappingMatrixToMaskVector.cc
  #CreateMatrix.cc
  #ReportMatrixColumnMeasure.cc
  #ReportMatrixInfo.cc
  #ReportMatrixRowMeasure.cc
  #ReorderMatrixByCuthillMcKee.cc
  #ReorderMatrixByReverseCuthillMcKee.cc
  #ResizeMatrix.cc
  SelectSubMatrix.cc
)

SET(Modules_Legacy_Math_HEADERS
  #CreateScalarMatrix.h
  AddLinkedNodesToLinearSystem.h
  AddKnownsToLinearSystem.h
  #RemoveZerosFromMatrix.h
  #SortMatrix.h
  #RemoveZeroRowsAndColumns.h
  #AppendMatrix.h
  BuildNoiseColumnMatrix.h
  #CreateGeometricTransform.h
  #ChooseMatrix.h
  ComputeSVD.h
  ConvertMatrixType.h
  CollectMatrices.h
  ReportColumnMatrixMisfit.h
  #EvaluateLinAlgBinary.h
  #EvaluateLinAlgUnary.h
  EvaluateLinAlgGeneral.h
  #ReportRootMeanSquareError.h
  #GetColumnOrRowFromMatrix.h
  SolveMinNormLeastSqSystem.h
  #SolveLinearSystem.h
  #GetSubmatrix.h
  SetSubmatrix.h
  #ConvertMaskVectorToMappingMatrix.h
  #ConvertMappingMatrixToMaskVector.h
  #CreateMatrix.h
  #ReportMatrixColumnMeasure.h
  #ReportMatrixInfo.h
  #ReportMatrixRowMeasure.h
  #ReorderMatrixByCuthillMcKee.h
  #ReorderMatrixByReverseCuthillMcKee.h
  #ResizeMatrix.h
  SelectSubMatrix.h
  share.h
)

SCIRUN_ADD_LIBRARY(Modules_Legacy_Math ${Modules_Legacy_Math_HEADERS} ${Modules_Legacy_Math_SRCS})

TARGET_LINK_LIBRARIES(Modules_Legacy_Math
  Core_Datatypes
  Core_Math
  Algorithms_Math
  Core_Algorithms_Legacy_FiniteElements
  Core_Parser
  #Core_Persistent
  #Core_Thread
  #Core_Utils
  Dataflow_Network
  #${TK_LIBRARY}
  #${GL_LIBRARY}
  #${M_LIBRARY}
  #${PETSC_UNI_LIBRARY}
  #${SCI_TEEM_LIBRARY}
)

IF(BUILD_SHARED_LIBS)
  ADD_DEFINITIONS(-DBUILD_Modules_Legacy_Math)
ENDIF(BUILD_SHARED_LIBS)
