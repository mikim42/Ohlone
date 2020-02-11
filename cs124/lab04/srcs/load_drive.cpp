/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_drive.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:18:30 by mikim             #+#    #+#             */
/*   Updated: 2018/04/07 14:31:44 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include <lab.h>

void	load_drive(void)
{
	if (cars.isEmpty() || people.isEmpty())
		return ;
	cars.Remove(drive.car);
	people.Remove(drive.person);
	drive.st_x = drive.x = drive.car.x;
	drive.st_y = drive.y = drive.car.y;
	drive.move = true;
}
