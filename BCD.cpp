// Tim Lum
// twhlum@gmail.com
// 2017.10.10
// For the University of Washington Bothell CSS 501A
// Autumn 2017, Graduate Certificate in Software Design & Development (GCSDD)
//
// File Description:
// This file is the implementation of the PunchCard class as defined by PunchCard.h
//
// Package files:
// Assg01_Driver_PunchCards.cpp
// PunchCard.cpp
// PunchCard.h
//
// Acknowledgements:
// Source material from:
// University of Washington Bothell
// CSS 501A Data Structures And Object-Oriented Programming I
// "Design and Coding Standards"
// Michael Stiber
//
// Template author:
// Tim Lum (twhlum@gmail.com)
//
// License: (Note to student, the following is optional)
// This software is published under the GNU general license which guarantees
// end users the freedom to run, study, share and modify the software.
// https://www.gnu.org/licenses/gpl.html
//
// Code Standards:
// I. Comment at beginning of file (above) stating (at a minimum):
//    A. File Name
//    B. Author Name
//    C. Date
//    D. Description of code purpose 
// II. Indentation:
//    A. 3 whitespaces ("   ")
//    B. May vary depending on language and instructor
// III. Variables:
//    A. Descriptive, legible name
//    B. Comment over any variable declaration describing:
//       0. Its use in the algorithm
//       1. Invariant information such as legal ranges of values
// IV. Class Files:
//    A. Separate *.cpp and *.h files should be used for each class.
//    B. Files names must exactly match class names (case-sensitive)
// V. Includes:
//    A. Calls for content ("#include") from the Standard Template Library (STL) should be formatted as follows:
//       0. DO type:     #include <vector>
//       1. Do NOT type: #include <vector.h>
//    B. You may use the directive "using namespace std;"
//       0. ??? (?CONFIRM?)
// VI. Classes:
//    A. Return values:
//       0. Do NOT return references to internal class structures.
//       1. Do NOT return pointers to internal class structures.
//    B. Do NOT expose any details of the internal implementation.
// VII. Functions + Methods:
//    A. Functions should be used for appropriate operations.
//    B. Reference arguments should be used only when necessary.
//    C. The (return?CONFIRM?) type of each function must be declared
//       0. Use 'void' when necessary
//    D. Declare as 'const' (unalterable) when no modification is made to the object state
//       0. UML 'query' property (?CONFIRM?)
// VIII. Function Comments:
//    A. DO include a comment prior to each function which includes the function's:
//       0. Purpose - Why does the function exist?
//       1. Parameters - What fields does the function contain?
//       2. Preconditions - What conditions must be true prior to the function call?
//       3. Postconditions - What conditions must be true after the function call?
//       4. Return value - What is the nature and range of the value returned by the function?
//       5. Functions called - What other functions are called by this function?
// IX. Loop invariants
//    A. Each loop should be commented with 'invariant' information (?CONFIRM?)
// X. Assertions:
//    A. May be comments or the 'assert()' feature.
//    B. Insert where useful to explain important features or subtle logic.
//    C. What, exactly, is an assertion (?CONFIRM?)
// XI. Prohibited (unless justified):
//    A. Global variables
//    B. "Gotos" (?CONFIRM?)
//
// Special instructions:
// To update Linux:
// sudo apt-get update && sudo apt-get install
// sudo apt-get update
//
// To make a new .cpp file in Linux:
// nano <file name>.cpp
//
// To make a new .h file in Linux:
// nano <file name>.h
//
// To make a new .txt file in Linux:
// nano <file name>.txt
//
// To compile in g++:
// g++ -std=c++11 PunchCard.cpp main.cpp
//
// To run with test input:
// ./a.out < TestInput.txt
//
// ---- BEGIN STUDENT CODE ----

// ---- IMPORT STATEMENTS ----

#pragma once

//Necessary to interact with 'cin' and 'cout' streams
#include <iostream>

// Necessary for string operations
#include <string>

// Includes the BCD class header
#include "BCD.h"

// ---- NAMESPACE STATEMENTS ----
using namespace std;


// ---- STRUCTS ----

struct Node {
      // Fields: Node fields
      string nodeName = "";
      int data = NULL;
      int borrow = 0;
      int carry = 0;
      Node* moreSDptr; // Node pointer to the next more significant digit (next)
      Node* lessSDptr; // Node pointer to the next least significant digit (prev)

      // Default node constructor
      Node( ) : nodeName("Head Node"), data(NULL), moreSDptr(nullptr), lessSDptr(nullptr) { }
      // Post-condition: Node exists with no data, next and prev pointers do not indicate anything.

      // Node constructor using a value and the pointers for its adjacent nodes
      Node(int someData, Node* moreSigDigit, Node* lessSigDigit) :
         data(someData),
         moreSDptr(moreSigDigit),
         lessSDptr(lessSigDigit)
         {
         // NEEDS TO BE PERFORMED AFTER THIS NODE IS CREATED   moreSigDigit->lessSDptr = thisDigit; // Set backpointer - Dereference the moreSigDigit pointer and acquire that Node's lessSDptr
         // NEEDS TO BE PERFORMED AFTER THIS NODE IS CREATED   lessSigDigit->moreSDptr = thisDigit; // <Set backpointer>
      }
   }; // Closing 'struct Node'

// Note: Fields can be initialized in EITHER the .h or the .cpp
// ---- FIELDS ----
Node* headptr;
bool isPositive; // Sign to determine whether this BCD is positive or negative
int length;

// Constructor - Default
// "In the BCD namespace, method named BCD receiving (<no arguments>), initializing 'head' to 'nullptr' and executing {<no commands>}
BCD::BCD( ) { // By default, the node pointer (Node*) named 'head' is initialized to nullptr
   //struct Node a = Node();   // Need to construct a new node, initialized to value of 0
}

// Destructor
BCD::~BCD() {
  /* Node* tempptr;
   for (; headptr; headptr = tempptr)
   {
      tempptr = headptr -> next;
      delete headptr;
   } */
}
// Closing class BCD

// ----OVERLOADS----
// << - Custom behavior for the extraction operator when dealing with an ostream object (left) and a BCD object (right)
// Parameters: thisBCDNumber - Used to store successive digits to be sent to 'cout'.
// Preconditions: None
// Postconditions: String representation of the BCD object will be sent to 'cout'.
// Return value: None
// Functions called: BCD::toString() - Converts BCD digits to a string object.
// If it's in the class definition, include 'friend'
ostream& operator<< (ostream& coutStream, BCD& someBCD) { // where 'cinData' is the input variable and 'card' is the PunchCard object
   string thisBCDNumber = "Operator<< Test String: ";
   // <Implement all string appending here>
   // thisBCDNumber += BCD::headptr->data;
   coutStream << thisBCDNumber;
   return coutStream;
}




/*
// ---- GLOBAL VARIABLES ----
// - PROHIBITED FOR THIS COURSE -

// ---- CONSTRUCTORS ----
// BCD::BCD() - Constructs a new BCD with a value of "0"
BCD::BCD() {
// <IMPLEMENTATION GOES IN HERE>


}

// BCD::BCD(int someInt) - Constructs a new BCD with an equivalent value to the received argument int
BCD::BCD(int someInt) {
   
   // <IMPLEMENTATION GOES IN HERE>
}
// BCD::BCD(const BCD&) - Constructs a new BCD that is a deep copy of the received argument BCD reference
BCD::BCD(const BCD&) {
   // <IMPLEMENTATION GOES IN HERE>
}






// To create a BCDnode instance:
BCDnode *newNode = new BCDnode;

// To copy a structure:
//BCDnode originalNode;
//BCDnode copiedNode = originalNode; // Should copy the internal values of the node, one by one.

// ---- METHODS ----

// insertMSD() - Inserts a node at the Most Significant Digit position

// insertLSD() - Inserts a node at the Least Significant Digit position

// removeMSD() - Removes a node at the Most Significant Digit position

// removeLSD() - Removes a node at the Least Significant Digit position



// toString() - To return a string representation of the decoded PunchCard.
// Parameters: returnString - Used to concatenate successive characters from the outputArray.
// Preconditions: None
// Postconditions: returnString is 80 characters in length, plus a newline character at its end.
// Return value: A string, 80 characters in length, with a newline character at its end.
// Functions called: None
const string BCD::toString() {
   //	cout << "Begin toString()" << endl; // DEBUG
   string returnString = "";
   return returnString;
}




// ----OVERLOADS----

// >> - Custom behavior for the insertion operator when dealing with an istream object (left) and a PunchCard object (right)
// Parameters: thisLine - Used to store successive lines of data from cin.
// Preconditions: Content must be loaded to cin, terminated by newline characters.
// Postconditions: inputArray will be loaded with the first 80 characters of the first 12 lines of input from cin.
// Return value: None
// Functions called: getline - Pulls the first line of data from cin
istream& operator>> (istream& cinData, BCD& someBCD) { // where 'cinData' is the input variable and 'card' is the PunchCard object
   string thisLine = "";
   //<Implementation goes here>
   return (cinData);
}



// ----DESTRUCTORS----
// BCD::~BCD()
//   <Destructor implementation goes here>
// }*/
