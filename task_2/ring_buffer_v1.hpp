#include <iostream>
#include <vector>
#include <tuple>

class ringBufferV1{
    private:
        std::vector<int> intBuffer;
        int bufferSize;
        int readPosition;
        int writePosition;
    public:
        ringBufferV1(int size) : bufferSize(size), readPosition{-1}, writePosition{-1}{
            intBuffer.clear();
        }
        std::pair<bool, int> writeNumber(int number);
        std::tuple<bool, int, int> readNumber();
        void printBuffer();
        void clearBuffer();
};
