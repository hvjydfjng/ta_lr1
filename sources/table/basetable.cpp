// basetable.cpp
#include "basetable.hpp"

void BaseTable::loadFromFile(const std::string& filename){
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file: " + filename);
        }

        std::string line;
        while (std::getline(file, line)) {
            std::vector<int> row;
            std::istringstream iss(line);
            std::string value;

            while (iss >> value) {
                if (value == "-") {
                    row.push_back(-1); // -1 означает неопределенное состояние
                } else {
                    row.push_back(std::stoi(value));
                }
            }
            data.push_back(row);
        }
        file.close();
};
void BaseTable::print() {
    for (const auto& row : this->getData()) {
        for (int value : row) {
            // Если значение -1, выводим " - " для красивого вывода
            if (value == -1) {
                std::cout << " - "; // Выводим с тремя символами для выравнивания
            } else {
                std::cout << std::setw(2) << value << " "; // Выравнивание на 2 символа
            }
        }
        std::cout << std::endl;
    }
}