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
char cpf[20];
} cliente;

typedef struct
{
char nome[50];
char marca[30];
char valorVenda[20];
} veiculo;

void listarClientes();
void interfaceVendedor();
void cadastrarVenda();
void interfaceGerencia();
void cadastraFuncionario();
void cadastraVeiculo();
void listarFuncionarios();
void listarAutomoveis();
void listarVendas();
void criaArquivos();
void listarFuncionarioss();
int demitirFuncionario();
void removerVeiculo(int codigoDoCarro);

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
	  else if (escolha == 2)
		  interfaceVendedor();
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

void listarFuncionarioss(){
  char c;
  printf(" -----------------------------------------------------\n Funcionarios da Davizin Automoveis\n\n");
  FILE *funcionarioss = fopen("funcionarioss.txt", "r");
  do{  
    c = fgetc(funcionarioss);
    printf("%c" , c);        
    }while (c != EOF);
  fclose(funcionarioss);
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
  FILE *funcionarioss = fopen("funcionarioss.txt", "a+");
    if(funcionarios == NULL){
    printf("Erro de abertura no arquivo\n");
    exit(1);
    }
  printf ("Qual e o nome do novo funcionario?\n");
    gets(novo->nome);
    fprintf(funcionarios, "Nome: %s\n", novo->nome);
    fprintf(funcionarioss, "Nome: %s\n", novo->nome);
  printf ("Qual sera o cargo do novo funcionario?\n");
    gets(novo->cargo);
    fprintf(funcionarios, "Cargo: %s\n", novo->cargo);
    fprintf(funcionarioss, "Cargo: %s\n", novo->cargo);
  printf ("Qual sera o salario do novo funcionario?\n");
    gets(novo->salario);
    fprintf(funcionarios, "Salario: %s\n", novo->salario); 
  printf ("Qual e o CPF do novo funcionario?\n");
    gets(novo->cpf);
    fprintf(funcionarios, "CPF: %s\n\n", novo->cpf);
    fprintf(funcionarioss, "CPF: %s\n\n", novo->cpf);
  printf ("\nFUNCIONARIO CADASTRADO!\nNome: %s\nCargo: %s\nSalario: %s\nCPF: %s\n\n", novo->nome, novo->cargo, novo->salario, novo->cpf);
  free (novo);
  fclose(funcionarios);
  fclose(funcionarioss);
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
  printf ("Qual sera o preco, em reais, do novo veiculo? Ex: 180.000\n");
    gets(carro->valorVenda);
    fprintf(automoveis, "Valor: %s\n\n", carro->valorVenda); 
  printf ("\nVEICULO CADASTRADO!\nNome: %s\nMarca: %s\nPreco para venda: %s\n\n", carro->nome, carro->marca, carro->valorVenda);
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
  fptr2 = fopen(temp, "w");
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
  fptr2=fopen(temp,"r");  /* mudar pra funcionarios depois da fase de testes */
  ch=fgetc(fptr2); 
  printf("Tem certeza de que deseja remover esse funcionario do sistema?\n"); 
  while(ch!=EOF) 
  { 
    printf("%c",ch); 
    ch=fgetc(fptr2); 
  }
  fclose(fptr2);
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

void interfaceVendedor(){
  int escolha = 0;
  while (escolha != 4){
    printf ("Escolha uma das opcoes listadas. \n");
    printf ("1 - Iniciar cadastro de venda.\n2 - Exibir ultimas vendas.\n3 - Exibir lista dos automoveis do patio.\n4 - Voltar ao menu.\n");
    scanf ("%d", &escolha);
    limpaBuffer();
  switch (escolha){
      case 1:
        cadastrarVenda();
      break;
      case 2:
        listarVendas();
      break;
      case 3:
        listarAutomoveis();
      break;
    }
  }
}

void removerVeiculo(int codigoDoCarro){
  int ctr = 0;
  FILE *fptr1, *fptr2;
  char automoveis[MAX] = "automoveis.txt";
  char str[MAX], temp[] = "temp.txt";
  fptr1 = fopen(automoveis, "r");
  if (!fptr1) 
  {
    printf("Nao foi possivel criar fptr1!\n");
  }
  fptr2 = fopen(temp, "w");
  if (!fptr2) 
  {
    printf("Nao foi possivel criar fptr2!\n");
  }
  while (!feof(fptr1)) 
  {
    strcpy(str, "\0");
    fgets(str, MAX, fptr1);
    if (!feof(fptr1)) 
    {
      ctr++;
      if (ctr != codigoDoCarro+1 && ctr != codigoDoCarro+2 && ctr!= codigoDoCarro+3 && ctr!=codigoDoCarro+4) 
        fprintf(fptr2, "%s", str);
    }
  }
  fclose(fptr1);
  fclose(fptr2);
  remove(automoveis);      // apaga o funcionarios txt
  rename(temp, automoveis);  // faz o arquivo temporario virar o novo funcionarios txt
} 

void cadastrarVenda(){
  cliente *comprador;
  comprador = (cliente *)malloc(sizeof(cliente));
  char ch, c;
  int ctr, deuCertoF = 0, deuCertoC = 0, confirma = 0, carro = 0, func = 0, nf;
  int lno, codigoAutomovel = 0, codigoVenda = 25, valorDavenda, deuCertoCliente = 0;
  char data[15];
  char opcao[10];
  FILE *fptr3;
  if(!fptr3){
    printf("Erro de abertura no arquivo.");
    exit(1);
  }
  FILE *fptr1, *fptr2;
  char funcionarios[MAX] = "funcionarios.txt";
  char str[MAX], temp[] = "temp.txt";
  char automoveis[MAX] = "automoveis.txt";
  char tempp[MAX] = "tempp.txt"; 
  char vendastemp[MAX] = "vendastemp.txt";
  while (deuCertoF == 0){
    lno = 0;
    ctr = 0;
    fptr1 = fopen(funcionarios, "r");
    if (!fptr1){
      printf ("Erro de abertura de arquivo.");
      exit(1);
    }
    fptr2 = fopen(temp, "w");
    if (!fptr2){
      printf ("Erro de abertura de arquivo.");
      exit(1);
    }
    printf ("Qual o codigo do vendedor que esta iniciando esse processamento? (Se precisar da lista de funcionarios, digite 0)\n");
    while (lno == 0){
      scanf("%d", &lno);
      if (lno != 0)
        break;
      else
        listarFuncionarioss();
    }
    if (lno > 1)
      lno = (5 * (lno-1));
    else
      lno = 0;
    while (!feof(fptr1)) 
    {
      strcpy(str, "\0");
      fgets(str, MAX, fptr1);
      if (!feof(fptr1)){
        ctr++;
        if (ctr == lno+4 || ctr == lno+1 || ctr == lno+2) 
          fprintf(fptr2, "%s", str);
        }
    }
    fclose(fptr1);
    fclose(fptr2);
    fptr2=fopen(temp,"r");
    ch = fgetc(fptr2); 
    while(ch!=EOF) 
    {  
      printf("%c",ch);
      ch=fgetc(fptr2); 
    }
    printf("\nEsse e o funcionario que esta a fazer o cadastro?\n1 - Sim          0 - Nao\n"); 
    scanf ("%d", &confirma);
    limpaBuffer();
    fclose(fptr2);
    if (confirma == 1)
      deuCertoF = 1;
    }
    while (deuCertoC == 0){
      lno = 0;
      ctr = 0;
      printf ("Qual o numero do automovel que sera vendido na lista? (Se precisar da lista de automoveis, digite 0)\n");
      while (lno == 0){
        scanf("%d", &lno);
        if (lno != 0)
          break;
        else
          listarAutomoveis();
        }
      fptr1 = fopen(automoveis, "r");
      if (!fptr1){
        printf ("Erro de abertura de arquivo.");
        exit(1);
      }
      fptr2 = fopen(tempp, "w");
      if (!fptr2){
        printf ("Erro de abertura de arquivo.");
        exit(1);
      }
      limpaBuffer();
      if (lno > 1)
        lno = (4 * (lno-1));
      else
        lno = 0;
      carro = lno;
      while (!feof(fptr1)) 
      {
        strcpy(str, "\0");
        fgets(str, MAX, fptr1);
        if (!feof(fptr1)){
          if (ctr == lno || ctr == lno+1 || ctr == lno+2) 
            fprintf(fptr2, "%s", str);
            ctr++;
        }
      }
      fclose(fptr1);
      fclose(fptr2);
      fptr2=fopen(tempp,"r");
      ch = fgetc(fptr2);
      while(ch!=EOF) 
      {  
        printf("%c",ch);
        ch=fgetc(fptr2); 
      }
      fclose(fptr2);
      printf("\nEsse e o carro que vai ser vendido?\n1 - Sim          0 - Nao\n"); 
      scanf ("%d", &confirma);
      limpaBuffer();
      if (confirma == 1)
        deuCertoC = 1;
    }
    while (deuCertoCliente == 0){
      printf ("Digite o nome do cliente que esta adquirindo o produto.\n");
      gets(comprador->nome);
      printf ("Digite o CPF do cliente que esta adquirindo o produto.\n");
      gets(comprador->cpf);
      printf ("Confirmar dados do comprador e concluir a venda?\n1 - Confirmar  0 - Corrigir\n");
      scanf ("%d", &deuCertoCliente);
      limpaBuffer();
    }
    fptr3 = fopen("vendas.txt", "a+");
    fptr2 = fopen(temp, "r");
    while (!feof(fptr2)) 
    {
      strcpy(str, "\0");
      fgets(str, MAX, fptr2);
      if (!feof(fptr2)) 
      {
        fprintf(fptr3, "%s", str);
      }
    }
    fclose(fptr2);
    fptr2 = fopen(tempp, "r");
    while (!feof(fptr2)) 
    {
      strcpy(str, "\0");
      fgets(str, MAX, fptr2);
      if (!feof(fptr2)) 
      {
        fprintf(fptr3, "%s", str);
      }
    }
    fprintf (fptr3,"Cliente: %s\nCPF: %s\n\n", comprador->nome, comprador->cpf);
    fclose(fptr2);
    fclose(fptr3);
    printf ("---------------------------------------\nVenda cadastrada com sucesso!\n---------------------------------------\nDeseja verificar a nota fiscal desta venda?\n1 - Sim     0 - Nao\n");
    scanf ("%d", &nf);
    if (nf == 1){
      printf("-----------------------------------------------------\n");
      printf ("Davizin Automoveis LTDA\nCNPJ: 80.933-646/0001-63\nInscricao Estadual: 256847126\nCEP: 89107-000\n");
      fptr3 = fopen(temp, "r");
      do{  
        c = fgetc(fptr3);
        printf("%c" , c);        
      } while (c != EOF);
      fclose(fptr3);
      fptr3 = fopen(tempp, "r");
      do{  
        c = fgetc(fptr3);
        printf("%c" , c);        
      } while (c != EOF);
      fclose(fptr3);
      printf ("Cliente: %s\n", comprador->nome);
      printf ("CPF: %s\n", comprador->cpf);
      printf ("-----------------------------------------------------\n");
    }
    removerVeiculo(carro);
    free(comprador);
}