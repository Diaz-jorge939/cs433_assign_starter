/**
* Assignment 3: CPU Scheduler
 * @file scheduler_sjf.cpp
 * @author Jorge Diaz
 * @brief This Scheduler class implements the SJF scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "scheduler_sjf.h"

#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief Constructor for the ReadyQueue class.
 */
SchedulerSJF::SchedulerSJF()  {
    // process_turnaround_times = new vector<int>();
    // process_wait_times = new vector<int>();
}
/**
 *@brief Destructor
*/
SchedulerSJF::~SchedulerSJF(){
    // delete process_turnaround_times;
    // delete process_wait_times;
}
static bool compareByBurstTime(const PCB& a, const PCB& b) {
    return a.burst_time < b.burst_time;
}
/**
 * @brief This function is called once before the simulation starts.
 *        It is used to initialize the scheduler.
 * @param process_list The list of processes in the simulation.
 */
void SchedulerSJF::init(std::vector<PCB>& process_list){
    sort(process_list.begin(), process_list.end(), compareByBurstTime);

    for (size_t i=0; i < process_list.size(); i++) 
        process_list_copy.push_back(process_list[i]);
}
/**
 * @brief This function is called once after the simulation ends.
 *        It is used to print out the results of the simulation.
 */
void SchedulerSJF::print_results() {
    int tt_sum = 0;
    int wt_sum = 0;

//     for (size_t i = 0; i < process_list_copy.size(); i++)
//     {
//         cout << process_list_copy.at(i).name << " turn-around time = " << process_turnaround_times->at(i) << ", waiting time = " << process_wait_times->at(i) << endl;
//         tt_sum += process_turnaround_times->at(i);
//         wt_sum += process_wait_times->at(i);
//     }
        for (size_t i = 0; i < process_list_copy.size(); i++)
        {
            cout << process_list_copy.at(i).name << " turn-around time = " << process_list_copy.at(i).turnaround_time << ", waiting time = " << process_list_copy.at(i).wait_time << endl;
            tt_sum += process_list_copy.at(i).turnaround_time;
            wt_sum += process_list_copy.at(i).wait_time;
        }
        cout << "Average turn-around time = " << (float)tt_sum/process_list_copy.size() << ", waiting time = " << (float)wt_sum / process_list_copy.size() << endl;
//     cout << "Average turn-around time = " << (float)tt_sum/process_turnaround_times->size() << ", waiting time = " << (float)wt_sum / process_wait_times->size() << endl;
}
/**
 * @brief This function simulates the scheduling of processes in the ready queue.
 *        It stops when all processes are finished.
 */
void SchedulerSJF::simulate(){
   int wt = 0;     // waiting time accumulator 

    // for (size_t i = 0; i < process_list_copy.size(); i++)
    // {
    //     cout << "Running Process " << process_list_copy.at(i).name << " for" << process_list_copy.at(i).burst_time << " time units" << endl;
    //     process_wait_times->push_back(wt);         // inserting waiting time
    //     wt = wt + process_list_copy.at(i).burst_time;      // turnaround time = waiting time + burst time
    //     process_turnaround_times->push_back(wt);   //inserting turnaround time
    // }
    for (size_t i = 0; i < process_list_copy.size(); i++)
    {
        cout << "Running Process " << process_list_copy.at(i).name << " for" << process_list_copy.at(i).burst_time << " time units" << endl;
        process_list_copy.at(i).wait_time = wt;         // inserting waiting time
        wt = wt + process_list_copy.at(i).burst_time;      // turnaround time = waiting time + burst time
        process_list_copy.at(i).turnaround_time = wt;   //inserting turnaround time
    }
}