#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string.h>
#include <strings.h>

using namespace std;


//Declarando Variables
ifstream archivo;
string miLinea;
vector <string> v2;
string reservada[17] = {"IF", "THEN", "ELSE","BEGIN", "END",
 "FOR", "REPEAT", "WHILE", "VARIABLE", "CONST", 
 "PROGRAM", "INCLUDE", "UNTIL", "FOREACH", 
 "SPLIT", "CASE", "SWITCH"};

string operadoBinario[4] = {"-", "+", "*", "/"};
string operadorLogico[6] = {"<", ">", "==", "<=", "=>", "!="};


int main (){
    int j = 0;
    string linea;
    archivo.open("lectura.txt");
    if(archivo.is_open()){
        while(!archivo.eof()){
            getline(archivo, linea);
            v2.push_back(linea);
        }
    }else{
        cout<<"El archivo no se encontrado"<<endl;
    }
    cout<<"Palabras Reservadas: "<<endl;
    for(size_t i = 0; i<v2.size(); i++){
        
        for(j=0; j<17; j++){
            const char *letra = v2[i].c_str();
            const char *busqueda = reservada[j].c_str();
            const char *resultado = strstr(letra, busqueda);
            if(strstr(v2[i].c_str(), reservada[j].c_str())){
                cout<<i<<") "<<reservada[j]<<endl;
            }
        }
    }
   
}
