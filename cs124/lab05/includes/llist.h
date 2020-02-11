/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:16:15 by mikim             #+#    #+#             */
/*   Updated: 2018/05/05 07:40:53 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#ifndef	LINKEDLIST_H
# define LINKEDLIST_H

# include <lab.h>

template <class Type>
struct	LLnode
{
	Type	*item;
	LLnode	*next;
};

template <class Type>
class	LList
{
	public:
		LList<Type>(void);
		~LList<Type>(void);

		bool	insert(Type *&item);
		bool	remove(Type *item);
		Type	*pop(void);

	private:
		LLnode<Type>	*_head;
};

template <class Type>
LList<Type>::LList(void)
{
	_head = NULL;
}

template <class Type>
LList<Type>::~LList(void)
{
	LLnode<Type>	*tmp;

	while (_head)
	{
		tmp = _head;
		_head = _head->next;
		delete tmp->item;
		delete tmp;
	}
}

template <class Type>
bool	LList<Type>::insert(Type *&item)
{
	LLnode<Type>	*newnode;
	LLnode<Type>	*tmp;

	if (!item || !(newnode = new LLnode<Type>))
		return false;
	newnode->item = item;
	newnode->next = NULL;
	if (!_head)
		_head = newnode;
	else
	{
		tmp = _head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newnode;
	}
	return true;
}

template <class Type>
bool	LList<Type>::remove(Type *item)
{
	LLnode<Type>	*tmp;
	LLnode<Type>	*del;

	if (!_head || !item)
		return false;
	tmp = NULL;
	del = _head;
	while (del)
	{
		if (*del->item == *item)
			break ;
		tmp = del;
		del = del->next;
	}
	if (!del)
		return false;
	else if (!tmp)
		_head = _head->next;
	else
		tmp->next = del->next;
	delete del->item;
	delete del;
}

template <class Type>
Type	*LList<Type>::pop(void)
{
	if (!_head)
		return NULL;
	return _head->item;
}

#endif
