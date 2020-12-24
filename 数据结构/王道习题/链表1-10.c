void Del_X1_1(Linklist &L, ElementType x)  //直接对链表L进行操作，L为指向当前结点的指针
{
	LNode *p;
	if (L == NULL)
		return;
	if (L->data == x)
	{
		p = L;
		L = L->next;  //此时的L为上一个结点的指针，直接将上一个结点的指针指向当前操作的下一个
		free(p);
		Del_X1(L, x);
	}
	else
		Del_X1(L->next, x);
}



void Del_X2_2(Linklist &L, ElementType x) //有头结点时，用迭代比递归方便
{
	LNode *p = L->next;
	LNode *r = L;
	LNode *q;
	while (p != NULL)
	{
		if (p->data == x)
		{
			q = p;
			p = p->next;
			r->next = p;
			free(q);
		}
		else
		{
			r = p;
			p = p->next;
		}
	}
}



//逆序输出链表的每个结点，原来用递归实现如此简单
void R_Print_3(Linklist L)
{
	if (L->next != NULL)
		R_Print(L->next);
	else
		print(L->next);
}



Linklist DelMin_4(Linklist &L)
{
	LNode *p = L->next;
	LNode *pre = L;
	LNode *mp = pre;
	while (p != NULL)
	{
		if (p->data < mp->next->data)
			mp = pre;
		pre = p;
		p = p->next;
	}
	p = mp->next;
	mp->next = p->next;
	free(p);
	return L;
}



Linklist Reverse_5(Linklist L) //就地逆置链表
{
	LNode *pre;
	LNode *p = L->next;
	LNode *n = p->next;
	p->next = NULL;
	while (n != NULL) //先while判断，进入while循环后再将各参数向前挪一步。感受一下不同之处，特别是在结尾处
	{
		pre = p;
		p = n;
		n = n->next;
		p->next = pre;
	}
	L->next = p;
	return L;
}



void Sort_6(Linklist &L)
{
	LNode *p = L->next;
	LNode *r = p->next; //用r来记录p的后续结点，以保证不断链
	LNode *pre;
	p->next = NULL; 	/*先将表头和p结点从原来的链表中截断，之后就从原链表中拿元素，在截断那个带表头的链表中进行插排*/
	p = r;
	while (p != NULL)
	{
		r = r->next;
		pre = L;
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}



void Del_7(Linklist &L, int low, int high)
{
	LNode *pre = L;
	LNode *p = pre->next;
	while (p != NULL)
	{
		if (p->data >= low && p->data <= high)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}



Linklist SearchCommon_8(Linklist L1, Linklist L2)
{
	int len1 = Length(L1);
	int len2 = Length(L2);
	int dist;
	Linklist longlist, shortlist;
	if (len1 > len2)
	{
		longlist = L1->next;
		shortlist = L2->next;
		dist = len1-len2;
	}
	else
	{
		longlist = L2->next;
		shortlist = L1->next;
		dist = len2-len1;
	}
	while (dist--)
		longlist = longlist->next;
	while (longlist && longlist != shortlist)
	{
		longlist = longlist->next;
		shortlist = shortlist->next;
	}
	return longlist;
}



void PrintDel_9(Linklist &head)  //先将头结点拉出来，在头结点后进行插排
{
	LNode *pre;
	LNode *p = head->next;
	LNode *r = p->next;
	p->next = NULL;
	p = r;
	while (p != NULL)
	{
		r = r->next;
		pre = head;
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
	pre = head;
	while (pre->next != NULL)   //拿插排完的有序链表，打印一个元素，删除一个结点
	{
		p = pre->next;
		print(p->data);
		pre->next = p->next;
		free(p);
	}
}



Linklist Discreat_10(Linklist &A)
{
	int i = 0;
	B = (Linklist)malloc(sizeof(LNode));
	B->next = NULL;
	LNode *pa = A;
	LNode *pb = B;
	LNode *p = pa->next;
	A->next = NULL;
	while (p !=NULL)
	{
		i++;
		if (i%2 == 0)
		{
			pb->next = p;
			pb = p;
		}
		else
		{
			pa->next = p;
			pa = p;
		}
		p = p->next;
	}
	pa->next = NULL;
	pb->next = NULL;
	return B;
}