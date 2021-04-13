#include <iostream>
#include <regex>

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
    std::cout<<"Hola mundo"<<std::endl;
	return 0;
}

