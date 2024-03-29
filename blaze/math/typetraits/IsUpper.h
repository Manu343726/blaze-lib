//=================================================================================================
/*!
//  \file blaze/math/typetraits/IsUpper.h
//  \brief Header file for the IsUpper type trait
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

#ifndef _BLAZE_MATH_TYPETRAITS_ISUPPER_H_
#define _BLAZE_MATH_TYPETRAITS_ISUPPER_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/typetraits/IsDiagonal.h>


namespace blaze {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Compile time check for upper triangular matrices.
// \ingroup math_type_traits
//
// This type trait tests whether or not the given template parameter is an upper triangular matrix
// type (i.e. a matrix type that is guaranteed to be upper triangular at compile time). In case
// the type is an upper triangular matrix type, the \a value member enumeration is set to 1, the
// nested type definition \a Type is \a TrueType, and the class derives from \a TrueType. Otherwise
// \a value is set to 0, \a Type is \a FalseType, and the class derives from \a FalseType.

   \code
   using blaze::rowMajor;

   typedef blaze::StaticMatrix<double,3UL,3UL,rowMajor>  StaticMatrixType;
   typedef blaze::DynamicMatrix<float,rowMajor>          DynamicMatrixType;
   typedef blaze::CompressedMatrix<int,rowMajor>         CompressedMatrixType;

   typedef blaze::UpperMatrix<StaticMatrixType>      UpperStaticType;
   typedef blaze::UpperMatrix<DynamicMatrixType>     UpperDynamicType;
   typedef blaze::UpperMatrix<CompressedMatrixType>  UpperCompressedType;

   blaze::IsUpper< UpperStaticType >::value         // Evaluates to 1
   blaze::IsUpper< const UpperDynamicType >::Type   // Results in TrueType
   blaze::IsUpper< volatile UpperCompressedType >   // Is derived from TrueType
   blaze::IsUpper< StaticMatrixType >::value        // Evaluates to 0
   blaze::IsUpper< const DynamicMatrixType >::Type  // Results in FalseType
   blaze::IsUpper< volatile CompressedMatrixType >  // Is derived from FalseType
   \endcode
*/
template< typename T >
struct IsUpper : public IsDiagonal<T>::Type
{
 public:
   //**********************************************************************************************
   /*! \cond BLAZE_INTERNAL */
   enum { value = IsDiagonal<T>::value };
   typedef typename IsDiagonal<T>::Type  Type;
   /*! \endcond */
   //**********************************************************************************************
};
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Specialization of the IsUpper type trait for const types.
// \ingroup math_type_traits
*/
template< typename T >
struct IsUpper< const T > : public IsUpper<T>::Type
{
 public:
   //**********************************************************************************************
   enum { value = IsUpper<T>::value };
   typedef typename IsUpper<T>::Type  Type;
   //**********************************************************************************************
};
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Specialization of the IsUpper type trait for volatile types.
// \ingroup math_type_traits
*/
template< typename T >
struct IsUpper< volatile T > : public IsUpper<T>::Type
{
 public:
   //**********************************************************************************************
   enum { value = IsUpper<T>::value };
   typedef typename IsUpper<T>::Type  Type;
   //**********************************************************************************************
};
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Specialization of the IsUpper type trait for cv qualified types.
// \ingroup math_type_traits
*/
template< typename T >
struct IsUpper< const volatile T > : public IsUpper<T>::Type
{
 public:
   //**********************************************************************************************
   enum { value = IsUpper<T>::value };
   typedef typename IsUpper<T>::Type  Type;
   //**********************************************************************************************
};
/*! \endcond */
//*************************************************************************************************

} // namespace blaze

#endif
