#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t shared_memory_key = ftok("/tmp", 'A');
    int shared_memory_id;
    char *shared_memory_data;

    // 连接到共享内存
    shared_memory_id = shmget(shared_memory_key, 1024, 0666 | IPC_CREAT);
    shared_memory_data = (char *)shmat(shared_memory_id, (void *)0, 0);

    // 输入要发送的数据
    printf("Enter data to send: ");
    fgets(shared_memory_data, 1024, stdin);

    // 分离共享内存
    shmdt(shared_memory_data);

    return 0;
}