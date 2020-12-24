typedef int Postion;           //Ë³ÐòÕ»µÄÊµÏÖ 
typedef struct SNode
{
	ElementType * Data;
	Postion Top;
	int MaxSize;
 };
 
typedef SNode * Stack;



Stack CreatStack(int MaxSize)    //Ë³ÐòÕ»µÄ´´½¨ 
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
	S -> Data = (ElementType *)malloc(MaxSize * sizeof(ElementType) );
	S -> Top = -1;
	S -> MaxSize = MaxSize;
	return S;
}




bool IsFull(Stack S)             //ÅÐ¶ÏË³ÐòÕ»ÊÇ·ñÒÑ¾­ÂúÁË 
{
	return (S -> Top == S -> MaxSize - 1);
 } 
 
 


bool IsEmpty(Stack S)            //ÅÐ¶ÏË³ÐòÕ»ÊÇ·ñÎª¿Õ 
{
	return (S -> Top == -1);
 }
 
 
 

bool Push (Stack S, ElementType X)     //Ñ¹ÈëÕ» 
{
	if ( IsFull(S) )
	{
	    Printf("Õ»Âú£¡\n");
	    return false;
    }
	else
	{
	    S -> Data[++S -> Top] = X;
	    return true;
    }
 }
 
 
 
ElementType Pop (Stack S)                  //µ¯³öÕ» 
{
    if ( IsEmpty(S) )
    {
        printf("Õ»¿Õ£¡\n");
		return ERROR;
   }
	else
	    return S -> Data[(S -> Top)--];
} 
