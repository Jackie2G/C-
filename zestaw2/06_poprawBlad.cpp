#include<iostream>
#include<cstdlib>
using namespace std;

int x = 0;
/*Napraw blad*/
int *getRandNumPtr () {
  x = rand () ;
  return &x;
}


int main () {
  int *randNumPtr = getRandNumPtr();
  cout << *randNumPtr << endl;
  return 0;
 }
