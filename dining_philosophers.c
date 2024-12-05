//volataile zmienna ulotna przy kazdym odwoaniu do zmiennej sprawdzenie rejestru
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

struct threadData {
    pthread_t threadID;
    int philosopherNumber;
};

void *function(void *p);

pthread_mutex_t forks[5];
struct threadData philosopher[5]; 

int main() {
    struct threadData philosopher[5]; 
    int i,k;

    for(i=0;i<5;i++) {
        k=pthread_mutex_init(&forks[i],NULL);
        if(k==-1) {
            printf("\n Mutex initialization failed");
            exit(1);
        }
    }

    for(i=0;i<5;i++) {
        philosopher[i].philosopherNumber=i;
        k=pthread_create(&philosopher[i].threadID,NULL,function,(void *)(philosopher+i));
        if(k!=0) {
            printf("\n Thread creation error \n");
            exit(1);
        }
    }
    for(i=0;i<5;i++) {
        k=pthread_join(philosopher[i].threadID,NULL);
        if(k!=0) {
            printf("\n Thread join failed \n");
            exit(1);
        }
    }
    for(i=0;i<5;i++) {
        k=pthread_mutex_destroy(&forks[i]);
        if(k!=0) {
            printf("\n Mutex Destroyed \n");
            exit(1);
        }
    }
    return 0;
}

void *function(void *philosopher) {
    
    struct threadData *currentData  = (struct threadData*)philosopher; 
    int n = currentData->philosopherNumber;
    for(;;) {
        printf("\nPhilosopher %d Started thinking ",n);
        fflush(stdout);
        usleep(100);
        pthread_mutex_lock(&forks[n]);
        pthread_mutex_lock(&forks[(n+1)%5]);
        printf("\nPhilosopher %d Finished thinking ",n);
        fflush(stdout);
        usleep(100);
        printf("\nPhilosopher %d Started eating ",n);
        fflush(stdout);
        usleep(100);
        pthread_mutex_unlock(&forks[n]);
        pthread_mutex_unlock(&forks[(n+1)%5]);
        printf("\nPhilosopher %d Finished eating",n);
        fflush(stdout);
        usleep(100);
        printf("\nPhilosopher %d Started thinking",n);
        fflush(stdout);
        usleep(100);
    }
}