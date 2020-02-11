/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llqueue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:10:39 by mikim             #+#    #+#             */
/*   Updated: 2018/05/05 05:02:05 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#ifndef LLQUEUE_H
# define LLQUEUE_H

# include <lab.h>

template <class Type>
struct LLQnode
{
	Type	*item;
	LLQnode	*next;
};

template <class Type>
class LLQueue
{
	public:
		LLQueue(void);
		~LLQueue(void);

		bool	pop(Type *&item);
		bool	push(Type *item);
		bool	isEmpty(void);
		size_t	size(void);

	private:
		LLQnode<Type>	*_front;
		LLQnode<Type>	*_rear;
		size_t			_size;
};

template <class Type>
LLQueue<Type>::LLQueue(void)
{
	_front = _rear = NULL;
	_size = 0;
}

template <class Type>
LLQueue<Type>::~LLQueue(void)
{
	LLQnode<Type>	*tmp;

	while (_front)
	{
		tmp = _front;
		delete tmp->item;
		delete tmp;
		_front = _front->next;
	}
}

template <class Type>
bool	LLQueue<Type>::pop(Type *&item)
{
	LLQnode<Type>	*tmp;

	if (isEmpty())
		return false;
	item = _front->item;
	tmp = _front;
	delete tmp;
	_front = _front->next;
	_size--;
	if (!_front)
		_rear = NULL;
	return true;
}

template <class Type>
bool	LLQueue<Type>::push(Type *item)
{
	LLQnode<Type>	*newnode;

	if (!item || !(newnode = new LLQnode<Type>))
		return false;
	newnode->item = item;
	newnode->next = NULL;
	if (!_front)
		_front = _rear = newnode;
	else
	{
		_rear->next = newnode;
		_rear = _rear->next;
	}
	_size++;
	return true;
}

template <class Type>
bool	LLQueue<Type>::isEmpty(void)
{
	return (!_size);
}

template <class Type>
size_t	LLQueue<Type>::size(void)
{
	return _size;
}

#endif
