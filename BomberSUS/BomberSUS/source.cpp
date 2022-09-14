#include <iostream>
#include <fstream>
#include <string>

float version = 0.0;
std::string title;
int textures = 0;

int main() {
	
	std::string temp;
	
	std::ifstream level("level.sus");
	
	//Abrir archivo
	if (!level.is_open()) {
		std::cout << "Error al abrir el archivo\n" << std::endl;
		return 1;
	}

	getline(level, temp, ';');

	std::cout << temp << std::endl;

	
	if (temp != "SUS") {
		std::cout << "Error: Cabecera mal formada" << std::endl;
		return 2;
	}

	//Cogemos version del archivo y cambiamos la nuestra
	getline(level, temp, ';');


	std::cout << temp << std::endl;


	version = stof(temp);

	//Para coger la siguiente linea
	getline(level, temp);   

	getline(level, temp, ';');
	//
	std::cout << temp << std::endl;

	//Comprobamos titulo y lo substituimos
	if (temp != "TITLE") {
		std::cout << "Error: Titulo incorrecto" << std::endl;
		return 3;
	}
	getline(level, temp, ';');


	std::cout << temp << std::endl;

	title = temp;

	getline(level, temp);

	getline(level, temp, ';');

	//Comprobamos texturas y lo substituimos
	if (temp != "TEXTURES") {
		std::cout << "Error: Texturas mal cargadas" << std::endl;
		return 4;
	}

	std::cout << temp << std::endl;

	getline(level, temp, ';');

	textures = stoi(temp);

	std::cout << temp << std::endl;

	return 0;
}