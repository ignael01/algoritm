#include "time.h"
#include <chrono>
#include <iostream>


// в коде не использую как тест использовал
int _time_() {


	using namespace std::chrono;


	// начальная отметка времени
	auto t0 = steady_clock::now();
	
	// конечная отметка времени
	auto t1 = steady_clock::now();
	// преобразование времени (обычно наносекунды) в миллисекунды
	auto delta = duration_cast<milliseconds>(t1 - t0);
	std::cout << "time delta (milliseconds) " << delta.count();
	return (0) ;

}
