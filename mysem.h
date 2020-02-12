/* mysem.h */
#include<signal.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define THREADS 12

typedef struct mysem{
	// use for atomic locking of all sempahore functions to avoid race.
	volatile long long int lock; 
	// use to store the value of the semaphore.
	int val;
	// use to store the number of threads blocked on the semaphore.
	int blkThreads;
	// use to hold the thread id of blocked threads. Set to maximum 
	// number of threads to avoid overflow. You can replace with
	// a linklist implementation if you'd like. 
	int  Q[THREADS];
	// use to store the front of the queue;
	int front;
	// use to store the back of the queue;
	int back;
} mysem_t;

// use signal handler from myThread.c
extern void nextThread(int oldThread);

extern void switchThread(int oldThread);

// Feel free to bring in other functions that
// you may need or newly created that can help
// with implementing your own semaphore.


// swap the value from a memory location and a register
void atomic_swap(volatile long long int*);

// initialize semaphore to an initial value
int mysem_init(mysem_t*,int);

// perform a down operation and return the latest value of the
// semaphore
void mysem_wait(mysem_t*);

// perform an up operation and return the latest value of the
// semaphore
void mysem_post(mysem_t*);

// return the current value of the semaphore
int mysem_value(mysem_t*);

// Feel free to create more function to support your sempahore
// implementation.
