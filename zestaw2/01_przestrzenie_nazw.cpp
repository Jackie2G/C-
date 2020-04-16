#include<iostream>
using namespace std; 
  
namespace nazwa{ 
    int val = 500; 
} 
  
int val = 100; 
  
int main() { 
    int val = 200; 
    cout << nazwa::val << '\n';  
    cout << val << '\n';  
    int arg1 ;
    arg1 = -1;

  {
    char arg1 = 'A';
    cout << arg1 << "\n" ;
  }

  cout << arg1 << "\n" ;
  
    return 0; 

}
