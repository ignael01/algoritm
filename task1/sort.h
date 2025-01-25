
#include <iostream>
#include "_array_.h"
#include <vector>
template<typename Type>
// ���������� ���������. �������������� ������, � ��� ����� length 
// O(n**2) ������� ������
void bubble_sorting(Type massiv[], size_t length) {

    // �������� � ����������� ��������� ����� ����� ���������� ���������
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

//  ������� ��������. �������������� ������ arr
// O(n log(n)) ������� ������ 
template<typename Type>
void merge(Type arr[], size_t left, size_t mid, size_t right) {
    // ��������� ������� �����������
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // ������� ��������� �������
    int* L = new int[n1]; // ����� ���������
    int* R = new int[n2]; // ������ ���������

    // �������� ������ � ��������� �������

    

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // ������� ��������� �������� ������� � arr[left..right]
    int i = 0; // ������ ������� ����������
    int j = 0; // ������ ������� ����������
    int k = left; // ������ �������

    // ���������� ������� ������� 
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

    // �������� ���������� ��������, ���� ����
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // �������� ���������� ��������, ���� ����
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // ����������� ��������� �������
    delete[] L;
    delete[] R;
}

// ������� ���������� ��������, �������������� ������ arr, ����� ���������� ����� ������� 0 , ������ ������� ���������
template<typename Type>
void mergeSort(Type arr[], size_t left, size_t right) {
    if (left < right) {
        // ������� �������� �������
        int mid = left + (right - left) / 2;

        // ���������� ��������� ��� ��������
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // ������� ��������������� ��������
        merge(arr, left, mid, right);
    }
}

// ������� ��� ���������� ������� � ����������� ������� �������� ��������

template<typename Type>
size_t partition(Type arr[], size_t low, size_t high) {
    int pivot = arr[high]; // �������� ��������� ������� � �������� ��������
    int i = low - 1; // ������ �������� ��������

    for (int j = low; j < high; j++) {
        // ���� ������� ������� ������ ��� ����� ��������
        if (arr[j] <= pivot) {
            i++; // ����������� ������ �������� ��������
            std::swap(arr[i], arr[j]); // ������ �������
        }
    }
    std::swap(arr[i + 1], arr[high]); // ������ ������� ������� ������� � ��������� ����� ���������� ��������
    return i + 1; // ���������� ������ �������� ��������
}

// ������� ������� ����������
// O(n log(n)) �������� ������ 
template<typename Type>
void quickSort(Type arr[], size_t low, size_t high) {
    if (low < high) {
        // ������� ������ �������� ��������
        int pi = partition(arr, low, high);

        // ���������� ��������� �������� �� � ����� ��������
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// ������� ��� ���������� ���� ��� /2
// O(n log(n)**2)   
template<typename Type>
void shellSort(Type arr[], size_t size) {
    // �������� � �������� ��������� � ��������� ���
    for (int gap = size / 2; gap > 0; gap /= 2) {
        // ��������� ���������� ��� �������� ���������
        for (int i = gap; i < size; i++) {
            // ��������� ������� �������
            int temp = arr[i];
            int j;

            // �������� �������� arr[0..i-gap], ������� ������ temp, �� ���� ������� ������
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp; // ��������� ������� � ���������� �����
        }
    }
}

//��������� ������������ �� ������
template<typename Type>
bool proverka_sort(Type massiv[], size_t length) {

    // �������� 
    for (size_t i = 0; i < length - 1;i++)
    {
        // ����� ���������� ������� ������� ������ �� ���������� ������ ������� false
        if (massiv[i] < massiv[i + 1])
        {
            return false;
        }
    }
    return true;

}