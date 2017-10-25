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
   int data = 0;
   int borrow = 0;
   int carry = 0;
   BCDnode* moreSDptr; // Node pointer to the next more significant digit (next)
   BCDnode* lessSDptr; // Node pointer to the next least significant digit (prev)




}; // Closing 'struct Node'

   // Note: Fields can be initialized in EITHER the .h or the .cpp

   // ---- FIELDS ----
BCDnode* headptr;
bool isPositive = true; // Sign to determine whether this BCD is positive or negative
int length = 1;

// ---- CONSTRUCTORS ----
// BCD::BCD() - Constructs a new BCD with a value of "0"
// "In the BCD namespace, method named BCD receiving (<no arguments>), initializing 'head' to 'nullptr' and executing {<no commands>}
BCD::BCD() { // By default, the node pointer (BCDnode*) named 'head' is initialized to nullptr
   
   headptr = new BCDnode();
   BCDnode* body = new BCDnode(0, headptr, headptr); // Generates new node with value of 0, headptr set to both 'next' and 'prev'
   headptr->lessSDptr = body;
   headptr->moreSDptr = body;
}

// BCD::BCD(int someInt) - Constructs a new BCD with an equivalent value to the received argument int
BCD::BCD(int someInt) {
   // Determine if the passed int is positive or negative
   if (someInt < 0) {
      isPositive = false;
      // Reverse the sign of the received int so BCD formation is performed with all positive nodes
      cout << "Achtung! This is negative!" << endl;
      someInt = someInt * -1;
   }

   // Make the head node
   headptr = new BCDnode();
   // Generates new node with value of the LSD of the int passed, headptr set to both 'next' and 'prev'
   BCDnode* body = new BCDnode((someInt % 10), headptr, headptr);
   headptr->lessSDptr = body;
   headptr->moreSDptr = body; // 4 of 4 pointers are set
   someInt = someInt / 10; // Divide

   while (someInt > 0) { // Breaks after Most SigDigit is divided by 10
      insertMSD(someInt % 10); // Remainder of the int when divided by 10 is always the least significant digit
      someInt = someInt / 10; // Drop the Least SigDigit from someInt
      cout << someInt << endl;
   }
}

// BCD::BCD(const BCD&) - Constructs a new BCD that is a deep copy of the received argument BCD reference
BCD::BCD(const BCD& someBCD) {
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

// + - Custom behavior for the addition operator when dealing with a BCD object (left) and a BCD object (right)
// Parameters: term1BCD - The original BCD object being added to ; term2BCD - The BCD number being added to the term1BCD.
// Preconditions: None
// Postconditions: A new BCD object exists representing the summed addition of the old BCD and received BCD.
// Return value: A new BCD object representing the summed addition
// Functions called: BCD::BCD(int) - Converts an int to a BCD object
BCD operator+(BCD& term1BCD, BCD& term2BCD) { // where 'someInt' is the input variable and 'thisBCD' is the original BCD object
                                              // Term1BCD exists
                                              // Term2BCD exists


   cout << "Wheeee!" << term1BCD.toString() << term2BCD.toString() << endl;
   BCD sumBCD; // Generate a sumBCD with value set to 0.
               // < Implement addition logic here >
               // Step 1, set current for all BCDs to Least SigDigit
               // currT1 = term1BCD.headptr->moreSDptr;
               // currT2 = term2BCD.headptr->moreSDptr;
               // currSum = sumBCD.headptr->moreSDptr;
   if (term1BCD.isPositive && term2BCD.isPositive) {
      cout << "Both terms are positive, so add()" << endl;
      sumBCD = term1BCD.add(term2BCD);
   }
   else if (term1BCD.isPositive && !term2BCD.isPositive || !term1BCD.isPositive && term2BCD.isPositive) {
      // Determine which is greater, send that first
      // Determine final sign, reserve it
      bool reserveSign = true;
      sumBCD = term1BCD.subtract(term2BCD);
      sumBCD.isPositive = reserveSign;
   }
   else {
      sumBCD = term1BCD.add(term2BCD);
   }
   return sumBCD;
}

// = - Custom behavior for the assignment operator when dealing with a BCD object (left) and a BCD object (right)
// Parameters: oldBCD - The original BCD object being overwritten ; newBCD - The BCD number being assigned.
// Preconditions: None
// Postconditions: A new BCD object exists representing the summed addition of the old BCD and received BCD.
// Return value: A new BCD object representing the summed addition
// Functions called: BCD::BCD(int) - Converts an int to a BCD object
/*
BCD operator=(BCD& oldBCD, BCD& newBCD) { // where 'someInt' is the input variable and 'thisBCD' is the original BCD object
// Term1BCD exists
// Term2BCD exists
if oldBCD.headptr == newBCD.headptr{
// < These are the same thing
// break;
}
cout << "Wheeee!" << endl;
BCD sumBCD; // Generate a sumBCD with value set to 0.
// < Implement addition logic here >
// Step 1, set current for all BCDs to Least SigDigit
// currT1 = term1BCD.headptr->moreSDptr;
// currT2 = term2BCD.headptr->moreSDptr;
// currSum = sumBCD.headptr->moreSDptr;
BCD::BCDnode* T1Curr = term1BCD.headptr->lessSDptr;
BCD::BCDnode* T2Curr = term1BCD.headptr->lessSDptr;
BCD::BCDnode* sumCurr = sumBCD.headptr->lessSDptr;
return sumBCD;
}
*/

//const BCD& operator=(const BCD&) {
// Test that "this != RightHandArgument" - If same, you'll end up deleting the thing, then filling it with its deleted self
// So if the test fails, we don't proceed any further and nothing happens (break)
// < Needs a
// clear() then
// copy() call - Recommend breaking out clear() and copy() to simplify code, gets reused during constructors and destructors
// Because the thing you're overwriting needs to be deallocated and emptied out before you attempt to replace it
// return(*this); // We need this line?
//}

// TODO: Implement copy() - Deep copy of all nodes

// TODO: Implement clear() - Deletes all nodes and deallocates memory

// TODO: Implement add(BCD, BCD)
BCD const BCD::add(const BCD& term2BCD) { // Need to fully qualify method location before 'this' becomes available for use
   cout << "Starting add()" << endl;
   cout << this->toString();
   cout << term2BCD.toString();
   cout << "term1, node1: " << (*this).headptr->moreSDptr->data << endl; // 'this' is a pointer - Access by dereferencing to a BCD.
   cout << "term2, node1: " << term2BCD.headptr->moreSDptr->data << endl; // term2BCD is a BCD - Access with . notation
   //int sum = (this.headptr->moreSDptr->data) + (term2BCD.headptr->moreSDptr->data);
   int sum = 0;
   int addCarry = 0;
   BCD sumBCD;
   int iteration = 0;
   bool terminate = false;
   BCDnode* T1curr = this->headptr->moreSDptr; // Set T1 current to term1's first node
   BCDnode* T2curr = term2BCD.headptr->moreSDptr; // Set T2 current to term2's first node
   BCDnode* sumcurr = sumBCD.headptr->moreSDptr;
   cout << "T1curr: " << T1curr->data << endl;
   cout << "T2curr: " << T2curr->data << endl;
   cout << "Sumcurr: " << sumcurr->data << endl;
   cout << "Sumcurr.carry: " << sumcurr->carry << endl;

   // While both BCDs are not resting at the head node...
   while (terminate == false) {
      iteration++;
      // Sum the two terms...
      sum = (T1curr->data) + (T2curr->data) + sumcurr->carry;
      // If it's 0-9, assign directly to the sumCurrent node's data field
      if (sum < 10) {
         sumcurr->data = sum;
      }
      // Otherwise, separate out the tens and ones to different variables
      else {
         addCarry = sum / 10;
         sum = sum % 10;
         // And assign the sum appropriately (carry is performed down below)
         sumcurr->data = sum;
      }
      cout << "sumcurr data: " << sumcurr->data << endl;

      // Advance T1 current node if it's not back on the head.
      if (T1curr != this->headptr) {
         T1curr = T1curr->moreSDptr;
      }

      // Advance T2 current node if it's not back on the head.
      if (T2curr != term2BCD.headptr) {
         T2curr = T2curr->moreSDptr;
      }

      cout << "T1curr: " << T1curr->data << endl;
      cout << "T2curr: " << T2curr->data << endl;
      // Test for exit condition, both T1curr and T2curr are back at the headptr and there is no carry to deal with.
      if (T1curr == this->headptr && T2curr == term2BCD.headptr && addCarry == 0) {
         terminate = true;
      }
      // If they aren't, we're going another round...
      else {
         // And the sumBCD will need another node for that.
         sumBCD.insertMSD(0);
         sumcurr->moreSDptr->carry = addCarry;
         // Which we then advance to:
         sumcurr = sumcurr->moreSDptr;

         // And re-zero our working variables so it doesn't muddle additions on the next cycle
         sum = 0;
         addCarry = 0;
      }
   } // Closing while loop

   cout << "sum of T1 and T2: " << sumBCD.toString() << endl;
   // Send the sumBCD, now complete, back to whatever called this function
   return(sumBCD);
}

// TODO: Implement subtract (BCD, BCD)
BCD const BCD::subtract(const BCD& term2BCD) {
   cout << "This is the subtract() method" << endl;
   return(term2BCD);
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
   if (someNodeptr->lessSDptr == headptr || someNodeptr->moreSDptr == headptr) {
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
const string BCD::toString() const {
   //	cout << "Begin toString()" << endl; // DEBUG
   string returnString = "Start toString(): ";

   // Append the headptr dereference's nodeName to the returnString.
   // returnString += headptr->nodeName;
   // Append the first body pointer's nodeName to the returnString
   // returnString += headptr->lessSDptr->nodeName;

   // Set the current node to the Most SigDigit
   BCDnode* currentNodeptr = headptr->lessSDptr;
   // While currentNodeptr is *not* back on the head...
   while (currentNodeptr != headptr) {
      // Append the actual data to the returnString
      returnString += std::to_string(currentNodeptr->data);
      // And move the current node to the next Less SigDigit
      currentNodeptr = currentNodeptr->lessSDptr;
   }
   return returnString;
}
