#include "ring_buffer_v2.hpp"

std::pair<bool, int> RingBufferV2::writeNumber(int number){
    
    std::cout << "writing begin ..." << std::endl;

    if (intBuffer.size() == bufferSize){
        std::cout << "error write " << number << 
            " ring buffer is full" << std::endl;
        return {false,-1};
    }

    intBuffer.push(number);
    std::cout << "wrote " << number << std::endl;

    return {true,0};
}

std::tuple<bool, int, int> RingBufferV2::readNumber(){
    
    int result;

    std::cout << "reading begin ..." << std::endl;

    if (intBuffer.size() == 0){
        std::cout << "error read, buffer is empty " << std::endl;
        return {false,-1,-1};
    }

    result = intBuffer.front();
    std::cout << "read " << result << std::endl;
    intBuffer.pop();

    return {true,intBuffer.size()-1,result};
}
