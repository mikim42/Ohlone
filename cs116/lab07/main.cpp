/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:33:27 by mikim             #+#    #+#             */
/*   Updated: 2018/04/08 13:36:28 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include "Birthday.h"

int		main(void)
{
	try
	{
		Birthday	bday;
		int			y, m, d;

		cout << "Enter birth year: ";
		cin >> y;
		cout << "Enter month number: ";
		cin >> m;
		cout << "Enther birth day: ";
		cin >> d;

		bday.setYear(y);
		bday.setMonth(m);
		bday.setDay(d);

		cout << bday << endl;
	}
	catch (Birthday::WrongDateException &e)
	{
		cout << e.what() << endl;
	}
	return (0);
}
