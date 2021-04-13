#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <stdlib.h>
#include <vector>
//pila
struct NodoV{
	std::vector <std::string> guardado;
	std::vector <std::string> contenido;
	NodoV *siguiente;
};
//arbol de expresión
struct NodoE{
	std::string id;
	std::vector <std::string> primeraPos;
	std::vector <std::string> ultimaPos;
	NodoE *izquierda;
	NodoE *derecha;
};
//Prototipos de función
void abrir_documento(std::string direccion);
void gotoxy(int, int);
//pilas
NodoV *general = NULL;
//arbol
NodoE *Raiz = NULL;
//Menú principal
int main ()
{
std::string direccion;
system("cls");
gotoxy(20,4);std::cout<<"CREACION DE LIBRERIA PARA ANALIZADOR LEXICO: ";
getline(std::cin, direccion);
abrir_documento(direccion);
return 0;
}
//apertura del documento
void abrir_documento(std::string dir){
	std:: string bracket;
	std::ifstream archivo1, archivo;
	char /*direccion[dir.length()]*/ text;
	int numero;
	//strcpy(direccion, dir.c_str());
	archivo.open("C:\\Users\\jordi\\Desktop\\Compiladores\\Archivos prueba\\DefinicionRegular.txt", std::ios::in);
	if(archivo.fail()){
		std::cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	while(!archivo.eof()){
		getline(archivo, bracket);
		std::cout<<bracket<<std::endl;
		//ESPECIFICACIONES GENERALES
		if(bracket=="[%%]"){
			std::cout<<"ESPECIFICACIONES GENERALES"<<std::endl;
			bool aux_salida = true;
			getline(archivo, bracket);
			while(aux_salida){
			
				if(bracket=="[%%]") break;	
				std::string nombre; 
				char aux[bracket.length()];
				char aux_name[200];
				char aux_cont[200];
				strcpy(aux, bracket.c_str());
				//std::cout<<aux<<std::endl;
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
				std::cout<<"         NOMBRE DE LA ESPECIFICACION       "<<std::endl;
				std::cout<<"-------->"<<aux_name<<"<-------"<<std::endl;
				//Variable contenido tiene la memoria de que parte del vector he analizado
				std::cout<<"---------------CONTENIDO--------------------"<<std::endl;
				while (aux[contenido]==32) contenido++;
				if(aux[contenido]=='['){
					contenido++;
					while(aux[contenido]!=']'){
						(aux[contenido]==',') ? contenido++:contenido;
						char aux_c;
						int primero, segundo;
						primero = aux[contenido];
						contenido++;
						contenido++;
						segundo = aux[contenido];
						while(segundo>=primero){
							aux_c=primero;
							std::cout<<aux_c<<"<- digito guardado"<<std::endl;
							primero++;  
						}
						contenido++;
					}
				}
				
				if(aux[contenido]==39){
					contenido++;
					(aux[contenido]==32) ? contenido++ : contenido;
					while(aux[contenido]!=39){
						char auxiliar;
						auxiliar = aux[contenido];
						std::cout<<auxiliar<<"<- digito guardado"<<std::endl;
						contenido++;
					}
				}
				getline(archivo,bracket);
			}
		std::cout<<"salio de esta mierda "<<std::endl;
		}
		//EXPRECIONES REGULARES
		if(bracket=="[%%]"){
			std::cout<<"ESPECIFICACIONES REGULARES"<<std::endl;
			getline(archivo, bracket);
			bool aux_salida = true;
			while(aux_salida){
				if(bracket=="[&&]") break;	
				std::string nombre; 
				char aux[bracket.length()];
				char aux_name[200];
				char aux_cont[200];
				strcpy(aux, bracket.c_str());
				//std::cout<<aux<<std::endl;
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
				std::cout<<"         NOMBRE DE LA ESPECIFICACION       "<<std::endl;
				std::cout<<"-------->"<<aux_name<<"<-------"<<std::endl;
				//Variable contenido tiene la memoria de que parte del vector he analizado
				std::cout<<"---------------CONTENIDO--------------------"<<std::endl;
				while (aux[contenido]==32) contenido++;
				if(aux[contenido]==39){
					contenido++;
					(aux[contenido]==32) ? contenido++ : contenido;
					while(aux[contenido]!=39){
						char auxiliar;
						auxiliar = aux[contenido];
						std::cout<<auxiliar<<"<- digito guardado"<<std::endl;
						contenido++;
					}
				}
				getline(archivo, bracket);
			}
		}
		//VALIDACIONES
		if(bracket=="[&&]"){
			std::cout<<"VALIDACIONES"<<std::endl;
			getline(archivo, bracket);
			bool aux_salida = true;
			while(aux_salida){
				if(bracket=="[&&]") break;	
				std::string nombre; 
				char aux[bracket.length()];
				char aux_name[200];
				char aux_cont[200];
				strcpy(aux, bracket.c_str());
				//std::cout<<aux<<std::endl;
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
				std::cout<<"         NOMBRE DE LA ESPECIFICACION       "<<std::endl;
				std::cout<<"-------->"<<aux_name<<"<-------"<<std::endl;
				//Variable contenido tiene la memoria de que parte del vector he analizado
				std::cout<<"---------------CONTENIDO--------------------"<<std::endl;
				while (aux[contenido]==32) contenido++;
				std::string validar_nombre = aux_name;
				if(validar_nombre=="Reservadas"){
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
							std::cout<<palabra<<"<- Palabra reservada de ->"<<id<<std::endl;
							}	
						contenido++;
						while (aux[contenido]==32||aux[contenido]==44) contenido++;
						}
					}	
				}
				//para validación de los comentarios
				if(validar_nombre=="ComI"||validar_nombre=="ComF"||validar_nombre=="ComL"){
					if(aux[contenido]=='['){
						contenido++;
						bool salida=true;
						while(salida){
							char comentario[200];
							int contador=0;
							while(aux[contenido]!=44 && aux[contenido]!=93){
								while(aux[contenido]==32) contenido++;
								comentario[contador]=aux[contenido];
								contador++;
								contenido++;
								
							}
							comentario[contador]=0;
							std::cout<<validar_nombre<<": "<<comentario<<std::endl;
							if(aux[contenido]==']') break;
							contenido++;
						}	
					}
				}
				
				getline(archivo, bracket);
			}
		}
		//numero = ascii(text);
		/*if(comp('[', text)){
			archivo.get(text);
			if(comp('%', text)){
				archivo.get(text);
				if(comp('%',text)){
					archivo.get(text);
					if(comp(']', text)){
						//primera lectura de braquets para especificaciones generales
						std::cout<<"ESPECIFICACIONES GENERALES"<<std::endl;
						std::string nombre, aux;
						bool salida=false;
						archivo.get(text);
						while(salida==false){
							if(text==10) getline(archivo, bracket, ' ');
							if(bracket=="[%%]"){
								salida=true;
							}
							std::cout<<"-"<<bracket<<"-"<<std::endl;
							nombre = bracket;
							archivo.get(text);
							while(text!=10){
							if(comp(text,32)) archivo.get(text);
							if(comp(text,':')){
								archivo.get(text);
								if(comp(text,32)) archivo.get(text);
								if(comp(text,'=')){
									archivo.get(text);
									if(comp(text,32)) archivo.get(text);
									if(comp(text,'[')){
										archivo.get(text);
										if(comp(text,32)) archivo.get(text);
										while(text!=']'){
										if(comp(text,',')) archivo.get(text);
										char aux;
										int primero, segundo;
										primero = text;
										archivo.get(text);
										archivo.get(text);
										segundo =text;
										while(segundo>=primero){
										aux=primero;
										std::cout<<aux<<"<- digito guardado"<<std::endl;
										primero++;  
										}
										archivo.get(text);	
										}
										
									}
									if(comp(text,39)){
										archivo.get(text);
										if(comp(text,32)) archivo.get(text);
										while(text!=39){
											char aux;
											aux=text;
											std::cout<<aux<<"<- digito guardado"<<std::endl;
											archivo.get(text);
										}
									}
								}
							}
							//especificación definida por rango
							
							archivo.get(text);
							}
						}
						//leer nombre de la especificación
					}
				}
			}
		}*/
		/*break;
		if(bracket=="[%%]"){
			std::cout<<"ESPECIFICACIONES REGULARES"<<std::endl;
						std::string nombre;
						bool salida=false;
						archivo.get(text);
						while(salida==false){
							getline(archivo, bracket, ' ');
							if(bracket=="[&&]"){
								salida=true;
							}
							std::cout<<"-"<<bracket<<"-"<<std::endl;
							nombre = bracket;
							archivo.get(text);
							while(text!=10){
							std::cout<<text<<std::endl;
							archivo.get(text);
							}
							if(text==10) text='.';
						}
		}*/
		/*if(comp('[', text)){
			archivo.get(text);
			if(comp('%', text)){
				archivo.get(text);
				if(comp('%',text)){
					archivo.get(text);
					if(comp(']', text)){
						//segunda lectura de braquets para especificaciones regulares
						std::cout<<"ESPECIFICACIONES REGULARES";
					}
				}
			}
		}
		if(comp('[', text)){
			archivo.get(text);
			if(comp('&', text)){
				archivo.get(text);
				if(comp('&',text)){
					archivo.get(text);
					if(comp(']', text)){
						//tercera lectura de brackets para validaciones
						std::cout<<"VALIDACIONES";
					}
				}
			}
		}
		if(comp('[', text)){
			archivo.get(text);
			if(comp('&', text)){
				archivo.get(text);
				if(comp('&',text)){
					archivo.get(text);
					if(comp(']', text)){
						//cuarta lectura de brackets para finalización de lectura
						std::cout<<"EOF";
					}
				}
			}
		}*/
	}
	archivo.close();
}
//función de posicionamiento
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
//conversión de array a cadena
 std::vector <std::string> convertir (char *array){
		char *token;
	    std::vector <std::string> nuevo;
		token=NULL;
		token = strtok(array, ",");
	    while(token){
	    	nuevo.push_back(token);
	    	token = strtok(NULL,",");
		}
	return nuevo;
 }
