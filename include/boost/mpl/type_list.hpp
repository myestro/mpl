//-----------------------------------------------------------------------------
// boost mpl/type_list.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2000-02
// Aleksey Gurtovoy
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee, 
// provided that the above copyright notice appears in all copies and 
// that both the copyright notice and this permission notice appear in 
// supporting documentation. No representations are made about the 
// suitability of this software for any purpose. It is provided "as is" 
// without express or implied warranty.

#ifndef BOOST_MPL_TYPE_LIST_HPP_INCLUDED
#define BOOST_MPL_TYPE_LIST_HPP_INCLUDED

#include "boost/mpl/list/preprocessor.hpp"
#include "boost/mpl/list/traits.hpp"
#include "boost/mpl/list/factory.hpp"
#include "boost/mpl/list/algorithm.hpp"
#include "boost/mpl/null.hpp"

namespace boost {
namespace mpl {

struct type_list_tag;

template<>
struct list_traits<type_list_tag>
    : mpl::basic_list_traits<type_list_tag>
{
    typedef mpl::null_argument null_argument;
};


template< BOOST_MPL_LIST_DEFAULT_PARAMETERS(typename T, mpl::null_argument) >
struct type_list
    : mpl::list_factory< type_list_tag, BOOST_MPL_LIST_PARAMETERS(T) >::type
{
    typedef typename mpl::list_factory<
          type_list_tag
        , BOOST_MPL_LIST_PARAMETERS(T)
        >::type type;
};

} // namespace mpl
} // namespace boost 

#endif // BOOST_MPL_TYPE_LIST_HPP_INCLUDED