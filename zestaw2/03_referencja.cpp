#include<iostream>
using namespace std;

/*Jeszcze raz wskaźniki + referencja*/
void print1(int i){//dzialamy na lokalnej kopii
  //cout << "W funkcji print1 " << ++i <<endl;
  cout << "W funkcji print1 " << i++ <<endl;
}

void print2(int *i){// w stylu C

   cout << "W funkcji print2 " << ++(*i) << endl;//Co by sie stalo, gdyby nie bylo gwiazdki?

}

void print3 (int &x) {// w stylu C++
      cout << "W funkcji print3 " << ++x << endl;;
}


int main(){
   int x = 23;
   int *p = &x;
   int &referencja = x;
   
   //print1(x); 
   //cout <<"Po wyjsciu z funkcji print1 x = " << x << endl;
   
   //print2(p);
   //print2(&x);
   //cout <<"Po wyjsciu z funkcji print2 x = " << x << endl;
   
   //print3(x);
   print3(referencja);
   cout <<"Po wyjsciu z funkcji print3 x = " << x << endl;
   
   return 0;
}
