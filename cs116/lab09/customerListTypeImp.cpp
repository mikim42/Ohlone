/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customerListTypeImp.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:53:29 by mikim             #+#    #+#             */
/*   Updated: 2018/04/23 18:18:41 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include "customerListType.h"

customerListType::customerListType(void)
{
	first = last = 0;
}

customerListType::~customerListType(void)
{
	Node	*tmp;

	while (first)
	{
		tmp = first;
		first = first->link;
		delete tmp;
	}
}

bool	customerListType::searchByName(string name)
{	// search and return node
	Node	*current = first;

	while (current)
	{
		if (current->info.getFirstname() == name ||
				current->info.getLastname() == name)
			return true;
		else
			current = current->link;
	}
	return false;
}

void	customerListType::insertFirst(const customerType &item)
{	// insert at the front
	Node	*newnode = new Node;

	newnode->info = item;
	newnode->link = first;
	first = newnode;
}

void	customerListType::insertLast(const customerType &item)
{
	Node	*newnode = new Node;

	newnode->info = item;
	newnode->link = 0;
	if (!last)
		first = last = newnode;
	else
	{
		last->link = newnode;
		last = last->link;
	}
}
void	customerListType::deleteNode(const customerType &item)
{
	Node	*current = first;
	Node	*tmp = 0;

	while (current)
	{
		if (current->info == item)
		{
			tmp = current;
			break ;
		}
		else
			current = current->link;
	}
	if (tmp)
	{
		current->link = tmp->link;
		delete tmp;
	}
}

void	customerListType::customerList(void)
{
	Node	*current = first;

	while (current)
	{
		cout << current->info << endl;
		current = current->link;
	}
}

void	customerListType::rented(int n, string title)
{
	Node	*current = first;

	while (current)
	{
		if (current->info.getAccountNo() == n)
		{
			current->info.rentDVD(title);
			break ;
		}
		else
			current = current->link;
	}
}

void	customerListType::returned(int n)
{
	Node	*current = first;

	while (current)
	{
		if (current->info.getAccountNo() == n)
		{
			current->info.returnDVD();
			break ;
		}
		else
			current = current->link;
	}
}
