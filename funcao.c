#include <stdio.h.>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "estruturas.h"

int menu(){
	int op;
	system ("cls");
	printf ("\t ------------BEM VINDO AO SOFTWARE DE GERENCIAMENTO FARMAC--------------\n");
		printf ("1  - INSERIR NOVO FUNCIONARIO.\n");	
		printf ("2  - MOSTRAR SOMA TOTAL DOS SALARIOS DOS FUNCIONARIOS POR TURNO.\n");
		printf ("3  - INSERIR MEDICAMENTOS. \n");
		printf ("4  - VERIFICAR SE ESSE MEDICAMENTO NECESSITA DE RECEITA.\n");
		printf ("5  - ALTERAR STATUS DE RECEITA DO MEDICAMENTO. \n");
		printf ("6  - VERIFICAR ESTOQUE DO MEDICAMENTO. \n");
		printf ("7  - ATUALIZAR ESTOQUE. \n");
		printf ("8  - QUANTIDADE DE MEDICAMENTOS QUE PRECISAM DE RECEITA. \n");
		printf ("9  - REALIZAR NOVA VENDA.\n");
		printf ("10 - RETORNAR A QUANTIDADE DE VENDAS DE UMA DETERMINADA DATA.\n");
		printf ("11 - VENDEDOR QUE MAIS REALIZOU VENDAS.\n");
		printf ("12 - GERAR NOTA EM XML.\n");
		printf ("13 - SAIR\n");
	scanf ("%d",&op);
	return op;
}
int novo_funcionario (func *funcionario, int i) {	// funçao pra inserir funcionario
	int cont, turno;
	system ("cls");
	printf ("CADASTRO DE NOVO FUNCIONARIO\n");
	printf ("DIGITE O NOME DO FUNCIONARIO:\n");
	fflush(stdin);
	gets(funcionario[i].nome);
	printf ("DIGITE A IDADE DO FUNCIONARIO:\n");
	fflush(stdin);
	gets(funcionario[i].idade);
	printf ("DIGITE O SEXO DO FUNCIONARIO:\n");
	fflush(stdin);
	gets(funcionario[i].sexo);
	printf ("DIGITE O SALARIO DO FUNCIONARIO:\n");
	fflush(stdin);
	scanf("%f",&funcionario[i].salario);
	do {
	printf ("DIGITE O TURNO DO FUNCIONARIO\n 1 - MANHA \n 2 - TARDE \n 3 - NOITE \n");
	fflush (stdin);
	scanf ("%d",&turno);
	if (turno == 1) {
		strcpy(funcionario[i].turno, "MANHA");		//funçao strcpy serve pra copiar os dados pra dentro de uma string
	} else if (turno == 2) {
		strcpy(funcionario[i].turno, "TARDE");
	} else if ( turno ==3 ){
		strcpy(funcionario[i].turno,"NOITE");
	} else {
		printf ("OPÇÃO INVALIDA!\n\n");
	}
	} while (turno != 1 && turno != 2 && turno != 3);  // laço caso um digito seja digitado incorretamente pra selecionar o turno.
	i++;
	printf ("FUNCIONARIO CADASTRADO COM SUCESSO. \n TECLE ENTER PARA VOLTAR.");
	return i;	
	system ("PAUSE");
}


void soma_salario (func *funcionario, int x) {     // função pra fazer a soma dos salarios divido por turno.
	float totalmanha=0, totalnoite=0, totaltarde=0;
	int op, i;
	system ("cls");
	for (i=0;i<x;i++) {
		if (strcmp(funcionario[i].turno,"MANHA")==0) {
		totalmanha=totalmanha+funcionario[i].salario;
	} else if (strcmp(funcionario[i].turno,"TARDE")==0) {
		totaltarde=totaltarde+funcionario[i].salario;
	} else {
		totalnoite=totalnoite+funcionario[i].salario;
		}
	}
	printf ("A SOMA DO SALARIO DE TODOS OS FUNCIONARIOS DA MANHA E DE: %.2f \n", totalmanha);
	printf ("A SOMA DO SALARIO DE TODOS OS FUNCIONARIOS DA TARDE E DE: %.2f \n", totaltarde);
	printf ("A SOMA DO SALARIO DE TODOS OS FUNCIONARIOS DA NOITE E DE: %.2f \n", totalnoite);
	printf ("\n\n TECLE ENTER PARA VOLTAR.\n\n");
}

int cad_medicamento(rem *remedio, int i) {   //cadastro de medicamento
	int receita;
	system ("cls");
	remedio[i].codigo=i;
	printf ("CADASTRO DE MEDICAMENTO.\n");
	printf ("DIGITE O NOME DO MEDICAMENTO:\n");
	fflush(stdin);
	gets (remedio[i].nome);
	printf ("DIGITE O NOME DO FABRICANTE:\n");
	fflush(stdin);
	gets (remedio[i].fabricante);
	printf ("DIGITE A QUANTIDADE EM ESTOQUE:\n");
	scanf ("%d",&remedio[i].quantidade);
	printf ("MEDICAMENTO NECESSITA DE RECEITA?\n 1 - SIM \n 2 - NAO.\n");
	scanf ("%d",&receita);
	if (receita == 1 ) {			//condição pra saber se o medicamento necessita de receita.
		strcpy (remedio[i].necessita_receita,"SIM");			//novamente a strcpy() sendo usada pra copiar dados pra dentro de uma string
	} else {
		strcpy (remedio[i].necessita_receita,"NAO");	
	}
		system ("cls");
		printf ("MEDICAMENTO CADASTRADO COM SUCESSO. \n");
		printf ("CODIGO DO MEDICAMENTO: %d\n", i);
		printf ("NOME: %s \n",remedio[i].nome);
		printf ("QUANTIDADE EM ESTOQUE: %d \n",remedio[i].quantidade);
		printf ("FABRICANTE: %s \n",remedio[i].fabricante);
		printf ("NECESSITA DE RECEITA: %s \n",remedio[i].necessita_receita);
		printf ("TECLE ENTER PARA VOLTAR.\n");
		i++;
		return i;	
	system ("PAUSE");
}

void teste_receita (rem *remedio) {					// a função aqui recebe o codigo do medicamento que foi gerado na função anterior 
	int i;											// e diz se ele necessita ou não de receita
	system ("cls");
	printf ("DIGITE O CODIGO DO MEDICAMENTO:\n");
	scanf ("%d",&i);
	printf ("NOME: %s \n",remedio[i].nome);
	printf ("QUANTIDADE EM ESTOQUE: %d \n",remedio[i].quantidade);
	printf ("FABRICANTE: %s \n",remedio[i].fabricante);
	if (strcmp(remedio[i].necessita_receita,"NAO")) {
			printf ("\nMEDICAMENTO NECESSITA DE RECEITA\n");
		} else if (strcmp(remedio[i].necessita_receita,"SIM")) {
		printf ("\nMEDICAMENTO NAO NECESSITA DE RECEITA\n");
		} else {
			printf ("\nMEDICAMENTO NAO CADASTRADO.");
		}
			printf ("TECLE ENTER PARA VOLTAR\n.");
	}

void alterar_receita (rem *remedio) {				//função para servi de alterador da variavel remedio[i].necessita_receita (pq ta dentro do vetor)
	int i, receita;									// se era sim ela por trocar pra não e vice e versa
	system ("cls");
	printf ("DIGITE O CODIGO DO MEDICAMENTO:\n");
	scanf ("%d",&i);
	printf ("NOME: %s \n",remedio[i].nome);
	printf ("QUANTIDADE EM ESTOQUE: %d \n",remedio[i].quantidade);
	printf ("FABRICANTE: %s \n",remedio[i].fabricante);
	printf ("MEDICAMENTO NECESSITA DE RECEITA?\n 1 - SIM \n 2 - NAO.\n");
	scanf ("%d",&receita);
	if (receita == 1 ) {
		strcpy (remedio[i].necessita_receita,"SIM");		//stycpy() novemante colocando dados dentro da string
	} else {
		strcpy (remedio[i].necessita_receita,"NAO");	
	}
	printf ("MEDICAMENTO ALTERADO COM SUCESSO.\n");
	printf ("TECLE ENTER PARA VOLTAR\n.");
}

void estoque (rem *remedio) {	//função para identificar o estoque de um remedio, é passado o codigo do medicamento e a função retorna nome e a qt do estoque
	int i;
	system ("cls");
	printf ("DIGITE O CODIGO DO MEDICAMENTO:\n");			
	scanf ("%d",&i);
	printf ("O MEDICAMENTO %s POSSUI %d DE ITENS NO ESTOQUE.\n", remedio[i].nome, remedio[i].quantidade);
	printf ("TECLE ENTER PARA VOLTAR.\n");
}

void att_estoque (rem *remedio, int x) {	// função pra atualizar o estoque, aqui ele vai atualizar todos os medicamentos cadastrados
	int i, op;								//perguntando um a um ao usuario se ele deseja atualizar o estoque deste medicamento
	for (i=0;i<x;i++) {
	system ("cls");
	printf ("ATUALIZACAO DE ESTOQUE\n");
	printf ("NOME: %s \n",remedio[i].nome);
	printf ("QUANTIDADE EM ESTOQUE: %d \n\n\n",remedio[i].quantidade);
	printf ("DESEJA ATUALIZAR O ESTOQUE DESTE MEDICAMENTO??\n 1 - SIM \n 2 - NAO\n");
	scanf ("%d",&op);
	if (op == 1) {
		printf ("DIGITE A NOVA QUANTIDADE:\n");
		scanf ("%d",&remedio[i].quantidade);
		printf ("\nESTOQUE ATUALIZADO. \n\n");
		printf ("\n ---------------------------\n");
		} else { 
		printf ("\n ---------------------------\n");
		}	
	}
	printf ("NAO RESTA MAIS NENHUM MEDICAMENTO A SER ATUALIZADO.\n");
	printf ("TECLE ENTER PARA VOLTAR.\n");
}
	
void qt_remedio_receita (rem *remedio, int x) {		//função pra dizer quantos medicamentos em precisam de receita, mas só aqueles que não estão com estoque 0.
	int i, qt_med=0 ;
	system ("cls");
	for (i=0;i<x;i++) {
		if (strcmp(remedio[i].necessita_receita,"NAO") && remedio[i].quantidade>0) {   //strcmp serve pra comparar se for igual retornando 0 ou 1.
			qt_med=qt_med+1;
			printf ("NOME: %s - STATUS: NECESSITA DE RECEITA.\n", remedio[i].nome);
		}
	}
	printf ("EXISTEM %d TIPOS DE REMEDIOS QUE NECESSITAM DE RECEITA. \n",qt_med);
}


int nova_venda (vend *venda, rem *remedio,func *funcionario, int x, int y){ // struct venda, struct remedio, struct funcionario, quant funcinario, quant med.
	int op, op2, op3, cont=0, i, f;											//função pra iniciar uma nova venda(deu um trabalho do carai essa kkk)
	system ("cls");
	printf ("DIGITE O CODIGO DO VENDEDOR:\n");
	scanf ("%d",&op);
	for (i=0;i<x;i++) {
		if (op==i) {
			strcpy (venda[cont].vendedor,funcionario[i].nome);	
			printf ("DIGITE O CODIGO DO PRODUTO:\n");
			scanf ("%d",&op2);
				for (f=0;f<y;f++) {
					if (op2>=y) {
						printf ("PRODUTO NAO CADASTRADO.\n");
					}
					if (op2==f && remedio[f].quantidade>0) {
						printf ("QUANTOS ITENS DESEJA VENDER?\n");
						scanf ("%d",&op3);
							if(remedio[f].quantidade<op3) {
								printf ("QUANTIDADE NAO DISPONIVEL.\n");
								printf ("TECLE ENTER PARA VOLTAR.\n");
							} else {
								remedio[f].quantidade=remedio[f].quantidade-op3;
								printf ("DIGITE A DATA DA VENDA.\n");
								fflush (stdin);
								gets(venda[cont].data);
								strcpy (venda[cont].remedio_vend, remedio[f].nome);
								venda[cont].qt_vd=op3;
								venda[cont].cod_venda=cont;
								cont++;
								funcionario[i].qt_vendas=funcionario[i].qt_vendas+1;
								printf ("\n\nVENDA REALIZADA COM SUCESSO. \n");
								printf ("TECLE ENTER PARA VOLTAR.\n");
								return cont;
							}						
					} 
					if (op2==f && remedio[f].quantidade==0) { 
					printf ("PRODUTO NAO DISPONIVEL EM ESTOQUE:\n");
					printf ("TECLE ENTER PARA VOLTAR.\n");
					}
				}		
		}
		if (op>=x) {
			printf ("FUNCIONARIO NÃO CADASTRADO.\n");
			printf ("TECLE ENTER PARA VOLTAR.\n");
		}		
	}
}

void relatorio_data (vend *venda, int x) {		//função pra relatorio por data (como foi uma suposição não coloquei todos os erros possiveis de um usuario).
	int i;										
	char op[30];
	system ("cls");
	printf ("DIGITE UMA DATA PARA SABER O RELATORIO. \n");
	scanf ("%s",&op);
	for (i=0;i<x;i++){
		if (strcmp(op, venda[i].data)==0) {
		printf ("RELATORIO COMPLETO DO DIA %s\n",op);
		printf ("CODIGO DA VENDA: %d \n",venda[i].cod_venda);
		printf ("DATA DA VENDA: %s\n",venda[i].data);
		printf ("NOME DO VENDEDOR: %s\n",venda[i].vendedor);
		printf ("NOME DO REMEDIO: %s\n",venda[i].remedio_vend);
		printf ("QUANTIDADE VENDIDA: %d\n",venda[i].qt_vd);
		printf ("-----------------------------------------");
		
		}
	}
}

void melhor_vendedor(func *funcionario, int x) { //função para retornar o melhor vendedor.
char nomemelhorfunc[30];
int melhorfunc=0, qtvendas, i;
system ("cls");
for (i=0;i<x;i++) {
		if (funcionario[i].qt_vendas>melhorfunc) {
			strcpy (nomemelhorfunc,funcionario[i].nome);
			qtvendas=funcionario[i].qt_vendas;
			melhorfunc=qtvendas;
			
		}
	}		
	printf ("O NOME DO MELHOR VENDEDOR FOI %s E ELE EFETUOU %d VENDAS.\n", nomemelhorfunc, qtvendas);
	printf ("\n\n TECLE ENTER PARA VOLTAR. \n");
}

void gerador_xml (vend *venda, int x) {
	FILE *arquivo;
	int i;
	
	system ("cls");
	printf ("DIGITE O CODIGO DA VENDA:\n");
	scanf ("%d",&i);
	if (i>=x) {
		printf ("\nVENDA AINDA NÃO REALIZADA:");
	} else {
	arquivo = fopen("Venda.xml" , "w" );
	
	fprintf (arquivo,"<nfeProc xmlns=\"http://www.portalfiscal.inf.br/nfe\" versao=\"3.10\">");
	fprintf (arquivo,"\n<NFe xmlns=\"http://www.portalfiscal.inf.br/nfe\">  ");
	fprintf (arquivo,"\n <infNFe versao=\"3.10\" Id=NFe35141100776574000741550030007231801234893694>  ");
	fprintf (arquivo,"\n <ide>  ");
	fprintf (arquivo,"\n  <cUF>35</cUF> ");
	fprintf (arquivo,"\n <cNF>23489369</cNF>  ");
	fprintf (arquivo,"\n <natOp>Venda de mercadoria adquir. de terceiros</natOp>  ");
	fprintf (arquivo,"\n  <indPag>0</indPag> ");
	fprintf (arquivo,"\n <mod>55</mod>  ");
	fprintf (arquivo,"\n  <serie>3</serie> ");
	fprintf (arquivo,"\n <nNF>723180</nNF>  ");
	fprintf (arquivo,"\n<dhEmi>2014-11-17T03:04:42-02:00</dhEmi>  ");
	fprintf (arquivo,"\n <dhSaiEnt>2014-11-17T03:04:42-02:00</dhSaiEnt>  ");
	fprintf (arquivo,"\n <tpNF>1</tpNF>  ");
	fprintf (arquivo,"\n<idDest>2</idDest>   ");
	fprintf (arquivo,"\n  <cMunFG>3522505</cMunFG>  ");
	fprintf (arquivo,"\n  <tpImp>1</tpImp> ");
	fprintf (arquivo,"\n<tpEmis>1</tpEmis>   ");
	fprintf (arquivo,"\n <cDV>4</cDV>  ");
	fprintf (arquivo,"\n  <tpAmb>1</tpAmb>  ");
	fprintf (arquivo,"\n  <finNFe>1</finNFe> ");
	fprintf (arquivo,"\n     <indFinal>1</indFinal> ");
	fprintf (arquivo,"\n <indPres>2</indPres>  ");
	fprintf (arquivo,"\n  <procEmi>0</procEmi> ");
	fprintf (arquivo,"\n <verProc>ELDOC</verProc>  ");
	fprintf (arquivo,"\n </ide>  ");
	fprintf (arquivo,"\n<emit>");
	fprintf (arquivo,"\n<CNPJ>00776574000741</CNPJ>");
	fprintf (arquivo,"\n   <xNome>B2W Companhia Digital</xNome>");
	fprintf (arquivo,"\n  <enderEmit> ");  
	fprintf (arquivo,"\n <xLgr>Estrada dos Alpes, 555</xLgr>  ");
	fprintf (arquivo,"\n  <nro>S/N</nro> ");
	fprintf (arquivo,"\n <xBairro>Itaqui</xBairro>  ");
	fprintf (arquivo,"\n  <cMun>3522505</cMun> ");
	fprintf (arquivo,"\n <xMun>ITAPEVI</xMun>  ");
	fprintf (arquivo,"\n  <UF>SP</UF> ");
	fprintf (arquivo,"\n  <CEP>06696150</CEP> ");
	fprintf (arquivo,"\n  </enderEmit> ");
	fprintf (arquivo,"\n   <IE>373117480111</IE> ");
	fprintf (arquivo,"\n  <CRT>3</CRT> ");
	fprintf (arquivo,"\n </emit>  ");
	fprintf (arquivo,"\n  <dest> ");
	fprintf (arquivo,"\n    <CPF>05251831404</CPF> ");
	fprintf (arquivo,"\n  <xNome>Kalber Roberto Pereira Silva</xNome> ");
	fprintf (arquivo,"\n  <enderDest> ");
	fprintf (arquivo,"\n   <xLgr>Sao Jose</xLgr> ");
	fprintf (arquivo,"\n  <nro>375</nro> ");
	fprintf (arquivo,"\n  <xBairro>Cruzeiro</xBairro> ");
	fprintf (arquivo,"\n   <cMun>2606408</cMun>");
	fprintf (arquivo,"\n <xMun>GRAVATA</xMun>  ");
	fprintf (arquivo,"\n  <UF>PE</UF>");
	fprintf (arquivo,"\n <CEP>55644360</CEP> ");
	fprintf (arquivo,"\n <fone>8198739789</fone>  ");
	fprintf (arquivo,"\n   </enderDest>  ");
	fprintf (arquivo,"\n  <indIEDest>9</indIEDest> ");
	fprintf (arquivo,"\n </dest> ");
	fprintf (arquivo,"\n   <det nItem=\"1\"> ");
	fprintf (arquivo,"\n  <prod> ");
	fprintf (arquivo,"\n <cProd>116607744</cProd>	  ");
	fprintf (arquivo,"\n  <cEAN>7892110165099</cEAN> ");
	fprintf (arquivo,"\n   <xProd> %s </xProd> ",venda[i].remedio_vend);  // nome do produto
	fprintf (arquivo,"\n <NCM>85234990</NCM>  ");
	fprintf (arquivo,"\n  <CFOP>6404</CFOP> ");
	fprintf (arquivo,"\n <uCom>PC</uCom>  ");
	fprintf (arquivo,"\n <qCom>%d</qCom>  ",venda[i].qt_vd);   // quantidade itens vendidos
	fprintf (arquivo,"\n  <vUnCom>54.90</vUnCom> ");     
	fprintf (arquivo,"\n <vProd>54.90</vProd>  ");
	fprintf (arquivo,"\n  <cEANTrib>7892110165099</cEANTrib> ");
	fprintf (arquivo,"\n <uTrib>PC</uTrib>  ");
	fprintf (arquivo,"\n  <qTrib>1</qTrib> ");
	fprintf (arquivo,"\n <vUnTrib>54.90</vUnTrib>  ");
	fprintf (arquivo,"\n <vFrete>35.09</vFrete>  ");
	fprintf (arquivo,"\n  <indTot>1</indTot> ");
	fprintf (arquivo,"\n   </prod> ");
	fprintf (arquivo,"\n  <imposto> ");
	fprintf (arquivo,"\n <ICMS>  ");
	fprintf (arquivo,"\n  <ICMS60> ");
	fprintf (arquivo,"\n  <orig>0</orig> ");
	fprintf (arquivo,"\n  <CST>60</CST> ");
	fprintf (arquivo,"\n  <vBCSTRet>0.00</vBCSTRet> ");
	fprintf (arquivo,"\n  <vICMSSTRet>0.00</vICMSSTRet> ");
	fprintf (arquivo,"\n  </ICMS60> ");
	fprintf (arquivo,"\n </ICMS>  ");
	fprintf (arquivo,"\n   <PIS> ");
	fprintf (arquivo,"\n  <PISAliq>  ");
	fprintf (arquivo,"\n  <CST>01</CST> ");
	fprintf (arquivo,"\n <vBC>89.99</vBC>  ");
	fprintf (arquivo,"\n  <pPIS>1.65</pPIS> ");
	fprintf (arquivo,"\n   <vPIS>1.48</vPIS> ");
	fprintf (arquivo,"\n  </PISAliq>  ");
	fprintf (arquivo,"\n </PIS>  ");
	fprintf (arquivo,"\n  <COFINS> ");
	fprintf (arquivo,"\n <COFINSAliq>  ");
	fprintf (arquivo,"\n  <CST>01</CST>  ");
	fprintf (arquivo,"\n  <vBC>89.99</vBC> ");
	fprintf (arquivo,"\n  <pCOFINS>7.60</pCOFINS>  ");
	fprintf (arquivo,"\n  <vCOFINS>6.84</vCOFINS> ");
	fprintf (arquivo,"\n </COFINSAliq>  ");
	fprintf (arquivo,"\n  </COFINS> ");
	fprintf (arquivo,"\n  </imposto> ");
	fprintf (arquivo,"\n </det>  ");
	fprintf (arquivo,"\n  <total> ");
	fprintf (arquivo,"\n  <ICMSTot>  ");
	fprintf (arquivo,"\n  <vBC>0.00</vBC> ");
	fprintf (arquivo,"\n <vICMS>0.00</vICMS>  ");
	fprintf (arquivo,"\n  <vICMSDeson>0.00</vICMSDeson>  ");
	fprintf (arquivo,"\n   <vBCST>0.00</vBCST> ");
	fprintf (arquivo,"\n  <vST>0.00</vST> ");
	fprintf (arquivo,"\n  <vProd>54.90</vProd> ");
	fprintf (arquivo,"\n <vFrete>35.09</vFrete>  ");
	fprintf (arquivo,"\n  <vSeg>0.00</vSeg> ");
	fprintf (arquivo,"\n   <vDesc>0.00</vDesc> ");
	fprintf (arquivo,"\n  <vII>0.00</vII>  ");
	fprintf (arquivo,"\n  <vIPI>0.00</vIPI>  ");
	fprintf (arquivo,"\n  <vPIS>1.48</vPIS>  ");
	fprintf (arquivo,"\n  <vCOFINS>6.84</vCOFINS> ");
	fprintf (arquivo,"\n   <vOutro>0.00</vOutro> ");
	fprintf (arquivo,"\n <vNF>89.99</vNF>  ");
	fprintf (arquivo,"\n    </ICMSTot> ");
	fprintf (arquivo,"\n </total>  ");
	fprintf (arquivo,"\n  <transp>  ");
	fprintf (arquivo,"\n  <modFrete>1</modFrete> ");
	fprintf (arquivo,"\n <vol>  ");
	fprintf (arquivo,"\n <qVol>1</qVol>  ");
	fprintf (arquivo,"\n  <pesoL>0.150</pesoL>  ");
	fprintf (arquivo,"\n <pesoB>0.150</pesoB>  ");
	fprintf (arquivo,"\n  </vol> ");
	fprintf (arquivo,"\n  </transp>  ");
	fprintf (arquivo,"\n  <infAdic> ");
	fprintf (arquivo,"\n  <infCpl>Nf.Id: 91217269 -Nao incidencia de ICMS - Mercadoria com Substituicao Tributaria, conforme Art 310 RICMS- 30 de novembro de 2000  Impostos Pagos: ICMS: R$ 3,62 (4,02%) ICMS-ST: R$ 5,01 (5,57%) PIS: R$ 1,48 (1,64%) COFINS: R$ 6,84 (7,60%);  N. Pedido: 02-579585504 N. Entrega: 363230371.</infCpl> ");
	fprintf (arquivo,"\n   <obsCont xCampo=\"SiglaERP\">  ");
	fprintf (arquivo,"\n  <xTexto>ORACLE</xTexto> ");
	fprintf (arquivo,"\n   </obsCont> ");
	fprintf (arquivo,"\n <obsCont xCampo=\"Logo\">  ");
	fprintf (arquivo,"\n  <xTexto>ACOM</xTexto>	 ");
	fprintf (arquivo,"\n  </obsCont> ");
	fprintf (arquivo,"\n <obsCont xCampo=\"NomedaMarca\">  ");
	fprintf (arquivo,"\n <xTexto>Americanas.com</xTexto>  ");
	fprintf (arquivo,"\n     </obsCont> ");
	fprintf (arquivo,"\n  </infAdic> ");
	fprintf (arquivo,"\n </infNFe>  ");
	fprintf (arquivo,"\n  <Signature xmlns=\"http://www.w3.org/2000/09/xmldsig#\"> ");
	fprintf (arquivo,"\n <SignedInfo>  ");
	fprintf (arquivo,"\n <CanonicalizationMethod Algorithm=\"http://www.w3.org/TR/2001/REC-xml-c14n-20010315\"/>  ");
	fprintf (arquivo,"\n   <SignatureMethod Algorithm=\"http://www.w3.org/2000/09/xmldsig#rsa-sha1\"/>  ");
	fprintf (arquivo,"\n <Reference URI=\"#NFe35141100776574000741550030007231801234893694\">  ");
	fprintf (arquivo,"\n <Transforms>  ");
	fprintf (arquivo,"\n <Transform Algorithm=\"http://www.w3.org/2000/09/xmldsig#enveloped-signature\"/>  ");
	fprintf (arquivo,"\n <Transform Algorithm=\"http://www.w3.org/TR/2001/REC-xml-c14n-20010315\"/>  ");
	fprintf (arquivo,"\n   </Transforms>  ");
	fprintf (arquivo,"\n  <DigestMethod Algorithm=\"http://www.w3.org/2000/09/xmldsig#sha1\"/> ");
	fprintf (arquivo,"\n <DigestValue>s64I/lcQq0VrkXNm5T0d+gH32kk=</DigestValue>  ");
	fprintf (arquivo,"\n   </Reference> ");
	fprintf (arquivo,"\n   </SignedInfo> ");
	fprintf (arquivo,"\n  <SignatureValue>aI2CT+F2jbqN4YqQnx6UKwqPm/j8zMmo/cz46nUnzG0dunsujYu+C/IMSZB7wldtzHtdjIzs6FWj3/ApCQ2VnPn/wRUiQvua1Rda+XwHhCg2OWrmEjdlVgcw8P599xLOPV/fcq1Fr6+nGDEJfJGdQbSWOTZrrROKFZgaxlBYXSywSajDgjZti63gTUxaV3DOLNYcD7W/LNSaZ3Gw4B4nSywQyIJhE1XRYsm7TvO4WyeHFQAlzesAmRZnkc4CT3fLJ/x9YqwXqIauZJ7znDoJpuEd/4vWNLGrYSnwMM2QUgnURtI2govjgGlTaRtgWiyNaE7RYhjf92NMimalXwsimA==</SignatureValue> ");
	fprintf (arquivo,"\n <KeyInfo>   ");
	fprintf (arquivo,"\n <X509Data> ");
	fprintf (arquivo,"\n  <X509Certificate>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</X509Certificate> ");
	fprintf (arquivo,"\n</X509Data>   ");
	fprintf (arquivo,"\n    </KeyInfo>  ");
	fprintf (arquivo,"\n  </Signature> ");
	fprintf (arquivo,"\n  </NFe>");
	fprintf (arquivo,"\n  <protNFe versao=\"3.10\">");
	fprintf (arquivo,"\n <infProt>  ");
	fprintf (arquivo,"\n <tpAmb>1</tpAmb>  ");
	fprintf (arquivo,"\n  <verAplic>SP_NFE_PL_008d</verAplic>  ");
	fprintf (arquivo,"\n   <chNFe>35141100776574000741550030007231801234893694</chNFe> ");
	fprintf (arquivo,"\n   <dhRecbto>2014-11-17T03:05:01-02:00</dhRecbto> ");
	fprintf (arquivo,"\n  <nProt>135140725516814</nProt> ");
	fprintf (arquivo,"\n  <digVal>s64I/lcQq0VrkXNm5T0d+gH32kk=</digVal> ");
	fprintf (arquivo,"\n   <cStat>100</cStat>  ");
	fprintf (arquivo,"\n   <xMotivo>Autorizado o uso da NF-e</xMotivo> ");
	fprintf (arquivo,"\n </infProt>  ");
	fprintf (arquivo,"\n   </protNFe> ");
	fprintf (arquivo,"\n  </nfeProc> ");
	fclose(arquivo);
	
		printf ("\n\n NOTA GERADA COM SUCESSO, TECLE ENTER PARA VOLTAR. \n");
	}

}
