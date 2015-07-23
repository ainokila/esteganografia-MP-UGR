#include<iostream>
#include<cstring>
#include"codificar.h"
#include"imagen.h"
#include"byte.h"



bool ocultar(Imagen &imagen, char mensaje[]){

	bool resultado=false;
	bool estado;
	byte actual;
	byte caracter;
	int posicion=0;
	
	/*Comprobacion de que la cadena sea menor que la imagen y 
	   modificación del mensaje */
	
	if(strlen(mensaje)*8<(imagen.columnas() * imagen.filas())){	

	/*Bucle para codificar (seguirá hasta el término de la mensaje) */	
		
		for(int i=0;i<=strlen(mensaje);i++){

			caracter=(mensaje[i]);
			
	/*Representación del valor de cada letra como forma de un byte (se mete 1 bit en la posición menos significade de cada byte de la 		  imagen). */
		
			for(int j=7;j>=0;j--){
				
				actual=imagen.getPos(posicion);
				estado=get(caracter,j);
				
				/* Comprobacción en caso de que no coincidan los valores del byte ,si son distintos se cambian, en caso 				   contrario permacerían igual. */
								
				if( (get(actual,cero)==1) && estado==0 ){

					off(actual,cero);
					imagen.setPos(posicion,actual);
					
					}
					
					else if( (get(actual,cero)==0)&& estado==1 ){
								
								
						on(actual,cero);
						imagen.setPos(posicion,actual);
						
					}
								
				posicion++;		
				
			};
			
						
		};

	resultado=true;

	};

	

return resultado; 

};


bool revelar (Imagen imagen, char mensaje [],const int TAM_MAX){

	//Declaración de las variables 

	int posicion=0;
	bool resultado=false;
	bool fin=false;
	bool valorActual;
	byte caracter;
	
	/*Construcción del mensaje */ 
	
	for(int i=0 ; i<TAM_MAX && !fin && (posicion < imagen.filas()*imagen.columnas() ) ;i++){
		
		/*Apagado de todos los bits de letra , para comprobar los que salen de imagen y encender el que sea 1 */
		
		caracter=0x0;		
		for(int j=7;j>=0;j--){

			valorActual=get(imagen.getPos(posicion),cero);
			posicion++;
			
			if(valorActual)

				on(caracter,j);
		};

	/*Cambio del valor de fin para finalizar el bucle*/

		if (caracter=='\0'){
			
			
			fin=true;
		
		}

		else 
		
			mensaje[i]=caracter;

	};

	if (fin==true){

		resultado=true;}

	return resultado;

}

				
				

























				
				

					
					
					
				
		

