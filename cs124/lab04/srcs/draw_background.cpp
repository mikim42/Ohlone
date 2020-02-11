/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 22:25:21 by mikim             #+#    #+#             */
/*   Updated: 2018/04/07 13:52:49 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include <lab.h>

void draw_background(cairo_t *cr)
{
	double			w, h;
	cairo_surface_t *s;

	cairo_save(cr);
	s = cairo_image_surface_create_from_png("streets/street2.png");
	w = static_cast<double>(WIDTH) / cairo_image_surface_get_width(s);
	h = static_cast<double>(HEIGHT) / cairo_image_surface_get_height(s);
	cairo_scale(cr, w, h);
	cairo_set_source_surface(cr, s, 0, 0);
	cairo_paint(cr);
	cairo_surface_destroy(s);
	cairo_restore(cr);
}

