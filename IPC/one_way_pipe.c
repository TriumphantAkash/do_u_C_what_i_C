//this program shows implementation of one way IPC between n processes
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
        pid_t pid;
        int myPipeFd[2];
        int ret;
        char buf[20];

        ret = pipe(myPipeFd);

        if(ret == -1){
                perror("pipe");
                exit(1);
        }

        pid = fork();

        if(pid == 0)    //child
        {
                printf("[PARENT PROCESS]\n");
                read(myPipeFd[0], buf, 15);
                printf("read message is: %s", buf);
        }else{
                //parent process

                printf("[CHILD PROCESS]\n\n");
                write(myPipeFd[1], "Heyy there", 12);//first integer in the array is set up and opened for reading, while the second integer for writing.
        }
        return 0;
}

