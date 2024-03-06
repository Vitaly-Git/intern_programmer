// Задание 1
//
// 1. На языке С/С++, написать функцию, которая быстрее всего (по процессорным тикам) отсортирует данный ей массив чисел.
//
// 2. Массив может быть любого размера со случайным порядком чисел (в том числе и отсортированным).
//
// 3. Объяснить почему вы считаете, что функция соответствует заданным критериям.
//
// Решение
//
// 1. Сразу хочется использовать сортировку пузырьком, но она будет медленная,
//    т.к. используются вложенные циклы. Её исключаем.
//
// 2. Можно использовать стандартный алгоритм из STL, но требуется написать
//    функцию самостоятельно, поэтому тоже исключаем.
//
// 3. Попробуем сделать аргументированный выбор одного из алгоритмов
//    быстой сортировки. Исходим из того, что сложность по времени и памяти должна быть минимальной,
//    чтобы уменьшить количество процессорных тиков на выполнение операции сортировки.
//
// 4. В итоге выбор останавился на сортировке кучи или быстрой сортировки.
//
// 5. Выберем сортировку кучи, как наименее затратную по временной сложности и использованию памяти,
//    и наиболее предсказуемую по сложности.

#include "task_3.hpp"

int main(){
    heapSortTest();
    return 0;
}

void heapSortTest(){

    assert(heapSort({1}) == ((std::vector<int>){1}));
    
    assert(heapSort({2,2}) == ((std::vector<int>){2,2}));
    
    assert(heapSort({3,2}) != ((std::vector<int>){3,2}));
    assert(heapSort({3,2}) == ((std::vector<int>){2,3}));
    
    assert(heapSort({3,2,1}) == ((std::vector<int>){1,2,3}));
    assert(heapSort({3,2,1}) != ((std::vector<int>){3,2,1}));

    assert(heapSort({3,3,2,2,1,1}) != ((std::vector<int>){3,3,2,2,1,1}));
    assert(heapSort({3,3,2,2,1,1}) == ((std::vector<int>){1,1,2,2,3,3}));

    assert(heapSort({5,4,3,8,1}) != ((std::vector<int>){5,4,3,8,1}));
    assert(heapSort({5,4,3,8,1}) == ((std::vector<int>){1,3,4,5,8}));

    assert(heapSort({5,4,3,8,1,34,78,12,1,2}) != ((std::vector<int>){5,4,3,8,1,34,78,12,1,2}));
    assert(heapSort({5,4,3,8,1,34,78,12,1,2}) == ((std::vector<int>){1,1,2,3,4,5,8,12,34,78}));

    std::cout<<"OK "<<__FUNCTION__<<std::endl;
}

std::vector<int> heapSort(std::vector<int> vectorToSort){

    int vectorSize = vectorToSort.size();

    std::cout<<"source vector: ";
    printVector(vectorToSort);

	for(int i=vectorSize/2-1; i>=0; --i){
        moveMaxValueToTop(vectorToSort, vectorSize, i);
    }

    std::cout<<"heaped vector: ";
    printVector(vectorToSort);    
	 
	for(int i=vectorSize-1; i>=0; --i)
	{
		std::swap(vectorToSort[0], vectorToSort[i]);
		moveMaxValueToTop(vectorToSort, i, 0);
	}

    std::cout<<"sorted vector: ";
    printVector(vectorToSort);
    std::cout<<std::endl;

    return vectorToSort;
}

void moveMaxValueToTop(std::vector<int>& vectorToSort, int vectorSize, int rootIndex)
{
	int maxValueIndex = rootIndex;
	int leftIndex = 2*rootIndex + 1;
	int rightIndex = 2*rootIndex + 2;
	  
	if (leftIndex < vectorSize && vectorToSort[leftIndex] > vectorToSort[maxValueIndex])
		maxValueIndex = leftIndex;
	  
	if (rightIndex < vectorSize && vectorToSort[rightIndex] > vectorToSort[maxValueIndex])
		maxValueIndex = rightIndex;

	if (maxValueIndex != rootIndex)
	{
		std::swap(vectorToSort[rootIndex], vectorToSort[maxValueIndex]);
        std::cout<<"processing vector: ";
        printVector(vectorToSort);
		moveMaxValueToTop(vectorToSort, vectorSize, maxValueIndex);
	}
}

void printVector(std::vector<int>& vectorToSort){

    std::cout << "[";

    for(auto it=vectorToSort.begin(); it!=vectorToSort.end(); ++it){
        if (it!=vectorToSort.begin())
            std::cout << " ";
        std::cout << *it;
    }

    std::cout << "]";

    std::cout << std::endl;
}