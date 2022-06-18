/*
 * Dictionary.h
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *              
 * Author: Guanhua Lao
 * Date: Mar 11th 2022
 */

 #pragma once

#include "BST.h"

template <class ElementType>
class Dictionary {
	
private:

/* You cannot change the following data member of this class. */
    BST<ElementType> * keyValuePairs;                  

/* Feel free to add private methods to this class. */

public:

/* You cannot change the prototype of the public methods of this class.
   Remember, if you add public methods to this class, our test driver 
   - the one we will use to mark this assignment - will not know about them
   since we will use these public method prototypes to create our test driver. */

    // Constructors and destructor:
	Dictionary();                               // Default constructor
    Dictionary(ElementType& element);           // Parameterized constructor 
    ~Dictionary();                              // Destructor 
	
    // Dictionary operations:

    // Description: Returns the number of elements in the dictionary
	unsigned int getElementCount() const;
	
	// Description: Puts "newElement" into the dictionary.
	// Precondition: "newElement" does not already exist in the dictionary.
    // Postcondition: newELement inserted into the dictionary
    // Time efficiency: O(log2 n)
	void put(const ElementType& newElement);

	// Description: Gets "newElement" from the dictionary.
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
    // Time efficiency: O(log2 n)
	ElementType& get(const ElementType& targetElement) const;

    // Description: Display the dictionary in order.
    //              The action to be done on each element during the traverse is the function "visit".
    // Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty
    // Time efficiency: O(n)
    void displayContent(void visit(const ElementType&)) const;
	
}; // end Dictionary

#include "Dictionary.cpp" // Including "Dictionary.cpp" (instead of copying the content of Dictionary.cpp) 
                          // is another way of creating templates.