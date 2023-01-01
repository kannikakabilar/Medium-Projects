#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

// If the program can be executed in a linux environment 
//then a semaphore can be used in place of a mutex lock
//sem_t mutex;
pthread_mutex_t lock;
// Keeps track of total number of jobs executed
int job_count = 0;
// A linked list that contains pointers to jobs ready for execution    
queue *ready_queue;
// A variable used to represent a shared resource that will be used by many jobs
int shared_num = 0;

int cpu_cycle = 0;

// Given the lower and upper limit, helps generate random number 
// to simulate substantial amounts of job creation
int randnum(int min_num, int max_num){
    return rand()%(max_num - min_num) + min_num;
}

// Helps create a user-defined job, given its cpu time and its priority
job* create_job(int cpu_time, int priority){
    job *my_job = malloc(sizeof(job));
    job_count ++;
    my_job->job_id = job_count;
    job_count ++;
    my_job->cpu_time = cpu_time;
    my_job->wait_time = 0;
    my_job->rando = 0;
    my_job->ref_num = my_job->job_id + JOBLIMIT;
    my_job->priority = priority;
    printf("Defined Job created with id: %d, cpu time: %d, ref num: %d\n", my_job->job_id, my_job->cpu_time, my_job->ref_num);

    return my_job;

}

// Helps create random jobs to simulate the functionality of this server scheduling algorithm
job* create_random_job(){
    job *rnd_job = malloc(sizeof(job));
    rnd_job->job_id = job_count;
    job_count ++;
    rnd_job->cpu_time = randnum(1, 10);
    rnd_job->wait_time = 0;
    rnd_job->rando = 1;
    rnd_job->ref_num = rnd_job->job_id;
    rnd_job->priority = 2; //randnum(1, 2); 
    printf("Random Job created with id: %d, cpu time: %d, ref num: %d\n", rnd_job->job_id, rnd_job->cpu_time, rnd_job->ref_num);

    return rnd_job;
}

// Prints the status of the job at the given time
void print_job(job* given_job){
    printf("Job ID: %d ", given_job->job_id);
    printf("Reference#: %d ", given_job->ref_num);
    printf("Current Wait time: %d ", given_job->wait_time);
    printf("Required CPU time: %d ", given_job->cpu_time);
    if(given_job->rando){
        printf("\nThis is a randomly created job\n");
    }else{
        printf("\nThis is a well-defined job\n");
    }
}