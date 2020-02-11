/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadDictionary.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:19:44 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/13 14:27:22 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lab.h>

bool loadDictionary(std::string f, std::vector<Entry> &v){
	std::string		title, w, t;
	std::ifstream	ifs(f);
	bool			r = ifs;

	getline(ifs, title);
	while (ifs >> w >> t){
		v.push_back(Entry(w,t));
	}
	return r;
}

#ifdef UNIT_TEST

TEST_CASE("Testing fill vector"){
	std::vector<Entry> v;

	REQUIRE(v.size() == 0);
	REQUIRE(loadDictionary("Dictionary", v));
	REQUIRE(v.size() == 4);

	Entry e1("want", "volere");
	Entry e2("a", "un");
	Entry e3("I", "io");
	Entry e4("this", "questo");

	std::vector <Entry> ev;
	ev.push_back(e1);
	ev.push_back(e2);
	ev.push_back(e3);
	ev.push_back(e4);
	REQUIRE(v == ev);
}

#endif
