//
// Created by lianlian on 17-7-15.
//

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "RoundRobin.h"

//Simple Process class
class Process
{
public:
    Process(const std::string& name) : mName(name){};
    void doWorkDuringTimeSlice(){
        std::cout << "Process "<< mName << " Performing work during time slice." << std::endl;
    }
    bool operator==(const Process &rhs){
        return mName == rhs.mName;
    }
private:
    std::string mName;
};


//Simple round-rodin based process scheduler
class Scheduler{
public:
    Scheduler(const std::vector<Process>& process);
    void schedulerTimeSlice();
    void removeProcess(const Process& process);
private:
    RoundRobin<Process> rr;
};

Scheduler::Scheduler(const std::vector<Process> &processes) {
    for(auto& process : processes){
        rr.add(process);
    }
}

void Scheduler::schedulerTimeSlice() {
    try{
        rr.getNext().doWorkDuringTimeSlice();
    }catch(std::out_of_range& e){
        std::cerr << "No more processes to schedule." << std::endl;
    }
}

void Scheduler::removeProcess(const Process &process) {
    rr.remove(process);
}

