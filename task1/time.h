#pragma once
#include <iostream>
#include <chrono>
#include <iomanip>
class Timer {
public:
    Timer() : running(false) {}

    void start() {
        if (!running) {
            start_time = std::chrono::high_resolution_clock::now();
            running = true;
            
        }
        else {
            std::cout << "������ ��� �������." << std::endl;
        }
    }

    double stop() {
        if (running) {
            auto end_time = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end_time - start_time;
            running = false;
            
            return(elapsed.count());
        }
        else {
            std::cout << "������ ��� ����������." << std::endl;
            return(-1.0);
        }
    }
    // ������ ��� ���������� running
    bool isRunning() const {
        return running;
    }

private:
    bool running;  // ����, �����������, ������� �� ������
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;  // ����� ������


};

int _time_();