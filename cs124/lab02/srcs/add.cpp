/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:59:56 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/20 16:18:29 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lab.h>

bool	add(std::string f, Entry entry)
{
	std::ofstream	ofs(f, std::ofstream::app);
	bool			r = ofs;

	if (r)
	{
		ofs << entry.word << " " << entry.translation << std::endl;
	}
	return r;
}

#ifdef UNIT_TEST

TEST_CASE("testing add new word")
{
	Node *head = 0x00;

	REQUIRE(loadDictionary(head, "Dictionary"));
	REQUIRE(add("Dictionary", Entry("word", "trans")));
}

#endif
