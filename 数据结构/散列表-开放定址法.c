#define MAX 100000        /* 允许开辟的最大散列表长度 */
typedef int ElementType;  /* 关键词类型用整型 */
typedef int Index;        /* 散列地址类型 */
typedef Index Position;   /* 数据所在位置与散列地址是同一类型 */
typedef enum { Legitimate, Empty, Deleted } EntryType;
/* 散列单元状态类型，分别对应：有合法元素、空单元、有已删除元素 */


typedef struct HashEntry Cell;  //散列表单元类型
struct HashEntry
{
	ElementType Data; //存放元素
	EntryType Info;   //单元状态
};


typedef struct TblNode HashTable; //散列表类型
struct TblNode       //散列表结点定义
{
	int TableSize;   //表的最大长度
	Cell *Cells;     //存放散列单元的数组
};


int NextPrime( int N ) //返回大于N且不超过MAX的最小素数
{
	int i, p = (N%2)?N+2:N+1; //从大于N的下一个奇数开始

	while ( p < MAX )
	{
		for ( i=(int)sqrt(p); i > 2; i-- )
			if ( !(p%i) )
				break;   //p不是素数
		if ( i = 2 )     //for正常结束，说明p是素数
			break;
		else
			p += 2;      //否则探测下一个奇数
	}
	return p;
}


HashTable CreateTable( int TableSize )
{
	HashTable H;
	int i;

	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	/* 保证散列表最大长度是素数 */
	H->Cells = (Cell *)malloc(H->TableSize*sizeof(Cell));
	/* 声明单元数组 */
	for ( i = 0; i < H->TableSize; i++ )
		H->Cells[i].Info = Empty;
	/* 初始化单元状态为"空单元" */
	return H;
}


Position Find( HashTable H, EntryType Key )  //平方探测法的查找
{
	Position CurrentPos, NewPos;
	int CNum = 0;

	NewPos = CurrentPos = Hash( Key, H->TableSize );

	/* 开始平方探测 */
	while ( H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != Key )
	{                                      /* 字符串类型的关键词需要strcmp函数 */
		if ( ++CNum%2 != 0 )  //奇数次冲突
		{
			NewPos = CurrentPos+(CNum+1)*(CNum+1)/4; //增量为负的(CNum+1)/2的平方
			if ( NewPos >= H->TableSize )
				NewPos = NewPos % H->TableSize  //调整为合法地址
		}
		else  //偶数次冲突
		{
			NewPos = CurrentPos - CNum*CNum/4;  //增量为负的CNum/2的平方
			while ( NewPos < 0 )
				NewPos += H->TableSize;         //调整为合法地址
		}
	}
	return NewPos;  //此时NewPos是Key的位置，或者是一个空单元的位置(找不到)
}


bool Insert( HashTable H, ElementType Key )
{
	Position Pos = Find( H, Key ); /* 先检查Key是否已经存在 */

	if ( H->Cells[Pos].Info == Empty )
	{
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		/*字符串类型的关键词需要strcpy函数! */
		return true;
	}
	else
	{
		printf("键值已存在!\n");
		return false;
	}
}