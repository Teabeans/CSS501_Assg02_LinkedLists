// Tim Lum
// twhlum@gmail.com
// 2017.10.27
// For the University of Washington Bothell CSS 501A
// Autumn 2017, Graduate Certificate in Software Design & Development (GCSDD)
//
// File Description:
// This file is the header (definitions) of the Binary Coded Decimal (BCD, aka. "Very Big Number") class.
//
// Package files:
// BCD.cpp
// BCD.h
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
// License:
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
// To install G++:
// sudo apt install g++
// 
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
// g++ -std=c++11 *.cpp
//
// To run with test input:
// ./a.out < TestInput.txt
//
// To run Valgrind:
// Install Valgrind:
// sudo apt install valgrind
//
// Run with:
// valgrind --leak-check=full <file folder path>/<file name, usually a.out>
// OR
// valgrind --leak-check=full --show-leak-kinds=all <file path>/a.out
//
// ie.
// valgrind --leak-check=full /home/Teabean/a.out
// OR
// valgrind --leak-check=full --show-leak-kinds=all /home/Teabean/a.out
//
// ---- BEGIN STUDENT CODE ----

// ---- IMPORT STATEMENTS ----


// Includes exceptions
#include <stdexcept>

//Necessary to interact with 'cin' and 'cout' streams
#include <iostream>

// Necessary for string operations
#include <string>

// Includes the BCD class header
#include "BCD.h"

// ---- NAMESPACE STATEMENTS ----
// Methods not found in the current namespace are directed to check the 'std' namespace
using namespace std;

// ---- STRUCTS ----

// #BCDnode: Structure representing a BCDnode
// Invariant information: Data field will always contain an integer value.   
struct BCDnode {
   // BCDnode fields: Declared in .h and omitted from .cpp file.
   // TODO: AFTER SUBMITTAL: Transfer struct implementation to the .cpp file.
/* 
   // #nodeName - Name of the node. Used for debugging.
   // Invariant information: None
   string nodeName;

   // #data - The numeric value that this node represents.
   // Invariant information: From INT_MIN to INT_MAX, but logically should be from 0 to +9.
   int data = 0;

   // #borrow - Used if this node has passed values to a LessSignificantDigit.
   // Invariant information: Valid range from 0 to INT_MAX.
   int borrow = 0;

   // #carry - Used if this node has received values from a LessSignificantDigit.
   // Invariant information: Valid range from 0 to INT_MAX.
   int carry = 0;

   // #moreSDptr - A pointer to this node's MoreSignificantDigit.
   // Invariant information: None
   BCDnode* moreSDptr;
      
   // #lessSDptr - A pointer to this node's LessSignificantDigit.
   // Invariant information: None
   BCDnode* lessSDptr;
*/

}; // Closing 'struct Node'

   // Note: Fields can be initialized in EITHER the .h or the .cpp

   // ---- FIELDS ----

// #headptr - Pointer to the head BCDnode
// Invariant information: Headptr always exists, though the head node itself may be deleted.
BCDnode* headptr;

// isPositive: Represents whether this BCD object is positive or not
// Invariant information: Range is from 0 to 1, where 0 represents 'false' (negative), and 1 represents 'true' (positive)
bool isPositive = true;

// length: For the head node only. Integer representing the node length of this BCD number ("1-2-3-4" has a length of "4")
// Invariant information: Range is from 0 to the maximimum value of an int (2,147,483,647)
int length = 1;

// PRIVATE METHODS:

// -None for this class-

// ---- CONSTRUCTORS ----

// #BCD() - Default constructor.
// Parameters: None
// Preconditions: None
// Postconditions: A BCD object exists with an internal state representing "0"
// Return value: None
// Functions called: None
// "In the BCD namespace, method named BCD receiving (<no arguments>), initializing 'head' to 'nullptr' and executing {<no commands>}
BCD::BCD() { // By default, the node pointer (BCDnode*) named 'head' is initialized to nullptr
   isPositive = true;
   headptr = new BCDnode();
   BCDnode* body = new BCDnode(0, headptr, headptr); // Generates new node with value of 0, headptr set to both 'next' and 'prev'
   headptr->lessSDptr = body;
   headptr->moreSDptr = body;
}

// #BCD(int) - Constructs a new BCD with an equivalent value to the received argument int
// Parameters: temp - Integer holder used for manipulations near the INT_MAX/MIN overflow limit
// Preconditions: None
// Postconditions: A BCD object exists with an internal state representing the integer passed to it
// Return value: None
// Functions called: insertMSD(), BCDnode() constructors
BCD::BCD(int someInt) {
   // Determine if the passed int is positive or negative
   int temp = someInt;
   if (temp < 0 && temp != (-2147483647 - 1) ) {
      isPositive = false;
      // Reverse the sign of the received int so BCD formation is performed with all positive nodes
      temp = temp * -1;
   }
   // Special behavior to avoid flipping INT_MIN, then having it immediately overflow back to INT_MIN
   // See off-by-one discrepancy between INT_MIN and INT_MAX.
   else if (temp == (-2147483647 - 1)) {
      isPositive = false;
      temp = (temp + 1) * -1;
   }
   else {
      isPositive = true;
   }

   // Make the head node
   headptr = new BCDnode();
   // Make the first body nodeptr
   BCDnode* body;
   // And populate it with the least significant digit
   if (someInt == (-2147483647 - 1)) {
      body = new BCDnode(((temp % 10)+1), headptr, headptr);
   }
   else {
      body = new BCDnode((temp % 10), headptr, headptr);
   }
   // Set the headnode pointers to the body node we just made
   headptr->lessSDptr = body;
   headptr->moreSDptr = body; // 4 of 4 pointers are set

   // Divide by 10 to drop the least significant digit for the next pass
   temp = temp / 10;

   // Breaks after Most SigDigit is divided by 10
   while (temp != 0) {
      // Remainder of the int when divided by 10 is the least significant digit
      insertMSD(temp % 10);
      // Drop the Least SigDigit from someInt
      temp = temp / 10;
   }

} // Close BCD(int) constructor

// #BCD(BCD&) - Deep copy constructor- Page 246
// Parameters: None
// Preconditions: A valid BCD object exists.
// Postconditions: A BCD object is created with an internal state representing, but distinct from, the received BCD argument.
// Return value: None
// Functions called: insertMSD(), BCDnode() constructors
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

// #~BCD() - Destructor - Deletes all dynamically allocated memory associated with a BCD object. Page 245-246
// Parameters: None
// Preconditions: A valid BCD object exists with a valid head node.
// Postconditions: All dynamically allocated memory made by the BCD is deallocated.
// Return value: None
// Functions called: obliterate()
BCD::~BCD() {
   //   cout << "~BCD Destructor. Address of targetted headptr is:" << endl << &headptr << endl;
   //   obliterate(headptr); // Turning off temporarily
   //    TODO: Verify that destructor works
   obliterate();
   headptr->moreSDptr = nullptr;
   headptr->lessSDptr = nullptr;
   delete headptr;
   //   cout << "~BCD Destructor complete. Linked list destroyed." << endl << endl;
}

// ---- METHODS ----

// const <return type> <method name>( <arguments> );
// e.g. const bool checkIfLastCard(someClass& someArg);

// #obliterate() - Deletes all nodes connected to the calling BCD's headptr node.
// Parameters: None
// Preconditions: A valid BCD object exists with a valid head node.
// Postconditions: All dynamically allocated memory attached to the head node is deallocated. The head node still exists.
// Return value: None
// Functions called: remove()
void BCD::obliterate() {
   //   cout << "Start obliterate(): " << endl;
   BCDnode* target = this->headptr->lessSDptr;
   while (target != headptr) {
      remove(target);
      target = this->headptr->lessSDptr;
   }
}

// #remove() - Deletes the target node
// Parameters: None
// Preconditions: A valid target node has been passed to this method
// Postconditions: Dynamically allocated memory used by the node is deallocated.
// Return value: bool - True if successful.
// Functions called: None
bool BCD::remove(BCDnode* target) {
   // Redirect pointers around the node to be deleted
   BCDnode* prev = target->moreSDptr;
   BCDnode* next = target->lessSDptr;
   prev->lessSDptr = next;
   next->moreSDptr = prev;

   // TODO: AFTER SUBMITTAL: Re-enable. Currently omitted for simplicity
   // Clearing internal fields for security
   // target->nodeName.clear();
   // target->data = NULL;
   // target->borrow = NULL;
   // target->carry = NULL;
   target->moreSDptr = nullptr;
   target->lessSDptr = nullptr;

   // Deallocate memory of target node.
   delete target; // Confirmed, pg. 280
   return(true);
}

// ----OVERLOADS----

// #int() - Custom behavior for the BCD to int conversion operator
// Parameters: overflowInt - Higher capacity integer used to check from intMax to 999,999,999.
// Preconditions: A BCD object exists with a valid numeric representation.
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

   // Iterate over the BCD, starting at the MostSigDigit, appending lesser significant digits
   while (curr != headptr) {
      // If we're on the next SD, multiply by 10
      overflowInt = overflowInt * 10;
      // Add the next LessSD to the sum...
      overflowInt = overflowInt + curr->data;
      // And move to the next node (if curr lands back on headptr, it will terminate after this).
      curr = curr->lessSDptr;
   }

   // Assign the sign
   if (isPositive == false) {
      overflowInt = overflowInt * (-1);
   }

   // Check to see if the long long is within a valid range...
   if (overflowInt > 2147483647) {
      throw std::out_of_range("The BCD exceeds the max value of an int.");
   }
   if ((overflowInt) < (-2147483647 - 1)) {
      throw std::out_of_range("The BCD exceeds the min value of an int.");
   }

   // If it's within range, assign to the return variable and send it back.
   else {
      returnInt = (int)overflowInt;
      return(returnInt);
   }
}

// #operator< - Custom behavior for the less-than operator when dealing with a BCD object (left) and a BCD object (right)
// Parameters: currT1 and currT2 - Pointers to the current node being used for comparison
// Preconditions: Two valid BCD objects exist and are being compared
// Postconditions: None
// Return value: Boolean - True if the Left-Hand Term (LHT) is 'less than' the Right-Hand Term (RHT), false if not.
// Functions called: numDigits() - For the length of the BCD object.
bool BCD::operator<(const BCD& someBCD) const {
   // Not less than if it's equal
   if (*this == someBCD) {
      return(false);
   } // closing if

   // Compare BCD sign. If unequal and T1 is positive then false, T1 is not less than T2
   if (isPositive != someBCD.isPositive && isPositive == true) {
      //cout << "Mismatch! Different sign!" << endl; // DEBUG
      return(false);
   } // closing if

   else if (isPositive != someBCD.isPositive && isPositive == false) {
      return(true);
   }

   // Otherwise
   // For positives....
   if (isPositive == true && someBCD.isPositive == true) {
      std::cout << "+ < +" << endl;
      // Compare lengths
      // If this is longer than someBCD, return false, it can't be less than
      if (numDigits() > someBCD.numDigits()) {
         std::cout << numDigits() << "vs" << someBCD.numDigits() << endl;
         //cout << "Mismatch! Different list length!" << endl; // DEBUG
         return(false);
      }
      // If this is shorter than someBCD, return true, it must be less than
      else if (numDigits() < someBCD.numDigits()) {
         std::cout << numDigits() << "vs" << someBCD.numDigits() << endl;
         //cout << "Mismatch! Different list length!" << endl; // DEBUG
         return(true);
      }

      // Both sign and length are equal, begin node by node comparison:
      else {
         // Queue both BCDs to their MostSD node:
         BCDnode* currT1 = headptr->lessSDptr;
         BCDnode* currT2 = someBCD.headptr->lessSDptr;

         // While we aren't back at the head node...
         while (currT1 != headptr) {
            // Compare the data of the current nodes.
            // If T1 > T2, it can't be less than, so return false
            if (currT1->data > currT2->data) {
               return(false);
            }
            // If T1 < T2....
            if (currT1->data < currT2->data) {
               return(true);
            }
            // Otherwise, advance to next node
            currT1 = currT1->lessSDptr;
            currT2 = currT2->lessSDptr;
         } // Closing while

      } // Closing else
   } // Closing if (positives)

   // Otherwise, for negatives.
   else if (isPositive == false && someBCD.isPositive == false) {
      std::cout << "- < -" << endl;
      // If this is longer than someBCD, return true must be less than
      if (numDigits() > someBCD.numDigits()) {
         return(true);
      }
      // If this is shorter than someBCD, return false, it must be greater than
      else if (numDigits() < someBCD.numDigits()) {
         return(false);
      }
      // Both sign and length are equal, begin node by node comparison:
      else {
         // Queue both BCDs to their MostSD node:
         BCDnode* currT1 = headptr->lessSDptr;
         BCDnode* currT2 = someBCD.headptr->lessSDptr;
         while (currT1 != headptr) {
            // Compare the data of the current nodes. If T1 > T2, it must be less than, so return true
            if (currT1->data > currT2->data) {
               return(true);
            }
            // Otherwise, T1 is less than T2.
            if (currT2->data > currT1->data) {
               return(false);
            }
            // Advance to next node
            currT1 = currT1->lessSDptr;
            currT2 = currT2->lessSDptr;
         } // Closing while
      } // Closing else
   } // Closing else if (negatives)
} // Closing operator<

// #operator== - Custom behavior for the equality operator when dealing with a BCD object (left) and a BCD object (right)
// Parameters: currT1 and currT2 - Pointers to the current node being used for comparison
// Preconditions: None
// Postconditions: None
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
         //cout << "Mismatch! Different sign!" << endl; // DEBUG
         return(false);
      }
      // Otherwise, compare BCD length. If unequal, these are not equal
      else if (numDigits() != someBCD.numDigits()) {
         //cout << "Mismatch! Different list length!" << endl; // DEBUG
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
               //cout << "Mismatch! Different node data!" << endl; // DEBUG
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
} // Closing operator==

// #operator= - Custom behavior for the assignment operator when dealing with a BCD object (left, implied) and a BCD object (right)
// Parameters: None
// Preconditions: Two valid BCD objects exist
// Postconditions: The LeftHandSide BCD linked list has been replaced with a new linked list reflecting the values of the RightHandSide argument
// Return value: *this, a pointer to the LeftHandSide argument
// Functions called: obliterate(), deepcopy()
BCD& BCD::operator=(const BCD& rightHandSide) {
   //cout << "Starting operator=" << endl;
   //cout << "RHS: " << rightHandSide.toString() << endl;
   if (this != &rightHandSide) {
      this->obliterate();
      this->deepcopy(rightHandSide);
      // Copy relevant field states
      this->length = rightHandSide.length;
      this->isPositive = rightHandSide.isPositive;
   }
   //cout << "Operator= complete... returning *this: " << this->toString() << endl;
   return *this;
}

// #operator>> - Custom behavior for the insertion operator when dealing with an istream object (left) and a BCD object (right)
// Parameters: numberBank - Used to store single int values from cin.
// Preconditions: Content must be loaded to cin, terminated by newline characters. A valid BCD object must already exist.
// Postconditions: The existing BCD object's internal nodes now represent the integer pulled from cin
// Return value: cinData - An istream object.
// Functions called: None
istream& operator>> (istream& cinData, BCD& someBCD) {
   // Capture the int value from cin
   int numberBank;
   cin >> numberBank;
   // Assign the int to someBCD
   someBCD = numberBank;
   //<Implementation goes here>
   return (cinData);
}

// #operator<< - Custom behavior for the extraction operator when dealing with an ostream object (left) and a BCD object (right)
// Parameters: thisBCDNumber - Used to store successive digits to be sent to 'cout'.
// Preconditions: None
// Postconditions: String representation of the BCD object will be sent to 'cout'.
// Return value: None
// Functions called: toString() - Converts BCD digits to a string object.
// If it's in the class definition, include 'friend'
ostream& operator<< (ostream& coutStream, BCD& someBCD) { // where 'cinData' is the input variable and 'card' is the PunchCard object
   string thisBCDNumber = "";
   // <Implement all string appending here>
   thisBCDNumber += someBCD.toString();
   coutStream << thisBCDNumber;
   return coutStream;
}

// #operator+ - Custom behavior for the addition operator when dealing with a BCD object (left) and a BCD object (right)
// Parameters: this - The original BCD object being added to (implied) ; term2BCD - The BCD number being added to the term1BCD.
// Preconditions: Two valid BCD objects exist
// Postconditions: A new BCD object exists representing the summed addition of the old BCD and received BCD.
// Return value: A new BCD object representing the summed addition
// Functions called: BCD(int), add(), subtract(), isGreaterMagnitudeThan()
const BCD BCD::operator+(BCD& term2BCD) {
   if (this->isPositive == true && term2BCD.isPositive == true) {
      return(this->add(term2BCD, true)); // Result must be positive
   }
   else if (this->isPositive == false && term2BCD.isPositive == false) {
      return(this->add(term2BCD, false)); // Result must be negative
   }
   else {
      // BIG + small => Delta is |T1| - |T2|
      if (this->isGreaterMagnitudeThan(term2BCD)) {
         if (this->isPositive == true) {
            return(this->subtract(term2BCD, true)); // Result will be positive
         }
         else {
            return(this->subtract(term2BCD, false)); // Result will be negative
         }
      }

      // small + BIG => Delta is |T2| - |T1|
      else if (term2BCD.isGreaterMagnitudeThan(*this)) {
         if (this->isPositive == true) {
            return(term2BCD.subtract(*this, false)); // Result will be negative
         }
         else {
            return(term2BCD.subtract(*this, true)); // Result will be positive
         }
      }
      // They're the same magnitude, but one is positive and one is negative
      else {
         return(BCD(0)); // Result is a negation, 0
      }
   }
} // Closing operator+

// #operator- - Custom behavior for the subtraction operator when dealing with a BCD object (left) and a BCD object (right)
// Parameters: term1BCD - The original BCD object being subtracted from ; term2BCD - The BCD number being subtracted from term1BCD.
// Preconditions: None
// Postconditions: A new BCD object exists representing the difference of the old BCD and received BCD.
// Return value: A new BCD object representing the difference from subtraction
// Functions called: BCD(int), add(), subtract, isGreaterMagnitudeThan()
BCD operator-(BCD& term1BCD, BCD& term2BCD) {
   if (term1BCD.isPositive == true && term2BCD.isPositive == false) {
      return(term1BCD.add(term2BCD, true)); // Result must be positive
   }
   else if (term1BCD.isPositive == false && term2BCD.isPositive == true) {
      return(term1BCD.add(term2BCD, false)); // Result must be negative
   }
   else {
      // BIG - small
      if (term1BCD.isGreaterMagnitudeThan(term2BCD)) {
         // (++) - (+)
         if (term1BCD.isPositive == true && term2BCD.isPositive == true) {
            return(term1BCD.subtract(term2BCD, true)); // Result will be positive
         }
         // (--) - (-)
         else {
            return(term1BCD.subtract(term2BCD, false)); // Result will be negative
         }
      }

      // small - BIG
      else if (term2BCD.isGreaterMagnitudeThan(term1BCD)) {
         // (+) - (++)
         if (term1BCD.isPositive == true) {
            return(term2BCD.subtract(term1BCD, false)); // Result will be negative
         }
         // (-) - (--)
         else {
            return(term2BCD.subtract(term1BCD, true)); // Result will be positive
         }
      }
      // They're the same magnitude, and both are positive or negative
      else {
         return(BCD(0)); // Result is a negation, 0
      }
   }
} // Closing operator-

// #isGreaterMagnitudeThan() - Determines which term has a larger absolute value
// Parameters: currT1 and CurrT2 - Used for iterative comparisons.
// Preconditions: Two valid BCDs exist which can be compared
// Postconditions: None
// Return value: bool - True if the absolute value of T1 is greater than T2. False otherwise.
// Functions called: None
bool const BCD::isGreaterMagnitudeThan(const BCD& term2) {
   // If term1 is longer, then its magnitude must be greater
   if (this->numDigits() > term2.numDigits()) {
      return(true);
   }
   // Conversely...
   else if (this->numDigits() < term2.numDigits()) {
      return(false);
   }
   // Otherwise, they have the same number of digits
   else {
      // So compare from MSD back.
      BCDnode* currT1 = headptr->lessSDptr;
      BCDnode* currT2 = term2.headptr->lessSDptr;
      while (currT1 != headptr) {
         if (currT1->data != currT2->data) {
            if (currT1->data > currT2->data) {
               return(true);
            }
            else if (currT1->data < currT2->data) {
               return(false);
            }
            // Otherwise, they're the same, so advance
         }
         currT1 = currT1->lessSDptr;
         currT2 = currT2->lessSDptr;
      }
   }
   // Comparison complete, they are equal magnitude
   return(false);
}

// #deepcopy() - Generates a deep copy of the received target BCD.
// Parameters: currT1 and CurrT2 - Used for iterative comparisons.
// Preconditions: Two valid BCDs exist
// Postconditions: The calling BCD's original content has been deallocated and replaced with nodes reflecting the target BCD.
// Return value: None
// Functions called: obliterate(), insertMSD()
void const BCD::deepcopy(const BCD& target) {
   // Test if 'this' and 'target' are the same thing
   if (headptr == target.headptr) {
      // Same target as this, so do nothing
   }
   else {
      // Delete all nodes associated with the headpointer (clean slate)
      obliterate();
      delete headptr;
      // Create a new node - copied from internal values of target.headptr - give its address to headptr.
      headptr = new BCDnode();
      // Set current node to the target LeastSD
      BCDnode* curr = target.headptr->moreSDptr;
      // Generate a new body node, also copied from the current target
      BCDnode* newBody = new BCDnode(curr->data, headptr, headptr); // 2/4 pointers set
      // Connect remaining pointers
      headptr->lessSDptr = newBody;
      headptr->moreSDptr = newBody; // 4/4 pointers are set
      
      // Advance (possibly back to the head)
      curr = curr->moreSDptr;
      while (curr != target.headptr) { // While we aren't back at the head...
         // Insert a new node at the MostSD using the current data field
         insertMSD(curr->data); 
         // Advance
         curr = curr->moreSDptr; 
      }
      // Node copies completed
   } // Closing else
} // Closing deepcopy()

// #add() - Adds a BCD object to another BCD object
// Parameters: sum - Working variable used to store the integer sum of two nodes. addCarry - Working variable used to store the tens place result of two integers summed. terminate - Terminate flag for a while loop. sumBCD - BCD object used to store successive addition operations.
// Preconditions: Two valid BCDs exist
// Postconditions: None
// Return value: A positive BCD representing the sum of two magnitudes
// Functions called: insertMSD()
// Need to fully qualify method location before 'this' becomes available for use
BCD const BCD::add(const BCD& term2BCD, bool isPositive) const {
   int sum = 0;
   int addCarry = 0;
   BCD sumBCD;
   bool terminate = false;

   BCDnode* T1curr = this->headptr->moreSDptr;    // Set T1 current node to term1's first node
   BCDnode* T2curr = term2BCD.headptr->moreSDptr; // Set T2 current node to term2's first node
   BCDnode* sumcurr = sumBCD.headptr->moreSDptr;  // Set the sum current node to sumBCD's first node
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

      // Advance T1 current node if it's not back on the head.
      if (T1curr != this->headptr) {
         T1curr = T1curr->moreSDptr;
      }

      // Advance T2 current node if it's not back on the head.
      if (T2curr != term2BCD.headptr) {
         T2curr = T2curr->moreSDptr;
      }

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
   sumBCD.isPositive = isPositive;
   // Send the sumBCD, now complete, back to whatever called this function
   return sumBCD;
} // Closing add()

// #subtract() - Subtracts a BCD object from another BCD object
// Parameters: difference - Working variable used to store the integer difference of two nodes. tempBorrow - Working variable used to store the tens place result of two integers summed. terminate - Terminate flag for a while loop. diffBCD - BCD object used to store successive addition operations.
// Preconditions: The absolute value of the calling BCD must be greater or equal to the absolute value of the argument BCD.
// Postconditions: A BCD representing the absolute magnitude btween the two BCDs exists. This BCD will be positive.
// Return value: boolean, representing whether this is the "last" card in a stack (true) or not (false).
// Functions called: None
BCD const BCD::subtract(const BCD& term2BCD, bool isPositive) const {
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

   // While both BCDs are not resting at the head node...
   while (terminate == false) {
      // Subtract the two terms...
      difference = (T1curr->data) - (T2curr->data) - diffcurr->borrow;
      // Borrow having been 'used', reset its value to 0
      diffcurr->borrow = 0;
      // If difference is less than 0 (ie.  3 - 4 = -1
      if (difference < 0) {
         // add ten and assign result to the diffCurrent node's data field
         diffcurr->data = (difference + 10);
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

      // Test for exit condition, both T1curr and T2curr are back at the headptr and there is no carry to deal with.
      if (T1curr == this->headptr && T2curr == term2BCD.headptr && tempBorrow == 0) {
         terminate = true;
      }
      // If they aren't, we're going another round...
      else {

         // And the diffBCD will need another node for that.
         diffBCD.insertMSD(0);
         // Which we then advance to:
         diffcurr = diffcurr->moreSDptr;
         // And assign the borrow value (0 or 1)
         diffcurr->borrow = tempBorrow;

         // And re-zero our working variables so it doesn't muddle additions on the next cycle
         difference = 0;
         tempBorrow = 0;
      }
   } // Closing while loop

   // Trim the zeroes, but halt if the only node is 0.
   while (diffBCD.headptr->lessSDptr->data == 0 && diffBCD.headptr->lessSDptr->lessSDptr != diffBCD.headptr) {
      diffBCD.remove(diffBCD.headptr->lessSDptr);
   }

   // Add the sign
   diffBCD.isPositive = isPositive;
   // Send the sumBCD, now complete, back to whatever called this function
   return(diffBCD);
} // Closing subtract()

// #isLastNode() - Declares whether the node in question is the last node in a linked list (.next or .prev leads to a node with a null value)
// Parameters: isLast - Boolean storing the results of the test
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
      //cout << "Head node located." << endl; // DEBUG
   }
   // Return flag status
   return(isLast);
}

// #insertMSD() - Inserts a node at the Most Significant Digit position
// Parameters: someData - Used to populate the new node's data field.
// Preconditions: None
// Postconditions: A new node is inserted as the the most significant digit position in the BCD
// Return value: None
// Functions called: BCDnode() constructor
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
   BCDnode* insertedNodeptr = new BCDnode(someData, oldLSD, headptr); // data, greater, lesser
   // Redirects the old LSD's next pointer to the inserted node
   oldLSD->lessSDptr = insertedNodeptr;
   // Redirect the head's moreSDptr to the current node.
   headptr->moreSDptr = insertedNodeptr;
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

// #toString() - To return a string representation of the BCD object.
// Parameters: returnString - Used to concatenate successive digits from the BCD.
// Preconditions: None
// Postconditions: None
// Return value: A string representing the sequential digits in the BCD and a (-) sign prefix if negative.
// Functions called: std::to_string() - To convert an int from a node data field to a string.
const string BCD::toString() const {
   string returnString = "";

   if (isPositive == true) {
      returnString += "";
   }
   else if (isPositive == false) {
      returnString += "-";
   }
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
} // closing toString();

// #operator* - Overload of the (*) operator for multiplication of two BCD objects.
// Parameters: finalSum, tempProduct, nodeProduct, carry, T1curr, T2curr, ProductCurr (see below for descriptions)
// Preconditions: Two valid BCD objects exist.
// Postconditions: A new BCD exists representing the product of the two terms
// Return value: A BCD representing the product
// Functions called: numDigits(), insertLSD(), insertMSD()
const BCD operator*(BCD& term1BCD, BCD& term2BCD) {
   // Sum of all temp products - This gets returned
   BCD finalSum; 
   // Product of one line of multiplication
   BCD tempProduct; 
   // Product of a single multiplication event
   int nodeProduct;
   // Carry value if one node needs to send digits to an adjacent node
   int carry = 0;
   // The current target of Term1
   BCD::BCDnode* T1curr = term1BCD.headptr->moreSDptr;
   // The current target of Term2
   BCD::BCDnode* T2curr = term2BCD.headptr->moreSDptr;
   // The current target of the tempProduct.
   BCD::BCDnode* ProductCurr;

   // Times 0 case - result will be 0.
   if (0 == term1BCD || 0 == term2BCD) {
      finalSum = 0;
      return (finalSum);
   }
   // Otherwise...
   // For every digit in Term2...
   for (int i = 0; i < term2BCD.numDigits(); i++) {
      // Build the sub-product
      // Against every digit in Term1...
      for (int j = 0; j < term1BCD.numDigits(); j++) {
         // Multiply the digits together
         nodeProduct = T1curr->data * T2curr->data;
         // Place node product at the MostSD
         // Special case for the first round (since first node is already 0)
         if (i == 0 && j == 0) {
            // On the first round, the temp product's first node's data receives result directly.
            tempProduct.headptr->moreSDptr->data = nodeProduct; // Note, may exceed 9, carries dealt with later
            //cout << "Round 1, tempProduct: " << tempProduct << endl;
         }
         else {
            tempProduct.insertMSD(nodeProduct); // Note, may exceed 9, carries dealt with later
         }
         // Advance term1 target
         T1curr = T1curr->moreSDptr;
         // Repeat node product calculation
      }
      // Handle subproduct carries
      // Pointing at LSD of Temp Product
      ProductCurr = tempProduct.headptr->moreSDptr;
      // While we aren't back at the head...
      while (ProductCurr != tempProduct.headptr) {
         // Add the carry (even if 0)
         ProductCurr->data = ProductCurr->data + carry;
         carry = 0;
         if (ProductCurr->data > 9) {
            // Extract how many tens there are...
            carry = ProductCurr->data / 10;
            // And set the node value to remainder of mod 10 division.
            ProductCurr->data = ProductCurr->data % 10;
         }
         // If we're on the last node, but the carry will take us one more, add a node
         if (ProductCurr->moreSDptr == tempProduct.headptr && carry > 0) {
            tempProduct.insertMSD(0);
         }
         // Advance!
         ProductCurr = ProductCurr->moreSDptr;
         // And one additional node hop to get T1curr past the head and back onto its LeastSigDigit.
         T1curr = term1BCD.headptr->moreSDptr;
      }
      // tempProduct now represents all multiplications with carries
      // Apply trailing zeros
      for (int k = 1; k < i; k++) { // Nothing happens on first digit of T2.
         tempProduct.insertLSD(0);
      }
      //add subproduct to finalSum
      finalSum = finalSum.add(tempProduct, true);
      tempProduct = 0;
      // Advance term 2
      T2curr = T2curr->moreSDptr;
   } // Repeat for next digit of term2
   // Assign sign
   if (term1BCD.isPositive != term2BCD.isPositive) {
      finalSum.isPositive = false;
   }
   return(finalSum);
}

// #operator/ - Overload of the (/) operator for division of two BCD objects.
// Parameters: result, sacriNumer, sacriDenom, numerSubset, counter, tempSign, sacriCurr (see below for descriptions)
// Preconditions: Two valid BCD objects exist.
// Postconditions: A new BCD exists representing the result of the two terms' division
// Return value: A BCD representing the result
// Functions called: insertLSD(), remove()
const BCD operator/(BCD& numer, BCD& denom) {
   // The returned result of the division operation
   BCD result;
   // A working numerator, copied from the received argument. Used to shed the positive or negative nature of the received numerator.
   BCD sacriNumer = numer;
   // A working denominator, used to shed the positive or negative nature of the received denominator.
   BCD sacriDenom = denom;
   // A subset of the numerator. Longhand division is performed against this variable.
   BCD numerSubset = 0;
   // A counter representing how many subtraction events take place between the sacriNumer and sacriDenom.
   int counter = 0;
   // Temporary holder of the final result sign
   bool tempSign = true;
   // Node pointer used to track the current position of the sacrificial numerator.
   BCD::BCDnode* sacriCurr = sacriNumer.headptr->lessSDptr;

   // Assign the sign
   if (numer.isPositive != sacriDenom.isPositive) {
      tempSign = false;
   }

   // Ensure that both numerator and denominator are treated as positives during algebraic manipulations.
   if (sacriNumer.isPositive != true) {
      sacriNumer.isPositive = true;
   }
   if (sacriDenom.isPositive != true) {
      sacriDenom.isPositive = true;
   }

   // Divide by zero case
   if (0 == sacriDenom) {
      // Implode
      throw std::invalid_argument("+++ Divide by cucumber error +++");
   }

   // Denominator (denom) bigger than numerator (numer)
   else if (sacriDenom > numer) {
      result = 0;
      return (result);
   }

   // Numerator is bigger than denominator
   else {
      while (sacriCurr != sacriNumer.headptr) {
         // If numerator is not not big enough, keep grabbing numbers from the sacriNumer until it's bigger
         while (numerSubset < sacriDenom) {
            // Make a new node
            numerSubset.insertLSD(sacriCurr->data);
            // Advance sacrificial current pointer and append a zero to the result
            sacriCurr = sacriCurr->lessSDptr;
            if (numerSubset < sacriDenom) {
               result.insertLSD(0);
            }
            // And delete the last number we were at (it can no longer be used)
            sacriNumer.remove(sacriCurr->moreSDptr);
            // Also trim leading zeroes, as this will jack up equality operators tests later
            if (numerSubset.headptr->lessSDptr->data == 0) {
               numerSubset.remove(numerSubset.headptr->lessSDptr);
            }
         }
         // Numerator is guaranteed large enough

         // Start mini subtractions while subtractions can be made
         while (numerSubset >= sacriDenom) {
            numerSubset = numerSubset - sacriDenom;
            counter++;
         }
         // numerator subset has been divided out as most it can be
         // So place the counter number in the result string
         result.insertLSD(counter);
         // Used up the counter, so reset it to zero
         counter = 0;
      } // End while sacriCurr != headptr
   }

   while (result.headptr->lessSDptr->data == 0) {
      result.remove(result.headptr->lessSDptr);
   }

   // Place the sign we calculated at the beginning onto the result.
   result.isPositive = tempSign;

   return(result);
}
