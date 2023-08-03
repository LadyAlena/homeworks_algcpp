#include <iostream>
#include <vector>

void count_sort(int* arr, int size) {
    // Находим максимальное и минимальное значения в массиве
    int min_val = arr[0];
    int max_val = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        } else if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Создаём массив подсчёта
    int range = max_val - min_val + 1;
    std::vector<int> count_arr(range);

    // Подсчитываем количество вхождений каждого элемента
    for (int i = 0; i < size; ++i) {
        count_arr[arr[i] - min_val]++;
    }

    // Перезаписываем исходный массив отсортированными значениями
    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (count_arr[i] > 0) {
            arr[index++] = i + min_val;
            count_arr[i]--;
        }
    }
}

// Функция для вывода массива на экран
void print_array(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Примеры массивов для тестирования
    int arr1[] = {19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17};
    auto size1 = std::size(arr1);

    int arr2[] = {16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16};
    auto size2 = std::size(arr2);

    int arr3[] = {21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10};
    auto size3 = std::size(arr3);

    // Тестирование функции
    std::cout << "Исходный массив 1: ";
    print_array(arr1, size1);
    count_sort(arr1, size1);
    std::cout << "Отсортированный массив 1: ";
    print_array(arr1, size1);
    std::cout << std::endl;

    std::cout << "Исходный массив 2: ";
    print_array(arr2, size2);
    count_sort(arr2, size2);
    std::cout << "Отсортированный массив 2: ";
    print_array(arr2, size2);
    std::cout << std::endl;

    std::cout << "Исходный массив 3: ";
    print_array(arr3, size3);
    count_sort(arr3, size3);
    std::cout << "Отсортированный массив 3: ";
    print_array(arr3, size3);
    std::cout << std::endl;

    return 0;
}
