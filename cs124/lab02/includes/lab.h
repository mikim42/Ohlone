/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:58:46 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/20 17:47:35 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAB_H
# define LAB_H

# include <iostream>
# include <fstream>
# include <catch.hpp>

using namespace std;

struct Entry
{
	Entry(string w="", string t="") : word(w), translation(t) {}
	bool	operator==(const Entry &e) const{
		return word == e.word && translation == e.translation;
	}
	string word;
	string translation;
};

struct Node
{
	Entry	entry;
	Node	*next;
};

bool	insert(Node *&head, Entry entry);
bool	loadDictionary(Node *&head, string fileName);
bool	add(string f, Entry entry);
bool	search(Node *&head, string word, Entry &e);
void	destroyList(Node *&head);

#endif
