#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "interface.h"

using namespace std;	


struct Aluno;
struct Lista{
	int Qtd; 
	Aluno Lista_Pontos[MAX]; 

};

Lista* Cria_Lista(){
	Lista *Pont;
	Pont = (Lista*) malloc(sizeof(Lista));
	if (Pont == NULL){
		return 0;
	}
	Pont ->Qtd=0;
	return Pont;
}

int Tamanho_Lista(Lista *Pont){
	if (Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return -1;
	}else{
		return Pont -> Qtd;
	}
	
}

int Lista_Cheia(Lista *Pont){
	
	if (Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return -1;
	}else{
		return (Pont -> Qtd == MAX); 
	}	
	
}

int Lista_Vazia(Lista *Pont){
		if (Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return -1;
	}else{
		return (Pont -> Qtd == 0); 
	}	
}

int Insere_Final(Lista *Pont, Aluno aluno) {
	if (Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return 0;
	}else if (Lista_Cheia(Pont)){
		cout<<"\nLista esta cheia, não é possível inserir mais alunos!"<<endl;	
		return 0;		
	}else{
		Pont -> Lista_Pontos[Pont -> Qtd] = aluno;
		Pont -> Qtd++; 
		return 1;
}
}       

int Insere_Inicio(Lista *Pont, Aluno aluno){
		if (Pont == NULL){
			cout<<"\nhouve algum problema"<<endl;
			return 0;
		}else if (Lista_Cheia(Pont)){
			cout<<"\nLista esta cheia, não é possível inserir mais alunos!"<<endl;	
			return 0;		
		}else{
			for (int i= Pont -> Qtd; i>=0; i--){ 
				Pont -> Lista_Pontos [i + 1] = Pont -> Lista_Pontos[i];
			}
			
			Pont -> Lista_Pontos[0] = aluno;
			Pont -> Qtd++; 
			return 1;
}		
}

int Inserir_Aluno_Matricula(Lista *Pont, Aluno aluno)	{
		if (Pont == NULL){
			cout<<"\nHouve algum problema"<<endl;
			return 0;
		}else if (Lista_Cheia(Pont)){
			cout<<"\nLista esta cheia, não é possível inserir mais alunos"<<endl;	
			return 0;		
		}else{
			int j= 0;
			while(j < Pont->Qtd && Pont-> Lista_Pontos[j].matricula < aluno.matricula) {
				j++;
			}
			for (int i= Pont -> Qtd - 1; i>= j; i--){ 
				Pont -> Lista_Pontos [i + 1] = Pont -> Lista_Pontos[i];
			}
			Pont -> Lista_Pontos[j] = aluno;
			Pont -> Qtd++;
			return 1;
}
}

int Remove_Inicio(Lista *Pont){
		if (Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return 0;
	}else if (Pont -> Qtd == 0){ 
		cout<<"\nNão foi possível a remoção de alunos na lista, pois ela está vazia!"<<endl;	
		return 0;		
	}else{
		
		for (int i = 0; i < Pont->Qtd; i++){  
				Pont -> Lista_Pontos [i] = Pont -> Lista_Pontos[i + 1];
			}
		Pont -> Qtd--;
		return 1;
}
}

int Remove_Final(Lista *Pont){
	if (Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return 0;
	}else if (Pont -> Qtd == 0){ 
		cout<<"\nNão foi possível a remoção de alunos na lista, pois ela está vazia"<<endl;	
		return 0;		
	}else{
		
		Pont -> Qtd--; 
		return 1;
}
	
}

int Remover_Aluno_Matricula(Lista *Pont, float  aluno_ponto){
		if (Pont == NULL){
			cout<<"\nHouve algum problema"<<endl;
			return 0;
		}else if (Lista_Cheia(Pont)){
			cout<<"\nNão foi possível a remoção de alunos na lista, pois ela está vazia!"<<endl;	
			return 0;		
		}else{
			int i= 0;
			while(i < Pont->Qtd && Pont-> Lista_Pontos[i].matricula != aluno_ponto) { 
				i++;
			}
			if (i == Pont -> Qtd)  { 
				printf("Aluno não encontrado na lista");
				return 0;
			}else{
				for (int j = i; j < Pont->Qtd; j++){
				Pont -> Lista_Pontos [j] = Pont -> Lista_Pontos[j + 1];
			}
			Pont -> Qtd--;
			return 1;
}
}
}

int Consulta_Lista_Pos(Lista *Pont, int Posicao, Aluno *aluno){
	if (Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return 0;
		}else if (Posicao <= 0 || Posicao > Pont->Qtd) {
			cout<<"\nA posição informada não foi encontrada!"<<endl;	
			return 0;		
		}else{
			*aluno = Pont -> Lista_Pontos[Posicao - 1];	
			return 1;			
}
}

int Buscar_matricula_Aluno(Lista *Pont, float escola_ponto, Aluno *aluno){
		if (Pont == NULL){
			cout<<"\nHouve algum problema"<<endl;
			return 0;		
		}else{
			int i= 0;
			while(i <Pont -> Qtd && Pont -> Lista_Pontos[i].matricula != escola_ponto){
				i++;
			}
			if(i == Pont->Qtd){
				cout<<"Aluno não encontrado na lista";
				return 0;
			}
}
}
void Imprimir_Lista(Lista *Pont){
	for (int i =0; i<Pont ->Qtd; i++){
		cout<< ""<<i+1<<"" "-";
		cout<<" "<<"Nome: "<<Pont->Lista_Pontos[i].nome<<"\n";
        cout<<"Sobrenome: "<<Pont->Lista_Pontos[i].sobrenome<<"\n";
        cout<<"Matricula: "<<Pont->Lista_Pontos[i].matricula<<"\n";
        cout<<"Idade: "<<Pont->Lista_Pontos[i].idade<<"\n";
        cout<<"Situação: "<<Pont->Lista_Pontos[i].situacao<<endl;
    }
   }

 

void Liberar_Lista(Lista *Pont){
	free(Pont);
}
