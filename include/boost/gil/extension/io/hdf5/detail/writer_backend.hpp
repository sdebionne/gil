//
// Copyright 2020 Samuel Debionne
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_EXTENSION_IO_HDF5_DETAIL_WRITER_BACKEND_HPP
#define BOOST_GIL_EXTENSION_IO_HDF5_DETAIL_WRITER_BACKEND_HPP

#include <boost/gil/extension/io/hdf5/tags.hpp>
#include <boost/gil/extension/io/hdf5/detail/device.hpp>

#include <boost/gil/detail/mp11.hpp>

namespace boost { namespace gil {

///
/// HDF5 Writer Backend
///
template< typename Device >
struct writer_backend< Device
                     , hdf5_tag
                     >
{
public:

    using format_tag_t = hdf5_tag;

public:

    writer_backend( const Device&                       io_dev
                  , const image_write_info< hdf5_tag >& info
                  )
    : _io_dev( io_dev )
    , _info( info )
    {}

protected:

    template< typename View >
    void write_header( const View& view )
    {
        using pixel_t = typename View::value_type;

        // get the type of the first channel (heterogeneous pixels might be broken for now!)
        using channel_t = typename channel_traits<typename element_type<pixel_t>::type>::value_type;
        using color_space_t = typename color_space_type<View>::type;

        // write dimensions
        hdf5_image_width::type  width  = (hdf5_image_width::type)  view.width();
        hdf5_image_height::type height = (hdf5_image_height::type) view.height();

        this->_io_dev.template set_property< hdf5_image_width  >( width  );
        this->_io_dev.template set_property< hdf5_image_height >( height );
    }


public:

    Device _io_dev;

    image_write_info< hdf5_tag > _info;
};

} // namespace gil
} // namespace boost

#endif
