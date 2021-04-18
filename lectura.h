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
	//DEFINICIONES REGULARES
	std::string $Identificador = espacio+Letra+"("+Letra+"|"+Digito+"|"+UnderLine+")"+"*";
	std::string NumeroEntero = espacio+Digito+Digito+"*";
	std::string Punto = espacio+"[+]";
	std::string NumeroFlotante = espacio+Numero+Punto+Numero;
	std::string ParentesisIzq = espacio+"[(]";
	std::string ParentesisDer = espacio+"[)]";
	std::string BracketIzq = espacio+"[[]";
	std::string BracketDer = espacio+"[]]";
	std::string OperdorBinario = espacio+"("+"[+]"+"|"+"[-]"+"|"+"[*]"+"|"+"[/]"+")";
	std::string OperadorLogico = espacio+"("+"[<]"+"|"+"[>]"+"|"+"[=][=]"+"|"+"[<][=]"+"|"+"[=][>]"+"|"+"[!][=]"+")";
	//VALIDACIONES
	std::string reservadas = "(IF|THEN|ELSE|BEGIN|END|FOR|REPEAT|WHILE|VARIABLE|CONST|PROGRAM|INCLUDE|UNTIL|FOREACH|SPLIT|CASE|SWITCH)";
	std::string ComI = "([/][*]|[(][*])";
	std::string ComF = "([*][/]|[*][)])";
	std::string ComL = "([-][-])";
	std::regex reg0(Letra);
	std::regex reg1(UnderLine);
	std::regex reg2(Digito);
	std::regex reg3(reservadas);
	std::regex reg4(ComI);
	std::regex reg5(ComF);
	std::regex reg6(ComL);
	std::regex reg7($Identificador);
	std::regex reg8(NumeroEntero);
	std::regex reg9(Punto);
	std::regex reg10(NumeroFlotante);
	std::regex reg11(ParentesisIzq);
	std::regex reg12(ParentesisDer);
	std::regex reg13(BracketIzq);
	std::regex reg14(BracketDer);
	std::regex reg15(OperdorBinario);
	std::regex reg16(OperadorLogico);
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
		bool match11 = std::regex_match(aux, reg11);
		bool match12 = std::regex_match(aux, reg12);
		bool match13 = std::regex_match(aux, reg13);
		bool match14 = std::regex_match(aux, reg14);
		bool match15 = std::regex_match(aux, reg15);
		bool match16 = std::regex_match(aux, reg16);
		if(match0)
			std::cout<<aux<<" es Letra"<<std::endl;
		else if(match1)
			std::cout<<aux<<" es UnderLine"<<std::endl;
		else if(match2)
			std::cout<<aux<<" es Digito"<<std::endl;
		else if(match3)
			std::cout<<aux<<" es reservadas"<<std::endl;
		else if(match4)
			std::cout<<aux<<" es ComI"<<std::endl;
		else if(match5)
			std::cout<<aux<<" es ComF"<<std::endl;
		else if(match6)
			std::cout<<aux<<" es ComL"<<std::endl;
		else if(match7)
			std::cout<<aux<<" es $Identificador"<<std::endl;
		else if(match8)
			std::cout<<aux<<" es NumeroEntero"<<std::endl;
		else if(match9)
			std::cout<<aux<<" es Punto"<<std::endl;
		else if(match10)
			std::cout<<aux<<" es NumeroFlotante"<<std::endl;
		else if(match11)
			std::cout<<aux<<" es ParentesisIzq"<<std::endl;
		else if(match12)
			std::cout<<aux<<" es ParentesisDer"<<std::endl;
		else if(match13)
			std::cout<<aux<<" es BracketIzq"<<std::endl;
		else if(match14)
			std::cout<<aux<<" es BracketDer"<<std::endl;
		else if(match15)
			std::cout<<aux<<" es OperdorBinario"<<std::endl;
		else if(match16)
			std::cout<<aux<<" es OperadorLogico"<<std::endl;

}
void CierraArchivo (){
return;
}
