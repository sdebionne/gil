//
// Copyright 2020 Samuel Debionne
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_EXTENSION_IO_HDF5_TAGS_HPP
#define BOOST_GIL_EXTENSION_IO_HDF5_TAGS_HPP

#include <boost/gil/detail/mp11.hpp>
#include <boost/gil/io/base.hpp>

#include <type_traits>

#include <hdf5.h>

namespace boost {
    namespace gil {

/// Defines hdf5 tag.
struct hdf5_tag : format_tag {};

/// Read information for hdf5 images.
///
/// The structure is returned when using read_image_info.
template<>
struct image_read_info< hdf5_tag >
{
    /// Default constructor
    image_read_info()
    {}
};


/// Write settings for hdf5 images.
///
/// The structure can be used for all write_xxx functions, except write_image_info.
template< typename Log >
struct image_write_info< hdf5_tag, Log >
{
    /// Default constructor
    image_write_info()
    {}
};

    } // namespace gil
} // namespace boost

#endif
