#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
        char cmd[10];
        pid_t pid;
        printf("Enter command : \n");
        scanf("%s",cmd);
        pid=fork();
        if(pid==0){
                execlp("date","date",NULL);
                printf("exec() system call failed");
                exit(1);
                }else{
                        wait(NULL);
                        printf("parent pid:%d",getppid());
                        printf("child pid:%d",getpid());
                }
        return 0;
}





