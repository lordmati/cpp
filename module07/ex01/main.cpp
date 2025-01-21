#include "iter.hpp"
void printElement(int element)
{
    std::cout << element << " ";
}
void doubleElement(int element)
{
    std::cout << (element * 2) << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *err = NULL;
    size_t length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    iter(arr, length, printElement);
    iter(err,length,printElement);
    std::cout << std::endl;

    std::cout << "Doubled elements: ";
    iter(arr, length, doubleElement);
    std::cout << std::endl;

    return 0;
}