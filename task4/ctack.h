#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* arr;         // ������ ��� �������� ��������� �����
    int capacity;   // ����������� �����
    int top;        // ������ �������� �������� �����

public:
    Stack(int size) : capacity(size), top(-1) {
        arr = new T[capacity]; // ��������� ������ ��� �������
    }

    ~Stack() {
        delete[] arr; // ������������ ������
    }
    // ���������� ��������
    void push(T value) {
        if (top == capacity - 1) {
            throw std::overflow_error("���� ����������!"); // ���������� ��� ������������
        }
        arr[++top] = value; // ����������� ������ � ��������� �������
    }
    //�������� ��������
    void pop() {
        if (top == -1) {
            throw std::underflow_error("���� ����!"); // ���������� ��� ������� ������� �� ������� �����
        }
        --top; // ��������� ������, ��� ����� ������ ������� �������
    }
    // ������� ������� ���������
    T peek() const {
        if (top == -1) {
            throw std::out_of_range("���� ����!"); // ���������� ��� ������� ���������� ������� ������� ������� �����
        }
        return arr[top]; // ���������� ������� �������
    }
    // ���������, ���� �� ����
    bool isEmpty() const {
        return top == -1; 
    }
    // ���������� ���������� ��������� � �����
    int size() const {
        return top + 1; 
    }
};
