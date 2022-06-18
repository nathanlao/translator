/*
 * Dictionary.cpp
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *              
 * Author: Guanhua Lao
 * Date: Mar 11th 2022
 */

#include "Dictionary.h"

/* Constructors and destructor */

    // Default constructor
    template<class ElementType>
    Dictionary<ElementType>::Dictionary(){
        keyValuePairs = NULL;
    }

    // Parameterized constructor
    template<class ElementType>
    Dictionary<ElementType>::Dictionary(ElementType& element) {
        keyValuePairs = new BST<ElementType>(element);
    }

    // Destructor
    template<class ElementType>
    Dictionary<ElementType>::~Dictionary() {
        // Testing purpose
        //cout << "Calling dictionary destructor" << endl;
        
        delete keyValuePairs;
    }

    // Dictionary operations:
    
    // Description: Returns the number of elements in the dictionary
    template<class ElementType>
    unsigned int Dictionary<ElementType>::getElementCount() const {
        
        return keyValuePairs -> getElementCount();
    }

    // Description: Puts "newElement" into the dictionary.
	// Precondition: "newElement" does not already exist in the dictionary.
    // Postcondition: newELement inserted into the dictionary
    // Time efficiency: O(log2 n)
    template<class ElementType>
    void Dictionary<ElementType>::put(const ElementType& newElement) {
        // Put root
        if (keyValuePairs == NULL) {
            keyValuePairs = new BST<ElementType>();
            keyValuePairs -> insert(newElement);
        // Put elements into dictionary
        } else {
            keyValuePairs -> insert(newElement);
        }
        return;
    }

    // Description: Gets "newElement" from the dictionary.
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
    // Time efficiency: O(log2 n)
    template<class ElementType>
    ElementType& Dictionary<ElementType>::get(const ElementType& targetElement) const {
        if (keyValuePairs == NULL)  {
			throw EmptyDataCollectionException("Dictionary is empty.");
        }
        // calling BST's public member retrieve()
        return keyValuePairs -> retrieve(targetElement);
    }

    // Description: Display the dictionary in order.
    //              The action to be done on each element during the traverse is the function "visit".
    // Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty
    // Time efficiency: O(n)
    template<class ElementType>
    void Dictionary<ElementType>::displayContent(void visit(const ElementType&)) const {
        if (keyValuePairs == NULL)  {
			throw EmptyDataCollectionException("Dictionary is empty.");
        }
        // calling BST's public member traverseInOrder()
        keyValuePairs -> traverseInOrder(visit);
    }

