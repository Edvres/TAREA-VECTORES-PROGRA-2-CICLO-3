#include<queue> //Libreria que se encarga del funcionamiento de la cola
#include <iostream>//Libreria para entrada y salida de datos
#include <windows.h>//Libreria que contiene las declaraciones de todas las funciones de la biblioteca Windows API,
#include <cstdlib>//Libreria con gestión de memoria dinámica, control de procesos y otras
#include <math.h>//Libreria para problemas matematicos
#include <stdlib.h>//para gestión de memoria dinámica, control de procesos y otras




//Esta programacion fue hecha por EDWIN ELIAS VALLADARES PORTILLO (VP18007)





//CONSISTE EN UTILIZAR COLAS QUE PERMITA ALMACENAR UN VECTOR CON LOS PUNTOS X Y Z EL PROGRAMA MUESTRA EL LISTADO
//DE LAS COORDENADAS EN EL ORDEN DE INGRESO Y EL PROMEDIO DE COORDENADAS X Y Z 
using namespace std;
void li(){ //Declaracion de una funcion, no retorna ni recibe nada.
	system ("cls");//La declaracion anterior es para esta funcion de limpiado de pantalla
}
void pa(){//Declaracion de una funcion, no retorna ni recibe nada.
	system ("pause");//La declaracion anterior es para esta funcion de mantener la pantalla pausada
}
struct coordenadas{
	float x;
	float y;
	float z;
};
void menuu()//Aca empieza el menu
	{
		cout << "|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|"<<endl;
		cout << "|                M    E     N     U                         |"<<endl;
		cout << "|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|"<<endl;
		cout << "|  1) AGREGAR ELEMENTOS                                     |"<<endl;
		cout << "|...........................................................|"<<endl;
		cout << "|  2) MOSTRAR COLA                                          |"<<endl;
		cout << "|...........................................................|"<<endl;
		cout << "|  3) MOSTRAR PROMEDIO                                      |"<<endl;
		cout << "|...........................................................|"<<endl;
		cout << "|  4) SALIR                                                 |"<<endl;
		cout << "|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|"<<endl;
		cout << ". Ingrese lo que desea hacer:                               ."<<endl;
	}



void agregar(coordenadas &aux){
	do{
	cout << "|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|"<<endl;
	cout << "|               INGRESO DE DATOS                            |"<<endl;
	cout << "|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|"<<endl;
	cout << "|INGRESAR DATOS DE X:                                      "; cin >> aux.x;
	}while(aux.x<0); //PARA ASEGURARSE QUE SEA MAYOR A 0
	
	do{
	cout << "|...........................................................|"<<endl;
	cout << "INGRESAR DATOS DE Y                                        "; cin >> aux.y;
	}while(aux.y<0); //PARA ASEGURARSE QUE SEA MAYOR A 0
	
	do{
	cout << "|...........................................................|"<<endl;
	cout << "|INGRESE DATOS DE X                                        "; cin >> aux.z;
	cout << "|...........................................................|"<<endl;
	}while(aux.z<0); //PARA ASEGURARSE QUE SEA MAYOR A 0
}
void mostrar(int q, coordenadas *in){
	int j=1;
	while(q>0){
		cout << "|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|"<<endl;
		cout << "|                       COLAS                               |"<<endl;
		cout << "|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|"<<endl;
		cout << " X COORDENADA"<<j<<" : " << in->x << endl;
		cout << " Y COORDENADA"<<j<<" : " << in->y << endl;
		cout << " Z COORDENADA"<<j<<" : " << in->z << endl;
		cout << "|...........................................................|"<<endl;
		in++; //EL PUNTERO AUMENTA POSICION
		q--; //DISMINUYE CANTIDAD DE ESPACIOS
		j++;
	}
}



void pro(int q, coordenadas *in){
	coordenadas pro;
	int j = 0;
	while(q>0){
		
		pro.x += in->x;
		pro.y += in->y;
		pro.z += in->z;
		in++; //EL PUNTERO AUMENTA POSICION
		q--; //DISMINUYE CANTIDAD DE ESPACIOS
		j++;
	}
	
	pro.x = (pro.x/j);
	pro.y = (pro.y/j);
	pro.z = (pro.z/j);
	cout << "|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|"<<endl;
	cout << "|                 P R O M E D I O S                         |"<<endl;
	cout << "|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|"<<endl;
	cout << "|PROMEDIO DE X:                                            " << pro.x <<endl;
	cout << "|...........................................................|"<<endl;
	cout << "|PROMEDIO DE Y:                                            " << pro.y <<endl;
	cout << "|...........................................................|"<<endl;
	cout << "|PROMEDIO DE Z:                                            "<<  pro.z <<endl;
	cout << "|...........................................................|"<<endl;
}

int main(){
	system ("color f0");//El cambio de color
	queue<coordenadas> cola;
	coordenadas aux;
	coordenadas *in;
	int op;
	int q;
	bool rep = false;
	q = cola.size();
	
	do //El do que ayuda a repetir el menu
	{
	
		menuu();//Acá empieza el void que habia hecho arriba para el menu
		cin>> op;//Datos guardados en la variable de tipo entero
		switch (op)
		{	
	    case 1:
	    pa();
		li();
		agregar(aux);
		cola.push(aux);
		in = &cola.front();
		q = cola.size();
		break;
	case 2:
		pa();
		li();
		mostrar(q,in);
		break;
	case 3:
		pa();
		li();
		pro(q,in);
		break;
	case 4:
		return 0;
	}
	pa();
	li();
	}while(op!=4);
}

