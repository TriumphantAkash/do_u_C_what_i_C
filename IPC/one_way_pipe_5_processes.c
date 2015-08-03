//this program shows implementation of one way IPC between 5 processes
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
        pid_t pid1, pid2, pid3, pid4, pid5;
        int myPipe1Fd[2];
        int myPipe2Fd[2];
        int myPipe3Fd[2];
        int myPipe4Fd[2];
        int myPipe5Fd[2];
        int ret1, ret2, ret3, ret4;
        char buf[20], buf1[20];

        ret1 = pipe(myPipe1Fd);

        if(ret1 == -1){
        error("pipe");
                exit(1);
        }

        pid1 = fork();

        if(pid1 == 0)   //child
        {
                printf("[CHILD PROCESS]\n");
                read(myPipe1Fd[0], buf, 15);
                        write(myPipe2Fd[1], buf, 12);//first integer in the array is set up and opened for reading, while the second integer for writing.
                //printf("read message is: %s", buf);

                        pid2 = fork();
                        if(pid2 == 0)   //child
                        {
                                printf("[GRANDCHILD PROCESS]\n");
                                read(myPipe2Fd[0], buf, 15);
                                write(myPipe3Fd[1], buf, 12);//first integer in the array is set up and opened for reading, while the second integer for writing.

                                pid3 = fork();
                                if(pid3 == 0)   //child
                                {
                                        printf("[GRANDGRANDCHILD PROCESS]\n");
                                        read(myPipe3Fd[0], buf, 15);
                                        write(myPipe4Fd[1], buf, 12);//first integer in the array is set up and opened for reading, while the second integer for
                                        pid4 = fork();
                                        if(pid4 == 0)   //child
                                        {
                                                printf("[GRANDGRANDGRANDCHILD PROCESS]\n");
                                                read(myPipe4Fd[0], buf, 15);
                                                //finally write it back to parent
                                                 write(myPipe5Fd[1], buf,12);

                                        }

                                }


                        }

        }else{
                //parent process

                printf("[PARENT PROCESS]\n\n");
                write(myPipe1Fd[1], "Heyy there", 12);//first integer in the array is set up and opened for reading, while the second integer for writing.
                read(myPipe5Fd[0], buf1, 15);
                printf("the message is back to parent is: %s", buf1);
        }
        return 0;
}
