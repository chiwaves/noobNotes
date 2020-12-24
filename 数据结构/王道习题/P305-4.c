void SelectSort( LinkNode L )
{
	LinkNode Initial, Pre, Now, PreMin, Min;
	Initial = L;
	L = NULL;

	while ( Initial )
	{
		Now = Min = Initial;
		Pre = PreMin = NULL;
		while ( Now )
		{			
			if ( Now->Data > Min->Data )
			{
				Min = Now;
				PreMin = Pre;
			}
			Pre = Now;
			Now = Now->Next;
		}
		if ( Min == Initial )
			Initial = Initial->Next;
		else
		{
			PreMin->Next = Min->Next;
			Min->Next = L;
			L = Min;
		}
	}
}