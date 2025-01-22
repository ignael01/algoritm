#include "poisk.h"
#include <iostream>
long long poisk_posl(size_t massiv[], long long lengh, long long x) {

	// ����� ����������������� �������� ���� ������� ������ ������������� ������ � ������� �� ����� for
	for (long long i = 0; i < lengh; i++) {
		if (massiv[i] == x) {return i;}
	}
	//
	return -1;
}

long long poisk_bin(size_t massiv[], long long x, int start_per, int stop_per) {
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
        return poisk_bin(massiv, x, bin + 1, stop_per);
    }
    // ���� ������� ������ ��������, ���� � ����� �����
    else {
        return poisk_bin(massiv, x, start_per, bin - 1);
    }
}

