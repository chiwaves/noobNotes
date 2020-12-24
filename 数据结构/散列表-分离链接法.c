#define KEYLENGTH 15                   /* 关键词字符串的最大长度 */
typedef char ElementType[KEYLENGTH+1]; /* 关键词类型用字符串 */
typedef int Index;                     /* 散列地址类型 */

/******** 以下是单链表的定义 ********/
typedef struct LNode *PtrToLNode;
struct LNode
{
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode List;
typedef PtrToLNode Postition;
/******** 以上是单链表的定义 ********/

typedef struct TblNode *HashTable; /* 散列表类型 */
struct TblNode                     /* 散列表结点定义 */
{
	int TableSize;
	List Heads;                    /* 指向链表头结点的数组 */
};


HashTable CreateTable( int TableSize )
{
	HashTable H;
	int i;

	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	H->Heads = (List)malloc(H->TableSize*sizeof(LNode));

	for ( i = 0; i < H->TableSize; i++)
	{
		H->Heads[i].Data[O] = '\0';
		H->Heads[i].Next = NULL;
	}
	return H;
}


Postition Find( HashTable H, ElementType Key )
{
	Postition P;
	Index Pos;

	Pos = Hash( Key, H->TableSize );    /* 初始散列位置 */
	P = H->Heads[Pos].Next;             /* 从该链表的第1个结点开始 */

	while ( strcmp(P->Data, Key) && P ) /* 当未到表尾，并且Key未找到时 */ 
		P = P->Next;

	return P;                           /* 此时P或者指向找到的结点，或者为NULL */
}


bool Insert( HashTable H, ElementType Key )
{
	Postition P, NewCell;
	Index Pos;

	P = Find( H, Key );
	if ( !P )
	{
		NewCell = (Postition)malloc(sizeof(LNode));
		strcpy(NewCell.Data, Key);
		Pos = Hash ( Key, H->TableSize );
		NewCell->Next = H->Heads[Pos].Next;
		H->Heads[Pos].Next = NewCell;
		return true;
	}
	else
	{
		printf("键值已存在!\n");
		return false;
	}
}


void DestroyTable ( HashTable H )
{
	Postition P, Tmp;
	int i;

	for ( i = 0; i < H->TableSize; i++ )
	{
		P = H->Heads[i].Next;
		while ( P )
		{
			Tmp = P->Next;
			free( P );
			P = Tmp;
		}
	}
	free( H->Heads );
	free( H );
}