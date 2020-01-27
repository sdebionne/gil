//
// Copyright 2020 Samuel Debionne
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_EXTENSION_IO_HDF5_WRITE_HPP
#define BOOST_GIL_EXTENSION_IO_HDF5_WRITE_HPP

namespace boost { namespace gil {

namespace detail {
  
} // namespace detail

///
/// HDF5 Dynamic Image Writer
///
template< typename Device >
class dynamic_image_writer< Device
                          , hdf5_tag
                          >
    : public writer< Device
                   , hdf5_tag
                   >
{
    using parent_t = writer<Device, hdf5_tag>;

public:

    dynamic_image_writer( const Device&                      io_dev
                        , const image_write_info< hdf5_tag >& info
                        )
    : parent_t( io_dev
              , info
              )
    {}

    template< typename Views >
    void apply( const any_image_view< Views >& views )
    {
        detail::dynamic_io_fnobj< detail::bmp_write_is_supported
                                , parent_t
                                > op( this );

        apply_operation( views, op );
    }
};

///
/// HDF5 Writer
///
template< typename Device >
class writer< Device
            , hdf5_tag
            >
    : public writer_backend< Device
                           , hdf5_tag
                           >
{
public:

    writer( const Device& io_dev
          , const image_write_info< hdf5_tag >& info
          )
    : backend_t( io_dev, info ) {}

    template<typename View>
    void apply( const View& view )
    {
        //write( view );
    }

private:

    using backend_t = writer_backend<Device, hdf5_tag>;
};

} // gil
} // boost

#endif
