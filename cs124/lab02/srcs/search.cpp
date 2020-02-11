/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:02:00 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/22 15:18:56 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lab.h>

bool	search(Node *&head, string word, Entry &e)
{
	for (Node *iter = head; iter; iter = iter->next)
	{
		if (iter->entry.word == word)
		{
			e = iter->entry;
			return true;
		}
	}
	return false;
}

#ifdef UNIT_TEST

TEST_CASE("testing search list")
{
	Node	*head = 0x00;
	Entry	e;

	REQUIRE_FALSE(search(head, "I", e));
	REQUIRE(loadDictionary(head, "Dictionary"));
	search(head, "I", e);
	REQUIRE(e.word == "I");
	REQUIRE(e.translation == "io");
}

#endif
