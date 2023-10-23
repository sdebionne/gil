//
// Copyright 2005-2007 Adobe Systems Incorporated
// Copyright 2020 Samuel Debionne
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_EXTENSION_DYNAMIC_IMAGE2_ANY_IMAGE_VIEW_HPP
#define BOOST_GIL_EXTENSION_DYNAMIC_IMAGE2_ANY_IMAGE_VIEW_HPP

namespace boost { namespace gil {

////////////////////////////////////////////////////////////////////////////////////////
/// CLASS any_image_view
///
/// \ingroup ImageViewModel
/// \brief Represents a run-time specified image view. Models HasDynamicXStepTypeConcept, HasDynamicYStepTypeConcept, Note that this class does NOT model ImageViewConcept
///
/// Represents a view whose type (color space, layout, planar/interleaved organization, etc) can be specified at run time.
/// It is the runtime equivalent of \p image_view.
/// Some of the requirements of ImageViewConcept, such as the \p value_type alias cannot be fulfilled, since the language does not allow runtime type specification.
/// Other requirements, such as access to the pixels, would be inefficient to provide. Thus \p any_image_view does not fully model ImageViewConcept.
/// However, many algorithms provide overloads taking runtime specified views and thus in many cases \p any_image_view can be used in places taking a view.
///
/// To perform an algorithm on any_image_view, put the algorithm in a function object and invoke it by calling \p variant2::visit(algorithm_fn, runtime_view);
////////////////////////////////////////////////////////////////////////////////////////

class any_image_view
{
public:
    using pixel_t = any_pixel_t;
    using const_t = any_image_const_view;
    using x_coord_t = std::ptrdiff_t;
    using y_coord_t = std::ptrdiff_t;
    using point_t = point<std::ptrdiff_t>;
    using size_type = std::size_t;

    using parent_t::parent_t;

    pixel_t     pixel()         const;
    std::size_t num_channels()  const;
    point_t     dimensions()    const;
    size_type   size()          const;
    x_coord_t   width()         const;
    y_coord_t   height()        const;
    
private:
    struct impl; // forward declaration of the implementation class
    // One implementation example: see below for other design options and trade-offs
    std::experimental::propagate_const< // const-forwarding pointer wrapper
        std::unique_ptr<                // unique-ownership opaque pointer
            impl>> m_pimpl;               // to the forward-declared implementation class
};

class any_image_const_view
{
public:
    using pixel_t = any_pixel_t;
    using const_t = any_image_const_view;
    using x_coord_t = std::ptrdiff_t;
    using y_coord_t = std::ptrdiff_t;
    using point_t = point<std::ptrdiff_t>;
    using size_type = std::size_t;

    using parent_t::parent_t;

    pixel_t     pixel()         const;
    std::size_t num_channels()  const;
    point_t     dimensions()    const;
    size_type   size()          const;
    x_coord_t   width()         const;
    y_coord_t   height()        const;
    
private:
    struct impl; // forward declaration of the implementation class
    // One implementation example: see below for other design options and trade-offs
    std::experimental::propagate_const< // const-forwarding pointer wrapper
        std::unique_ptr<                // unique-ownership opaque pointer
            impl>> m_pimpl;               // to the forward-declared implementation class
};

}}  // namespace boost::gil

#endif
