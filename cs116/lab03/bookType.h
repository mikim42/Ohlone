/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bookType.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:19:36 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/13 22:06:00 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOKTYPE_H
# define BOOKTYPE_H
# include <string>
# include <iostream>
# include <fstream>

using namespace std; 
 
class bookType 
{
	public:
		// TODO
		bookType();
		~bookType();

		void	setBookInfo(string title, string ISBN, string Publisher,
							int PublishYear, string auth[], double cost,
							int copies, int authorCount);

		string	getTitle(void);
		string	getISBN(void);
		string	getPublisher(void);
		int		getPublishYear(void);
		int		getNoOfAuthors(void);
		string	getAuthor(int index);
		int		getQuantity(void);
		double	getPrice(void);

		void	updateQuantity(int quantity);
	private:
		string	bookTitle;
		string	bookISBN;
		string	bookPublisher;
		int		bookPublishYear;

		int		noOfAuthors;
		string	authors[4];

		int		quantity;
		double	price;
};

void	getBookData(bookType books[], int& noOfBooks);
void	printBookData(bookType books[], int noOfBooks);
void	searchBookData(bookType books[], int noOfBooks);
void	searchBookDataByISBN(bookType books[], int noOfBooks, string ISBN,
								int& loc);
void	searchBookDataByTitle(bookType books[], int noOfBooks, string title,
								int& loc);
void	updateCopiesInStock(bookType books[], int noOfBooks);
void	showMenu();
void	subMenu();

#endif
