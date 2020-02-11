/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:57:01 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/08 17:33:54 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lab.h>

int		main(void){
	std::vector<Entry> v;
	std::string	file;

	std::cout << "Please, enter dictionary file name: ";
	getline(std::cin, file);

	if (loadDictionary(file, v)){
		std::string	input;
		std::string w, t;

		while (!std::cin.eof()){
			bool		err = true;

			std::cout << std::endl;
			std::cout << "What do you want to do?" << std::endl
					  << "[1] Look up a word" << std::endl
					  << "[ctrl + D] Exit" << std::endl;
			getline(std::cin, input);
			while (input == "1" && !std::cin.eof()){
				std::cout << std::endl;
				std::cout << "[ctrl + D] Exit" << std::endl
						  << "Please, enter a word: ";
				getline(std::cin, w);
				if (lookUpWord(w, t, v)){
					std::cout << std::endl;
					std::cout << "English: " << w << std::endl
							  << "Italian: " << t << std::endl;
					err = false;
				}
				else if (!std::cin.eof()){
					std::cout << std::endl;
					std::cout << "Cannot find the word." << std::endl
							  << "[1] Look up another word" << std::endl
							  << "[2] Make a new word" << std::endl;
					getline(std::cin, input);
					if (input == "2"){
						t = "";
						while (t.empty() && !std::cin.eof()){
							std::cout << std::endl;
							std::cout << "Please, enter the translation for "
									  << w << ": ";
							getline(std::cin, t);
							if (t.empty()){
								std::cout << std::endl;
								std::cout << "Wrong input. Please try again."
										  << std::endl;
							}
						}
						if (!insertWord(file, w, t) || !loadDictionary(file, v)){
							std::cout << "Failed to add a new word."
									  << std::endl;
						}
						err = false;
					}
				}
			}
			if (err && !std::cin.eof()){
				std::cout << "Sorry, wrong input. Please try again."
						  << std::endl;
			}
		}
	}
	else{
		std::cout << "Failed to open file " << file << "." << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
