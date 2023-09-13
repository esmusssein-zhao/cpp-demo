#pragma once
#include <iostream>

struct BinaryTreeNode
{
	int m_nValue = -1;
	BinaryTreeNode* m_pLeft = nullptr;
	BinaryTreeNode* m_pRight = nullptr;
};

static size_t times = 0;
BinaryTreeNode* reEveyRoot(int* preorder_b, int* preorder_n, int* inorder_b, int* inorder_n)
{
	times++;
	std::cout << times << std::endl;
	BinaryTreeNode* root = new BinaryTreeNode;
	root->m_nValue = *preorder_b;
	if(preorder_b == preorder_n || inorder_b==inorder_n)
	{
		root->m_pLeft = root->m_pRight = nullptr;
		return root;
	}
	else
	{
		int* lRoot_b = inorder_b;
		int len = 0;
		while (*inorder_b != *preorder_b)
		{
			++inorder_b;
			++len;
		}
		if (lRoot_b == inorder_b)
		{
			root->m_pLeft = nullptr;
		}
		else
		{
			int* lRoot_e = --inorder_b;
			root->m_pLeft = reEveyRoot(++preorder_b, preorder_b + len, lRoot_b, lRoot_e);
		}
		if (inorder_b == inorder_n)
		{
			root->m_pRight = nullptr;
		}
		else
		{
			int* rRoot_b = inorder_b+2;
			root->m_pRight = reEveyRoot(preorder_b + len+1, preorder_n, rRoot_b, inorder_n);
		}
	}
}

BinaryTreeNode* reBuildTree(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length == 0)
	{
		return nullptr;
	}
	else
	{
		return reEveyRoot(preorder, preorder + length - 1, inorder, inorder + length - 1);
	}
}