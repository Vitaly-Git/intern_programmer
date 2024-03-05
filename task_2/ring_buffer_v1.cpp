#include "ring_buffer_v1.hpp"

std::pair<bool, int> RingBufferV1::writeNumber(int number){
    
    int newWriteIndex = writeIndex + 1;

    std::cout << "writing begin ..." << std::endl;

    if (newWriteIndex == bufferSize)
        newWriteIndex = 0;
    
    if (newWriteIndex == readIndex || 
        newWriteIndex == 0 && readIndex == -1 && intBuffer.size()>0){
        std::cout << "error write " << number << " at index " << newWriteIndex << 
        ". read index achieved at " << readIndex << std::endl;
        return {false,-1};
    }

    if (newWriteIndex >= intBuffer.size())
        intBuffer.push_back(number);
    else
        intBuffer[newWriteIndex] = number;

    writeIndex = newWriteIndex;

    printBuffer();

    return {true,writeIndex};
}

std::tuple<bool, int, int> RingBufferV1::readNumber(){
    
    int result;

    std::cout << "reading begin ..." << std::endl;

    int newReadIndex = readIndex + 1;

    if (newReadIndex == bufferSize)
        newReadIndex = 0;
    
    if (newReadIndex == writeIndex || 
        newReadIndex == 0 && writeIndex == -1){
        std::cout << "error read at index " << newReadIndex << 
        ". write index achieved at " << writeIndex << std::endl;
        return {false,-1,-1};
    }

    result = intBuffer[newReadIndex];

    std::cout << "read " << result << " at idx.: " << newReadIndex << std::endl;

    readIndex = newReadIndex;

    printBuffer();

    return {true,readIndex,result};
}

std::tuple<bool, int, int> RingBufferV1::readNumber(int index){

    std::cout << "reading by index begin ..." << std::endl;

    if (index > bufferSize - 1){
        std::cout << "error read at index " << index << 
        ". buffer size " << bufferSize << " less that index " << index << std::endl;
        return {false,-1,-1};
    }

    int readIndexBeforeChange = readIndex;
    readIndex = index-1;

    auto readResult = this->readNumber();

    if (std::get<0>(readResult) == false)
        readIndex = readIndexBeforeChange;

    return readResult;    
}

void RingBufferV1::printBuffer(){

    std::cout << "ring buffer [";

    for(auto it=intBuffer.begin(); it!=intBuffer.end(); ++it){
        if (it!=intBuffer.begin())
            std::cout << " ";
        std::cout << *it;
    }

    std::cout << "]";

    std::cout << " read idx.:" << readIndex << " write idx.:" << writeIndex << std::endl;
}

void RingBufferV1::clearBuffer(){
    intBuffer.clear();
    readIndex = -1;
    writeIndex = -1;   
    bufferSize = 0;
    std::cout << "buffer cleared" << std::endl;
}
