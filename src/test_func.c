

#include "../include/minishell.h"
#include <sys/wait.h>


// int	main(int argc, char *argv[], char *envp[])
// {
// 	char			*str;

//     (void)envp;
// 	if (!argc && !argv)
// 		return (0);
// 	while (1)
// 	{
// 		str = readline("minishell$> ");
//         if(str == NULL)
//             return (1);
// 	}
// }

// int main() {
     
//     pid_t pid = 0;
     
//     int x;
// 	int status;
//     x = 0;
//     printf("하이 %d\n", pid);
// 	pid = fork();
    
// 	while (1)
// 	{
// 		if(pid > 0) {  // 부모 코드
// 			x = 1;
// 			printf("나는 부모 PID : %ld,  x : %d\n",(long)getpid(), x);
// 			int childPid;
// 			scanf("%d", &childPid);
// 			// int i = wait(&status);
// 			int i = waitpid(childPid,&status,WNOHANG);
// 			printf("자식의 pid = %d\n", i);
// 			printf("status = %d\n", status);
// 			printf("WIFEXITED = %d\n", WIFEXITED(status));
// 		}
// 		else if(pid == 0){  // 자식 코드
// 			x = 2;
// 			printf("나는 자식 PID : %ld,  x : %d\n",(long)getpid(), x);
// 			sleep(5);
// 			exit(0);
// 		}
// 		else {  // fork 실패
// 			printf("fork Fail! \n");
// 			return -1;
// 		}
// 		sleep(3);
// 	}
     
//     return 0;
 
// }


// #include <string.h>
// #define MAX_BUF 1024
// #define READ 0
// #define WRITE 1
// int main(){
//         int fd[2];
//         pid_t pid;
//         char buf[MAX_BUF];

//         if(pipe(fd) < 0){
//                 printf("pipe error\n");
//                 exit(1);
//         }
//         if((pid=fork())<0){
//                 printf("fork error\n");
//                 exit(1);
//         }

//         printf("\n");
// 		while(1)
// 		{
// 			if(pid>0){ //parent process
// 					close(fd[READ]);
// 					scanf("%s", buf);
// 					write(fd[WRITE],buf,strlen(buf));
// 			}else{  //child process
// 					close(fd[WRITE]);
// 					read(fd[READ],buf,MAX_BUF);
// 					printf("child got message : %s\n",buf);
// 			}
// 		}
//         exit(0);
// }


// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
#include <string.h>
#define MAX_BUF 1024
#define READ 0
#define WRITE 1
int main(){
        int fdA[2],fdB[2];
        pid_t pid;
        char buf[MAX_BUF];
        int count=0;

        if(pipe(fdA) < 0){
                printf("pipe error\n");
                exit(1);
        }

        if(pipe(fdB) < 0){
                printf("pipe error\n");
                exit(1);
        }

        if((pid=fork())<0){
                printf("fork error\n");
                exit(1);
        }

        printf("\n");
        if(pid>0){ //parent process
                close(fdA[READ]);
                close(fdB[WRITE]);
                while(1){
                        sprintf(buf,"parent %d",count++);
                        write(fdA[WRITE],buf,MAX_BUF);
                        memset(buf,0,sizeof(buf));
                        read(fdB[READ],buf,MAX_BUF);
                        printf("parent got message : %s\n",buf);
                        sleep(1);
                }
        }else{  //child process
                close(fdA[WRITE]);
                close(fdB[READ]);
                count=100000;
                while(1){
                        sprintf(buf,"child %d",count++);
                        write(fdB[WRITE],buf,MAX_BUF);
                        memset(buf,0,sizeof(buf));
                        read(fdA[READ],buf,MAX_BUF);
                        printf("\tchild got message : %s\n",buf);
                        sleep(1);
                }
        }
        exit(0);
}
