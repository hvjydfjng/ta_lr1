#ifndef AUTOMAT_HPP
#define AUTOMAT_HPP

#include "transitiontable.hpp"  // Подключение таблицы переходов
#include "outputtable.hpp"      // Подключение таблицы состояний
#include <cmath>                // Для округления
#include <string>
#include <vector>

class Automat {
public:
    TransitionTable transitionTable;  // Таблица переходов
    OutputTable outputTable;          // Таблица выходов
    int numTriggers;                  // Количество триггеров (битов)
    int numOutputs;                   // Количество выходов

    // Атрибуты для хранения СДНФ триггеров и выходов
    std::vector<std::string> trig_dnf;
    std::vector<std::string> out_dnf;

    // Преобразование числа в двоичную строку фиксированной длины
    std::string toBinary(int num, int bits);

    // Конструктор, принимающий таблицу переходов и таблицу выходов
    Automat(TransitionTable& tt, OutputTable& ot);

    // Метод для построения СДНФ для триггеров или выходов
    void generateSDNF(const BaseTable& table, int numItems, std::vector<std::string>& dnfStorage);
    void printSDNF(const std::string& itemName, const std::vector<std::string>& dnfStorage);
};

#endif // AUTOMAT_HPP
