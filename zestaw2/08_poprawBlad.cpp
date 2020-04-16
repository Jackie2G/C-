#include<iostream>
using namespace std;

void doubleNumber ( int &num ) { num = num * 2;}

int main () {
  int num = 35;
  doubleNumber ( num ) ;
  cout << num << endl; // Chcemy, by num = 70
  return 0;
}

