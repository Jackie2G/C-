#include <iostream>
#include <fstream>

using namespace std;

class Point{
    private:
    int x, y;
    public:
    Point(){
        x = 0;
        y = 0;
    }
    Point(int nx, int ny){
        x = nx;
        y = ny;
    }
    int getX() const { return x; }

    int getY() const { return y; }

    void setX(const int new_x){
        x = new_x;
    }

    void setY(const int new_y){
        y = new_y;
    }
};

int main(){
    Point punkt;
    cout << punkt.getX();
    cout << '\t';
    cout << punkt.getY() << endl;
    int a, b, c, d, t;
    cin >> a;
    cin >> b;
    Point punkt1(a, b);
    cout << punkt1.getX();
    cout << '\t';
    cout << punkt1.getY() << endl;
    Point punkt2;
    cin >> c;
    cin >> d;
    punkt2.setX(c);
    punkt2.setY(d);
    cout << punkt2.getX();
    cout << '\t';
    cout << punkt2.getY() << endl;
    cin >> t;
    Point *tab = new Point[t];
    for (int i = 0; i < t; i ++){
        cin >> a;
        cin >> b;
        tab[i] = Point(a, b);
        cout << tab[i].getX();
        cout << '\t';
        cout << tab[i].getY() << endl;
    }
    delete[] tab;

    return 0;
}