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
  pTask->pfTask     = NULL;
  pTask->pTaskArg   = NULL;
  pTask->u32Time    = 0;
  pTask->u32ActTime = 0;
  pTask->eTaskType  = TASKTYPE_NOP;
}

// -------------------------------------------------------
// Returns if two task structures are equal
// -------------------------------------------------------
static bool TaskIdentical(Task_t* pT1, Task_t* pT2) {
  
  return (pT1->pfTask    == pT2->pfTask)   &&
         (pT1->pTaskArg  == pT2->pTaskArg) &&
         (pT1->u32Time   == pT2->u32Time)  &&
         (pT1->eTaskType == pT2->eTaskType);
}

// -------------------------------------------------------
// Insert a new task into task list
// -------------------------------------------------------
static int InsertTask(Task_t* pTask) {

  int ret = -1;

  // Check for free task space
  for (byte i = 0; i < MAX_NUM_OF_TASKS; i++) {
     
    // There is a free space
    if (oTasks[i].eTaskType == TASKTYPE_NOP) {
      // Insert the task
      oTasks[i] = *pTask;
      ret = i;
      break;
    }
  }

  return ret;
}

// -------------------------------------------------------
// Execute a task
// -------------------------------------------------------
static void Execute(Task_t* pTask) {
  // Run the task 
  if (pTask->pfTask != NULL) {
    (*pTask->pfTask)(pTask->pTaskArg);
  }
}


/******************************************************************************
 *    P U B L I C  F U N C T I O N S                                          *
 ******************************************************************************/


// -------------------------------------------------------
// Initialises the scheduler
// -------------------------------------------------------
void SchedInit() {
  byte i;
  for(i = 0; i < MAX_NUM_OF_TASKS; i++) {
    ClearTask(&oTasks[i]);
  }
}


// -------------------------------------------------------
// Executes one "tick" of the task scheduler 
// -------------------------------------------------------
void SchedRun() {
  unsigned long u32CurrTime = millis();
  bool bIsIdle  = true;
  byte i;

  // Go through the task list
  for(i = 0; i < MAX_NUM_OF_TASKS; i++) {
    
    // check if the task has been scheduled to run now or in the past 
    if (oTasks[i].eTaskType == TASKTYPE_ONCE) {
      // task has been scheduled to execute
      if (oTasks[i].u32ActTime <= u32CurrTime) {         
          // Execute Task
          Execute(&oTasks[i]);
          // Delete Task
          ClearTask(&oTasks[i]);
      }

      if (oTasks[i].u32ActTime <= u32CurrTime + MAX_IDLE_TIME) {
          bIsIdle = false;
      }
    }
    
    else if (oTasks[i].eTaskType == TASKTYPE_CYCLIC) {
       // task has been scheduled to execute
       if (oTasks[i].u32ActTime <= u32CurrTime) {         
          // Execute Task
          Execute(&oTasks[i]);
          // Set next activation time
          oTasks[i].u32ActTime = u32CurrTime + oTasks[i].u32Time;
       }

       if (oTasks[i].u32ActTime <= u32CurrTime + MAX_IDLE_TIME) {
          bIsIdle = false;
      }
    }  
  }

  // This is an idle tick -- run through idle tasks
  if (bIsIdle) {
    // Go through the task list
    for (i = 0; i < MAX_NUM_OF_TASKS; i++) {
     
      // Execute idle tasks
      if (oTasks[i].eTaskType == TASKTYPE_IDLE)
        Execute(&oTasks[i]);
    }
  }
}


// -------------------------------------------------------
// Add a task by the application
// -------------------------------------------------------
int  AddTask(TaskType_t type, Task_fp pfTask, unsigned long Time) {

    int  ret; 
    unsigned long u32RegistrationTime = millis();
    
    Task_t oT;
    ClearTask(&oT);
    oT.eTaskType = type;
    oT.pfTask    = pfTask;
    
    // Check task type
    switch (type) {
    
    // Idle task
    case TASKTYPE_IDLE:
      // no times required     
      ret = InsertTask(&oT); 
      break;
      
    // task runs only once  
    case TASKTYPE_ONCE:
      // Set activation time
      oT.u32ActTime = u32RegistrationTime + Time;
      ret = InsertTask(&oT); 
      break;

    // Cyclic Task  
    case TASKTYPE_CYCLIC:
      // set to run on the next tick after registration
      oT.u32ActTime = 0;
      oT.u32Time = Time;
      ret = InsertTask(&oT); 
      break;

    // Invalid task
    case TASKTYPE_NOP:
    default:
     ret = -1;
  }
  return ret;
}

// -------------------------------------------------------
// Delete a task from the scheduled task list
// -------------------------------------------------------
void KillTask(int taskHandle) {

  if ((taskHandle >= 0) && (taskHandle < MAX_NUM_OF_TASKS))
  // Delete task
  ClearTask(&oTasks[taskHandle]);
  
}
