#include <iostream>
#include <cmath>
#include <vector>

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

int main () {
   figgeo <float> variable (2.2);
   vector<float> pepe;
   pepe=variable.circulo();
   cout << pepe[1] << endl;
   cout << variable.cuadrado() << endl;
  return 0;
}
