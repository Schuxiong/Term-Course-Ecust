public class IsBST {
    public static boolean isBST(Node root){
        if(root == null){
            return true;
        }
        int res = Integer.MIN_VALUE;
        Stack<Node> stack = new Stack<>();
        while(root != null || !stack.isEmpty()){
            if(root != null){
                stack.push(root);
                root = root.left;
            }else{
                root = stack.pop();
                // 判断部分
                if(root.data < res){
                    return false;
                }else{
                    res = root.data;
                    root = root.right;
                }
            }
        }
        return true;
    }
public static void main(String[] args) {
    Node node1 = new Node(5);
    Node node2 = new Node(3);
    Node node3 = new Node(7);
    Node node4 = new Node(2);
    Node node5 = new Node(4);
    Node node6 = new Node(6);
    node1.left = node2;
    node1.right = node3;
    node2.left = node4;
    node2.right = node5;
    node3.left = node6;
    // 显示中序遍历结果
    Print.inOrderUnR(node1);
    System.out.println(isBST(node1));
    System.out.println(checkBST(node1));

}
