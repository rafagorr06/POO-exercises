#include <iostream>
#include <fstream>
#include <sstream>
int main (int argc, char *argv[])
{

    char n[6] = {'m','s','w','1','0'};

    char m[5] = {'2','0','1','6'};

    for(int i = 1; i <= 78; ++i){
        std::stringstream archivo;
        
        archivo <<"design"<<i<<".wds";

        std::ofstream arch1(archivo.str(),std::ios::binary|std::ios::in|std::ios::out);

        arch1.seekp(178);
    
        arch1.write(reinterpret_cast<char*>(&n),sizeof(n));

        arch1.seekp(239);
        
        arch1.write(reinterpret_cast<char*>(&m),sizeof(m));

    }


    return 0;
}
