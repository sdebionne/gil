//
// Copyright 2020 Samuel Debionne
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_EXTENSION_IO_HDF5_DETAIL_SUPPORTED_TYPES_HPP
#define BOOST_GIL_EXTENSION_IO_HDF5_DETAIL_SUPPORTED_TYPES_HPP

#include <boost/gil/extension/io/hdf5/tags.hpp>

#include <boost/gil/channel.hpp>
#include <boost/gil/color_base.hpp>
#include <boost/gil/io/base.hpp>

#include <type_traits>

namespace boost{ namespace gil {

namespace detail {

// Read support

// HDF5 virtually supports everything
struct hdf5_read_support : read_support_true
{};


// Write support

struct hdf5_write_support : write_support_true
{};

} // namespace detail

template<typename Pixel>
struct is_read_supported<Pixel, hdf5_tag>
    : std::integral_constant<bool, detail::hdf5_read_support::is_supported>
{};

template<typename Pixel>
struct is_write_supported<Pixel, hdf5_tag>
    : std::integral_constant<bool, detail::hdf5_write_support::is_supported>
{};

}} // namespace boost::gil

#endif
