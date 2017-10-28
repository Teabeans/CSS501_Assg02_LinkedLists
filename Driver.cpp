#include <iostream>
#include "BCD.h"

using namespace std;

int main() {
   // Control variables
   bool BCDConstructorDefaultTest      = 1;
   bool BCDtoStringTest                = 1;
   bool BCDOperatorIntTest             = 1;
   bool EqualityOperatorTest           = 1;
   bool BCDConstructorByIntTest        = 1;
   bool BCDnumDigitsTest               = 1;
   bool BCDAssignmentOperatorTest      = 0;
   bool DestructorTest                 = 1;

   // Test of the BCD default constructor
   if (BCDConstructorDefaultTest == true) {
      cout << endl <<  "BCD Default Constructor test:" << endl;
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
      BCD equalityTest1;
      BCD equalityTest2;
      cout << "EQTest1 == EQtest1: " << (equalityTest1 == equalityTest1) << endl; // Expected: 1
      cout << "EQTest1 == EQtest2: " << (equalityTest1 == equalityTest2) << endl; // Expected: 0
      cout << "EQTest2 == EQtest1: " << (equalityTest2 == equalityTest1) << endl; // Expected: 0
      cout << "EQTest2 == EQtest2: " << (equalityTest2 == equalityTest2) << endl; // Expected: 1
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
      // To compile in Linux:
      // g++ -std=c++11 PunchCard.cpp main.cpp
      // To run Valgrind:
      // valgrind --leak-check=full .a/a.out
      BCD destructThis(24682468);
   } // Destructor (~BCD*()) gets called right here

   /*
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
   n1 + n2;
   cout << "Did we reach this?" << endl;
//   n1 - n2;

   //n1 = n2 + b;
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
