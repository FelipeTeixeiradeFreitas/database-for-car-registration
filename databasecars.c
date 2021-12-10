#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2


struct carro
{
	char marca [100];
	char placa [7];
	int codCarro1;
	int al;
	int cod;
	struct carro *proximoCarro;
};
struct carro *primeiroCarro;
struct carro *ultimoCarro;

int i;

struct cliente
{
    char nome [100];
    int codCarro2;
    struct cliente *proximoCliente;
};
struct cliente *primeiroCliente;
struct cliente *ultimoCliente;




void inicia_lista_cliente ()
{
 primeiroCliente = NULL;
 ultimoCliente = NULL;
}

void inicia_lista_carro ()
{
 primeiroCarro = NULL;
 ultimoCarro = NULL;
}



void menu()
{
 printf("MENU\n");
 printf("1-Cadastrar cliente\n");
 printf("2-Mostrar lista de clientes \n");
 printf("3-Cadastrar carro\n");
 printf("4-Mostrar lista de carros \n");
 printf("5-Alterar cliente\n");
 printf("6-Alterar carro\n");
 printf("10-Sair\n");
 printf("\n \n");

}

void altera_carro()
{
	int i=0;
	struct carro* pCarro;
	int buscaCarro;
	char novaPlaca[50];
	char novaMarca[50];
	system ( "cls" );
 printf ( "\n \n \n" );
 printf("Informe o codigo do carro para alterar os registros\n");
 scanf("%d", &buscaCarro);
	pCarro=primeiroCarro;
	while(pCarro!=ultimoCarro)
	{
		
		if(pCarro->codCarro1==buscaCarro)
		{
			printf("Informe a nova marca do carro\n");
			scanf("%s", novaMarca);
			printf("Informe a nova placa do carro\n");
			scanf("%s", novaPlaca);
			strcpy(pCarro->marca, novaMarca);
			strcpy(pCarro->placa, novaPlaca);
			i++;
			break;
		}
		else
		{
			pCarro=pCarro->proximoCarro;
		}
    }
	if(pCarro==ultimoCarro)
	{
	    if(pCarro->codCarro1==buscaCarro)
	    {
		    printf("Informe a nova marca do carro\n");
			scanf("%s", novaMarca);
			printf("Informe a nova placa do carro\n");
			scanf("%s", novaPlaca);
			strcpy(pCarro->marca, novaMarca);
			strcpy(pCarro->placa, novaPlaca);
			i++;
	    }
		else
		{
			pCarro=pCarro->proximoCarro;
		}
	}
}


void altera_cliente()
{
	int i=0;
	struct cliente* pCliente;
	char buscaCliente[50];
	char novo[50];
	system ( "cls" );
 printf ( "\n \n \n" );
 printf("Informe o nome do cliente que deseja alterar\n");
 scanf("%s", buscaCliente);
	pCliente=primeiroCliente;
	while(pCliente!=ultimoCliente)
	{
		
		if(strcmp(pCliente->nome, buscaCliente)==0)
		{
			printf("Informe o nome do novo cliente\n");
			scanf("%s", novo);
			strcpy(pCliente->nome, novo);
			i++;
			break;
		}
		else
		{
			pCliente=pCliente->proximoCliente;
		}
	}
	if(pCliente==ultimoCliente)
	{
		if(strcmp(pCliente->nome, buscaCliente)==0)
		{
			printf("Informe o nome do novo cliente\n");
			scanf("%s", novo);
			strcpy(pCliente->nome, novo);
			i++;
		}
		else
		{
			pCliente=pCliente->proximoCliente;
		}
	}
}


void cadastra_cliente ()
{
 system ( "cls" );
 printf ( "\n \n \n" );

 struct cliente *novoCliente;
 novoCliente = malloc ( 1*sizeof(struct cliente));
 novoCliente->proximoCliente = NULL;

 
 i=10;
 struct carro *pcarro;
	int busca, a ,b;
	printf ( "nome do cliente: \n" );
    fflush ( stdin ); 
    gets ( novoCliente->nome );
	while(i==10){
	printf("informe o codigo do carro que deseja alugar\n");
	    scanf("%d",&busca);
	  
	pcarro=primeiroCarro;
	while(pcarro!=ultimoCarro)
	{
		
		if((pcarro->codCarro1==busca)&&(!pcarro->al))
		{
			printf("carro encontrado\n");
			novoCliente->codCarro2=busca;
			pcarro->al=1;
			i++;
			break;
		}
		else
		{
			pcarro=pcarro->proximoCarro;
		}
	}
	if(pcarro==ultimoCarro)
	{
		if((pcarro->codCarro1==busca)&&(!pcarro->al))
		{
			printf("carro encontrado\n");
			novoCliente->codCarro2=busca;
			pcarro->al=1;
			i++;
		}
		else
		{
			pcarro=pcarro->proximoCarro;
		}
	}
	
	if(i==10){
		printf("Invalido\n \n");
	}


}

 if ( NULL == primeiroCliente )
 {
 primeiroCliente = novoCliente;
 ultimoCliente = primeiroCliente;
 }
 else
 {
 ultimoCliente->proximoCliente = novoCliente;
 ultimoCliente = novoCliente;
 }
 
}

void cadastra_carro ()
{
 system ( "cls" );
 printf ( "\n \n \n" );
 int busca;
struct carro* pesquisaCarro;
 struct carro* novoCarro;
 novoCarro = malloc ( 1*sizeof(struct carro));
 novoCarro->proximoCarro = NULL;

 printf ( "marca do carro: \n" );
 fflush ( stdin ); 
 gets ( novoCarro->marca );

 printf ( "placa do carro: \n" );
 fflush ( stdin ); 
 gets ( novoCarro->placa );
 
 
 i=10;
 while(i==10){
	printf("informe o codigo do carro que deseja alugar\n");
	    scanf("%d",&busca);
	  
	pesquisaCarro=primeiroCarro;
	while(pesquisaCarro!=ultimoCarro)
	{
		
		if((pesquisaCarro->codCarro1==busca)&&(pesquisaCarro->cod))
		{
			printf("Codigo valido\n\n");
			pesquisaCarro->cod=1;
			novoCarro->codCarro1=busca;
			i++;
			break;
		}
		else
		{
			pesquisaCarro=pesquisaCarro->proximoCarro;
		}
	}
	if(pesquisaCarro==ultimoCarro)
	{
		if((pesquisaCarro->codCarro1==busca)&&(pesquisaCarro->cod))
		{
			printf("Codigo valido\n");
			novoCarro->codCarro1=busca;
			pesquisaCarro->cod=1;
			i++;
		}
		else
		{
			pesquisaCarro=pesquisaCarro->proximoCarro;
		}
	}
	
	if(i==10){
		printf("Invalido\n \n");
	}
}

 
 

 if ( NULL == primeiroCarro )
 {
 primeiroCarro = novoCarro;
 ultimoCarro = primeiroCarro;
 }
 else
 {
 ultimoCarro->proximoCarro = novoCarro;
 ultimoCarro = novoCarro;
 }
}

void print_lista_carro()
{
 system ( "cls" );

 printf ( "\n \n \n" );

 struct carro* auxCarro;
 auxCarro = primeiroCarro;

 while ( auxCarro != NULL )
 {
 printf ("Codigo do carro: %d \n", auxCarro->codCarro1);	
 printf ("Marca do carro: %s \n", auxCarro->marca);
 printf ("Placa do carro: %s \n", auxCarro->placa);
 if(auxCarro->al){printf("Carro alugado\n");}else{printf("Carro disponivel\n");}
 printf ("\n");
 auxCarro = auxCarro->proximoCarro;
 }
}


void print_lista_cliente()
{
	int i=0;
 system ( "cls" );

 printf ( "\n \n \n" );
 struct carro* auxCarro;
 auxCarro=primeiroCarro;

 struct cliente* auxCliente;
 auxCliente = primeiroCliente;
 
 while ( auxCliente != NULL )
 {
 printf ("Nome do cliente> %s \n", auxCliente->nome);
 while(auxCarro!=ultimoCarro)
	{
		if(auxCliente->codCarro2==auxCarro->codCarro1)
		{
			printf ("Codigo do carro: %d \n", auxCarro->codCarro1);
			printf("Marca do carro: %s\n", auxCarro->marca);
			printf("Placa do carro: %s\n", auxCarro->placa);
			if(auxCarro->al){printf("Carro alugado\n");}else{printf("Carro disponivel\n");}
			printf("\n");
			i++;
			break;
		}
		else
		{
			auxCarro=auxCarro->proximoCarro;
		}
	}
	if(auxCarro==ultimoCarro)
	{
	
		if(auxCarro->codCarro1==auxCliente->codCarro2)
		{
			printf("Marca do carro: %s\n", auxCarro->marca);
			printf("Placa do carro: %s\n", auxCarro->placa);
			printf("\n");
			auxCliente->codCarro2=auxCarro->codCarro1;
			i++;
		}
		else
		{
			auxCarro=auxCarro->proximoCarro;
		}
	}
	
	if(i==0){
		printf("carro não encontrado\n");
	}
 auxCliente = auxCliente->proximoCliente;
 }
}

/*
void procura_carro()
{
	struct carro *pcarro;
	char busca[100];
	printf("informe a placa do carro\n");
	scanf("%s", busca);
	pcarro=primeiroCarro;
	while(pcarro!=ultimoCarro)
	{
		printf("ciclo\n");
		if(strcmp(pcarro->placa, busca)==0)
		{
			printf("cliente encontrado\n");
		}
		else
		{
			pcarro=pcarro->proximoCarro;
		}
	}
	if(pcarro==ultimoCarro)
	{
		printf("ciclo\n");
		if(strcmp(pcarro->placa, busca)==0)
		{
			printf("cliente encontrado\n");
		}
		else
		{
			pcarro=pcarro->proximoCarro;
		}
	}
}*/


int main()
{
	
	int i=0;
	int opcao;
	inicia_lista_cliente ();
    inicia_lista_carro ();
    while(opcao!=10)
    {
    	menu();
    	scanf("%d", &opcao);
    	switch(opcao)
    	{
    		case 1:
    		    cadastra_cliente();
    		    break;
    	    case 2:
    		    print_lista_cliente();
    		    break;
    	    case 3:
    		    cadastra_carro();
    		    break;
    	    case 4:
    		    print_lista_carro();
    		    break;
    		case 5:
    			altera_cliente();
    			break;
    		case 6:
    			altera_carro();
    			break;
        }
	}
    
    //cadastra();
    //cadastra();
    //mostra();    
 system ( "Pause" );
 return 0;
}

