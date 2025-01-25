#include "_array_.h"
#include <random>
#include <iostream>
// ������� ������ �� �������� ������� n - ����� ������� min � max  �������  ��������
size_t *_array_(int n, int min, int max) {
	

// ��������� ������������ ������ �� n  ���������
	size_t *massiv = new size_t[n];
	for (size_t i = 0; i < n;i++) {
		massiv[i] = getRandomNumber(min,max);
	}
	
	return (massiv);
}

// ������� ������
int getRandomNumber(int min, int max) {
	// ������� ��������� ��������� ����� � �������������� �������� ������� ��� ������
	std::random_device rd;  // �������� ��������� ����� �� ����������� ����������
	std::mt19937 gen(rd());  // �������������� ��������� ������������ ��������
	std::uniform_int_distribution<> distr(min, max);  // ������ ����������� �������������

	return distr(gen);  // ���������� � ���������� ��������� �����
}



//����� � �������� ������
void print(size_t massiv[], int n) {
	for (int i = 0; i < n;i++) {
		std::cout << (massiv[i])<< " ";

	}
	std::cout << std::endl;
}
template<typename Type>
bool proverka_array(Type array , size_t length) {
	for (size_t i = 0; i < length; i++)
	{
		if (array[i] <= 0) { return false; }
	}
}