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

#pragma once

//Necessary to interact with 'cin' and 'cout' streams
#include <iostream>
// Necessary for string operations
#include <string>
// Methods not found in the current namespace are directed to check the 'std' namespace
using namespace std;

// ---- CLASS BCD ----
class BCD {
   // --- PRIVATE REGION --- PRIVATE REGION --- PRIVATE REGION ---
private:
   // ---- PRIVATE FIELDS ----

   // length: For the head node only. Integer representing the node length of this BCD number ("1-2-3-4" has a length of "4")
   // Invariant information: Range is from 0 to the maximimum value of an int (2,147,483,647)
   int length;

   // isPositive: Represents whether this BCD object is positive or not
   // Invariant information: Range is from 0 to 1, where 0 represents 'false' (negative), and 1 represents 'true' (positive)
   bool isPositive;

   // PRIVATE METHODS:

   // -None for this class-

   // --- PUBLIC REGION --- PUBLIC REGION --- PUBLIC REGION ---
public:

   // PUBLIC FIELDS:

   // #BCDnode: Structure representing a BCDnode
   // Invariant information: Data field will always contain an integer value.
   struct BCDnode {
      //BCDnode fields:

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

      // #BCDnode() - Default node constructor
      // Parameters: None
      // Preconditions: None
      // Postconditions: A BCDnode exists with an internal state representing "0". "Next" and "Prev" pointers are to nullptr.
      // Return value: None
      // Functions called: None
      BCDnode() : nodeName("Head Node"), data(0), moreSDptr(nullptr), lessSDptr(nullptr) { }

      // #BCDnode(int, ptr, ptr) - Node constructor using a value and the pointers for its adjacent nodes.
      // Parameters: None
      // Preconditions: None
      // Postconditions: A BCDnode exists with an internal state representing the received value. Its "Next" and "Prev" pointers are to the MoreSignificantDigit and LessSignificantDigit nodes.
      // Return value: None
      // Functions called: None
      BCDnode(int someData, BCDnode* moreSigDigit, BCDnode* lessSigDigit) :
         nodeName("Body Node"),
         data(someData),
         moreSDptr(moreSigDigit),
         lessSDptr(lessSigDigit) {
      }

      // #BCDnode(nodeptr) - Constructor using another node - Creates a deep copy
      // Parameters: None
      // Preconditions: The received target pointer must indicate a valid BCDnode.
      // Postconditions: A BCDnode exists with an internal state representing the received value. Its "Next" and "Prev" pointers remain null.
      // Return value: None
      // Functions called: None
      BCDnode(BCDnode* targetNodeptr) :
         // Copy relevant fields
         nodeName(targetNodeptr->nodeName),
         data(targetNodeptr->data){
      }

   }; // End BCDnode struct

   // #headptr - Pointer to the head BCDnode
   // Invariant information: Headptr always exists, though the head node itself may be deleted.
   BCDnode* headptr;

   // PUBLIC METHODS:

   // ---- CONSTRUCTORS ----

   // #BCD() - Default constructor.
   // Parameters: None
   // Preconditions: None
   // Postconditions: A BCD object exists with an internal state representing "0"
   // Return value: None
   // Functions called: None
   BCD();

   // #BCD(int) - Integer constructor.
   // Parameters: temp - Integer holder used for manipulations near the INT_MAX/MIN overflow limit
   // Preconditions: None
   // Postconditions: A BCD object exists with an internal state representing the integer passed to it
   // Return value: None
   // Functions called: insertMSD(), BCDnode() constructors
   BCD(int someInt);

   // #BCD(BCD&) - Deep copy constructor- Page 246
   // Parameters: None
   // Preconditions: A valid BCD object exists.
   // Postconditions: A BCD object is created with an internal state representing, but distinct from, the received BCD argument.
   // Return value: None
   // Functions called: insertMSD(), BCDnode() constructors
   BCD(const BCD& someBCD);

   // ---- METHODS ----

   // const <return type> <method name>( <arguments> );
   // e.g. const bool checkIfLastCard(someClass& someArg);

   // #obliterate() - Deletes all nodes connected to the calling BCD's headptr node.
   // Parameters: None
   // Preconditions: A valid BCD object exists with a valid head node.
   // Postconditions: All dynamically allocated memory attached to the head node is deallocated. The head node still exists.
   // Return value: None
   // Functions called: remove()
   void obliterate();

   // #remove() - Deletes the target node
   // Parameters: None
   // Preconditions: A valid target node has been passed to this method
   // Postconditions: Dynamically allocated memory used by the node is deallocated.
   // Return value: bool - True if successful.
   // Functions called: None
   bool remove(BCDnode* target);

   // #add() - Adds a BCD object to another BCD object
   // Parameters: sum - Working variable used to store the integer sum of two nodes. addCarry - Working variable used to store the tens place result of two integers summed. terminate - Terminate flag for a while loop. sumBCD - BCD object used to store successive addition operations.
   // Preconditions: Two valid BCDs exist
   // Postconditions: None
   // Return value: A positive BCD representing the sum of two magnitudes
   // Functions called: insertMSD()
   BCD const add(const BCD& term2BCD, bool isPositive) const;

   // #subtract() - Subtracts a BCD object from another BCD object
   // Parameters: difference - Working variable used to store the integer difference of two nodes. tempBorrow - Working variable used to store the tens place result of two integers summed. terminate - Terminate flag for a while loop. diffBCD - BCD object used to store successive addition operations.
   // Preconditions: The absolute value of the calling BCD must be greater or equal to the absolute value of the argument BCD.
   // Postconditions: A BCD representing the absolute magnitude btween the two BCDs exists. This BCD will be positive.
   // Return value: boolean, representing whether this is the "last" card in a stack (true) or not (false).
   // Functions called: None
   BCD const subtract(const BCD& term2BCD, bool isPositive) const;

   // #isLastNode() - Declares whether the node in question is the last node in a linked list (.next or .prev leads to a node with a null value)
   // Parameters: isLast - Boolean storing the results of the test
   // Preconditions: None
   // Postconditions: None
   // Return value: boolean, representing whether this is the "last" card in a stack (true) or not (false).
   // Functions called: None
   const bool isLastNode(BCDnode* someNode);

   // insertMSD() - Inserts a node at the Most Significant Digit position
   // Parameters: someData - Used to populate the new node's data field.
   // Preconditions: None
   // Postconditions: A new node is inserted as the the most significant digit position in the BCD
   // Return value: None
   // Functions called: BCDnode() constructor
   const void insertMSD(int someData);

   // insertLSD() - Inserts a node at the Least Significant Digit position
   // Parameters: someData - Used to populate the new node's data field.
   // Preconditions: None
   // Postconditions: A new node is inserted as the the least significant digit position in the BCD
   // Return value: None
   // Functions called: None
   const void insertLSD(int someData);

   // numDigits() - Returns the number of nodes within a BCD
   // Parameters: None
   // Preconditions: None
   // Postconditions: None
   // Return value: length - An int value representing the length of the BCD object.
   // Functions called: None
   int numDigits() const;

   // #toString() - To return a string representation of the BCD object.
   // Parameters: returnString - Used to concatenate successive digits from the BCD.
   // Preconditions: None
   // Postconditions: None
   // Return value: A string representing the sequential digits in the BCD and a (-) sign prefix if negative.
   // Functions called: std::to_string() - To convert an int from a node data field to a string.
   const string toString() const;

   // #isGreaterMagnitudeThan() - Determines which term has a larger absolute value
   // Parameters: currT1 and CurrT2 - Used for iterative comparisons.
   // Preconditions: Two valid BCDs exist which can be compared
   // Postconditions: None
   // Return value: bool - True if the absolute value of T1 is greater than T2. False otherwise.
   // Functions called: None
   bool const isGreaterMagnitudeThan(const BCD& term2);

   // #deepcopy() - Generates a deep copy of the received target BCD.
   // Parameters: currT1 and CurrT2 - Used for iterative comparisons.
   // Preconditions: Two valid BCDs exist
   // Postconditions: The calling BCD's original content has been deallocated and replaced with nodes reflecting the target BCD.
   // Return value: None
   // Functions called: obliterate(), insertMSD()
   void const deepcopy(const BCD& target);

   // #int() - Custom behavior for the BCD to int conversion operator
   // Parameters: overflowInt - Higher capacity integer used to check from intMax to 999,999,999.
   // Preconditions: A BCD object exists with a valid numeric representation.
   // Postconditions: An int representation of the BCD number between (2^31)-1 and (-)(2^31) has been returned OR an 'out_of_range' error has been thrown.
   // Return value: returnInt - Variable storing the value of the BCD integer.
   // Functions called: None
   operator int() const;

   // #operator< - Custom behavior for the less-than operator when dealing with a BCD object (left) and a BCD object (right)
   // Parameters: currT1 and currT2 - Pointers to the current node being used for comparison
   // Preconditions: Two valid BCD objects exist and are being compared
   // Postconditions: None
   // Return value: Boolean - True if the Left-Hand Term (LHT) is 'less than' the Right-Hand Term (RHT), false if not.
   // Functions called: numDigits() - For the length of the BCD object.
   // Per pg. 436 - Modeled after operator== overload
   // bool operator<(const LinkedList<ItemType>& rightHandSide) const;
   bool operator<(const BCD& someBCD) const;

   // #operator== - Custom behavior for the equality operator when dealing with a BCD object (left) and a BCD object (right)
   // Parameters: currT1 and currT2 - Pointers to the current node being used for comparison
   // Preconditions: None
   // Postconditions: None
   // Return value: Boolean - True if BCDs being compared are the 'same', false if not.
   // Functions called: numDigits() - For the length of the BCD object.
   // Per pg. 436
   // bool operator==(const LinkedList<ItemType>& rightHandSide) const;
   bool operator==(const BCD& someBCD) const;


   // #operator= - Custom behavior for the assignment operator when dealing with a BCD object (left, implied) and a BCD object (right)
   // Parameters: None
   // Preconditions: Two valid BCD objects exist
   // Postconditions: The LeftHandSide BCD linked list has been replaced with a new linked list reflecting the values of the RightHandSide argument
   // Return value: *this, a pointer to the LeftHandSide argument
   // Functions called: obliterate(), deepcopy()
   // Per pg. 438
   // LinkedList<ItemType>& operator=(const LinkedList<ItemType>& rightHandSide);
   // Must include BCD:: to make this a 'member function', otherwise it's global.
   BCD& operator=(const BCD& someBCD);

   // #operator>> - Custom behavior for the insertion operator when dealing with an istream object (left) and a BCD object (right)
   // Parameters: numberBank - Used to store single int values from cin.
   // Preconditions: Content must be loaded to cin, terminated by newline characters. A valid BCD object must already exist.
   // Postconditions: The existing BCD object's internal nodes now represent the integer pulled from cin
   // Return value: cinData - An istream object.
   // Functions called: None
   // If it's in the class definition, include 'friend'
   friend istream& operator>>(istream& cinData, BCD& someBCD);
   // inputStream (by reference) operator-named->> ( <left argument type>(by reference) <left argument name>, <right argument type>(by reference) <right argument name>);

   // #operator<< - Custom behavior for the extraction operator when dealing with an ostream object (left) and a BCD object (right)
   // Parameters: thisBCDNumber - Used to store successive digits to be sent to 'cout'.
   // Preconditions: None
   // Postconditions: String representation of the BCD object will be sent to 'cout'.
   // Return value: None
   // Functions called: toString() - Converts BCD digits to a string object.
   // If it's in the class definition, include 'friend'
   friend ostream& operator<<(ostream& coutStream, BCD& someBCD);

   // #operator+ - Custom behavior for the addition operator when dealing with a BCD object (left) and a BCD object (right)
   // Parameters: this - The original BCD object being added to (implied) ; term2BCD - The BCD number being added to the term1BCD.
   // Preconditions: Two valid BCD objects exist
   // Postconditions: A new BCD object exists representing the summed addition of the old BCD and received BCD.
   // Return value: A new BCD object representing the summed addition
   // Functions called: BCD(int), add(), subtract(), isGreaterMagnitudeThan()
   const BCD operator+(BCD& term2BCD);

   // #operator- - Custom behavior for the subtraction operator when dealing with a BCD object (left) and a BCD object (right)
   // Parameters: term1BCD - The original BCD object being subtracted from ; term2BCD - The BCD number being subtracted from term1BCD.
   // Preconditions: None
   // Postconditions: A new BCD object exists representing the difference of the old BCD and received BCD.
   // Return value: A new BCD object representing the difference from subtraction
   // Functions called: BCD(int), add(), subtract, isGreaterMagnitudeThan()
   friend BCD operator-(BCD& term1BCD, BCD& term2BCD);

   // #operator* - Overload of the (*) operator for multiplication of two BCD objects.
   // Parameters: finalSum, tempProduct, nodeProduct, carry, T1curr, T2curr, ProductCurr (see below for descriptions)
   // Preconditions: Two valid BCD objects exist.
   // Postconditions: A new BCD exists representing the product of the two terms
   // Return value: A BCD representing the product
   // Functions called: numDigits(), insertLSD(), insertMSD()
   friend const BCD operator*(BCD& term1BCD, BCD& term2BCD);

   // #operator/ - Overload of the (/) operator for division of two BCD objects.
   // Parameters: result, sacriNumer, sacriDenom, numerSubset, counter, tempSign, sacriCurr (see below for descriptions)
   // Preconditions: Two valid BCD objects exist.
   // Postconditions: A new BCD exists representing the result of the two terms' division
   // Return value: A BCD representing the result
   // Functions called: insertLSD(), remove()
   friend const BCD operator/(BCD& term1BCD, BCD& term2BCD);


   //   friend const BCD& operator=(const BCD& someBCD);

   // ---- DESTRUCTORS -----

   // TODO: AFTER SUBMITTAL: Relocate destructor to location directly after constructors.
   // #~BCD() - Destructor - Deletes all dynamically allocated memory associated with a BCD object. Page 245-246
   // Parameters: None
   // Preconditions: A valid BCD object exists with a valid head node.
   // Postconditions: All dynamically allocated memory attached to the head node is deallocated.
   // Return value: None
   // Functions called: obliterate()
   ~BCD();

}; // Closing class 'BCD'
