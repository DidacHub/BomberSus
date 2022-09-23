#include <iostream>
#include <fstream>
#include <string>
#include <map>
//#include "source.h"

float version = 0.0;
std::string title;
int num_textures = 0;
std::map<std::string, std::string> textures;

std::string** background;
int background_w = 0;
int background_h = 0;
std::string** foreground;
int foreground_w = 0;
int foreground_h = 0;
std::string** objects;
int objects_w = 0;
int objects_h = 0;

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

	num_textures = stoi(temp);

	std::cout << temp << std::endl;

	getline(level, temp);

	for (int i = 0; i < num_textures; i++) {
		std::string key;
		getline(level, key, ';');

		std::string value;
		getline(level, value, ';');

		textures[key] = value;

		std::cout << key << ";" << value << std::endl;

		getline(level, temp);
	}

	getline(level, temp, ';');

	if (temp != "BACKGROUND") {
		std::cout << "Error: Background incorrecto" << std::endl;
		return 5;
	}

	std::cout << temp << std::endl;

	getline(level, temp, ';');
	
	std::cout << temp << std::endl;

	background_w = stoi(temp);

	getline(level, temp, ';');
	std::cout << temp << std::endl;

	background_h = stoi(temp);

	getline(level, temp);

	//Dibujando background

	background = new std::string * [background_h];

	for (int i = 0; i < background_h; i++) {
		background[i] = new std::string[background_w];
		
	}
	
	for (int i = 0; i <  background_h; i++) {
		for (int j = 0; j < background_w; j++) {
			getline(level, temp, ';');
			std::cout << temp;

			background[i][j] = temp;
		}
		std::cout << std::endl;

		getline(level, temp);

	}

	//Cogiendo foreground

	getline(level, temp, ';');

	if (temp != "FOREGROUND") {
		std::cout << "Error: Foreground incorrecto" << std::endl;
		return 6;
	}

	std::cout << temp << std::endl;

	getline(level, temp, ';');

	std::cout << temp << std::endl;

	foreground_w = stoi(temp);

	getline(level, temp, ';');
	std::cout << temp << std::endl;

	foreground_h = stoi(temp);

	getline(level, temp);

	//Dibujando foreground

	foreground = new std::string * [foreground_h];

	for (int i = 0; i < foreground_h; i++) {
		foreground[i] = new std::string[foreground_w];

	}

	for (int i = 0; i < foreground_h; i++) {
		for (int j = 0; j < foreground_w; j++) {
			getline(level, temp, ';');
			std::cout << temp;

			foreground[i][j] = temp;
		}
		std::cout << std::endl;

		getline(level, temp);

	}
	
	//Cogiendo objects
	getline(level, temp, ';');

	if (temp != "OBJECTS") {
		std::cout << "Error: Objetos incorrecto" << std::endl;
		return 7;
	}

	std::cout << temp << std::endl;

	getline(level, temp, ';');

	std::cout << temp << std::endl;

	objects_w = stoi(temp);

	getline(level, temp, ';');
	std::cout << temp << std::endl;

	objects_h = stoi(temp);

	getline(level, temp);

	

	//Dibujando objetos

	objects = new std::string * [objects_h];

	for (int i = 0; i < objects_h; i++) {
		objects[i] = new std::string[objects_w];

	}

	for (int i = 0; i < objects_h; i++) {
		for (int j = 0; j < objects_w; j++) {
			getline(level, temp, ';');
			std::cout << temp;

			objects[i][j] = temp;
		}
		std::cout << std::endl;

		getline(level, temp);

	}

	return 0;
}