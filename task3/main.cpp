
/* ������ ������������ ��� ������ ������� ��� ���������� ������ ���������� ���������

*/
#include <iostream>
#include "..\task1\_array_.h"
#include "..\task1\time.h"
#include <chrono>
#include "..\task1\database.h"
#include "..\task1\sort.h"
#include "..\task1\assert_test.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	assert_test();
	//������ ��������� �������� ����� ������� ��� � ��� ������� ��������
	int lengh = 10;
	int min = 1; // min  ������� ������������ �������� ��� ��������� ����� �������
	int max = 1000; // max  ������� ������������� �������� ��� ��������� ����� �������
	int koll = 20;  // ���������� ��������, ������� ��� ������ ����� ����������� ��� 
	Timer timer;
	
	double* koll_push_1 = new double[koll];  // ������ � ������� ����� ��������� ����� ��� ������ ����������
	double* koll_push_2 = new double[koll];
	double* koll_push_3 = new double[koll];
	double* koll_push_4 = new double[koll];
	int* len = new int[koll];	           // len ����� ������� � ������ ��������


	for (int i = 0; i < koll; i++) {


		//���� �������_____________________________

		if (koll != 1 and i != 0) { lengh += koll * 1000; }//������ ���� ������� �������� ��������� ����� ������� 
		size_t *massiv = _array_(lengh, min, max);// ���� � ����� ������� 
		//result(massiv, lengh);

		// ����������� �������
		size_t* massiv_copy = new size_t[lengh];
		std::memcpy(massiv_copy, massiv, lengh * sizeof(size_t));
		
		double koll_new = 0;
		//________________ ����� ���� �������

		//  1 ������ ���������� 	
		timer.start(); // ��������� ������
		bubble_sorting(massiv_copy, lengh);
		koll_push_1[i] = timer.stop() * 1000;// ��������� ������� � ������ � ������ ����� ������

		std::memcpy(massiv_copy, massiv, lengh * sizeof(size_t));

		
		// 2 ������ ���������� ������� ���������� ��������
		timer.start();
		
		mergeSort(massiv_copy,0, lengh-1);
		koll_push_2[i] = timer.stop() * 1000;// ��������� ������� � ������ � ������ ����� ������

		std::memcpy(massiv_copy, massiv, lengh * sizeof(size_t));

		// 3 ������ ���������� ������� ������� ����������
		timer.start();
		quickSort(massiv_copy, 0, lengh - 1);
		koll_push_3[i] = timer.stop() * 1000;// ��������� ������� � ������ � ������ ����� ������
		
		std::memcpy(massiv_copy, massiv, lengh * sizeof(size_t));
		
		// 4 ������ ���������� ������� ��� ���������� �����
		timer.start();
		shellSort(massiv_copy, lengh );
		koll_push_4[i] = timer.stop() * 1000;// ��������� ������� � ������ � ������ ����� ������


		delete[] massiv;
		len[i] = lengh;
	}

	//������ � ���� � ���������� txt ��� ��������� ��������
	database_sort(koll_push_1, koll_push_2, koll_push_3, koll_push_4, koll, len);
		
	delete[] koll_push_1;

}