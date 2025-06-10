#include<stdio.h>
#define MAXSIZE 1000001
typedef struct {
    int val;
    int lchild;
    int rchild;
}Node;
Node data[MAXSIZE];
int Judge(Node data);
int Judge(Node p) {
    if (p.lchild == 0 && p.rchild == 0) return 1;

    if ((p.lchild != 0) && (p.val <= data[p.lchild].val) || (p.rchild != 0) && (p.val >= data[p.rchild].val))
        return 0;
    else {
        if (p.lchild != 0) return Judge(data[p.lchild]);
        if (p.rchild != 0) return Judge(data[p.rchild]);
    }
}
int main(void) {
    int n, root, i, j, val_i, left_i, right_i, flag;
    scanf("%d %d", &n, &root);
    for (i = 1; i <= n; i++) {
        scanf("%d %d %d", &val_i, &left_i, &right_i);
        data[i].val = val_i;
        data[i].lchild = left_i;
        data[i].rchild = right_i;
    }
    flag = Judge(data[root]);
    if (flag) {
        printf("True\n");
    }
    else {
        printf("False\n");
    }
    return 0;
}
