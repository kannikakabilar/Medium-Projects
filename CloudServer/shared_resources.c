#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

/* More shared resources can be included in this file to be accesses by the various jobs */

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

/*  Each job's cpu time is added to the shared num to demonstarte the amount of cpu cycle it
    uses while in the critical section
*/
void* cpu(void* given_job){
    // Before entering the critical section to access and modify the shared resource,
    // each thread must acquire the lock to prevent race conditions
    //sem_wait(&mutex);
    pthread_mutex_lock(&lock);
    sleep(3);
    
    // If the job is from a round robin queue then it must only use the define time quanta
    if(((job *)given_job)->priority == 1 && ((job *)given_job)->cpu_time > ROUNDROBIN_TIMEQUANTA){
        shared_num += ROUNDROBIN_TIMEQUANTA;
        ((job *)given_job)->cpu_time -= ROUNDROBIN_TIMEQUANTA;
        cpu_cycle = ROUNDROBIN_TIMEQUANTA;
    }else{
        shared_num += ((job *)given_job)->cpu_time;
        ((job *)given_job)->cpu_time = 0;
        cpu_cycle = ((job *)given_job)->cpu_time;
    }
    printf("Job ID: %d completed execution on shared resource: %i\n", ((job *)given_job)->job_id, shared_num);
    
    // Unlock to allow other threads to enter the critical section
    //sem_post(&mutex);
    pthread_mutex_unlock(&lock);
    return given_job;
}