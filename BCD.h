// Tim Lum
// twhlum@gmail.com
// 2017.10.10
// For the University of Washington Bothell CSS 501A
// Autumn 2017, Graduate Certificate in Software Design & Development (GCSDD)
//
// File Description:
// This file is the header (definitions) of the PunchCard class.
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

using namespace std;

class BCD {
   // --- PRIVATE REGION --- PRIVATE REGION --- PRIVATE REGION ---
   private:

   // PRIVATE FIELDS:
   // ---- FIELDS ----

   // length: For the head node only. Integer representing the node length of this BCD number ("1-2-3-4" has a length of "4")
   // Invariant information: Range is from 0 to the maximimum value of an int (2,147,483,647)
   int length;

   // isPositive: For the head node only.
   // Invariant information:
   bool isPositive;

   // prevBCD: A BCD address. Points to the Most Significant Digit (MSD) if this node is the head, points to next least significant digit (LSD) if not.
   // Invariant information: 
   BCD* prevBCD; // Type is a BCD address. Must assign it &someBCD

   // nextBCD: A BCD address. Points to LSD if this node is the head, points to next most significant digit if not.
   // Invariant information:
   BCD* nextBCD; // Type is a BCD address. Must assign it &someBCD

   // headBCD: A BCD address. Points to the head of this node's number string.
   // Invariant information:
   BCD* headBCD;

   // value: An integer representing the numeric digit stored at this position. Value is Null for head.
   // Invariant information: Value is in range from 0 to 9.
   int value;

   // carry: An integer representing whether this node has received a carry during an addition operation. (i.e. In "2-3" + "8", node "2" will receive a carry)
   // Invariant information: Value is always 0 when no algebraic operation is being performed.
   int carry;

   // borrow: An integer representing whether this node has provided a borrow during a subtraction operation.
   // Invariant information: Value is always 0 when no algebraic operation is being performed.
   int borrow;

   // PRIVATE METHODS:


   // --- PUBLIC REGION --- PUBLIC REGION --- PUBLIC REGION ---
   public:

   struct Node;

   // PUBLIC FIELDS:

   // PUBLIC METHODS:

   // ---- CONSTRUCTORS ----
   // BCD() - Default constructor.
   // Parameters: None
   // Preconditions: None
   // Postconditions: A BCD object exists with an internal state representing "0"
   // Return value: None
   // Functions called: None
   BCD();

   // BCD(int) - Integer constructor.
   // Parameters: None
   // Preconditions: None
   // Postconditions: A BCD object exists with an internal state representing the integer passed to it
   // Return value: None
   // Functions called: None
   BCD(int someInt);

   // BCD(BCD&) - Deep copy constructor
   // Parameters: None
   // Preconditions: None
   // Postconditions: A BCD object is created with an internal state identical to but distinct from the received BCD argument.
   // Return value: None
   // Functions called: None
   BCD(const BCD&);

   // const <return type> <method name>( <arguments> );
   // e.g. const bool checkIfLastCard();

   // isLastCard() - Declares whether the node in question is the last node in a linked list (.next or .prev leads to a node with a null value)
   // Parameters: No internal fields
   // Preconditions: None
   // Postconditions: None
   // Return value: boolean, representing whether this is the "last" card in a stack (true) or not (false).
   // Functions called: None
   const bool isLastNode();

   // insertMSD() - Inserts a node at the Most Significant Digit position
   // Parameters: someData - Used to populate the new node's data field.
   // Preconditions: None
   // Postconditions: A new node is inserted as the the least significant digit position in the BCD
   // Return value: None
   // Functions called: None
   const void BCD::insertMSD(int someData);

   // insertLSD() - Inserts a node at the Least Significant Digit position
   // Parameters: someData - Used to populate the new node's data field.
   // Preconditions: None
   // Postconditions: A new node is inserted as the the least significant digit position in the BCD
   // Return value: None
   // Functions called: None
   const void BCD::insertLSD(int someData);

   // toString() - To return a string representation of the BCD object.
   // Parameters: someData - Used to populate the new node's data field.
   // Preconditions: None
   // Postconditions: A new node is inserted as the the most significant digit position in the BCD
   // Return value: None
   // Functions called: None
   const string toString();

   // >> - Custom behavior for the insertion operator when dealing with an istream object (left) and a PunchCard object (right)
   // Parameters: thisLine - Used to store successive lines of data from cin.
   // Preconditions: Content must be loaded to cin, terminated by newline characters.
   // Postconditions: inputArray will be loaded with the first 80 characters of the first 12 lines of input from cin.
   // Return value: None
   // Functions called: getline - Pulls the first line of data from cin
   // If it's in the class definition, include 'friend'
   friend istream& operator>>(istream& cinData, BCD& someBCD);
   //     inputStream (by reference) operator-named->> ( <left argument type>(by reference) <left argument name>, <right argument type>(by reference) <right argument name>);

   // >> - Custom behavior for the extraction operator when dealing with an ostream object (left) and a BCD object (right)
   // Parameters: thisNumber - Used to store successive digits to be sent to 'cout'.
   // Preconditions: None
   // Postconditions: String representation of the BCD object will be sent to 'cout'.
   // Return value: None
   // Functions called: BCD::toString() - Converts BCD digits to a string object.
   // If it's in the class definition, include 'friend'
   friend ostream& operator<<(ostream& coutStream, BCD& someBCD);


   // ---- DESTRUCTORS -----
   ~BCD();

}; // Closing 'class BCD'
