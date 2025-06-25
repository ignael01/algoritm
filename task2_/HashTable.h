#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <functional> // Для std::hash
#include <random>
#include <fstream>
using namespace std;

template <typename K, typename V>
struct Record {
    size_t id;    // Идентификатор записи
    K key;        // Ключ
    V value;      // Значение

    Record(size_t id, const K& key, const V& value) : id(id), key(key), value(value) {}
         
};


template <typename K, typename V>
class HashTable {
private:
    std::vector<std::vector<Record<K, V>>> table; // Хэш-таблица
    size_t currentSize;                             // Текущий размер таблицы
    size_t nextId;                                  // Следующий идентификатор

   

    // реализация хэш-функции
    size_t hashFunction(const K& key) {
        std::hash<K> hasher;
        if (table.size() != 0) { return hasher(key) % table.size(); }
        else { return hasher(key) % 10; };
        //cout << hasher(key) % table.size();

        
    }
    // Метод для генерации ключа на основе значения
    K generateKey(const V& value) {
        return static_cast<K>(std::hash<V>()(value)); 

    }


public:
    //конструктор с параметром размера таблицы
    HashTable(size_t size) {
        if (size == 0) throw std::invalid_argument("Size must be > 0");
        table.resize(size);
    }

    // вставка
    void insert(const V& value) {
        //cout << "fafsa";
        // Генерация ключа на основе значения

        K key = generateKey(value);
        
        size_t index = hashFunction(key);
        /*cout << "fafsa";
        cout << index;*/

        // Проверка на существование ключа и обновление значения
        for (auto& record : table[index]) {
            if (record.key == key) {
                
                record.value = value; // Обновление значения, если ключ уже существует
                return;
            }
        }
        
        // Добавление новой пары с уникальным id
        table[index].emplace_back(nextId++, key, value);
        currentSize++;
    }
    // удаление
    bool remove(const  V& value) {
        K key = generateKey(value);
        size_t index = hashFunction(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it); // Удаление элемента
                currentSize--;
                return true; // Элемент удален
            }
        }
        return false; // Элемент не найден
    }
    // пойск элемента

    bool get(const  V& value) {
        K key = generateKey(value);
        size_t index = hashFunction(key);
        for (auto& pair : table[index]) {
           /* cout << pair.key << " ";
            cout << key << " ";*/
            if (pair.key == key) {
                pair.value = pair.value;
                return true; // Успешное извлечение
            }
        }
        return false; // Ключ не найден
    }

   

    // Получение текущего размера
    size_t size() const {
        return currentSize;
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return currentSize == 0;
    }

    
};
// функция рандом
int getRandomNumber(int min, int max) {
    // Создаем генератор случайных чисел с использованием текущего времени как семени
    std::random_device rd;  // Получаем случайное число из аппаратного генератора
    std::mt19937 gen(rd());  // Инициализируем генератор Мерсеннского твистера
    std::uniform_int_distribution<> distr(min, max);  // Задаем равномерное распределение

    return distr(gen);  // Генерируем и возвращаем случайное число
}
void database_array(double array[],size_t length[]) {
    // создание и открытие текстового файла
    ofstream MyFile("array.csv");

    // запись времени
    for (size_t i = 0; i < sizeof(length); i++)
    {
        cout << length[i] << "," << array[i];
        MyFile << length[i] << "," << array[i]; // запись строки в файл

        MyFile << "\n";
    }

}

#endif