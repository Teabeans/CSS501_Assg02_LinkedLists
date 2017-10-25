#include <iostream>
#include "BCD.h"

using namespace std;

int main() {
   int a = 123;
   int b = 876;

   BCD n1(a);
   cout << "Start N1 " << n1 << endl;
   BCD n2(b);
   cout << "Start N2 " << n2 << endl;

   cout << "Converted 125 (int) to " << n2 << " BCD" << endl;
   n1 + n2;
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
