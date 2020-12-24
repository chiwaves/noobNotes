typedef struct ThreadNode	//二叉线索树的存储结构
{
	ElemType data;
	struct ThreadNode *lchild;
	struct ThreadNode *rchild;
	int ltag;	//左标志域ltag用0来表示lchild指向左孩子，用1表示lchild指向前驱
	int rtag;	//同理
}ThreadNode, *ThreadTree;



void InThread(ThreadTree &p, ThreadTree &pre)	//中序线索化递归算法
{
	if (p)
	{
		InThread(p->lchild, pre);	//递归线索化左子树
		if (!p->lchild)	//如果p的左子树为空，建立前驱线索
		{
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre && !pre->rchild)	//如果前驱结点不空，前驱结点右子树为空
		{
			pre->rchild = p;	//建立前驱结点的后继线索
			pre->rtag = 1;
		}
		pre = p;					//标记当前结点成为刚刚访问过的结点
		InThread(p->rchild, pre);	//递归，线索化右子树
	}
}

void CreateInThread(ThreadTree T) 	//中序遍历对二叉树进行线索化的主程序
{
	ThreadTree pre = NULL;
	if (T)					//如果T非空，线索化T
	{
		InThread(T, pre);
		pre->rchild = NULL;	//处理遍历的最后一个结点
		pre->rtag = 1;
	}
}



/*利用线序二叉树，可以实现二叉树遍历的非递归算法，以下是利用中序线索二叉树进行中序遍历*/
void InorderTraversal(ThreadNode *T)
{
	while (T->ltag == 0)	//先找到T的最左下结点(不一定是叶结点)，即是中序遍历第一个访问的结点
		T = T->lchild;
	while (T)
	{
		visit(T->data);
		if (T->rtag == 0)	//如果此时的T有右子树，在其右子树进行中序遍历
		{
			T = T->rchild;
			while (T->ltag == 0)	//找到子树p的最左下结点(不一定是叶结点)。即将p看作根结点时，中序遍历第一个访问的结点
				T = T->lchild;
		}
		else	//如果rtag==1，即rchild是后继线索，则直接跳到后继结点
			T = T->rchild;
	}
}