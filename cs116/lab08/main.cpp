/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 11:06:55 by mikim             #+#    #+#             */
/*   Updated: 2018/04/15 11:29:30 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include <iostream>

void	draw_stars(int space, int star)
{
	//	draw empty spaaces
	for (int i = 0; i < space; i++)
		std::cout << " ";
	//	draw stars
	for (int i = 0; i < star; i++)
		std::cout << "* ";
	std::cout << std::endl;
}

void	stars(int curr, int total, bool side)
{
	// check the side (top or bottom)
	if (side)
	{	//	if it's top side:
		if (curr < total)
		{	//	draw stars until curr hits the total
			draw_stars(total - curr, curr);
			//	recur until it hits the total
			return (stars(curr + 1, total, side));
		}
		else
		{	//	change the side to draw bottom part
			stars(total - 2, total, false);
		}
	}
	else
	{	//	if it's bottom side:
		if (curr > 0)
		{	//	draw stars until curr hits 0
			draw_stars(total - curr, curr);
			//	recur until it hits 0
			return (stars(curr - 1, total, side));
		}
	}
}

int		main(void)
{
	int		line;

	std::cout << "Enter the number of lines in the grid: ";
	std::cin >> line;
	stars(1, line + 1, true);
	return (0);
}
