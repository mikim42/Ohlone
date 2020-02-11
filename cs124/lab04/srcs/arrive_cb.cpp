/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrive_cb.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:55:38 by mikim             #+#    #+#             */
/*   Updated: 2018/04/07 14:58:45 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include <lab.h>

void	arrive_cb(void *)
{
	static int	n = 1;
	Person		p;
	string		s;
	int			r;

	r = rand() % 8 + 1; 
	s = PERSON_PATH + to_string(r) + PNG;
	p.s = cairo_image_surface_create_from_png(s.c_str());
	r = rand() % 10;
	p.x = (WIDTH * 0.5) + r * (WIDTH * 0.04);
	p.y = (HEIGHT * 0.9) - (r * 2);
	people.Insert(p);
	if (n++ == MAX_CAR)
		Fl::remove_timeout(arrive_cb);
	else
		Fl::repeat_timeout(static_cast<double>(r / 3 + 2), arrive_cb);
}
