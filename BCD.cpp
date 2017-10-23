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

struct BCDnode {
      // Fields: Node fields
      string nodeName = "";
      int data = NULL;
      int borrow = 0;
      int carry = 0;
      BCDnode* moreSDptr; // Node pointer to the next more significant digit (next)
      BCDnode* lessSDptr; // Node pointer to the next least significant digit (prev)

      // Default node constructor
      BCDnode( ) : nodeName("Head Node"), data(NULL), moreSDptr(nullptr), lessSDptr(nullptr) { }
      // Post-condition: Node exists with no data, next and prev pointers do not indicate anything.

      // Node constructor using a value and the pointers for its adjacent nodes
      BCDnode(int someData, BCDnode* moreSigDigit, BCDnode* lessSigDigit) :
         nodeName("Body Node"),
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
BCDnode* headptr;
bool isPositive; // Sign to determine whether this BCD is positive or negative
int length;

// ---- CONSTRUCTORS ----
// BCD::BCD() - Constructs a new BCD with a value of "0"
// "In the BCD namespace, method named BCD receiving (<no arguments>), initializing 'head' to 'nullptr' and executing {<no commands>}
BCD::BCD( ) { // By default, the node pointer (BCDnode*) named 'head' is initialized to nullptr
   headptr = new BCDnode();
   BCDnode* body = new BCDnode(0, headptr, headptr); // Generates new node with value of 0, headptr set to both 'next' and 'prev'
   headptr->lessSDptr = body;
   headptr->moreSDptr = body;
}

// BCD::BCD(int someInt) - Constructs a new BCD with an equivalent value to the received argument int
BCD::BCD(int someInt) {
   headptr = new BCDnode();
   BCDnode* body = new BCDnode((someInt% 10), headptr, headptr); // Generates new node with value of the LSD of the int passed, headptr set to both 'next' and 'prev'
   headptr->lessSDptr = body;
   headptr->moreSDptr = body;
   someInt / 10;
   while (someInt > 0) {
      insertMSD(someInt % 10); // Remainder of the int when divided by 10 is always the least significant digit
      someInt / 10;
      // 1234 % 10 = 4
      // '4'
      // 123 % 10 = 3
      // '3-4'
      // 12 % 10 = 2
      // '2-3-4'
      // 1 % 10 = 1
      // '1-2-3-4'
      // 0 - Loop breaks
   }
}

// BCD::BCD(const BCD&) - Constructs a new BCD that is a deep copy of the received argument BCD reference
BCD::BCD(const BCD&) {
   // <IMPLEMENTATION GOES IN HERE>
   // To copy a structure:
   //BCDnode originalNode;
   //BCDnode copiedNode = originalNode; // Should copy the internal values of the node, one by one.
}

// Destructor
// TODO: DELETE ALL NODES IN THE BCD! This is where that happens.
BCD::~BCD() {
   /*
   // To create a BCDnode instance:
   BCDnode *newNode = new BCDnode;
   
   Node* tempptr;
   for (; headptr; headptr = tempptr)
   {
      tempptr = headptr -> next;
      delete headptr;
   } */
}

// ----OVERLOADS----

// >> - Custom behavior for the insertion operator when dealing with an istream object (left) and a BCD object (right)
// Parameters: thisLine - Used to store successive lines of data from cin.
// Preconditions: Content must be loaded to cin, terminated by newline characters.
// Postconditions: inputArray will be loaded with the first 80 characters of the first 12 lines of input from cin.
// Return value: None
// Functions called: None
istream& operator>> (istream& cinData, BCD& someBCD) { // where 'cinData' is the input variable and 'someBCD' is the BCD object
   string thisLine = "";
   //<Implementation goes here>
   return (cinData);
}

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
   thisBCDNumber += someBCD.toString();
   coutStream << thisBCDNumber;
   return coutStream;
}

// isLastNode() - Declares whether the node in question is the last node in a linked list (.next or .prev leads to a node with a null value)
// Parameters: No internal fields
// Preconditions: None
// Postconditions: None
// Return value: boolean, representing whether this is the "last" card in a stack (true) or not (false).
// Functions called: None
const bool isLastNode(BCDnode* someNodeptr) {
   // Flag to determine whether this is the last node or not
   bool isLast = false;
   // Test criteria, can be returned directly (TODO?)
   // If the passed node's lessSDptr or moreSDptr point to the head, then this is a last node.
   if (someNodeptr -> lessSDptr == headptr || someNodeptr -> moreSDptr == headptr) {
      isLast = true;
   }
   // Return flag status
   return(isLast);
}

// insertMSD() - Inserts a node at the Most Significant Digit position
// Parameters: someData - Used to populate the new node's data field.
// Preconditions: None
// Postconditions: A new node is inserted as the the least significant digit position in the BCD
// Return value: None
// Functions called: None
const void BCD::insertMSD(int someData) {
   // Make a new node off in space. Its data is the argument passed. Its MSD pointer points to head, its LSD pointer points to the old MSD.
   BCDnode* insertedNodeptr = new BCDnode(someData, headptr, headptr->lessSDptr);
   // Redirects the old MSD's next pointer to the inserted node
   headptr->lessSDptr->moreSDptr = insertedNodeptr; 
   // Redirect the head's lessSDptr to the current node.
   headptr->lessSDptr = insertedNodeptr; 
   // New node created with int data and 4 of 4 pointers are pointed at the correct place
}

// insertLSD() - Inserts a node at the Most Significant Digit position
// Parameters: someData - Used to populate the new node's data field.
// Preconditions: None
// Postconditions: A new node is inserted as the the least significant digit position in the BCD
// Return value: None
// Functions called: None
const void BCD::insertLSD(int someData) {
   // Make a new node off in space. Its data is the argument passed. Its LSD pointer points to head, its MSD pointer points to the old LSD.
   BCDnode* insertedNodeptr = new BCDnode(someData, headptr->moreSDptr, headptr);
   // Redirects the old LSD's next pointer to the inserted node
   headptr->moreSDptr->lessSDptr = insertedNodeptr;
   // Redirect the head's moreSDptr to the current node.
   headptr->moreSDptr = insertedNodeptr;
   // New node created with int data and 4 of 4 pointers are pointed at the correct place
}

// toString() - To return a string representation of the decoded PunchCard.
// Parameters: returnString - Used to concatenate successive characters from the outputArray.
// Preconditions: None
// Postconditions: returnString is 80 characters in length, plus a newline character at its end.
// Return value: A string, 80 characters in length, with a newline character at its end.
// Functions called: None
const string BCD::toString() {
   //	cout << "Begin toString()" << endl; // DEBUG
   string returnString = "toString() test string: ";
   returnString += headptr->nodeName; // Append the headptr dereference's nodeName to the returnString
   returnString += headptr->lessSDptr->nodeName;
   returnString += std::to_string(headptr->lessSDptr->data);
   return returnString;
}
/*
// ---- GLOBAL VARIABLES ----
// - PROHIBITED FOR THIS COURSE -




}











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

// }*/
