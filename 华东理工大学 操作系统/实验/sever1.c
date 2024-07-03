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

    // 创建共享内存段
    shared_memory_id = shmget(shared_memory_key, 1024, 0666 | IPC_CREAT);

    // 连接到共享内存
    shared_memory_data = (char *)shmat(shared_memory_id, (void *)0, 0);

    printf("Server process is waiting for data...\n");

    // 读取共享内存中的数据
    while (1) {
        if (shared_memory_data[0] != '\0') {
            printf("Received data: %s\n", shared_memory_data);
            shared_memory_data[0] = '\0'; // 清空共享内存
        }
    }

    // 分离共享内存
    shmdt(shared_memory_data);

    // 删除共享内存
    shmctl(shared_memory_id, IPC_RMID, NULL);

    return 0;
}