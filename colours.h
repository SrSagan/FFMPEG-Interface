
void SetColour(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void MenuOp(int Num, char descripcion[200], char valor[100])
{
	
	
	if(valor[0] == '|')
	{
	SetColour(12);
	printf("(%d)", Num);
	SetColour(7);
	printf(" %s", descripcion);
	SetColour(12);
	printf(" %s\n", valor);
	SetColour(7);
	}
	else{
	SetColour(3);
	printf("(%d)", Num);
	SetColour(7);
	printf(" %s", descripcion);
	SetColour(10);
	printf(" %s\n", valor);
	SetColour(7);
	}
	
}
