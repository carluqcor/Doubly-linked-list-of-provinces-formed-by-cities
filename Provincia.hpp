/*!	
	\file  Provincia.hpp
	\brief Definición de la clase Provincia
	\author Carlos Luque Córdoba
	\date  07/04/2018
	\version 1.0

*/

#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

// Para comprobar las pre y post condiciones
#include <cassert>

#include <string>


#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"


/*!	
	\namespace ed
	\brief Espacio de nombres para la Provincia Estructuras de Datos

*/
namespace ed{
/*!	

  \class Provincia
  \brief Definición de la clase Provincia

*/
class Provincia
{
	//!	\name Métodos públicos de la clase Provincia

	private:
		std::string _nombre;     //!<  \brief Nombre de la Provincia
		int _codigo;	  //!<  \brief Código de la Provincia

	  	ed::ListaDoblementeEnlazadaOrdenadaMunicipios _listaMunicipios; //!<  \brief Lista de municipios de la Provincia


	/////////////////////////////////////////////////////////////////////

	//!	\name  Métodos públicos de la clase Provincia

  public: 

	//!	\name Constructor
	/*! 
			\brief     Constructor que crea una Provincia(std::string nombre, int codigo)
			\attention Constructor con 2 argumentos      
			\note      Función inline
			\param	   nombre: Nombre de la Provincia
			\param 	   codigo: Código de la Provincia
		 	\warning   Los parámetros tienen valores por defecto
			\pre       Ninguna
			\post      (getNombre()==nombre and getCodigo()==codigo and hayMunicipios()==false)
			\sa        getNombre(), getCodigo(), hayMunicipios()
	*/
	inline Provincia(std::string nombre="", int codigo=0){
		_nombre=nombre;
		_codigo=codigo;
		#ifndef NDEBUG
			assert(getNombre()==nombre and getCodigo()==codigo and hayMunicipios()==false);
		#endif
  	}


	/////////////////////////////////////////////////////////////////////

	//!	\name Observadores
	/*! 
			\fn        string getNombre()
			\brief     Función que devuelve el nombre de la Provincia
			\note      Función inline
			\return    Nombre de la provincia
			\pre       Ninguna
			\post	   Ninguna
	*/
	inline std::string getNombre(){return _nombre;}
	
	/*! 
			\fn        int getCodigo()
			\brief     Función que devuelve el código de la Provincia
			\note      Función inline
			\return    Código de la provincia
			\pre       Ninguna
			\post	   Ninguna
	*/
	inline int getCodigo(){return _codigo;}

	/*! 
			\fn        bool hayMunicipios()
			\brief     Función que determina si hay municipios en la Provincia o no
			\note      Función bool
			\return    True si hay más de 1 municipio y false si no hay ninguno
			\pre       Ninguna
			\post	   Ninguna
			\sa        isEmpty()
	*/
	bool hayMunicipios();

	/*! 
			\fn        int getNumeroMunicipios()
			\brief     Función que determina el numero de municipios que tiene una Provincia
			\note      Función int			
			\return    Número de municipios en la Provincia
			\pre       Ninguna
			\post	   Ninguna
			\sa        nItems()
	*/
	int getNumeroMunicipios();

	/*! 
			\fn        bool existeMunicipio(std::string)
			\brief     Función que comprueba si un municipio existe
			\note      Función bool
			\param     cad: Nombre del municipio a buscar
			\return    True si existe el municipio y false si no existe
			\pre       Ninguna
			\post	   Ninguna
			\sa        setNombre(std::string) y find(Municipio)
	*/
	bool existeMunicipio(std::string cad);

	/*! 
			\fn        Municipio getMunicipio(std::string)
			\brief     Función que devuelve el municipio con el nombre de la cadena pasada como referencia
			\note      Función Municipio
			\param     cad: Nombre del municipio a devolver
			\return    Municipio con el nombre pasado por referencia
			\pre       existeMunicipio(std::string)==true
			\post	   Ninguna
			\sa        existeMunicipio(std::string), setNombre(std::string), getCurrentItem() y find(Municipio)
	*/
	ed::Municipio getMunicipio(std::string cad);

	/*! 
			\fn        int getTotalHombres()
			\brief     Función que devuelve el total de hombres de la provincia (suma de los hombres de todos los municipios)
			\note      Función int
			\return    Número total de hombres de la provincia
			\pre       Ninguna
			\post	   Ninguna
			\sa        getCurrentItem(), gotoHead(), isLastItem(), getHombres(), gotoNext()
	*/
	int getTotalHombres();

	/*! 
			\fn        int getTotalMujeres()
			\brief     Función que devuelve el total de mujeres de la provincia (suma de las mujeres de todos los municipios)
			\note      Función int
			\return    Número total de mujeres de la provincia
			\pre       Ninguna
			\post	   Ninguna
			\sa        getCurrentItem(), gotoHead(), isLastItem(), getMujeres(), gotoNext()
	*/
	int getTotalMujeres();

	/*! 
			\fn        int getTotalHombres()
			\brief     Función que devuelve el total de hombres y mujeres de la provincia (suma de los hombres y mujeres de todos los municipios)
			\note      Función inline
			\return    Número total de hombres y mujeres de la provincia
			\pre       Ninguna
			\post	   valorDevuelto==getTotalHombres()+getTotalMujeres()
			\sa        getTotalHombres() y getTotalMujeres()
	*/
	inline int getTotalHabitantes(){
		int total=(getTotalHombres()+getTotalMujeres());
		return total;
		#ifndef NDEBUG
			assert(total==getTotalHombres()+getTotalMujeres());
		#endif
	}
	
	/////////////////////////////////////////////////////////////////////

	//!	\name Modificadores
	/*! 
			\fn        void setNombre(std::string cad)
			\brief     Función que reajusta el nombre de la provincia por el nombre pasado como referencia
			\note      Función inline
			\param     cad: Nombre de la provincia
			\pre       Ninguna
			\post	   getNombre()==cad
			\sa        getNombre()
	*/
	inline void setNombre(std::string cad){
		_nombre=cad;
		#ifndef NDEBUG
			assert(getNombre()==cad);
		#endif
	}
	/*! 
			\fn        void setCodigo(int cod)
			\brief     Función que reajusta el código de la provincia por el codigo pasado como referencia
			\note      Función inline
			\param     cod: Código de la provincia
			\pre       Ninguna
			\post	   getCodigo()==cad
			\sa        getCodigo()
	*/
	inline void setCodigo(int cod){
		_codigo=cod;
		#ifndef NDEBUG
			assert(getCodigo()==cod);
		#endif
	}

	/*! 
			\fn        void insertarMunicipio(Municipio municipio)
			\brief     Función que inserta el municipio pasado como referencia      
			\note      Función void
			\param	   municipio: Objeto de tipo Municipio que servirá para insertar en la lista
			\pre       existeMunicipio((municipio.getNombre()))==false
			\post      existeMunicipio(municipio.getNombre())==true y getNumeroMunicipios()==(old.getNumeroMunicipios+1)
			\sa        existeMunicipio(municipio.getNombre()), getNumeroMunicipios() y getNombre()
	*/
	void insertarMunicipio(Municipio municipio);

	/*! 
			\fn        void borrarMunicipio(std::string cad)
			\brief     Función que borra el elemento pasado como referencia 
			\note      Función void
			\param	   cad: Cadena de tipo string para saber el nombre del municipio a eliminar
			\pre       existeMunicipio(cad)==true
			\post      existeMunicipio(cad))==false y getNumeroMunicipios()==(old.getNumeroMunicipios-1)
			\sa        existeMunicipio(cad)), getNumeroMunicipios(), getNombre(), gotoHead(), getMunicipio(cad), find(municipìo) y remove()
	*/
	void borrarMunicipio(std::string cad);

	/*! 
			\fn        void borrarTodosLosMunicipios()
			\brief     Función que borra todos los elementos de la lista
			\note      Función void
			\pre       Ninguna
			\post      hayMunicipios()==false
			\sa        isEmpty(), removeAll() y hayMunicipios()
	*/

	void borrarTodosLosMunicipios();


	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia
	/*! 
			\fn        void escribirMunicipios()
			\brief     Función que muestra por pantalla los municipios de la Provincia actual
			\note      Función void
			\pre       Ninguna
			\post      Ninguna
			\sa        isEmpty(), gotoHead(), getNumeroMunicipios(), getCurrentItem(), getCodigoPostal(), getNombre(), getHombres(), getMujeres(), isLastItem() y gotoNext()
	*/
	void escribirMunicipios();

	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros
	/*! 
			\fn        bool cargarFichero(std::string cad)
			\brief     Función que carga el fichero con los municipios de la provincia del fichero
			\note      Función bool
			\param     cad: Cadena de tipo string para conocer el nombre de fichero
			\warning   Se borran todos los municipios primero, ya que si no se recopiarian los municipios
			\return    True si la funcion is_open() devuelve true y por lo tanto se ha cargado correctamente el fichero, si no devuelve false.
			\pre       Ninguna
			\post      Ninguna
			\sa        borrarTodosLosMunicipios(), setCodigo(), setNombre() y insertarMunicipio()
	*/
	bool cargarFichero(std::string cad);

	/*! 
			\fn        bool grabarFichero(std::string cad)
			\brief     Función que graba el fichero con los municipios de la provincia
			\note      Función bool
			\param     cad: Cadena de tipo string para conocer el nombre de fichero
			\return    True si la funcion is_open() devuelve true y por lo tanto se ha grabado correctamente el fichero, si no devuelve false.		
			\pre       Ninguna
			\post      Ninguna
			\sa        getCodigo(), getNombre(), gotoHead(), isLastItem(), getCurrentItem() y gotoNext()
	*/
	bool grabarFichero(std::string cad);

}; //Fin de la clase  Provincia


} // Fin del espacio de nombres ed

#endif // _PROVINCIA_HPP_
