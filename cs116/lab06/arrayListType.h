//	Template

#ifndef H_arrayListType
#define H_arrayListType

using namespace std;
 
class arrayListType 
{
public: 
    bool isEmpty() const;
      //Function to determine whether the list is empty
      //Postcondition: Returns true if the list is empty;
      //               otherwise, returns false.

    bool isFull() const;
      //Function to determine whether the list is full
      //Postcondition: Returns true if the list is full; 
      //               otherwise, returns false.

    int listSize() const;
      //Function to determine the number of elements in 
      //the list.
      //Postcondition: Returns the value of length.

    int maxListSize() const;
      //Function to determine the maximum size of the list
      //Postcondition: Returns the value of maxSize.

    void print() const;
      //Function to output the elements of the list
      //Postcondition: Elements of the list are output on the 
      //               standard output device.

    bool isItemAtEqual(int location, int item) const;
      //Function to determine whether item is the same as
      //the item in the list at the position specified 
      //by location.
      //Postcondition: Returns true if list[location] 
      //               is the same as item; otherwise, 
      //               returns false.
      //               If location is out of range, an 
      //               appropriate message is displayed.

    virtual void insertAt(int location, int insertItem) = 0;
      //Function to insert insertItem in the list at the 
      //position specified by location. 
      //Note that this is an abstract function.
      //Postcondition: Starting at location, the elements of 
      //               the list are shifted down, 
      //               list[location] = insertItem; length++;    
      //               If the list is full or location is out of
      //               range, an appropriate message is displayed.

    virtual void insertEnd(int insertItem) = 0;
      //Function to insert insertItem at the end of 
      //the list. Note that this is an abstract function.
      //Postcondition: list[length] = insertItem; and length++;
      //               If the list is full, an appropriate 
      //               message is displayed.

    void removeAt(int location);
      //Function to remove the item from the list at the 
      //position specified by location 
      //Postcondition: The list element at list[location] is 
      //               removed and length is decremented by 1.
      //               If location is out of range, an 
      //               appropriate message is displayed.

    void retrieveAt(int location, int& retItem) const;
      //Function to retrieve the element from the list at the  
      //position specified by location 
      //Postcondition: retItem = list[location] 
      //               If location is out of range, an 
      //               appropriate message is displayed.

    virtual void replaceAt(int location, int repItem) = 0;
      //Function to replace the elements in the list 
      //at the position specified by location. 
      //Note that this is an abstract function.
      //Postcondition: list[location] = repItem 
      //               If location is out of range, an 
      //               appropriate message is displayed.

    void clearList();
      //Function to remove all the elements from the list 
      //After this operation, the size of the list is zero.
      //Postcondition: length = 0;

    virtual int seqSearch(int searchItem) const = 0;
      //Function to search the list for searchItem.
      //Note that this is an abstract function.
      //Postcondition: If the item is found, returns the 
      //               location in the array where the item is  
      //               found; otherwise, returns -1.

    virtual void remove(int removeItem) = 0;
      //Function to remove removeItem from the list.
      //Note that this is an abstract function.
      //Postcondition: If removeItem is found in the list,
      //               it is removed from the list and length 
      //               is decremented by one.

    arrayListType(int size = 100);
      //Constructor
      //Creates an array of the size specified by the 
      //parameter size. The default array size is 100.
      //Postcondition: The list points to the array, length = 0,
      //               and maxSize = size;

    arrayListType (const arrayListType& otherList);
       //Copy constructor

    virtual ~arrayListType();
      //Destructor
      //Deallocate the memory occupied by the array.

protected:
    int *list;    //array to hold the list elements
    int length;   //variable to store the length of the list
    int maxSize;  //variable to store the maximum 
                  //size of the list
};


#endif
