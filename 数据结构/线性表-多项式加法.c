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
	    
	else return 0;                               // ���ں���ֻ��ͨ�����ݽ�ȥһ��ָ�룬�ı�ָ���ֵ�������һ������ı�ָ�룬�Ǳ��봫�ݽ�����ָ���ָ�� 
}



  
void Attach (int c, int e, Polynomial * pRear)    // pRear ��ָ��ָ���ָ�룬ͨ���ı������ʵ�ε�ָ�� &rear ��ֵ rear���ı�βָ��rear 
{
	Polynomial P = (Polynomial)malloc(struct PolyNode);   //��������һ����㣬Pָ��ý�㣬P�ֿ��Խ���P���ĵ�ַ 
	P -> coef = c;
	P -> expon = e;
	P -> link = NULL;
	(*pRear) -> link = P;   // ��ʱ����ָ����ָ��P����ʱrear �� front ��ָ��ý��
	*pRear = P;             // P��P���ĵ�ַ������ pRear��ֵ����ʱ��rearָ��P��㣬front����Ӱ�죬rear �� front �ֵ����� 
}                           // ������rearָ�����ʽβ��frontָ�����ʽͷ




Polynomial PolyAdd (Polynomial P1, Polynomial P2)
{
	int sum;
	Polynomial front, rear, temp;
	rear = (Polynomial)malloc( sizeof(struct PolyNode) );   //����ֻ������һ����ʱ��㣬��ʱ��rear �� front��ָ�����ʱ��� 
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
	    
	rear -> link = NULL;     //����3.19���У����Ҿ���û��Ҫ��rearָ�����һ����㣬�ý���ں���Attach���Ѿ�ָ����NULL 
	temp = front;
	front = front -> link;
	free (temp);
	return front;
}
