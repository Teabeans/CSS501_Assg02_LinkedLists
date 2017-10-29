#include <iostream>
#include "BCD.h"

using namespace std;

int main() {
   // Control variables
   bool BCDConstructorDefaultTest      = 0;
   bool BCDtoStringTest                = 0;
   bool BCDOperatorIntTest             = 0;
   bool EqualityOperatorTest           = 0;
   bool BCDConstructorByIntTest        = 0;
   bool BCDnumDigitsTest               = 0;
   bool BCDAssignmentOperatorTest      = 0;
   bool DestructorTest                 = 0;
   bool BCDIntAssignmentTest           = 1;

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

   // Test of assignment operator overload (=)
   if (BCDAssignmentOperatorTest == true) {
      cout << endl << "BCD Assignment Operator test:" << endl;
      BCD identity1;
      BCD identity2;
      cout << "Address of Identity1: " << &identity1 << endl;
      cout << "Address of Identity2: " << &identity2 << endl;

      cout << "Address of ID1.headptr: " << identity1.headptr << endl;
      cout << "Address of ID2.headptr: " << identity2.headptr << endl;

      cout << "Performing self-assignment... " << endl;
      identity1 = identity1;
      cout << "Address of ID1: " << &identity1 << endl;
      cout << "Address of ID1.headptr: " << identity1.headptr << endl;
      cout << "Above addresses should match old ID1 and ID1.headptr addresses." << endl;

      cout << "Performing other-assignment... " << endl;
      identity1 = identity2;
      cout << "Address of Identity1: " << &identity1 << endl;
      cout << "Address of Identity2: " << &identity2 << endl;
      cout << "Address of ID1.headptr: " << identity1.headptr << endl;
      cout << "Address of ID2.headptr: " << identity2.headptr << endl;
      cout << "Address of ID1, ID2, and ID2.headptr should remain unchanged." << endl << "Address of ID1.headptr should be new." << endl;
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

   // Test of BCD int assignment
   if (BCDIntAssignmentTest == true) {
      cout << endl << "BCD Int Assignment test:" << endl;
      cout << "Assigning int to BCD object" << endl;
      BCD assignmentTest = 13579;
      cout << "The value of the test BCD is: " << assignmentTest.toString() << endl;
   }
     
     if (true) {
     int someInt = 12345;
     BCD destructorTest(someInt);
     }

     int a = 123456;
     int b = 12341123;

     BCD n1(a);
     cout << "Start N1 " << n1 << endl;
     BCD n2(b);
     cout << "Start N2 " << n2 << endl;

     cout << "Converted 125 (int) to " << n2 << " BCD" << endl;
     // TODO: Program is breaking here
     n1 = n1 + n2;
     cout << "Did we reach this?" << endl;
     n1 - n2;

     n1 = n2 + b;
     cout << "Final test complete!" << endl;
     /*
     cout << n2 << " + 975 (int) = " << n1 << endl;

     cin >> n2;
     cout << "Input " << n2 << endl;

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
