#pragma once

#include <iostream>
#include <vector>
#include "DNF.hpp"
#include "Impl.hpp"

class Cover_table
{
    public:
    std::vector<Impl> sdnf;
    std::vector<Impl> tdnf;
    std::vector<std::vector<bool>> table;
    
    Cover_table(DNF&, DNF&);
    ~Cover_table();
    void buildTable();
    void printTable();
    void minimize();
};