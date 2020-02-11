/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bookTypeImp.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:47:56 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/13 22:05:40 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bookType.h" 
 
using namespace std;

bookType::bookType()
{
   // Default constructor
}

bookType::~bookType()
{
   // Destructor
}

// TODO other methods of bookType
void	bookType::setBookInfo(string title, string ISBN, string Publisher,
								int PublishYear, string auth[], double cost,
								int copies, int authorCount)
{
		this->bookTitle = title;
		this->bookISBN = ISBN;
		this->bookPublisher = Publisher;
		this->bookPublishYear = PublishYear;
		this->noOfAuthors = authorCount;
		for (int i = 0; i < authorCount; i++)
			this->authors[i] = auth[i];
		this->quantity = copies;
		this->price = cost;
}

string	bookType::getTitle(void) { return this->bookTitle; }

string	bookType::getISBN(void) { return this->bookISBN; }

string	bookType::getPublisher(void) { return this->bookPublisher; }

int		bookType::getPublishYear(void) { return this->bookPublishYear; }

int		bookType::getNoOfAuthors(void) { return this->noOfAuthors; }

string	bookType::getAuthor(int index)
{
	if (index < 0 || index >= this->noOfAuthors)
	{
		cout << "Error. Failed to get author name" << endl;
		return "";
	}
	return this->authors[index];
}

int		bookType::getQuantity(void) { return this->quantity; }

double	bookType::getPrice(void) { return this->price; }

void	bookType::updateQuantity(int quantity)
{
	if (quantity < 0)
	{
		cout << "Error. Failed to update" << endl;
		return ;
	}
	this->quantity = quantity;
}
