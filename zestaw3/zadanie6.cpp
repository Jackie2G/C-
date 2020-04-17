#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
using namespace std;

int count_columns(string nazwaPliku){
    fstream inputStream{ nazwaPliku};
    if (inputStream.fail()) return -1;
    string dummyLine;
    getline(inputStream, dummyLine);
    inputStream.close();
    //ponizej liczymy wszystkie kolumny oddzielone za pomoca znaku tabulacji lub spacji
    const int numCollums = count( dummyLine.begin(), dummyLine.end(), '\t' ) + count( dummyLine.begin(), dummyLine.end(), ' ' ) + 1;
    return numCollums;
}

int count_rows(string nazwaPliku){
    fstream inputStream{ nazwaPliku };
    if (inputStream.fail()) return -1;
    int lines = 0;
    string dummyLine;;
    while (inputStream.peek() != EOF){
        getline(inputStream, dummyLine);
        lines++;
    }
    inputStream.close();
    return lines;
}

// int sizeX = count_rows("dane2.txt");
// int sizeY = count_columns("dane2.txt");
// double* tab = new double[sizeX*sizeY];

int obliczParametry(string nazwaPliku, double &a, double &b, int sizeX, int sizeY, double* tab){
    fstream inputStream{ nazwaPliku };
    if (inputStream.fail()) return -1;
    for (int i = 0; i < sizeX; i++){
        for (int j = 0; j < sizeY; j++){
            inputStream >> tab[i * sizeY + j];
        }
    }
    inputStream.close();
    double xsum = 0, x2sum = 0, ysum = 0, xysum = 0;
    for (int i = 0; i < sizeX; i++){
        xsum += tab[i * sizeY];
        ysum += tab[i * sizeY + 1];
    }
    xsum = xsum / sizeX;
    ysum = ysum / sizeX;
    
    for (int j = 0; j < sizeX; j++){
        xysum += (tab[j * sizeY] - xsum) * (tab[j * sizeY + 1] - ysum);
        x2sum += pow((tab[j * sizeY] - xsum), 2.0);
    }
    a = xysum / x2sum;
    b = ysum - (a * xsum);
    return 0;
}

int main(){
    double a = 0, b = 0;
    string plik;
    cin >> plik;
    int sizeX = count_rows("dane2.txt");
    int sizeY = count_columns("dane2.txt");
    double* tab = new double[sizeX*sizeY];
    obliczParametry(plik, a, b, sizeX, sizeY, tab);
    printf("Wspolczynniki a = %lf, b = %lf\n", a, b);
    return 0;
}
