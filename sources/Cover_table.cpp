#include "Cover_table.hpp"

Cover_table::Cover_table(DNF& TDNF, DNF& SDNF){
    Cover_table::sdnf = SDNF.Data;
    Cover_table::tdnf = TDNF.Data;
    buildTable();
}

Cover_table::~Cover_table(){
    
}

void Cover_table::buildTable(){
    table.resize(tdnf.size(), std::vector<bool>(sdnf.size(), false));       //Задаём размер таблицы по импликантам
    for (int i = 0; i < tdnf.size(); i++)                                   //Заполняем таблицу
    {
        for(int j =0; j < sdnf.size(); j++){
            if (sdnf[j].Inf == true)
            {
                if ( (sdnf[j].Num & ~tdnf[i].P) == tdnf[i].Num)
                {
                    table[i][j] = true;
                }
            }            
        }
    }
}

void Cover_table::printTable(){
    std::cout<<"Implicant Cover Table:\n";
    for (int i = 0; i < tdnf.size(); i++)
    {
        for (int j = 0; j < sdnf.size(); j++)
        {
            std::cout<<(table[i][j] ? "+":"-") << " ";
        }
        std::cout<<std::endl;
    }
}
void Cover_table::minimize() {
    // Выполняем цикл, пока есть строки для проверки
    bool hasChanges = true;

    while (hasChanges) {
        hasChanges = false; // Сбрасываем флаг изменений

        // Проходим по каждой строке (импликанты ТДНФ)
        for (int i = 0; i < tdnf.size(); i++) {
            bool canExcludeCurrentRow = true; // Изначально предполагаем, что строку можно исключить

            // Проверяем каждый столбец в текущей строке
            for (int j = 0; j < sdnf.size(); j++) {
                if (table[i][j]) { // Если в строке есть знак "+"
                    bool isCoveredByOthers = false;

                    // Проверяем, покрывается ли этот столбец другими строками
                    for (int k = 0; k < tdnf.size(); k++) {
                        if (k != i && table[k][j]) { // Если другая строка также покрывает этот столбец
                            isCoveredByOthers = true;
                            break; // Достаточно найти хотя бы одну строку, которая покрывает этот столбец
                        }
                    }

                    // Если хотя бы один столбец не покрывается другими строками, строку нельзя исключить
                    if (!isCoveredByOthers) {
                        canExcludeCurrentRow = false; // Строку нельзя исключить
                        break; // Выходим из внутреннего цикла
                    }
                }
            }

            // Если строка может быть исключена (покрыта другими), удаляем её
            if (canExcludeCurrentRow) {
                tdnf.erase(tdnf.begin() + i); // Удаление импликанты ТДНФ
                table.erase(table.begin() + i); // Удаление строки таблицы
                hasChanges = true; // Фиксируем, что было сделано изменение
                break; // Прерываем цикл, чтобы начать проверку с первой строки
            }
        }
    }
}


