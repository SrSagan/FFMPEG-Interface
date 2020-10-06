
/*colores
1 = azul oscuro
2 = verde oscuro
3 = cyan oscuro
4 = rojo oscuro
5 = violeta oscuro
6 = dorado oscuro
7 = blanco oscuro (standart)
8 = gris
9 = azul
10 = verde
11 = cyan
12 = rojo
13 = violeta
14 = dorado
15 = blanco*/
void SetColour(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void MenuOpMain(int Num, char descripcion[200], char valor[100])
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
	
	void MenuOpAdv(int Num, char descripcion[200], char valor[100])
	{
		
		SetColour(3);
		printf("(%d)", Num);
		SetColour(7);
		printf(" %s", descripcion);
		SetColour(14);
		printf(" %s\n", valor);
		SetColour(7);
		
		
	}
	

