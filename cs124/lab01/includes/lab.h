/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:58:46 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/08 16:15:45 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAB_H
# define LAB_H

# include <iostream>
# include <fstream>
# include <vector>
# include <catch.hpp>

struct Entry{
	Entry(std::string w, std::string t) : word(w), translation(t) {}
	bool	operator==(const Entry &e) const{
		return word == e.word && translation == e.translation;
	}
	std::string word;
	std::string translation;
};

bool	loadDictionary(std::string f, std::vector<Entry> &v);
bool	lookUpWord(std::string w, std::string &t, const std::vector<Entry> v);
bool	insertWord(std::string f, std::string w, std::string t);

#endif
