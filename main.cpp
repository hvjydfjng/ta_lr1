#include "main.hpp"



int main(){
    //Чтение СДНФ из файла
    std::ifstream input_file("scale.txt");
    std::ofstream output_file("mdnf.txt");
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
    DNF sdnf(line);
    function.Print();
    std::cout<<"********************************"<<std::endl;
    function.Minimize(function);
    function.Print();
    Cover_table result(function, sdnf);
    std::cout<<"********************************"<<std::endl;
    result.printTable();
    std::cout<<"********************************"<<std::endl;
    result.minimize();
    result.printTable();
    for (int i = 0; i < result.tdnf.size(); i++)
    {
        result.tdnf[i].Print();
    }

    for (int i = 0; i < result.tdnf.size(); i++)
    {
        output_file<<result.tdnf[i].toFormattedString(4)<<std::endl;
    }
    return 0;
}