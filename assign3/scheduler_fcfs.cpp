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

/**
 * @brief Constructor for the ReadyQueue class.
 */
 SchedulerFCFS::SchedulerFCFS()  {
 }

/**
 *@brief Destructor
*/
SchedulerFCFS::~SchedulerFCFS() {
}

/**
 * @brief This function is called once before the simulation starts.
 *        It is used to initialize the scheduler.
 * @param process_list The list of processes in the simulation.
 */
void SchedulerFCFS::init(std::vector<PCB>& process_list){
    for (size_t i=0; i< process_list.size(); i++) 
        process_list_copy.push_back(process_list[i]);
}
/**
 * @brief This function is called once after the simulation ends.
 *        It is used to print out the results of the simulation.
 */
void SchedulerFCFS::print_results() {
    int tt_sum = 0;
    int wt_sum = 0;

    for (size_t i = 0; i < process_list_copy.size(); i++)
    {
        cout << process_list_copy.at(i).name << " turn-around time = " << process_list_copy.at(i).turnaround_time << ", waiting time = " << process_list_copy.at(i).wait_time << endl;
        tt_sum += process_list_copy.at(i).turnaround_time;
        wt_sum += process_list_copy.at(i).wait_time;
    }

    cout << "Average turn-around time = " << (float)tt_sum/process_list_copy.size() << ", waiting time = " << (float)wt_sum / process_list_copy.size() << endl;
}

/**
 * @brief This function simulates the scheduling of processes in the ready queue.
 *        It stops when all processes are finished.
 */
void SchedulerFCFS::simulate(){
    int wt = 0;     // waiting time accumulator 
    
    for (size_t i = 0; i < process_list_copy.size(); i++){
        cout << "Running Process " << process_list_copy.at(i).name << " for" << process_list_copy.at(i).burst_time << " time units" << endl;
        process_list_copy.at(i).wait_time = wt;             // 
        wt = wt + process_list_copy.at(i).burst_time;      // turnaround time = waiting time + burst time
        process_list_copy.at(i).turnaround_time = wt;
    }

}
