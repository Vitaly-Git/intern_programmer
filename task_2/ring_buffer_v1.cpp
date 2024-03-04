#include "ring_buffer_v1.hpp"

std::pair<bool, int> ringBufferV1::writeNumber(int number){
    
    int newWritePosition = writePosition + 1;

    if (newWritePosition == bufferSize)
        newWritePosition = 0;
    
    if (newWritePosition == readPosition){
        std::cout << "error wrtte " << number << " at position " << newWritePosition << 
        ". read position achieved at " << readPosition << std::endl;
        return {false,-1};
    }

    if (newWritePosition >= intBuffer.size())
        intBuffer.push_back(number);
    else
        intBuffer[newWritePosition] = number;

    writePosition = newWritePosition;

    printBuffer();

    return {true,writePosition};
}

std::tuple<bool, int, int> ringBufferV1::readNumber(){
    
    int result;

    int newReadPosition = readPosition + 1;

    if (newReadPosition == bufferSize)
        newReadPosition = 0;
    
    if (newReadPosition == writePosition){
        std::cout << "error read at position " << newReadPosition << 
        ". write position achieved at " << writePosition << std::endl;
        return {false,-1,-1};
    }

    result = intBuffer[newReadPosition];

    readPosition = newReadPosition;

    printBuffer();

    return {true,readPosition,result};
}

void ringBufferV1::printBuffer(){

    for(auto it=intBuffer.begin(); it!=intBuffer.end(); ++it){
        if (it!=intBuffer.begin())
            std::cout << " ";
        std::cout << *it;
    }

    std::cout << " read pos.:" << readPosition << " write pos.:" << writePosition << std::endl;
}

void ringBufferV1::clearBuffer(){
    intBuffer.clear();
    readPosition = -1;
    writePosition = -1;   
    bufferSize = 0;
    std::cout << "buffer cleared" << std::endl;
}
