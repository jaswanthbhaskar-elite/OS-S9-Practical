#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
        int main(){
                pid_t pid;
                printf("Parent Process\n");
                printf("%d", getpid());
                printf("%d", getppid());
                pid=fork();
                if(pid<0){
                        printf("fork() invocation failed");
                        exit(1);
                }else if(pid==0){
                        printf("Child process\n");
                        printf("%d", getpid());
                        printf("%d", getppid());
                        execl("/bin/ls","ls","-l",NULL);
                        printf("exec() failed");
                        exit(1);
                }else{
                        printf("Parent process\n");
                        wait(NULL);
                        printf("Parent resumed\n");
                        printf("Child process Finished\n");
                        exit(1);
                }
                return 0;
}