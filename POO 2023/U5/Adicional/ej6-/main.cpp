#include <fstream>
#include <iostream>
#include <string>
#include <regex>

using std::getline; using std::ifstream;using std::ofstream;
using std::cout; using std::cin; using std::vector;
using std::endl; using std::string;
using std::regex_replace; using std::regex;

int main(){
    

    string palabra, buscar, reemplazar;

    cout <<"Buscar: ";getline(cin,buscar);

    cout <<"Reemplazar: ";getline(cin,reemplazar);
    
    ifstream arch1("./text.txt");

    vector<string>v;

    while(getline(arch1,palabra)){
        
        string p = regex_replace(palabra,regex(buscar),reemplazar);

        v.push_back(p);

    }

    arch1.close();

    ofstream arch2("./text.txt");

    for(size_t i = 0 ; i < v.size(); ++i){

        arch2 << v[i]<<"\n";
    }

    arch2.close();

    return 0;
}
