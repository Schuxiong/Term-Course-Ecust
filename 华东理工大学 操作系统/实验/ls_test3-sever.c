#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message_buffer {
    long message_type;
    char message_text[100];
};

int main() {
    key_t message_queue_key;
    int message_queue_id;
    struct message_buffer message;

    // 生成消息队列的键值
    message_queue_key = ftok("/tmp", 'A');

    // 创建消息队列
    message_queue_id = msgget(message_queue_key, 0666 | IPC_CREAT);

    // 接收消息
    msgrcv(message_queue_id, &message, sizeof(message.message_text), 1, 0);

    // 显示接收到的消息
    printf("Received message: %s\n", message.message_text);

    // 删除消息队列
    msgctl(message_queue_id, IPC_RMID, NULL);

    return 0;
}