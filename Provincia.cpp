/*!	

	\file  Provincia.cpp
	\brief Definición de la clase Provincia
  	\author Carlos Luque Córdoba
 	\date   07/04/2018  
	\version 1.0

*/
//Para los flujos de entrada/salida en ficheros.
#include <fstream>  
#include <iostream>
#include <stdlib.h>

// Para comprobar las pre y post condiciones
#include <cassert>

#include "Provincia.hpp"

#include "macros.hpp"


// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE Provincia

///////////////////////////////////////////////////////////////////////////////

// OSBSERVADORES

bool ed::Provincia::hayMunicipios(){
	if(_listaMunicipios.isEmpty()==false)
		return true;
	else
		return false;
}

int ed::Provincia::getNumeroMunicipios(){
	int nitemsnow=_listaMunicipios.nItems();
	return nitemsnow;
}

bool ed::Provincia::existeMunicipio(std::string cad){
	ed::Municipio municipio;
	municipio.setNombre(cad);
	if((_listaMunicipios.find(municipio)) == true)
		return true;
	else 
		return false;
}

ed::Municipio ed::Provincia::getMunicipio(std::string cad){
	#ifndef NDEBUG
		assert(existeMunicipio(cad)==true);
	#endif	
	ed::Municipio municipio;
	municipio.setNombre(cad);
	_listaMunicipios.find(municipio);
	municipio=_listaMunicipios.getCurrentItem();
	return municipio;
}

int ed::Provincia::getTotalHombres(){
		Municipio municipio;
		int v=0;
		_listaMunicipios.gotoHead();
		while(! _listaMunicipios.isLastItem()){
			municipio=_listaMunicipios.getCurrentItem();
			v+=municipio.getHombres();
			_listaMunicipios.gotoNext();
		}
		municipio=_listaMunicipios.getCurrentItem();
		v+=municipio.getHombres();
		return v;
}

int ed::Provincia::getTotalMujeres(){
		Municipio municipio;
		int m=0;
		_listaMunicipios.gotoHead();
		while(! _listaMunicipios.isLastItem()){
			municipio=_listaMunicipios.getCurrentItem();
			m+=municipio.getMujeres();
			_listaMunicipios.gotoNext();
		}
		municipio=_listaMunicipios.getCurrentItem();
		m+=municipio.getMujeres();
		return m;
}


/////////////////////////////////////////////////////////////////////////////////////////

// MODIFICADORES

void ed::Provincia::insertarMunicipio(ed::Municipio municipio){
	#ifndef NDEBUG
		assert(existeMunicipio((municipio.getNombre()))==false);
	#endif	
	int oldnitems;
	oldnitems=getNumeroMunicipios();
	_listaMunicipios.insert(municipio);
	std::string cad=municipio.getNombre();
		
	#ifndef NDEBUG
		assert(existeMunicipio(cad)==true);
		assert(getNumeroMunicipios()==(oldnitems+1));
	#endif	
}

void ed::Provincia::borrarMunicipio(std::string cad){
	#ifndef NDEBUG
		assert(existeMunicipio(cad)==true);
	#endif
	int oldnitems=getNumeroMunicipios();
	_listaMunicipios.gotoHead();
	Municipio municipio;
	municipio=getMunicipio(cad);
	_listaMunicipios.find(municipio);
	_listaMunicipios.remove();
	
	
	#ifndef NDEBUG
		assert(existeMunicipio(cad)==false);
		assert(getNumeroMunicipios()==oldnitems-1);
	#endif	
}

void ed::Provincia::borrarTodosLosMunicipios(){
	if(_listaMunicipios.isEmpty()==false)
		_listaMunicipios.removeAll();
	#ifndef NDEBUG
		assert(hayMunicipios()==false);
	#endif
}


///////////////////////////////////////////////////////////////////////////////////

// FUNCIÓN DE ESCRITURA

void ed::Provincia::escribirMunicipios(){
	int i;
	Municipio municipio;
	std::cout<<BIYELLOW<<"Codigo Postal"<<RESET<<" "<<BIGREEN<<"Nombre"<<";"<<RESET<<BIBLUE<<"Hombres"<<";"<<RESET<<BIPURPLE<<"Mujeres"<<RESET<<std::endl;
	if(_listaMunicipios.isEmpty()==false)
		_listaMunicipios.gotoHead();
	if(getNumeroMunicipios()>1){
		for(i=0;i<getNumeroMunicipios();i++){
			municipio=_listaMunicipios.getCurrentItem();
			std::cout<<BIYELLOW<<municipio.getCodigoPostal()<<RESET<<" "<<BIGREEN<<municipio.getNombre()<<";"<<RESET<<BIBLUE<<municipio.getHombres()<<";"<<RESET<<BIPURPLE<<municipio.getMujeres()<<RESET<<std::endl;
			if((_listaMunicipios.isLastItem())==false)
				_listaMunicipios.gotoNext();	
		}
	}else{
		if(_listaMunicipios.isEmpty()==false){
			municipio=_listaMunicipios.getCurrentItem();
			std::cout<<BIYELLOW<<municipio.getCodigoPostal()<<RESET<<" "<<BIGREEN<<municipio.getNombre()<<";"<<RESET<<BIBLUE<<municipio.getHombres()<<";"<<RESET<<BIPURPLE<<municipio.getMujeres()<<RESET<<std::endl;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////

// OPERACIONES CON FICHEROS

bool ed::Provincia::cargarFichero(std::string cad){
	borrarTodosLosMunicipios();
	std::ifstream mun;
	ed::Municipio municipio;
	mun.open(cad.c_str());
	std::string f;
	if(mun.is_open()){
		std::getline(mun, f, ' ');
		setCodigo(atoi(f.c_str()));

		std::getline(mun, f, '\n');
		setNombre(f);
		
		while(!mun.eof()){
 			 mun>>municipio;
  			if(!existeMunicipio(municipio.getNombre())){
	  			if(!mun.eof())
	  			insertarMunicipio(municipio);
	  		}else
	  			std::cout<<BIRED<<"El municipio "<<municipio.getNombre()<<" ya se encuentra en la lista"<<RESET<<std::endl;
	 	}	

		mun.close();
		return true;
	
	}else
	return false;
}

bool ed::Provincia::grabarFichero(std::string cad){
	std::ofstream mun;
	mun.open(cad.c_str());
	if(mun.is_open()){
		mun<<getCodigo()<<" "<<getNombre()<<"\n";
		_listaMunicipios.gotoHead();	
		while(_listaMunicipios.isLastItem() != true){
			mun<<(_listaMunicipios.getCurrentItem());
			_listaMunicipios.gotoNext();
		}
		mun<<(_listaMunicipios.getCurrentItem());
		mun.close();
		return true;
	}else
	return false;
}
