/**
@file bite.h
@author CVR 
@brief Manejo de los bytes , pudiendo modificar cada uno.

*/

#ifndef _BLOQUELED_H_
#define	_BLOQUELED_H_


typedef unsigned char byte; ///< Un @c byte contiene el estado de 8 bits

/**
@brief enciende el bit @p pos del @c byte @p b 
@param b 	el @c byte cuyo bit se quiere activar
@param pos 	el bit dentro de @p b que se quiere activar (0 más a la derecha)
*/

void on(byte &b, int pos);

/**
@brief apaga el bit @p pos del  @c byte @p b  
@param b 	el @c byte cuyo bit se quiere desactivar
@param pos 	el bit dentro de @p b que se quiere desactivar (0 más a la derecha)
*/

void off(byte &b, int pos);

/**
@brief devuelve el estado del bit (encendido = true, apagado = false) en la posición @p pos 
@param b 	el @c byte que se quiere consultar
@param pos 	el bit dentro de @ b que se quiere consultar (0 más a la derecha)
@retval true 	si el bit en la posición @p pos está encendido
@retval false	si el bit en la posición @p pos está apagado
*/

bool get(byte b, int pos);

/**
@brief Muestra por la salida estándar una secuencia de 0s y 1s correspondiente  al estado de cada bit
@param b el @c byte que se quiere imprimir

Muestra por la salida estándar una secuencia de 0s y 1s correspondiente  al estado de cada bit del byte donde un cero representa que un bit está apagado y un uno que el bit está encendido. Se implementa utilizando la función "get".

Por ejemplo, si en el @c byte @c b están encendidos los bits en posiciones 1 y 3 (0 más a la derecha), @c print(b); mostrará @c 00001010

*/

void print(byte b);

/**
@brief enciende todos los bits
@param b el @c byte que se quiere encender completamente. 
*/

void encender(byte &b);

/**
@brief apaga todos los bits
@param b el @c byte que se quiere apagar completamente. 
*/

void apagar(byte &b);

/**
@brief enciende los bits según la configuración de @p v
@param b el @c byte sobre el que se quiere actuar 
@param v vector de 8 elementos que contiene la secuencia de bits que se quieren asignar

Asigna a @p b la configuración de bits contenida en @p v. @p v es un vector de 8 booleanos donde @c true significa encendido y @c false significa apagado.
*/

void asignar(byte &b, const bool v[]);

/**
@brief recupera la configuración de todos los bit
@param b el @c byte que se quiere consultar
@param v vector de 8 elementos que contendrá el estado de cada uno de los bits de @ b

Vuelca en @p v la configuración de bits contenida en @p b. @c true significa encendido y @c false significa apagado. El tamaño de @p v debe ser 8.
*/

void volcar(byte b, bool v[]);

/**
@brief devuelve las posiciones de los bits encendidos
@param b el @c byte que se quiere consultar
@param posic vector de enteros (valores entre 0 a 7) que indican la posición de los bits de @p b que están encendidos
@param cuantos número de bits encendidos en @p b (número de elementos usados en el vector @p posic)
*/

void encendidos(byte b, int posic[], int &cuantos);

#endif	

