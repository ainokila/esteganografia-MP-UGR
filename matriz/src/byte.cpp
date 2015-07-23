#include <iostream>
#include "byte.h"

using namespace std;

void on(byte &b, int pos){   
   
//Comprobación de que la posición es la correcta

	if(pos >= 0 && pos < 8){

	//Creación de la mascara, esta debe estar acorde con la posión a encender

		byte mask= 0x1 <<pos;   
	
   	//Modificacion de "b" según "mask"
		b=b|mask;
	}

//Mensaje de error en caso de que la posición sea incorrecta
	else 
		cout<<"\nPosicion incorrecta.";
}

void off(byte &b, int pos){

//Comprobación de que la posición es la correcta

	if(pos >= 0 && pos < 8){

	/*Creación de la máscara en concordancia con la posión a apagar
	y modificación de "b"*/

		byte mask = 0x1 << pos;
		mask= ~mask;
		b = b&mask;
	}

else 

//Mensaje de error en caso de introducir una posición incorrecta

	cout << "Mensaje de error: posición incorrecta.";
}

bool get(byte b, int pos){

//Variable de tipo buleano para determinar el estado del LED (encendido o apagado)

	bool estado;

	//Creación de la máscara y comprobación de los resultados.

	byte mask= 0x1 << pos;
	
	if ((b&mask) > 0)
		estado = true;
		
	else 
	   estado=false;

return estado;

}

void print(byte b){

//Comprobación de las posición del byte e impresión.

	for(int i=7; i >=0; i--){
		cout << get(b,i);		
	}

cout << endl;
}

void encender(byte &b){

/* Comprobación de si las posición es 0 o 1 en "b". En el primer caso,
 haciendo uso del método "on" cambiamos el 0 a 1 */

	for(int i=0; i < 8; i++){
	
		if( get(b,i) == false )

			on(b,i);
	}
}
			
void apagar(byte &b){

//Caso contrario al anterior (uso del método "off")

	for(int i=0; i < 8; i++){
	
		if( get(b,i) == true )

			off(b,i);
	}
}

void asignar(byte &b, const bool v[]){

/* Comprobación de que secuencia de bits esta contenida en el vector v[]
  y en función de ello encendido de bloqueled. */

	for(int i=0; i < 8; i++){

		if(v[i] == 1)
		
			on(b,i);
		
		else if(v[i] == 0)
		
			off(b,i);

	}
}	

void volcar(byte b, bool v[]){

/* Comprobación del estado del LED en todas las posiciones e
introducción de la secuencia de LEDS en el vector v[]. */

	for(int i=0; i < 8; i++)
		
		v[i]=get(b,i);
		
}

void encendidos(byte b, int posic[], int &cuantos){
   /* Mediante el método "get" se procede a contar cuantos LEDS
	están encendido y se determina su posición. */
   
   //Declaración de una variable para las posiciones del vector.
   
   int j=0;
   
   for(int i=0; i < 8; i++){
    
   //Comprobación de si está encendido o no.
     
      if(get(b,i)==1){
         
         posic[j]=i;
         cuantos++;
         j++;
      }
   }
}

   
  
	



