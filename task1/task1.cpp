#include <iostream>
#include "_array_.h"
#include "time.h"
#include <chrono>
#include "database.h"
#include "assert_test.h"
int main()
{

	//вводим начальные значение длину массива мин и мах границы значении
	int lengh = 20;
	int min = 1;
	int max = 100;
	// количество операции, сколько раз должен будет запуститься код 
	double koll = 1;

	
	assert_test();

	//запись в файл с раширением txt для постройки графиков
	//database(koll_push, koll);
}
