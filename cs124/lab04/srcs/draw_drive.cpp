/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_drive.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 01:46:12 by mikim             #+#    #+#             */
/*   Updated: 2018/04/07 14:56:59 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include <lab.h>

void	draw_drive(cairo_t *cr)
{
	if (drive.x < WIDTH)
	{
		cairo_save(cr);
		cairo_set_source_surface(cr, drive.car.s, drive.x, drive.y);
		cairo_paint(cr);
		cairo_scale(cr, 0.5, 0.5);
		cairo_set_source_surface(cr, drive.person.s,
									drive.x * 2 + 20, drive.y * 2 - 20);
		cairo_paint(cr);
		cairo_restore(cr);
		drive.x += (DEST_X - drive.st_x) * 0.02;
		drive.y += (DEST_Y - drive.st_y) * 0.02;
	}
	else
	{
		cairo_surface_destroy(drive.car.s);
		cairo_surface_destroy(drive.person.s);
		drive.move = false;
	}
}
