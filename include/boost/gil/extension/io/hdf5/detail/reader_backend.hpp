//
// Copyright 2020 Samuel Debionne
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_EXTENSION_IO_HDF5_DETAIL_READER_BACKEND_HPP
#define BOOST_GIL_EXTENSION_IO_HDF5_DETAIL_READER_BACKEND_HPP

#include <boost/gil/extension/io/hdf5/tags.hpp>

namespace boost { namespace gil {

///
/// HDF5 Backend
///
template< typename Device >
struct reader_backend< Device
                     , hdf5_tag
                     >
{
public:

    using format_tag_t = hdf5_tag;

public:

    reader_backend( const Device&                          io_dev
                  , const image_read_settings< hdf5_tag >& settings
                  )
    : _io_dev  ( io_dev   )
    , _settings( settings )
    , _info()
    {
        read_header();

        if( _settings._dim.x == 0 )
        {
            _settings._dim.x = _info._width;
        }

        if( _settings._dim.y == 0 )
        {
            _settings._dim.y = _info._height;
        }
    }

    void read_header()
    {
    }

    /// Check if image is large enough.
    void check_image_size( const point_t& img_dim )
    {
    }

public:

    Device _io_dev;

    image_read_settings< hdf5_tag > _settings;
    image_read_info< hdf5_tag >     _info;
};

} // namespace gil
} // namespace boost

#endif
