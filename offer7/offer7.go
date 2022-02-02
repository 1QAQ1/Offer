package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(inorder) == 0 {
		return nil
	}
	root := &TreeNode{preorder[0], nil, nil}
	//find the position of root in inorder
	i := 0
	for ; i < len(inorder); i++ {
		if inorder[i] == preorder[0] {
			break
		}
	}

	root.Left = buildTree(preorder[1:i+1], inorder[0:i])
	root.Right = buildTree(preorder[i+1:len(preorder)], inorder[i+1:len(inorder)])
	return root
}

func main() {

}
