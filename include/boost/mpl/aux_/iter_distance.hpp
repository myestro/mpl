//-----------------------------------------------------------------------------
// boost mpl/aux_/iter_distance.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002
// Aleksey Gurtovoy
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee, 
// provided that the above copyright notice appears in all copies and 
// that both the copyright notice and this permission notice appear in 
// supporting documentation. No representations are made about the 
// suitability of this software for any purpose. It is provided "as is" 
// without express or implied warranty.

#ifndef BOOST_MPL_AUX_ITER_DISTANCE_HPP_INCLUDED
#define BOOST_MPL_AUX_ITER_DISTANCE_HPP_INCLUDED

#include "boost/mpl/aux_/msvc_workarounds.hpp"
#include "boost/config.hpp"

namespace boost {
namespace mpl {
namespace aux {

#if defined(BOOST_MSVC) && (BOOST_MSVC < 1300)

BOOST_MPL_AUX_MSVC_DEPENDENT_TEMPLATE_WRAPPER_DEF(msvc_distance, distance_, 1)

template<
      typename Iterator
    , typename Other
    > 
struct iter_distance
    : msvc_distance<Iterator>::template result_<Other>
{
};

#else

template<
      typename Iterator
    , typename Other
    > 
struct iter_distance
    : Iterator::template distance_<Other>
{
};

#endif

} // namespace aux
} // namespace mpl
} // namespace boost

#endif // BOOST_MPL_AUX_ITER_DISTANCE_HPP_INCLUDED