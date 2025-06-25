#include "BinSTree.h"
using namespace std;
#include <vector>


#include <assert.h> 
void asert_() {
    //одиночный пень 

    
    TreeNode<int>* root = new TreeNode<int>(1, nullptr, nullptr);
    
    
    //assert(traverse_RLN(root, []) == "1 "); // ответ 1

    root->left = new TreeNode<int>(2, nullptr, nullptr);
    root->right = new TreeNode<int>(3, nullptr, nullptr);

    root->left->left = new TreeNode<int>(4, nullptr, nullptr);
    root->left->right = new TreeNode<int>(5, nullptr, nullptr);

    root->right->right = new TreeNode<int>(6, nullptr, nullptr);
    
    
    vector<int> values;
    values = traverse_RLN(root, values);

    // Ожидаемые значения
    std::vector<int> expected = { 6, 3, 5, 4, 2, 1 };
    
    // Проверка содержимого вектора с помощью assert
    assert(values.size() == expected.size()); // Сначала проверяем размер
    for (size_t i = 0; i < expected.size(); ++i) {
        assert(values[i] == expected[i]); // Сравниваем элементы
    }
    
    assert(depth(root) == 3); // 3
    assert(countNodes(root) == 6);
    assert(search(root, 3) == root->right);
    // обьект- переменая - 
    // тип данных tree   шаблоный тип BinSTree с хранящимися в нем перемеными типа int 
    BinSTree<int> tree;
    cout << "\n";

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);

    
    
    values = tree.traverse_rln();
    // Ожидаемые значения
    expected.clear();
    expected = { 7,4,1,3,5};
     //tree.printinorder();
    // Проверка содержимого вектора с помощью assert
    assert(values.size() == expected.size()); // Сначала проверяем размер
    for (size_t i = 0; i < expected.size(); ++i) {
        assert(values[i] == expected[i]); // Сравниваем элементы
    }
    //cout << tree.depth_();
    assert(tree.depth_() == 3); // 3
    /*cout << tree.countnodes();*/
    assert(tree.countnodes() == 5);
    //assert(tree.search(3) == tree);
    values.clear();

    // it  итератор определяется автоматически 
    //begin имеет тип возвращаемого значения итератора который указывает на узел 
    //энд имеет тип возвращаемого значения iterator который определяет последнии узел на пустоту
    for (auto it = tree.begin(); it != tree.end(); ++it) {
        //*it получить доступ к значению на котором находитсья it
        
        values.push_back(*it) ;
    }
    expected.clear();
    expected = { 1,3,4,5,7 };
    //tree.printinorder();
   // Проверка содержимого вектора с помощью assert
    assert(values.size() == expected.size()); // Сначала проверяем размер
    for (size_t i = 0; i < expected.size(); ++i) {
        assert(values[i] == expected[i]); // Сравниваем элементы
    }
    
}

int main() {
    setlocale(LC_ALL, "Russian");
    asert_(); // тесты

    TreeNode<int>* root = new TreeNode<int>(1, nullptr, nullptr);
    root->left = new TreeNode<int>(2, nullptr, nullptr);
    root->right = new TreeNode<int>(3, nullptr, nullptr);

    root->left->left = new TreeNode<int>(4, nullptr, nullptr);
    root->left->right = new TreeNode<int>(5, nullptr, nullptr);

    root->right->right = new TreeNode<int>(6, nullptr, nullptr);
    std::vector<int> values;
    
    values= traverse_RLN(root, values);
    for (int val : values) {
        cout << val << " ";
    }
    
    /*
    * 
    *                1
    *              2    3
    *           4   5       6
    
    */
   
    
    /*cout << "\n";
    printInOrder(root);
    cout << "\n" ;
    cout <<  depth(root);
    cout << "\n";
    cout << countNodes(root);*/
    cout << "\n";
    cout << search(root,6);
   /* clear(root);
    printPreOrder(root);
    cout << "\n";
    printPostOrder(root);*/

    BinSTree<int> tree;
    cout << "\n";
    
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.printinorder();

    std::cout << "Элементы дерева в порядке возрастания: ";
    // позволяет автоматически определять тип итератор 
    // 
    for (auto it = tree.begin(); it != tree.end(); ++it) {
        std::cout << *it << " ";
    }
    //std::cout << "Дерево в порядке возрастания: ";
    //tree.printInOrder; // Вывод: 1 3 4 5 7

    //int searchValue = 4;
    //if (search(tree,searchValue)) {
    //    std::cout << searchValue << " найдено в дереве." << std::endl;
    //}
    //else {
    //    std::cout << searchValue << " не найдено в дереве." << std::endl;
    //}

   



    //tree.clear(); // Очистка дерева

    /*
    * 
    *                1
    *              2    3
    *           4   5       6
    
    */
   
    
    cout << "\n";
    return 0;
}



