/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customerListType.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:39:21 by mikim             #+#    #+#             */
/*   Updated: 2018/04/23 18:12:39 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#ifndef CUSTOMERLIST_TYPE_H
# define CUSTOMERLIST_TYPE_H

# include "customerType.h" 

struct	Node
{
	customerType	info;
	Node			*link;
};

class customerListType 
{ 
	public:
		customerListType(void);
		~customerListType(void);
		bool	searchByName(string name);
		void	insertFirst(const customerType &item);
		void	insertLast(const customerType &item);
		void	deleteNode(const customerType &item);
		void	customerList(void);
		void	rented(int n, string title);
		void	returned(int n);

	private:
		Node	*first;
		Node	*last;
};

#endif
