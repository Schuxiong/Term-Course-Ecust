#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;
vector<int> tree_vector; 
typedef struct  TreeNode
{
	int data;
	TreeNode *left, *right;
}TreeNode;
TreeNode *root = NULL;

TreeNode *create_node(int data)
{
   TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
   new_node->data = data;
   new_node->left = NULL;
   new_node->right = NULL;
   return new_node;
}

TreeNode *build_tree(int index)
{
	if(index >= tree_vector.size())
	{
		return NULL;
	}
	else if(tree_vector[index] == -1)
	{
		return NULL;
	}
	else
	{
		TreeNode *new_node = create_node(tree_vector[index]);
		new_node->left=build_tree(2 * index +1);
		new_node->right=build_tree(2 * index +2);
		return new_node;
	}
}

//求任意两个节点的最近公共祖先
TreeNode *find(TreeNode *root, int data) 
{

	if (root == NULL) 
	{
		return NULL;
	}
	else if (root->data == data)
	{
		return root;
	 } 
	TreeNode *left = find(root->left, data);
	if (left!= NULL)
	{
		return left;
	}
	else
	{
		return find(root->right, data);
	}
}
TreeNode *lowerCommonAncestor(TreeNode *root, TreeNode *p,TreeNode *q)
{
	if(root == NULL || p == root || q == root)
	{
		return root;
	}
	TreeNode *left = lowerCommonAncestor(root->left, p, q);
	TreeNode *right = lowerCommonAncestor(root->right, p, q);
	if(left != NULL && right != NULL)
	{
		return root;
	}
	else if(left != NULL)
	{
		return left;
	}
	else
	{
		return right;
	}
}
int main(int argc, char **argv)
{
#ifdef CHECL_ARGS
    if(argc < 2)
    {
    	cout << "Usage: " << argv[0] << "<input_file>" << endl
    	return -1; 
	}
	assert(argc == 2);
	ifstream in(argv[i]);
#else
    ifstream in("p4.txt");
#endif
    assert(in.is_open()&&"Check your file path is correct");
    string line;
    bool build_tree_flag = true;
    int a = -1, b = -1;
    while(getline(in,line))
    {
    	istringstream iss(line);
    	int x;
    	while (iss >> x)
    	{
    		if(build_tree_flag)
    		{
    			tree_vector.push_back(x); 
			}
			else
			{
				if(a == -1)
				{
					a = x;
				}
			}
		}
		if(build_tree_flag)
		{
			build_tree_flag = false;
		}
	}
	root = build_tree(0);
	TreeNode *a_node = find(root,a);
	assert(a_node != NULL && a_node->data == a);
	TreeNode *b_node = find(root,b);
	assert(b_node != NULL && b_node->data == b);
	TreeNode *lca = lowerCommonAncestor(root, a_node, b_node);
	assert(lca != NULL);
	cout << lca->data << endl;
	return 0;
}
