#include "main.hpp"



int main(){
    TransitionTable tt;
    OutputTable ot;
    tt.loadFromFile("f_table.txt"); // Загружаем таблицу переходов из файла
    ot.loadFromFile("g_table.txt");
    Automat automat(tt,ot);
    automat.generateSDNF(tt,automat.numTriggers,automat.trig_dnf); // Генерация и вывод СДНФ для всех триггеров
    automat.generateSDNF(ot,automat.numOutputs,automat.out_dnf); // Генерация и вывод СДНФ для всех триггеровS
    // Вывод СДНФ для триггеров
    automat.printSDNF("D", automat.trig_dnf);
    std::cout<<"**********************"<<std::endl;
    // Вывод СДНФ для выходов
    automat.printSDNF("Y", automat.out_dnf);
    std::cout<<automat.numOutputs<<std::endl;
    return 0;
}