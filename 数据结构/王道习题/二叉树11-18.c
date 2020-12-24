void Delete_11(BinTree BT)
{
	if (BT)
	{
		DeleteX(BT->left);
		DeleteX(BT->right);
		free(BT);
	}
}

void SearchX_11(BinTree BT, ElemType x)
