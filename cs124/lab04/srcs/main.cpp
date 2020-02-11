/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:38:16 by mikim             #+#    #+#             */
/*   Updated: 2018/04/07 14:38:15 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include <lab.h>

LLQUEUE			cars;
RBQUEUE			people;
DRIVE			drive;
Fl_Cairo_Window	cw(WIDTH, HEIGHT);

int main(void)
{
	srand(clock());
	cw.label("Car Queues");
	cw.set_draw_cb(draw_cb);
	load_cars();
	Fl::add_timeout(2, arrive_cb);
	Fl::add_timeout(0.1, redraw_cb);
	cw.show();
	Fl::run();
	cw.clear();
	return (0);
}
