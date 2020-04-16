#include<iostream>
using namespace std;

int main(){

const int a = 10;
const int *ptr1 = &a; //wskaznik do stalej typu int. Mozna modyfikowac wskaznik, nie mozna modyfikowac obiektu na ktory wskazuje.
ptr1++;    // OK
//*ptr1 = 5; // error


int b = 10;
int *const ptr2 = &b;//staly wskaznik do typu int. Mozna modyfikowac obiekt, na ktory wskazuje wskaznik, nie mozna modyfikowac samego wskaznika.
*ptr2 = 5; // OK
//ptr2++;    // error
}
