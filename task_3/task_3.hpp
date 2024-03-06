#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> heapSort(std::vector<int> vectorToSort);
void moveMaxValueToTop(std::vector<int>& vectorToSort, int vectorSize, int rootIndex);

void heapSortTest();
void printVector(std::vector<int>& vectorToSort);