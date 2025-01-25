#include <iostream>

//������� �����  ����� ������� length  ������� ��������� x
// �(n) ��� �������� ������
template<typename Type>
long long search(Type massiv[], long long lengh, long long x) {

    // ����� ����������������� �������� ���� ������� ������ ������������� ������ � ������� �� ����� for
    for (long long i = 0; i < lengh; i++) {
        if (massiv[i] == x) { return i; }
    }
    //
    return -1;
}


// �������� �����. �������� ��������� x  ��������� ��������� start_per  �������� ��������� stop_per
//O(log(n)) ��� ���� �������
template<typename Type>
long long binary_search(Type massiv[], long long x, long long start_per, long long stop_per) {
    // �������� ������
    if (start_per > stop_per) {
        return -1; // ������� �� ������
    }

    // ������� ������� ������
    int bin = start_per + (stop_per - start_per) / 2;
    // ���������, ������ �� �������
    if (massiv[bin] == x) {
        return bin; // ���������� ������ ���������� ��������
    }

    // ���� ������� ������ ��������, ���� � ������ �����
    if (massiv[bin] < x) {
        return binary_search(massiv, x, bin + 1, stop_per);
    }
    // ���� ������� ������ ��������, ���� � ����� �����
    else {
        return binary_search(massiv, x, start_per, bin - 1);
    }
}

