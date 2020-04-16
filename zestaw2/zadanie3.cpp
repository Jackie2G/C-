#include <iostream>

using namespace std;

void zamien(double* x, double* y){
    double pomocnicza{*x};
    *x = *y;
    *y = pomocnicza;
}

void zamien(double& x, double& y){
    double pomocnicza{x};
    x = y;
    y = pomocnicza;
}

int main(){
    double a = 2.0, b = 4.0;
    double* x = &a;
    double* y = &b;
    zamien(x, y);
    printf("Po zamianie x: %lf, y: %lf \n", *x, *y);
    zamien(&a, &b);
    printf("Po zamianie x: %lf, y: %lf \n", *x, *y);
}