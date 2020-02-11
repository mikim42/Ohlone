/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertWord.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:43:26 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/13 14:27:05 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lab.h>

bool	insertWord(std::string f, std::string w, std::string t){
	std::ofstream	ofs(f, std::ofstream::app);
	bool			r = ofs;

	if (r){
		ofs << w << " " << t << std::endl;
	}
	return r;
}

#ifdef UNIT_TEST

TEST_CASE("Testing insert word"){
	std::vector<Entry> v;
	std::string w, t;

	REQUIRE(loadDictionary("Dictionary", v));
	REQUIRE(v.size() == 4);

	REQUIRE_FALSE(lookUpWord("hello", t, v));
	REQUIRE(insertWord("Dictionary", "hello", "world"));

	REQUIRE(loadDictionary("Dictionary", v));
	REQUIRE(lookUpWord("hello", t, v));
	REQUIRE(t == "world");
}

#endif
