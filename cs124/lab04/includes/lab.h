/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:46:21 by mikim             #+#    #+#             */
/*   Updated: 2018/04/07 16:17:07 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#ifndef LAB_H
# define LAB_H

# include <string>
# include <cairo.h>
# include <config.h>
# include <FL/Fl_Cairo_Window.H>
# include <car.h>
# include <person.h>
# include <drive.h>
# include <llqueue.h>
# include <rbqueue.h>

using namespace std;

const string	CAR_PATH = "cars/car";
const string	PERSON_PATH = "persons/person";
const string	PNG = ".png";
const int		WIDTH = 600;
const int		HEIGHT = 400;
const int		MAX_CAR = 5;
const double	DEST_X = WIDTH;
const double	DEST_Y = HEIGHT * 0.7;

void	load_cars(void);
void	draw_cb(Fl_Cairo_Window *cw, cairo_t *cr);
void	draw_background(cairo_t *cr);
void	load_drive(void);
void	draw_drive(cairo_t *cr);
void	arrive_cb(void *);
void	redraw_cb(void *);

extern LLQUEUE			cars;
extern RBQUEUE			people;
extern DRIVE			drive;
extern Fl_Cairo_Window	cw;

#endif
