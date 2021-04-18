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
vector <string> v4;

// vectores para las especificaciones generales, regulares y validaciones
vector <string> general;
vector <string> regular;
vector <string> validacion;
vector <string> identificadorTxt;

// vector separacion especificaciones generales
std::map<string, string> especificacionGeneral;
std::map<string, string> especificacionRegular;
std::map<string, string> especificacionValidacion;


int i = 0;
int j = 0;


typedef pair<string, string> componenteGeneral;
typedef pair<string, string> componenteRegular;
typedef pair<string, string> componenteValidacion;
std::map<string, string> expresion1;


void generadorArchivo(){
    ofstream archivo;

    archivo.open("archivo.h");
    archivo<<"#include <regex>\n\n\n";    
    
    for(size_t i = 0; i <identificadorTxt.size(); i++){
        archivo<<identificadorTxt[i]<<endl;
        archivo<<v4[i]<<endl;
    }
        
//    archivo<<"\nstd::string Alfabeto = \""+Digito+"\";";
//    archivo<<"\n\nvoid generadorLexicografico(){\n";
//    archivo<<"\tstd::string Entero = "+Entero+";\n";
//    archivo<<"\tstd::string Idnetificador = "+identi+";\n";
//    archivo<<"\tstd::string aux;\n";
//    archivo<<"\tstd::regex reg1(Entero);\n";
//    archivo<<"\twhile (true){\n";
//    archivo<<"\t\tstd::cin>>aux;\n";
//    archivo<<"\t\tbool match = regex_match(aux, reg1);\n";
//    archivo<<"\t\tif(match)\n";
//    archivo<<"\t\t\tstd::cout<<\"Entero\"<<std::endl;\n";
//    archivo<<"\t}\n";
//    archivo<<"}";
    archivo.close();
}

string separadoTxt(string palabra, regex expresion){
    cout<<boolalpha;
    smatch matches;
    string palabraExpresion;
    string palabraSinComa;
    string palabra_transformada = palabra;
    char chars[] = ",";
    while(regex_search(palabra, matches, expresion)){
        cout<<"is there a match: "<<matches.ready()<<endl;
        cout<<"are there not matches: "<<matches.empty()<<endl;
        cout<<"Number of matches: "<<matches.size()<<endl;
        cout<<matches.str()<<endl;
        palabra_transformada = matches.str();
        palabra = matches.suffix().str();
    cout<<palabra_transformada<<"gg"<<endl;
    }
    string::size_type pos = palabra_transformada.find("‘", 0);
    string::size_type pos1 = palabra_transformada.find("’", 0);


    while (palabra_transformada.find("‘") != string::npos)
        palabra_transformada.replace(palabra_transformada.find("‘"), 1, "\'");	
    
    while (palabra_transformada.find("’") != string::npos)
        palabra_transformada.replace(palabra_transformada.find("’"), 1, "\'");

    // if (pos < string::npos){
    //     palabra_transformada.replace(pos, string("‘").length(), "\"");
    // }
    
    // if (pos1 < string::npos)
    // 	palabra_transformada.replace(pos1, string("’").length(), "\"");

    palabra_transformada.erase(remove(palabra_transformada.begin(), palabra_transformada.end(), chars[0]), palabra_transformada.end());
    cout<<palabra_transformada<<"gg"<<endl;
    // std::remove_if(palabra_transformada.begin(), palabra_transformada.end(), ::isspace);
    return palabra_transformada;
}



std::string trim(const std::string& str, const std::string& whitespace = "\t"){ 
    const auto strBegin = str.find_first_not_of(whitespace); 
    if (strBegin == std::string::npos) return ""; 
    const auto strEnd = str.find_last_not_of(whitespace); 
    const auto strRange = strEnd - strBegin + 1; 
    return str.substr(strBegin, strRange); 
}

std::string reduce(const std::string& str, const std::string& fill = " ", const std::string& whitespace = "\t"){ 
    // trim first 
    auto result = trim(str, whitespace); 
    // replace sub ranges 
    auto beginSpace = result.find_first_of(whitespace); 
    while (beginSpace != std::string::npos) { 
        const auto endSpace = result.find_first_not_of(whitespace, beginSpace); 
        const auto range = endSpace - beginSpace; result.replace(beginSpace, range, fill); 
        const auto newStart = beginSpace + fill.length(); beginSpace = result.find_first_of(whitespace, newStart); 
    } 
    return result; 
}


void separadorGeneral(string nombre, int seleccion){
    std::string palabra = nombre;
    std::string delimiter = ":=";
    std::string palabra_transformada;
    double total = 0;
    size_t pos = 0;
    std::string token;
    while ((pos = palabra.find(delimiter)) != std::string::npos) {
        token = reduce(palabra.substr(0, pos)); 
        palabra_transformada = palabra.erase(0, pos + delimiter.length());        
        if (seleccion == 1){
            especificacionGeneral.insert(std::pair<string, string>(token, palabra));
        }
        else if(seleccion == 2){
            especificacionRegular.insert(componenteRegular(token,palabra));
        }
        else if(seleccion == 3){
            // cout<<words[i]<<"3"<<endl;
            cout<<token<<"2"<<endl;
            cout<<palabra<<"2"<<endl;   
            especificacionValidacion.insert(componenteValidacion(token,palabra));
        }        
    } 
}


string identificador(string word2){
    string letra = "";
    istringstream buf(word2);

    string orden  = to_string(j);
    for(string word; buf>>word;){
        cout<<"La palabra es: "<<word<<endl;
        if(word == "("){
            word = " \"(\" ";
        }else if(word == ")"){
            word = " \")\" ";
        }else{
            for(size_t i = 0; i < identificadorTxt.size(); i++){
                if (identificadorTxt[i].find(word) != string::npos){
                    cout<<word<<"="<<identificadorTxt[i]<<endl;
                    word = " + "+word+" + ";
                    i++;
                }
            }
        }
        letra += word;
    }
    return letra;
}



int main(){
	SetConsoleOutputCP(CP_UTF8);
    string Digito = "[0-9]";
    string Alfabeto = "[a-zA-Z]";
    string Entero = "\"0|\" + Digito + Digito + \"*\"";
    string linea;

    int j = 0;

    std::regex igual("[:=]");
    // std::regex regEntero("..[-].*.?|..[‘-’].*.?");
    std::regex regEntero("\(([^()]+)\)|\[(.*?)\]");

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
    
    // for(int i = 0; i<general.size(); i++){   
    //     separadoTxt(general[i], regEntero);
    //     Separador(v3[i]);
    // }
//    
//    map<string, string>::iterator i;
//     for (i = especificacionGeneral.begin(); i != especificacionGeneral.end(); i++){
//         cout << setw(10) << i->first <<" = "<< setw(12) << i->second << endl;
//     }

   for(auto &el1: especificacionGeneral){
       cout<<el1.first<<" "<<el1.second<<endl;
    //    identificador(el1.first, el1.second);
   }

//    for(size_t i = 0; i<general.size(); i++){
//        separadoTxt(general[i], regEntero);
//    }
//    generadorArchivo(v3[2], v3[6], Entero, v[0]);
    
    //Se escriben las especificaciones generales
    std::cout<<"ESPECIFICACIONES GENERALES"<<std::endl;
    for (size_t i = 0; i < general.size(); i++){
        cout<<general[i]<<endl;
        separadorGeneral(general[i], 1);
    }

    // Se escriben las especificaciones regulares
    std::cout<<"ESPECIFICACION REGULARES"<<std::endl;
    for (size_t i = 0; i < regular.size(); i++){
        cout<<regular[i]<<endl;
        
        separadorGeneral(regular[i], 2);
    }
    
    // Se escriben las validaciones
    std::cout<<"VALIDACION"<<std::endl;
    for (size_t i = 0; i < validacion.size(); i++){
        cout<<validacion[i]<<endl;
        separadorGeneral(validacion[i], 3);
    }

    // Se empiezan a separar las palabras y se le quitan el :=
    // cout<<endl;
    // for (size_t i = 0; i < v4.size(); i++){
    //     cout<<v4[i]<<endl;
    // }
    cout<<"Muestra datos que hay en los array Map"<<endl;
    map<string, string>::iterator i;
    for(i = especificacionGeneral.begin(); i != especificacionGeneral.end(); i++){
        cout<<i->first<<" -> "<<i->second<<endl;
        identificadorTxt.push_back(i->first);
        v4.push_back(separadoTxt(i->second, regEntero));
    }

    //Metiendo datos en un vector
    for(i = especificacionRegular.begin(); i != especificacionRegular.end(); i++)
        identificadorTxt.push_back(i->first);

    for(i = especificacionRegular.begin(); i != especificacionRegular.end(); i++){
        string regular = "";
        cout<<i->first<<i->second<<endl;
        regular = separadoTxt(i->second, regEntero);
        v4.push_back(identificador(regular));
    }

    for(i = especificacionValidacion.begin(); i != especificacionValidacion.end(); i++){
        cout<<i->first<<" -> "<<i->second<<endl;
        
        identificadorTxt.push_back(i->first);
        v4.push_back(i->second);          
    }

    cout<<"\n\nVector Identificador"<<endl;
    for(size_t i = 0; i < identificadorTxt.size(); i++){
        cout<<identificadorTxt[i]<<" su identificador es "<<v4[i]<<".."<<endl;
    }
    generadorArchivo();

    return 0;
}


