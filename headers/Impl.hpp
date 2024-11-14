#pragma once

#include <iostream>
#include <vector>
#include "stdbool.h"

class Impl
{
     public:
        int Num;
        int Ind;
        int P;
        bool Pw;
        bool Inf;                                                       //Если имликанта определена в СДНФ
        bool IsValid;                                                   //В случае, если склейка не удалась, возращаем false
        Impl();
        Impl(int, bool);
        Impl(int, int);
        ~Impl();
        static Impl Patch(Impl&, Impl&);                            //Склейка
        void Print();
        int Count(int);
        std::string toFormattedString(int totalVars);                                                 //Расчёт кол-ва единиц в числе N
};