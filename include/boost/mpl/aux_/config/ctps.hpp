
#ifndef BOOST_MPL_AUX_CONFIG_CTPS_HPP_INCLUDED
#define BOOST_MPL_AUX_CONFIG_CTPS_HPP_INCLUDED

// Copyright (c) 2000-04 Aleksey Gurtovoy
//
// Use, modification and distribution are subject to the Boost Software 
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy 
// at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Source$
// $Date$
// $Revision$

#include <boost/mpl/aux_/config/workaround.hpp>
#include <boost/config.hpp>

#if    !defined(BOOST_MPL_CFG_NO_NONTYPE_TEMPLATE_PARTIAL_SPEC) \
    && !defined(BOOST_MPL_PREPROCESSING_MODE) \
    && BOOST_WORKAROUND(__BORLANDC__, < 0x600) 

#   define BOOST_MPL_CFG_NO_NONTYPE_TEMPLATE_PARTIAL_SPEC

#endif

// BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION is defined in <boost/config.hpp>

#endif // BOOST_MPL_AUX_CONFIG_CTPS_HPP_INCLUDED