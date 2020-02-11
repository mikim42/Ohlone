/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 13:28:00 by mikim             #+#    #+#             */
/*   Updated: 2018/05/05 07:23:36 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

# include <lab.h>

template <class Type>
struct Bnode
{
	Type	*item;
	Bnode<Type>	*left;
	Bnode<Type>	*right;
};

template <class Type>
class Btree
{
	public:
		Btree(void);
		~Btree(void);

		bool	insert(Type *&item);
		bool	remove(Type *item);
		bool	remove(std::string login);
		Type	*search(Type *item);
		Type	*pop(void);

	private:
		Bnode<Type>	*_root;
		bool		insert(Bnode<Type> *&root, Type *&item);
		bool		remove(Bnode<Type> *&root, Type *item);
		Type		*search(Bnode<Type> *root, Type *item);
		void		minimum(Bnode<Type> *root, Bnode<Type> *&min);
		void		destroy(Bnode<Type> *root);
};

template <class Type>
Btree<Type>::Btree(void)
{
	_root = NULL;
}

template <class Type>
Btree<Type>::~Btree(void)
{
	destroy(_root);
}

template <class Type>
bool	Btree<Type>::insert(Type *&item)
{
	if (!item || search(item))
		return false;
	else
		return (insert(_root, item));
}

template <class Type>
bool	Btree<Type>::insert(Bnode<Type> *&root, Type *&item)
{
	if (!root)
	{
		if (!(root = new Bnode<Type>))
			return false;
		root->item = item;
		root->left = root->right = NULL;
		return true;
	}
	else if (item < root->item)
		insert(root->left, item);
	else
		insert(root->right, item);
}

template <class Type>
bool	Btree<Type>::remove(Type *item)
{
	if (!item)
		return false;
	else
		return (remove(_root, item));
}

template <class Type>
bool	Btree<Type>::remove(std::string login)
{
	Type	*tmp;

	if ((tmp = search(login)))
		return (remove(_root, tmp));
	else
		return false;
}

template <class Type>
bool	Btree<Type>::remove(Bnode<Type> *&root, Type *item)
{
	Bnode<Type>	*tmp;

	if (!root)
		return false;
	if (root->item == item)
	{
		tmp = root;
		if (!root->left)
			root = root->right;
		else if (!root->right)
			root = root->left;
		else
			minimum(root->right, root);
		delete tmp->item;
		delete tmp;
	}
	else if (item < root->item)
		remove(root->left, item);
	else
		remove(root->right, item);
	return true;
}

template <class Type>
Type	*Btree<Type>::search(Type *item)
{
	Bnode<Type> *tmp = _root;

	if (_root)
		std::cout << _root->item->getLogin() << std::endl;
	if (!item)
		return NULL;
	else
		search(tmp, item);
}

template <class Type>
Type	*Btree<Type>::search(Bnode<Type> *root, Type *item)
{
	if (!root)
		return NULL;
	if (*root->item == *item)
		return root->item;
	else if (*item < *root->item)
		return search(root->left, item);
	else
		return search(root->right, item);
}

template <class Type>
Type	*Btree<Type>::pop(void)
{
	if (_root)
		return _root->item;
	return NULL;
}

template <class Type>
void	Btree<Type>::minimum(Bnode<Type> *root, Bnode<Type> *&min)
{
	if (root)
	{
		if (min->item < root->item)
			min = root;
		minimum(root->left, min);
		minimum(root->right, min);
	}
}

template <class Type>
void	Btree<Type>::destroy(Bnode<Type> *root)
{
	if (root)
	{
		destroy(root->left);
		destroy(root->right);
		delete root->item;
		delete root;
	}
}

#endif
