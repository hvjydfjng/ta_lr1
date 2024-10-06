#include "Impl.hpp"

Impl::Impl(){
    Num = 0;
    Ind = Count(0);
    P = 0;
    Pw = false;
    Inf = false;
    IsValid = false;

}

Impl::Impl(int impl_number, bool defined){
    Num = impl_number;
    Ind = Count(impl_number);
    P = 0;
    Pw = false;
    Inf = defined;
    IsValid = true;
}

Impl::Impl(int impl_number, int p){
    Num = impl_number;
    Ind = Count(impl_number);
    P = p;
    Pw = false;
    Inf = true;
    IsValid = true;
}

Impl::~Impl(){

}

int Impl::Count(int impl_number){                      //Расчёт кол-ва единиц в числе N
        int count = 0;
        while (impl_number>0)
    {
        if(impl_number & 1){
            count++;
        }
        impl_number = impl_number>>1;
    }
    return count;
}

void Impl::Print() {
    std::cout << "Impl Data: " << std::endl;
    std::cout << "Num: " << Num << std::endl;
    std::cout << "Ind (count of ones): " << Ind << std::endl;
    std::cout << "P: " << P << std::endl;
    std::cout << "Pw: " << (Pw ? "true" : "false") << std::endl;
    std::cout << "Inf: " << (Inf ? "true" : "false") << std::endl;
    std::cout << "IsValid: " << (Inf ? "true" : "false") << std::endl;
}

Impl Impl::Patch(Impl &A, Impl &B) {
    // Условия склейки
    if ((A.Num < B.Num) && (A.P == B.P) && ((B.Ind - A.Ind) == 1) && (A.Count(B.Num - A.Num) == 1)) {
        A.Pw = true;
        B.Pw = true;
        Impl C(A.Num, B.Num - A.Num);
        return C;
    }
    
    // Если склейка невозможна
    Impl invalidImpl;
    return invalidImpl;
}


