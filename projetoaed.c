#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 256

typedef struct
{
char nome[50];
char cargo[30];
char salario[30];
char cpf[16];
} funcionario;

typedef struct
{
char nome[50];
int cpf;
} cliente;

typedef struct
{
char nome[50];
char marca[30];
char valorVenda[20];
char codigo[20];
cliente clienteAtual;
} veiculo;

/*
void listarClientes();
void geraNotaFiscal(funcionario vendedor, cliente comprador);
void interfaceVendedor();
void cadastraVenda();
*/
void interfaceGerencia();
void cadastraFuncionario();
void cadastraVeiculo();
void listarFuncionarios();
void listarAutomoveis();
void listarVendas();
void criaArquivos();
int demitirFuncionario();

void limpaBuffer(){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return; 
}


int main (){
	int escolha = 0;
  criaArquivos(); /* Cria os primeiros txt na pasta do programa caso ja nao existam */
  while (escolha != 3){
    printf ("Bem vindo. Deseja visualizar as opcoes da loja como gerente ou vendedor?\n1 - Gerente       2 - Vendedor       3 - Sair do programa\n");
    scanf ("%d", &escolha);
    limpaBuffer();
	  if (escolha == 1)
		  interfaceGerencia();
    /*
	  else if (escolha == 2)
		  interfaceVendedor();
	  */
  }
  return 0;
}

void criaArquivos(){
  FILE *vendas = fopen("vendas.txt", "r");
  if (vendas == NULL){
    vendas = fopen ("vendas.txt", "w");
    fprintf (vendas,"Log de vendas da Davizin Automoveis.\n");
    
   }
   fclose(vendas);
  FILE *funcionarios = fopen("funcionarios.txt", "r");
  if (funcionarios == NULL){
    funcionarios = fopen ("funcionarios.txt", "w");
    fprintf (funcionarios,"Lista de funcionarios da Davizin Automoveis.\n\n");
    
  }
  fclose(funcionarios);
  FILE *clientes = fopen("clientes.txt", "r");
  if (clientes == NULL){
    clientes = fopen ("clientes.txt", "w");
    fprintf (clientes,"Lista dos ultimos clientes da Davizin Automoveis.\n");
    
  }
  fclose(clientes);
  FILE *automoveis = fopen("automoveis.txt", "r");
  if (automoveis == NULL){
    automoveis = fopen ("automoveis.txt", "w");
    fprintf (automoveis,"Lista dos carros disponiveis na Davizin Automoveis.\n");
  }
  fclose(automoveis);
  FILE *alugueis = fopen("alugueis.txt", "r");
  if (alugueis == NULL){
    alugueis = fopen ("alugueis.txt", "w");
    fprintf (alugueis,"Log de alugueis ativos da Davizin Automoveis.\n");
  }  
  fclose(alugueis);
}
/*///////////////////////////////////////////////////// FUNCOES COMUNS AS DUAS INTERFACES//////////////////////////////////*/

void listarAutomoveis(){
  char c;
  printf("-----------------------------------------------------\nLista de automoveis disponiveis no patio:\n\n");
  FILE *automoveis = fopen("automoveis.txt", "r");
  do{  
    c = fgetc(automoveis);
    printf("%c" , c);        
    }while (c != EOF);
  fclose(automoveis);
  printf ("-----------------------------------------------------\n");
}

void listarVendas(){
  char c;
  printf("-----------------------------------------------------\nUltimas vendas feitas na Davizin Automoveis\n\n");
  FILE *vendas = fopen("vendas.txt", "r");
  do{  
    c = fgetc(vendas);
    printf("%c" , c);        
    }while (c != EOF);
  fclose(vendas);
  printf ("-----------------------------------------------------\n");
}

/*///////////////////////////////////////////////////// INTERFACE DE GERENTE /////////////////////////////////////////////*/
/*///////////////////////////////////////////////////// INTERFACE DE GERENTE /////////////////////////////////////////////*/
/*///////////////////////////////////////////////////// INTERFACE DE GERENTE /////////////////////////////////////////////*/
/*///////////////////////////////////////////////////// INTERFACE DE GERENTE /////////////////////////////////////////////*/

void interfaceGerencia(){
	int escolha = 0;
  int test;
	while (escolha != 7){
    printf ("Escolha uma das opcoes listadas. \n");
    printf ("1 - Listar funcionarios.\n2 - Adicionar funcionario ao sistema.\n3 - Demitir funcionario.\n4 - Exibir lista dos automoveis do patio. \n5 - Cadastrar novo veiculo no sistema.\n6 - Exibir ultimas vendas.\n7 - Voltar ao menu.\n");
		scanf ("%d", &escolha);
    limpaBuffer();
  	  switch (escolha){
     	  case 1:
         	listarFuncionarios();
          break;
        case 2:
          cadastraFuncionario();
          break;
        case 3:
        	test = demitirFuncionario();
          if (test == 0)
            printf ("\nFuncionario demitido com sucesso!\n");
          break;	
        case 4:
          listarAutomoveis();
          break;
        case 5:
          cadastraVeiculo();
          break;
        case 6:
          listarVendas();
          break;
    }
  }
}

void listarFuncionarios(){
  char c;
  printf(" -----------------------------------------------------\n Gerenciamento de funcionarios da Davizin Automoveis\n\n");
  FILE *funcionarios = fopen("funcionarios.txt", "r");
  do{  
    c = fgetc(funcionarios);
    printf("%c" , c);        
    }while (c != EOF);
  fclose(funcionarios);
  printf ("-----------------------------------------------------\n");
}

void cadastraFuncionario(){
  funcionario *novo;
  novo = (funcionario *)malloc(sizeof(funcionario));
  if (!novo) {
    printf("Não conseguiu alocar a memória\n");
    exit(1);
  }
  FILE *funcionarios = fopen("funcionarios.txt", "a+");
    if(funcionarios == NULL){
    printf("Erro de abertura no arquivo\n");
    exit(1);
    }
  printf ("Qual e o nome do novo funcionario?\n");
    gets(novo->nome);
    fprintf(funcionarios, "Nome: %s\n", novo->nome);
  printf ("Qual sera o cargo do novo funcionario?\n");
    gets(novo->cargo);
    fprintf(funcionarios, "Cargo: %s\n", novo->cargo);
  printf ("Qual sera o salario do novo funcionario?\n");
    gets(novo->salario);
    fprintf(funcionarios, "Salario: %s\n", novo->salario); 
  printf ("Qual e o CPF do novo funcionario?\n");
    gets(novo->cpf);
    fprintf(funcionarios, "CPF: %s\n\n", novo->cpf);
  printf ("\nFUNCIONARIO CADASTRADO!\nNome: %s\nCargo: %s\nSalario: %s\nCPF: %s\n\n", novo->nome, novo->cargo, novo->salario, novo->cpf);
  free (novo);
  fclose(funcionarios);
}

void cadastraVeiculo(){
  veiculo *carro;
  carro = (veiculo *)malloc(sizeof(veiculo));
  FILE *automoveis = fopen("automoveis.txt", "a+");
    if(automoveis == NULL){
    printf("Erro de abertura no arquivo\n");
    exit(1);
    }
  printf ("Qual e o nome do novo veiculo?\n");
    gets(carro->nome);
    fprintf(automoveis, "Nome: %s\n", carro->nome);
  printf ("Qual e a marca do novo veiculo?\n");
    gets(carro->marca);
    fprintf(automoveis, "Marca: %s\n", carro->marca);
  printf ("Qual sera o preco do novo veiculo?\n");
    gets(carro->valorVenda);
    fprintf(automoveis, "Valor: %s\n\n", carro->valorVenda); 
  printf ("\nVEICULO CADASTRADO!\nNome: %s\nMarca: %s\nPreco para venda: %s\n", carro->nome, carro->marca, carro->valorVenda);
  free(carro);
  fclose(automoveis);
}

int demitirFuncionario(){
  int lno, ctr = 0;
  int teste;
  int z = 0;
  char ch;
  FILE *fptr1, *fptr2;
  char funcionarios[MAX] = "funcionarios.txt";
  char str[MAX], temp[] = "temp.txt";
  listarFuncionarios();
  fptr1 = fopen(funcionarios, "r");
  if (!fptr1) 
  {
    printf("Nao foi possivel criar fptr1!\n");
    return 0;
  }
  fptr2 = fopen(temp, "w"); // open the temporary file in write mode 
  if (!fptr2) 
  {
    printf("Nao foi possivel criar fptr2!\n");
    return 0;
  }
  printf("Qual funcionario da lista sera demitido? (Digite a posicao dele na lista de funcionarios)\n");
  scanf("%d", &lno);
  if (lno > 1)
    lno = (5 * (lno-1));
  else
    lno = 1;
  while (!feof(fptr1)) 
  {
    strcpy(str, "\0");
    fgets(str, MAX, fptr1);
    if (!feof(fptr1)) 
    {
      ctr++;
      if (ctr == lno || ctr == lno+1 || ctr == lno+2 || ctr == lno+3 || ctr == lno+4) 
        fprintf(fptr2, "%s", str);
    }
  }
  fclose(fptr1);
  fclose(fptr2);
  fptr1=fopen(temp,"r");  /* mudar pra funcionarios depois da fase de testes */
  ch=fgetc(fptr1); 
  printf("Tem certeza de que deseja remover esse funcionario do sistema?\n"); 
  while(ch!=EOF) 
  { 
    printf("%c",ch); 
    ch=fgetc(fptr1); 
  }
  fclose(fptr1);
  scanf ("%d", &z);
  if (z == 0)
    return 0;
  else{
    fptr1 = fopen(funcionarios, "r");
    fptr2 = fopen(temp, "w");
    ctr = 0;
    while (!feof(fptr1)) 
    {
      strcpy(str, "\0");
      fgets(str, MAX, fptr1);
      if (!feof(fptr1)) 
      {
        ctr++;
        if (ctr != lno && ctr != lno+1 && ctr!= lno+2 && ctr != lno+3 && ctr != lno+4) 
          fprintf(fptr2, "%s", str);
        }
      }
    fclose(fptr1);
    fclose(fptr2);
    remove("funcionarios.txt");      // apaga o funcionarios txt
    rename(temp, funcionarios);  // faz o arquivo temporario virar o novo funcionarios txt
    fptr1=fopen(funcionarios,"r");
    ch=fgetc(fptr1); 
    printf("A lista de funcionarios agora e:\n"); 
    while(ch!=EOF) 
    { 
      printf("%c",ch); 
      ch=fgetc(fptr1); 
    }
    fclose(fptr1);
    return 0;
  }
} 

/*///////////////////////////////////////////////////// INTERFACE DE VENDEDOR /////////////////////////////////////////////*/
/*///////////////////////////////////////////////////// INTERFACE DE VENDEDOR /////////////////////////////////////////////*/
/*///////////////////////////////////////////////////// INTERFACE DE VENDEDOR /////////////////////////////////////////////*/
/*
void interfaceVendedor(){
  int escolha = 0;
  printf ("Escolha uma das opcoes listadas. \n");
  printf ("1 - Iniciar cadastro de venda.\n2 - Exibir ultimas vendas.\n3 - Cadastrar um aluguel.\n4 - Exibir lista dos automoveis do patio.\n");
  while (escolha < 1 || escolha > 4){
    scanf ("%d", &escolha);
    limpa();
  switch (escolha){
      case 1:
        cadastraVenda();
      break;
      case 2:
        listarVendas();
      break;
      case 3:
        cadastraAluguel(); 
      break;
      case 4:
        listarAutomoveis();
      break;
      }
    }
}

void cadastraVenda(){
  funcionario vendedor;
  cliente comprador;
  int valorDavenda;
  FILE *vendas = fopen("vendas.txt", "a+");
  if(vendas == NULL){
    printf("Erro de abertura no arquivo.");
    exit(1);
  }
  printf ("Que vendedor esta iniciando esse processamento?\n");
    gets(vendedor.nome);
    fprintf(vendas, "Vendedor: %s\n", vendedor.nome);
  printf ("Qual e o nome do cliente?\n");
    gets(comprador.nome);
    fprintf(funcionarios, "Nome: %s\n", novo.nome);
  printf ("Qual sera o cargo do novo funcionario?\n");
    gets(novo.cargo);
    fprintf(funcionarios, "Cargo: %s\n", novo.cargo);
  printf ("Qual sera o salario do novo funcionario?\n");
    gets(novo.salario);
    fprintf(funcionarios, "Salario: %s\n", novo.salario); 
  printf ("Qual e o CPF do novo funcionario?\n");
    gets(novo.cpf);
    fprintf(funcionarios, "CPF: %s\n\n", novo.cpf);
  printf ("\nFUNCIONARIO CADASTRADO!\nNome: %s\nCargo: %s\nSalario: %s\nCPF: %s\n", novo.nome, novo.cargo, novo.salario, novo.cpf);
  fclose(funcionarios);
}
*/