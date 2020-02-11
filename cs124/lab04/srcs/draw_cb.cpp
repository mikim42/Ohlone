/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cb.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:47:23 by mikim             #+#    #+#             */
/*   Updated: 2018/04/07 14:30:54 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include <lab.h>

void	draw_cb(Fl_Cairo_Window *cw, cairo_t *cr)
{
	(void)cw;
	if (cars.isEmpty() && !drive.move)
		Fl::remove_timeout(redraw_cb);
	draw_background(cr);
	cars.draw_cars(cr);
	people.draw_people(cr);
	if (drive.move)
		draw_drive(cr);
	else
		load_drive();
} 
