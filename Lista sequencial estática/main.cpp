#include <iostream>

#include <locale.h>

#include <math.h>

#include <stdlib.h>

#include "interface.h"



using namespace std;


int main(){

   setlocale(LC_ALL, "Portuguese");

   Lista *Lista_Alunos;

   Aluno P, *Pont_P;

   Pont_P = &P;

   int i=1, Aux=0;

   char Menu;
  
	
   Lista_Alunos = Cria_Lista();

   cout<<"Uma Lista_Alunos foi criada."<<endl;

   while (i != 0){

      cout<<"O que Deseja Consultar na Lista?\nOpções:"<<endl;

      cout<<"C - Consultar tamanho da Lista:"<<endl;

      cout<<"I - Imprimir a Lista:"<<endl;   

      cout<<"Q - Inserir Aluno no Inicio da Lista:"<<endl;

      cout<<"W - Inserir Aluno no Final da Lista:"<<endl;

      cout<<"E - Inserir Aluno Pela Matrícula:"<<endl;
      cout<<"F - Retirar Aluno no Inicio da lista:"<<endl;
      cout<<"Z - Retirar Aluno no Final da Lista:"<<endl;
      cout<<"X - Retirar Aluno Pela Matrícula:"<<endl;
      cout<<"N - Buscar Aluno Pela Matrícula:"<<endl;
      cout<<"B - Buscar Aluno Pela Posição na Lista:"<<endl;
      

      cout<<"Qualquer outra opção fechará o Programa!!!"<<endl;

      cin>>Menu;

      

      Menu = toupper(Menu); 

      switch (Menu){

         case 'C': 

            Aux = Tamanho_Lista(Lista_Alunos);

            cout<<"Quantidade de Alunos na Lista: "<<Aux<<endl;

            break;

         case 'I': 

            Imprimir_Lista (Lista_Alunos);

            break;

         case 'Q':

            cout<<"Nome do Aluno: "; cin>>P.nome;

            cout<<"Sobrenome do Aluno: "; cin>>P.sobrenome; 
            
            cout<<"Matrícula do Aluno: "; cin>>P.matricula; 
             
            cout<<"Idade do Aluno: "; cin>>P.idade; 

            Aux = Insere_Inicio(Lista_Alunos, P);

            if (Aux==0){

               cout<<"Houve um Erro";

            }

            break;

         case 'W':

            cout<<"Nome do Aluno: "; cin>>P.nome;

            cout<<"Sobrenome do Aluno: "; cin>>P.sobrenome; 
            
            cout<<"Matrícula do Aluno: "; cin>>P.matricula; 
             
            cout<<"Idade do Aluno: "; cin>>P.idade;

            Aux = Insere_Final(Lista_Alunos, P);

            if (Aux==0){

               cout<<"Houve um erro";
				
            }

            break;

         case 'E':

            cout<<"Informe a Matrícula: "; cin>>P.matricula;

            

            Aux = Inserir_Aluno_Matricula(Lista_Alunos, P);

            if (Aux==0){

               cout<<"Matricula Inexistente!";

            } 

            break;
        case 'F':
        		
				Aux = Remove_Inicio(Lista_Alunos);
				if (Aux == 0) {
					cout<<"Não foi possível pois houve um erro!";
				}
  				break;
   		case 'Z':
   				
   				Aux = Remove_Final(Lista_Alunos);
				if (Aux == 0) {
					cout<<"Não foi possível, pois houve um erro!";
				}
   				break;
   		case 'X' :
   			cout<<"Informe a Matrícula que Deseja Remolver:"; cin>>P.matricula; 
			Aux = Remover_Aluno_Matricula (Lista_Alunos, P.matricula);
			if (Aux == 0) {
				cout<<"Não foi possível, pois houve um erro!";
				}		
   			break;
   		case 'B' :
   			cout<<"Digite a Posição do Aluno na Lista: "; cin>>Aux;
   			Aux = Consulta_Lista_Pos(Lista_Alunos, Aux, Pont_P);
   			if (Aux == 0) {
				cout<<"Não foi possível, pois houve um erro!";
			}else{
				cout<<"\n"<<"Aluno Solicitado: "<<P.nome<<" "<<P.sobrenome<<"\n"<<"Matrícula: "<<P.matricula<<"\n"<<"Idade: "<<P.idade<<"\n"<<endl;
				cout<<"\nDigite S para alterar a nota!"<<endl;
      			cout<<"Digite N para não alterar a nota!"<<endl;
				char Soma;
					
      			cin>>Soma;

      			Soma = toupper(Soma);

     			switch (Soma){

         			case 'S': 
         				cout<<"\nNota 1: ";cin>>P.nota_1;
         				cout<<"Nota 2: ";cin>>P.nota_2;
         				P.calc_med_1 = P.nota_1 * 0.4;
         				P.calc_med_2 = P.nota_2 * 0.6;
         				P.calc_med = P.calc_med_1 + P.calc_med_2;
         				P.media_final = P.calc_med;
         				if (P.media_final>=6){
         					cout<<"\nNota 1: " << P.nota_1<<endl;
         					cout<<"Nota 2: " <<P.nota_2<<endl;
         					cout<<"Média Final: "<<P.media_final<<endl;
         					cout<<"Aluno Aprovado!!!"<<endl;
         					
						}else{
							cout<<"\nNota 1: " << P.nota_1<<endl;
         					cout<<"Nota 2: " <<P.nota_2<<endl;
         					cout<<"Média Final: "<<P.media_final<<endl;       						
         					cout<<"Aluno Reprovado!!!"<<endl;
         						
							}
							break;

            			
            			case 'N':
            				
            				cout<<"Notas não alteradas!"<<endl;
            				
            				break;
   	
			}
			}
			
			break;
		case 'N':
            cout<<"Informe a Matrícula do Aluno: "; cin>>Aux;
        	Aux =  Buscar_matricula_Aluno(Lista_Alunos, P.matricula, Pont_P);
            if (Aux == 0) {
            	cout<<"Não foi Possível Pois Houve um Erro!";
            }else{
                cout<<"Digite a matrícula do Aluno desejado: "<<P.matricula<<P.nome<<endl;
                cout<<"\n"<<"Aluno Solicitado: "<<P.nome<<" "<<P.sobrenome<<"\n"<<"Matrícula: "<<P.matricula<<"\n"<<"Idade: "<<P.idade<<"\n"<<endl;
				cout<<"\nDigite S para alterar a nota!"<<endl;
      			cout<<"Digite N para não alterar a nota!"<<endl;
			 
				char Soma;
				
					
      			cin>>Soma;

      

      			Soma = toupper(Soma);

     			switch (Soma){

         			case 'S': 
         				cout<<"\nNota 1: ";cin>>P.nota_1;
         				cout<<"Nota 2: ";cin>>P.nota_2;
         				P.calc_med_1 = P.nota_1 * 0.4;
         				P.calc_med_2 = P.nota_2 * 0.6;
         				P.calc_med = P.calc_med_1 + P.calc_med_2;
         				P.media_final = P.calc_med;
         				if (P.media_final>=6){
         					cout<<"\nNota 1: " << P.nota_1<<endl;
         					cout<<"Nota 2: " <<P.nota_2<<endl;
         					cout<<"Média Final: "<<P.media_final<<endl;
         					cout<<"Aluno Aprovado!!!"<<endl;
         					
						}else{
							cout<<"\nNota 1: " << P.nota_1<<endl;
         					cout<<"Nota 2: " <<P.nota_2<<endl;
         					cout<<"Média Final: "<<P.media_final<<endl;       						
         					cout<<"Aluno Reprovado!!!"<<endl;
         							
							}
							break;

            			
            			case 'N':
            				
            				cout<<"\nNotas não alteradas!"<<endl;
            				
            				break;
        	}
			}
			
            break;	
   		
         default: 

            cout<<"Lista encerrada!"<<endl;

            Liberar_Lista(Lista_Alunos);

            exit(0);

            break;

      }

      cout<<endl<<endl;

   }

   return 0;

}
