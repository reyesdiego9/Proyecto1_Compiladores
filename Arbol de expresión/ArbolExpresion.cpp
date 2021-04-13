#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <ctype.h>
struct NodoA{
	std::string id;
	NodoA *izquierda;
	NodoA *derecha;
};
struct NodoP{
	std::string id;
	NodoP *siguiente;
};
NodoP *siguiente = NULL;
//prototipos de función
NodoA *crearnodo(NodoA*&,std::string);
void insertarnodo(NodoA *&, std::string);
std::vector <std::string> convertircadena (char *);
std::string analisis(std::string);
int jerarquia(std::string);
std::string tokenizar(std::string);
void crearArbol(std::vector <std::string>);
bool isoperator(std::string);
//principal
int main(){
	std::vector <std::string> nuevo;
	std::string expresion = "Letra Underline ( Letra | Digito | UnderLine ) * #";
	expresion = analisis(expresion);
	expresion = tokenizar(expresion);
	char *token, aux[expresion.length()];
	strcpy(aux, expresion.c_str());
	token=strtok(aux, ".");
	while(token){
		std::cout<<"Token: "<<token<<" bool: "<<isoperator(token)<<std::endl;
		nuevo.push_back(token);
		token=strtok(NULL, ".");
	}
	crearArbol(nuevo);
	/*
	std::cout<<"VECTOR RESULTANTE"<<std::endl;
	for(int i = nuevo.size()-1; i>=0; i--){
		std::cout<<"Elemento: "<<nuevo.at(i)<<std::endl;
	}*/
	system("PAUSE");
	return 0;
}

//agregamos le operador para concatenación
std::string analisis(std::string expresion){
	int MAX=1000;
	char aux[expresion.length()], aux1[MAX];
	strcpy(aux,expresion.c_str());
	std::string expresionreducida;
	int cont=0, cont1=0;
	char anterior=0;
	//agregar un simbolo para la concatenación
	while(aux[cont]!=0){
		bool espacio=false;
		bool dalfa=false;
		bool palfa=false;
		bool psigno=false;
		bool par=false;
		bool ppar=false;
		while(aux[cont]==32){
			cont++;
			espacio=true;
		}
		switch(anterior){
			case '*':
			case '|':
			case ')':
				psigno=true;
				break;
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
		anterior = aux[cont];
		cont++;
		cont1++;
	}
	aux1[cont1]=0;
	expresionreducida = aux1;
	return expresionreducida;
}
//agregamos el separador para poder tokenizar expresiones
std::string tokenizar(std::string expresion){
	int max=1000, cont=0, cpyi=0;
	
	char aux[expresion.length()], cpy[max];
	strcpy(aux, expresion.c_str());
	while(aux[cont]!=0){
	bool entry =true;
		switch(aux[cont]){
			case '.':
			case '*':
			case '|':
			case '(':
			case ')':
				cpy[cpyi]='.';
				cpyi++;
				cpy[cpyi]=aux[cont];
				cpyi++;
				cpy[cpyi]='.';
				cpyi++;
				entry=false;
				cont++;
				break;
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
//creación del arbol de expresión
void crearArbol(std::vector <std::string> pila){
	NodoA *Arbol=NULL;
	std::vector <std::string> aux=pila;
	
}
int jerarquia(std::string caracter){
int valor =0;
if(caracter == ")") valor =1; 
if(caracter == "|") valor =2;
if(caracter == ".") valor =3;
if(caracter == "*") valor =4;
if(caracter == "(") valor =5;
return valor;	
}
NodoA *crearnodo(std::string dato){
	NodoA* nuevo_nodo = new NodoA();
	nuevo_nodo->id = dato;
	nuevo_nodo->derecha =NULL;
	nuevo_nodo->izquierda=NULL;
	return nuevo_nodo;
}

void insertarnodo(NodoA *&arbol, std::string dato){
	if(arbol==NULL){
		NodoA *nuevo_nodo = crearnodo (dato);
		arbol=nuevo_nodo;
	}else{
		if(isoperator(dato)){
			char auxiliar[dato.length()];
			strcpy(auxiliar, dato.c_str());
			switch(auxiliar[0]){
				case '*':
					break;
			}
		}
	}
}

bool isoperator(std::string cadena){
	if(cadena=="*"||cadena=="|"||cadena=="."||cadena=="("||cadena==")") return true;
	else return false;
}
/*
std::vector <std::string> convertircadena (char *array){
		char *token;
	    std::vector <std::string> nuevo;
	    nuevo.push_back("^");
		token=NULL;
		token = strtok(array, ",");
	    while(token){
	    	nuevo.push_back(token);
	    	token = strtok(NULL,",");
		}
		nuevo.push_back("^");
	return nuevo;
 }*/
