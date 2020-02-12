/* myThread.h */

#define _XOPEN_SOURCE 500

#include <unistd.h>
#include <ucontext.h>
#include <signal.h>
#include <stdlib.h>
#include <semaphore.h>
#include <time.h>
#include <sys/time.h>
#include "mysem.h"

#define DEAD 0
#define READY 1
#define RUNNING 2

void cleanup(void);
void task1(int);
void task2(int);
void signalHandler(int signal);

// Finds the next available thread and switches to it
void nextThread(int oldThread);

// Switches from old thread to current thread
void switchThread(int oldThread);
