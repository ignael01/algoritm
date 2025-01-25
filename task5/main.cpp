
/*
* поствиксный калькулятор
* 
* Реализуйте алгоритм постфиксного калькулятора, на основе собственного класса стека. Реализуйте операции сложения, вычитания, умножения и деления.
Создайте тесты для калькулятора. Тестируйте математические операции отдельно и в составе сложных выражений.


*/
#include <iostream>
#include "..\task4\ctack.h"
#include <sstream>
#include <string>
#include <cctype>
#include < assert.h> 
//  считает постфиксное выражение
int evaluatePostfix(const std::string& expression) {
    Stack<int> stack(expression.size());// стек 
    std::istringstream iss(expression);// длина
    std::string token; // переменая которая разбирает строку по символьно

    while (iss >> token) {
        if (std::isdigit(token[0])) { // Если токен - число
            stack.push(std::stoi(token));
        }
        else { // Если токен - оператор
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
                    std::cerr << "Ошибка: Деление на ноль" << std::endl;
                    return 0;
                }
                break;
            case ' ':
                std::cout << " ебучий пробел";
                break;
            default:
                std::cerr << "Ошибка: Неизвестный оператор " << token << std::endl;
                return 0;
            }
        }
    }

    return stack.peek(); // Результат
}

int main() {
    {
        // ((3+4)*2)-7=7
        assert(evaluatePostfix("3 4 + 2 * 7 -") ==7);
        // ((45+4)*2)-7=91
        assert(evaluatePostfix("45 4 + 2 * 7 -") == 91);
        // assert  с простыми значениями
    }
    setlocale(LC_ALL, "Russian");
    std::string expression;

   std::cout << "Введите постфиксное выражение (например, '3 4 + 2 * 7 -'): ";
   std::getline(std::cin, expression);

    int result = evaluatePostfix(expression);
    std::cout << "Результат: " << result << std::endl;
    
    
}