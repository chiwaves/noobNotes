typedef int ElemType;  //链表数据的类型定义
typedef struct LNode  //链表结点的结构定义
{
	ElemType data;  //结点数据
	struct LNode *link;  //结点链接指针
}LNode, *Linklist;

int Search_k (Linklist list, int k)  //查找链表list倒数第k个结点，并输出该节点的数据
{
	LNode *p = list;
	LNode *q;
	while (p && k--)  //遍历链表直到最后一个结点
		p = p->link;
	if (p == NULL)  //如果链表中结点数小于k，退出循环后p指向空
		return 0;  //查找失败返回0
	else
	{
		q = list->link;  //p移动了k步后，q开始和p同步移动
		while (p)
		{
			p = p->link;
			q = q->link;
		}
		printf("%d\n", q->data);  //查找成功，打印结点数据并返回1
		return 1;
	}
}



typedef struct Node
{
	char data;
	struct Node *next;
}SNode;

int length (SNode *str)  //求链表长度的函数
{
	int count = 0;
	while (str->next)
	{
		count++;
		str = str->next;
	}
	return count;
}

SNode* Find_Common (SNode *str1, SNode *str2)
{
	int len1 = length(str1);
	int len2 = length(str2);
	int dist;
	SNode *longer, *shorter;
	if (len1 > len2)
	{
		dist = len1 - len2;
		longer = str1;
		shorter = str2;
	}
	else
	{
		dist = len2 - len1;
		longer = str2;
		shorter = str1;
	}
	while (dist--)
		longer = longer->next;
	while (longer->next && longer->next != shorter->next)  //将指针longer和shorter同步向后移
	{
		longer = longer->next;
		shorter = shorter->next;
	}
	return longer;  //返回共同后缀的起始地址
}




typedef struct Node
{
	int data;
	struct Node *link;
}Node, *PNODE;

void Del_Same (PNODE head, int n)
{
	PNODE p = head;  //p为工作结点指针
	PNODE r;  //之后用r来指向要删除的结点
	int *con = (int*)malloc(sizeof(int)*(n+1));  //申请n+1个位置的辅助数组
	int *sta, num, i;
	for (i = 0; i < n+1; i++)  //数组元素初值为0
		*(con+i) = 0;
	while (p->link)
	{
		num = p->link->data;  //num保存p下一个结点的数据data
		if (num > 0)
			sta = con+num;  //sta指向数组中|data|位置的数值
		else
			sta = con-num;
		if (*sta == 1)  //如果sta指向的数组元素为1时，表示该数据重复
		{
			r = p->link;  //删除结点操作
			p->link = r->link;
			free (r);
		}
		else  //如果sta指向的数组元素为0，表示首次出现
		{
			*sta = 1;
			p = p->link;
		}
	}
	free (con);  //释放辅助数组
}