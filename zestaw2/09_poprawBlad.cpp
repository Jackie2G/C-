#include<iostream>
#include <cstdlib> //zawiera funkcje matematyczne
using namespace std;

int difference ( const int x , const int y ) {

    int diff = abs ( x - y ) ;
    return diff;
}


int main () {

    cout << difference (24 , 1238) << endl;

    return 0;

}


