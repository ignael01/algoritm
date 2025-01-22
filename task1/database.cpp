#include "database.h"
#include <iostream>
#include <fstream>
using namespace std;

void database(double time[], int koll, int len[]) {
    // создание и открытие текстового файла
    ofstream MyFile("test.csv");
    // запись времени
    for (size_t i = 0; i < koll; i++)
    {
        MyFile << time[i] << ", "; // запись строки в файл
        
    }
    //запись длины массива
    MyFile << std::endl;
    for (size_t i = 0; i < koll; i++)
    {
        MyFile << len[i] << ", "; // запись строки в файл

    }

}

