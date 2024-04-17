#include <fcntl.h>
#include <fstream>
#include <cstring>
#include <iostream>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

const int NUM = 19;
const int MAXBUF = 64;

int main(void)
{
    pid_t child_pid[NUM];

    std::cout << "System Monitor: pid #" << getpid() << std::endl;

    for(int i=0; i<NUM; i++)
    {
        child_pid[i] = fork();

        // child process
        if(child_pid == 0)
        {
            std::cout << "Child: pid #" << getpid() << std::endl;

            // set high prio
            int nice_value = -19;
            int rc = setpriority(PRIO_PROCESS, 0, nice_value);
            nice_value = getpriority(PRIO_PROCESS, 0);    // validate the set
            std::cout << "Child: rc #" << rc << ", nice value #" << nice_value << std::endl;

            execlp( "sudo", "sudo", "./nLoop2", NULL );

            std::cerr << "execlp() error... \n";
            exit(EXIT_FAILURE);
        }
    }

    sleep(1);

    std::cout << "System Monitor: DONE\n";

    int status = -1;
    pid_t pid = 0;

    // wait for child processes
    while(pid > 0)
    {
        // wait() is blocking, waitpid() is non blocking
        // waits for specifics to terminate
        pid = wait( &status );

        std::cout << "System Monitor: the child pid #" << pid << " finished...\n";
    }

    std::cout << "System Monitor: all done!\n";
    return EXIT_SUCCESS;
}