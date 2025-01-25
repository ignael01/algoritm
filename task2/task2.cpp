
/* проект предусмотрет для пойска переменной из массива 

*/
#include <iostream>
#include "..\task1\_array_.h"
#include "..\task1\time.h"
#include <chrono>
#include "..\task1\database.h"
#include "..\task2\poisk.h"
#include < algorithm >
#include "..\task1\sort.h"
#include "..\task1\assert_test.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	//assert_test();

	//вводим начальные значение длину массива мин и мах границы значении
	int lengh = 100;
	int min = 1;
	int max = 100000;
	int koll = 20;  // количество операции, сколько раз должен будет запуститься код 
	Timer timer;
	Timer timer2;
	double *koll_push_good = new double[koll];  // массив в которой будет храниться время
	double* koll_push_badle = new double[koll];
	double* koll_push = new double[koll];
	double* koll_push_bin = new double[koll];
	double* koll_push_bin_good = new double[koll];
	double* koll_push_bin_badle = new double[koll];

	int* len = new int[koll];	           // len длина массива в разных условиях
	

	for (int i = 0; i < koll; i++) {


		//Пост условия_____________________________
		
		if (koll != 1 and i!= 0) { lengh = lengh + 100'000; }//разные ввод условии например изменения длины массива 
		size_t* massiv = _array_(lengh, min, max);// ввод и вывод массива 
		//result(massiv, lengh);
		double koll_new = 0;
		//________________ конец пост условии
		// пойск 1 способом 	
			// для плохая ситуация если нету значения
		int poisk = 0;//элемент который нужно найти 
		timer.start(); // Запускаем таймер
		std::cout << search(massiv, lengh, poisk) << "  ";
		koll_push_badle[i] = timer.stop() * 1000;// остановка таймера и запись в массив время работы
		
			// если рандом
		 poisk = getRandomNumber(min,max);//элемент который нужно найти 
		timer.start(); // Запускаем таймер
		std::cout << search(massiv, lengh, poisk) << "  ";
		koll_push[i] = timer.stop() * 1000;// остановка таймера и запись в массив время работы

			//если удачно 
			
		 poisk = massiv[0];//элемент который нужно найти 
		timer.start(); // Запускаем таймер
		std::cout << search(massiv, lengh, poisk) << "  ";
		koll_push_good[i] = timer.stop() * 1000;// остановка таймера и запись в массив время работы

		
		// для второго способа требуеться сортировка
		std::sort(massiv, massiv + lengh);
		// пойск 2 способом (бинарный)
			timer2.start();
		for (size_t i = 0; i < 200; i++)
		{
		//рандомный случай
			 poisk = getRandomNumber(min,max);
			
			std::cout << binary_search(massiv, poisk, 0, lengh-1) <<" ";
			

		}
		koll_push_bin[i] = timer2.stop() * 1000;// остановка таймера и запись в массив время работы
		//	// худший случай
		 poisk = 0;
		timer2.start();
		std::cout << binary_search(massiv, poisk, 0, lengh - 1) << " ";
		koll_push_bin_badle[i] = timer2.stop() * 1000;// остановка таймера и запись в массив время работы
		
		// найлучий случай
		 poisk = massiv[0 + (lengh - 0) / 2];
		timer2.start();
		std::cout << binary_search(massiv, poisk, 0, lengh - 1) << " ";
		koll_push_bin_good[i] = timer2.stop() * 1000;// остановка таймера и запись в массив время работы


		delete[] massiv;
		len[i] = lengh;
		std::cout<<std::endl;
	}
	
	//запись в файл с раширением txt для постройки графиков
	database(koll_push_good, koll_push_badle,koll_push, koll_push_bin_good,koll_push_bin_badle,koll_push_bin, koll,len);
	
	delete[] koll_push;

}