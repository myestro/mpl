//-----------------------------------------------------------------------------
// boost mpl/test/count_if.cpp source file
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

#include "boost/mpl/count_if.hpp"
#include "boost/mpl/type_list.hpp"
#include "boost/mpl/value_list.hpp"
#include "boost/mpl/comparison/less.hpp"
#include "boost/mpl/comparison/equal_to.hpp"
#include "boost/mpl/make_fun.hpp"
#include "boost/mpl/same_as.hpp"
#include "boost/mpl/int_t.hpp"
#include "boost/type_traits/arithmetic_traits.hpp"
#include "boost/static_assert.hpp"
#include "boost/config.hpp"

namespace mpl = boost::mpl;

#if !defined(BOOST_NO_TEMPLATE_TEMPLATE_PARAMETERS)
    typedef mpl::make_f_x<boost::is_float> is_float_type;
#else
    BOOST_MPL_MAKE_F_X(is_float_type, boost::is_float);
#endif

int main()
{    
    typedef mpl::type_list<int,char,long,short,char,long,double,long> types;
    typedef mpl::value_list<1,0,5,1,7,5,0,5> values;
    
    BOOST_STATIC_ASSERT((mpl::count_if< types, is_float_type >::value == 1));
    BOOST_STATIC_ASSERT((mpl::count_if< types, mpl::same_as<char> >::value == 2));
    BOOST_STATIC_ASSERT((mpl::count_if< types, mpl::same_as<void> >::value == 0));
    
    BOOST_STATIC_ASSERT((mpl::count_if< values, mpl::lt<5> >::value == 4));
    BOOST_STATIC_ASSERT((mpl::count_if< values, mpl::eq<0>  >::value == 2));
    BOOST_STATIC_ASSERT((mpl::count_if< values, mpl::eq<-1> >::value == 0));
    
    return 0;
}