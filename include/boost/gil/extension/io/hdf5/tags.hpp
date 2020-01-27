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

/// Defines the dataset to read in a multidataset hdf5 file.
struct hdf5_dataset : property_base< hid_t >
{
    using default_value = std::integral_constant<type, 0>;
};

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

/// Read settings for hdf5 images.
///
/// The structure can be used for all read_xxx functions, except read_image_info.
template<>
struct image_read_settings< hdf5_tag > : public image_read_settings_base
{
    /// Default constructor
    image_read_settings< hdf5_tag >()
    : image_read_settings_base()
    , _directory( hdf5_dataset::default_value::value )
    {}

    /// Constructor
    /// \param top_left  Top left coordinate for reading partial image.
    /// \param dim       Dimensions for reading partial image.
    /// \param directory Defines the page to read in a multipage hdf5 file.
    image_read_settings( const point_t&              top_left
                       , const point_t&              dim
                       , const hdf5_dataset::type& dataset = hdf5_dataset::default_value::value
                       )
    : image_read_settings_base( top_left
                              , dim
                              )
    , _dataset( dataset )
    {}

    /// Defines the page to read in a multipage hdf5 file.
    hdf5_dataset::type _dataset;
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
