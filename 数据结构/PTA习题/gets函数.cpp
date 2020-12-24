void getstring(char a[])
{
	int i = 0;
	bool isenter = false;
	while (i < 300 && isenter == false)
	{
		scanf("%c", &a[i]);
		if (a[i] == '\n')
		{
			a[i] = '\0';
			isenter = true;
		}
		i++;
	}
}