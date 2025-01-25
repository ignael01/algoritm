#include "database.h"
#include <iostream>
#include <fstream>
using namespace std;

void database_sort(double time[], double time_2[], double time_3[], double time_4[], int koll, int len[]) {
    // �������� � �������� ���������� �����
    ofstream MyFile("poisk.csv");
    // ������ �������
    for (size_t i = 0; i < koll; i++)
    {
        MyFile << len[i]<< ","<< time[i]<< ","<< time_2[i]; // ������ ������ � ����
        
        MyFile << "\n";
    }



}




void database(double time_good[], double time_badle[], double time[], double time_bin_good[], double time_bin_badle[], double time_bin[], int koll, int len[]) {
    // �������� � �������� ���������� �����
    ofstream MyFile("sort.csv");
    
    // ������ ������� 
    // ��� ����������������� ������
    for (size_t i = 0; i < koll; i++)
    {
        MyFile <<len[i]<<","<< time_good[i] << "," << time_badle[i] << "," << time[i] ; // ������ ������ � ����

        MyFile << "\n";
    }

    ofstream MyFile_bin("sort_bin.csv");

    // ������ ������� 
    // ��� ����������������� ������
    for (size_t i = 0; i < koll; i++)
    {
        MyFile_bin << len[i] << "," << time_bin_good[i] << "," << time_bin_badle[i] << "," << time_bin[i]; // ������ ������ � ����

        MyFile_bin << "\n";
    }

}
   



void database_array(double array[],size_t length) {
    // �������� � �������� ���������� �����
    ofstream MyFile("array.csv");

    // ������ �������
    for (size_t i = 0; i < length; i++)
    {
        MyFile << array[i] ; // ������ ������ � ����

        MyFile << "\n";
    }

}