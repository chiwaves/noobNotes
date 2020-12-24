Linklist Discreat_11 (Linklist &A)
{
	Linklist B = (Linklist)malloc(sizeof(LNode));
	B->next = NULL;
	LNode *pa = A;
	LNode *p = A->next;
	LNode *q;
	while (p != NULL)
	{
		pa->next = p;
		pa = p;
		q = p->next;
		p = q->next;
		q->next = B->next;
		B->next = q;
	}
	pa->next = NULL;
	return B;
}



bool DelSame_12(Linklist &L)
{
	LNode *p = L->next;
	LNode *q;
	if (p == NULL)
		return false;
	while (p->next != NULL)
	{
		q = p->next;
		if (p->data == q->data)
		{
			p->next = q->next;
			free(q);
		}
		else
			p = p->next;
	}
	return true;
}



void MergeList_13(Linklist &LA, Linklist &LB)
{
	LNode *pa = LA->next;
	LNode *pb = LB->next;
	LNode *q;
	pc->next = NULL;
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			q = pa;
			pa = pa->next;
			q->next = LA->next;
			LA->next = q;
		}
		else
		{
			q = pb;
			pb = pb->next;
			q->next = LA->next;
			LA->next = q;
		}
	}
	if (pa)
		pb = pa;
	while (pb)
	{
		q = pa;			
		pa = pa->next;
		q->next = LA->next;
		LA->next = q;
	}
	free(LB);
}



void Get_Common_14(Linklist A, Linklist B)
{
	Linklist C = (Linklist)malloc(sizeof(LNode));
	LNode *pa = A->next;
	LNode *pb = B->next;
	LNode *pc = C;
	LNode *q;
	while (pa && pb)
	{
		if (pa->data < pb->data)
			pa = pa->next;
		else if (pb->data < pa->data)
			pb = pb->next;
		else
		{
			q = (LNode*)malloc(sizeof(LNode));
			q->data = pa->data;
			pc->next = q;
			pc = pc->next;
			pa = pa->next;
			pb = pb->next;
		}
	}
	pc->next = NULL;
}



Linklist Union_15(Linklist &LA, Linklist &LB)
{
	LNode *pa = LA->next;
	LNode *pb = LB->next;
	LNode *pn = LA;
	LNode *q;
	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			q = pa;
			pa = pa->next;
			free(q);
		}
		else if (pa->data > pb->data)
		{
			q = pb;
			pb = pb->next;
			free(q);
		}
		else
		{
			pn->next = pa;
			pn = pa;
			pa = pa->next;
			q = pb;
			pb = pb->next;
			free(q);
		}
	}
	if (pa)
		pb = pa;
	while (pb)
	{
		q = pb;
		pb = pb->next;
		free(q);
	}
	pn->next = NULL;
	free(LB);
	return LA;
}



bool Pattern_16(Linklist A, Linklist B)
{
	LNode *pa = A->next;
	LNode *pb = B->next;
	LNode *q = pa;
	while (pa && pb)
	{
		if (pa->data == pb->data)
		{
			pa = pa->next;
			pb = pb->next;
		}
		else
		{
			q = q->next;
			pa = q;
			pb = B->next;
		}
	}
	if (pb)
		return false;
	else
		return true;
}



bool Symmetry_17(DLinklist L)
{
	DNode *p = L->next;
	DNode *q = L->prior;
	while (p != q && q->next != p)
	{
		if (p->data != q->data)
			return false;
		p = p->next;
		q = q->prior;
	}
	return true;
}



void Link_18(Linklist &h1, Linklist &h2)
{
	LNode *p1 = h1;
	LNode *p2 = h2;
	while (p1->next != h1)
		p1 = p1->next;
	while (p2->next != h2)
		p2 = p2->next;
	p1->next = h2->next;
	p2->next = h1;
	free (h2);
}



void DelAll_19(Linklist &L)
{
	LNode *pre;
	LNode *p;
	LNode *minpre;
	LNode *min;
	while (L->next != L)
	{
		pre = L;
		p = L->next;
		while (p != L)
		{
			if (p->data < min->data)
			{
				minpre = pre;
				min = p;
			}
			pre = p;
			p = p->next;
		}
		printf("%d\n",min->data);
		minpre->next = min->next;
		free (min);
	}
	free (L);
}



DLinklist Locate_20(DLinklist &L, ElementType x)
{
	DNode *p = L->next;
	DNode *q;
	while (p && p->data != x)
		p = p->next;
	if (p->data == x)
	{
		p->freq++;
		p->pred->next = p->next;
		p->next->pred = p->pred;
		q = p->pred;
		while (q != L && q->freq <= p->freq)
			q = q->pred;
		p->next = q->next;
		p->next->pred = p;
		q->next = p;
		p->pred = q;
		return p;
	}
	else
	{
		printf("not exist\n");
		return NULL;
	}
}