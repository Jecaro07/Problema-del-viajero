#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <cmath>
//#include <array>

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>


#define _USE_MATH_DEFINES

using namespace std;
 using std::vector;
 
 void pedir_pantalla_f(int &A, int &B, vector<vector<float>> &puntos,
 vector<float> &punto_final){
 
 int coordenadas,n_puntos;
  float pto;

	// COORDENADAS
	do{		
	cout << "Numero de coordenadas que manejamos (2/3): " << endl; 
   cin >> coordenadas;		
	}while(coordenadas!=3 && coordenadas!=2);
   cout << "Coordenadas: " << coordenadas << endl;
   
   // NUMERO DE PUNTOS
   cout << "Numero de puntos que manejamos (entero): " << endl; 
   cin >> n_puntos;	
   
   puntos.resize(n_puntos); // IMPORTANTE EL RESIZE
   punto_final.resize(coordenadas);
   
   // PUNTO INICIAL
   puntos[0].resize(coordenadas); // IMPORTANTE EL RESIZE
   for(int j=0; j<coordenadas;j++){ 
   cout << "Punto inicial; coordenada " << j+1 << " : " << endl; 
	cin >> pto; 
	puntos[0][j]=pto; }// fin del for 
	
	// PUNTO FINAL
	for(int j=0; j<coordenadas;j++){ 
   cout << "Punto final; coordenada " << j+1 << " : " << endl; 
	cin >> pto; 
	punto_final[j]=pto; }// fin del for 
   
   // PUNTOS DE LA TRAYECTORIA
   for(int i=1; i<n_puntos;i++){
	   puntos[i].resize(coordenadas); // IMPORTANTE EL RESIZE
	   for(int j=0; j<coordenadas;j++){   
   	cout << "Punto de la trayectoria numero "<< i+1 << " ; coordenada " << j+1 << " : " << endl; 
	cin >> pto; 
	puntos[i][j]=pto;  
   }} // fin de ambos for
   
   B=coordenadas; A=n_puntos;
 
 }
 
 
int main () {
	
   int A,B;
   vector<vector<float>> puntos;
   vector<float> punto_final;
  
  pedir_pantalla_f(A, B,puntos,punto_final);

   
  return 0; 
}
