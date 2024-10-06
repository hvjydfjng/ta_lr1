#include "main.hpp"

int main(){
    //Чтение СДНФ из файла
    std::ifstream input_file("scale.txt");
    if(!input_file.is_open()){
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    std::string line;
    if(std::getline(input_file, line)){
        std::cout<<"Readed line:"<<line<<std::endl;
    }
    input_file.close();
    //Обработка для получения номеров и инициализации СДНФ
    DNF function(line);
    function.Print();
    std::cout<<"********************************"<<std::endl;
    function.Minimize(function);
    function.Print();
    return 0;
}