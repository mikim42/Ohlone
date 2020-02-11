/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llqueue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:49:22 by mikim             #+#    #+#             */
/*   Updated: 2018/04/07 05:26:20 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#ifndef LLQUEUE_H
# define LLQUEUE_H

# include <lab.h>

struct		NODE
{
	Car		car;
	NODE	*next;
};

class	LLQUEUE 
{
	private:
		NODE	*front;
		NODE	*rear;

	public:
		LLQUEUE();
		~LLQUEUE();

		bool	Insert(Car &car);
		bool	Remove(Car &car);
		bool	isEmpty();
		void	draw_cars(cairo_t* cr);
}; 

#endif
