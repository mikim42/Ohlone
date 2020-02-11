/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   car.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:48:17 by mikim             #+#    #+#             */
/*   Updated: 2018/04/07 05:37:57 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#ifndef CAR_H
# define CAR_H

# include <lab.h>

struct				Car
{
	double			x;
	double			y;
	cairo_surface_t	*s;
};

#endif