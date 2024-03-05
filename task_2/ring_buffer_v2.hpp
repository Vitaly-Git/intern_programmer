#include <iostream>
#include <queue>
#include <tuple>

class RingBufferV2{
    private:
        std::queue<int> intBuffer;
        int bufferSize;
    public:
        RingBufferV2(int size) : bufferSize(size){
        }
        std::pair<bool, int> writeNumber(int number);
        std::tuple<bool, int, int> readNumber();
};
