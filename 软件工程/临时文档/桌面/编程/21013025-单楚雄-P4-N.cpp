#include<bits/stdc++.h>
#include<cstring>
using namespace std;
struct Bstnode {
	int data;
	Bstnode* left;
	Bstnode* right;
};
//创建新节点
Bstnode* GetNewNode(int data) {
	Bstnode* newNode = new Bstnode();
	(*newNode).data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
//建树
Bstnode* CreateBiTree(char* a, char* b, int L) {
	if(L <= 0) return NULL;
	Bstnode* root = new Bstnode;
	root->data = *b;
	char* c;
	for(c = a; c != NULL; c++) if(*c == *b) break;
	int k = c - a;	
	root->left = CreateBiTree( a, b + 1, k);
	root->right = CreateBiTree(c + 1, b + 1 + k, L - k - 1);
	return root;
} 
//层次遍历
void LevelOrder(Bstnode* root) {
	if (root == NULL) return;
	queue<Bstnode*> Q;
	Q. push(root);
	while (!Q.empty()) {
		Bstnode* current = Q.front();
		cout << current->data << " ";
		if (current->left != NULL) Q.push(current->left);
		if (current->right != NULL) Q.push(current->right);
		Q.pop();
	}
}
//前序遍历
void Preorder(Bstnode* root) {
	if (root == NULL) return;
	cout << root->data ;
	Preorder(root->left);
	Preorder(root->right);
}
//中序遍历
void Inorder(Bstnode* root) {
	if (root == NULL) return;
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}
//后序遍历
void Postorder(Bstnode* root) {
	if (root == NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << " ";
}
bool flag = 0; Bstnode *ans;
bool LCA(Bstnode* root, char p, char q) {
	if(root == NULL) {
		return 0;
	}
//	cout << root->data << endl;
	bool lh = LCA(root->left, p, q);
	bool rh = LCA(root->right, p, q);
	if(lh && rh) {
		flag = 1;
		ans = root;  
	}
//	cout << root->data << " " << lh << " " << rh << endl;
	return lh || rh || (p == root->data || q == root->data);
}
int main() {
	char a[100], b[100];
	Bstnode* root = new Bstnode;
	scanf("%s", b);
	scanf("%s", a);
//	reverse(b, b+strlen(b));
	root = CreateBiTree(a, b, strlen(a));
	char p, q;
	cin >> p >> q;
//	cout << p << q << endl;
	LCA(root, p, q);
	if(flag) cout << ans->data << endl;
	else cout << "NULL" << endl;
}


