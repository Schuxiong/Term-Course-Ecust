#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 64

int main() {
    int pipe_fd[2]; // 管道文件描述符数组
    pid_t child_pid;
    char message[BUFFER_SIZE];
    
    // 创建管道
    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed");
        exit(1);
    }
    
    // 创建子进程
    child_pid = fork();
    
    if (child_pid == -1) {
        perror("Fork failed");
        exit(1);
    }
    
    if (child_pid == 0) {
        // 子进程
        close(pipe_fd[1]); // 关闭管道写入端
        
        // 从管道读取父进程发送的消息
        ssize_t bytes_read = read(pipe_fd[0], message, BUFFER_SIZE);
        if (bytes_read > 0) {
            printf("Child (PID %d) received message from parent: %s\n", getpid(), message);
        }
        
        close(pipe_fd[0]); // 关闭管道读取端
    } else {
        // 父进程
        close(pipe_fd[0]); // 关闭管道读取端
        
        // 向管道写入消息
        char parent_message[] = "Hello from parent!";
        write(pipe_fd[1], parent_message, strlen(parent_message) + 1);
        
        close(pipe_fd[1]); // 关闭管道写入端
    }
    
    return 0;
}