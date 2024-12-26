/******************************************************************************
 * Demonstrator of a simple non-preemptive scheduler                          *
 * sched.cpp                                                                  *
 *                                                                            *
 * Module: "Embedded Systems 2" - Uebung 2-2                                  *
 *                                                                            *
 * Hochschule Mittweida, INW                                                  *
 * Prof. J. Thomanek                                                          *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
 *   I N C L U D E S                                                          *
 ******************************************************************************/
#include <Arduino.h>
#include "sched.h"


/******************************************************************************
 *   M O D U L E  L O C A L  D A T A                                          *
 ******************************************************************************/

// Task list
static Task_t oTasks[MAX_NUM_OF_TASKS];


/******************************************************************************
 *    L O C A L  F U N C T I O N S                                            *
 ******************************************************************************/

// -------------------------------------------------------
// Reset Task structure
// -------------------------------------------------------
static void ClearTask(Task_t* pTask) {
  // ---> TODO: Implementation <---
}

// -------------------------------------------------------
// Returns if two task structures are equal
// -------------------------------------------------------
static bool TaskIdentical(Task_t* pT1, Task_t* pT2) {
  bool res = false;
  // ---> TODO: Implementation <---
  return res;
}

// -------------------------------------------------------
// Insert a new task into task list
// -------------------------------------------------------
static int InsertTask(Task_t* pTask) {

  int ret = -1;
  // ---> TODO: Implementation <---
  return ret;
}

// -------------------------------------------------------
// Execute a task
// -------------------------------------------------------
static void Execute(Task_t* pTask) {
  // ---> TODO: Implementation <---
}


/******************************************************************************
 *    P U B L I C  F U N C T I O N S                                          *
 ******************************************************************************/

// -------------------------------------------------------
// Initialises the scheduler
// -------------------------------------------------------
void SchedInit() {
  // ---> TODO: Implementation <---
}


// -------------------------------------------------------
// Executes one "tick" of the task scheduler 
// -------------------------------------------------------
void SchedRun() {
  // ---> TODO: Implementation <---
}


// -------------------------------------------------------
// Add a task by the application
// -------------------------------------------------------
int  AddTask(TaskType_t type, Task_fp pfTask, unsigned long Time) {
  int  ret = 0; 
  // ---> TODO: Implementation <---    
  return ret;
}

// -------------------------------------------------------
// Delete a task from the scheduled task list
// -------------------------------------------------------
void KillTask(int taskHandle) {
  // ---> TODO: Implementation <---
}
