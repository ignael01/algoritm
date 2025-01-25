#include <iostream>

//обычный пойск  длина массива length  искома€ перемена€ x
// ќ(n) дл€ среднего случа€
template<typename Type>
long long search(Type massiv[], long long lengh, long long x) {

    // поиск последовательного значени€ если находит обьект останавливает таймер и выходит из цикла for
    for (long long i = 0; i < lengh; i++) {
        if (massiv[i] == x) { return i; }
    }
    //
    return -1;
}


// бинарный пойск. искаема€ перемена€ x  начальна€ перемена€ start_per  конечна€ перемена€ stop_per
//O(log(n)) дл€ всех случаев
template<typename Type>
long long binary_search(Type massiv[], long long x, long long start_per, long long stop_per) {
    // ѕроверка границ
    if (start_per > stop_per) {
        return -1; // Ёлемент не найден
    }

    // Ќаходим средний индекс
    int bin = start_per + (stop_per - start_per) / 2;
    // ѕровер€ем, найден ли элемент
    if (massiv[bin] == x) {
        return bin; // ¬озвращаем индекс найденного элемента
    }

    // ≈сли элемент больше среднего, ищем в правой части
    if (massiv[bin] < x) {
        return binary_search(massiv, x, bin + 1, stop_per);
    }
    // ≈сли элемент меньше среднего, ищем в левой части
    else {
        return binary_search(massiv, x, start_per, bin - 1);
    }
}

