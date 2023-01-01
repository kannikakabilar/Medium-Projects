#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "cloud_subtype.h"
#include "cloud_jobs.c"
#include "cloud_queues.c"

// If the program can be executed in a linux environment 
//then a semaphore can be used in place of a mutex lock
//sem_t mutex;
extern pthread_mutex_t lock;
// Keeps track of total number of jobs executed
extern int job_count;
// A linked list that contains pointers to jobs ready for execution    
extern queue *ready_queue;
// A variable used to represent a shared resource that will be used by many jobs
extern int shared_num;

extern int cpu_cycle;

int main(void) {
    // This is a well-defined job where cpu_time is 3 and its priority is 1
    // Users can use this to create specific jobs with properties that match their needs
    job *my_job = create_job(3, 1);
    print_job(my_job);
    
    // Initialize the ready queue, so that it can start holding pointers to jobs
    ready_queue = init_queue();

    // In order to demonstrate the functionality of this program, this loop will
    // create and insert randomly generated jobs
    for(int i=0; i<10; i++){
        insert_queue(ready_queue, create_random_job());
    }

    // The ready queue before execution
    print_queue(ready_queue);
    // execute all jobs in queue    
    execute_queue(ready_queue);
    // once execution is complete, the queue will be empty
    print_queue(ready_queue);
    printf("Cloud Server completed running\n");
    return 0;
}