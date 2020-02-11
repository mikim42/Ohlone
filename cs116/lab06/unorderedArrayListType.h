/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unorderedArrayListType.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:16:20 by mikim             #+#    #+#             */
/*   Updated: 2018/03/27 23:28:47 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 **	Mingyun Kim
 **	https://www.github.com/mikim42
 */

#ifndef H_unorderedArrayListType
#define H_unorderedArrayListType

# include "arrayListType.h"

template <class T>
class unorderedArrayListType: public arrayListType
{
	private:
		T	*list;
	public:
		//	function overloading
		void print() const
		{
			for (int i = 0; i < length; i++)
				cout << list[i] << " ";
			cout << endl;
		}	//	end print

		void insert(T insertItem) 
		{
			//	check if the list if full
			if (this->length >= this->maxSize)
				cout << "[!] List is full." << endl;
			else
			{	//	update all items in the list
				for (int i = this->length; i > 0; i--)
					this->list[i] = this->list[i - 1];
				//	put new item at the front
				this->list[0] = insertItem;
				//	update the length
				this->length++;
			}
		}	//	end insert

		int seqSearch(int searchItem) const
		{
			//	iterate through the list
			for (int i = 0; i < this->length; i++)
			{
				//	if found, return the index 
				if (this->list[i] == searchItem)
					return (i);
			}
			//	if not found, return -1
			return (-1);
		}	//	end seqSearch

		int seqSearch(T searchItem) const
		{
			//	iterate through the list
			for (int i = 0; i < this->length; i++)
			{
				//	if found, return the index 
				if (this->list[i] == searchItem)
					return (i);
			}
			//	if not found, return -1
			return (-1);
		}	//	end seqSearch

		void insertAt(int location, int insertItem)
		{
			//	check if the location is out of range
			if (location < 0 || location > this->length ||
					this->length >= this->maxSize || location >= this->maxSize)
				cout << "[!] Location is out of range." << endl;
			else
			{
				//	update all items in the list
				for (int i = this->length; i > location; i--)
					this->list[i] = this->list[i - 1];
				//	put new item at the location
				this->list[location] = insertItem;
				//	update the length
				this->length++;
			}
		}	//	end insertAt

		void insertAt(int location, T insertItem)
		{
			//	check if the location is out of range
			if (location < 0 || location > this->length ||
					this->length >= this->maxSize || location >= this->maxSize)
				cout << "[!] Location is out of range." << endl;
			else
			{
				//	update all items in the list
				for (int i = this->length; i > location; i--)
					this->list[i] = this->list[i - 1];
				//	put new item at the location
				this->list[location] = insertItem;
				//	update the length
				this->length++;
			}
		}	//	end insertAt

		void insertEnd(int insertItem)
		{
			//	check if the list is full
			if (this->length >= this->maxSize)
				cout << "[!] The list is full." << endl;
			else
			{
				//	put new item at the end
				this->list[this->length] = insertItem;
				//	update the length
				this->length++;
			}
		}	//	end insertEnd

		void insertEnd(T insertItem)
		{
			//	check if the list is full
			if (this->length >= this->maxSize)
				cout << "[!] The list is full." << endl;
			else
			{
				//	put new item at the end
				this->list[this->length] = insertItem;
				//	update the length
				this->length++;
			}
		}	//	end insertEnd

		void replaceAt(int location, int repItem)
		{
			//	check if the location is out of range
			if (location < 0 || location > length || location >= maxSize)
				cout << "[!] Location is out of range." << endl;
			//	replace the item
			this->list[location] = repItem;
		}	//	end replaceAt

		void replaceAt(int location, T repItem)
		{
			//	check if the location is out of range
			if (location < 0 || location > length || location >= maxSize)
				cout << "[!] Location is out of range." << endl;
			//	replace the item
			this->list[location] = repItem;
		}	//	end replaceAt

		void remove(int removeItem)
		{
			int	location = -1;
			//	iterate through the list
			for (int i = 0; i < this->length; i++)
			{
				//	get the index when found
				if (this->list[i] == removeItem)
				{
					location = i;
					break ;
				}
			}
			//	print err message when not found
			if (location < 0)
				cout << "[!] The item does not exist in the list." << endl;
			else
			{
				//	update the list
				for (int i = location; i < this->length; i++)
					this->list[i] = this->list[i + 1];
				//	update the length
				this->length--;
			}
		}	//	end remove

		void remove(T removeItem)
		{
			int	location = -1;
			//	iterate through the list
			for (int i = 0; i < this->length; i++)
			{
				//	get the index when found
				if (this->list[i] == removeItem)
				{
					location = i;
					break ;
				}
			}
			//	print err message when not found
			if (location < 0)
				cout << "[!] The item does not exist in the list." << endl;
			else
			{
				//	update the list
				for (int i = location; i < this->length; i++)
					this->list[i] = this->list[i + 1];
				//	update the length
				this->length--;
			}
		}	//	end remove

		unorderedArrayListType(int size)
		{
			if (size <= 0)
			{
				cout << "The array size must be positive. Creating "
					<< "an array of the size 100." << endl;

				maxSize = 100;
			}
			else
				maxSize = size;

			length = 0;

			list = new T[maxSize];
		}	//	end constructor 
};

#endif
