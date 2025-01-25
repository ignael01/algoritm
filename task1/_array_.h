#pragma once
//создает рандомное значение по мин значению и мах значению
int getRandomNumber(int min, int max);
//вывод на экран массив
void print(size_t massiv[], int n);
//создает массив и заполняет его рандомными значениями
size_t* _array_(int n, int min, int max);

// проверка на положительное число и не должно быть равным 0 (array[i]<=0)
template<typename Type>
bool proverka_array(Type array, size_t length);