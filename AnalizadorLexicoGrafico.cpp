#include <stdio.h>
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <stdlib.h>
#include <iterator>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <utility>
#include <string>
#include <regex>

using namespace std;

int contador = 0;
std::vector<std::string> especificacion;
std::vector<std::string> texto;
std::string ubicacion;
struct NodoV{
	std::string id;
	std::vector <std::string> contenido;
	NodoV *siguiente;
};


//Prototipos de funci�n
void escribircodigo();
void escribirPila( NodoV*& pila, std::ofstream &, bool);
void guardar(std::ofstream &, std::vector <std::string>, bool);
void abrir_documento(std::string direccion);
void gotoxy(int, int);
void agregarpila(NodoV*& pila, std::string,std::vector <std::string>);
void mostrarpila(NodoV *&);
void reescribir(char array[]);
void mostrar (std::vector <std::string> n);
void escribirRegex(NodoV *& pila,std::ofstream &);
void Color(int Background, int Text); 
std::vector <std::string> separador(std::string);
std::vector <std::string> anadirvector(std::string);
std::string analisisgeneral(std::string);
std::string tokenizar(std::string);
std::string analisis(std::string);
bool isoperator(std::string);
bool isoperator(std::string);
//pilas
NodoV *general = NULL;
NodoV *regular = NULL;
NodoV *validaciones = NULL;
//borradores---------------------------------------------------------------------------
std::string trim(const std::string& str, const std::string& whitespace = " \t"){ 
const auto strBegin = str.find_first_not_of(whitespace); 
if (strBegin == std::string::npos) return ""; 
const auto strEnd = str.find_last_not_of(whitespace); 
const auto strRange = strEnd - strBegin + 1; 
return str.substr(strBegin, strRange); 
}

std::string reduce(const std::string& str, const std::string& fill = " ", const std::string& whitespace = " \t"){ 
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
//Men� principal
int main (){
SetConsoleOutputCP(CP_UTF8);
std::string direccion;
std::ifstream archivo1, archivo;
std::string linea;
system("cls");
Color(0,9);gotoxy(5,1);std::cout<<"UMG VILLA NUEVA, INGENIERIA EN SISTEMAS";
Color(0,9);	gotoxy(5,2);std::cout<<"DESARROLLADO POR:";Color(0,14); std::cout<<" JORDI AUGUSTO GONZALEZ QUINTAL CARNET: 5090-18-5206";
Color(0,14);	gotoxy(5,3);std::cout<<"                  JUAN DIEGO REYEZ ZEPEDA        CARNET: 5090-18-5233";
Color(0,9);	gotoxy(45,7);std::cout<<"GENERADOR DE ANALIZADOR LEXICOG";
	gotoxy(2,10);std::cout<<"DIRECCION DE SU DOCUMENTO TXT: ";
	Color(0,11);
getline(std::cin, direccion);
abrir_documento(direccion);
system("cls");
Color(0,10);
std::cout<<"TRANSFORMACION DE EXPRESIONES GENERALES"<<std::endl;
mostrarpila(general);
Color(0,11);
std::cout<<"TRANSFORMACION DE EXPRESIONES REGULARES"<<std::endl;
mostrarpila(regular);
Color(0,12);
std::cout<<"TRANSFORMACION VALIDACIONES"<<std::endl;
mostrarpila(validaciones);
system("pause");
escribircodigo();
Color(0,2);
std::cout<<"LIBRERIA GENERADA CON EXITO..."<<std::endl;
Color(0,14);
return 0;
}
void reescribir(char array[]){
    SetConsoleOutputCP(CP_UTF8);
    std::ofstream rees;
    rees.open(array, std::ios::in);
    for(size_t i = 0; i < texto.size(); i++){
        rees<<texto[i]<<std::endl;
    }
    rees.close();
}

//apertura del documento
void abrir_documento(std::string dir){
	system("cls");
	std::string bracket;
	std::ifstream archivo1, archivo, rees;
	char direccion[dir.length()] , text;
	std::string linea;
	int numero, MAX=10000;
	char chars[] = ",";
	strcpy(direccion, dir.c_str());
	std::string s(direccion);
	ubicacion = regex_replace(s, regex(".txt"), ".h");
	archivo.open(direccion, std::ios::in);
	rees.open(direccion, std::ios::in);
	if(archivo.fail()){
		std::cout<<"No se pudo abrir el archivo";
		exit(1);
	}  
	Color(0,15);gotoxy(45,2);std::cout<<"LECTURA DEL ARCHIVO"<<std::endl;
    while(!rees.eof()) {
        getline(rees, linea);
        std::cout<<linea<<std::endl;
        linea = regex_replace(linea, regex("‘"), "'");
        linea = regex_replace(linea, regex("’"), "'");
        texto.push_back(linea);
    }
    Color(0,15);std::cout<<" LECTURA REALIZADA CON EXITO"<<std::endl;
    system("pause");
	reescribir(direccion);
	//caracter raro -30
	while(!archivo.eof()){	
		getline(archivo, bracket);
		//ESPECIFICACIONES GENERALES
		if(reduce(bracket)=="[%%]"){
			getline(archivo,bracket);
			do{
			std::vector <std::string> guardado;
			std::vector <std::string> info;
			guardado = separador(bracket);
			std::string auxiliar=analisisgeneral(guardado.at(1));
			info.push_back(auxiliar);
			agregarpila(general, guardado.at(0), info);
    		getline(archivo, bracket);
			}while (reduce(bracket)!="[%%]");
		}
		//EXPRECIONES REGULARES
		if(reduce(bracket)=="[%%]"){
			getline(archivo,bracket);
			do{
			std::string contenido;
			std::vector <std::string> guardado;
			std::vector <std::string> info;
			guardado = separador(bracket);
			//guardar en pila
			
			contenido = tokenizar(analisis(guardado.at(1)));
			info = anadirvector(contenido);
			agregarpila(regular, guardado.at(0), info);
    		getline(archivo, bracket);
			}while (bracket!="[&&]");
		}
		//VALIDACIONES
		if(bracket=="[&&]"){
			getline(archivo, bracket);
			bool aux_salida = true;
			while(aux_salida){
				if(bracket=="[&&]") break;	
				std::string nombre; 
				char aux[bracket.length()];
				char aux_name[200];
				char aux_cont[200];
				strcpy(aux, bracket.c_str());
				//leer nombre
				int salida=0;
				int contenido=0;
				int entrada=0;
				while(salida<2){
					(aux[contenido]==32) ? contenido++: contenido;
					if(aux[contenido]==':'||aux[contenido]=='='){
						contenido++;
						salida++;
					}else{
						aux_name[entrada]=aux[contenido];
						contenido++;
						entrada++;
					}
				}
				aux_name[entrada] = 0;
				//Variable contenido tiene la memoria de que parte del vector he analizado
				while (aux[contenido]==32) contenido++;
				std::string validar_nombre = aux_name;
				if(validar_nombre=="Reservadas"){
					std::vector <std::string> palabras;
					if(aux[contenido]=='['){
						contenido++;
						bool salida =true;
						while(salida){
							char palabra[200];
							char id[200];
							int copiador=0;
							if(aux[contenido]==']') break;
							if(aux[contenido]==0){
								getline(archivo, bracket);
								strcpy(aux, bracket.c_str());
								contenido=0;
								while (aux[contenido]==32) contenido++;
							}
							while(aux[contenido]!=61){
								id[copiador]=aux[contenido];
								copiador++;
								contenido++;
							}
							id[copiador]=0;
							contenido++;
							copiador=0;
							if(aux[contenido]==39){
								contenido++;
								while(aux[contenido]!=39){
									palabra[copiador]=aux[contenido];
									contenido++;
									copiador++;
								}
							palabra[copiador]=0;
							}
							palabras.push_back(palabra);
						contenido++;
						while (aux[contenido]==32||aux[contenido]==44) contenido++;
						}
					agregarpila(validaciones, "reservadas", palabras);
					}	
				}
				//para validaci�n de los comentarios
				if(validar_nombre=="ComI"||validar_nombre=="ComF"||validar_nombre=="ComL"){
					std::vector <std::string> comentarios;
					if(aux[contenido]=='['){
						contenido++;
						bool salida=true;
						while(salida){
							char comentario[200];
							int contador=0;
							while(aux[contenido]!=44 && aux[contenido]!=93){
								while(aux[contenido]==32) contenido++;
								comentario[contador]='[';
								contador++;
								comentario[contador]=aux[contenido];
								contador++;
								contenido++;
								comentario[contador]=']';
								contador++;
							}
							comentario[contador]=0;
							comentarios.push_back(comentario);
							if(aux[contenido]==']') break;
							contenido++;
						}
					}
				agregarpila(validaciones, validar_nombre, comentarios);
				}
				getline(archivo, bracket);
			}
		}
	}
	archivo.close();
}
//funci�n de posicionamiento
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
 //separar cadena
std::vector <std::string> separador(std::string bracket){
	std::string delim=":=";
	std::vector <std::string> words{};
	size_t pos =0;
	while ((pos = bracket.find(delim)) != std::string::npos) {
        words.push_back(reduce(bracket.substr(0,pos)));
        bracket.erase(0, pos + delim.length());
    }
    if (!bracket.empty()) words.push_back(reduce(bracket.substr(0, pos)));
return words;	
 }
//manejo de pila
void agregarpila(NodoV*& pila, std::string ide,std::vector <std::string> n ){
	NodoV* nuevo_nodo = new NodoV();
	nuevo_nodo->id = ide;
	nuevo_nodo->contenido = n;
	nuevo_nodo->siguiente =pila;
	pila = nuevo_nodo;
}
//mostrarpila
void mostrarpila(NodoV *& p){
	NodoV* aux = new NodoV();
	aux=p;
	while(aux!=NULL){
	std::cout<<" ";
	Color(0,9);std::cout<<"std::string "<<aux->id;
	Color(0,6);std::cout<<" = ";
	Color(0,14);mostrar(aux->contenido);
	aux=aux->siguiente;
	}
}
//analisis expresiones generales
std::string analisisgeneral(std::string expg){
	char aux[expg.length()];
	char auxelim[expg.length()];
	int cte=0, cte2=0, comillas=0;
	strcpy(aux,expg.c_str());
	while(aux[cte]!=0){
	bool agregare = false;
		(aux[cte]==39)? comillas++ : comillas;
		if(aux[cte]==39 && comillas==1){
			auxelim[cte2]=34;
			cte2++;
			aux[cte] = '[';
		}else if(aux[cte]=='['&&comillas==0){
			auxelim[cte2]=34;
			cte2++;
		}
		if(aux[cte]==39 && comillas==2){
			aux[cte] = ']';
			comillas=0;
			agregare=true;
		}else if(aux[cte]==']'&&comillas==0){
			agregare=true;
		}
		if(aux[cte]!=44){
			auxelim[cte2]=aux[cte];	
			cte2++;
			cte++;
		}else{
		cte++;	
		}
		if(agregare){
			auxelim[cte2]=34;
			cte2++;
		}
	}
	auxelim[cte2]=0;
	std::string volver=auxelim;
	return volver;
}
//analisis expresiones regulares
std::string analisis(std::string expresion){
	int MAX=1000;
	char aux[expresion.length()], aux1[MAX];
	strcpy(aux,expresion.c_str());
	std::string expresionreducida;
	int cont=0, cont1=0, comillas =0;
	char anterior=0;
	bool antes=false;
	//agregar un simbolo para la concatenaci�n
	while(aux[cont]!=0){
		bool espacio=false;
		bool dalfa=false;
		bool palfa=false;
		bool psigno=false;
		bool par=false;
		bool ppar=false;
		bool agregar=false;
		while(aux[cont]==32){
			cont++;
			espacio=true;
		}
		switch(anterior){
			case '*':
			case '|':
			case ')':
			case '(':
				psigno=true;
				break;
		}
		if(aux[cont]==39){
		cont++;
		aux1[cont1] = 34; cont1++;
			while(aux[cont]!=39){
				aux1[cont1] = '['; cont1++;
				aux1[cont1] = aux[cont]; 
				cont1++;
				cont++;
				aux1[cont1] = ']'; cont1++;
			}
		aux[cont]=34;
		}
		if(aux[cont]=='(') par=true;
		if(anterior=='(') ppar=true;
		if(anterior==')'&&aux[cont]=='('){
			aux1[cont1]='.';
			cont1++;	
		} 
		if(isalpha(aux[cont])) dalfa=true;
		if(isalpha(anterior)) palfa=true;
		if(!ppar&&par&&!psigno&&anterior!=0){
			aux1[cont1]='.';
			cont1++;	
		}
		if(espacio&&dalfa&&palfa){
			aux1[cont1]='.';
			cont1++;	
		}
		if(espacio && aux[cont]=='#'){
			aux1[cont1]='.';
			cont1++;	
		}
		aux1[cont1] = aux[cont];
		cont1++;
		anterior = aux[cont];
		cont++;
	}
	aux1[cont1]=0;
	expresionreducida = aux1;
	return expresionreducida;
}
//agregamos el separador para poder tokenizar expresiones
std::string tokenizar(std::string expresion){
	int max=1000, cont=0, cpyi=0, cor=0;
	char aux[expresion.length()], cpy[max];
	strcpy(aux, expresion.c_str());
	while(aux[cont]!=0){
	bool entry =true;
	if(aux[cont]==91) cor++;
	if(aux[cont]==93) cor=0;
	if(cor!=1){
		switch(aux[cont]){
			case '*':
			case '|':
			case '(':
			case ')':
				cpy[cpyi]='.';
				cpyi++;
				cpy[cpyi]='"';
				cpyi++;
				cpy[cpyi]=aux[cont];
				cpyi++;
				cpy[cpyi]='"';
				cpyi++;
				cpy[cpyi]='.';
				cpyi++;
				entry=false;
				cont++;
				break;
		}
	}
	if(entry){
		cpy[cpyi]=aux[cont];
				cpyi++;
				cont++;
	}
	}
	cpy[cpyi]=0;
	std::string token;
	token =cpy;
return token;
}
//encontrar operadores
bool isoperator(std::string cadena){
	if(cadena=="*"||cadena=="|"||cadena=="."||cadena=="("||cadena==")") return true;
	else return false;
}
//a�adir a vector
std::vector <std::string> anadirvector(std::string text){
	std::string delim = ".";
	std::vector<std::string> words{};

    size_t pos = 0;
    while ((pos = text.find(delim)) != std::string::npos) {
        std::string var = text.substr(0, pos);
        if(var!=""){
		words.push_back(var);
		}
        text.erase(0, pos + delim.length());
    }
    if (!text.empty())
        words.push_back(text.substr(0, pos));
    return words;
}
//mostrarcontenido
void mostrar(std::vector <std::string> n){
	std::cout<<"espacio+";
	for(int i=0;	i<n.size(); i++){
		std::cout<<n.at(i);
		i == (n.size() - 1) ? std::cout<<";"<<std::endl: std::cout<<"+";
	}
	return;
}
void escribircodigo(){
	std::string linea1 = "\tstd::string aux;\n"
    "\tstd::fstream file;\n"
    "\tstd::string word, t, q, filename;\n";
	std::ofstream archivo;
	archivo.open(ubicacion);
	archivo.clear();
	//Lllamando librerias
	archivo<<"#include <regex>\n"
	"#include <fstream>"<<std::endl;
	archivo<<"\n\nvoid ObtieneToken(std::string);"<<std::endl;

	//Abriendo el archivo
	archivo<<"void AbreArchivo (){"<<std::endl;
	archivo<<linea1<<std::endl;
	archivo<<"\tfilename = \"file.txt\";\n"
	"\tfile.open(filename.c_str());\n"
	"\twhile (file >> word){\n"
	"\t\tObtieneToken(word);\n"
	"\t}\n";
	archivo<<"return;"<<std::endl<<"}"<<std::endl;
	archivo<<"void ObtieneToken (std::string aux){"<<std::endl;
	archivo<<"\t//RECONOCIMIENTO DE TOKENS"<<std::endl;
	archivo<<"std::string espacio = \"\";"<<std::endl;
	//escritura de la pila general
	archivo<<"\t//DEFINICIONES GENERALES"<<std::endl;
	escribirPila(general, archivo, true);
	//escritura de la pila regular
	archivo<<"\t//DEFINICIONES REGULARES"<<std::endl;
	escribirPila(regular, archivo, true);
	//escriturab de la pila de validaciones
	archivo<<"\t//VALIDACIONES"<<std::endl;
	escribirPila(validaciones, archivo, false);

	//Creacion de variables regex
	escribirRegex(general, archivo);
	escribirRegex(validaciones, archivo);
	escribirRegex(regular, archivo);

	//While

	for(size_t i = 0; i<contador; i++){
		archivo<<"\t\tbool match"<<i<<" = std::regex_match(aux, "<<"reg"<<i<<");"<<std::endl;
	
	}
	for(size_t i = 0; i<contador; i++){
		if(i == 0){
			archivo<<"\t\tif(match"<<i<<")\n"
			"\t\t\tstd::cout<<aux<<\" es "<<especificacion[i]<<"\"<<std::endl;"<<std::endl;
		}else{
			archivo<<"\t\telse if(match"<<i<<")\n"
			"\t\t\tstd::cout<<aux<<\" es "<<especificacion[i]<<"\"<<std::endl;"<<std::endl;
		}
	}

	archivo<<std::endl<<"}"<<std::endl;
	archivo<<"void CierraArchivo (){"<<std::endl;
	archivo<<"return;"<<std::endl<<"}"<<std::endl;
	archivo.close();
}

void escribirRegex(NodoV *& pila,std::ofstream & archivo){
	int i;
	NodoV* aux = new NodoV();
	NodoV* aux1 = new NodoV();
	aux=NULL;
	aux1=pila;
	while(aux1!=NULL){
		agregarpila(aux, aux1->id, aux1->contenido);
		aux1=aux1->siguiente;
	}
	while(aux!=NULL){
		archivo<<"\tstd::regex reg"<<i<<"("<<aux->id<<");"<<std::endl;
		especificacion.push_back(aux->id);
		aux=aux->siguiente;
		i++;
		contador++;
	}
}

void escribirPila(NodoV *& pila,std::ofstream & archivo, bool validacion){
	NodoV* aux = new NodoV();
	NodoV* aux1 = new NodoV();
	aux=NULL;
	aux1=pila;
	while(aux1!=NULL){
	agregarpila(aux, aux1->id, aux1->contenido);
	aux1=aux1->siguiente;
	}
	while(aux!=NULL){
	archivo<<"\tstd::string "<<aux->id<<" = ";
	
	guardar(archivo,aux->contenido, validacion);
	aux=aux->siguiente;
	}
}
void guardar(std::ofstream & archivo, std::vector <std::string> n, bool validacion){
	if(validacion==true){
	archivo<<"espacio+";
	for(int i=0;	i<n.size(); i++){
		archivo<<n.at(i);
		i == (n.size() - 1) ? archivo<<";"<<std::endl: archivo<<"+";
	}
	}else{
	archivo<<"\"(";
	for(int i=0;	i<n.size(); i++){
		archivo<<n.at(i);
		i == (n.size() - 1) ? archivo<<")\";"<<std::endl: archivo<<"|";
	}
	}
	return;
}
 //color de la letra
 void Color(int Background, int Text){ // Funci�n para cambiar el color del fondo y/o pantalla

 HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

 // Para cambiar el color, se utilizan n�meros desde el 0 hasta el 255.
 // Pero, para convertir los colores a un valor adecuado, se realiza el siguiente c�lculo.
 int    New_Color= Text + (Background * 16);

 SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
}
