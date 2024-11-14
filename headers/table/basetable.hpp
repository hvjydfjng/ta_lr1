// basetable.hpp
#ifndef BASETABLE_HPP
#define BASETABLE_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip> // Для std::setw

class BaseTable {
protected:
    std::vector<std::vector<int>> data;

public:
    virtual ~BaseTable() = default;
    
    // Общий метод для загрузки данных
    void loadFromFile(const std::string& filename);
    void print();
    // Метод для доступа к данным
    const std::vector<std::vector<int>>& getData() const { return data; }
};

#endif // BASETABLE_HPP
