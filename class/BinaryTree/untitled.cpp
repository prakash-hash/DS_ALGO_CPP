#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* construct(int *preorder, int preStart, int preEnd, int *inorder, int inStart,int inEnd){
	if(preStart > preEnd || inStart > inEnd){
		return NULL;
	}

	int val = preorder[preStart];
	BinaryTreeNode<int> *p = new BinaryTreeNode<int>(val);

	int k = 0;
	for(int i = inStart; i <= inEnd; i++){
		if(val == inorder[i]){
			k = i;
			break;
		}
	}

	p -> left = construct(preorder,preStart+1,preStart + k - inStart, inorder,inStart,k-1);
	p -> right = construct(preorder,preStart + k - inStart+1, preEnd, inorder,k + 1, inEnd);

	return p;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder,int inLength){
	int preStart = 0;
	int preEnd = preLength-1;
	int inStart = 0;
	int inEnd = inLength-1;

	return construct(preorder, preStart, preEnd, inorder, inStart, inEnd);
}