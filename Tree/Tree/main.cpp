#include "tree.h"

int main(int argc, char** argv)
{
	int preorder[]{ 1,2,4,7,3,5,6,8 };
	int inorder[]{ 4,7,2,1,5,3,8,6 };
	BinaryTreeNode* root = reBuildTree(preorder,inorder, 8);
	return 0;
}