#include "automat.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

// Преобразование числа в двоичную строку фиксированной длины
std::string Automat::toBinary(int num, int bits) {
    std::string binary;
    for (int i = bits - 1; i >= 0; --i) {
        binary += (num & (1 << i)) ? '1' : '0';
    }
    return binary;
}

// Конструктор
Automat::Automat(TransitionTable& tt, OutputTable& ot)
    : transitionTable(tt), outputTable(ot) {
    
    int maxState = 0;
    for (const auto& row : transitionTable.getData()) {
        for (int state : row) {
            if (state != -1) {
                maxState = std::max(maxState, state);
            }
        }
    }
    numTriggers = std::ceil(std::log2(maxState));

    int maxOutput = 0;
    for (const auto& row : outputTable.getData()) {
        for (int output : row) {
            if (output != -1) {
                maxOutput = std::max(maxOutput, output);
            }
        }
    }
    numOutputs = maxOutput;

    // Инициализация векторов для хранения СДНФ
    trig_dnf.resize(numTriggers);
    out_dnf.resize(numOutputs);
}

// Метод для генерации СДНФ
void Automat::generateSDNF(const BaseTable& table, int numItems, std::vector<std::string>& dnfStorage) {
    int numInputs = table.getData().size();    // Количество входов
    int numStates = table.getData()[0].size(); // Количество состояний

    // Перебираем элементы (по количеству бит в состоянии или выходе)
    for (int item = 0; item < numItems; ++item) {
        std::string itemSDNF;  // Строка для хранения СДНФ текущего элемента

        // Перебираем все входы и состояния
        for (int input = 0; input < numInputs; ++input) {
            for (int currentState = 0; currentState < numStates; ++currentState) {
                int nextItem = table.getData()[input][currentState];
                if (nextItem == -1) continue;  // Пропускаем недостающие состояния

                // Корректируем состояние (уменьшаем на 1, чтобы начать с 0)
                int adjustedNextItem = nextItem - 1;
                int adjustedCurrentState = currentState;

                // Получаем двоичные представления
                std::string currentStateBin = toBinary(adjustedCurrentState, numItems);
                std::string inputBin = toBinary(input, std::ceil(std::log2(numInputs)));
                std::string nextItemBin = toBinary(adjustedNextItem, numItems);
                std::cout<<nextItemBin<<"\t"<<currentState<<"\t"<<inputBin<<"\t"<<item<<std::endl;
                // Проверка активации текущего item в следующем состоянии
                if (nextItemBin[numItems - item - 1] == '1') {
                    // Формируем импликанту: номер строки + номер столбца
                    std::string implicant = inputBin + currentStateBin;
                    std::cout<<"YES"<<std::endl;
                    // Добавляем импликанту в СДНФ текущего элемента
                    if (!itemSDNF.empty()) itemSDNF += " ";
                    itemSDNF += implicant;
                }
            }
        }

        // Сохраняем полученную СДНФ для текущего элемента в dnfStorage
        dnfStorage[item] = itemSDNF;
    }
}

void Automat::printSDNF(const std::string& itemName, const std::vector<std::string>& dnfStorage) {
    for (size_t i = 0; i < dnfStorage.size(); ++i) {
        std::cout << "SDNF for " << itemName << i << ": ";
        if (!dnfStorage[i].empty()) {
            std::cout << dnfStorage[i];
        } else {
            std::cout << "No terms for this item.";
        }
        std::cout << std::endl;
    }
}
