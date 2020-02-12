Userspace Thread Scheduler

Daniel Shchur
2019

Special Instructions:

The makefile comes with a few special targets that makes it easier to compile different versions of the program:

 - `make` or `make compileSem`: Will compile with mySem

 - `make compileNoSem`: Will compile with no semaphore.

 - `make clean`: Cleans program and object files


I spent about 5 hours on the scheduler and about 6 hours on the semaphore, which included debugging and reading about contexts and quirks.

Difficulty of scheduler: 2 -- Wasn't bad after reading up about contexts and context switching

Difficulty of semaphore: 3 -- A lot of code was given, was just running into bugs
