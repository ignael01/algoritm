#include "test_stack.h"
#include <iostream>
#include "ctack.h"

void testStack() {
    setlocale(LC_ALL, "Russian");
    Stack<int> intStack(5); // ������� ���� ��� ����� �����

    // ���� 1: ��������, ��� ���� ����
    std::cout << "���� 1: ���� ����? " << (intStack.isEmpty() ? "��" : "���") << std::endl;

    // ���� 2: ���������� ��������� � ����
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    std::cout << "���� 2: ��������� 3 ��������. ������ �����: " << intStack.size() << std::endl;

    // ���� 3: �������� �������� ��������
    std::cout << "���� 3: ������� �������: " << intStack.peek() << std::endl; // ��������� 30

    // ���� 4: �������� �������� ��������
    intStack.pop();
    std::cout << "���� 4: ����� pop, ������� �������: " << intStack.peek() << std::endl; // ��������� 20

    // ���� 5: �������� ������� �����
    std::cout << "���� 5: ������ �����: " << intStack.size() << std::endl; // ��������� 2

    // ���� 6: �������� ���� ���������
    intStack.pop();
    intStack.pop();
    std::cout << "���� 6: ����� �������� ���� ���������, ���� ����? " << (intStack.isEmpty() ? "��" : "���") << std::endl;

    // ���� 7: �������� ����������
    try {
        intStack.pop(); // ������� ������� �� ������� �����
    }
    catch (const std::underflow_error& e) {
        std::cout << "���� 7: " << e.what() << std::endl; // ��������� ��������� �� ������
    }

    try {
        intStack.peek(); // ������� ���������� ������� ������� ������� �����
    }
    catch (const std::out_of_range& e) {
        std::cout << "���� 8: " << e.what() << std::endl; // ��������� ��������� �� ������
    }

    // ���� 9: ������������ �����
    for (int i = 0; i < 5; ++i) {
        intStack.push(i);
    }

    try {
        intStack.push(6); // ������� ����������� ����
    }
    catch (const std::overflow_error& e) {
        std::cout << "���� 9: " << e.what() << std::endl; // ��������� ��������� �� ������
    }
}