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
	
	cout<<"Uma Árvore RUBRO NEGRA Balanceada foi criada!."<<endl;
	while (i != 0){
		cout<<"Informe o que deseja realizar na Árvore Binária!\nOpções:"<<endl;
		cout<<"V - Verificar se a Árvore tá vazia;"<<endl;
		cout<<"A - Altura da Árvore;"<<endl;	
		cout<<"Q - Quantidade de NÓS na Árvore;"<<endl;
		cout<<"I - Imprimir Estrutura nas Ordens;"<<endl;
		cout<<"N - Inserir novo Elemento;"<<endl;
		cout<<"R - Remover um Elemento;"<<endl;		
		cout<<"B - Buscar um Elemento;"<<endl;
		cout<<"Qualquer outra opção fechará a execução do Programa!"<<endl;
		cin>>Menu;
		
		Menu = toupper(Menu); 
		switch (Menu){
			case 'V': 
				system("cls");
				if(VeriVazia_ArvRB(raiz)){
					cout<<"Árvore Rubro negra está Vazia!!"<<endl;
				} else {
					cout<<"Árvore Rubro negra possui elementos !!"<<endl;
				}
				break;
			case 'A': 
				system("cls");
				Aux = Altura_ArvRB(raiz);
				cout<<"Altura da árvore: "<<Aux<<endl;
				break;
			case 'Q':
				system("cls");
				Aux = QtdNO_ArvRB(raiz);
				cout<<"Quantidade de NÓS na árvore: "<<Aux<<endl;
				break;
			case 'I':
				system("cls");
				cout<<"Arvore Rubro negra(1-Pré Ordem): "<<endl;
				PreOrdem_ArvRB(raiz, 0);
				break;
			case 'N':
				system("cls");
				cout<<"Qual número deseja inserir na Árvore: ";
				cin>>Aux;
				if(insere_ArvRB(raiz, Aux)){
					cout<<"Inserção ok!"<<endl;
				} else{
					cout<<"Inserção falhou!"<<endl;
				}
				break;
			case 'R':
				system("cls");
				cout<<"Qual número deseja Retirar da Árvore: ";
				cin>>Aux;
				if(remove_ArvRB(raiz, Aux)){
					cout<<"Remoção ok!"<<endl;
				} else{
					cout<<"Remoção falhou!"<<endl;
				}
				break;
			case 'B':
				system("cls");
				cout<<"Qual número deseja Buscar na Árvore: ";
				cin>>Aux;
				if(consulta_ArvRB(raiz, Aux)){
					cout<<"O Número informado está na Árvore!"<<endl;
				} else{
					cout<<"O Número informado não está na Árvore!!"<<endl;
				}
				break;
			default:
					system("cls");
					cout<<"Árvore liberada da memória! Execução encerrada!"<<endl;
					libera_ArvRB(raiz);
					exit(0);
				break;
		}
	}
	return 0;
}
	
	

