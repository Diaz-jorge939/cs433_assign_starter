/**
* Assignment 3: CPU Scheduler
 * @file scheduler_fcfs.cpp
 * @author Jorge Diaz
 * @brief This Scheduler class implements the FCSF scheduling algorithm.
 * @version 0.1
 */

#include "scheduler_fcfs.h"

// TODO: add implementation of SchedulerFCFS constructor, destrcutor and 
// member functions init, print_results, and simulate here

/**
 * @brief Constructor for the ReadyQueue class.
 */
 SchedulerFCFS::SchedulerFCFS()  {
     //TODO: add your code here
 }

/**
 *@brief Destructor
*/
SchedulerFCFS::~SchedulerFCFS() {
    //TODO: add your code to release dynamically allocate memory
}

/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void SchedulerFCFS::init(std::vector<PCB>& process_list){
    //TODO: add your code here
    // When adding a PCB to the queue, you must change its state to READY.
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
void SchedulerFCFS::print_results() {
    //TODO: add your code here
    // When removing a PCB from the queue, you must change its state to RUNNING.
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
void SchedulerFCFS::simulate(){
    //TODO: add your code here 
}
