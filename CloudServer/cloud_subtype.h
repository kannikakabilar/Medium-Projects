#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

// This is not an upperlimit but a number set to uniquely identify between user-defined jobs and randomly created jobs
#define JOBLIMIT 100 
// When Jobs are placed in the round_robin queue, this is defined to be their time-quanta
#define ROUNDROBIN_TIMEQUANTA 2 

// Each job is treated like a process, so this struct is used to hold information about the job during its execution
typedef struct PCB {
    // Each job is given a unique job id
    int job_id;
    // The remaining cpu time the job requires to complete execution
    int cpu_time;
    // The amount of time that the job has been waiting in the queue
    int wait_time;
    // Set to 1 if this job was randomly created
    int rando; 
    // A unique identification given to user to identify the state of the job  
    int ref_num;
    // The job will get placed in the multi-level queue based on its priority
    int priority;
    // Each job will be executing on its own thread
    pthread_t job_thread;
} job;

// When a job is required to be inserted into the ready queue for execution, 
// a node is used to point at the job while holding the place in the queue
typedef struct node{
    int id;
    job* node_job;
    struct node *next;
    struct node *prev;
} node;

// The ready queue is designed using the doubly linked list structure where each element
// is a node that points to the previous, and next node and its corresponding job
typedef struct linked_list{
    int count; // contains the number of elemnts stored in the linked list
    int round_robin; // Equals 1 if its a round robin queue else 0
    node *front;
    node *end;
} queue;
