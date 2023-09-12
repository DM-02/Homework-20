//
//  main.cpp
//  Homework 20
//
//  Created by Дмитрий Сергеевич on 10.09.2023.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

const int size = 20;

// Заполняет массив случайными числами в заданном диапазоне
void fill_arr(int arr[], int left, int right) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (right - left) + left;
    }
}

// Выводит массив в консоль
void print_arr(int arr[]) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Возвращает индекс первого вхождения элемента в массив
int search_index(int arr[], int element, int begin = 0) {
    for (int i = begin; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// Возвращает индекс последнего вхождения элемента в массив
int search_last_index(int arr[], int element, int begin = 0) {
    int lastIndex = -1;
    for (int i = begin; i < size; i++) {
        if (arr[i] == element) {
            lastIndex = i;
        }
    }
    return lastIndex;
}

// Возвращает минимальный элемент массива
int arr_min(int arr[]) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Возвращает максимальный элемент массива
int arr_max(int arr[]) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Возвращает среднее арифметическое всех элементов массива
float mean_value(int arr[]) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static_cast<float>(sum) / size;
}

// Выводит все элементы массива, которые входят в заданный диапазон
void range(int arr[], int left, int right) {
    for (int i = 0; i < size; i++) {
        if (arr[i] >= left && arr[i] < right) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

// Возвращает количество вхождений элемента в массив
int count(int arr[], int element) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            count++;
        }
    }
    return count;
}

// Сортирует массив по возрастанию с помощью пузырькового метода сортировки
void sort_arr(int arr[]) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(0));

    int arr[size];

    fill_arr(arr, -50, 51);

    std::cout << "Массив: ";
    print_arr(arr);

    int searchElement = 10;
    int searchIndex = search_index(arr, searchElement);
    std::cout << "Индекс первого вхождения " << searchElement << " в массив: " << searchIndex << std::endl;

    int searchLastIndex = search_last_index(arr, searchElement);
    std::cout << "Индекс последнего вхождения " << searchElement << " в массив: " << searchLastIndex << std::endl;

    int minValue = arr_min(arr);
    std::cout << "Минимальное значение в массиве: " << minValue << std::endl;

    int maxValue = arr_max(arr);
    std::cout << "Максимальное значение в массиве: " << maxValue << std::endl;

    float mean = mean_value(arr);
    std::cout << "Среднее значение всех элементов массива: " << mean << std::endl;

    std::cout << "Элементы массива, входящие в диапазон от -10 до 10: ";
    range(arr, -10, 11);

    int searchCount = count(arr, searchElement);
    std::cout << "Количество вхождений " << searchElement << " в массиве: " << searchCount << std::endl;

    sort_arr(arr);
    std::cout << "Отсортированный массив: ";
    print_arr(arr);

    return 0;
}
