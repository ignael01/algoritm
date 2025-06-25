#ifndef BINSTREE_H
#define BINSTREE_H
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <stack>
/**
 * @brief Узел дерева
 */
template <typename T>
// шаблон 
struct TreeNode {
    T value;
    TreeNode* left;
    TreeNode* right;

    // коснструктор 

    TreeNode(T value1, TreeNode* left1, TreeNode* right1) {
        value = value1;
        left = left1;
        right = right1;
    }
};

template <typename T>
// класс
class BinSTree {
private:
    

    TreeNode<T>* root;

    // Метод добавление
    // входные данные value

    void insert(TreeNode<T>*& node, T value) {
        if (node == nullptr) {

            node = new TreeNode<T>(value, nullptr, nullptr);
        }
        else if (value < node->value) {
            insert(node->left, value);
        }
        else {
            insert(node->right, value);
        }
    }

    
   

    

public:
    BinSTree() : root(nullptr) {}

    /*~BinSTree() {
        clear(root);
    }*/

    void insert(T value) {
        insert(root, value);
    }

    int search(T value) const {
        return search(root, value);
    }

    void clear() {
        clear(root);
    }

    int depth_() const {
        return depth(root);
    }

    int countnodes() const {
        return countNodes(root);
    }

    void printinorder()  {
        printInOrder(root);
        std::cout << std::endl;
    }

    void printpreorder() {
        printpreorder(root);
        std::cout << std::endl;
    }

    void printpostorder()  {
        printpostorder(root);
        std::cout << std::endl;
    }
    vector<int> traverse_rln() {
        vector<int> values;
        return traverse_RLN(root, values);
       /* std::cout << std::endl;*/
    }
    // Итератор
    class iterator {
    private:
        // стек который хранит указатели на узлы дерева
        stack<TreeNode<T>*> nodeStack;

        // добавляет все левые узлы в стек
        void pushLeft(TreeNode<T>* node) {
            while (node != nullptr) {
                nodeStack.push(node);
                node = node->left;
            }
        }

    public:
        // Конструктор
        iterator(TreeNode<T>* root) {
            pushLeft(root);
        }

        // Оператор разыменования
        // возвращает сылку на узел 
        T& operator*() {
            return nodeStack.top()->value;
        }

        // Оператор инкрементации
        //для перемещение итератора на следующий узел 

        iterator& operator++() {
            TreeNode<T>* node = nodeStack.top();
            nodeStack.pop();
            if (node->right != nullptr) {
                pushLeft(node->right);
            }
            return *this;
        }

        // Проверка на равенство
        // сравнивает текущий итератор с другим
        bool operator!=(const iterator& other) const {
            return nodeStack != other.nodeStack;
        }
    };
    // 
    iterator begin() {
        return iterator(root);
    }

    iterator end() {
        return iterator(nullptr);
    }
};

// метод пойска  функция  bigO(log2(n))
// возвращаемый тип указатель 
// при ненахождении nullptr
// при нахождение указатель на узел в котором находиться искомое значение 
template <typename T>
TreeNode<T>* search(TreeNode<T>* node, T value)  {

    if (node == nullptr) return nullptr;
    if (node->value == value) return node ;
    return value < node->value ? search(node->left, value) : search(node->right, value);
}

// метод очистки 
//*& - сылка на указатель, нужен для модификации адреса 
template <typename T>
void clear(TreeNode<T>*& node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }
}

// функция глубина
template <typename T>
int depth(TreeNode<T>* node)  {
    if (node == nullptr) return 0;
    int leftDepth = depth(node->left);
    int rightDepth = depth(node->right);
    return 1 + std::max(leftDepth, rightDepth);
}

// функция узла подсчета
template <typename T>
int countNodes(TreeNode<T>* node)  {
    if (node == nullptr) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

template <typename T>
void printInOrder(TreeNode<T>* node)  {
    if (node) {
        printInOrder(node->right);
        printInOrder(node->left);
        std::cout << node->value << " ";
        
    }
}
template <typename T>
void printPreOrder(TreeNode<T>* node)  {
    if (node) {
        std::cout << node->value << " ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}
template <typename T>
void printPostOrder(TreeNode<T>* node)  {
    if (node) {
        printPostOrder(node->left);
        printPostOrder(node->right);
        std::cout << node->value << " ";
    }
}

// функция обхода типа RLN, входные данные узел, пустой массив, который будет заполняться. 
template <typename T>
vector<T> traverse_RLN(TreeNode<T>* root, vector<T> values) {
    // Проверка на пустое дерево
    if (root == nullptr) {
        return values;
    }
    else {
        // Обход правого поддерева
        values = traverse_RLN(root->right, values); // R
        // Обход левого поддерева
        values = traverse_RLN(root->left, values);  // L
        // Добавление текущего узла
        values.push_back(root->value); // N
    }
    return values;
}



#endif // BINSTREE_H



