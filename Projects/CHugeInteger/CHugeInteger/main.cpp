#include "CHugeInteger.h"

int main() {
   CHugeInteger a, b, c;
   a.read();
   b.read();
   c = a * b;
   c.Print();
   return 0;
}