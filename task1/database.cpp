#include "database.h"
#include <iostream>
#include <fstream>
using namespace std;

void database(double time[], int koll, int len[]) {
    // �������� � �������� ���������� �����
    ofstream MyFile("test.csv");
    // ������ �������
    for (size_t i = 0; i < koll; i++)
    {
        MyFile << time[i] << ", "; // ������ ������ � ����
        
    }
    //������ ����� �������
    MyFile << std::endl;
    for (size_t i = 0; i < koll; i++)
    {
        MyFile << len[i] << ", "; // ������ ������ � ����

    }

}

