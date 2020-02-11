/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:56:10 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/20 16:16:14 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lab.h>

bool	insert(Node *&head, Entry entry)
{
	Node	*newnode = new Node;

	if (!newnode)
		return false;
	newnode->entry.word = entry.word;
	newnode->entry.translation = entry.translation;
	newnode->next = head;
	head = newnode;
	return true;
}

#ifdef UNIT_TEST

TEST_CASE("Testing list insert")
{
	Node	*head = 0x00;

	REQUIRE(insert(head, Entry("I", "io")));
	REQUIRE(head->entry.word == "I");
	REQUIRE(head->entry.translation == "io");

	REQUIRE(insert(head, Entry("a", "un")));
	REQUIRE(head->entry.word == "a");
	REQUIRE(head->entry.translation == "un");
}

#endif
