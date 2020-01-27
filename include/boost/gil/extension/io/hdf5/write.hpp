//
// Copyright 2020 Samuel Debionne
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_EXTENSION_IO_HDF5_WRITE_HPP
#define BOOST_GIL_EXTENSION_IO_HDF5_WRITE_HPP

template< typename Device >
class writer< Device
            , hdf5_tag
            >
{
public:

    writer( Device & file )
    : out(file)
    {}

    template<typename View>
    void apply( const View& view )
    {
        // your implementation here
    }

    template<typename View>
    void apply( const View&                        view
              , const image_write_info< hdf5_tag >& info )
    {
        // your implementation here
    }
};

#endif
