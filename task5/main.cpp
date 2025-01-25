
/*
* ����������� �����������
* 
* ���������� �������� ������������ ������������, �� ������ ������������ ������ �����. ���������� �������� ��������, ���������, ��������� � �������.
�������� ����� ��� ������������. ���������� �������������� �������� �������� � � ������� ������� ���������.


*/
#include <iostream>
#include "..\task4\ctack.h"
#include <sstream>
#include <string>
#include <cctype>
#include < assert.h> 
//  ������� ����������� ���������
int evaluatePostfix(const std::string& expression) {
    Stack<int> stack(expression.size());// ���� 
    std::istringstream iss(expression);// �����
    std::string token; // ��������� ������� ��������� ������ �� ���������

    while (iss >> token) {
        if (std::isdigit(token[0])) { // ���� ����� - �����
            stack.push(std::stoi(token));
        }
        else { // ���� ����� - ��������
            int right = stack.peek(); stack.pop();
            int left = stack.peek(); stack.pop();
            switch (token[0]) {
            case '+':
                stack.push(left + right);
                break;
            case '-':
                stack.push(left - right);
                break;
            case '*':
                stack.push(left * right);
                break;
            case '/':
                if (right != 0) {
                    stack.push(left / right);
                }
                else {
                    std::cerr << "������: ������� �� ����" << std::endl;
                    return 0;
                }
                break;
            case ' ':
                std::cout << " ������ ������";
                break;
            default:
                std::cerr << "������: ����������� �������� " << token << std::endl;
                return 0;
            }
        }
    }

    return stack.peek(); // ���������
}

int main() {
    {
        // ((3+4)*2)-7=7
        assert(evaluatePostfix("3 4 + 2 * 7 -") ==7);
        // ((45+4)*2)-7=91
        assert(evaluatePostfix("45 4 + 2 * 7 -") == 91);
        // assert  � �������� ����������
    }
    setlocale(LC_ALL, "Russian");
    std::string expression;

   std::cout << "������� ����������� ��������� (��������, '3 4 + 2 * 7 -'): ";
   std::getline(std::cin, expression);

    int result = evaluatePostfix(expression);
    std::cout << "���������: " << result << std::endl;
    
    
}