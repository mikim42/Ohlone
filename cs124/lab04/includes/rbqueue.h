/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbqueue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:52:47 by mikim             #+#    #+#             */
/*   Updated: 2018/04/07 05:02:30 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#ifndef RBQUEUE_H
# define RBQUEUE_H

# include <lab.h>

const int	BUFSIZE = 256;

class	RBQUEUE 
{
	private:
		Person	buf[BUFSIZE];
		int		front;
		int		rear;
		int		nextIndex(int index); 

	public:
		RBQUEUE();
		~RBQUEUE();

		bool	Insert(Person s);
		bool	Remove(Person &s);
		bool	isEmpty();
		bool	isFull();
		void	draw_people(cairo_t *cr);
}; 
 
#endif
