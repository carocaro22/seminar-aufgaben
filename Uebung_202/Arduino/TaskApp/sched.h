/******************************************************************************
 * Demonstrator of a simple non-preemptive scheduler                          *
 * sched.h                                                                    *
 *                                                                            *
 * Module: "Embedded Systems 2" - Uebung 2-2                                  *
 *                                                                            *
 * Hochschule Mittweida, INW                                                  *
 * Prof. J. Thomanek                                                          *
 *                                                                            *
 ******************************************************************************/

#ifndef __SCHED_H__
#define __SCHED_H__

/******************************************************************************
 *   C O N S T A N T S                                                        *
 ******************************************************************************/

#define MAX_NUM_OF_TASKS  10  // maximum number of tasks handled by the scheduler 
#define MAX_IDLE_TIME     20  // Maximum duration of idle tasks

/******************************************************************************
 *   T Y P E  D E F I N I T I O N S                                           *
 ******************************************************************************/

// Task types
typedef enum {
	TASKTYPE_NOP,      // No operation - empty
	TASKTYPE_IDLE,     // Idle tasks - run if there are no active scheduled tasks
	TASKTYPE_ONCE,     // Runs only one at specified time offset after registration
	TASKTYPE_CYCLIC    // Runs every specified time intervall
}TaskType_t;

// Function pointer of tasks
typedef void (*Task_fp)(void *);

// Task structure
typedef struct {
	
	Task_fp       pfTask;     // the task function pointer 
	void*         pTaskArg;   // task arguments
	unsigned long u32Time;    // Cycle time
	unsigned long u32ActTime; // Next activation time
	TaskType_t    eTaskType;  // Task Type
}Task_t ;


/******************************************************************************
 *   F U N C T I O N S  D E C L A R A T I O N                                 *
 ******************************************************************************/
// Scheduler Initialization
void SchedInit();

// Scheduler process
void SchedRun();

// Register an new task
int AddTask(TaskType_t    type, 
             Task_fp       pfTask, 
             unsigned long u32Time);

// Cancel an existing task
void KillTask(int taskHandle);

#endif
