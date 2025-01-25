
#include <iostream>
#include "_array_.h"
#include <vector>
template<typename Type>
// сортировка пузырькем. типизированный массив, и его длина length 
// O(n**2) средний случай
void bubble_sorting(Type massiv[], size_t length) {

    // проверка и перемещения элементов между собой сортировка пузырьком
    for (size_t i = 0; i < length - 1;i++)
    {
        for (size_t j = 0; j < length - i - 1; j++)
        {
            if (massiv[j] > massiv[j + 1])
            {
                std::swap(massiv[j], massiv[j + 1]);
            }

        }

    }

}

//  слияние массивов. типизированный массив arr
// O(n log(n)) средний случай 
template<typename Type>
void merge(Type arr[], size_t left, size_t mid, size_t right) {
    // Вычисляем размеры подмассивов
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Создаем временные массивы
    int* L = new int[n1]; // Левый подмассив
    int* R = new int[n2]; // Правый подмассив

    // Копируем данные в временные массивы

    

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Слияние временных массивов обратно в arr[left..right]
    int i = 0; // Индекс первого подмассива
    int j = 0; // Индекс второго подмассива
    int k = left; // Индекс слияния

    // производим слияние массива 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы, если есть
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Копируем оставшиеся элементы, если есть
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Освобождаем временные массивы
    delete[] L;
    delete[] R;
}

// Функция сортировки слиянием, типизированный массив arr, левая координата нужно указать 0 , правая сторона координат
template<typename Type>
void mergeSort(Type arr[], size_t left, size_t right) {
    if (left < right) {
        // Находим середину массива
        int mid = left + (right - left) / 2;

        // Рекурсивно сортируем обе половины
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Сливаем отсортированные половины
        merge(arr, left, mid, right);
    }
}

// Функция для разделения массива и возвращения индекса опорного элемента

template<typename Type>
size_t partition(Type arr[], size_t low, size_t high) {
    int pivot = arr[high]; // Выбираем последний элемент в качестве опорного
    int i = low - 1; // Индекс меньшего элемента

    for (int j = low; j < high; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++; // Увеличиваем индекс меньшего элемента
            std::swap(arr[i], arr[j]); // Меняем местами
        }
    }
    std::swap(arr[i + 1], arr[high]); // Меняем местами опорный элемент с элементом после последнего меньшего
    return i + 1; // Возвращаем индекс опорного элемента
}

// Функция быстрой сортировки
// O(n log(n)) среднеий случай 
template<typename Type>
void quickSort(Type arr[], size_t low, size_t high) {
    if (low < high) {
        // Находим индекс опорного элемента
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем элементы до и после опорного
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// Функция для сортировки Шелл шаг /2
// O(n log(n)**2)   
template<typename Type>
void shellSort(Type arr[], size_t size) {
    // Начинаем с большого интервала и уменьшаем его
    for (int gap = size / 2; gap > 0; gap /= 2) {
        // Выполняем сортировку для текущего интервала
        for (int i = gap; i < size; i++) {
            // Сохраняем текущий элемент
            int temp = arr[i];
            int j;

            // Сдвигаем элементы arr[0..i-gap], которые больше temp, на одну позицию вперед
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp; // Вставляем элемент в правильное место
        }
    }
}

//проверяет отсортирован ли массив
template<typename Type>
bool proverka_sort(Type massiv[], size_t length) {

    // проверка 
    for (size_t i = 0; i < length - 1;i++)
    {
        // еслли предыдущий элемент массива меньше ли следующего масива выводит false
        if (massiv[i] < massiv[i + 1])
        {
            return false;
        }
    }
    return true;

}