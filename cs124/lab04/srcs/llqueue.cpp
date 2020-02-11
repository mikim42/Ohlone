/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llqueue.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:50:47 by mikim             #+#    #+#             */
/*   Updated: 2018/04/07 13:53:22 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include <lab.h>

LLQUEUE::LLQUEUE(void)
{
	front = rear = NULL;
}

LLQUEUE::~LLQUEUE(void)
{
	NODE	*tmp;

	while (front)
	{
		tmp = front;
		front = front->next;
		cairo_surface_destroy(tmp->car.s);
		delete tmp;
	}
}

bool	LLQUEUE::Insert(Car &car)
{
	NODE	*new_node = new NODE;

	if (!new_node)
	   	return false;
	new_node->car = car; 
	new_node->next = NULL;
	if (rear == 0)
		front = rear = new_node;
	else 
	{
		rear->next = new_node;
		rear = rear->next;
	}
	return true;
} 

bool	LLQUEUE::Remove(Car &car)
{
	NODE	*tmp;

	if (front == 0)
	   	return false;
	car = front->car;
	tmp = front;
	front = front->next;
	delete tmp;
	if (front == 0)
		rear = 0;
	return true;
} 

bool	LLQUEUE::isEmpty(void)
{
	return (front == NULL);
}

void	LLQUEUE::draw_cars(cairo_t* cr)
{
	for(NODE* n = front; n; n = n->next)
	{
		cairo_set_source_surface(cr, n->car.s, n->car.x, n->car.y);
		cairo_paint(cr);
	}
}
