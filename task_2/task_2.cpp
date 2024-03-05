// Задание 1
//
// 1. На языке С++, написать минимум по 2 класса реализовывающих циклический буфер.
// 
// 2. Объяснить плюсы и минусы каждой реализации.
//
//
// Решение
//
// 1. Циклический буфер через вектор. 
//    Плюсы: Доступ к элементам очень быстрый, выполнится за О(1).
//           Есть метод произвольного доступа через индекс.
//    Минусы: При постоянном расширении будет происходить перевыделение
//            память, характерное для вектора.
//
// 2. Циклический буфер через очередь.
//    Плюсы: Всё ещё работает, хотя за О(n).
//    Минусы: Код значительно усложнился и работает дольше.

#include "task_2.hpp"

int main(){
    ringBufferV1Test();
    return 0;
}

void ringBufferV1Test(){

    RingBufferV1 rb(3);
    assert(rb.writeNumber(0).first == true);
    assert(rb.writeNumber(1).first == true);
    assert(rb.writeNumber(2).first == true);
    assert(rb.writeNumber(3).first == false);

    assert(std::get<0>(rb.readNumber()) == true);
    assert(std::get<0>(rb.readNumber()) == true);
    assert(std::get<0>(rb.readNumber()) == false);
    
    assert(rb.writeNumber(4).first == true);
    assert(rb.writeNumber(5).first == false);

    assert(std::get<0>(rb.readNumber()) == true);
    assert(std::get<0>(rb.readNumber()) == false);

    assert(std::get<0>(rb.readNumber(3)) == false);
    assert(std::get<0>(rb.readNumber(0)) == false);
    assert(std::get<0>(rb.readNumber(1)) == true);
    assert(std::get<0>(rb.readNumber(2)) == true);

    std::cout<<"OK "<<__FUNCTION__<<std::endl;
}
