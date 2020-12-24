struct PolyNode{
	int coef;
	int expon;
	struct PolyNode * link;
};
typedef struct PolyNode * Polynomial;
Polynomial P1, P2;





int Compare (int e1, int e2)
{
	if (e1 > e2)
	    return 1;
	
	else if (e1 < e2)
	    returnn -1;
	    
	else return 0;                               // 由于函数只能通过传递进去一个指针，改变指针的值。如果进一步，想改变指针，那必须传递进函数指针的指针 
}



  
void Attach (int c, int e, Polynomial * pRear)    // pRear 是指向指针的指针，通过改变输入的实参的指针 &rear 的值 rear，改变尾指针rear 
{
	Polynomial P = (Polynomial)malloc(struct PolyNode);   //又申请了一个结点，P指向该结点，P又可以叫作P结点的地址 
	P -> coef = c;
	P -> expon = e;
	P -> link = NULL;
	(*pRear) -> link = P;   // 临时结点的指针域指向P，此时rear 和 front 都指向该结点
	*pRear = P;             // P（P结点的地址）赋给 pRear的值。此时，rear指向P结点，front不受影响，rear 和 front 分道扬镳 
}                           // 因此造成rear指向多项式尾，front指向多项式头




Polynomial PolyAdd (Polynomial P1, Polynomial P2)
{
	int sum;
	Polynomial front, rear, temp;
	rear = (Polynomial)malloc( sizeof(struct PolyNode) );   //这里只申请了一个临时结点，此时，rear 和 front都指向该临时结点 
	front = rear;
	while (P1 && P2)
	{
		switch ( Compare(P1 -> expon, P2 -> expon) )
		{
			case (0):
			sum = P1 -> coef + P2 -> coef;
			if (sum)  Attach (sum, P1 -> expon, &rear);
			P1 = P1 -> link;
			P2 = P2 -> link;
			break;
			
		case (1):
			Attach (P1 -> coef, P1 -> expon, &rear);
			P1 = P1 -> link;
			break;
			
		case (-1):
			Attach (P2 -> coef, P2 -> expon, &rear);
			P2 = P2 -> link;
			break;
		}
	}
	
	for (; P1; P1 = P1 -> link)
	    Attach (P1 -> coef, P1 -> expon, &rear);
	    
	for (; P2; P2 = P2 -> link)
	    Attach (P2 -> coef, P2 -> expon, &rear);
	    
	rear -> link = NULL;     //代码3.19中有，但我觉得没必要，rear指向最后一个结点，该结点在函数Attach中已经指向了NULL 
	temp = front;
	front = front -> link;
	free (temp);
	return front;
}
