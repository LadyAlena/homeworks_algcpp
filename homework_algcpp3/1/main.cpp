#include <iostream>
#include <vector>

// Функция слияния двух отсортированных подмассивов
void merge(int* arr, int left, int middle, int right) {
    int left_size = middle - left + 1;
    int rigth_size = right - middle;

    std::vector<int> left_arr(left_size);
    std::vector<int> rigth_arr(rigth_size);

    for (int i = 0; i < left_size; i++)
        left_arr[i] = arr[left + i];
    for (int i = 0; i < rigth_size; i++)
        rigth_arr[i] = arr[middle + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < left_size && j < rigth_size) {
        if (left_arr[i] <= rigth_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = rigth_arr[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < rigth_size) {
        arr[k] = rigth_arr[j];
        j++;
        k++;
    }
}

// Функция сортировки слиянием
void merge_sort_helper(int* arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        merge_sort_helper(arr, left, middle);
        merge_sort_helper(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void merge_sort(int* arr, int size) {
    merge_sort_helper(arr, 0, size - 1);
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
    merge_sort(arr1, size1);
    std::cout << "Отсортированный массив 1: ";
    print_array(arr1, size1);
    std::cout << std::endl;

    std::cout << "Исходный массив 2: ";
    print_array(arr2, size2);
    merge_sort(arr2, size2);
    std::cout << "Отсортированный массив 2: ";
    print_array(arr2, size2);
    std::cout << std::endl;

    std::cout << "Исходный массив 3: ";
    print_array(arr3, size3);
    merge_sort(arr3, size3);
    std::cout << "Отсортированный массив 3: ";
    print_array(arr3, size3);
    std::cout << std::endl;

    return 0;
}