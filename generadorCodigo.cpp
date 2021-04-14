#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <map>
#include <iomanip>
#include <string>
#include <sstream>
#include <windows.h>
#include <cstdio>

using namespace std;

struct cadena{
    string cadenaCompleta;
};


ifstream archivo;
string palabra_transformada;
vector <string> v;
vector <string> v2;
vector <string> v3;
vector <string> general;
vector <string> regular;
vector <string> validacion;
int i = 0;



typedef pair<string, string> componenteGeneral;
std::map<string, string> expresion1;


void generadorArchivo(string, string, string);

void generadorArchivo(string Digito, string Alfabeto,
    string Entero, string identi){
    ofstream archivo;

    archivo.open("archivo.h");
    archivo<<"#include <regex>\n\n\n";    
    archivo<<"std::string Digito = \""+Alfabeto+"\";"; 
    archivo<<"\nstd::string Alfabeto = \""+Digito+"\";"; 
    archivo<<"\n\nvoid generadorLexicografico(){\n";
    archivo<<"\tstd::string Entero = "+Entero+";\n";
    archivo<<"\tstd::string Idnetificador = "+identi+";\n";
    archivo<<"\tstd::string aux;\n";
    archivo<<"\tstd::regex reg1(Entero);\n";

    archivo<<"\twhile (true){\n";
    archivo<<"\t\tstd::cin>>aux;\n";
    archivo<<"\t\tbool match = regex_match(aux, reg1);\n";
    archivo<<"\t\tif(match)\n";
    archivo<<"\t\t\tstd::cout<<\"Entero\"<<std::endl;\n";
    archivo<<"\t}\n";
    archivo<<"}";
    archivo.close();
}

void separadoTxt(string palabra, regex expresion){
    cout<<boolalpha;
    smatch matches;
    string palabraExpresion;
    string palabraSinComa;
    string palabra_transformada;
    char chars[] = ",";
    string bar = "‘";
    size_t len = bar.length();
    while(regex_search(palabra, matches, expresion)){
        cout<<"is there a match: "<<matches.ready()<<endl;
        cout<<"are there not matches: "<<matches.empty()<<endl;
        cout<<"Number of matches: "<<matches.size()<<endl;
        cout<<matches.str()<<endl;
        palabra_transformada = matches.str();
        palabra = matches.suffix().str();

    }
    string::size_type pos = palabra_transformada.find("‘", 0);
    if (pos < string::npos)
        palabra_transformada.replace(pos, string("‘").length(), "\"");

    palabra_transformada.erase(remove(palabra_transformada.begin(), palabra_transformada.end(), chars[0]), palabra_transformada.end());
    v3.push_back(palabraSinComa);
}


void Separador(string definicion){
    std::string s = definicion;
    std::string delimiter = ":= ";
    std::string palabra;
    double total = 0;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        s.erase(0, pos + delimiter.length());
        palabra = s;
        expresion1.insert(componenteGeneral(token, s));
    }
    v3.push_back(palabra_transformada);
}

    int j = 0;
void identificador(string word1, string word2){
    string letra = "";
    istringstream buf(word2);

    string orden  = to_string(j);
    for(string word; buf>>word;){
        cout<<word<<endl;
        if(word == "("){
            word = "+\"(\"+";
        }else if(word=="|"){
            word = "+\"|\"+";
        }else if(word==")"){
            word = "+\")\"+";
        }else if(word=="*"){
            word = "\"*\"";
        }
        letra += word;
    }

    v.push_back(letra);
    cout<<v[0]<<endl;
}



int main(){
	SetConsoleOutputCP(CP_UTF8);
    string Digito = "[0-9]";
    string Alfabeto = "[a-zA-Z]";
    string Entero = "\"0|\" + Digito + Digito + \"*\"";
    string linea;

    int j = 0;

    
    std::regex igual("[:=]");
    std::regex regEntero("..[-].*.?|[‘-’].*.?");

    // Lectura de archivo y se guarda linea por linea en el vector v2
    archivo.open("lectura.txt");
    
    if(archivo.fail()){
        cout<<"El archivo no se encontrado"<<endl;
    }else{
        while(!archivo.eof()) {
            getline(archivo, linea);
            if(linea == "[%%]"){
                getline(archivo, linea);
                do{
                    general.push_back(linea);
                    getline(archivo, linea);
                }while(linea != "[%%]");
            }else{
                do{
                    regular.push_back(linea);
                    getline(archivo, linea);
                }while(linea != "[&&]");
                if(linea == "[&&]"){
                    getline(archivo, linea);
                    do{
                        validacion.push_back(linea);
                        getline(archivo, linea);
                    }while(linea != "[&&]");
                    getline(archivo, linea);
                }
            }
     
         v2.push_back(linea);
        }
    }

    // for(int i=0; i < v2.size(); i++){
    //     if(v2[i]=="[%%]")
    //         cout<<"hola";
    // }
    
    for(int i = 0; i<general.size(); i++){   
        separadoTxt(general[i], regEntero);
        Separador(general[i]);
    }
    
    map<string, string>::iterator i;
    // for (i = expresion1.begin(); i != expresion1.end(); i++){
    //     cout << setw(10) << i->first <<" = "<< setw(12) << i->second << endl;
    // }


    // for(auto &el1: expresion1){
    //     cout<<el1.first<<" "<<el1.second<<endl;
    //     identificador(el1.first, el1.second);
    // }

    // 
    // separadoTxt(v2[1], regEntero);
    // generadorArchivo(v3[2], v3[6], Entero, v[0]);
    std::cout<<"ESPECIFICACIONES GENERALES"<<std::endl;
    for (size_t i = 0; i < general.size(); i++){
        cout<<general[i]<<endl;
    }

    std::cout<<"ESPECIFICACION REGULARES"<<std::endl;
    for (size_t i = 0; i < regular.size(); i++){
        cout<<regular[i]<<endl;
    }
    
    std::cout<<"VALIDACION"<<std::endl;
    for (size_t i = 0; i < validacion.size(); i++){
        cout<<validacion[i]<<endl;
    }
    
    for (size_t i = 0; i < v3.size(); i++)
    {
        cout<<v3[i]<<endl;
    }
    

    return 0;
}


