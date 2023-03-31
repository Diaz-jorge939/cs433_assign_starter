/**
* Assignment 3: CPU Scheduler
 * @file scheduler_fcfs.cpp
 * @author Jorge Diaz
 * @brief This Scheduler class implements the FCSF scheduling algorithm.
 * @version 0.1
 */

#include "scheduler_fcfs.h"
#include <iostream>
#include <string>
using namespace std;

// TODO: add implementation of SchedulerFCFS constructor, destrcutor and 
// member functions init, print_results, and simulate here

/**
 * @brief Constructor for the ReadyQueue class.
 */
 SchedulerFCFS::SchedulerFCFS()  {
    proc_name = new vector<string>();
    proc_burst_times = new vector<int>();
    proc_turnaround_times = new vector<int>();
    proc_wait_times = new vector<int>();
 }

/**
 *@brief Destructor
*/
SchedulerFCFS::~SchedulerFCFS() {
    delete proc_name;
    delete proc_burst_times;
    delete proc_wait_times;
    delete proc_turnaround_times;
}

/**
 * @brief This function is called once before the simulation starts.
 *        It is used to initialize the scheduler.
 * @param process_list The list of processes in the simulation.
 */
void SchedulerFCFS::init(std::vector<PCB>& process_list){
    for (int i = 0; i < process_list.size(); i++) {
        proc_name->push_back(process_list[i].name);
        proc_burst_times->push_back(process_list[i].burst_time);
    }
}
/**
 * @brief This function is called once after the simulation ends.
 *        It is used to print out the results of the simulation.
 */
void SchedulerFCFS::print_results() {
    int tt_sum = 0;
    int wt_sum = 0;

    for (size_t i = 0; i < proc_burst_times->size(); i++)
    {
        cout << proc_name->at(i) << " turn-around time = " << proc_turnaround_times->at(i) << ", waiting time = " << proc_wait_times->at(i) << endl;
        tt_sum += proc_turnaround_times->at(i);
        wt_sum += proc_wait_times->at(i);
    }

    cout << "Average turn-around time = " << (float)tt_sum/proc_turnaround_times->size() << ", waiting time = " << (float)wt_sum / proc_wait_times->size() << endl;
}

/**
 * @brief This function simulates the scheduling of processes in the ready queue.
 *        It stops when all processes are finished.
 */
void SchedulerFCFS::simulate(){
    int wt = 0;     // waiting time accumulator 

    for (size_t i = 0; i < proc_burst_times->size(); i++)
    {
        cout << "Running Process " << proc_name->at(i) << " for" << proc_burst_times->at(i) << " time units" << endl;
        proc_wait_times->push_back(wt);         // inserting waiting time
        wt = wt + proc_burst_times->at(i);      // turnaround time = waiting time + burst time
        proc_turnaround_times->push_back(wt);   //inserting turnaround time
    }
}
