#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "shared_resources.c"

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

// Initializes queue by setting a dummy node as the identifying pointer
queue* init_queue(){
    queue* my_queue = malloc(sizeof(queue));
    node *head_node = malloc(sizeof(node));
    head_node->id = 0;
    head_node->prev = head_node;
    head_node->next = NULL;
    head_node->node_job = create_job(-1, 2);
    my_queue->count = 0;
    my_queue->front = head_node;
    my_queue->end = head_node;
    return my_queue;
}

// Given a job, it will be inserted at the end of the queue 
// as this insert function follows FCFS
void insert_queue(queue* given_queue, job* add_job){
    node *my_node = malloc(sizeof(node));
    my_node->id = add_job->job_id;
    my_node->node_job = add_job;
    my_node->next = NULL;
    
    my_node->prev = given_queue->end;
    given_queue->end->next = my_node;
    given_queue->end = my_node;
    given_queue->count += 1;

}

// Given a unique job_id and a queue, the particular node pointing to the specific job_id 
// will be deleted, else if the node is not found the queue will remain unchanged
void del_queue(queue* given_queue, int job_id){
    node* to_del = given_queue->front;
    if(to_del->id == 0){
        to_del = to_del->next;
    }
    if(given_queue->count != 0){
        while(to_del != NULL){
            if(to_del->id == job_id){
                to_del->prev->next = to_del->next;
                if(to_del->next){
                    to_del->next->prev = to_del->prev;
                }
                free(to_del);
                given_queue->count -= 1;
                break;
            }
            to_del = to_del->next;
        }
    }
}

// Given a queue, all of its jobs will be executed and removed if the jobs complete execution
void execute_queue(queue* given_queue){
    node* curr_node = given_queue->front;
    //sem_init(&mutex, 0, 1);
    pthread_mutex_init(&lock, NULL);
    if(curr_node->id == 0){
        curr_node = curr_node->next;
    }

    // Create a thread for each job node and send it to execution all at once
    node* tmp_node = curr_node;
    while(curr_node != NULL){
        printf("Sending for execution, job id: %d\n", curr_node->id);
        pthread_create(&curr_node->node_job->job_thread, NULL, cpu, curr_node->node_job);
        curr_node = curr_node->next;
    }
    
    // Collect the threads once they have completed the execution
    // and delete from queue if the have completed their cpu time
    curr_node = given_queue->front;
    if(curr_node->id == 0){
        curr_node = curr_node->next;
    }
    while(curr_node != NULL){
        pthread_join(curr_node->node_job->job_thread, NULL);
        printf("Done executing job id: %d\n", curr_node->id);
        if(curr_node->node_job->cpu_time == 0){
            tmp_node = curr_node;
            del_queue(given_queue, curr_node->id);
            curr_node = tmp_node->next;
            continue;
        }
        tmp_node = curr_node;
        del_queue(given_queue, curr_node->id);
        insert_queue(given_queue, tmp_node->node_job);
        curr_node = tmp_node->next;
    } 
    //sem_destroy(&mutex);
    pthread_mutex_destroy(&lock);
}

// Prints the given queue for a visual representation of what it contains
void print_queue(queue* given_queue){
    node* curr_node = given_queue->front;
    if(curr_node->id == 0){
        curr_node = curr_node->next;
    }
    while(curr_node != NULL){
        printf("Node id: %d ->", curr_node->id);
        curr_node = curr_node->next;
    } 
    if(given_queue->count == 0){
        printf("[Queue is Empty]");
    }
    printf("\n");
}