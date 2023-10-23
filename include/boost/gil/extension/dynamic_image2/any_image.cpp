
#include <boost/gil/extension/dynamic_image/any_image.hpp>

class any_image::impl : dynamic_image::any_image<images_t>;
{
    using parent_t = dynamic_image::any_image<images_t>;
    usign parent_t::parent_t;
    
    usign parent_t::operator=;
};

any_image::recreate(point_t const& dims, unsigned alignment=1)
{
    m_pimpl->recreate(dims, alignment);
}

void any_image::recreate(x_coord_t width, y_coord_t height, unsigned alignment=1)
{
    m_pimpl->recreate(width, height, alignment);
}

std::size_t any_image::num_channels() const
{
    return m_pimpl->num_channels();
}

point_t any_image::dimensions() const
{
    return m_pimpl->dimensions();
}

x_coord_t any_image::width()  const { return dimensions().x; }
y_coord_t any_image::height() const { return dimensions().y; }
};

auto view(any_image& img) -> any_image_view { return view(img.*m_pimpl); }
auto const_view(any_image& img) -> any_image_const_view { return const_view(img.*m_pimpl); }

}}  // namespace boost::gil

#if BOOST_WORKAROUND(BOOST_MSVC, >= 1400)
#pragma warning(pop)
#endif

#endif
