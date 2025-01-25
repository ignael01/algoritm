
/* проект предусмотрет для записи времени при сортировки данных различными способами

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
	//вводим начальные значение длину массива мин и мах границы значении
	int lengh = 10;
	int min = 1; // min  граница минимального значения для генерации числа массива
	int max = 1000; // max  граница максимального значения для генерации числа массива
	int koll = 20;  // количество операции, сколько раз должен будет запуститься код 
	Timer timer;
	
	double* koll_push_1 = new double[koll];  // массив в которой будет храниться время для разных сортировок
	double* koll_push_2 = new double[koll];
	double* koll_push_3 = new double[koll];
	double* koll_push_4 = new double[koll];
	int* len = new int[koll];	           // len длина массива в разных условиях


	for (int i = 0; i < koll; i++) {


		//Пост условия_____________________________

		if (koll != 1 and i != 0) { lengh += koll * 1000; }//разные ввод условии например изменения длины массива 
		size_t *massiv = _array_(lengh, min, max);// ввод и вывод массива 
		//result(massiv, lengh);

		// копирование массива
		size_t* massiv_copy = new size_t[lengh];
		std::memcpy(massiv_copy, massiv, lengh * sizeof(size_t));
		
		double koll_new = 0;
		//________________ конец пост условии

		//  1 способ сортировки 	
		timer.start(); // Запускаем таймер
		bubble_sorting(massiv_copy, lengh);
		koll_push_1[i] = timer.stop() * 1000;// остановка таймера и запись в массив время работы

		std::memcpy(massiv_copy, massiv, lengh * sizeof(size_t));

		
		// 2 способ сортировки Функция сортировки слиянием
		timer.start();
		
		mergeSort(massiv_copy,0, lengh-1);
		koll_push_2[i] = timer.stop() * 1000;// остановка таймера и запись в массив время работы

		std::memcpy(massiv_copy, massiv, lengh * sizeof(size_t));

		// 3 способ сортировки Функция быстрой сортировки
		timer.start();
		quickSort(massiv_copy, 0, lengh - 1);
		koll_push_3[i] = timer.stop() * 1000;// остановка таймера и запись в массив время работы
		
		std::memcpy(massiv_copy, massiv, lengh * sizeof(size_t));
		
		// 4 способ сортировки Функция для сортировки Шелла
		timer.start();
		shellSort(massiv_copy, lengh );
		koll_push_4[i] = timer.stop() * 1000;// остановка таймера и запись в массив время работы


		delete[] massiv;
		len[i] = lengh;
	}

	//запись в файл с раширением txt для постройки графиков
	database_sort(koll_push_1, koll_push_2, koll_push_3, koll_push_4, koll, len);
		
	delete[] koll_push_1;

}