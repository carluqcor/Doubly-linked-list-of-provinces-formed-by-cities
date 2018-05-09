/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal de la provincia
  \author Carlos Luque Córdoba
  \date   07/04/2018
*/

#include <iostream>
#include <string>  

// Para usar atoi
#include <stdlib.h>

#include "Provincia.hpp"

#include "Municipio.hpp"

#include "funcionesAuxiliares.hpp"


#include "macros.hpp"

int ed::menu()
{
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,11);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,11);
	std::cout <<  "[1] Comprobar si la provincia tiene municipios";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,11);
	std::cout << "[2] Cargar la provincia desde un fichero";

	PLACE(posicion++,11);
	std::cout << "[3] Grabar la provincia en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,11);
	std::cout << "[4] Consultar datos de la provincia";

	PLACE(posicion++,11);
	std::cout <<  "[5] Mostrar municipios de la provincia";

	PLACE(posicion++,11);
	std::cout << "[6] Modificar datos de la provincia: código o nombre";

	PLACE(posicion++,11);
	std::cout << "[7] Borrar todos los municipios de una provincia";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,11);
	std::cout << "[8] Consultar un municipio";

	PLACE(posicion++,11);
	std::cout << "[9] Insertar un municipio";

	PLACE(posicion++,11);
	std::cout << "[10] Borrar un municipio";

	PLACE(posicion++,11);
	std::cout << "[11] Comparar dos Municipios";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,11);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,11);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}


//////////////////////////////////////////////////////////////////////////////

void ed::comprobarProvinciaVacia(ed::Provincia &provincia){
	if(provincia.hayMunicipios() == false)
		std::cout<<BIGREEN<<"No hay municipios."<<RESET<<std::endl;
	else
		std::cout<<BIYELLOW<<"Hay al menos 1 municipio en la provincia."<<RESET<<std::endl;

	return;
}

//////////////////////////////////////////////////////////////////////////////

void ed::cargarProvincia(ed::Provincia &provincia){	
	std::string cad;
	std::cout<<BIPURPLE<<"Introduzca el nombre del fichero..."<<RESET<<std::endl;
	std::getline(std::cin,cad);
	
	if((provincia.cargarFichero(cad)) == true)
		std::cout<<BIGREEN<<"El fichero ha sido cargado con existo."<<RESET<<std::endl;
	else{
		std::cout<<BIYELLOW<<"Error al cargar el fichero."<<RESET<<std::endl;
	}
	return;
}

void ed::grabarProvincia(ed::Provincia  &provincia){
	if(provincia.hayMunicipios()==false)
		std::cout<<BIRED<<"Error, no hay municipios"<<RESET<<std::endl;
	else{
		std::string cad;
		std::cout<<BIPURPLE<<"Introduzca el nombre del fichero..."<<RESET<<std::endl;
		std::getline(std::cin,cad);
		
		if((provincia.grabarFichero(cad)) == true){
			std::cout<<BIGREEN<<"El fichero ha sido cargado con existo."<<RESET<<std::endl;
		}
		else
			std::cout<<BIYELLOW<<"Error al grabar el fichero."<<RESET<<std::endl;
	}	
	return;
}

//////////////////////////////////////////////////////////////////////

void ed::consultarDatosDeProvincia(ed::Provincia &provincia){
	if(provincia.hayMunicipios()==true)
		std::cout<<BIGREEN<<"Provincia: "<<provincia.getNombre()<<"\nCódigo: "<<provincia.getCodigo()<<"\nNúmero de Hombres: "<<provincia.getTotalHombres()<<"\nNúmero de Mujeres: "<<provincia.getTotalMujeres()<<"\nHabitantes totales: "<<provincia.getTotalHabitantes()<<RESET<<std::endl;
	else{
		std::cout<<BIYELLOW<<"Provincia: "<<provincia.getNombre()<<"\nCódigo: "<<provincia.getCodigo()<<"\nNúmero de Hombres: 0"<<"\nNúmero de Mujeres: 0"<<"\nHabitantes totales: 0"<<RESET<<std::endl;
		std::cout<<BIRED<<"No hay ningún municipio en la provincia."<<RESET<<std::endl;
	}
	return;
}


//
void ed::mostrarMunicipiosDeProvincia(ed::Provincia & provincia){
	if(provincia.hayMunicipios()==true)
		provincia.escribirMunicipios();
	else
		std::cout<<BIRED<<"No hay ningún municipio en la provincia."<<RESET<<std::endl;
	return;
}


////////////////////////////////////////////////////////////////////////
void ed::modificarDatosDeProvincia(ed::Provincia &provincia){

	int opcion, codigo;
	std::string nombre; 

	do{
		std::cout << BIYELLOW  << "Nombre de la provincia: "  << RESET 
				  << provincia.getNombre() << std::endl; 
		std::cout << BIYELLOW << "Código de la provincia: " << RESET
				  << provincia.getCodigo() << std::endl  << std::endl;

		std::cout << "Indique qué dato desea modificar: " << std::endl;
		std::cout << BIBLUE << "(1) Nombre " << std::endl;
		std::cout << BIBLUE << "(2) Código" << std::endl  << std::endl;
		std::cout << BIRED << "(0) Salir" << std::endl << std::endl  << std::endl;
		std::cout << BIGREEN;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
	    std::cin.ignore();

		std::cout << std::endl;
			
		switch(opcion)
		{
			case 0: 
					// Fin de las modificaciones
					break;
			case 1:
					std::cout << BIGREEN;
					std::cout << "Nuevo nombre de la provincia: ";
					std::cout << RESET;
					std::getline(std::cin,nombre);
					provincia.setNombre(nombre);
					break;

			case 2:
					std::cout << BIGREEN;
					std::cout << "Nuevo código de la provincia: ";
					std::cout << RESET;
					std::cin >> codigo;
					provincia.setCodigo(codigo);
					break;
			default:
					std::cout << BIRED << "Opción incorrecta:" << RESET 
							  << opcion << std::endl;
		}
	}while (opcion != 0);

	return;
}


void ed::borrarTodosLosMunicipiosDeProvincia(ed::Provincia &provincia){
	if(provincia.hayMunicipios()==false)
		std::cout<<BIRED<<"Error, no hay municipios que borrar"<<RESET<<std::endl;
	else{
		std::cout<<BIGREEN<<"Se van a borrar todos los municipios que hay en la provincia..."<<RESET<<std::endl;
		provincia.borrarTodosLosMunicipios();
		if(provincia.hayMunicipios()==false)
			std::cout<<BIYELLOW<<"Se han a borrado todos los municipios satisfactoriamente..."<<RESET<<std::endl;
	}
	return;
}


void ed::consultarMunicipioDeProvincia(ed::Provincia &provincia){
	if(provincia.hayMunicipios()==false)
		std::cout<<BIRED<<"Error, no hay municipios que consultar"<<RESET<<std::endl;
	else{
		std::string cad;
		std::cout<<BIPURPLE<<"Introduzca el nombre del municipio a mostrar..."<<RESET<<std::endl;
		std::getline(std::cin,cad);
		if((provincia.existeMunicipio(cad))==true)
			provincia.getMunicipio(cad).escribirMunicipio();
		else
			std::cout<<BIRED<<"Error no existe el municipio "<<cad<<RESET<<std::endl;
	}
	return;
}

void ed::insertarMunicipioEnProvincia(ed::Provincia &provincia){
	ed::Municipio municipio;
	municipio.leerMunicipio();
	if(provincia.existeMunicipio(municipio.getNombre())==true)
		std::cout<<BIRED<<"Error, el municipio a insertar ya existe y no puede insertarse otra vez"<<RESET<<std::endl;
	else{
	provincia.insertarMunicipio(municipio);
	provincia.escribirMunicipios();
	if(provincia.existeMunicipio(municipio.getNombre())==true)
		std::cout<<BIYELLOW<<"El municipio se ha introducido correctamente."<<RESET<<std::endl;
	}
	return;
}

  


void ed::borrarMunicipioDeProvincia(ed::Provincia &provincia){
	if(provincia.hayMunicipios()==false)
		std::cout<<BIRED<<"Error, no hay municipios que borrar"<<RESET<<std::endl;
	else{
		std::string cad;
		std::cout<<BIPURPLE<<"Introduzca el nombre del municipio a eliminar..."<<RESET<<std::endl;
		std::getline(std::cin,cad);

		std::cout<<BIGREEN<<"El municipio "<<cad<<" se va a borrar..."<<RESET<<std::endl;

		provincia.borrarMunicipio(cad);
		if((provincia.existeMunicipio(cad))==false)
			std::cout<<BIYELLOW<<"El municipio "<<cad<<" se ha borrado."<<RESET<<std::endl;
		std::cin.ignore();
	}	
	return;
}


void ed::compararMunicipios(ed::Provincia &provincia){
	if(provincia.hayMunicipios()==false || provincia.getNumeroMunicipios()<2)
		std::cout<<BIRED<<"Error, no hay suficientes municipios que comparar, al menos se necesitan 2"<<RESET<<std::endl;
	else{
		std::string cad, cad2;
		std::cout<<BIPURPLE<<"Introduzca el nombre del primer municipio"<<RESET<<std::endl;
		std::getline(std::cin,cad);

		std::cout<<BIPURPLE<<"Introduzca el nombre del segundo municipio"<<RESET<<std::endl;
		std::getline(std::cin,cad2);
		if(provincia.existeMunicipio(cad)==true && provincia.existeMunicipio(cad2)==true){
			if(provincia.getMunicipio(cad).getHabitantes()>provincia.getMunicipio(cad2).getHabitantes())
				std::cout<<BIGREEN<<provincia.getMunicipio(cad).getNombre()<<" tiene mas habitantes que "<<provincia.getMunicipio(cad2).getNombre()<<RESET<<std::endl;
			else if	(provincia.getMunicipio(cad).getHabitantes()==provincia.getMunicipio(cad2).getHabitantes())
				std::cout<<BIGREEN<<provincia.getMunicipio(cad).getNombre()<<" tiene los mismos habitantes que "<<provincia.getMunicipio(cad2).getNombre()<<RESET<<std::endl;
			else if(provincia.getMunicipio(cad).getHabitantes()<provincia.getMunicipio(cad2).getHabitantes())
				std::cout<<BIGREEN<<provincia.getMunicipio(cad).getNombre()<<" tiene menos habitantes que "<<provincia.getMunicipio(cad2).getNombre()<<RESET<<std::endl;
		}else{
			std::cout<<BIRED<<"Error, uno de los municipios no existe, ha sido borrado o no ha sido insertado"<<RESET<<std::endl;
		}

	}
}

