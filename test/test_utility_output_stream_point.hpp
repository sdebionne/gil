//
// Copyright 2019-2020 Mateusz Loskot <mateusz at loskot dot net>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_TEST_TEST_UTILITY_OUTPUT_STREAM_POINT_HPP
#define BOOST_GIL_TEST_TEST_UTILITY_OUTPUT_STREAM_POINT_HPP

#include <boost/core/demangle.hpp>
#include <boost/core/typeinfo.hpp>

// Utilities to make GIL primitives printable for BOOST_TEST_EQ and other macros

namespace boost { namespace gil {

template <typename T>
std::ostream& operator<<(std::ostream& os, point<T> const& p)
{
    os << "point<" << boost::core::demangled_name(typeid(T)) << ">";
    os << "(" << p.x << ", " << p.y << ")" << std::endl;
    return os;
}

}} // namespace boost::gil

#endif
