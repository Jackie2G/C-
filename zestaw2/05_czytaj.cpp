#include <iostream>
#include <fstream>
using namespace std;

int main(){
/*  unsigned int n;
  cout << "Podaj liczbe\n" << endl;
  cin >> n;
  cout <<"Wprowadzono n = " << n << endl;
*/
/*  ofstream output;
  output.open ("przyklad.txt");
  if (output.is_open())
  {
    output << "Ten tekst zapiszemy w pliku.\n";
    output << "To beda trzy linie.\n";
    output << "A to jest ostatnia linia.\n";
  }
  else cout << "Blad. Nie mozna otworzyc pliku.\n";
  output.close();
  
*/
/*
  string line;
  ifstream input ("przyklad.txt");
  if (input.is_open())
  {
    while ( getline (input,line) )
    {
      cout << line << '\n';
    }
    input.close();
  }

  else cout << "Blad. Plik nie istnieje.\n"; 
*/
  int tablica[100];
  ifstream input2 ("dane1.txt");
  if (input2.is_open())
  {
    for (int i = 0; i < 100; i++){
    input2 >> tablica[i];
    }
  }

  else cout << "Blad. Plik nie istnieje.\n"; 
  cout << tablica[0] << endl;
  input2.close();



}

  


