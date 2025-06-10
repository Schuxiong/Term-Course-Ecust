 
#include<iostream>
using namespace std;
 
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
 
struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree], T2[MaxTree];
 
Tree BuildTree(struct TreeNode T[]);
int Isomorphic(Tree R1, Tree R2);
//测试函数
Tree BuildTreeTest1(struct TreeNode T1[]);
Tree BuildTreeTest2(struct TreeNode T2[]);
 
int main()
{
 
    int boot1, boot2;
    string result;
 
    //测试用例
    //建二叉树
    //boot1 = BuildTreeTest1(T1);
    //boot2 = BuildTreeTest2(T2);
 
    boot1 = BuildTree(T1);
    boot2 = BuildTree(T2);
 
    if(Isomorphic(boot1, boot2))
        result = "True";
    else
        result = "False";
 
    cout << result <<endl;
 
    return 0;
}
 
Tree BuildTree(struct TreeNode T[])
{
    int N;
    int cl, cr;
    int Root = Null;
 
    cin >> N;
 
    if(N){
        int check[N];
        for(int i=0; i<N; i++)  check[i] = 0;
        for(int i=0; i<N; i++){
            cin >> T[i].Element;
            cin >> cl;
            cin >> cr;
 
            if(cl != -1 ){
                T[i].Left = cl;
                check[T[i].Left] = 1;
            }
            else
                T[i].Left = Null;
 
            if(cr != -1 ){
                T[i].Right = cr;
                check[T[i].Right] = 1;
            }
            else
                T[i].Right = Null;
        }
        //找出根结点
        int i;
        for(i=0; i<N; i++){
            if(!check[i]) break;
        }
        Root = i;
    }
    return Root;
}
 
int Isomorphic(Tree R1, Tree R2)
{
    //结点都为空, 同构
    if( (R1 == Null) && (R2 == Null))
        return 1;
    //结点只有其中一个为空，非同构
    if( ((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)) )
        return 0;
    //结点不同，非同构
    if( (T1[R1].Element) != T2[R2].Element)
        return 0;
    //都没有左孩子
    if( (T1[R1].Left == Null) && (T2[R2].Left == Null))
        return Isomorphic(T1[R1].Right, T2[R2].Right);
    //同有左孩子，且左孩子结点相同
    if( ((T1[R1].Left!=Null) && (T2[R2].Left!=Null)) && ((T1[T1[R1].Left].Element)==(T2[T2[R2].Left].Element)))
        return ( Isomorphic( T1[R1].Left, T2[R2].Left) && Isomorphic( T1[R1].Right, T2[R2].Right));
    //其他，比较左右孩子是否同构
    else
        return( Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
}
 
Tree BuildTreeTest1(struct TreeNode T1[])
{
    int N = 8;
    int check[N];
    char cl, cr;
    int Root;
 
    char input[N][3] = \
    {   {'A', '1', '2'},\
        {'B', '3', '4'},\
        {'C', '5', '-'},\
        {'D', '-', '-'},\
        {'E', '6', '-'},\
        {'G', '7', '-'},\
        {'F', '-', '-'},\
        {'H', '-', '-'},\
    };
 
    if(N){
        for(int i=0; i<N; i++)  check[i] = 0;
        for(int i=0; i<N; i++){
            T1[i].Element = input[i][0];
            cl = input[i][1];
            cr = input[i][2];
 
            if(cl != '-'){
                T1[i].Left = cl-'0';
                check[T1[i].Left] = 1;
            }
            else
                T1[i].Left = Null;
 
            if(cr != '-'){
                T1[i].Right = cr-'0';
                check[T1[i].Right] = 1;
            }
            else
                T1[i].Right = Null;
        }
        //找出根结点
        int i;
        for(i=0; i<N; i++){
            if(!check[i]) break;
        }
        Root = i;
    }
    return Root;
}
 
Tree BuildTreeTest2(struct TreeNode T2[])
{
    int N = 8;
    int check[N];
    char cl, cr;
    int Root;
 
    char input[N][3] = \
    {   {'G', '-', '4'},\
        {'B', '7', '6'},\
        {'F', '-', '-'},\
        {'A', '5', '1'},\
        {'H', '-', '-'},\
        {'C', '0', '-'},\
        {'D', '-', '-'},\
        {'E', '2', '-'},\
    };
 
    if(N){
        for(int i=0; i<N; i++)  check[i] = 0;
        for(int i=0; i<N; i++){
            T2[i].Element = input[i][0];
            cl = input[i][1];
            cr = input[i][2];
 
            if(cl != '-'){
                T2[i].Left = cl-'0';
                check[T2[i].Left] = 1;
            }
            else
                T2[i].Left = Null;
 
            if(cr != '-'){
                T2[i].Right = cr-'0';
                check[T2[i].Right] = 1;
            }
            else
                T2[i].Right = Null;
        }
        //找出根结点
        int i;
        for(i=0; i<N; i++){
            if(!check[i]) break;
        }
        Root = i;
    }
    return Root;
}
 
