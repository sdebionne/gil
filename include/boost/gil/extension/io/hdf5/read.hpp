//
// Copyright 2020 Samuel Debionne
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_EXTENSION_IO_HDF5_READ_HPP
#define BOOST_GIL_EXTENSION_IO_HDF5_READ_HPP

template< typename Device
        , typename ConversionPolicy
        >
class reader< Device
            , hdf5_tag
            , ConversionPolicy
            >
            : public reader_base< hdf5_tag
                                , ConversionPolicy
                                >
{
private:

    typedef typename ConversionPolicy::color_converter_type cc_t;

public:

    reader( Device& device )
    : _io_dev( device )
    {}

    reader( Device&     device
          , const cc_t& cc
          )
    : _io_dev( device )
    , reader_base< hdf5_tag
                 , ConversionPolicy
                 >( cc )
    {}

    image_read_info< hdf5_tag > get_info()
    {
        // your implementation here
    }

    template< typename View >
    void apply( const View& dst_view )
    {
        // your implementation here
    }
};

#endif
