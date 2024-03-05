#include <iostream>
#include <vector>
#include <tuple>

class RingBufferV1{
    private:
        std::vector<int> intBuffer;
        int bufferSize;
        int readIndex;
        int writeIndex;
    public:
        RingBufferV1(int size) : bufferSize(size), readIndex{-1}, writeIndex{-1}{
            intBuffer.clear();
        }
        std::pair<bool, int> writeNumber(int number);
        std::tuple<bool, int, int> readNumber();
        std::tuple<bool, int, int> readNumber(int index);
        void printBuffer();
        void clearBuffer();
};
