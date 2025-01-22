
#include <iostream>
#include "..\task1\_array_.h"
#include "..\task1\time.h"
#include <chrono>
#include "..\task1\database.h"
#include "poisk.h"
#include < algorithm >
#include "..\task1\sort.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	//вводим начальные значение длину массива мин и мах границы значении
	int lengh = 200;
	int min = 1;
	int max = 100;
	// количество операции, сколько раз должен будет запуститься код 
	int koll = 10;
	Timer timer;
	double *koll_push = new double[koll];
	int* len = new int[koll];
	for (int i = 0; i < koll; i++) {


		//Пост условия_____________________________
		//разные ввод условии например изменения длины массива 
		if (koll != 1 and i!= 0) { lengh += koll * 1000; }
		
		
		int poisk = 10;//элемент который нужно найти 

		size_t* massiv = _array_(lengh, min, max);// ввод и вывод массива 
		//result(massiv, lengh);
		double koll_new = 0;
		//________________ конец пост условии

				
		//std::cout << "Таймер запущен: " << (timer.isRunning() ? "Да" : "Нет") << std::endl; // Проверяем состояние таймера
		// Запускаем таймер
		
		
		timer.start();
		
		std::cout<<poisk_posl(massiv, lengh, poisk)<<"  ";
		
		//sort(massiv, lengh);
		//std::cout << poisk_bin(massiv, poisk, 0, lengh-1) <<" ";
		
		
		
		koll_push[i] = timer.stop()*100;

		//std::cout << koll_push[i] << std::endl;
		delete[] massiv;
		len[i] = lengh;
	}

	//запись в файл с раширением txt для постройки графиков
	database(koll_push, koll,len);
	delete[] koll_push;

}