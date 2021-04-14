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

string miLinea;
vector <string> v2;
string reservada[17] = {"IF", "THEN", "ELSE","BEGIN", "END",
 "FOR", "REPEAT", "WHILE", "VARIABLE", "CONST", 
 "PROGRAM", "INCLUDE", "UNTIL", "FOREACH", 
 "SPLIT", "CASE", "SWITCH"};

string operadoBinario[4] = {"-", "+", "*", "/"};
string operadorLogico[6] = {"<", ">", "==", "<=", "=>", "!="};

void token(int, string[], string);


int main (){
    int j = 0;
    string linea;
    archivo.open("lectura.txt");
    if(archivo.is_open()) {
        while(!archivo.eof()) {
            getline(archivo, linea);
            v2.push_back(linea);
        }
    }else{
        cout<<"El archivo no se encontrado"<<endl;
    }
    
    token(14, reservada, "Palabra Reservada: ");
    token(4, operadoBinario, "Operadores Binarios: ");
    token(6, operadorLogico, "Operadores Logicos: ");
}

void token(int num, string palabras[], string oracion){ 
    int contador = 0;
    for(size_t i = 0; i<v2.size(); i++) {
        const char *letra = v2[i].c_str();
        for(int j=0; j<num; j++){
            const char *busqueda = palabras[j].c_str();
            const char *resultado = strstr(letra, busqueda);
            if(resultado){
                cout<<oracion<<palabras[j]<<endl;
                contador++;
            }
        } 
    }
    cout<<"Hay "<<contador<<" "<<oracion<<endl;
}
