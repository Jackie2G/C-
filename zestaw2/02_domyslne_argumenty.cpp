#include<iostream>
using namespace std;

/*UWAGA na const*/
void printNTimes (const char * msg = "napis\n" , int n = 1) {
	for ( int i = 0; i < n ; ++ i ) {
	   cout << msg ;
	}
}

int main(){
  //printNTimes();
  //printNTimes("Niedomyslny napis\n");
  printNTimes("Niedomyslny napis\n", 5);

}
