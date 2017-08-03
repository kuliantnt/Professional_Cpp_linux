#include <iostream>
#include "Process.h"

int main(int argc, char** argv) {
    std::vector <Process> processes = {Process("1"), Process("2"), Process("3")};
    Scheduler scheduler(processes);
    for(int i = 0; i!=4; ++i) {
        scheduler.schedulerTimeSlice();
    }
    scheduler.removeProcess(processes[1]);
    std:: cout << "Removed second process"<< std::endl;
    for(int i = 0; i!=4; ++i) {
        scheduler.schedulerTimeSlice();
    }
    return 0;
}
