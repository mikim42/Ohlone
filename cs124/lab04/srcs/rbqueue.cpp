/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbqueue.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:48:42 by mikim             #+#    #+#             */
/*   Updated: 2018/04/07 13:53:18 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include <lab.h>

RBQUEUE::RBQUEUE(void)
{
}

RBQUEUE::~RBQUEUE(void)
{
	while (front != rear)
	{
		cairo_surface_destroy(buf[front].s);
		front = nextIndex(front);
	}
}

int		RBQUEUE::nextIndex(int index)
{
	if (++index == BUFSIZE)
		index = 0;
	return index;
}

bool	RBQUEUE::Insert(Person s)
{
	if (isFull())
		return false;
	buf[rear] = s;
	rear = nextIndex(rear);
	return true;
} 

bool	RBQUEUE::Remove(Person &s)
{
	if (isEmpty())
		return false;
	s = buf[front];
	front = nextIndex(front);
	return true;
}

bool	RBQUEUE::isEmpty()
{
	return (front == rear);
}
bool	RBQUEUE::isFull()
{
	return (nextIndex(rear) == front);
}

void	RBQUEUE::draw_people(cairo_t* cr)
{
	for(int i = front; i != rear; i = nextIndex(i))
	{
		cairo_set_source_surface(cr, buf[i].s, buf[i].x, buf[i].y);
		cairo_paint(cr);
	}
}
