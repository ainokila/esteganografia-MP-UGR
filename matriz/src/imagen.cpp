#include "imagen.h"
#include "pgm.h"
#include "pgm.cpp"
#include <iostream>
#include <fstream>
using namespace std ;


/// Construye una imagen vacía (0 filas, 0 columnas)
   	Imagen::Imagen(){
																																																																																																																																																																																																																																												
		nfilas=0;
		ncolumnas=0;
		datos = NULL;
	}	
   
// Constructor de copia

	void Imagen::copia(Imagen & imagen){
		if(datos==NULL)
			destruir();
		nfilas = imagen.filas();
		ncolumnas = imagen.columnas();
		datos = new byte*[nfilas];
		datos[0]=new byte[nfilas*ncolumnas];
		for (int i=1; i < nfilas; i++){
			datos[i] = datos[i-1] + ncolumnas;
		} 
		for(int i=0;i<nfilas;i++)
			for(int j=0;j<ncolumnas;j++)
				datos[i][j]=imagen.get(i,j);
	}

	Imagen::Imagen(Imagen & imagen){
		copia(imagen);
	}
	


/**
@brief Construye una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen

Construye una imagen de tamaño @a filas x @a columnas y pone todos 
sus elementos a 0.
*/

   	Imagen::Imagen(int filas, int columnas){
		nfilas=filas;
		ncolumnas=columnas;
		datos = new byte *[filas];
		datos[0]= new byte[nfilas*ncolumnas];
		for (int i=1; i < nfilas; i++){
			datos[i] = datos[i-1] + ncolumnas; 
		}
	}
   

/**
@brief Sobrecarga del operador igual para la asignacion entre clases de Imagen
@param Imagen
Copia a la clase de una imagen a otra imagen. 
*/


	Imagen & Imagen::operator=(const Imagen &rhs ) {
	
		if(this!=&rhs ) {

			//destruir();
			nfilas=rhs.nfilas;
			ncolumnas=rhs.ncolumnas;
			crear(nfilas,ncolumnas);

			for(int i = 0 ; i <nfilas ; i++ ) {

				for(int j = 0 ; j<ncolumnas; j++ ){
					//set(i,j,rhs.get(i,j));
					datos[i][j]=rhs.datos[i][j];
				
				}

			}

		}



	return (*this);

	}

/**
@brief Crea una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen

Dimensiona la imagen a tamaño @a filas x @a columnas y pone todos 
sus elementos a 0.
*/

  	void Imagen::crear(int filas, int columnas){

		nfilas=filas;
		ncolumnas=columnas;
		datos = new byte *[filas];
		datos[0]= new byte[nfilas*ncolumnas];

		for (int i=1; i < nfilas; i++){
			datos[i] = datos[i-1] + ncolumnas; 
		}
		//Bucle para recorrer el vector.

		for(int i = 0; i < nfilas; i++){
			for ( int j = 0; j < ncolumnas; j++){
 				datos[i][j] = 0;
			}
		}
	}
 
/**
@brief Destruye los datos y la memoria dinamica.

Liberamos la memoria dinamica.
*/

	void Imagen::destruir(){
		if (datos != NULL){
			nfilas=ncolumnas=0;
			delete [] datos [0];
			delete [] datos;
		}
	}
     	Imagen::~Imagen(){
		destruir();
	}
     
   
/**
@brief Devuelve el número de filas de las imagen
@return el número de filas de la imagen
*/

   	int Imagen::filas(){
		return nfilas;
	}

   
/**
@brief Devuelve el número de columnas de las imagen
@return el número de columnas de la imagen
*/

   	int Imagen::columnas(){
		return ncolumnas;
	}
   

/**
@brief Asigna el valor @a v a la posición (@a x,@a y) de la imagen
@param y 	fila de la imagen
@param x 	columna de la imagen 
@param v 	valor a asignar

Asigna el valor @a v a la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x 
del vector.    
*/

   	void Imagen::set(int y, int x, byte v){
		
		datos[y][x]=v;

	} 
   
   
/**
@brief Devuelve el valor de la posición (@a x,@a y) de la imagen
@param y	 fila de la imagen
@param x	 columna de la imagen 
@return el valor de la posición (@a x,@a y) de la imagen

Devuelve el valor de la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x 
del vector.    
*/

   	byte Imagen::get(int y, int x){
		return datos[y][x];
	} 
   
   
/**
@brief Asigna el valor @a v a la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector
@param v 	valor a asignar

Asigna el valor @a v a la posición @a i de la imagen considerada como vector. La posición @a i 
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la 
fila y @c x representa la columna.    
*/

   	void Imagen::setPos(int i, byte v){

		if(columnas()*filas() > i ) {
			int fila=i/ncolumnas;
			int columna=i-ncolumnas*fila;
			datos[fila][columna]=v;
			
		}
	}
   
 
/**
@brief Devuelve el valor de la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector

Devuelve el valor de la posición @a i de la imagen considerada como vector. La posición @a i 
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la 
fila y @c x representa la columna.    
*/

   	byte Imagen::getPos(int i){

		if(columnas()*filas() > i ) {
			int fila=i/ncolumnas;
			int columna=i-ncolumnas*fila;
			return datos[fila][columna];			
		}
		return -1;
	}

   
/**
@brief Carga una imagen desde un fichero 
@param nombreFichero nombre del fichero que contiene la imagen
@retval true 	si ha tenido éxito en la lectura
@retval false 	si se ha producido algún error en la lectura

Lee desde disco los datos de la imagen llamada @a nombreFichero y la guarda en la memoria. La función debe asegurarse de que la imagen es de un tipo de imagen conocido y de que su tamaño es menor del tamaño máximo permitido (@c MAXDATOS)
*/

   	bool Imagen::leerImagen(const char nombreFichero[]){

		int filas, columnas;
		

		if(infoPGM(nombreFichero, filas, columnas) == IMG_PGM_BINARIO){
			
			crear(filas, columnas);

				return leerPGMBinario(nombreFichero, datos[0],nfilas,ncolumnas);
			
			
		  }else if(infoPGM(nombreFichero, filas, columnas) == IMG_PGM_TEXTO){
			
			crear(filas, columnas);
				
				return leerPGMTexto(nombreFichero, datos[0],nfilas,ncolumnas);
			
		     	
                  }else {

			cerr << "ERROR EN TIPO DE ARCHIVO" << endl ;
			return false;
		}
		    


		    
	
	}
   

/**
@brief Guarda una imagen desde un fichero 
@param nombreFichero nombre del fichero que contiene la imagen
@retval true 	si ha tenido éxito en la escritura
@retval false 	si se ha producido algún error en la escritura
*/

   	bool Imagen::escribirImagen(const char nombreFichero[]){

		
		bool exito = false; 


			cout << "Se escribira un archivo de Texto"<< endl;
			exito=escribirPGMTexto (nombreFichero, datos[0],nfilas,ncolumnas);
			
		return exito;
	}


/**
@brief Rota la imagen 90 grados a la derecha, es un metodo auxiliar
*/
	void Imagen::girarnoventa(){
		
		Imagen aux(ncolumnas,nfilas);		
		for( int i = 0 ; i < ncolumnas ; i++ ) {
			for ( int j = 0 ; j < nfilas ; j++ ){
				aux.set(i,j,get(j,i));
			}

		}
	
		copia(aux);
		
	}


/**
@brief Rota la imagen n grados o en sentido horario o en sentido antihorario.
@param grados numero de grados que deseemos girar la imagen.
@param sentidoHorario , si es true se girara en sentigo horario , sino en sentido antihorario.
*/

	bool Imagen::rotacion(int grados, bool sentidoHorario){

		
		
		if(grados==90 || grados==180 || grados==270 ){

			int veces ;

			if (!sentidoHorario){
				grados= 360-grados;
			}
			
			veces = grados/90;
			
			for ( int i = 0 ; i < veces ; i++ ){	
				girarnoventa();
			}

		return true ;

		}else{
			return false ;
		}

	}

	


// Métodos para la realización del bloque 4

	Imagen Imagen::operator+( Imagen &imagen){

		int filas, columnas;

		if( nfilas > imagen.filas())
			filas = nfilas;
		else
			filas = imagen.filas();
		columnas = ncolumnas + imagen.columnas();
		
		Imagen resultado(filas,columnas);
		
		

		for (int i = 0; i < nfilas; i++){
			for( int j = 0; j < ncolumnas; j++){
				resultado.datos[i][j] = datos[i][j];
				
			}
		}
		
		for (int i = 0; i < imagen.filas(); i++){
			for ( int j = 0; j < imagen.columnas(); j++){
				resultado.datos[i][j+ncolumnas] = imagen.datos[i][j];
				
			}
		}
		
		return resultado;
	}

