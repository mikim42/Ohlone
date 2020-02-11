/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadDictionary.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:54:21 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/20 17:27:01 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lab.h>

bool	loadDictionary(Node *&head, string fileName)
{
	ifstream	ifs(fileName);
	string		title, w, t;
	bool		r = true;

	r = ifs;
	getline(ifs, title);
	while (ifs >> w >> t)
		if (!insert(head, Entry(w, t)))
		{
			r = false;
			break ;
		}
	return r;
}

#ifdef UNIT_TEST

TEST_CASE("Testing load list")
{
	Node	*head = 0x00;

	REQUIRE(loadDictionary(head, "Dictionary"));
	REQUIRE_FALSE(loadDictionary(head, "dictionary"));
}

#endif
