//=================================================================================================
/*!
//  \file blazetest/mathtest/MatchAdaptor.h
//  \brief Header file for the MatchAdaptor type trait
//
//  Copyright (C) 2013 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================

#ifndef _BLAZETEST_MATHTEST_MATCHADAPTOR_H_
#define _BLAZETEST_MATHTEST_MATCHADAPTOR_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/adaptors/Forward.h>
#include <blaze/math/constraints/Matrix.h>
#include <blaze/math/typetraits/IsDiagonal.h>
#include <blaze/math/typetraits/IsLower.h>
#include <blaze/math/typetraits/IsSymmetric.h>
#include <blaze/math/typetraits/IsUpper.h>
#include <blaze/math/typetraits/RemoveAdaptor.h>
#include <blaze/util/mpl/If.h>


namespace blazetest {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================


//*************************************************************************************************
/*!\brief Matches the adaptor of two matrix types.
//
// The MatchAdaptor type trait uses the same matrix adapter on the given type \a T2 as is used
// on the type \a T1: In case \a T1 has an adaptor (SymmetricMatrix, LowerMatrix, UpperMatrix,
// DiagonalMatrix, ...) the same adaptor is added to \a T2. Note that this type trait only works
// for matrix types. The attempt to instantiate it with non-matrix types results in a compile
// time error.
*/
template< typename T1    // The adapted type
        , typename T2 >  // The type to be adapted
struct MatchAdaptor
{
 private:
   //**********************************************************************************************
   /*! \cond BLAZE_INTERNAL */
   typedef typename blaze::RemoveAdaptor<T2>::Type  Tmp;
   /*! \endcond */
   //**********************************************************************************************

 public:
   //**********************************************************************************************
   /*! \cond BLAZE_INTERNAL */
   typedef typename blaze::If< blaze::IsSymmetric<T1>
                             , blaze::SymmetricMatrix<Tmp>
                             , typename blaze::If< blaze::IsDiagonal<T1>
                                                 , blaze::DiagonalMatrix<Tmp>
                                                 , typename blaze::If< blaze::IsLower<T1>
                                                                     , blaze::LowerMatrix<Tmp>
                                                                     , typename blaze::If< blaze::IsUpper<T1>
                                                                                         , blaze::UpperMatrix<Tmp>
                                                                                         , T2
                                                                                         >::Type
                                                                     >::Type
                                                 >::Type
                             >::Type  Type;
   /*! \endcond */
   //**********************************************************************************************

 private:
   //**Compile time checks*************************************************************************
   /*! \cond BLAZE_INTERNAL */
   BLAZE_CONSTRAINT_MUST_BE_MATRIX_TYPE( T1 );
   BLAZE_CONSTRAINT_MUST_BE_MATRIX_TYPE( T2 );
   /*! \endcond */
   //**********************************************************************************************
};
//*************************************************************************************************

} // namespace blazetest

#endif
