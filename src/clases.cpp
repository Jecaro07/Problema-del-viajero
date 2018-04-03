#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#define _USE_MATH_DEFINES

using namespace std;
 using std::vector;

template <class T>
class figgeo {
    T d;
  public:
    figgeo (T dato)
      {d=dato;}
    vector<T> circulo();
    T cuadrado();
};

template <class T>
vector<T> figgeo<T>::circulo()
{
  vector<T> retval;
  retval.resize(2);
  retval[0]=2*M_PI*d; // PERIMETRO
  retval[1]=M_PI*d*d; // AREA
  return retval;
}

template <class T>
T figgeo<T>::cuadrado()
{
  T retval;
  retval = d*4; // DEVUELVE a SI SE CUMPLE Y b EN EL CASO CONTRARIO
  return retval;
}

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int main () {
    string line; float dd;
    vector <string> words;
  ifstream myfile;
  myfile.open("datos.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
		words = split(line,' ');
		//dd=stof(line);	
      cout << line<< '\n';
    }
    cout<<endl;
    for(int j=0;j<words.size();j++){
    cout << words[j]<< '\n';}
    
    myfile.close();
  }

  else cout << "Unable to open file"; 

   
   
  return 0;
}
