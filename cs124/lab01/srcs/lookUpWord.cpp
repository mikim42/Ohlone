/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookUpWord.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:22:45 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/13 14:27:40 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lab.h>

bool	lookUpWord(std::string w, std::string &t, const std::vector<Entry> v){
	bool	r = false;
	for (size_t i = 0; i < v.size(); i++){
		if (w == v[i].word){
			r = true;
			t = v[i].translation;
			break ;
		}
	}
	return r;
}

#ifdef UNIT_TEST

TEST_CASE("Testing find word"){
	std::vector<Entry> v;
	std::string t;

	REQUIRE(loadDictionary(DICTIONARY, v));
	REQUIRE(v.size() == 4);

	REQUIRE_FALSE(lookUpWord("hello", t, v));
	REQUIRE(lookUpWord("I", t, v));

	REQUIRE(lookUpWord("this", t, v));
	REQUIRE(t == "questo");
}

#endif
