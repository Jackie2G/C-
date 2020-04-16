#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

double obliczPi(int n){
    srand(500);
    double x, y;
    int k = 0;
    for(int i = 1; i <= n; i++){
        x = (double)rand() / float(RAND_MAX);
        y = (double)rand() / float(RAND_MAX);
        if(x * x + y * y <= 1) k++;
    }
    return 4 * double(k) / n;
}

int main(){

    int T;
    int n;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> n;
        cout << obliczPi(n) << endl;
    }
}