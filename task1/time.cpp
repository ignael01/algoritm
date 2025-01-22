#include "time.h"
#include <chrono>
#include <iostream>


// � ���� �� ��������� ��� ���� �����������
int _time_() {


	using namespace std::chrono;


	// ��������� ������� �������
	auto t0 = steady_clock::now();
	
	// �������� ������� �������
	auto t1 = steady_clock::now();
	// �������������� ������� (������ �����������) � ������������
	auto delta = duration_cast<milliseconds>(t1 - t0);
	std::cout << "time delta (milliseconds) " << delta.count();
	return (0) ;

}
