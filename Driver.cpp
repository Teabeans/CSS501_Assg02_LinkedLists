#include <iostream>
#include "BCD.h"

using namespace std;

int main() {
   // Control variables
   bool BCDConstructorDefaultTest = 1; // Done
   bool BCDtoStringTest = 1; // Done
   bool BCDOperatorIntTest = 1; // Done
   bool EqualityOperatorTest = 1; // Done
   bool BCDConstructorByIntTest = 1; // Done
   bool BCDnumDigitsTest = 1; // Done
   bool BCDRemoveTest = 1; // Done
   bool BCDObliterateTest = 1; // Done
   bool BCDConstructorBCDTest = 1; // Done
   bool BCDAssignmentOperatorTest = 1; // Done
   bool LessThanOperatorTest = 1; // Done

   bool DestructorTest = 1; // Not done - Test in Valgrind

   bool BCDIntAssignmentTest = 1; // Done
   bool MagnitudeTest = 1; // Done
   bool OperatorPlusTest = 1; // Done
   bool PlusAndAssignTest = 1; // Done
   bool cinDebugTest = 1; // Done - Confirm that the program can pull content in from cin.
   // In Visual Studio 2017, go to Debug > Project Properties... > Configuration Properties > Debugging > Command Arguments > Edit...
   // Enter '< someTextFileName.txt' (sans single quotes)
   // The above text file should be located in your project directory adjacent your source files, containing valid data entries
   // In this case, whitespace delimited integers.
   // The text file may be located elsewhere, but the command argument file path will need to be adjusted accordingly.
   bool cinBCDTest = 1; // Done
   bool OperatorPlusTestII = 1; // Done
   bool OperatorMinusTest = 1; // Done
   bool LimitBreakerTest = 1; // Done
   bool OperatorMultiply = 1; // Not done


   // Test of the BCD default constructor
   if (BCDConstructorDefaultTest == true) {
      cout << endl << "BCD Default Constructor test:" << endl;
      cout << "Insantiating BCD object... ";
      BCD constructorTest;
      cout << "Object of class 'BCD' created." << endl;
   }

   // Test of toString() method
   if (BCDtoStringTest == true) {
      cout << endl << "BCD toString() test:" << endl;
      if (BCDConstructorDefaultTest == true) { // Runs if the BCD default constructor is running
         BCD toStringTest;
         string testString = toStringTest.toString();
         cout << "BCD object's 'toString()' output: " << toStringTest.toString();
      }
      if (BCDConstructorDefaultTest == true) { // Runs if the BCD constructor by int is running
         BCD toStringTest1(123456789);
         BCD toStringTest2(-987654321);
         string testString1 = toStringTest1.toString();
         string testString2 = toStringTest2.toString();
         cout << "(+) BCD object's 'toString()' output: " << testString1 << endl;
         cout << "(-) BCD object's 'toString()' output: " << testString2 << endl;
      }
   }

   // Test of int operator overload
   if (BCDOperatorIntTest == true) {
      cout << endl << "BCD operator(int) test:" << endl;
      cout << "Insantiating BCD object... ";
      BCD BCDintTest(12345);
      cout << "Insantiating 'testInt' variable of type 'int'... ";
      int testInt;
      cout << "Assigning the BCD object to 'testInt'... ";
      testInt = BCDintTest;
      cout << "The value of 'testInt' is now: " << testInt << endl;

      cout << "Insantiating BCD object... ";
      BCD BCDintTest2(-2147483647);
      // Increments the BCD object by 1 (past the int overflow limit
      // BCDintTest2.headptr->moreSDptr->data++;
      // <Your access lines of code goes here>
      cout << "Insantiating 'testInt' variable of type 'int'... ";
      int testInt2;
      cout << "Assigning the BCD object to 'testInt'... ";
      testInt2 = BCDintTest2;
      cout << "The value of 'testInt' is now: " << testInt2 << endl;
   }

   // Test of equality operator
   if (EqualityOperatorTest == true) {
      cout << endl << "Equality operator overload test:" << endl;
      BCD equalityTest1(-123); //  Set 1: BCD signs differ
      BCD equalityTest2(123);  //  Set 1: Expected 1 : 0 : 0 : 1
      BCD equalityTest3(12345); //   Set 2: BCDs are equivalent
      BCD equalityTest4(12345); //   Set 2: Expected: 1 : 1 : 1 : 1
      BCD equalityTest5(22345); // Set 3: BCD value differs
      BCD equalityTest6(12345); // Set 3: Expected 1 : 0 : 0 : 1
      cout << "EQTest1 == EQtest1: " << (equalityTest1 == equalityTest1) << endl; // Expected: 1
      cout << "EQTest1 == EQtest2: " << (equalityTest1 == equalityTest2) << endl; // Expected: 0
      cout << "EQTest2 == EQtest1: " << (equalityTest2 == equalityTest1) << endl; // Expected: 0
      cout << "EQTest2 == EQtest2: " << (equalityTest2 == equalityTest2) << endl; // Expected: 1

      cout << "EQTest3 == EQtest3: " << (equalityTest3 == equalityTest3) << endl; // Expected: 1
      cout << "EQTest3 == EQtest4: " << (equalityTest3 == equalityTest4) << endl; // Expected: 0
      cout << "EQTest4 == EQtest3: " << (equalityTest4 == equalityTest3) << endl; // Expected: 0
      cout << "EQTest4 == EQtest4: " << (equalityTest4 == equalityTest4) << endl; // Expected: 1

      cout << "EQTest5 == EQtest5: " << (equalityTest5 == equalityTest5) << endl; // Expected: 1
      cout << "EQTest5 == EQtest6: " << (equalityTest5 == equalityTest6) << endl; // Expected: 0
      cout << "EQTest6 == EQtest5: " << (equalityTest6 == equalityTest5) << endl; // Expected: 0
      cout << "EQTest6 == EQtest6: " << (equalityTest6 == equalityTest6) << endl; // Expected: 1
   }

   // Test of BCD constructor by 'int'
   if (BCDConstructorByIntTest == true) {
      cout << endl << "BCD Constructor by 'int' test:" << endl;
      cout << "Insantiating positive BCD object... ";
      BCD constructorTest1(12345);
      cout << "Object of class 'BCD' created with value of " << constructorTest1.toString() << "." << endl;
      cout << "Insantiating negative BCD object... ";
      BCD constructorTest2(-12345);
      cout << "Object of class 'BCD' created with value of " << constructorTest2.toString() << "." << endl;
   }

   // Test of BCD numDigits() method: How many digits are in the BCD?
   if (BCDnumDigitsTest == true) {
      cout << endl << "BCD Number of Digits output test:" << endl;
      cout << "Insantiating empty BCD object... ";
      BCD numDigitsTest1;
      cout << "Insantiating BCD object with (7) digits... ";
      BCD numDigitsTest2(1234567);
      cout << "The number of digits should read 1:7. They are: " << numDigitsTest1.numDigits() << ":" << numDigitsTest2.numDigits() << endl;
   }

   // Test of BCD remove() method: Helper method for clear()
   if (BCDRemoveTest == true) {
      cout << endl << "BCD Remove() test:" << endl;
      BCD target(12345);

      target.remove(target.headptr->moreSDptr);
      cout << "Target condition (1234): " << target << endl; // Expected 1234
      cout << "isLastNode()" << target.isLastNode(target.headptr) << endl << endl;
      target.remove(target.headptr->lessSDptr);
      cout << "Target condition (234): " << target << endl; // Expected 234
      cout << "isLastNode()" << target.isLastNode(target.headptr) << endl << endl;
      target.remove(target.headptr->lessSDptr);
      cout << "Target condition (34): " << target << endl; // Expected 34
      cout << "isLastNode()" << target.isLastNode(target.headptr) << endl << endl;
      target.remove(target.headptr->lessSDptr);
      cout << "Target condition (4): " << target << endl; // Expected 4
      cout << "isLastNode()" << target.isLastNode(target.headptr) << endl << endl;
      target.remove(target.headptr->lessSDptr);
      cout << "Target condition (-): " << target << endl; // Expected -
      cout << "isLastNode()" << target.isLastNode(target.headptr) << endl << endl;
      cout << "Head deleted == " << target.remove(target.headptr); // This line requires that remove() return something (such as a bool)
      // Attempting to cout with a fully empty BCD will probably cause an exception.
   }

   // Test of BCD obliterate() method (a.k.a. clear() - renamed to avoid naming conflict with String method of same name)
   if (BCDObliterateTest == true) {
      cout << endl << "BCD Remove() test:" << endl;
      BCD obliterateTest(123456789);
      obliterateTest.obliterate();
      cout << "Output of deleted BCD: " << obliterateTest.toString() << "<end output>" << endl;
   }

   // Test of BCD Constructor by BCD
   if (BCDConstructorBCDTest == true) {
      BCD original(123123123);
      cout << "Contents of original: " << original << endl;
      cout << "Generating copy..." << endl;
      BCD copy(original);
      cout << "Contents of copy: " << copy << endl;
      cout << "Address pointed at by headpointers (original:copy)" << original.headptr << ":" << copy.headptr << endl;
      cout << "           Address of headpointers (original:copy)" << &original.headptr << ":" << &copy.headptr << endl;
   }

   // Test of assignment operator overload (=)
   if (BCDAssignmentOperatorTest == true) {
      cout << endl << "BCD Assignment Operator test:" << endl;
      BCD identity1(123);
      BCD identity2(456);
      cout << "Address comparison (ID1): " << &identity1 << " : " << identity1.headptr << endl << endl;
      cout << "Address comparison (ID2): " << &identity2 << " : " << identity2.headptr << endl << endl;

      cout << "Performing self-assignment... " << endl;
      identity1 = identity1;
      cout << "Address comparison (ID1): " << &identity1 << " : " << identity1.headptr << endl << endl;

      cout << "Performing other-assignment... " << endl;
      identity1 = identity2;
      cout << "Address comparison (ID1): " << &identity1 << " : " << identity1.headptr << endl << endl;
      cout << "Address comparison (ID2): " << &identity2 << " : " << identity2.headptr << endl << endl;
   }

   // Test of BCD destructor ~BCD()
   if (DestructorTest == true) {
      cout << endl << "BCD Destructor test:" << endl;
      cout << "Note: No meaningful output is likely to be generated here. Use Valgrind." << endl;
      // To compile in Linux:
      // g++ -std=c++11 PunchCard.cpp main.cpp

      // To install Valgrind:
      // sudo apt install valgrind

      // To run Valgrind:
      // valgrind --leak-check=full <file path>/a.out
      // valgring --leak-check=full --show-leak-kinds=all <file path>/a.out

      BCD destructThis(24682468);
   } // Destructor (~BCD*()) gets called right here

   // Test of the Less Than comparison operator
   if (LessThanOperatorTest == true) {
      cout << endl << "Comparison operator < test:" << endl;
      BCD term1(1234);
      BCD term2(-4321);
      BCD term3(1234);
      cout << "T1 == T2? (0) : " << (term1 == term2) << endl;
      cout << "T1 >  T2? (1) : " << (term1 >  term2) << endl;
      cout << "T1 <  T2? (0) : " << (term1 <  term2) << endl;
      cout << "T1 == T3? (1) : " << (term1 == term3) << endl;
      cout << "T2 <= T3? (1) : " << (term2 <= term3) << endl;
      cout << "T2 >= T3? (0) : " << (term2 >= term3) << endl;
      cout << "T1 >= T3? (1) : " << (term1 >= term3) << endl;
   }

   // Test of BCD int assignment
   if (BCDIntAssignmentTest == true) {
      cout << endl << "BCD Int Assignment test:" << endl;
      cout << "Assigning int (13579) to BCD object" << endl;
      BCD assignmentTest = 13579;
      cout << "The value of the test BCD is: " << assignmentTest.toString() << endl;
      cout << "Reassigning a value (2468)..." << endl;
      assignmentTest = 2468;
      cout << "The value of the test BCD is: " << assignmentTest.toString() << endl;
      cout << "Reassigning a value (-9999)..." << endl;
      assignmentTest = -9999;
      cout << "The value of the test BCD is: " << assignmentTest.toString() << endl;
   }

   // Test of BCD magnitude judging
   if (MagnitudeTest == true) {
      cout << endl << "Magnitude test:" << endl;
      BCD term1(12345);
      BCD term2(-12345);

      BCD term3(12345);
      BCD term4(-12346);

      BCD term5(12346);
      BCD term6(-1234);

      cout << "T1 is greater magnitude than T2? (expect 0) : " << term1.isGreaterMagnitudeThan(term2) << endl;
      cout << "T3 is greater magnitude than T4? (expect 0) : " << term3.isGreaterMagnitudeThan(term4) << endl;
      cout << "T5 is greater magnitude than T6? (expect 1) : " << term5.isGreaterMagnitudeThan(term6) << endl;
   }

   // Test of Operator+ overload
   if (OperatorPlusTest == true) {
      cout << endl << "Operator+ test:" << endl;
      BCD term1(123);
      BCD term2(333);
      cout << "Term1: " << term1.toString() << endl;
      cout << "Term2: " << term2.toString() << endl;
      term1 + term2;
      cout << "Operator+ completed successfully." << endl;
   }

   // Test of Operator+ and Operator= overload
   if (PlusAndAssignTest == true) {
      cout << endl << "Operator+ and Operator= test:" << endl;
      BCD term1(123); 
      BCD term2(654);
      // cout << term1 << term2 << endl; // DEBUG

      BCD term3 = term1 + term2;
      // cout << term3 << endl; // DEBUG
      cout << "If result is '777', Operator+ and Operator= overload test completed successfully." << endl;
   }

   // Test of external prompt to cin input stream
   if (cinDebugTest == true) {
      cout << endl << "Reading from cin" << endl;
      string test = "";
      cin >> test;
      cout << test;
   }

   // Test of cin input to a BCD object
   if (cinBCDTest == true) {
      BCD cinEater;
      cout << "Content of cinEater: " << cinEater << endl;
      cout << "Inserting content from cin..." << endl;
      cin >> cinEater;

      cout << "Content of cinEater: " << cinEater << endl;
   }

   // Test of Operator+ overload, round II
   if (OperatorPlusTestII == true) {
      cout << endl << "Operator+ test:" << endl;
      BCD term1(99345);
      BCD term2(654);
      BCD sum1;

      BCD term3(-99345);
      BCD term4(-654);
      BCD sum2;

      BCD term5(100122);
      BCD term6(-123);
      BCD sum3;

      BCD term7(-100122);
      BCD term8(123);
      BCD sum4;

      sum1 = term1 + term2;
      sum2 = term3 + term4;
      sum3 = term5 + term6;
      sum4 = term7 + term8;

      cout << "Operator+ completed successfully." << endl;

      cout << "Results sum1 (expect +99999): " << sum1 << endl;
      cout << "Results sum2 (expect -99999): " << sum2 << endl;
      cout << "Results sum3 (expect +99999): " << sum3 << endl;
      cout << "Results sum4 (expect -99999): " << sum4 << endl;

      cout << "Updating sums..." << endl;

      sum1 = term2 + term1;
      sum2 = term3 + term4;
      sum3 = term5 + term6;
      sum4 = term7 + term8;

      cout << "Results sum1 (expect +99999): " << sum1 << endl;
      cout << "Results sum2 (expect -99999): " << sum2 << endl;
      cout << "Results sum3 (expect +99999): " << sum3 << endl;
      cout << "Results sum4 (expect -99999): " << sum4 << endl;

      cout << "Updating sums for negation..." << endl;

      sum1 = term1 + term3;
      sum2 = term4 + term2;
      sum3 = term7 + term5;
      sum4 = term8 + term6;

      cout << "Results sum1 (expect +0): " << sum1 << endl;
      cout << "Results sum2 (expect +0): " << sum2 << endl;
      cout << "Results sum3 (expect +0): " << sum3 << endl;
      cout << "Results sum4 (expect +0): " << sum4 << endl;
   }

   // Test of Operator- overload
   if (OperatorMinusTest == true) {
      cout << endl << "Operator- test:" << endl;
      BCD term1(100122);
      BCD term2(123);
      BCD sum1;

      BCD term3(-100122);
      BCD term4(-123);
      BCD sum2;

      BCD term5(99876);
      BCD term6(-123);
      BCD sum3;

      BCD term7(-99876);
      BCD term8(123);
      BCD sum4;

      sum1 = term1 - term2; // +99999
      sum2 = term3 - term4; // -99999
      sum3 = term5 - term6; // +99999
      sum4 = term7 - term8; // -99999

      cout << "Results sum1 (expect +99999): " << sum1 << endl;
      cout << "Results sum2 (expect -99999): " << sum2 << endl;
      cout << "Results sum3 (expect +99999): " << sum3 << endl;
      cout << "Results sum4 (expect -99999): " << sum4 << endl;

      cout << "Updating sums..." << endl;

      sum1 = term2 - term1; // -99999
      sum2 = term4 - term3; // +99999
      sum3 = term6 - term5; // -99999
      sum4 = term8 - term7; // +99999

      cout << "Results sum1 (expect -99999): " << sum1 << endl;
      cout << "Results sum2 (expect +99999): " << sum2 << endl;
      cout << "Results sum3 (expect -99999): " << sum3 << endl;
      cout << "Results sum4 (expect +99999): " << sum4 << endl;

      cout << "Updating sums for negation..." << endl;

      sum1 = term1 - term5 - term8 - term8; // 0
      sum2 = term3 - term7 - term4 - term4; // 0
      sum3 = term5 - term1 - term6 - term6; // 0
      sum4 = term7 - term3 - term8 - term8; // 0

      cout << "Results sum1 (expect +0): " << sum1 << endl;
      cout << "Results sum2 (expect +0): " << sum2 << endl;
      cout << "Results sum3 (expect +0): " << sum3 << endl;
      cout << "Results sum4 (expect +0): " << sum4 << endl;

      cout << "Operator- completed successfully." << endl;
   }

   // Test of breaking 'int' limit
   if (LimitBreakerTest == true) {
      cout << endl << "Limit Breaker test:" << endl;
      BCD term1(2147483647);
      BCD term2(2147483647);
      BCD sum1 = term1 + term2;
      cout << "Sum1: " << sum1 << endl;
   }

   // Test of multiply operator
   if (OperatorMultiply == true) {
      cout << endl << "Multiplication test:" << endl;
      BCD term1(123);
      BCD term2(12);
      BCD product = term1 * term2;
      cout << "Product: " << product << endl;
   }

   cout << "Final test complete!" << endl;
   /*
   cout << n2 << " + 975 (int) = " << n1 << endl;



   BCD n3 = 64;
   cout << "Converted 64 (int) to " << n3 << " BCD" << endl;

   BCD sum = n1 + n3;
   BCD difference = n1 - n3;
   BCD product = n1 * n3;
   BCD quotient = n1 / n3;
   cout << n1 << " + " << n3 << " = " << sum;
   cout << n1 << " - " << n3 << " = " << difference;
   cout << n1 << " * " << n3 << " = " << product;
   cout << n1 << " / " << n3 << " = " << quotient;

   cout << product << " has " << product.numDigits() << " digits" << endl;
   
   */

   return (0);
}
