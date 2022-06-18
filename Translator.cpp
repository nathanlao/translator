/*
 * Translator.cpp
 * 
 * Description: Drives the testing of the BST, the BSTNode, 
 *              the WordPair, the dictionary and all the exceptions classes. 
 *
 * Author: Guanhua Lao
 * Last Modification Date: Mar 11th 2022
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "Dictionary.h"

void display(const WordPair& anElement) {
    cout << anElement;
} // end of display

int main(int argc, char* argv[]) {
    
    Dictionary<WordPair>* dictionary = new Dictionary<WordPair>(); // Create a dictionary of WordPair objects

    string aLine = "";
    string aWord = "";
    string englishW = "";
    string translationW = "";
    string filename = "myDataFile.txt";
    string delimiter = ":";
    size_t pos = 0;
    WordPair translated;

    ifstream myfile(filename); // Read file
    if (myfile.is_open()) {
        cout << "Reading from a file: " << filename << endl;
        // while not EOF (user has not entered CTRL+D)
        while (getline(myfile, aLine)) {

            pos = aLine.find(delimiter); // Find the delimiter and save the position into pos
            englishW = aLine.substr(0, pos); // Get the English word before the delimiter (i.e. <English>:<translation>)
            aLine.erase(0, pos + delimiter.length()); // Remove the englishW and delimiter
            translationW = aLine; // Get the translation word
            WordPair aWordPair(englishW, translationW);

            // insert the word pair into the dictionary using try/catch block
            try {
                dictionary -> put(aWordPair);
            } catch (ElementAlreadyExistsException& anException) {
                cout << "put() unsuccessful because " << anException.what() << endl;
            }
        }
        // Tesing: total number of elements
        //cout << dictionary -> getElementCount() << endl;
        myfile.close(); // Close the file

        // Allow user to get its translation from the dictionary object
        if (argc == 1) {
            
            // Testing purposes:
            // cout << "Enter the English word to get its translation: " << endl;

            while (getline(cin, aWord)) {
                WordPair aWordPair(aWord); // Read the English word

                // retrieve aWordPair from "testing" using a try/catch block
                try {
                    translated = dictionary -> get(aWordPair); // Get the translated word
                    // print aWordPair
                    display(translated);
                } catch (EmptyDataCollectionException& anException) {
                    cout << "get() unsuccessful because " << anException.what() << endl;
                } catch (ElementDoesNotExistException& anException) {
                    cout << "***Not Found!***" << endl;
                }
            }

            // If user entered "display" at the commanc line
        } else if ((argc > 1) && (strcmp(argv[1], "display") == 0)) {
            try {
                dictionary -> displayContent(display);
            } catch (EmptyDataCollectionException& anException) {
                cout << "displayContent() unsuccessful because " << anException.what() << endl;
            }

        }
    } else {
        cout << "Failed to open file.";
    }

    // Call delete to deallocate heap memory
    delete dictionary;

    return 0;
}