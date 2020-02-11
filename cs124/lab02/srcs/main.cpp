/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:37:24 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/20 17:51:23 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lab.h>

#ifndef UNIT_TEST

int main(void)
{
	Node *head = 0x00;
	string	file;

	cout << "Please, enter dictionary file name: ";
	getline(cin, file);
	if (loadDictionary(head, file))
	{
		string	input;
		string	w, t;
		Entry	e;

		while (!cin.eof())
		{
			bool	err = true;

			cout << endl;
			cout << "What do you want to do?" << endl
					  << "[1] Search a word" << endl
					  << "[ctrl + D] Exit" << endl;
			getline(cin, input);
			while (input == "1" && !cin.eof())
			{
				cout << endl;
				cout << "[ctrl + D] Exit" << endl
					 << "Please, enter a word: ";
				getline(cin, w);
				if (search(head, w, e))
				{
					cout << endl;
					cout << "English: " << e.word << endl
						 << "Italian: " << e.translation << endl;
					err = false;
				}
				else if (!cin.eof())
				{
					cout << endl;
					cout << "Cannot find the word." << endl
						 << "[1] Look up another word" << endl
						 << "[2] Make a new word" << endl;
					getline(cin, input);
					if (input == "2")
					{
						t = "";
						while (t.empty() && !cin.eof())
						{
							cout << endl;
							cout << "Please, enter the translation for "
								 << w << ": ";
							getline(cin, t);
							if (t.empty())
							{
								cout << endl;
								cout << "Wrong input. Please try again."
									 << endl;
							}
						}
						destroyList(head);
						if (!add(file, Entry(w, t)) || !loadDictionary(head, file))
							cout << "Failed to add a new word." << endl;
						err = false;
					}
				}
			}
			if (err && !cin.eof())
				cout << "Sorry, wrong input. Please try again." << endl;
		}
	}
	else
		cout << "Failed to open file " << file << "." << endl;
	cout << endl;
	destroyList(head);
	return 0;
}

#endif
