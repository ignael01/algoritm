// пойска - big O дл€  среднего случа€ (1)
//удаление- big 0 дл€  среднего случа€ (1)
// вставки- big 0 дл€  среднего случа€ (1)

using namespace std;
#include < assert.h> 
#include "HashTable.h"
#include "..\task1\time.h"
#include "..\task1\database.h"
#include <random>


int main() {
    setlocale(LC_ALL, "Russian");

    

    //средн€€ врем€ пойска 
    // 
    //вводим начальные значение длину массива мин и мах границы значении
    int lengh = 100;
    int min = 1; // min  граница минимального значени€ дл€ генерации числа массива
    int max = 10000; // max  граница максимального значени€ дл€ генерации числа массива
    int koll = 10;  // количество операции, сколько раз должен будет запуститьс€ код 
    size_t* len = new size_t[koll];	           // len длина в разных услови€х
    double* pet = new double[10];
    Timer timer;
    double cr;
    double* koll_push = new double[koll];  // массив в которой будет хранитьс€ врем€ дл€ разных сортировок

    for (int i = 0; i < koll; i++) {
        cr = 0;
        if (koll != 1 and i != 0) { lengh = lengh *  10; }//разные ввод условии например изменени€ длины массива 


        //lengh = lengh + 100.000;
        for (int j = 0; j < 10; j++) { // среднее  между результатами в одном деапозоне 
            /*cout << "sfasf";*/
            //ѕост услови€_____________________________
            int poisk = getRandomNumber(min, max);
            //cout << poisk;

            // нужно вести все хэш таблицу с размерностью в length , в него же запаолн€ет значение koll, рандом значений от min до max

            HashTable<int, int> hashTable(lengh);
            //cout << poisk;
            for (int i = 0; i < koll; ++i) {
                /*cout << poisk;*/
                hashTable.insert(getRandomNumber(min, max));
            }
            /*cout << poisk;*/
            //________________ конец пост условии


            timer.start(); // «апускаем таймер

            hashTable.get(poisk);
            // пойск сделать 

            // среднее посчет 

            pet[j] = timer.stop() * 1000;
            

        }
        
        
        for (int i = 0; i < 10;i++) {
            cr =cr + pet[i];
         
        }
        cout << cr;
        koll_push[i] = cr/10;// остановка таймера и запись в массив врем€ работы
        cout << "\n";
        cout << koll_push[i];
        cout << "\n";
        //cout << "dfsdfsd";

        len[i] = lengh;

    }
    //запись в файл с раширением txt дл€ постройки графиков
    database_array(koll_push, len);

    /*с-----------------------------------------------------------------------------------------------------------*/
    // ¬ставка элементов
    HashTable<int, int> hashTable(1);
    hashTable.insert(1);
    hashTable.insert(34);
    hashTable.insert(74);
    cout << "“екущий размер: " << hashTable.size() << std::endl;
    //// пойск элементов
    int value = 34;
    assert(hashTable.get(value)==true);

    if (hashTable.get(value)) {
        std::cout << "»звлечение  «начение : " << value<< std::endl;
    }
    else {
        std::cout << "не найдено." << std::endl;
    }

    // ”даление элемента
    if (hashTable.remove(2)) {
        std::cout << " удалено." << std::endl;
    }
    else {
        std::cout << " не найдено." << std::endl;
    }
    assert(hashTable.remove(1) == true);

     //ѕроверка размера
    
    cout << "“екущий размер: " << hashTable.size() << std::endl;
    assert(hashTable.size()==2);
    return 0;
}
