#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* arr;         // Массив для хранения элементов стека
    int capacity;   // Вместимость стека
    int top;        // Индекс верхнего элемента стека

public:
    Stack(int size) : capacity(size), top(-1) {
        arr = new T[capacity]; // Выделение памяти для массива
    }

    ~Stack() {
        delete[] arr; // Освобождение памяти
    }
    // добавления элемента
    void push(T value) {
        if (top == capacity - 1) {
            throw std::overflow_error("Стек переполнен!"); // Исключение при переполнении
        }
        arr[++top] = value; // Увеличиваем индекс и добавляем элемент
    }
    //удаления элемента
    void pop() {
        if (top == -1) {
            throw std::underflow_error("Стек пуст!"); // Исключение при попытке удалить из пустого стека
        }
        --top; // Уменьшаем индекс, тем самым удаляя верхний элемент
    }
    // выводит верхние знаечение
    T peek() const {
        if (top == -1) {
            throw std::out_of_range("Стек пуст!"); // Исключение при попытке посмотреть верхний элемент пустого стека
        }
        return arr[top]; // Возвращаем верхний элемент
    }
    // Проверяем, пуст ли стек
    bool isEmpty() const {
        return top == -1; 
    }
    // Возвращаем количество элементов в стеке
    int size() const {
        return top + 1; 
    }
};
