#include <stdio.h>
#include <stdlib.h>

typedef int BTData;
typedef int BSTData;
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

void changeLeftSubTree(BtreeNode *main, BtreeNode *sub)
{
	main->left = sub;
}

void changeRightSubTree(BtreeNode *main, BtreeNode *sub)
{
	main->right = sub;
}

BtreeNode *removeLeftSubTree(BtreeNode *tree)
{
	BtreeNode *delNode;

	if (tree != NULL)
	{
		delNode = tree->left;
		tree->left = NULL;
	}

	return delNode;
}

BtreeNode *removeRightSubTree(BtreeNode *tree)
{
	BtreeNode *delNode;

	if (tree != NULL)
	{
		delNode = tree->right;
		tree->right = NULL;
	}

	return delNode;
}

void bstMakeAndInit(BtreeNode **pRoot)
{
	*pRoot = NULL;
}

BSTData bstGetNodeData(BtreeNode *bst)
{
	return getData(bst);
}

void bstInsert(BtreeNode **pRoot, BSTData data)
{
	BtreeNode *pNode = NULL;
	BtreeNode *cNode = *pRoot;
	BtreeNode *nNode = NULL;

	while (cNode != NULL)
	{
		if (data == getData(cNode))
			return; // 키의 중복을 허용하지 않음

		pNode = cNode;
		if (getData(cNode) > data)
			cNode = getLeftSubTree(cNode);
		else
			cNode = getRightSubTree(cNode);
	}

	nNode = makeBtreeNode();
	setData(nNode, data);

	if (pNode == NULL)
	{
		*pRoot = nNode;
	}
	else
	{
		if (getData(pNode) > data)
			makeLeftSubTree(pNode, nNode);
		else
			makeRightSubTree(pNode, nNode);
	}
}

BtreeNode *bstSearch(BtreeNode *bst, BSTData target)
{
	BtreeNode *cNode = bst;
	BSTData cData;

	while (cNode != NULL)
	{
		cData = getData(cNode);
		if (cData == target)
			return cNode;
		else if (cData > target)
			cNode = getLeftSubTree(cNode);
		else
			cNode = getRightSubTree(cNode);
	}

	return NULL;
}

BtreeNode *bstRemove(BtreeNode **pRoot, BSTData target)
{
	BtreeNode *pVRoot = makeBtreeNode();
	BtreeNode *pNode = pVRoot;
	BtreeNode *cNode = *pRoot;
	BtreeNode *dNode;

	changeRightSubTree(pVRoot, *pRoot);

	while (cNode != NULL && getData(cNode) != target)
	{
		pNode = cNode;
		if (target < getData(cNode))
			cNode = getLeftSubTree(cNode);
		else
			cNode = getRightSubTree(cNode);
	}

	if (cNode == NULL)
		return NULL;

	dNode = cNode;

	// 첫 번째 경우: 삭제 대상이 리프 노드인 경우
	if (getLeftSubTree(dNode) == NULL && getRightSubTree(dNode) == NULL)
	{
		if (getLeftSubTree(pNode) == dNode)
			removeLeftSubTree(pNode);
		else
			removeRightSubTree(pNode);
	}
	// 두 번째 경우: 삭제 대상이 하나의 자식 노드를 갖는 경우
	else if (getLeftSubTree(dNode) == NULL || getRightSubTree(dNode) == NULL)
	{
		BtreeNode *dcNode; // 삭제 대상의 자식 노드 가리킴

		if (getLeftSubTree(dNode) != NULL)
			dcNode = getLeftSubTree(dNode);
		else
			dcNode = getRightSubTree(dNode);

		if (getLeftSubTree(pNode) == dNode)
			changeLeftSubTree(pNode, dcNode);
		else
			changeRightSubTree(pNode, dcNode);
	}
	// 세 번째 경우: 삭제 대상이 두 개의 자식 노드를 갖는 경우
	else
	{
		BtreeNode *mNode = getRightSubTree(dNode); // 대체 노드 가리킴(삭제할 노드를 대체)
		BtreeNode *mpNode = dNode;				   // 대체 노드의 부모 노드 가리킴
		int delData;

		// 삭제 대상의 대체 노드를 찾는다. 제일 작은 값을 찾아야하니 왼쪽 서브 트리를 탐색함.
		while (getLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = getLeftSubTree(mNode);
		}

		// 대체 노드에 저장된 값을 삭제할 노드에 대입한다.
		delData = getData(dNode);
		setData(dNode, getData(mNode));

		// 대체 노드의 부모 노드와 자식 노드를 연결한다.
		if (getLeftSubTree(mpNode) == mNode)
			changeLeftSubTree(mpNode, getRightSubTree(mNode));
		else
			changeRightSubTree(mpNode, getRightSubTree(mNode));

		dNode = mNode;
		setData(dNode, delData);
	}

	// 삭제된 노드가 루트 노드인 경우에 대한 추가적인 처리
	if (getRightSubTree(pVRoot) != *pRoot)
		*pRoot = getRightSubTree(pVRoot);

	free(pVRoot);
	return dNode;
}

void showIntData(int data)
{
	printf("%d ", data);
}

void bstShowAll(BtreeNode *bst)
{
	inOrderTraverse(bst, showIntData);
}

void main()
{
	BtreeNode *bstRoot;
	BtreeNode *sNode;

	bstMakeAndInit(&bstRoot);

	bstInsert(&bstRoot, 9);
	bstInsert(&bstRoot, 1);
	bstInsert(&bstRoot, 6);
	bstInsert(&bstRoot, 2);
	bstInsert(&bstRoot, 8);
	bstInsert(&bstRoot, 3);
	bstInsert(&bstRoot, 5);

	bstShowAll(bstRoot);
	printf("\n");

	sNode = bstRemove(&bstRoot, 3);
	free(sNode);

	bstShowAll(bstRoot);
	printf("\n");

	sNode = bstRemove(&bstRoot, 8);
	free(sNode);

	bstShowAll(bstRoot);
	printf("\n");
}