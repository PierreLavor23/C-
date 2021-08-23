#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include "interface.cpp"
using namespace std;

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	char Menu, confirma;
	int Aux, i=1;

	ArvRB *raiz; 
	
	raiz = cria_ArvRB();
	
	cout<<"Uma �rvore RUBRO NEGRA Balanceada foi criada!."<<endl;
	while (i != 0){
		cout<<"Informe o que deseja realizar na �rvore Bin�ria!\nOp��es:"<<endl;
		cout<<"V - Verificar se a �rvore t� vazia;"<<endl;
		cout<<"A - Altura da �rvore;"<<endl;	
		cout<<"Q - Quantidade de N�S na �rvore;"<<endl;
		cout<<"I - Imprimir Estrutura nas Ordens;"<<endl;
		cout<<"N - Inserir novo Elemento;"<<endl;
		cout<<"R - Remover um Elemento;"<<endl;		
		cout<<"B - Buscar um Elemento;"<<endl;
		cout<<"Qualquer outra op��o fechar� a execu��o do Programa!"<<endl;
		cin>>Menu;
		
		Menu = toupper(Menu); 
		switch (Menu){
			case 'V': 
				system("cls");
				if(VeriVazia_ArvRB(raiz)){
					cout<<"�rvore Rubro negra est� Vazia!!"<<endl;
				} else {
					cout<<"�rvore Rubro negra possui elementos !!"<<endl;
				}
				break;
			case 'A': 
				system("cls");
				Aux = Altura_ArvRB(raiz);
				cout<<"Altura da �rvore: "<<Aux<<endl;
				break;
			case 'Q':
				system("cls");
				Aux = QtdNO_ArvRB(raiz);
				cout<<"Quantidade de N�S na �rvore: "<<Aux<<endl;
				break;
			case 'I':
				system("cls");
				cout<<"Arvore Rubro negra(1-Pr� Ordem): "<<endl;
				PreOrdem_ArvRB(raiz, 0);
				break;
			case 'N':
				system("cls");
				cout<<"Qual n�mero deseja inserir na �rvore: ";
				cin>>Aux;
				if(insere_ArvRB(raiz, Aux)){
					cout<<"Inser��o ok!"<<endl;
				} else{
					cout<<"Inser��o falhou!"<<endl;
				}
				break;
			case 'R':
				system("cls");
				cout<<"Qual n�mero deseja Retirar da �rvore: ";
				cin>>Aux;
				if(remove_ArvRB(raiz, Aux)){
					cout<<"Remo��o ok!"<<endl;
				} else{
					cout<<"Remo��o falhou!"<<endl;
				}
				break;
			case 'B':
				system("cls");
				cout<<"Qual n�mero deseja Buscar na �rvore: ";
				cin>>Aux;
				if(consulta_ArvRB(raiz, Aux)){
					cout<<"O N�mero informado est� na �rvore!"<<endl;
				} else{
					cout<<"O N�mero informado n�o est� na �rvore!!"<<endl;
				}
				break;
			default:
					system("cls");
					cout<<"�rvore liberada da mem�ria! Execu��o encerrada!"<<endl;
					libera_ArvRB(raiz);
					exit(0);
				break;
		}
	}
	return 0;
}
	
	

