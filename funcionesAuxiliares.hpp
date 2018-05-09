/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 2
  \author Carlos Luque Córdoba
  \date   07/04/2018
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Provincia.hpp"


// SE DEBEN INCLUIR LOS COMENTARIOS DE DOXYGEN DE CADA FUNCIÓN

namespace ed
{

	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
  int menu();

	///////////////////////////////////////////////////////////////////

	/*!		\fn 	   void comprobarProvinciaVacia(Provincia & provincia)
			\brief     Función que cumprueba si una provincia está vacía    
			\note      Función void
			\param     provincia: Objeto de tipo Provincia pasado como referencia  
			\sa        hayMunicipios()
	*/
	void comprobarProvinciaVacia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*!		\fn 	   void cargarProvincia(Provincia & provincia)
			\brief     Función que carga el fichero que contiene los municipios de una provincia   
			\note      Función void
			\param     provincia: Objeto de tipo Provincia pasado como referencia  
			\sa        cargarFichero(std::string)
	*/
	void cargarProvincia(ed::Provincia & provincia);

	/*!		\fn 	   void grabarProvincia(Provincia & provincia)
			\brief     Función que graba el fichero que contiene los municipios de una provincia   
			\note      Función void
			\param     provincia: Objeto de tipo Provincia pasado como referencia  
			\sa        grabarFichero(std::string)
	*/
	void grabarProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*!		\fn 	   void consultarDatosDeProvincia(Provincia & provincia)
			\brief     Función que imprime por pantalla los datos de una provincia
			\note      Función void
			\param     provincia: Objeto de tipo Provincia pasado como referencia  
			\sa        hayMunicipios(), getNombre(), getCodigo(), getTotalHombres(), getTotalMujeres() y getTotalHabitantes
	*/
	void consultarDatosDeProvincia(ed::Provincia & provincia);

	/*!		\fn 	   void mostrarMunicipiosDeProvincia(Provincia & provincia)
			\brief     Función que muestra por pantalla los municipios de la provincia actual
			\note      Función void
			\param     provincia: Objeto de tipo Provincia pasado como referencia  
			\sa        escribirMunicipios()
	*/
	void mostrarMunicipiosDeProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*!		\fn 	   void modificarDatosDeProvincia(Provincia & provincia)
			\brief     Función que permite al usuario modificar los datos de la provincia actual
			\note      Función void
			\param     provincia: Objeto de tipo Provincia pasado como referencia  
			\sa        getNombre(), getCodigo(), setNombre() y setCodigo()
	*/
	void modificarDatosDeProvincia(ed::Provincia & provincia);

	/*!		\fn 	   void borrarTodosLosMunicipiosDeProvincia(Provincia & provincia)
			\brief     Función que borra todos los elementos de una provincia
			\note      Función void
			\param     provincia: Objeto de tipo Provincia pasado como referencia  
			\sa        escribirMunicipios() y borrarTodosLosMunicipios()
	*/
	void borrarTodosLosMunicipiosDeProvincia(ed::Provincia & provincia);


	///////////////////////////////////////////////////////////////////

	/*!		\fn 	   void consultarMunicipioDeProvincia(Provincia & provincia)
			\brief     Función que muestra los datos del municipio, en el caso de que exista
			\note      Función void
			\param     provincia: Objeto de tipo Provincia pasado como referencia  
			\sa        existeMunicipio(), getMunicipio(std::string) y escribirMunicipio()
	*/
	void consultarMunicipioDeProvincia(ed::Provincia & provincia);

	/*!		\fn 	   void insertarMunicipioEnProvincia(Provincia & provincia)
			\brief     Función que inserta el municipio pasado como referencia
			\note      Función void
			\param     provincia: Objeto de tipo Provincia pasado como referencia  
			\sa        escribirMunicipios(), leerMunicipio(), insertarMunicipio(), existeMunicipio() y getNombre()
	*/
	void insertarMunicipioEnProvincia(ed::Provincia & provincia);

	/*!		\fn 	   void borrarMunicipioDeProvincia(Provincia & provincia)
			\brief     Función que borra el elemento pasado como referencia
			\note      Función void
			\param     provincia: Objeto de tipo Provincia pasado como referencia  
			\sa        escribirMunicipios(), leerMunicipio(), insertarMunicipio(), existeMunicipio() y getNombre()
	*/
	void borrarMunicipioDeProvincia(ed::Provincia & provincia);

	/*!		\fn 	   void compararMunicipios(Provincia & provincia)
			\brief     Función que compara dos municipios pedidos al usuario por terminal
			\note      Función void
			\param     provincia: Objeto de tipo Provincia pasado como referencia  
			\sa        getMunicipio(std::string cad) y getHabitantes()
	*/
	void compararMunicipios(ed::Provincia & provincia);

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

