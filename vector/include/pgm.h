/**
  * @file 
  * @brief Fichero cabecera para la E/S de imágenes PGM 
  *
  * Permite la E/S de archivos de tipos PGM
  *
  */
  
#ifndef _PGM_H_
#define _PGM_H_
  
/**
  * @brief Tipo de imagen
  *
  * Declara una serie de constantes para representar los distintos tipos
  * de imágenes que se pueden manejar.
  *
  * @see LeerTipoImagen
  */

enum TipoImagen {
  IMG_DESCONOCIDO,	///< Tipo de imagen desconocido
  IMG_PGM_BINARIO,	///< Imagen tipo PGM Binario
  IMG_PGM_TEXTO		///< Imagen tipo PGM Texto
};


/**
  * @brief Consulta el tipo de imagen del archivo y sus dimensiones
  *
  * @param nombre indica el nombre del archivo de disco a consultar
  * @param filas Parámetro de salida con las filas de la imagen.
  * @param columnas Parámetro de salida con las columnas de la imagen.
  * @return Devuelve el tipo de la imagen en el archivo 
  *
  * @see TipoImagen
  */

TipoImagen infoPGM(const char nombre[], int& filas, int& columnas);


/**
  * @brief Lee una imagen de tipo PGM binario
  *
  * @param nombre 	nombre del archivo a leer
  * @param filas 	Parámetro de salida con las filas de la imagen.
  * @param columnas Parámetro de salida con las columnas de la imagen.
  * @param datos 	vector para obtener el valor de cada uno de los píxeles
  *        desde la esquina superior izqda a la inferior dcha. 
  * @retval true 	si ha tenido éxito en la lectura.
  * @retval false 	si se ha producido algún error en la lectura.
  * @pre datos 		debe tener tamaño suficiente para almacenar
  *      @a filas x @a columnas bytes de datos de la imagen.
  */

bool leerPGMBinario (const char nombre[], unsigned char datos[], int& filas, int& columnas);

/**
  * @brief Escribe una imagen de tipo PGM binario
  *
  * @param nombre 	nombre del archivo a escribir
  * @param datos 	vector con @a filas x @a columnas bytes que corresponden
  *       a los valores de los píxeles de la imagen de grises.
  * @param filas 	número de filas de la imagen
  * @param columnas	número de columnas de la imagen
  * @retval true 	si ha tenido éxito en la escritura.
  * @retval false 	si se ha producido algún error en la escritura.
  */

bool escribirPGMBinario (const char nombre[], const unsigned char datos[], int filas, int columnas);
/**
  * @brief Lee una imagen de tipo PGM Texto
  *
  * @param nombre 	nombre del archivo a leer
  * @param filas 	Parámetro de salida con las filas de la imagen.
  * @param columnas Parámetro de salida con las columnas de la imagen.
  * @param datos 	vector para obtener el valor de cada uno de los píxeles
  *        desde la esquina superior izqda a la inferior dcha. 
  * @retval true 	si ha tenido éxito en la lectura.
  * @retval false 	si se ha producido algún error en la lectura.
  * @pre datos 		debe tener tamaño suficiente para almacenar
  *      @a filas x @a columnas bytes de datos de la imagen.
  */

bool leerPGMTexto (const char nombre[], unsigned char datos[], int& filas, int& columnas);


/**
  * @brief Escribe una imagen de tipo PGM Texto
  *
  * @param nombre 	nombre del archivo a escribir
  * @param datos 	vector con @a filas x @a columnas bytes que corresponden
  *       a los valores de los píxeles de la imagen de grises.
  * @param filas 	número de filas de la imagen
  * @param columnas	número de columnas de la imagen
  * @retval true 	si ha tenido éxito en la escritura.
  * @retval false 	si se ha producido algún error en la escritura.
  */

bool escribirPGMTexto (const char nombre[], const unsigned char datos[], int filas, int columnas);


#endif

