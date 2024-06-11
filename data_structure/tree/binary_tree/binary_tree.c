#include <stdio.h>
#include <stdlib.h>

typedef int BTData;
typedef void (*VisitFuncPtr)(BTData data);

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
} BtreeNode;

BtreeNode *makeBtreeNode()
{
	BtreeNode *node = (BtreeNode *)malloc(sizeof(BtreeNode));
	node->left = NULL;
	node->right = NULL;

	return node;
}

BTData getData(BtreeNode *node)
{
	return node->data;
}

BTData setData(BtreeNode *node, BTData data)
{
	node->data = data;
}

BtreeNode *getLeftSubTree(BtreeNode *bTree)
{
	return bTree->left;
}

BtreeNode *getRightSubTree(BtreeNode *bTree)
{
	return bTree->right;
}

void makeLeftSubTree(BtreeNode *main, BtreeNode *sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

void makeRightSubTree(BtreeNode *main, BtreeNode *sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}

void inOrderTraverse(BtreeNode *tree, VisitFuncPtr action)
{
	if (tree == NULL)
		return;

	inOrderTraverse(tree->left, action);
	action(tree->data);
	inOrderTraverse(tree->right, action);
}

void preOrderTraverse(BtreeNode *tree, VisitFuncPtr action)
{
	if (tree == NULL)
		return;

	action(tree->data);
	inOrderTraverse(tree->left, action);
	inOrderTraverse(tree->right, action);
}

void postOrderTraverse(BtreeNode *tree, VisitFuncPtr action)
{
	if (tree == NULL)
		return;

	inOrderTraverse(tree->left, action);
	inOrderTraverse(tree->right, action);
	action(tree->data);
}

void deleteTree(BtreeNode *tree)
{
	if (tree == NULL)
		return;

	deleteTree(tree->left);
	deleteTree(tree->right);

	free(tree);
}