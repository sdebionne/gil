//
// Copyright 2005-2007 Adobe Systems Incorporated
// Copyright 2020 Samuel Debionne
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_EXTENSION_DYNAMIC_IMAGE2_ANY_IMAGE_HPP
#define BOOST_GIL_EXTENSION_DYNAMIC_IMAGE2_ANY_IMAGE_HPP

#include <boost/gil/extension/dynamic_image2/any_image_view.hpp>

#include <boost/config.hpp>

#if BOOST_WORKAROUND(BOOST_MSVC, >= 1400)
#pragma warning(push)
#pragma warning(disable:4512) //assignment operator could not be generated
#endif

namespace boost { namespace gil {

namespace detail {

template <typename T>
using get_view_t = typename T::view_t;

template <typename Images>
using images_get_views_t = mp11::mp_transform<get_view_t, Images>;

template <typename T>
using get_const_view_t = typename T::const_view_t;

template <typename Images>
using images_get_const_views_t = mp11::mp_transform<get_const_view_t, Images>;

struct recreate_image_fnobj
{
    using result_type = void;
    point<std::ptrdiff_t> const& _dimensions;
    unsigned _alignment;

    recreate_image_fnobj(point<std::ptrdiff_t> const& dims, unsigned alignment)
        : _dimensions(dims), _alignment(alignment)
    {}

    template <typename Image>
    result_type operator()(Image& img) const { img.recreate(_dimensions,_alignment); }
};

template <typename AnyView>  // Models AnyViewConcept
struct any_image_get_view
{
    using result_type = AnyView;
    template <typename Image>
    result_type operator()(Image& img) const
    {
        return result_type(view(img));
    }
};

template <typename AnyConstView>  // Models AnyConstViewConcept
struct any_image_get_const_view
{
    using result_type = AnyConstView;
    template <typename Image>
    result_type operator()(Image const& img) const { return result_type{const_view(img)}; }
};

} // namespce detail

////////////////////////////////////////////////////////////////////////////////////////
/// \ingroup ImageModel
/// \brief Represents a run-time specified image. Note it does NOT model ImageConcept
///
/// Represents an image whose type (color space, layout, planar/interleaved organization, etc) can be specified at run time.
/// It is the runtime equivalent of \p image.
/// Some of the requirements of ImageConcept, such as the \p value_type alias cannot be fulfilled, since the language does not allow runtime type specification.
/// Other requirements, such as access to the pixels, would be inefficient to provide. Thus \p any_image does not fully model ImageConcept.
/// In particular, its \p view and \p const_view methods return \p any_image_view, which does not fully model ImageViewConcept. See \p any_image_view for more.
////////////////////////////////////////////////////////////////////////////////////////

class any_image
{
public:
    using view_t = any_image_view;
    using const_view_t = any_image_const_view;
    using x_coord_t = std::ptrdiff_t;
    using y_coord_t = std::ptrdiff_t;
    using point_t = point<std::ptrdiff_t>;

    using parent_t::parent_t;

    void recreate(point_t const& dims, unsigned alignment=1);
    void recreate(x_coord_t width, y_coord_t height, unsigned alignment=1);

    std::size_t num_channels() const;

    point_t dimensions() const;

    x_coord_t width()  const;
    y_coord_t height() const;
    
private:
    struct impl; // forward declaration of the implementation class
    // One implementation example: see below for other design options and trade-offs
    std::experimental::propagate_const< // const-forwarding pointer wrapper
        std::unique_ptr<                // unique-ownership opaque pointer
            impl>> m_pimpl;               // to the forward-declared implementation class
};

///@{
/// \name view, const_view
/// \brief Get an image view from a run-time instantiated image

/// \ingroup ImageModel

/// \brief Returns the non-constant-pixel view of any image. The returned view is any view.
/// \tparam Images Models ImageVectorConcept
auto view(any_image& img) -> any_image_view;

/// \brief Returns the constant-pixel view of any image. The returned view is any view.
/// \tparam Types Models ImageVectorConcept
auto const_view(any_image& img) -> any_image_view;
///@}

}}  // namespace boost::gil

#if BOOST_WORKAROUND(BOOST_MSVC, >= 1400)
#pragma warning(pop)
#endif

#endif
