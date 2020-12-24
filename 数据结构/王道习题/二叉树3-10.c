void PostOrder_3(BinTree BT)  //二叉树后序遍历非递归算法
{
	BinTree T = BT;
	BinTree R = NULL;
	Stack S = CreatStack(MaxSize);
	while (T||!IsEmpty(S))
	{
		if (T)
		{
			Push(S, T);
			T = T->left;
		}
		else
		{
			T = GetTop(S, T);  //这里用读取栈顶的操作取代了原先弹一次，读取再压入的操作
			if (T->right && T->right!=R)
			{
				T = T->right;
				Push(S, T);
				T = T->left;
			}
			else
			{
				T = Pop(S, T);
				visit(T->data);
				R = T;
				T = NULL;
			}
		}
	}
}



void InvertLevel_4(BinTree BT)  //二叉树自下而上，自右往左层序遍历
{
	Queue Q = CreatQueue();  //基于原有的层序遍历用队列来实现
	Stack S = CreatStack();  //外加一个栈来辅助，使最后输出顺序逆置
	BinNode *p;
	if (BT)
	{
		EnQueue(Q, BT);
		while (!IsEmpty(Q))  //如果队列不空，则进入循环
		{
			DeQueue(Q, p);
			Push(S, p);
			if (p->lchild)
				EnQueue(Q, p->lchild);
			if (p->rchild)
				EnQueue(Q, p->rchild);
		}
	}
	while (!IsEmpty(S))
	{
		Pop(S, p);
		visit(p->data);
	}
}



int BTdepth_5(BinTree BT)  //非递归算法求二叉树高度，思路：还是基于层序遍历
{
	int front = -1, rear = -1;
	int last = 0;  //last指向下一层第一个结点的位置
	int level = 0;  //level用来记录高度
	BinTree p;
	BinTree Q[MaxSize];  //设置队列Q，元素是二叉树结点指针且容量足够
	if (!BT)
		return 0;  //树空，高度为0
	Q[++rear] = BT; //根结点入队
	while (front < rear) //队不空，则进入下一轮循环
	{
		p = Q[++front];  //队列元素出队，即正在访问的结点
		if (p->lchild)
			Q[++rear] = p->lchild;
		if (p->rchild)
			Q[++rear] = p->rchild;
		if (front == last)
			level++;
		last = rear;  //last指向下层
	}
	return level;
}



BinTree PreInCreat_6(ElemType A[], ElemType B[], int la, int ra, int lb, int rb) //已知先序序列A和中序B来重建一棵树，经典的递归算法，建议重复
{
	int len1, len2;  //len1, len2分别记录根结点左右子树序列的长度。la,ra,lb,rb分别是先序和中序序列中，本次递归划分出来的左右子树开始结束位置
	int i = lb;
	root = (BinNode*)malloc(sizeof(BinNode));
	root->data = A[la];
	while (B[i] != root->data)
		i++;
	len1 = i - lb;
	len2 = rb - i;
	if (len1)
		root->left = PreInCreat(A, B, la+1, la+len1, lb, i-1);
	else
		root->left = NULL;
	if (len2)
		root->right = PreInCreat(A, B, la+len1+1, ra, i+1, rb);
	else
		root->right = NULL;
	return root;
}



bool IsComplete_7(BinTree BT)	//判断一棵二叉树是否是完全二叉树
{
	BinNode *p;
	Queue Q = CreatQueue();
	if (!BT)
		return true;
	EnQueue(Q, BT);
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);
		if (p)
		{
			EnQueue(Q, p->left);
			EnQueue(Q, p->right);
		}
		else	//一旦发现一个空结点，那他之后必须都是空结点，否则不是完全二叉树
		{
			while (!IsEmpty(Q))
			{
				DeQueue(Q, p);
				if (p->left || p->right)
					return false;
			}
			return true;
		}
	}
}



int DsonNodes_8st(BinTree BT)	//计算一个二叉树所有双分支结点的个数，标答
{
	if (!BT)	//如果BT空，已经越过了叶结点，返回0
		return 0;
	else if (BT->left && BT->right)
		return DsonNodes(BT->left) + DsonNodes(BT->right) + 1;	//如果有左右儿子，返回左右子树的计数和，再加1
	else
		return DsonNodes(BT->left) + DsonNodes(BT->right);		//如果只有一个儿子，就只返回左右子树的计数和
}

void DsonNodes_8(BinTree BT, int &count)	//自己瞎写。用参数传递辅助(表达可能有误)，这里int &用法不知是否正确
{
	if (BT)
	{
		if (BT->left && BT->right)
			count++;
		DsonNodes_8(BT->left, count);
		DsonNodes_8(BT->right, count);
	}
}
void Count(BinTree BT)
{
	int count = 0;
	DsonNodes_8(BT, count);
}



void Swap_9(BinTree BT)	//把二叉树中所有结点的左右子树进行交换
{
	BinNode *tmp;
	if (BT)
	{
		Swap(BT->left);
		Swap(BT->right);
		tmp = BT->left;
		BT->left = BT->right;	//操作对象还是BT->left，BT->right。所以不用因为担心形参的问题而写成 tmp = *(BT->left)
		BT->right = tmp;
	}
}



int count = 1;	//设置全局变量作为序号计数
ElemType Findk_10(BinTree BT, int k)	//查找二叉树先序遍历的第k个结点的数据
{
	if (!BT)
		return '#';
	if (count == k)
		return BT->data;
	count++;
	data = Findk_10(BT->left, k);
	if (data != '#')
		return data;
	data = Findk_10(BT->right, k);
	return data;
}