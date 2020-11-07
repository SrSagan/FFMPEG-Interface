#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <Windows.h>
//#include "codecs.h"
//#include "format.h"
#include "colours.h"



int main()
{
	bool IncTrue = 0;
	bool FinTrue = 0;
	bool SecTrue = false;
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
	char Vcodec[20] = "";
	char Acodec[20] = "";
	char Scodec[20] = "";
	char IncTime[100] = "00:00:00";
	char FinTime[100] = "";
	char SecFile[200] = "";
	
	//menu principal
	menu:
	system("cls");
	SetColour(9);
	printf("-------------------------------------MENU--------------------------------------\n");
	MenuOpMain(1, "Seleccionar ubicacion del archivo de entrada:", InFile);
	MenuOpMain(2, "Seleccionar ubicacion del archivo de salida:", OutFile);
	MenuOpMain(3, "Seleccionar formato de archivo:", FileFormat);
	MenuOpMain(4, "Opciones avanzadas", ""); 
	MenuOpMain(5, "Convertir", "");
	MenuOpMain(6, "Ayuda", "");
	SetColour(9);
	printf("-------------------------------------MENU--------------------------------------\n\n");
	SetColour(7);
	
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
		scanf("%c", &temp);
		scanf("%[^\n]", InFile);
		goto menu;
		break;
		
		//seleccion de archivo de salida
		case 2:
		printf("Escriba la ubicacion donde desea guardar su archivo convertido incluyendo el nombre de su archivo\n");
		printf("Ej: c:\\carpeta\\videoConvertido\n");
		scanf("%c", &temp);
		scanf("%[^\n]", OutFile);
		goto menu;
		break;
		
		//seleccion formato de archivo de salida
		case 3:
		printf("Seleccione a que formato desea convertir su archivo de entrada\n");
		printf("Ej: avi\nSi desea ver una lista de los archivos soportados vaya a ayuda\n");
		scanf("%c", &temp);
		scanf("%[^\n]", FileFormat);
		goto menu;
		break;

		//---------------------------------------------------------------------------------------------------
		//Opciones avanazadas
		
		//seleccion de codecs, sub, etc
		case 4:
		menuAv:
		system("cls");
		SetColour(5);
		printf("----------------------------Opciones Avanzadas---------------------------------\n");
		MenuOpAdv(1, "Recortar video/audio", "");
		MenuOpAdv(2, "Seleccionar streams a convertir", "");
		MenuOpAdv(3, "Anadir stream de video por archivo externo", "");
		MenuOpAdv(4, "Seleccionar codec de video:", Vcodec);
		MenuOpAdv(5, "Seleccionar codec de audio:", Acodec);
		MenuOpAdv(6, "Seleccionar codec de subtitulo:", Scodec);
		MenuOpAdv(7, "Volver al menu principal", "");
		SetColour(5);
		printf("----------------------------Opciones Avanzadas---------------------------------\n");
		SetColour(7);
		scanf("%d", &menuOpcionAv);
		system("cls");
		
		//opciones avanzadas
		switch(menuOpcionAv)
		{
		
			//recortar video/audio
			// -ss start 00:00:00 -t end 00:00:01 -async 1 (obligatorio)
			case 1:
			menuRec:
			system("cls");
			SetColour(5);
			printf("---------------------------------Recortar--------------------------------------\n");
			MenuOpAdv(1, "Seleccionar donde desea que comience su archivo:", IncTime);
			MenuOpAdv(2, "Seleccionar donde desea que termine su archivo:", FinTime);
			MenuOpAdv(3, "Volver a las opciones avanzadas", "");
			SetColour(5);
			printf("---------------------------------Recortar--------------------------------------\n");
			SetColour(7);
			
			scanf("%d", &menuOpcionRec);
			system("cls");
			switch(menuOpcionRec)
			{
				//Comienzo de archivo
				case 1:
				printf("Escriba el tiempo donde quiere que comienze su archivo\n");
				printf("(Ej: 00:01:15) El archivo comenzara en los 15 Seg. 1 Min.\nEscriba c para cancelar\n");
				scanf("%c", &temp);
				scanf("%[^\n]", IncTime);
				if((IncTime[0] == 'c') || (IncTime[0] == 'C')) strcpy(IncTime, " ");
				else IncTrue = true;
				goto menuRec;
				break;
				
				//Fin de archivo
				case 2:
				printf("Escriba el tiempo donde terminara su archivo\n");
				printf("(Ej: 00:02:30) El archivo terminara a los 2 Min. 30 Seg.\nEscriba c para cancelar\n");
				scanf("%c", &temp);
				scanf("%[^\n]", FinTime);
				if((FinTime[0] == 'c') || (FinTime[0] == 'C')) strcpy(FinTime, " ");
				else FinTrue = true;
				goto menuRec;
				break;
				
				//Volver a opciones avanzadas
				case 3:
				goto menuAv;
				break;
				
				default:
				goto menuRec;
				break;
				
			}
			break;
			
			//Seleccionar streams (map)
			case 2:
			streams:
			system("cls");
			SetColour(5);
			printf("----------------------------------Streams--------------------------------------\n");
			MenuOpAdv(1 ,"Modificar stream:", map1);
			MenuOpAdv(2 ,"Modificar stream:", map2);
			MenuOpAdv(3 ,"Modificar stream:", map3);
			MenuOpAdv(4 ,"Modificar stream:", map4);
			MenuOpAdv(5 ,"Modificar stream:", map5);
			MenuOpAdv(6 ,"Volver a las opciones avanzadas", "");
			SetColour(5);
			printf("----------------------------------Streams--------------------------------------\n");
			SetColour(7);
			
			scanf("%d", &menuOpcionSt);
			system("cls");
			
			//opcines stream
			switch(menuOpcionSt)
			{
				//Stream 1
				case 1:
				printf("Elija que stream de entrada usar y en que stream de salida se guardara\n");
				printf("(Ej: map 0:1) para 0 siendo el numero del archivo de entrada y stream 1 siendo el numero de stream en el archivo 0\nEscriba c para cancelar\n");
				scanf("%c", &temp);
				scanf("%[^\n]", map1);
				if(map1[0] == 'c')map1[0] = ' ';
				else{
				sprintf(temp,"-%s",map1);
				strcpy(map1, temp);
				}
				goto streams;
				break;
				
				//Stream 2
				case 2:
				printf("Elija que stream de entrada usar y en que stream de salida se guardara\n");
				printf("(Ej: map 0:1) para 0 siendo el numero del archivo de entrada y stream 1 siendo el numero de stream en el archivo 0\nEscriba c para cancelar\n");
				scanf("%c", &temp);
				scanf("%[^\n]", map2);
				if(map2[0] == 'c')map2[0] = ' ';
				else{
				sprintf(temp,"-%s",map2);
				strcpy(map2, temp);
				}
				goto streams;
				break;
				
				//Stream 3
				case 3:
				printf("Elija que stream de entrada usar y en que stream de salida se guardara\n");
				printf("(Ej: map 0:1) para 0 siendo el numero del archivo de entrada y stream 1 siendo el numero de stream en el archivo 0\nEscriba c para cancelar\n");
				scanf("%c", &temp);
				scanf("%[^\n]", map3);
				if(map3[0] == 'c')map3[0] = ' ';
				else{
				sprintf(temp,"-%s",map3);
				strcpy(map3, temp);
				}
				goto streams;
				break;
				
				//Stream 4
				case 4:
				printf("Elija que stream de entrada usar y en que stream de salida se guardara\n");
				printf("(Ej: map 0:1) para 0 siendo el numero del archivo de entrada y stream 1 siendo el numero de stream en el archivo 0\nEscriba c para cancelar\n");
				scanf("%c", &temp);
				scanf("%[^\n]", map4);
				if(map4[0] == 'c')map4[0] = ' ';
				else{
				sprintf(temp,"-%s",map4);
				strcpy(map4, temp);
				}
				goto streams;
				break;
				
				//Stream 5
				case 5:
				printf("Elija que stream de entrada usar y en que stream de salida se guardara\n");
				printf("(Ej: map 0:1) para 0 siendo el numero del archivo de entrada y stream 1 siendo el numero de stream en el archivo 0\nEscriba c para cancelar\n");
				scanf("%c", &temp);
				scanf("%[^\n]", map5);
				if(map5[0] == 'c')map5[0] = ' ';
				else{
				sprintf(temp,"-%s",map5);
				strcpy(map5, temp);
				}
				goto streams;
				break;
				
				//Volver a menu avanzado
				case 6:
				goto menuAv;
				break;
				
				default:
				goto streams;
				break;
				
			}
			break;
			
			//Añadir stream o sub externo
			case 3:
			printf("Escriba la ubicacion del archivo secundario que quiere agregar\n");
			printf("Ej: c:\\subtitulos.srt\nEscriba X para cancelar\n");
			scanf("%c", &temp);
			scanf("%[^\n]", SecFile);
			if((SecFile[0] == 'x') || (SecFile[0] == 'X')) strcpy(SecFile, " ");
			else SecTrue = true;
			goto menuAv;
			break;
			
			//Seleccionar codec de video
			case 4:
			printf("Escriba el codec de video que desea usar\n");
			printf("Ej: h264\nEscriba C para cancelar\n");
			scanf("%c", &temp);
			scanf("%[^\n]", Vcodec);
			sprintf(temp,"-c:v %s",Vcodec);
			strcpy(Vcodec, temp);
			goto menuAv;
			break;
			
			//Seleccionar codec de audio
			case 5:
			printf("Escriba el codec de audio que desea usar\n");
			printf("Ej: mp3\nEscriba C para cancelar\n");
			scanf("%c", &temp);
			scanf("%[^\n]", Acodec);
			sprintf(temp,"-c:a %s",Acodec);
			strcpy(Acodec, temp);
			goto menuAv;
			break;
			
			//Seleccionar codec de sub
			case 6:
			printf("Escriba el codec de subtitulos que desea usar\n");
			printf("Ej: mov_text\nEscriba C para cancelar\n");
			scanf("%c", &temp);
			scanf("%[^\n]", Scodec);
			sprintf(temp,"-c:s %s",Scodec);
			strcpy(Scodec, temp);
			goto menuAv;
			break;
			
			//Volver al menu principal
			case 7:
			goto menu;
			break;
			
			default:
			goto menuAv;
			break;
			
		}
		break;
		
		//Escribir comandos
		case 5:
		//comando si se corta el tiempo de inicio
		if(SecTrue == true)
		{
		if(IncTrue == true)sprintf(cmd,"ffmpeg -i \"%s\"  -i \"%s\" -ss %s %s %s %s %s %s %s %s  %s  -async 1 \"%s.%s\"", InFile, SecFile, IncTime, map1, map2, map3, map4, map5, Vcodec, Acodec, Scodec, OutFile, FileFormat);
		//comando si se corta el tiempo de fin
		if(FinTrue == true)sprintf(cmd,"ffmpeg -i \"%s\" -i \"%s\" -to %s %s %s %s %s %s  %s  %s  %s -async 1 \"%s.%s\"", InFile, SecFile, FinTime, map1, map2, map3, map4, map5, Vcodec, Acodec, Scodec, OutFile, FileFormat);
		//comando si se corta el tiempo de inicio y de fin
		if((IncTrue == true) && (FinTrue == true))sprintf(cmd,"ffmpeg -i \"%s\" -i \"%s\" -ss %s -to %s %s %s %s %s %s  %s  %s  %s -async 1 \"%s.%s\"", InFile, SecFile, IncTime, FinTime, map1, map2, map3, map4, map5, Vcodec, Acodec, Scodec, OutFile, FileFormat);
		//comando si no se corta nada
		if((IncTrue == false) && (FinTrue == false))sprintf(cmd,"ffmpeg -i \"%s\" -i \"%s\" %s %s %s %s %s  %s  %s  %s \"%s.%s\"", InFile, SecFile, map1, map2, map3, map4, map5, Vcodec, Acodec, Scodec, OutFile, FileFormat);
		}
		else{
		
		if(IncTrue == true)sprintf(cmd,"ffmpeg -i \"%s\" -ss %s %s %s %s %s %s  %s  %s  %s  -async 1 \"%s.%s\"", InFile, IncTime, map1, map2, map3, map4, map5, Vcodec, Acodec, Scodec, OutFile, FileFormat);
		//comando si se corta el tiempo de fin
		if(FinTrue == true)sprintf(cmd,"ffmpeg -i \"%s\" -to %s %s %s %s %s %s  %s  %s  %s -async 1 \"%s.%s\"", InFile, FinTime, map1, map2, map3, map4, map5, Vcodec, Acodec, Scodec, OutFile, FileFormat);
		//comando si se corta el tiempo de inicio y de fin
		if((IncTrue == true) && (FinTrue == true))sprintf(cmd,"ffmpeg -i \"%s\" -ss %s -to %s %s %s %s %s %s  %s  %s  %s -async 1 \"%s.%s\"", InFile, IncTime, FinTime, map1, map2, map3, map4, map5, Vcodec, Acodec, Scodec, OutFile, FileFormat);
		//comando si no se corta nada
		if((IncTrue == false)&&(FinTrue == false))sprintf(cmd,"ffmpeg -i \"%s\" %s %s %s %s %s  %s  %s  %s \"%s.%s\"", InFile, map1, map2, map3, map4, map5, Vcodec, Acodec, Scodec, OutFile, FileFormat);
		
		}
		
		printf("Se ejecutara el siguiente comando\n%s",cmd);
		printf("\nEsta usted de acuerdo (S/N)?");
		scanf("%s", agree);
		if((agree[0] == 'S') || (agree[0] == 's'))system(cmd);
		if(agree[0] == 'n' || 'N')goto menu;
		return 0;
		break;
		
		//menu de ayuda
		case 6:
		menuHelp:
		system("cls");
		SetColour(5);
		printf("-------------------------------Menu de ayuda-----------------------------------\n");
		MenuOpAdv(1 ,"Lista de formatos", "");
		MenuOpAdv(2 ,"Lista de codecs", "");
		MenuOpAdv(3 ,"Autores de FFMPEG", "");
		MenuOpAdv(4 ,"Volver al menu principal", "");
		SetColour(5);
		printf("-------------------------------Menu de ayuda-----------------------------------\n\n");
		SetColour(7);

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
			
			//Info sobre los creadores de FFMPEG
			case 3:
			printf("FFMPEG fue creado por el ffmpeg team, y fue lanzado el 20 de diciembre");
			printf("del 2000. Puedes encontrar mas informacion en ffmpeg.org\nEscriba cualquier caracter para salir\n");
			scanf("%s");
			goto menu;
			break;
			
			//Volver al menu principal
			case 4:
			goto menu;
			break;
			
			default:
			goto menuHelp;
			break;
		}
		break;
		
		default : 
		goto menu;
		break;
		
	}
	return 0;

}