#include <iostream>
#include <cstddef>

using namespace std ;

class Point {

  // tutaj przepisz klase Point z poprzednich zajec
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

class PointArray {
  int size ;
  Point *points ;
  void resize ( int newSize ) {
    //Metoda, ktora skraca, badz wydluza tablice points wg rozmiaru podanego jako argument*/
    Point *ptsToCopy = points;
    points = new Point[newSize];
    for (int i = 0; i < newSize; i++){
      points[i] = ptsToCopy[i];
    }
    size = newSize;
    delete [] ptsToCopy;
  }
  
  public:
  PointArray () {
    size = 0;
    points = new Point [0];
  }



  PointArray (const Point ptsToCopy [] , const int toCopySize) {
     //konstruktor
    size = toCopySize;
    points = new Point[size];
    for (int i = 0; i < size; i++){
      points[i] = ptsToCopy[i];
    }

  }

  PointArray ( const PointArray & other ) {
     //konstruktor kopiujacy.
    size = other.size;
    points = new Point[size];
    for (int i = 0; i < size; i++){
      points[i] = other.points[i];
    }
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
    resize(size + 1);
    points[size - 1] = p;
  }



  void insert ( const int pos , const Point & p ) {
    /*Zaimplementuj metode, ktora wstawia element na pozycje pos. Uzyj metody resize*/
    if (pos < size){
      resize(size + 1);
      for (int i = size - 1; i > pos; i--){
        points[i] = points[i - 1];
      }
      points[pos] = p;
    }
    else if (pos == size){
      push_back(p);
    }
    else{
      resize(pos + 1);
      points[pos] = p;
    }
  }



  void remove ( const int pos ) {
    /*Zaimplementuj metode, ktora usuwa element z pozycji pos. Uzyj metody resize*/
    Point last_one = points[size - 1];  
    resize(size - 1);
    int i = pos;
    for(i; i < size - 1; i++){
      points[i] = points[i + 1];
    }
    points[i] = last_one;
  }




  void print(){
    if(getSize() == 0) cout << "Pusta tablica" << endl;
    for(int i = 0; i < getSize(); i++){
        cout << "[" << i << "] " << ": " << points[i].getX() << "\t" << points[i].getY() << endl;
    }
  }
  

  int getSize () const { 
  //metoda zwracajaca aktualny rozmiar obiektu PointArray
    return size;
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


