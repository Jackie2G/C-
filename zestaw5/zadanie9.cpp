#include <iostream>
#include <cstddef>

using namespace std ;

class Point {

  // tutaj przepisz klase Point z poprzednich zajec
  
};

class PointArray {
  int size ;
  Point *points ;
  void resize ( int newSize ) {
    //Metoda, ktora skraca, badz wydluza tablice points wg rozmiaru podanego jako argument*/
  }
  
  public:
  PointArray () {
    size = 0;
    points = new Point [0];
  }



  PointArray (const Point ptsToCopy [] , const int toCopySize) {
     //konstruktor

  }

  PointArray ( const PointArray & other ) {
     //konstruktor kopiujacy.
  }


  ~PointArray () {
  //destruktor
    delete [] points ;
  }
  
  void clear () {
    resize (0) ;
  }

  void push_back ( const Point & p ) {
    /*Zaimplementuj metode, ktora dodaje element na koniec tablicy. Uzyj metody resize*/
  }



  void insert ( const int pos , const Point & p ) {
    /*Zaimplementuj metode, ktora wstawia element na pozycje pos. Uzyj metody resize*/
  }



  void remove ( const int pos ) {
    /*Zaimplementuj metode, ktora usuwa element z pozycji pos. Uzyj metody resize*/  
  }




  void print(){
    if(getSize() == 0) cout << "Pusta tablica" << endl;
    for(int i = 0; i < getSize(); i++){
        cout << "[" << i << "] " << s << ": " << points[i].getX() << "\t" << points[i].getY() << endl;
    }
  }
  

  int getSize () const { 
  //metoda zwracajaca aktualny rozmiar obiektu PointArray
  
  }

};


//Funkcja pomocnicza
string getWord(string& s) {
  string word = "";                                                                                                                         
  size_t space_pos = s.find(" ");    

  if (space_pos != string::npos) {
    word = s.substr(0, space_pos);
    s = s.substr(space_pos + 1);
  } else if (s.size() > 0) {
    word = s;
  }

  return word;
}


/////////////////////////////PROSZE DOPISAC BRAKUJACE ELEMENTY KODU///////////////
////////////////////////////PROSZE NIC Z PLIKU NIE KASOWAC///////////////////////
///////////////////////////uruchamianie: ./a.out < input.txt //////////////////
int main(){

  PointArray pArr;
  string line = "";
  getline(cin, line);
  string cmd = getWord(line);
  while (cmd != "end") {
    if(cmd == "clear"){
       pArr.clear();
       cout << "clear:" << endl;
       pArr.print();
       cout << "dlugosc tablicy: " << pArr.getSize() << endl;
    }
    else if(cmd == "push_back"){
       cout << "push_back: " << line << endl;
       int x = stoi(getWord(line));
       int y = stoi(getWord(line));
       Point p(x, y);
       pArr.push_back(p);
       pArr.print();
       cout << "dlugosc tablicy: " << pArr.getSize() << endl;
    }
    else if(cmd == "remove"){
       cout << "remove: " << line << endl;
       int pos = stoi(getWord(line));
       pArr.remove(pos);
       pArr.print();
       cout << "dlugosc tablicy: " << pArr.getSize() << endl;
    }
    else if(cmd == "insert"){
       cout << "insert: " << line << endl;
       int pos = stoi(getWord(line));
       int x = stoi(getWord(line));
       int y = stoi(getWord(line));
       Point p(x, y);
       pArr.insert(pos, p);
       pArr.print();
       cout << "dlugosc tablicy: " << pArr.getSize() << endl;
    }
    else{
      cout << "CMD: " << cmd << ":\tnieznana" << endl;
    }
    getline(cin, line);
    cmd = getWord(line);

  }
    

}


