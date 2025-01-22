#include "poisk.h"
#include <iostream>
long long poisk_posl(size_t massiv[], long long lengh, long long x) {

	// поиск последовательного значения если находит обьект останавливает таймер и выходит из цикла for
	for (long long i = 0; i < lengh; i++) {
		if (massiv[i] == x) {return i;}
	}
	//
	return -1;
}

long long poisk_bin(size_t massiv[], long long x, int start_per, int stop_per) {
    // Проверка границ
    if (start_per > stop_per) {
        return -1; // Элемент не найден
    }

    // Находим средний индекс
    int bin = start_per + (stop_per - start_per) / 2;
    // Проверяем, найден ли элемент
    if (massiv[bin] == x) {
        return bin; // Возвращаем индекс найденного элемента
    }

    // Если элемент больше среднего, ищем в правой части
    if (massiv[bin] < x) {
        return poisk_bin(massiv, x, bin + 1, stop_per);
    }
    // Если элемент меньше среднего, ищем в левой части
    else {
        return poisk_bin(massiv, x, start_per, bin - 1);
    }
}

