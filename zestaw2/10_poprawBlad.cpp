#include<iostream>
using namespace std;


const int ARRAY_LEN = 10;

int main () {


  int arr [ ARRAY_LEN ] = {10}; // Zwroc uwage na inicjalizacje


  int *xPtr = arr;
  int *yPtr = arr + ARRAY_LEN - 1;


  cout << *xPtr <<"\t" << *yPtr << endl; // Powinno byc 10 0


  return 0;

 }

