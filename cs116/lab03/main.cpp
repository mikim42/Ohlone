/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*   GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:47:55 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/13 22:17:53 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bookType.h" 
 
int		main()
{
    bookType	books[100];
    int			noOfBooks = 0;
    int			choice = 0;

    getBookData(books, noOfBooks);
    while(choice != 9)
    {
    	// TODO
    	showMenu();
    	cin >> choice;
		switch (choice)
		{
			case 1:
				cout << "[NUMBER] TITLE" << endl;
				for (int i = 0; i < noOfBooks; i++)
					cout << "[" << i + 1 << "] " << books[i].getTitle() << endl;
				break ;
			case 2:
				cout << "[NUMBER] TITLE | ISBN" << endl;
				for (int i = 0; i < noOfBooks; i++)
					cout << "[" << i + 1 << "] " << books[i].getTitle() << " | "
						 << books[i].getISBN() << endl;
				break ;
			case 3:
				searchBookData(books, noOfBooks);
				break ;
			case 4:
				updateCopiesInStock(books, noOfBooks);
				break ;
			case 5:
				printBookData(books, noOfBooks);
				break ;
			case 9:
				return 0;
			default:
				cout << "Wrong input. Please try again." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break ;
		}
		if (cin.eof())
			break ;
    }
    return 0;
}

void	getBookData(bookType books[], int& noOfBooks)
{
    string		title;
    string		ISBN;
    string		Publisher;
    int			PublishYear;
    string		auth[4];
    double		cost;
    int			copies;
    int			authorCount;
    ifstream	infile;
    char		ch;

    infile.open("bookData.txt");
    if (!infile)
    {
        cout << "Cannot open Input file" << endl;
        cout << "Exit the program" << endl;
        return;
    }

    infile >> noOfBooks;
    infile.get(ch);
    for (int i = 0; i < noOfBooks; i++)
    {
        getline(infile, title);
        getline(infile, ISBN);
        getline(infile, Publisher);
        infile >> PublishYear >> cost >> copies >> authorCount;
        infile.get(ch);
        for (int j = 0; j < authorCount; j++)
            getline(infile, auth[j]);
        books[i].setBookInfo(title, ISBN, Publisher, PublishYear,
								auth, cost, copies, authorCount);
    }
}

void printBookData(bookType books[], int noOfBooks)
{
    // TODO
	for (int i = 0; i < noOfBooks; i++)
	{
		cout << "Index: " << i + 1 << endl
			 << "Title: " << books[i].getTitle() << endl
			 << "ISBN: " << books[i].getISBN() << endl
			 << "Publisher: " << books[i].getPublisher() << endl
			 << "Published Year: " << books[i].getPublishYear() << endl;
		for (int j = 0; j < books[i].getNoOfAuthors(); j++)
			cout << "Author [" << j + 1 << "] " << books[i].getAuthor(i)
				 << endl;
		cout << "Number of Copy: " << books[i].getQuantity() << endl
			 << "Price per Copy: " << books[i].getPrice() << endl;
		cout << "--------------------------------------" << endl << endl;
	}
}

void searchBookDataByISBN(bookType books[], int noOfBooks, string ISBN)
{
    // TODO
	for (int i = 0; i < noOfBooks; i++)
	{
		if (books[i].getISBN() == ISBN)
		{
			cout << "Index: " << i + 1 << endl
				 << "Title: " << books[i].getTitle() << endl
				 << "ISBN: " << books[i].getISBN() << endl
				 << "Publisher: " << books[i].getPublisher() << endl
				 << "Published Year: " << books[i].getPublishYear() << endl;
			for (int j = 0; j < books[i].getNoOfAuthors(); j++)
				cout << "Author [" << j + 1 << "] " << books[i].getAuthor(j)
					 << endl;
			cout << "Number of Copy: " << books[i].getQuantity() << endl
				 << "Price per Copy: " << books[i].getPrice() << endl;
			cout << "--------------------------------------" << endl << endl;
		}
	}
}

void searchBookDataByTitle(bookType books[], int noOfBooks, string title)
{
    // TODO
	for (int i = 0; i < noOfBooks; i++)
	{
		if (books[i].getTitle() == title)
		{
			cout << "Index: " << i + 1 << endl
				 << "Title: " << books[i].getTitle() << endl
				 << "ISBN: " << books[i].getISBN() << endl
				 << "Publisher: " << books[i].getPublisher() << endl
				 << "Published Year: " << books[i].getPublishYear() << endl;
			for (int j = 0; j < books[i].getNoOfAuthors(); j++)
				cout << "Author [" << j + 1 << "] " << books[i].getAuthor(j)
					 << endl;
			cout << "Number of Copy: " << books[i].getQuantity() << endl
				 << "Price per Copy: " << books[i].getPrice() << endl;
			cout << "--------------------------------------" << endl << endl;
		}
	}
}

void searchBookData(bookType books[], int noOfBooks)
{
    // TODO
	string	keyword;
	int		choice;

	subMenu();
	cin >> choice;
	cin.clear();
	cin.ignore(256, '\n');
	switch (choice)
	{
		case 1:
			cout << "Enter ISBN: ";
			getline(cin, keyword);
			searchBookDataByISBN(books, noOfBooks, keyword);
			break ;
		case 2:
			cout << "Enter TITLE: ";
			getline(cin, keyword);
			searchBookDataByTitle(books, noOfBooks, keyword);
			break ;
		default:
			cout << "Wrong input. Return to menu." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			break ;
	}
}

void updateCopiesInStock(bookType books[], int noOfBooks)
{
    // TODO
	int		index;
	int		copies = -1;

	cout << "Enter Index of the book you want to update: ";
	cin >> index;
	if (index > 0 || index < noOfBooks)
	{
		cout << "Title: " << books[index - 1].getTitle() << endl
			 << "Number of Copy: " << books[index - 1].getQuantity() << endl
			 << "Enter new Number of Copy: ";
		cin >> copies;
		if (cin.eof())
			return ;
		else if (cin.fail() || copies < 0)
		{
			cout << "Wrong input. Return to menu" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			return ;
		}
		else
			books[index - 1].updateQuantity(copies);
	}
}

void showMenu()
{
	cout << endl;
    cout << "Welcome to Rock's Book Store" << endl;
    cout << "To make a selection enter the number and press enter" 
         << endl;
    cout << "1: Print a list of books" << endl;
    cout << "2: Print a list of books and ISBN numbers" << endl;
    cout << "3: To see if a book in store" << endl;
    cout << "4: To update the number of copies of a book" << endl;
    cout << "5: To print books data" << endl;
    cout << "9: Exit the program." << endl;
}

void subMenu()
{
	cout << endl;
    cout << "Enter" << endl;
    cout << "1: To search the book by ISBN" << endl;
    cout << "2: To search the book by title" << endl;
}
