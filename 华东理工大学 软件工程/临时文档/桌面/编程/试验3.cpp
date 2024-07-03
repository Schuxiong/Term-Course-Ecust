
void getTree(TreeNode* Node, vector<int>& data)
{
    if(Node==nullptr) return;
    getTree(Node->left, data);
    data.push_back(Node->val);
    getTree(Node->right, data);
}
 
 
TreeNode* increasingBST(TreeNode* root) {
    vector<int> data;
    getTree(root, data);    
    TreeNode* ans= new TreeNode(-1);
    TreeNode* cur = ans;
    for(auto index:data ){
        cur->right = new TreeNode(index);
        cur = cur->right;
    }
    return ans->right;
}   















// 递归实现遍历二叉树
void getTree(TreeNode* Node, vector<int>& data){
    if(Node==nullptr) return;
    getTree(Node->left, data);
    data.push_back(Node->val);
    getTree(Node->right, data);
}
 
// 循环实现遍历二叉树
void getTreeBy(TreeNode* Node, vector<int>& data ){
    stack<TreeNode*> res;
    res.push(Node);
    while(!res.empty()){
        TreeNode* tem=res.top();
        res.pop();
        if(tem){
            if(tem->right) res.push(tem->right);
            res.push(tem);
            res.push(nullptr);
            if(tem->left) res.push(tem->left);
        }
        else{
            data.push_back(res.top()->val);
            res.pop();
        }
 
    }
}
 
TreeNode* increasingBST(TreeNode* root) {
    vector<int> data;
    //getTree(root, data);    // 递归实现遍历二叉树
    getTreeBy(root, data);  // 循环实现中序遍历二叉树
 
    TreeNode* ans=new TreeNode(-1);
    TreeNode* cur = ans;
    for(auto index:data ){
        cur->right = new TreeNode(index);
        cur = cur->right;
    }
    return ans->right;
}   
