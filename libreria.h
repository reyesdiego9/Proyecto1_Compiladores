#include <regex>
#include <fstream>


void ObtieneToken(std::string);
void AbreArchivo (){
	std::string aux;
	std::fstream file;
	std::string word, t, q, filename;

	filename = "file.txt";
	file.open(filename.c_str());
	while (file >> word){
		ObtieneToken(word);
	}
return;
}
void ObtieneToken (std::string aux){
	//RECONOCIMIENTO DE TOKENS
std::string espacio = "";
	//DEFINICIONES GENERALES
	std::string Letra = espacio+"[a-zA-Z]";
	std::string UnderLine = espacio+"[_]";
	std::string Digito = espacio+"[0-9]";
	std::string BracketIzq = espacio+"[[]";
	std::string BracketDer = espacio+"[]]";
	std::string Punto = espacio+"[.]";
	//DEFINICIONES REGULARES
	std::string ParentesisIzq = espacio+"[(]";
	std::string ParentesisDer = espacio+"[)]";
	std::string $Identificador = espacio+Letra+"("+Letra+"|"+Digito+"|"+UnderLine+")"+"*";
	std::string Numero = espacio+Digito+Digito+"*";
	std::string NumeroFlotante = espacio+Numero+Punto+Numero;
	std::string OperdorBinario = espacio+"("+"[+]"+"|"+"[-]"+"|"+"[*]"+"|"+"[/]"+")";
	std::string OperadorLogico = espacio+"("+"[<]"+"|"+"[>]"+"|"+"[=][=]"+"|"+"[<][=]"+"|"+"[=][>]"+"|"+"[!][=]"+")";
	//VALIDACIONES
	std::string reservadas = "(IF|THEN|ELSE|BEGIN|END|FOR|REPEAT|WHILE|VARIABLE|CONST|PROGRAM|INCLUDE|UNTIL|FOREACH|SPLIT|CASE|SWITCH)";
	std::string ComI = "([/][*]|[(][*])";
	std::string ComF = "([*][/]|[*][)])";
	std::string ComL = "([-][-])";
	std::regex reg0(ParentesisIzq);
	std::regex reg1(ParentesisDer);
	std::regex reg2($Identificador);
	std::regex reg3(Numero);
	std::regex reg4(NumeroFlotante);
	std::regex reg5(OperdorBinario);
	std::regex reg6(OperadorLogico);
	std::regex reg7(reservadas);
	std::regex reg8(ComI);
	std::regex reg9(ComF);
	std::regex reg10(ComL);
		bool match0 = std::regex_match(aux, reg0);
		bool match1 = std::regex_match(aux, reg1);
		bool match2 = std::regex_match(aux, reg2);
		bool match3 = std::regex_match(aux, reg3);
		bool match4 = std::regex_match(aux, reg4);
		bool match5 = std::regex_match(aux, reg5);
		bool match6 = std::regex_match(aux, reg6);
		bool match7 = std::regex_match(aux, reg7);
		bool match8 = std::regex_match(aux, reg8);
		bool match9 = std::regex_match(aux, reg9);
		bool match10 = std::regex_match(aux, reg10);
		if(match0)
			std::cout<<aux<<" es ParentesisIzq"<<std::endl;
		if(match1)
			std::cout<<aux<<" es ParentesisDer"<<std::endl;
		if(match2)
			std::cout<<aux<<" es $Identificador"<<std::endl;
		if(match3)
			std::cout<<aux<<" es Numero"<<std::endl;
		if(match4)
			std::cout<<aux<<" es NumeroFlotante"<<std::endl;
		if(match5)
			std::cout<<aux<<" es OperdorBinario"<<std::endl;
		if(match6)
			std::cout<<aux<<" es OperadorLogico"<<std::endl;
		if(match7)
			std::cout<<aux<<" es reservadas"<<std::endl;
		if(match8)
			std::cout<<aux<<" es ComI"<<std::endl;
		if(match9)
			std::cout<<aux<<" es ComF"<<std::endl;
		if(match10)
			std::cout<<aux<<" es ComL"<<std::endl;

}
void CierraArchivo (){
return;
}
