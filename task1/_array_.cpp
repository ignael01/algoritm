#include "_array_.h"
#include <random>
#include <iostream>
// создаем массив со входными данными n - длина массива min и max  границы  значений
size_t *_array_(int n, int min, int max) {
	

// обьявляем динамический массив из n  элементов
	size_t *massiv = new size_t[n];
	for (size_t i = 0; i < n;i++) {
		massiv[i] = getRandomNumber(min,max);
	}
	
	return (massiv);
}

// функция рандом
int getRandomNumber(int min, int max) {
	// Создаем генератор случайных чисел с использованием текущего времени как семени
	std::random_device rd;  // Получаем случайное число из аппаратного генератора
	std::mt19937 gen(rd());  // Инициализируем генератор Мерсеннского твистера
	std::uniform_int_distribution<> distr(min, max);  // Задаем равномерное распределение

	return distr(gen);  // Генерируем и возвращаем случайное число
}



//вывод в терминал массив
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