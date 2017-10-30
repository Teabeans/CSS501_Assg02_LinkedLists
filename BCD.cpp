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

// Includes exceptions
#include <stdexcept>

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
   isPositive = true;
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
   else {
      isPositive = true;
   }

   // Make the head node
   headptr = new BCDnode();
   // Generates new node with value of the LSD of the int passed, headptr set to both 'next' and 'prev'
   // Make the first body node
   cout << someInt << endl;
   BCDnode* body = new BCDnode((someInt % 10), headptr, headptr);
   headptr->lessSDptr = body;
   headptr->moreSDptr = body; // 4 of 4 pointers are set
   someInt = someInt / 10; // Divide
   cout << someInt << endl;

   while (someInt > 0) { // Breaks after Most SigDigit is divided by 10
      insertMSD(someInt % 10); // Remainder of the int when divided by 10 is always the least significant digit
      someInt = someInt / 10; // Drop the Least SigDigit from someInt
      cout << someInt << endl;
   }
}

// #ConstructorBCD - Copy Constructor - Page 246
// Constructs a new BCD that is a deep copy of the received argument BCD reference
BCD::BCD(const BCD& someBCD) {
   isPositive = someBCD.isPositive;
   length = someBCD.length;

   // Target the LeastSD node of someBCD
   BCDnode* currTarget = someBCD.headptr->moreSDptr;

   // Head instantiated. Body instantiated with LeastSD node of someBCD data
   headptr = new BCDnode();
   BCDnode* body = new BCDnode((currTarget->data), headptr, headptr);
   headptr->moreSDptr = body;
   headptr->lessSDptr = body;

   // Advance one node (note: this may put us on the head node)
   currTarget = currTarget->moreSDptr;
   while (currTarget != someBCD.headptr) {
      // Add a new node at the MostSD digit location
      insertMSD(currTarget->data);
      // Advance the target by 1 MoreSD place
      currTarget = currTarget->moreSDptr;
   }
   // Target is back on the head, so the list has been copied.
}

// #~BCD() - Destructor - Page 245-246
// Deletes all nodes in a list (appears to work as of 10.27
BCD::~BCD() {
   cout << "~BCD Destructor. Address of targetted headptr is:" << endl << &headptr << endl;
//   obliterate(headptr); // Turning off temporarily
   if (false) {
      BCDnode* currTgtPtr;
      currTgtPtr = headptr->moreSDptr;
      while (currTgtPtr != headptr) {
         cout << endl << "Address of currTarget in obliterate(): " << &currTgtPtr << "(" << currTgtPtr->data << ")" << endl;
         remove(currTgtPtr);
         currTgtPtr = headptr->lessSDptr;
         cout << endl << "CurrTarget changed to address: " << &currTgtPtr << endl << endl;
      }
   }
   cout << "~BCD Destructor complete. Linked list destroyed." << endl << endl;
}



// ----OVERLOADS----


// #int() - Custom behavior for the int conversion operator
// Parameters: 
// Preconditions: A BCD object exists with headptr directed to a valid linked list.
// Postconditions: An int representation of the BCD number between (2^31)-1 and (-)(2^31) has been returned OR an 'out_of_range' error has been thrown.
// Return value: returnInt - Variable storing the value of the BCD integer.
// Functions called: None
BCD::operator int() const {
   // Initial check of BCD length. Used to exclude number out of range of doubles and Long Longs.
   if (numDigits() > 10) {
      throw std::out_of_range("The BCD exceeds the value of an int.");
   }
   // Higher capacity variable used to check from intMax to 999,999,999.
   double overflowInt = 0;
   // Eventual return integer
   int returnInt = 0;
   BCDnode* curr = headptr->lessSDptr;

   while (curr != headptr) {
      // If we're on the next SD, multiply by 10
      overflowInt = overflowInt * 10;
      // Add the next LessSD to the sum...
      overflowInt = overflowInt + curr->data;
      // And move to the next node (if curr lands back on headptr, it will terminate after this).
      curr = curr->lessSDptr;
   }
   if (isPositive == false) {
      overflowInt = overflowInt * (-1);
   }
   // Check to see if the long long is within a valid range...
   if (overflowInt > 2147483647 || overflowInt < (-2147483647 - 1)) {
      throw std::out_of_range("The BCD exceeds the value of an int.");
   }
   // If it's within range, assign to the return variable and send it back.
   else {
      returnInt = (int)overflowInt;
      return(returnInt);
   }
}

// #operator< - Custom behavior for the less-than operator when dealing with a BCD object (left) and a BCD object (right)
// Parameters: 
// Preconditions: 
// Postconditions:
// Return value: Boolean - True if the Left-Hand Term (LHT) is 'less than' the Right-Hand Term (RHT), false if not.
// Functions called: numDigits() - For the length of the BCD object.
bool BCD::operator<(const BCD& someBCD) const {
   // Not less than if it's equal
   if (*this == someBCD) {
      return(false);
   }
   else {
      // Compare BCD sign. If unequal, these are not equal
      if (isPositive > someBCD.isPositive) {
         cout << "Mismatch! Different sign!" << endl; // DEBUG
         return(false);
      }
      // Otherwise, compare BCD length. If unequal, these are not equal
      else if (numDigits() < someBCD.numDigits()) {
         cout << "Mismatch! Different list length!" << endl; // DEBUG
         return(true);
      }
      // Both sign and length are equal, begin node by node comparison:
      else {
         // Queue both BCDs to their MostSD node:
         BCDnode* currT1 = headptr->lessSDptr;
         BCDnode* currT2 = someBCD.headptr->lessSDptr;
         while (currT1 != headptr) {
            // Compare the data of the current nodes. If different, these are not equal.
            if (currT1->data > currT2->data) {
               cout << "Mismatch! Different node data!" << endl; // DEBUG
               // Positive comparison case
               if (isPositive == true) {
                  return(false);
               }
               // Negative comparison case
               else {
                  return(true);
               }
            }
            // If the nodes' data is the same, advance to the next MoreSD.
            else {
               currT1 = currT1->moreSDptr;
               currT2 = currT2->moreSDptr;
            }
         }
      }
   }
}


// #operator== - Custom behavior for the equality operator when dealing with a BCD object (left) and a BCD object (right)
// Parameters: 
// Preconditions: 
// Postconditions: inputArray will be loaded with the first 80 characters of the first 12 lines of input from cin.
// Return value: Boolean - True if BCDs being compared are the 'same', false if not.
// Functions called: numDigits() - For the length of the BCD object.
bool BCD::operator==(const BCD& someBCD) const {
   // Tests for identity:
   if (headptr == someBCD.headptr) {
      return(true);
   }
   else {
      // Compare BCD sign. If unequal, these are not equal
      if (isPositive != someBCD.isPositive) {
         cout << "Mismatch! Different sign!" << endl; // DEBUG
         return(false);
      }
      // Otherwise, compare BCD length. If unequal, these are not equal
      else if (numDigits() != someBCD.numDigits()) {
         cout << "Mismatch! Different list length!" << endl; // DEBUG
         return(false);
      }
      // Both sign and length are equal, begin node by node comparison:
      else {
         // Queue both BCDs to their LeastSD node:
         BCDnode* currT1 = headptr->moreSDptr;
         BCDnode* currT2 = someBCD.headptr->moreSDptr;
         while (currT1 != headptr) {
            // Compare the data of the current nodes. If different, these are not equal.
            if (currT1->data != currT2->data) {
               cout << "Mismatch! Different node data!" << endl; // DEBUG
               return(false);
            }
            // If the nodes' data is the same, advance to the next MoreSD.
            else {
               currT1 = currT1->moreSDptr;
               currT2 = currT2->moreSDptr;
            }
         }
      }
      // All logical equality tests complete as true (Sign, length, data fields)
      return(true);
   }
}









// TODO: Verify that the assignment operator works
// #operator= - Custom behavior for the assignment operator when dealing with a BCD object (left, implied) and a BCD object (right)
// Parameters:
// Preconditions:
// Postconditions:
// Return value:
// Functions called: 
BCD& BCD::operator=(const BCD& rightHandSide) {
   cout << "Starting operator=" << endl;
   if (this != &rightHandSide) {
      this->obliterate();
      this->deepcopy(rightHandSide);
      this->length = rightHandSide.length;
   }
   cout << "Operator= complete... returning *this" << endl;
   return *this;
}











// #operator>> - Custom behavior for the insertion operator when dealing with an istream object (left) and a BCD object (right)
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

// #operator<< - Custom behavior for the extraction operator when dealing with an ostream object (left) and a BCD object (right)
// Parameters: thisBCDNumber - Used to store successive digits to be sent to 'cout'.
// Preconditions: None
// Postconditions: String representation of the BCD object will be sent to 'cout'.
// Return value: None
// Functions called: BCD::toString() - Converts BCD digits to a string object.
// If it's in the class definition, include 'friend'
ostream& operator<< (ostream& coutStream, BCD& someBCD) { // where 'cinData' is the input variable and 'card' is the PunchCard object
   string thisBCDNumber = "";
   // <Implement all string appending here>
   thisBCDNumber += someBCD.toString();
   coutStream << thisBCDNumber;
   return coutStream;
}

// #operator+ - Custom behavior for the addition operator when dealing with a BCD object (left) and a BCD object (right)
// Parameters: term1BCD - The original BCD object being added to ; term2BCD - The BCD number being added to the term1BCD.
// Preconditions: None
// Postconditions: A new BCD object exists representing the summed addition of the old BCD and received BCD.
// Return value: A new BCD object representing the summed addition
// Functions called: BCD::BCD(int) - Converts an int to a BCD object
//const MyClass MyClass::operator+(const MyClass &other) const
const BCD operator+(BCD& term1BCD, BCD& term2BCD) { // where 'someInt' is the input variable and 'thisBCD' is the original BCD object
// Term1BCD exists
// Term2BCD exists

cout << "Starting operator+: " << term1BCD.toString() << term2BCD.toString() << endl;
//   if (term1BCD.isPositive == true && term2BCD.isPositive == true) {
cout << "Positive + Positive: so add()" << endl;
return(term1BCD.add(term2BCD));
cout << "Operator+ completed" << endl;
//   }
   /*   else if (term1BCD.isPositive && !term2BCD.isPositive || !term1BCD.isPositive && term2BCD.isPositive) {
   // Determine which is greater, send that first
   // Determine final sign, reserve it
   cout << "Positive + Negative or Negative + Positive: so subtract()" << endl;
   bool reserveSign = true;
   sumBCD = term1BCD.subtract(term2BCD);
   sumBCD.isPositive = reserveSign;
   }
   else {
   cout << "Negative + Negative: so add()" << endl;
   sumBCD = term1BCD.add(term2BCD);
   } */
   //   return sumBCD;
}

// #operator- - Custom behavior for the subtraction operator when dealing with a BCD object (left) and a BCD object (right)
// Parameters: term1BCD - The original BCD object being subtracted from ; term2BCD - The BCD number being subtracted from term1BCD.
// Preconditions: None
// Postconditions: A new BCD object exists representing the difference of the old BCD and received BCD.
// Return value: A new BCD object representing the difference from subtraction
// Functions called: BCD::BCD(int) - Converts an int to a BCD object
BCD operator-(BCD& term1BCD, BCD& term2BCD) { // where 'someInt' is the input variable and 'thisBCD' is the original BCD object

   cout << "Starting operator-()" << term1BCD.toString() << term2BCD.toString() << endl;
   BCD diffBCD; // Generate a sumBCD with value set to 0.
                // < Implement addition logic here >
                // Step 1, set current for all BCDs to Least SigDigit
                // currT1 = term1BCD.headptr->moreSDptr;
                // currT2 = term2BCD.headptr->moreSDptr;
                // currSum = sumBCD.headptr->moreSDptr;
   diffBCD = term1BCD.subtract(term2BCD);
   /*   if (term1BCD.isPositive && term2BCD.isPositive || !term1BCD.isPositive && !term2BCD.isPositive) {
   cout << "Both terms are positive or both are negative, so subtract()" << endl;
   diffBCD = term1BCD.subtract(term2BCD);
   }
   /*   else if (term1BCD.isPositive && !term2BCD.isPositive || !term1BCD.isPositive && term2BCD.isPositive) {
   cout << "The terms are a mix of positive and negative, so add()" << endl;
   // Determine which is greater, send that first
   // Determine final sign, reserve it
   bool reserveSign = true;
   diffBCD = term1BCD.add(term2BCD);
   diffBCD.isPositive = reserveSign;
   }
   else {
   diffBCD = term1BCD.add(term2BCD);
   }
   */
   return diffBCD;
}

// #deepcopy()
// Precondition:
void const BCD::deepcopy(const BCD& target) {
   cout << "Starting deepcopy()" << endl; // DEBUG
                                          // Test if 'this' and 'target' are the same thing
   if (headptr == target.headptr) {
      cout << "Same target as this, so do nothing" << endl; // DEBUG
   }
   else {
      // Delete all nodes associated with the headpointer (clean slate)
      obliterate();
      // Create a new node - copied from internal values of target.headptr - give its address to headptr.
      cout << "deepcopy() 1" << endl;
      //TODO: BREAKING HERE!
      headptr = new BCDnode();
      // Set current node to the target LeastSD
      cout << "deepcopy() 2" << endl;
      BCDnode* curr = target.headptr->moreSDptr;
      // Generate a new body node, also copied from the current target
      cout << "deepcopy() 3" << endl;
      BCDnode* newBody = new BCDnode(curr->data, headptr, headptr); // 2/4 pointers set
                                                                    // Connect remaining pointers
      cout << "deepcopy() 4" << endl;
      headptr->lessSDptr = newBody;
      headptr->moreSDptr = newBody; // 4/4 pointers are set
      cout << "Copying nodes... " << endl; // DEBUG
      while (curr != target.headptr) { // While we aren't back at the head...
         curr = curr->moreSDptr; // Advance
         insertMSD(curr->data); // Insert a new node at the MostSD using the current data field
      }
      cout << "Node copies completed." << endl; // DEBUG
   }
}

// #obliterate() - Deletes all nodes linked to the specified headnode and deallocates memory
// Parameters: sum - Working variable used to store the integer sum of two nodes. addCarry - Working variable used to store the tens place result of two integers summed. terminate - Terminate flag for a while loop. sumBCD - BCD object used to store successive addition operations.
// Preconditions: None
// Postconditions: None
// Return value: boolean, representing whether this is the "last" card in a stack (true) or not (false).
// Functions called: None
// Breaks if an empty list is sent
void BCD::obliterate() {
   cout << "Start obliterate(): " << endl;
   while (this->isLastNode(headptr)) {
      remove(headptr->lessSDptr);
   }
   /*   BCDnode* currTarget = nullptr;
      // Delete body nodes
      while (currTarget != headptr) {
         currTarget = headptr->lessSDptr;
         cout << endl << "Address of currTarget in obliterate(): " << &currTarget << "(" << currTarget->data << ")" << endl;
         remove(currTarget);

         cout << endl << "CurrTarget changed to address: " << &currTarget << endl << endl;
      }
      cout << "Body nodes deleted" << endl; // DEBUG
      cout << "Targeting head in obliterate() at address: " << headptr << endl; // DEBUG
      remove(headptr);
   cout << "obliterate() destructors being called... " << endl;*/
}



// #add() - Adds a BCD object to another BCD object
// Parameters: sum - Working variable used to store the integer sum of two nodes. addCarry - Working variable used to store the tens place result of two integers summed. terminate - Terminate flag for a while loop. sumBCD - BCD object used to store successive addition operations.
// Preconditions: None
// Postconditions: None
// Return value: boolean, representing whether this is the "last" card in a stack (true) or not (false).
// Functions called: None
BCD const BCD::add(const BCD& term2BCD) const { // Need to fully qualify method location before 'this' becomes available for use
   cout << "Starting add()" << endl;

   int sum = 0;
   int addCarry = 0;
   BCD sumBCD;
   cout << "Address of empty sumBCD: " << &sumBCD << endl;
   cout << "Address of empty sumBCD headptr: " << &sumBCD.headptr << endl;
   bool terminate = false;

   BCDnode* T1curr = this->headptr->moreSDptr;    // Set T1 current node to term1's first node
   BCDnode* T2curr = term2BCD.headptr->moreSDptr; // Set T2 current node to term2's first node
   BCDnode* sumcurr = sumBCD.headptr->moreSDptr;  // Set the sum current node to sumBCD's first node
   // cout << "T1curr: " << T1curr->data << endl; // DEBUG
   // cout << "T2curr: " << T2curr->data << endl; // DEBUG
   cout << "add(), Sumcurr: " << sumcurr->data << endl; // DEBUG
   cout << "add(), Sumcurr.carry: " << sumcurr->carry << endl; // DEBUG

   // While both BCDs are not resting at the head node...
   while (terminate == false) {
      // Sum the two terms...
      sum = (T1curr->data) + (T2curr->data) + sumcurr->carry;
      // Carry having been 'used', reset its value to 0
      sumcurr->carry = 0;
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
      // cout << "sumcurr data: " << sumcurr->data << endl; // DEBUG

      // Advance T1 current node if it's not back on the head.
      if (T1curr != this->headptr) {
         T1curr = T1curr->moreSDptr;
      }

      // Advance T2 current node if it's not back on the head.
      if (T2curr != term2BCD.headptr) {
         T2curr = T2curr->moreSDptr;
      }

      // cout << "T1curr: " << T1curr->data << endl; // DEBUG
      // cout << "T2curr: " << T2curr->data << endl; // DEBUG
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

   cout << "sum of T1 and T2: " << sumBCD.toString() << endl; // DEBUG
   cout << "Address of loaded sumBCD: " << &sumBCD << endl;
   cout << "Returning sumBCD and add() destructors being called." << endl;
   // Send the sumBCD, now complete, back to whatever called this function
   return sumBCD; // TODO: Probably right here; we're returning a BCD that gets destructed in short order
                  // Although... isn't that the point? Generate a sum and then return it so it can be assigned to something else?
}

// #subtract() - Subtracts a BCD object from another BCD object
// Parameters: sum - Working variable used to store the integer sum of two nodes. addCarry - Working variable used to store the tens place result of two integers summed. terminate - Terminate flag for a while loop. sumBCD - BCD object used to store successive addition operations.
// Preconditions: The absolute value of the calling BCD must be greater or equal to the absolute value of the argument BCD.
// Postconditions: A BCD representing the absolute magnitude btween the two BCDs exists. This BCD will be positive.
// Return value: boolean, representing whether this is the "last" card in a stack (true) or not (false).
// Functions called: None
BCD const BCD::subtract(const BCD& term2BCD) {
   cout << "Starting subtract()" << endl;

   int difference = 0;
   int tempBorrow = 0;
   BCD diffBCD;
   bool terminate = false;
   // Example 1024-123 = 901
   //  123
   //  901
   BCDnode* T1curr = this->headptr->moreSDptr; // Set T1 current node to term1's first node
   BCDnode* T2curr = term2BCD.headptr->moreSDptr; // Set T2 current node to term2's first node
   BCDnode* diffcurr = diffBCD.headptr->moreSDptr; // Set the sum current node to sumBCD's first node
                                                   // cout << "T1curr: " << T1curr->data << endl; // DEBUG
                                                   // cout << "T2curr: " << T2curr->data << endl; // DEBUG
                                                   // cout << "Sumcurr: " << sumcurr->data << endl; // DEBUG
                                                   // cout << "Sumcurr.carry: " << sumcurr->carry << endl; // DEBUG

                                                   // While both BCDs are not resting at the head node...
   while (terminate == false) {
      // Subtract the two terms...
      difference = (T1curr->data) - (T2curr->data) - diffcurr->borrow;
      // Borrow having been 'used', reset its value to 0
      diffcurr->borrow = 0;
      // If difference is less than 0
      if (difference < 0) {
         // add ten and assign result to the diffCurrent node's data field
         diffcurr->data = difference + 10;
         // But because we had to add ten, increment the borrow on the next node by 1.
         tempBorrow = 1;
      }
      // Otherwise, just assign directly to the result node
      else {
         diffcurr->data = difference;
      }

      // Advance T1 current node if it's not back on the head.
      if (T1curr != this->headptr) {
         T1curr = T1curr->moreSDptr;
      }

      // Advance T2 current node if it's not back on the head.
      if (T2curr != term2BCD.headptr) {
         T2curr = T2curr->moreSDptr;
      }

      // cout << "T1curr: " << T1curr->data << endl; // DEBUG
      // cout << "T2curr: " << T2curr->data << endl; // DEBUG
      // Test for exit condition, both T1curr and T2curr are back at the headptr and there is no carry to deal with.
      if (T1curr == this->headptr && T2curr == term2BCD.headptr && tempBorrow == 0) {
         terminate = true;
      }
      // If they aren't, we're going another round...
      else {
         // And the diffBCD will need another node for that.
         diffBCD.insertMSD(0);
         // Assign the borrow value to the new node (0 or 1)
         diffcurr->moreSDptr->borrow = tempBorrow;
         // Which we then advance to:
         diffcurr = diffcurr->moreSDptr;

         // And re-zero our working variables so it doesn't muddle additions on the next cycle
         difference = 0;
         tempBorrow = 0;
      }
   } // Closing while loop

     // Trim the zeroes
   while (diffBCD.headptr->lessSDptr->data == 0) {
      diffBCD.remove(diffBCD.headptr->lessSDptr);
   }

   cout << "difference of T1 and T2: " << diffBCD.toString() << endl;
   // Send the sumBCD, now complete, back to whatever called this function

   return(diffBCD);
}

// #isLastNode() - Declares whether the node in question is the last node in a linked list (.next or .prev leads to a node with a null value)
// Parameters: No internal fields
// Preconditions: None
// Postconditions: None
// Return value: boolean, representing whether this is the "last" card in a stack (true) or not (false).
// Functions called: None
const bool BCD::isLastNode(BCDnode* someNodeptr) {
   // Flag to determine whether this is the last node or not
   bool isLast = false;
   // Test criteria, can be returned directly (TODO?)
   // If the passed node's lessSDptr or moreSDptr point to the head, then this is a last node.
   if (someNodeptr->lessSDptr == headptr || someNodeptr->moreSDptr == headptr) {
      isLast = true;
      cout << "Head node located." << endl; // DEBUG
   }
   // Return flag status
   return(isLast);
}

// #insertMSD() - Inserts a node at the Most Significant Digit position
// Parameters: someData - Used to populate the new node's data field.
// Preconditions: None
// Postconditions: A new node is inserted as the the most significant digit position in the BCD
// Return value: None
// Functions called: None
const void BCD::insertMSD(int someData) {
   BCDnode* oldMSD = headptr->lessSDptr;
   // Make a new node off in space. Its data is the argument passed. Its MSD pointer points to head, its LSD pointer points to the old MSD.
   BCDnode* insertedNodeptr = new BCDnode(someData, headptr, oldMSD); // data, greater, lesser
   // Redirects the old MSD's next pointer to the inserted node
   oldMSD->moreSDptr = insertedNodeptr;
   // Redirect the head's lessSDptr to the current node.
   headptr->lessSDptr = insertedNodeptr;
   // New node created with int data and 4 of 4 pointers are pointed at the correct place
}

// #insertLSD() - Inserts a node at the Least Significant Digit position
// Parameters: someData - Used to populate the new node's data field.
// Preconditions: None
// Postconditions: A new node is inserted as the the least significant digit position in the BCD
// Return value: None
// Functions called: None
const void BCD::insertLSD(int someData) {
   BCDnode* oldLSD = headptr->moreSDptr;
   // Make a new node off in space. Its data is the argument passed. Its LSD pointer points to head, its MSD pointer points to the old LSD.
   BCDnode* insertedNodeptr = new BCDnode(someData, headptr->moreSDptr, headptr); // data, greater, lesser
   // Redirects the old LSD's next pointer to the inserted node
   oldLSD->lessSDptr = insertedNodeptr;
   // Redirect the head's moreSDptr to the current node.
   oldLSD = insertedNodeptr;
   // New node created with int data and 4 of 4 pointers are pointed at the correct place
}

// #numDigits() - Returns the number of nodes within a BCD
// Parameters: None
// Preconditions: None
// Postconditions: None
// Return value: length - An int value representing the length of the BCD object.
// Functions called: None
int BCD::numDigits() const {
   int counter = 0;
   BCDnode* curr = headptr->moreSDptr;
   while (curr != headptr) {
      curr = curr->moreSDptr;
      counter++;
   }
   return(counter);
}

// #remove() - Deletes a specified node, deallocates memory, and redirects relevant pointers
// Parameters:
// Preconditions:
// Postconditions:
// Return value: boolean, representing whether this method completed successfully.
// Functions called: None
bool BCD::remove(BCDnode* target) {
   if (target == nullptr) {
      cout << "ACHTUNG! remove() has been passed a nullptr. Breaking.";
      return(false);
   }
   //   cout << "Start remove(). Address of remove() target: " << &target << endl; // DEBUG
   BCDnode targetNode = *target;
   cout << targetNode.data;

   //   cout << "Redirecting pointers around target" << endl; // DEBUG
   target->moreSDptr->lessSDptr = target->lessSDptr;
   target->lessSDptr->moreSDptr = target->moreSDptr;

   //   cout << "Clearing internal fields (for security)..." << endl; // DEBUG - Omitted for simplicity (get working before optimizing)
   //   target->nodeName.clear();
   //   target->data = NULL;
   //   target->borrow = NULL;
   //   target->carry = NULL;
   //   target->moreSDptr = nullptr;
   //   target->lessSDptr = nullptr;

   //   cout << "Remove()ing target node" << endl;// DEBUG
   // Deallocate memory of target node.
   delete(target); // Confirmed, pg. 280
   return(true);
}

// #toString() - To return a string representation of the decoded PunchCard.
// Parameters: returnString - Used to concatenate successive characters from the outputArray.
// Preconditions: None
// Postconditions: returnString is 80 characters in length, plus a newline character at its end.
// Return value: A string, 80 characters in length, with a newline character at its end.
// Functions called: None
const string BCD::toString() const {
   string returnString = "'";

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
   returnString += "'";
   return returnString;
}
