/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_cars.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:18:30 by mikim             #+#    #+#             */
/*   Updated: 2018/04/07 13:54:29 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include <lab.h>

void load_cars(void)
{
	for (int i = 0; i < MAX_CAR; i++)
	{
		Car		c;
		string	s;
		int		r;

		r = rand() % 5;
		s = CAR_PATH + to_string(r) + PNG;
		c.s = cairo_image_surface_create_from_png(s.c_str());
		c.x = 200 - (i * 50);
		c.y = static_cast<double>(HEIGHT) * 0.85 + i * 5;
		cars.Insert(c);
	}
}
