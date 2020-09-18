#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "codecs.h"
//#include "format.h"

int main()
{
	bool IncTrue = 0;
	bool FinTrue = 0;
	int menuOpcion = 0;
	int menuOpcionH = 0;
	int menuOpcionAv = 0;
	int menuOpcionSt = 0;
	int menuOpcionRec = 0;
	char InFile[200] = "|indefinido|";
	char OutFile[200] = "|indefinido|";
	char FileFormat[100] = "|indefinido|";
	char cmd[500];
	char agree[2];
	char temp[100];
	char map1[20] = "";
	char map2[20] = "";
	char map3[20] = "";
	char map4[20] = "";
	char map5[20] = "";
	char Vcodec[20] = "copy";
	char Acodec[20] = "copy";
	char Scodec[20] = "copy";
	char IncTime[100] = "00:00:00";
	char FinTime[100] = "";
	//menu principal
	
	menu:
	system("cls");
	printf("-------------------------------------MENU--------------------------------------\n");
	printf("(1) Seleccionar ubicacion del archivo de entrada\n");
	printf("(2) Seleccionar ubicacion del archivo de salida\n");
	printf("(3) Seleccionar formato de archivo: %s\n", FileFormat);
	printf("(4) Opciones avanzadas\n"); 
	printf("(5) Convertir\n");
	printf("(6) Ayuda\n");
	printf("-------------------------------------MENU--------------------------------------\n\n");
	
	printf("Archivo de entrada: %s\n", InFile);
	printf("Archivo de salida: %s.%s\n\n", OutFile, FileFormat);

	scanf("%d", &menuOpcion);
	system("cls");
	
	//opciones del menu principal
	switch(menuOpcion)
	{
		//seleccion de archivo de entrada
		case 1: 
		printf("Escriba la ubicacion de su archivo incluyendo el nombre del archivo y su formato\n");
		printf("Ej: c:\\carpeta\\video.mp4\n");
		scanf("%s", InFile);
		goto menu;
		break;
		
		//seleccion de archivo de salida
		case 2:
		printf("Escriba la ubicacion donde desea guardar su archivo convertido incluyendo el nombre de su archivo\n");
		printf("Ej: c:\\carpeta\\videoConvertido\n");
		scanf("%s", OutFile);
		goto menu;
		break;
		
		//seleccion formato de archivo de salida
		case 3:
		printf("Seleccione a que formato desea convertir su archivo de entrada\n");
		printf("Ej: avi\nSi desea ver una lista de los archivos soportados vaya a ayuda\n");
		scanf("%s", FileFormat);
		goto menu;
		break;

		//---------------------------------------------------------------------------------------------------
		//Opciones avanazadas
		
		//seleccion de codecs, sub, etc
		case 4:
		menuAv:
		system("cls");
		printf("----------------------------Opciones Avanzadas---------------------------------\n");
		printf("(1) Recortar video/audio\n");
		printf("(2) Seleccionar streams a convertir\n");
		printf("(3) Anadir stream de video por archivo externo (proximamente)\n");
		printf("(4) Seleccionar codec de video (proximamente) %s\n", Vcodec);
		printf("(5) Seleccionar codec de audio (proximamente)\n");
		printf("(6) Seleccionar codec de subtitulo (proximamente)\n");
		printf("(7) Volver al menu principal\n");
		printf("----------------------------Opciones Avanzadas---------------------------------\n");
		scanf("%d", &menuOpcionAv);
		
		//opciones avanzadas
		switch(menuOpcionAv)
		{
		
			//recortar video/audio
			// -ss start 00:00:00 -t end 00:00:01 -async 1 (obligatorio)
			case 1:
			menuRec:
			system("cls");
			printf("---------------------------------Recortar--------------------------------------\n");
			printf("(1) Seleccionar donde desea que comience su archivo: %s\n", IncTime);
			printf("(2) Seleccionar donde desea que termine su archivo: %s\n", FinTime);
			printf("(3) Volver a las opciones avanzadas\n");
			printf("---------------------------------Recortar--------------------------------------\n");
			
			scanf("%d", &menuOpcionRec);
			system("cls");
			switch(menuOpcionRec)
			{
				//Comienzo de archivo
				case 1:
				printf("Escriba el tiempo donde quiere que comienze su archivo\n");
				printf("(Ej: 00:01:15) El archivo comenzara en los 15 Seg. 1 Min.\nEscriba c para cancelar\n");
				scanf("%s", IncTime);
				if(IncTime[1] == 'c' || 'C')IncTime[0] = '0';
				else IncTrue = true;
				goto menuRec;
				break;
				
				//Fin de archivo
				case 2:
				printf("Escriba el tiempo donde terminara su archivo\n");
				printf("(Ej: 00:02:30) El archivo terminara a los 2 Min. 30 Seg.\nEscriba c para cancelar\n");
				scanf("%s", FinTime);
				if(FinTime[1] == 'c' || 'C')FinTime[0] = ' ';
				else FinTrue = true;
				goto menuRec;
				break;
				
				//Volver a opciones avanzadas
				case 3:
				goto menuAv;
				break;
				
			}
			break;
			
			//Seleccionar streams (map)
			case 2:
			streams:
			system("cls");
			printf("----------------------------------Streams--------------------------------------\n");
			printf("(1) Modificar stream: %s\n", map1);
			printf("(2) Modificar stream: %s\n", map2);
			printf("(3) Modificar stream: %s\n", map3);
			printf("(4) Modificar stream: %s\n", map4);
			printf("(5) Modificar stream: %s\n", map5);
			printf("(6) Volver a las opciones avanzadas\n");
			printf("----------------------------------Streams--------------------------------------\n");
			
			scanf("%d", &menuOpcionSt);
			
			//opcines stream
			switch(menuOpcionSt)
			{
				//Stream 1
				case 1:
				printf("Elija que stream de entrada usar y en que stream de salida se guardara\n");
				printf("(Ej: map 0:1) para stream 0 de entrada y stream 1 de salida\nEscriba c para cancelar\n");
				scanf("%c", &temp);
				scanf("%[^\n]", map1);
				if(map1[1] == 'c' || 'C')map1[0] = ' ';
				goto streams;
				break;
				
				//Stream 2
				case 2:
				printf("Elija que stream de entrada usar y en que stream de salida se guardara\n");
				printf("(Ej: map 0:1) para stream 0 de entrada y stream 1 de salida\nEscriba c para cancelar\n");
				scanf("%c", &temp);
				scanf("%[^\n]", map2);
				if(map2[1] == 'c' || 'C')map2[0] = ' ';
				goto streams;
				break;
				
				//Stream 3
				case 3:
				printf("Elija que stream de entrada usar y en que stream de salida se guardara\n");
				printf("(Ej: map 0:1) para stream 0 de entrada y stream 1 de salida\nEscriba c para cancelar\n");
				scanf("%c", &temp);
				scanf("%[^\n]", map3);
				if(map3[1] == 'c' || 'C')map3[0] = ' ';
				goto streams;
				break;
				
				//Stream 4
				case 4:
				printf("Elija que stream de entrada usar y en que stream de salida se guardara\n");
				printf("(Ej: map 0:1) para stream 0 de entrada y stream 1 de salida\nEscriba c para cancelar\n");
				scanf("%c", &temp);
				scanf("%[^\n]", map4);
				if(map4[1] == 'c' || 'C')map4[0] = ' ';
				goto streams;
				break;
				
				//Stream 5
				case 5:
				printf("Elija que stream de entrada usar y en que stream de salida se guardara\n");
				printf("(Ej: map 0:1) para stream 0 de entrada y stream 1 de salida\nEscriba c para cancelar\n");
				scanf("%c", &temp);
				scanf("%[^\n]", map5);
				if(map5[1] == 'c' || 'C')map5[0] = ' ';
				goto streams;
				break;
				
				//Volver a menu avanzado
				case 6:
				goto menuAv;
				break;
				
			}
			break;
			
			//Añadir stream o sub externo
			case 3:
			//Codigo incompleto
			goto menuAv;
			break;
			
			//Seleccionar codec de video
			case 4:
			printf("Escriba el codec de video que desea usar\n");
			printf("Ej: h264\nEscriba C para cancelar\n");
			scanf("%s", temp);
			if(temp[0] == 'c' || 'C')goto menuAv;
			else temp[20] = Vcodec[20];
			goto menuAv;
			break;
			
			//Seleccionar codec de audio
			case 5:
			goto menuAv;
			break;
			
			//Seleccionar codec de sub
			case 6:
			//codigo incompleto
			goto menuAv;
			break;
			
			//Volver al menu principal
			case 7:
			goto menu;
			break;
			
		}
		break;
		
		//Escribir comandos
		case 5:
		//comando si se corta el tiempo de inicio
		if(IncTrue == true)sprintf(cmd,"ffmpeg -i %s -ss %s %s %s %s %s %s -async 1 %s.%s", InFile, IncTime, map1, map2, map3, map4, map5, OutFile, FileFormat);
		//comando si se corta el tiempo de fin
		if(FinTrue == true)sprintf(cmd,"ffmpeg -i %s -to %s %s %s %s %s %s -async 1 %s.%s", InFile, FinTime, map1, map2, map3, map4, map5, OutFile, FileFormat);
		//comando si se corta el tiempo de inicio y de fin
		if((IncTrue == true) && (FinTrue == true))sprintf(cmd,"ffmpeg -i %s -ss %s -to %s %s %s %s %s %s -async 1 %s.%s", InFile, IncTime, FinTime, map1, map2, map3, map4, map5, OutFile, FileFormat);
		//comando si no se corta nada
		if((IncTrue == false)&&(FinTrue == false))sprintf(cmd,"ffmpeg -i %s %s %s %s %s %s %s.%s", InFile, map1, map2, map3, map4, map5, OutFile, FileFormat);
		
		printf("Se ejecutara el siguiente comando\n%s",cmd);
		printf("\nEsta usted de acuerdo (S/N)?");
		scanf("%s", agree);
		if((agree[0] == 'S') || (agree[0] == 's'))system(cmd);
		if(agree[0] == 'n' || 'N')goto menu;
		break;
		
		//menu de ayuda
		case 6:
		menuHelp:
		system("cls");
		printf("-------------------------------Menu de ayuda-----------------------------------\n");
		printf("(1) Lista de formatos\n");
		printf("(2) Lista de codecs\n");
		printf("(3) Volver al menu principal\n");
		printf("-------------------------------Menu de ayuda-----------------------------------\n\n");

		scanf("%d", &menuOpcionH);
		
		//opciones del menu de ayuda
		system("cls");
		switch(menuOpcionH)
		{
			//Lista de formatos de archivo
			case 1:
			printf("Los diferentes formatos estan listados en esta pagina\n\n");
			printf("https://ffmpeg.org/ffmpeg-all.html#Supported-File-Formats_002c-Codecs-or-Features");
			printf("\n\nEscriba cualquier caracter para salir\n");
			scanf("%s");
			goto menuHelp;
			break;
			
			//Lista de codecs
			case 2:
			printf("Los diferentes codecs estan listados en esta pagina\n\n");
			printf("https://ffmpeg.org/ffmpeg-all.html#Video-Codecs\n");
			printf("\n\nEscriba cualquier caracter para salir\n");
			scanf("%s");
			goto menuHelp;
			break;
			
			//Volver al menu principal
			case 3:
			goto menu;
			break;
		}
		break;
		
		default : 
		goto menu;
		break;
		
		
	}
	return 0;

}