//structs
struct func1 {    // struct de funcionario
	char nome[50], idade[50], sexo[50], turno[20];
	float salario;
	int qt_vendas;
};
typedef struct func1 func;
struct rem1 {   // struct de remedio
	char nome [50], fabricante[50], necessita_receita[5];
	int quantidade, codigo;
};
typedef struct rem1 rem;
struct vend1 {   //struct de venda
	char data[10], vendedor[30], remedio_vend[30];
	int qt_vd, cod_venda;
};
typedef struct vend1 vend;

//funções usadas no programa
int novo_funcionario (func *funcionario, int i);
void soma_salario (func *funcionario, int x);
void rel_funcionario(func *funcionario, int x);
int cad_medicamento(rem *remedio, int i);
void teste_receita (rem *remedio);
void alterar_receita (rem *remedio);
void estoque (rem *remedio);
void att_estoque (rem *remedio, int x);
void qt_remedio_receita (rem *remedio, int x);
int nova_vend (rem *remedio, vend *venda, int x);
void relatorio_vendas (vend *venda, int x);
int nova_venda (vend *venda, rem *remedio,func *funcionario, int x, int y);
void melhor_vendedor(func *funcionario, int x);
void relatorio_data (vend *venda, int x);
void gerador_xml (vend *vendas, int x);
int menu();
