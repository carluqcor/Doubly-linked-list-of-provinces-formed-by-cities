/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
  	\author Carlos Luque Córdoba
  	\date   07/04/2018 
	\version 1.0
*/

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "NodoMunicipioInterfaz.hpp"
#include "Municipio.hpp"


	//! \name Observadores públicos 

	int ed::ListaDoblementeEnlazadaOrdenadaMunicipios::nItems() const {
		int i=0;
		if(!isEmpty()){
			ed::NodoDoblementeEnlazadoMunicipio *nuevo = this->getHead();
			while(nuevo->getNext() != NULL){
				i++;
				nuevo=nuevo->getNext();
			}
			i++;
		}
		return i;
	}

	bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::isFirstItem() const {
		#ifndef NDBUG
			assert(isEmpty()==false);
		#endif

		if(getCurrent()==getHead())
			return true;
		else
			return false;
	}

	bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::isLastItem() const {
		#ifndef NDBUG
			assert(isEmpty() == false);
		#endif
		if(this->getCurrent()->getNext() == NULL)
			return true;
		else
			return false;
	}

	ed::Municipio const &ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getCurrentItem() const {
		#ifndef NDBUG
			assert(isEmpty()==false);
		#endif
		
		return (this->getCurrent()->getItem());
	}

	ed::Municipio const &ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getPreviousItem() const {
		#ifndef NDBUG
			assert(isEmpty()==false);
			assert(isFirstItem()==false);
		#endif
		
		return (this->getCurrent()->getPrevious()->getItem());
	}

	ed::Municipio const &ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getNextItem() const {
			#ifndef NDBUG
			assert(isEmpty()==false);
			assert(isLastItem()==false);
		#endif
		
		return (this->getCurrent()->getNext()->getItem());
	}

    //! \name Modificadores públicos

	void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoHead(){
		#ifndef NDBUG
			assert(isEmpty()==false);
		#endif
		
		setCurrent(getHead());

		#ifndef NDBUG
			assert(isFirstItem()==true);
		#endif
	}

	void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoLast(){
		#ifndef NDBUG
			assert(isEmpty()==false);
		#endif

			while(! isLastItem())
				gotoNext();
		#ifndef NDBUG
			assert(isLastItem()==true);
		#endif
	}

	void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoPrevious(){
		#ifndef NDBUG
			assert(isEmpty()==false);
			assert(isFirstItem()==false);
		#endif
			setCurrent(getCurrent()->getPrevious());
	}


	void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoNext(){
		#ifndef NDBUG
			assert(isEmpty()==false);
			assert(isLastItem()==false);
		#endif

		setCurrent(getCurrent()->getNext());
	}

	bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::find(ed::Municipio const &municipio){
		bool val=false;
		if(isEmpty()==true){
			val=false;
			return val;
		}else{
			gotoHead();
			while(isLastItem() == false){
				if((getCurrentItem() == municipio)==true){
					val=true;

					#ifndef NDBUG
						if(val)
							assert(getCurrentItem()==municipio);
					#endif
						return val;
				}
				else
					gotoNext();
			}
			if(nItems()>1){
				if(isLastItem() && (getCurrentItem() == municipio)==true){
					val=true;
					#ifndef NDBUG
						if(val)
							assert(getCurrentItem()==municipio);
					#endif
					return val;
				}
			}

			if(!val){
				gotoHead();
				while(((this->getCurrentItem()==municipio)==false) && (this->getCurrentItem()<municipio) && (isLastItem()!=true)){
					gotoNext();
				}
			}
		}

		if(getCurrentItem()==municipio)
			val=true;

		#ifndef NDBUG
			if(isEmpty()==false){
				if(!val) 
					assert((municipio < getCurrentItem())==true || isLastItem()==true);
			}
		#endif
		return val;
	}
	
	void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::insert(ed::Municipio const &municipio){
		#ifndef NDBUG
			assert(find(municipio)==false);
		#endif

		ed::NodoDoblementeEnlazadoMunicipio *nuevo = new ed::NodoDoblementeEnlazadoMunicipio(municipio, NULL, NULL);
		int oldnitems=nItems();
		if(isEmpty()==true){
			setHead(nuevo);
			setCurrent(getHead());
		
		}
		else{
			gotoHead();
			if((this->isFirstItem()) and (this->isLastItem())){
				if(municipio<(this->getHead()->getItem())){
					getHead()->setPrevious(nuevo);
					nuevo->setNext(getHead());
					setHead(nuevo);
					setCurrent(nuevo);	
				}else{
					getHead()->setNext(nuevo);
					nuevo->setPrevious(getHead());
					setCurrent(nuevo);
				}
			}
			else{
				find(municipio);

				if(isLastItem()==false){
					if(municipio<(this->getHead()->getItem())){
					getHead()->setPrevious(nuevo);
					nuevo->setNext(getHead());
					setHead(nuevo);
					setCurrent(nuevo);	
					}else{
						nuevo->setNext(getCurrent());
						nuevo->setPrevious(getCurrent()->getPrevious());
						getCurrent()->getPrevious()->setNext(nuevo);
						getCurrent()->setPrevious(nuevo);
						setCurrent(nuevo);

					}
				}else{
					if(municipio<(this->getCurrentItem())){
						nuevo->setNext(getCurrent());
						nuevo->setPrevious(getCurrent()->getPrevious());
						getCurrent()->getPrevious()->setNext(nuevo);
						getCurrent()->setPrevious(nuevo);
						setCurrent(nuevo);	

					}else{
					nuevo->setNext(NULL);
					nuevo->setPrevious(getCurrent());
					getCurrent()->setNext(nuevo);
					setCurrent(nuevo);

					}
				}
			}	
		}

		#ifndef NDBUG
			assert((getCurrentItem()==municipio));
			assert(nItems()==oldnitems+1);
		#endif
	}

	
	void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::remove(){
		#ifndef NDBUG
			assert(isEmpty()==false);
		#endif
		int oldnitems=nItems();
		bool first=isFirstItem();
		bool last=isLastItem();

		if(isFirstItem() && isLastItem()){
			delete getCurrent();
			setHead(NULL);
		}

		else if(isLastItem()){
			ed::Municipio municipioPrev=getPreviousItem();
			ed::NodoDoblementeEnlazadoMunicipio *nuevo =getCurrent();
			getCurrent()->getPrevious()->setNext(NULL);
			setCurrent(getCurrent()->getPrevious());
			delete nuevo;
			#ifndef NDBUG
				assert(nItems()==oldnitems-1);
			if(last==true)
				assert(isEmpty()==true || (municipioPrev==getCurrentItem() && isLastItem()==true));
			#endif			
		}	

		else if(isFirstItem()){
			ed::Municipio municipioNext=getNextItem();
			ed::NodoDoblementeEnlazadoMunicipio *nuevo =getCurrent();
			setHead(getCurrent()->getNext());
			getHead()->setPrevious(NULL);
			setCurrent(getCurrent()->getNext());
			delete nuevo;

			#ifndef NDBUG
				assert(nItems()==oldnitems-1);
			if(first==true)
			assert(isEmpty()==true || (municipioNext==getCurrentItem() && isFirstItem()==true));
			#endif			
		}

		else if(!isFirstItem() && !isLastItem()){
			ed::Municipio municipioPrev=getPreviousItem();
			ed::Municipio municipioNext=getNextItem();
			ed::NodoDoblementeEnlazadoMunicipio *nuevo =getCurrent();
			getCurrent()->getNext()->setPrevious(getCurrent()->getPrevious());
			getCurrent()->getPrevious()->setNext(getCurrent()->getNext());
			setCurrent(getCurrent()->getNext());
			delete nuevo;
			
			#ifndef NDBUG
				assert(nItems()==oldnitems-1);
		
			if(first==false and last==false)
				assert(municipioPrev == getPreviousItem() && municipioNext == getCurrentItem());
	
			#endif
		}

	}

	void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::removeAll(){
		if(isEmpty()==false){
			gotoHead();
			while(isEmpty() == false){
				remove();
			}
		}
		setHead(NULL);
		#ifndef NDBUG
			assert(isEmpty()==true);
		#endif
	}
