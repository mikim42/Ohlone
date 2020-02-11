/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:58:04 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/01/30 10:03:09 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Name: Mingyun Kim

* Lab 1 Chapter 8 Array
* D. S. Malik, Chapter 8 page 605, #7
*/

#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

int sumVotes(int list[], int size);
int winnerIndex(int list[], int size);

int main()
{
	string	candidate[5] = {"", "", "", "", ""};
	int		vote[5] = {-1, -1, -1, -1, -1};
	int		sum, winner;
	size_t	width = 9;

	for (int i = 0; i < 5; i++)
	{
		while (candidate[i].empty())
		{
			cout << "Please, enter the last name of cadidate" << i + 1 << ": ";
			getline(cin, candidate[i]);
			if (candidate[i].empty())
				cout << "Name can't be empty. Please try again." << endl;
			else if (candidate[i].length() > width)
				width = candidate[i].length();
		}
		while (vote[i] < 0)
		{
			cout << "Please, enter the number of votes " << candidate[i]
				 << " received: ";
			cin >> vote[i];
			if (cin.fail())
			{
				cout << "Please, enter a number" << endl;
				vote[i] = -1;
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	sum = sumVotes(vote, static_cast<int>(sizeof(vote) / sizeof(int)));
	winner = winnerIndex(vote, static_cast<int>(sizeof(vote) / sizeof(int)));
	cout << setw(width) << left << "Candidate";
	cout << "   " << "Votes Received   " << "% of Total Votes" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout.precision(2);
		cout << setw(width) << left << candidate[i] << "   ";
		cout << setw(14) << right << vote[i] << "   " << setw(16) << fixed << 
				(static_cast<double>(vote[i]) / sum * 100) << endl; 
	}
	cout << "The Winner of the Election is " <<
			candidate[winner] << "." << endl;
	return 0;
}

int sumVotes(int list[], int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
		sum += list[i];
	return sum;
}

int winnerIndex(int list[], int size)
{
	int winInd = 0;
	int big = list[0];

	for (int i = 0; i < size; i++)
	{
		if (big < list[i])
		{
			big = list[i];
			winInd = i;
		}
	}
	return winInd;
}
