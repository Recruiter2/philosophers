_This project has been created as part of the 42 curriculum by tzinaliy._

# Description
The goal of the Dining Philosophers problem, is to get familiar with threads mutexes and learn basics of threading a process. 


# Instructions

This program is written in C language and thus needs the **`gcc` or `clang`
 compiler** and standard libraries to run

- run 
```bash
make
```
- then 
```bash
./philo 5 800 200 200
```
```bash
./philo 4 410 200 200 
```
```bash
valgrind --fair-sched=yes --tool=helgrind ./philo 1 800 200 200 
```

The arguments are:

| Parameter | Meaning | Example |
|---|---|---:|
| `number_of_philosophers` | Number of philosophers and forks | `5` |
| `time_to_die` | Maximum time, in milliseconds, a philosopher can go without eating | `800` |
| `time_to_eat` | Time, in milliseconds, spent eating | `200` |
| `time_to_sleep` | Time, in milliseconds, spent sleeping | `200` |
| `number_of_times_each_philosopher_must_eat` | Optional limit: program stops after every philosopher eats this many times | `7` |

note : the 7th parameter is optional

# Resources

In general:

- man pages for `pthread_create`, `pthread_join`, `pthread_detach`, `pthread_mutex_init` (page 3) , `pthread_mutex_destroy`, `printf`, `pthread_mutex_lock`, `pthread_mutex_unlock`, `pthread_join` </br>
https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/ </br>
https://en.wikipedia.org/wiki/Race_condition </br>
https://medium.com/@sherniiazov.da/mutexes-in-c-ac2b0f1a6d34 </br>
https://stackoverflow.com/questions/34524/what-is-a-mutex </br>
https://linux.die.net/man/2/lock </br>
https://github.com/DeRuina/philosophers/blob/main/README.md </br>
https://www.youtube.com/watch?v=KF8dF1QS8Go </br>
https://github.com/mcombeau/philosophers </br>
https://www.csl.mtu.edu/cs4411.choi/www/Resource/Semaphore.pdf </br>
https://undo.io/resources/detecting-deadlocks-c-cplusplus/ </br>
https://database.guide/what-is-lock-granularity/ </br>

Asan (debug):

- https://www.osc.edu/resources/getting_started/howto/howto_use_address_sanitizer



## How was AI used? 
LLMs were ocasionally used as a tutor. For the following tasks: explain code and different concepts such as threads; explaining the project. I used llm to explain the parameters and make it easy to draw table of parameters in README, write some comments. I used llm to help fixing data race issue in my code. I didn't use it for anything else.


