#include "test_stack.h"
#include <iostream>
#include "ctack.h"

void testStack() {
    setlocale(LC_ALL, "Russian");
    Stack<int> intStack(5); // Создаем стек для целых чисел

    // Тест 1: Проверка, что стек пуст
    std::cout << "Тест 1: Стек пуст? " << (intStack.isEmpty() ? "Да" : "Нет") << std::endl;

    // Тест 2: Добавление элементов в стек
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    std::cout << "Тест 2: Добавлено 3 элемента. Размер стека: " << intStack.size() << std::endl;

    // Тест 3: Проверка верхнего элемента
    std::cout << "Тест 3: Верхний элемент: " << intStack.peek() << std::endl; // Ожидается 30

    // Тест 4: Удаление верхнего элемента
    intStack.pop();
    std::cout << "Тест 4: После pop, верхний элемент: " << intStack.peek() << std::endl; // Ожидается 20

    // Тест 5: Проверка размера стека
    std::cout << "Тест 5: Размер стека: " << intStack.size() << std::endl; // Ожидается 2

    // Тест 6: Удаление всех элементов
    intStack.pop();
    intStack.pop();
    std::cout << "Тест 6: После удаления всех элементов, стек пуст? " << (intStack.isEmpty() ? "Да" : "Нет") << std::endl;

    // Тест 7: Проверка исключений
    try {
        intStack.pop(); // Попытка удалить из пустого стека
    }
    catch (const std::underflow_error& e) {
        std::cout << "Тест 7: " << e.what() << std::endl; // Ожидается сообщение об ошибке
    }

    try {
        intStack.peek(); // Попытка посмотреть верхний элемент пустого стека
    }
    catch (const std::out_of_range& e) {
        std::cout << "Тест 8: " << e.what() << std::endl; // Ожидается сообщение об ошибке
    }

    // Тест 9: Переполнение стека
    for (int i = 0; i < 5; ++i) {
        intStack.push(i);
    }

    try {
        intStack.push(6); // Попытка переполнить стек
    }
    catch (const std::overflow_error& e) {
        std::cout << "Тест 9: " << e.what() << std::endl; // Ожидается сообщение об ошибке
    }
}