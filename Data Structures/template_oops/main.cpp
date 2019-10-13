#include <iostream>
using namespace std ;
template <class X>
void bigger( X a, X b) {
   if(a>b)
    cout << " \nGreater out of a and b is  " << a << endl;
   else
   cout << " \nGreater out of a and b is  " << b << endl;
}
int main( ) {
    int a = 10, b = 20 ;
    float c = 10.5, d = 20.5 ;
    bigger(a , b);                   // function using int parameters
    bigger(c , d);                   // function using float parameters
    bigger ('e','f');               // function using char parameters
    return 0;
}
