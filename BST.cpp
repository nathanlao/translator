/*
 * BST.cpp
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Inspired from our textbook
 * Date of last modification: Feb. 2022
 */

#include "BST.h"
	
// You can modify the implementation of these methods, but cannot modify their proptotype.
// However, if you modify the implementation of these methods, your code must still 
// satisfy the documentation contract above each of these methods.

/* Constructors and destructor */

	// Default constructor
    template<class ElementType>
	BST<ElementType>::BST() {
		root = NULL;
		elementCount = 0;
	}
	
	// Parameterized constructor
    template<class ElementType>      
    BST<ElementType>::BST(ElementType& element) {
		root = new BSTNode<ElementType>(element);
		elementCount = 1;	
	}               

    // Copy constructor
    template<class ElementType>  
	BST<ElementType>::BST(const BST<ElementType>& aBST)  
	{
		// to do
		// Testing purpose
		// cout << "Calling copy constructor" << endl; 
		root = copyR(aBST.root);
		elementCount = aBST.elementCount;
	}

	// Destructor 
    template<class ElementType> 
	BST<ElementType>::~BST() {

    	// to do
		// Testing purpose
		//cout << "Calling destructor." << endl;
		this -> clearR(root);
    }                     
	
/* Getters and setters */

    // Description: Returns the number of elements currently stored in the binary search tree.	
	// Time efficiency: O(1)
    template<class ElementType>	
	unsigned int BST<ElementType>::getElementCount() const {		

		return this->elementCount;
	}
	

/* BST Operations */

    // Description: Inserts an element into the binary search tree.
	//              This is a wrapper method which calls the recursive insertR( ).
	// Precondition: "newElement" does not already exist in the binary search tree.
    // Exception: Throws the exception "ElementAlreadyExistsException" 
	//            if "newElement" already exists in the binary search tree.
	// Time efficiency: O(log2 n)	
    template<class ElementType>
	void BST<ElementType>::insert(const ElementType& newElement) {
		
	    // Binary search tree is empty, so add the new element as the root
		if (elementCount == 0) {
			root = new BSTNode<ElementType>(newElement);
			elementCount++;
		}
		else 
		  if ( !insertR(newElement, root) ) {
  	         throw ElementAlreadyExistsException("Element already exists in the data collection.");
  	      }
  	   return;
  	}

    // Description: Recursive insertion into a binary search tree.
	//              Returns true when "anElement" has been successfully inserted into the 
	//              binary search tree. Otherwise, returns false.
    template<class ElementType>
	bool BST<ElementType>::insertR(const ElementType& anElement, BSTNode<ElementType>* current) { 
		
		// to do
		bool ableToInsert = false;

		// Base case: if anElement is alreaday exist, return false(unable to insert)
		if (anElement == current -> element) {
			ableToInsert = false;
		} else {
			// If the element in the current node is > the element we are inserting 
			if (current -> element > anElement) {
				// insert anElement at left of current node 
				if (current -> left != NULL) {
					// recursive back 
					return insertR(anElement, current -> left);
				} else {
					// Insert anElement at the left of current node
					// if left of the current node is NULL
					current -> left = new BSTNode<ElementType>(anElement);
					ableToInsert = true;
				}
				// if the element in the current node is <= the element we are inserting
			} else {
				// insert anElement at right side
				if (current -> right != NULL) {
					// recursive back
					return insertR(anElement, current -> right);
				} else {
					// Insert a new node at the right side
					// if there is nothing in the right side of current node
					current -> right = new BSTNode<ElementType>(anElement);
					ableToInsert = true;
				}
			}
		}
		elementCount++;
		return ableToInsert;
	}

	
    // Description: Retrieves "targetElement" from the binary search tree.
	//              This is a wrapper method which calls the recursive retrieveR( ).
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
	//            thrown from the retrieveR(...)
	//            if "targetElement" is not in the binary search tree.
	// Time efficiency: O(log2 n)
    template<class ElementType>
    ElementType& BST<ElementType>::retrieve(const ElementType& targetElement) const {
        
	    // Check precondition: If binary search tree is empty
		if (elementCount == 0)  
			throw EmptyDataCollectionException("Binary search tree is empty.");
		
		// Otherwise, search for it		
		ElementType& translated = retrieveR(targetElement, root);

		return translated;
	}

    // Description: Recursive retrieval from a binary search tree.
	// Exception: Throws the exception "ElementDoesNotExistException" 
	//            if "targetElement" is not found in the binary search tree.
    template<class ElementType>
    ElementType& BST<ElementType>::retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const {

		// to do
		// If targetElement is not found, throw exception
		if (current == NULL) {
			throw ElementDoesNotExistException("Element does not exist in the data collection.");
		} else {
			// otherwise, element found and we do the next:
			// Base case: return the element if we found it (root).
			if (current -> element == targetElement) {
				return current -> element;

				// go to left child if element in current node > target
			} else if (current -> element > targetElement) {
				return retrieveR(targetElement, current -> left);

				// go to right child if element in current node < target
				// no need to consider the (=) case, since no duplicated elements are allowed
			} else {
				return retrieveR(targetElement, current -> right);
			} 
		}

	} // end of retrieveR
				
	
    // Description: Traverses the binary search tree in order.
	//              This is a wrapper method which calls the recursive traverseInOrderR( ).
	//              The action to be done on each element during the traverse is the function "visit".
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Time efficiency: O(n)		
    template<class ElementType>
	void BST<ElementType>::traverseInOrder(void visit(const ElementType&)) const {
		
		// Check precondition: If binary search tree is empty
		if (elementCount == 0)  
			throw EmptyDataCollectionException("Binary search tree is empty.");

		traverseInOrderR(visit, root);
		
		return;
	}

    // Description: Recursive in order traversal of a binary search tree.	
	template<class ElementType>
	void BST<ElementType>::traverseInOrderR(void visit(const ElementType&), BSTNode<ElementType>* current) const {
		
		// to do
		// If this is not empty BST
		if (current != NULL) {

			// traverse the left child if possible
			if (current-> left != NULL) {
				traverseInOrderR(visit, current -> left);
			}

			visit(current -> element); // process the current node

			// traverse the right child if possible
			if (current -> right != NULL) {
				traverseInOrderR(visit, current -> right);
			}
		}
	}
	
	// Description: Recursive copy the elements from binary search tree.
	template<class ElementType>
	BSTNode<ElementType>* BST<ElementType>::copyR(BSTNode<ElementType>* copyNode) {
		if (copyNode == NULL) {
			return NULL;
		}

		// copy node to newNode
		BSTNode<ElementType>* newNode = new BSTNode<ElementType>(copyNode -> element);

		// Go to the left child and copy the node if possible
		if (copyNode -> left != NULL) {
			newNode->left = copyR(copyNode->left);
		}

		// Go to the right child and copy the node if possible
		if (copyNode -> right != NULL) {
			newNode->right = copyR(copyNode->right);
		}
		
		return newNode;
	}	

	// Description: Recursive clear from a binary search tree.
	template<class ElementType>
	void BST<ElementType>::clearR(BSTNode<ElementType>* Node) {

		// If node is pointing to something
		if (Node != NULL) {

			if (Node -> left != NULL) {
				clearR(Node->left); // remove left child
			}
			
			if (Node -> right != NULL) {
				clearR(Node->right); // remove right child
			}

			delete Node;	// delete the node we are pointing to
			Node = NULL;
		}
	}