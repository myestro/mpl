//-----------------------------------------------------------------------------
// boost mpl/identity/select2nd.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2000-01
// Aleksey Gurtovoy
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee, 
// provided that the above copyright notice appears in all copies and 
// that both the copyright notice and this permission notice appear in 
// supporting documentation. No representations are made about the 
// suitability of this software for any purpose. It is provided "as is" 
// without express or implied warranty.

#ifndef BOOST_MPL_IDENTITY_SELECT2ND_HPP
#define BOOST_MPL_IDENTITY_SELECT2ND_HPP

#include "boost/mpl/et.hpp"

namespace boost {
namespace mpl {

template<typename Pair>
struct select2nd
{
    typedef typename Pair::second type;
};

// limited forms of ET, just for now
template<>
struct select2nd<mpl::_1>
{
    template<typename U> struct apply
        : select2nd<U>
    {
    };
};

template<>
struct select2nd<mpl::placeholder>
{
    template<typename U> struct apply
        : select2nd<U>
    {
    };
};

} // namespace mpl
} // namespace boost 

#endif // BOOST_MPL_IDENTITY_SELECT2ND_HPP