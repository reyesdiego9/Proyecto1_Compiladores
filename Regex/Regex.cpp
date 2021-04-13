#include <iostream>
#include <regex>

void PrintMatches(std::string str,
        std::regex reg){
    
    // Used when your searching a string
    std::smatch matches;
    
    // Show true and false in output
    std::cout << std::boolalpha;
       
    // Determines if there is a match and match 
    // results are returned in matches
    while(std::regex_search(str, matches, reg)){
        std::cout << "Checked for Results : " << 
                matches.ready() << "\n";
        
        std::cout << "Are there no matches : " << 
                matches.empty() << "\n";
        
        std::cout << "Number of matches : " << 
                matches.size() << "\n";
        
        // Get the first match
        std::cout << matches.str(1) << "\n";
        
        // Eliminate the previous match and create
        // a new string to search
        str = matches.suffix().str();
        
        std::cout << "\n";
    }
}

void PrintMatches2(std::string str, std::regex reg){
    
    // This holds the first match
    std::sregex_iterator currentMatch(str.begin(),
            str.end(), reg);
    
    // Used to determine if there are any more matches
    std::sregex_iterator lastMatch;
    
    // While the current match doesn't equal the last
    while(currentMatch != lastMatch){
        std::smatch match = *currentMatch;
        std::cout << match.str() << "\n";
        currentMatch++;
    }
    std::cout << std::endl;
    
}

int main(void){
	std::string str2 = "982";
	std::string aux;
	std::string letra="([a-z]|[A-Z])";
	std::string Digito="[0-9]";
	std::string Underline= "[_]";
	std::string regs = letra +"("+letra+"|"+Digito+"|"+Underline+")*";
	std::string numero = Digito + Digito+"*";
	std::string flotante = numero+ "[.]" + numero;
	std::string operadorb = "([+]|[-]|[*]|[/])";
	std::string operadorl = "(<|>|==|<=|=>|!=)";
	std::regex reg(regs);
    std::regex reg2 (numero);
	std::regex reg3(flotante);
    std::regex reg4 (operadorb);
	std::regex reg5(operadorl);
	std::cout<<flotante<<std::endl;
	while(true){
		std::cin>>aux;
		bool match  = regex_match(aux,reg);
		bool match2 = regex_match(aux,reg2);
		bool match3 = regex_match(aux,reg3);
		bool match4 = regex_match(aux,reg4);
		bool match5 = regex_match(aux,reg5);
		//std::cout<<(match2? "match": "no match")<<std::endl;
		if(match){
			std::cout<<"$Identificador"<<std::endl;
		}
		if(match2){
			std::cout<<"Numero"<<std::endl;
		}
		if(match3){
			std::cout<<"Float"<<std::endl;
		}
		if(match4){
			std::cout<<"Operador Binario"<<std::endl;
		}
		if(match5){
			std::cout<<"Operador Logico"<<std::endl;
		}
	}
    //PrintMatches2(str2,reg2);
    std::cout<<"finalizo"<<std::endl;
	return 0;
}

