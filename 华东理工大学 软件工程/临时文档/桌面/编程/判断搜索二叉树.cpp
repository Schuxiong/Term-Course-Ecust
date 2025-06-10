public class IsBST 
{
	public static boolean isBST (Node root)
	{
		if (root == null){
			return ture;
		}
	int res = Integer.MIN_VALUE;
	Stack <Node> stack= new Stack <> ();
	while (root != null || !stack.isEmpty())
	{
		if( root != null){
			stack.push(root);
			root = root.left;
		}
		else {
			root = stack.pop();//еп╤о
			if (root.data < res){
				return false;
			} 
			else{
				res = root.data;
				root = root.right;
			}
		}
	}
	return true;
	}
 } 
