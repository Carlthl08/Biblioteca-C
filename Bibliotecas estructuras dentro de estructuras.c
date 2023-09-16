//Realizar un programa para controlar varias biblioetcas usando estructuras dentro de estructuras
#include <stdio.h>
#include <string.h>
#define n 50

typedef struct 
{
	char nombre_lib[n];
	char autor[n];
	int lleno_lib;
}libro;

typedef struct 
{
	char nombre_bi[n];
	libro lib[10];
	int lleno_bi;
}biblioteca;

biblioteca bi[3];

void vacio()
{
	
	int i,j;
	
	for(i=0; i<3; i++)
	{
		bi[i].lleno_bi=0;
		for(j=0; j<10; j++)
		{
			bi[i].lib[j].lleno_lib=0;
		}
	}
}

void cambio(char palabra[n])
{
	int i;
	
	for(i=0; i<n; i++)
	{
		if(palabra[i]=='\n')
			palabra[i]=='\0';
	}
}

void anadebi()
{
	int i, aux=0;
	
	for(i=0; i<3 && aux==0;  i++)
	{
		if(bi[i].lleno_bi==0)
		{
			printf("Introdice un nombre para la biblioteca: \n");
			fflush(stdin);
			fgets(bi[i].nombre_bi, n, stdin);
			cambio(bi[i].nombre_bi);
			
			bi[i].lleno_bi=1;
			aux=1;
		}
	}
	
	if(aux==0)
		printf("No queda espacio libre para una nueva biblioteca \n");
}

void anadelib()
{
	int i, op, aux=0; 
	
	for(i=0; i<3; i++)
	{
		if(bi[i].lleno_bi==1)
		{
			printf("%d, %s\n",i,bi[i].nombre_bi);
		}
	}
	scanf("%d", &op);
	
	for(i=0; i<10 && aux==0; i++)
	{
		if(bi[op].lib[i].lleno_lib==0)
		{
			printf("Introduce un nombre del libro: \n");
			fflush(stdin);
			fgets(bi[op].lib[i].nombre_lib, n, stdin);
			cambio(bi[op].lib[i].nombre_lib);
			
			printf("Introduce un nombre del autor: \n");
			fflush(stdin);
			fgets(bi[op].lib[i].nombre_lib, n, stdin);
			cambio(bi[op].lib[i].nombre_lib);
			
			bi[op].lib[i].lleno_lib=1;
			aux=1;
		}
	}
}

void consulta()
{
	int op,i,j,aux;
	char buscar[n];
	
	aux=1;
	
	do
	{
		printf("Que quieres buscar, nombre de libro o nombre autor: \n");
		printf("Nombre del libro......................................1\n");
		printf("Nombre del autor......................................2\n");
		scanf("%d", &op);
	}while(op<1 || op>2);
	
	switch(op)
	{
		case 1:
			printf("Introduce el nombre del libro: \n");
			fflush(stdin);
			fgets(buscar,n,stdin);
			cambio(buscar);
			
			for(i=0; i<3; i++)
			{
				aux=1;
				for(j=0; j<10; j++ )
				{
					aux=strcmp(buscar,bi[i].lib[j].nombre_lib);
					if(aux==0)
					{
						printf("El libro %d se encuentra se encuentra en la biblioteca %s \n", buscar,bi[i].nombre_bi);
						printf("El autor del libro es %d \n", bi[i].lib[j].autor);
					}
				}
			}
		break;
		
		case 2:
			printf("Introduce el nombre del autor: \n");
			fflush(stdin);
			fgets(buscar,n,stdin);
			cambio(buscar);
			
			for(i=0; i<3; i++)
			{
				aux=1;
				for(j=0; j<10; j++ )
				{
					aux=strcmp(buscar,bi[i].lib[j].autor);
					if(aux==0)
					{
						printf("El libro %d se encuentra se encuentra en la biblioteca %s \n", bi[i].lib[j].nombre_lib,bi[i].nombre_bi);
					
					}
				}
			}
			break;
	}
}

int main ()
{
	int op;
	char key;
	
	vacio();
	
	do
	{
		do
		{
			printf("Elige la opcion que deseas \n");
			printf("Anadir una  nueva bliblioetca.....................1\n");
			printf("Anadir un libro a la blioteca.....................2\n");
			printf("Consultar un libro................................3\n");
			printf("Salir.............................................4\n");
			scanf("%d", &op);
		}while(op<1 || op>3);
		
		switch(op)
		{
			case 1:
				anadebi();
				break;
			case 2:
				anadelib();
				break;
			case 3:
				consulta();
				break;
		}
		printf("Introduce si deseas realizar otra operacion \n");
		scanf("%c", &key);
	}while(key=='S' || key== 's');
	system("pause");
}
