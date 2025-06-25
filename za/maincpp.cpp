
#include <random>
#include <iostream>
//вывод в терминал массив
void print(size_t massiv[], int n) {
    for (int i = 0; i < n;i++) {
        std::cout << (massiv[i]) << " ";

    }
    std::cout << std::endl;
}
// функция рандом
int getRandomNumber(int min, int max) {
    // Создаем генератор случайных чисел с использованием текущего времени как семени
    std::random_device rd;  // Получаем случайное число из аппаратного генератора
    std::mt19937 gen(rd());  // Инициализируем генератор Мерсеннского твистера
    std::uniform_int_distribution<> distr(min, max);  // Задаем равномерное распределение

    return distr(gen);  // Генерируем и возвращаем случайное число
}
// создаем массив со входными данными n - длина массива min и max  границы  значений
size_t* _array_(int n, int min, int max) {


	// обьявляем динамический массив из n  элементов
	size_t* massiv = new size_t[n];
	for (size_t i = 0; i < n;i++) {
		massiv[i] = getRandomNumber(min, max);
	}

	return (massiv);
}

template<typename Type>
void Sort(Type arr[], int size) {
    for (int i = 1; i < size; i++) // внешний цикл  
    {
       
        int key = arr[i]; // очередной элемент для вставки (ключ)  
        //std::cout << key;
        Type j;
        for (j = i - 1; j >= 0 && arr[j] > key; j--) // внутренний цикл  
        {
            arr[j + 1] = arr[j]; // сдвиг элементов вправо  
            arr[j] = key; // вставка элемента (ключа) в нужное место  
        }
    }
    //print(arr,size);
    //return arr;
}

// бинарный пойск. искаемая переменая x  начальная переменая start_per  конечная переменая stop_per
//O(log(n)) для всех случаев
template<typename Type>
long long binary_search(Type massiv[], long long x, long long start_per, long long stop_per) {
    
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
        return binary_search(massiv, x, bin + 1, stop_per);
    }
    // Если элемент меньше среднего, ищем в левой части
    else {
        return binary_search(massiv, x, start_per, bin - 1);
    }
}

int main(){


    int length= 100;
    int min = 0;
    int max = 100;
    std::cout << "Введите значение x :";
    long long x;
    std::cin >> x;

    size_t* massiv = _array_(length,min,max);

    print(massiv,length);
    std::cout << "\n";


    Sort(massiv, length);
    print(massiv, length);
    std::cout << "\n";
    std::cout << binary_search(massiv,x,1,100);


}