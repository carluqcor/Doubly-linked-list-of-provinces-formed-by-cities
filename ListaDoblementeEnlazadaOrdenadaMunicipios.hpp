/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.hpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
  	\author Carlos Luque Córdoba
  	\date   07/04/2018
	\version 1.0

*/

#ifndef __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
#define __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaOrdenadaMunicipiosInterfaz.hpp"

#include "NodoDoblementeEnlazadoMunicipio.hpp"

#include "Municipio.hpp"

// DEBES ESPECIFICAR LAS FUNCIONES DE LA CLASE ListaDoblementeEnlazadaOrdenadaMunicipios


/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos

*/ 
namespace ed {
 
/*!	
  \class ListaDoblementeEnlazadaOrdenadaMunicipios 
  \brief Definición de la clase ListaDoblementeEnlazadaOrdenadaMunicipios
	  	\n Lista doblemente enlazada de nodos de municipios ordenados alfabéticamente de forma ascendente 
*/
  class ListaDoblementeEnlazadaOrdenadaMunicipios: public ed::ListaOrdenadaMunicipiosInterfaz
  {
	//! \name  Atributos y métodos privados 

	private:
		ed::NodoDoblementeEnlazadoMunicipio *_head;    //!< \brief puntero al primer nodo de la lista
		ed::NodoDoblementeEnlazadoMunicipio *_current; //!< \brief puntero al nodo current de la lista

    //! \name Observadores privados 

	/*!
		\brief  Devuelve el nodo cabeza
		\note   Función inline
        \pre    La lista no está vacía
		\return Variable privada _head
		\sa		isEmpty()
    */
    inline ed::NodoDoblementeEnlazadoMunicipio * getHead() const
	{
		#ifndef NDEBUG
			assert(isEmpty()==false);
		#endif
		return this->_head;
	}

	/*!
		\brief  Devuelve el nodo actual
		\note   Función inline
        \pre    La lista no está vacía
		\return Variable privada _current
		\sa		isEmpty()
    */
	inline ed::NodoDoblementeEnlazadoMunicipio * getCurrent() const
	{
		#ifndef NDEBUG
			assert(isEmpty()==false);
		#endif
		return this->_current;
	}

    //! \name Modificadores privados 
	
	/*!
		\brief  Posiciona en _head el nodo head
		\note   Función inline
        \post   _head==head
    */
	inline void setHead(ed::NodoDoblementeEnlazadoMunicipio *head) 
	{
		this->_head = head;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->_head == head);
		#endif //NDEBUG		
	}

	/*!
		\brief  Posiciona en _current el nodo current
		\note   Función inline
        \post   _current==current
    */
    inline void setCurrent(ed::NodoDoblementeEnlazadoMunicipio *current) 
	{
		this->_current = current;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->_current == current);
		#endif //NDEBUG		
	}


	//! \name  Métodos públicos

	public:

	//! \name Constructores

    /*! 
		\brief Construye una lista vacía
		\note  Función inline
		\post  isEmpty() == true
	*/
	inline ListaDoblementeEnlazadaOrdenadaMunicipios(){
		this->_head=NULL;
		this->_current=NULL;

		#ifndef NDEBUG
			assert(isEmpty() == true);
		#endif
	}
	
  
	//! \name Destructor 

    /*! 
		\brief Destruye una lista liberando la memoria de sus nodos
		\note Función codificada en el fichero cpp
		\post isEmpty() == true
	*/
	~ListaDoblementeEnlazadaOrdenadaMunicipios(){
		removeAll();	
		#ifndef NDEBUG
			assert(isEmpty() == true);
		#endif
    }


	//! \name Observadores públicos  

	/*!
        \brief  Comprueba si la lista está vacía
		\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \note   Función de tipo "const": no puede modificar al objeto actual
        \return true, si la lista está vacía; false, en caso contrario
    */
	inline bool isEmpty() const{
		if(this->_head==NULL)
			return true;
		else
			return false;
	}

	/*!
        \brief  Devuelve el número de elementos o ítems de la lista
		\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \note   Función de tipo "const": no puede modificar al objeto actual
        \return Número entero que representa el número de elementos o ítems de la lista
    */
	int nItems() const;

	/*!
		\brief  Comprueba si el cursor está en el primer Municipio
		\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \note   Función de tipo "const": no puede modificar al objeto actual
		\pre    La lista no está vacía
		\return Verdadero, si el cursor está situado en la cabeza; falso en caso contrario
	*/
	bool isFirstItem() const;

	/*!
		\brief  Comprueba si el cursor está en el último Municipio
		\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \note   Función de tipo "const": no puede modificar al objeto actual
		\pre    La lista no está vacía
		\return true, si el cursor está situado al final de la lista; false, en caso contrario
    */
	bool isLastItem() const;

	/*!
		\brief  Devuelve el Municipio situado en el campo informativo indicado por el cursor
		\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \note   Función de tipo "const": no puede modificar al objeto actual
		\pre    La lista no está vacía
		\return Una referencia constante al municipio indicado por el cursor
    */
	ed::Municipio const &getCurrentItem() const;

	/*!
		\brief  Devuelve el Municipio situado en el campo informativo anterior
		\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \note   Función de tipo "const": no puede modificar al objeto actual
		\pre    La lista no está vacía 
		\pre    El cursor no está situado en el primer nodo
		\return Una referencia al municipio situado en el nodo previo al indicado por el cursor
    */
	ed::Municipio const &getPreviousItem() const;

	/*!
		\brief  Devuelve el Municipio situado en el campo informativo posterior
		\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \note   Función de tipo "const": no puede modificar al objeto actual
		\pre    La lista no está vacía 
		\pre 	El cursor no está situado en el último nodo
        \return Una referencia al municipio situado en el nodo siguiente al indicado por el cursor
    */
	ed::Municipio const &getNextItem() const;

    //! \name Modificadores públicos

	/*!
		\brief  Coloca el cursor en la primera posición de la lista
		\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \pre    La lista no está vacía
        \post   El ítem actual es el primero: isFirstItem() == true
		\return void
		\sa		gotoLast(), gotoPrevious(), gotoNext()
    */
	void gotoHead();

	/*!
		\brief  Coloca el cursor en la última posición de la lista
		\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \pre    La lista no está vacía
        \post   El ítem actual es el último:  isLastItem() == true
		\return void
		\sa		gotoHead(), gotoPrevious(), gotoNext()
    */
	void gotoLast();

	/*!
		\brief  Coloca el cursor en la posición anterior de la lista
		\note   Función virtual pura, que deberá ser redefinida en la clase heredera
		\pre    La lista no está vacía
		\pre    El ítem actual no es el primero: isFirstItem() == false
		\post   Ninguna
		\return void
		\sa		gotoHead(), gotoLast(), gotoNext()
    */
	void gotoPrevious();

	/*!
		\brief  Coloca el cursor en la posición siguiente de la lista
        \pre    La lista no está vacía
        \pre    El ítem actual no es el último: isLastItem() == false
		\post   Ninguna
		\return void
		\sa		gotoHead(), gotoLast(), gotoPrevious()
	*/
	void gotoNext();

	/*!
		\brief  Coloca el cursor en el nodo que contiene al municipio en su campo informativo, si existe;
		\param  municipio: municipio buscado; referencia constante de la clase Municipio
 		\post   retVal==true implica que getCurrentItem() == municipio
   		\post   retVal==false implica que getCurrentItem > municipio o isLastItem() == true
		\return true, si el municipio está en la lista; false, en caso contrario
    */
	bool find(ed::Municipio const &municipio);

	/*!
		\brief Inserta un Municipio de forma ordenada por apellidos y nombre
		\param municipio: objeto de la clase Municipio que va a ser insertado; referencia constante de la clase Municipio
		\pre   find(municipio) == false
 		\post  getCurrentItem() == municipio
		\sa    remove() 
    */
	void insert(ed::Municipio const &municipio);
	
	/*!
		\brief Borra el municipio indicado por el cursor
		\pre   La lista no está vacía: isEmpty()== false
		\post  El número de municipios se reduce en uno
        \n 	   nItems()==old.nItems()-1
    	\post  Si old.isFirstItem()==falso y  old.isLastItem()==falso entonces old.getPreviousItem()== getPreviousItem() y old.getNextItem()==getCurrentItem()
		\post  Si old.lastItem()==verdadero entonces isEmpty()==verdadero o old.getPreviousItem()==getCurrentItem() y isLastItem()==verdadero
	    \post  Si old.isFirstItem()==verdadero entonces isEmpty()==verdadero o old.getNextItem()==getCurrentItem() y isFirstItem()==verdadero
		\sa    insert()
    */
	void remove();
	/*! 
		\fn        void removeAll()
		\brief     Función que borra todos los elementos de la lista
		\note      Función void
		\pre       Ninguna
		\post      isEmpty==true
		\sa        remove(), isEmpty(), gotoHead
	*/
	void removeAll();

}; // Fin de la clase ListaDoblementeEnlazadaOrdenadaMunicipios
 
} //namespace ed
 
#endif // __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
