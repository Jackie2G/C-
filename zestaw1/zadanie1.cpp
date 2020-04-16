#include <iostream>
#include <fstream>
using namespace std;

typedef struct wezel {
    
    char *tytul;
    char *autor;
    double cena;
    int ilosc;
    struct wezel *nastepny;
} ksiazka;

ksiazka *glowa = NULL;

void push_back(ksiazka *element){

    wezel *t = new wezel(*element);
    wezel *tmp = glowa;
    if (tmp == nullptr)
    {
        glowa = t;
    }
    else
    {
        while (tmp->nastepny != nullptr)
        {
            tmp = tmp-> nastepny;
        }
        tmp->nastepny = t;
    }
}

int wypelnij_strukture(const char* nazwaPliku){
    fstream inputStream { nazwaPliku };
    if (inputStream.fail()) return -1;
}

int main(){

    cout << "jest git \n";
    return 0;
}

