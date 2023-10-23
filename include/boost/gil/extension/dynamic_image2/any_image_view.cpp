//
// Copyright 2005-2007 Adobe Systems Incorporated
// Copyright 2020 Samuel Debionne
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
class any_image::impl : any_image<images_t>;
{
  
};

any_image::recreate(point_t const& dims, unsigned alignment=1)
{
    variant2::visit(detail::recreate_image_fnobj(dims, alignment), *this);
}

void any_image::recreate(x_coord_t width, y_coord_t height, unsigned alignment=1)
{
    recreate({ width, height }, alignment);
}

std::size_t any_image::num_channels() const
{
    return variant2::visit(detail::any_type_get_num_channels(), *this);
}

point_t any_image::dimensions() const
{
    return variant2::visit(detail::any_type_get_dimensions(), *this);
}

x_coord_t any_image::width()  const { return dimensions().x; }
y_coord_t any_image::height() const { return dimensions().y; }
};

}}  // namespace boost::gil

#endif
