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

    // 获取消息队列
    message_queue_id = msgget(message_queue_key, 0666 | IPC_CREAT);

    // 设置消息类型
    message.message_type = 1;

    // 输入要发送的消息
    printf("Enter a message: ");
    fgets(message.message_text, 100, stdin);

    // 发送消息
    msgsnd(message_queue_id, &message, sizeof(message.message_text), 0);

    printf("Message sent: %s\n", message.message_text);

    return 0;
}