#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>
#include <regex>
std::string ubicacion = "C:\\Users\\jdrz2\\Desktop\\Universidad\\Analizador";

using namespace std;

std::vector <std::string> general;

void reescribir(){
    SetConsoleOutputCP(CP_UTF8);
    std::ofstream archivo;
    archivo.open(ubicacion+"\\lectura.txt", std::ios::in);
    for(size_t i = 0; i < general.size(); i++){
        archivo<<general[i]<<std::endl;
    }
    archivo.close();
}


int main(){
    SetConsoleOutputCP(CP_UTF8);
    std::ifstream archivo1, archivo;
    std::string linea;
    archivo.open(ubicacion+"\\lectura.txt", std::ios::in);
	if(archivo.fail()){
		std::cout<<"No se pudo abrir el archivo";
		exit(1);
	}
    while(!archivo.eof()) {
        getline(archivo, linea);
        linea = regex_replace(linea, regex("‘"), "'");
        linea = regex_replace(linea, regex("’"), "'");
        general.push_back(linea);
    }
    reescribir();
}

