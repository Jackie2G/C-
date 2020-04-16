#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <math.h>

const int rozmiar = 1000;
double tablica[rozmiar][2];


using namespace std;


int czytaj(const char* nazwaPliku) {
    fstream inputStream{ nazwaPliku };
    if (inputStream.fail()) return -1;
    int i{ 0 };
    while (inputStream >> tablica[i][0] >> tablica[i++][1]) {}
    inputStream.close();
    return 0;
}

void obliczParametry(double &a, double &b){
    double xsum = 0, x2sum = 0, ysum = 0, xysum = 0;
    for (int i = 0; i < rozmiar; i++){
        xsum += tablica[i][0];
        ysum += tablica[i][1];
    }
    xsum = xsum / rozmiar;
    ysum = ysum / rozmiar;
    
    for (int j = 0; j < rozmiar; j++){
        xysum += (tablica[j][0] - xsum) * (tablica[j][1] - ysum);
        x2sum += pow((tablica[j][0] - xsum), 2.0);
    }
    a = xysum / x2sum;
    b = ysum - (a * xsum);
}

int main(){

    czytaj("dane2.txt");

    double a = 0, b = 0;
    obliczParametry(a, b);
    printf("Wspolczynniki a = %lf, b = %lf\n", a, b);

    return 0;
}