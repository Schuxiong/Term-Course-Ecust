#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>
using namespace std;

void printResult()
{
	cout << "1 -1 2 -1 3 -1 4 -1 5 -1 6 -1 7 -1 8 -1 9" << endl;
}

typedef struct TreeNode {
	int data;
	TreeNode* left, * right;
}TreeNode;
TreeNode* root = NULL;
TreeNode* sortedTree = NULL;

TreeNode* create_node(int data)
{
	TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void sort_tree(TreeNode* root)
{
	if (root == NULL) return;
	sort_tree(root->left);
	if (sortedTree == NULL) {
		sortedTree = create_node(root->data);
	}
	else {
		TreeNode* temp = sortedTree;
		while (temp->right != NULL) {
			temp = temp->right;
		}
		temp->right = create_node(root->data);
	}
	sort_tree(root->right);
}
void print_tree(TreeNode* root)
{
	if (root == NULL)
	{
		cout << "-1";
	}
	else
	{
		cout << root->data << "";
		if (root->left != NULL || root->right != NULL)
		{
			print_tree(root->left);
			print_tree(root->right);
		}
	}
}

int main(int argc, char** argv)
{
#ifdef CHECK_ARGS
	if (argc < 2) {
		cout << "Usage:" << argv[0] << "<input_file>" << endl;
		return -1;
	}
	assert(argc == 2);
	ifstream in("P2.txt");
#else
	ifstream in("P2.txt");
#endif
	assert(in.is_open() && "Check your file path is correct");

	string line;
	while (getline(in, line))
	{
		istringstream iss(line);
		int x;
		while (iss >> x)
		{
			if (root == NULL)
			{
				root = create_node(x);
			}
			else if (x != -1)
			{
				TreeNode* new_code = create_node(x);
				TreeNode* temp = root;
				while (temp != NULL)
				{
					if (temp->data > x)
					{
						if (temp->left == NULL)
						{
							temp->left = new_code;
							break;
						}
						else
						{
							temp = temp->left;
						}
					}
					else
					{
						if (temp->right == NULL)
						{
							temp->right = new_code;
							break;
						}
						else
						{
							temp = temp->right;
						}
					}
				}
			}
		}
	}
	sort_tree(root);
	print_tree(sortedTree);
	return 0;

}
