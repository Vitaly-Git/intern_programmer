// Задание 1
//
// 1. На языке С/С++, написать алгоритм (функцию) определения четности целого числа,
//    который будет аналогичен нижеприведенному по функциональности, но отличен по своей сути.
//
// 2. Объяснить плюсы и минусы обеих реализаций.

// Решение
//
// 1. Функция isEvenNewV1 проверяет на четность через особенность деления целых чисел, 
//    и получения разницы между исходным числом удвоенным результатом деления.
// 2. Функция isEvenNewV2 проверяет четность путем вычитания двойки из числа
//    и проверки остатка.
// 3. Функция isEvenNewV3 использует тот факт, что у четных чисел нулевой бит равен 0.

#include "task_1.hpp"

int main(){
    isEvenNewTest();
    return 0;
}

bool isEven(int value){
    return value%2==0;
    }

bool isEvenNewV1(int value){
    return value - 2*(value/2) == 0;
    }

bool isEvenNewV2(int value){

    if (value==0)
        return true;
    else if (value==1)
        return false;

    int remainder = value;

    if (remainder>0)
        while(remainder>=2)
            remainder = remainder - 2;
    else    
        while(remainder<=-2)
            remainder = remainder + 2;

    return (remainder==0);
    }

bool isEvenNewV3(int value){

    std::bitset<256>valueInBits((unsigned long long)value);
    
    return (valueInBits.test(0)==0);
    }

void isEvenNewTest(){
    for(int8_t i=-127;i<127;++i)
        assert(isEven(i)==isEvenNewV1(i)==isEvenNewV2(i)==isEvenNewV3(i));
        
    std::cout<<"OK isEvenNewTest"<<std::endl;
}