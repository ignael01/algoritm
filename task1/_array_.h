#pragma once
//������� ��������� �������� �� ��� �������� � ��� ��������
int getRandomNumber(int min, int max);
//����� �� ����� ������
void print(size_t massiv[], int n);
//������� ������ � ��������� ��� ���������� ����������
size_t* _array_(int n, int min, int max);

// �������� �� ������������� ����� � �� ������ ���� ������ 0 (array[i]<=0)
template<typename Type>
bool proverka_array(Type array, size_t length);