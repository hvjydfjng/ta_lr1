#include "DNF.hpp"

DNF::DNF(std::string input_data){
    for (size_t i = 0; i < input_data.length(); i++)    
    {
        if(input_data[i] == '1'){
            Data.push_back(Impl(i,true));
        }
        if(input_data[i] == '-'){
            Data.push_back(Impl(i,false));
        }
    }
}

DNF::~DNF(){

}

void DNF::Minimize(DNF& TargetDNF){
    int start_size;                                                                                                         //Запоминаем стартовые импликанты 
    bool NotPatched = true;
    while (NotPatched == true)
    {
        NotPatched = false;
        start_size = TargetDNF.Data.size();
        for(int i = 0; i < start_size; i++)                                                                                 //Перебор всех изначальных импликант
        {
            for (int j = 0; j < start_size; j++)
            {
                Impl Patched_Impl = TargetDNF.Data[i].Patch(TargetDNF.Data[i], TargetDNF.Data[j]);        
                if (Patched_Impl.IsValid == true)
                {
                    TargetDNF.Data.push_back(Patched_Impl);
                }
            } 
        }
        for (auto it = TargetDNF.Data.begin(); it != TargetDNF.Data.end(); )                                            //Удаляем склеенные импликанты
        {
            if (it->Pw == true) {
                NotPatched = true;
                it = TargetDNF.Data.erase(it);                                                                              // erase возвращает новый корректный итератор
            } else {
                ++it;                                                                                                         // Увеличиваем итератор только если не удаляем элемент
            }
        }       
    }
}

void DNF::Print() {
    for (int i = 0; i < Data.size(); i++)
    {
        Data[i].Print();
    }
    
}
Impl& GetImpl(int);