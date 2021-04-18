#include <regex>

std::string espacio = " ";
std::string OperadorLogico = espacio+"("+"[<]"+"|"+"[>]"+"|"+"[=][=]"+"|"+"[<][=]"+"|"+"[=][>]"+"|"+"[!][=]"+")";
std::string OperdorBinario = espacio+"("+"[+]"+"|"+"[-]"+"|"+"[*]"+"|"+"[/]"+")";
std::string NumeroFlotante = espacio+Numero+Punto+Numero;
std::string Numero = espacio+Digito+Digito+"*";
std::string $Identificador = espacio+Letra+"("+Letra+"|"+Digito+"|"+UnderLine+")"+"*";
std::string ParentesisDer = espacio+"[)]";
std::string ParentesisIzq = espacio+"[(]";
std::string Punto = espacio+"[.]";
std::string BracketDer = espacio+"[]]";
std::string BracketIzq = espacio+"[[]";
std::string Digito = espacio+"[0-9]";
std::string UnderLine = espacio+"[_]";
std::string Letra = espacio+"[a-zA-Z]";


void identificarPalabras(){
    std::string aux;
}