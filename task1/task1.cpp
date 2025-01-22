#include <iostream>
#include "_array_.h"
#include "time.h"
#include <chrono>
#include "database.h"
int main()
{

	//вводим начальные значение длину массива мин и мах границы значении
	int lengh = 20;
	int min = 1;
	int max = 100;
	// количество операции, сколько раз должен будет запуститься код 
	int koll = 1;

	
	
	Timer timer;
	double *koll_push=new double[koll];


	for (int i=0; i<koll; i++) {
	
		//Пост условия_____________________________
		//разные ввод условии например изменения длины массива lengh= koll *10
		
		
		// ввод и вывод массива 
		
		int* massiv = _array_(lengh, min, max);
		result(massiv, lengh);
		
		//________________ конец пост условии


		std::cout << "Таймер запущен: " << (timer.isRunning() ? "Да" : "Нет") << std::endl; // Проверяем состояние таймера
		timer.start();
		std::cout << "Таймер запущен: " << (timer.isRunning() ? "Да" : "Нет") << std::endl; // Проверяем состояние таймера
		timer.stop();
		std::cout << "Таймер запущен: " << (timer.isRunning() ? "Да" : "Нет") << std::endl; // Проверяем состояние таймера
		return 0;
		
	}

	//запись в файл с раширением txt для постройки графиков
	database(koll_push, koll);
}
