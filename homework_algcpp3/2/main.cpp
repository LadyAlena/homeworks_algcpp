#include <iostream>
#include <algorithm>

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort_helper(int* arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);

        quick_sort_helper(arr, low, pivot_index - 1);
        quick_sort_helper(arr, pivot_index + 1, high);
    }
}

void quick_sort(int* arr, int size) {
    quick_sort_helper(arr, 0, size - 1);
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    int arr1[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    auto size1 = std::size(arr1);

    int arr2[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    auto size2 = std::size(arr2);

    int arr3[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    auto size3 = std::size(arr3);

    std::cout << "Исходный массив 1: ";
    print_array(arr1, size1);
    quick_sort(arr1, size1);
    std::cout << "Отсортированный массив 1: ";
    print_array(arr1, size1);
    std::cout << std::endl;

    std::cout << "Исходный массив 2: ";
    print_array(arr2, size2);
    quick_sort(arr2, size2);
    std::cout << "Отсортированный массив 2: ";
    print_array(arr2, size2);
    std::cout << std::endl;

    std::cout << "Исходный массив 3: ";
    print_array(arr3, size3);
    quick_sort(arr3, size3);
    std::cout << "Отсортированный массив 3: ";
    print_array(arr3, size3);
    std::cout << std::endl;

    return 0;
}
