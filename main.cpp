#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cctype>
#include <conio.h>
#include <cstdlib>
#include <string>

using namespace std;
#define T 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int num;
	string opt;	
	int op;
	string mat = "Matematicas";
	string fic = "Fisica";
	string pro = "Programacion";
	int materias = 0;
	int estudiantes_suspensos = 0;
	int estudiantes_aprobados = 0;
	int flag;
			
	cout <<"\n	*** 	MENU	***		\n"<<endl;
	printf("Recuerte que las notas estan enumeradas de la siguiente forma\n\nNota 1: Matematicas; Nota 2: Fisica; Nota 3: Programacion\n\n");
	printf("Ingrese la cantidad de estudiantes: \n");
	cin>> num;
	//scanf("%d", &num);
	
	int lista_estudiante[num][3];
	
	for (int i= 0; i < num; i++){
		printf("Ingrese las notas del Estudiante %d: \n", i+1);
		for(int j= 0; j < 3; j++){
			printf("Nota %d: \n", j+1);
			scanf("%d", &lista_estudiante[i][j]);
		}
	}
	
	/* MUESTRA LA MATRIZ DE NOTAS */
	for (int i= 0; i < num; i++){
		printf("\nEstudiante %d: ", i+1);
		for(int j= 0; j < 3; j++){
			printf("nota %d: %d; ", j+1, lista_estudiante[i][j]);
		}
	}
	
	do{
		printf("\n\t	*******************		\n");
		printf("\n\n\tA continuacion opciones de visualizacion de notas\n");
		printf("\n - Ingrese 1 : Si desea conocer estudiantes suspendidos en alguna materia\n");
		printf("\n - Ingrese 2 : Si desea conocer estudiantes aprobados en todas las materias\n");
		printf("\n - Ingrese 3 : Si desea salir del programa\n");
		printf("\t Ingrese una opcion (solo dato numerico): \n");
		cin >> opt;	
		op = atoi(opt.c_str());	
		
		switch(op){
			case 1:
				puts("\n\t**Estudiantes suspendidos en alguna materia**");
				for (int i= 0; i < num; i++){
					flag = 0;
					for(int j= 0; j < 3; j++){
						if(lista_estudiante[i][j] < 70){							
							flag = 1;
						}
					}
					if (flag ==1){
						estudiantes_suspensos++;
					}
				}
				printf("\n Hay %d estudiantes suspendidos en alguna materia\n", estudiantes_suspensos);
				break;
			case 2:
				puts("\n\tEstudiantes aprobados en todas las materias\n");				
				for (int i= 0; i < num; i++){
					printf("\nEstudiantes Aprobados (>70): \n");
					for(int j= 0; j < 3; j++){		
						if(lista_estudiante[i][j] > 70){
							materias++;
						}
					}
					if(materias == 3){
						estudiantes_aprobados++;
					}
				}
				printf("\n Hay %d estudiantes aprobados\n", estudiantes_aprobados);
				break;
			case 3:
				puts("\n\tOpción 3\n");
				break;
			case 4:
				puts("\n\tOpción 4\n");
				break;			
			default:
				break;
		}
				
	}while(!(op>0 && op<=4));

	system("pause");
	return 0;	
}

