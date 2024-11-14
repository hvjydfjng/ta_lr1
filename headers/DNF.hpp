#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Impl.hpp"

class DNF
{  
    public:
        std::vector<Impl> Data;
        DNF(std::string);
        ~DNF();

        void Minimize(DNF&);
        void Print();
        Impl& GetImpl(int);
};