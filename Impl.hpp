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
        bool Inf;
        bool IsValid;                                 //В случае, если склейка не удалась, возращаем false
        Impl();
        Impl(int, bool);
        Impl(int, int);
        ~Impl();
        static Impl Patch(Impl&, Impl&);               //Склейка
        void Print();
        int Count(int);                                 //Расчёт кол-ва единиц в числе N
};