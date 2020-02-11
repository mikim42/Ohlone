/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyList.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:02:31 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/20 16:16:11 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lab.h>

void destroyList(Node *&head)
{
	Node *t = NULL;

	while (head)
	{
		t = head;
		head = head->next;
		delete t;
	}
	head = NULL;
}

#ifdef UNIT_TEST

TEST_CASE("Testing list destroy")
{
	Node *head = NULL;

	REQUIRE(loadDictionary(head, "Dictionary"));
	destroyList(head);
	REQUIRE(head == NULL);
}

#endif
