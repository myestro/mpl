
#ifndef BOOST_MPL_DIVIDES_HPP_INCLUDED
#define BOOST_MPL_DIVIDES_HPP_INCLUDED

// + file: boost/mpl/divides.hpp
// + last modified: 25/feb/03

// Copyright (c) 2000-03
// Aleksey Gurtovoy
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee, 
// provided that the above copyright notice appears in all copies and 
// that both the copyright notice and this permission notice appear in 
// supporting documentation. No representations are made about the 
// suitability of this software for any purpose. It is provided "as is" 
// without express or implied warranty.
//
// See http://www.boost.org/libs/mpl for documentation.

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/aux_/typeof.hpp>
#include <boost/mpl/aux_/value_wknd.hpp>
#include <boost/mpl/aux_/na_spec.hpp>
#include <boost/mpl/aux_/lambda_support.hpp>
#include <boost/mpl/aux_/config/eti.hpp>
#include <boost/config.hpp>

namespace boost {
namespace mpl {

template<
      typename T, T N1, T N2, T N3 = 1, T N4 = 1, T N5 = 1
    >
struct divides_c
{
    BOOST_STATIC_CONSTANT(T, value = (N1 / N2 / N3 / N4 / N5));
#if !defined(__BORLANDC__)
    typedef integral_c<T,value> type;
#else
    typedef integral_c<T,(N1 / N2 / N3 / N4 / N5)> type;
#endif
};

#if defined(BOOST_MPL_CFG_MSVC_ETI_BUG)
template<>
struct divides_c<long,0,0,0,0,0>
{
};
#endif

template<
      typename BOOST_MPL_AUX_NA_PARAM(T1)
    , typename BOOST_MPL_AUX_NA_PARAM(T2)
    , typename T3 = integral_c<int,1>
    , typename T4 = integral_c<int,1>
    , typename T5 = integral_c<int,1>
    >
struct divides
    : divides_c<
          BOOST_MPL_AUX_TYPEOF(T1,
             T1::value / T2::value / T3::value / T4::value / T5::value
            )
        , BOOST_MPL_AUX_MSVC_VALUE_WKND(T1)::value
        , BOOST_MPL_AUX_MSVC_VALUE_WKND(T2)::value
        , BOOST_MPL_AUX_MSVC_VALUE_WKND(T3)::value
        , BOOST_MPL_AUX_MSVC_VALUE_WKND(T4)::value
        , BOOST_MPL_AUX_MSVC_VALUE_WKND(T5)::value
        >
{
    BOOST_MPL_AUX_LAMBDA_SUPPORT(5, divides, (T1,T2,T3,T4,T5))
};

BOOST_MPL_AUX_NA_SPEC2(2,5,divides)

} // namespace mpl
} // namespace boost

#endif // BOOST_MPL_DIVIDES_HPP_INCLUDED