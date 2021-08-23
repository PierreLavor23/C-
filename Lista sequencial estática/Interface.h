#define MAX 8
struct Aluno {
        char nome[50];
        char sobrenome[50];
        char situacao[30] = "Cursando";
        int matricula, idade;
        float nota_1 ;
		float nota_2 ;
        float calc_med_1;
        float calc_med_2;
        float calc_med;
		float media_final;
       


};
struct Lista;

Lista* Cria_Lista();
int Tamanho_Lista(Lista *Pont);
int Lista_Cheia(Lista *Pont);
int Lista_Vazia(Lista *Pont);
int Insere_Final(Lista *Pont, Aluno aluno) ;           
int Insere_Inicio(Lista *Pont, Aluno aluno);
int Inserir_Aluno_Matricula(Lista *Pont, Aluno aluno);
void Imprimir_Lista(Lista *Pont);
void Liberar_Lista(Lista *Pont);
int Remove_Final(Lista *Pont);
int Remove_Inicio(Lista *Pont);
int Remover_Aluno_Matricula(Lista *Pont, float  aluno_ponto);
int Consulta_Lista_Pos(Lista *Pont, int Posicao, Aluno *aluno);
int Buscar_matricula_Aluno(Lista *Pont, float escola_ponto, Aluno *aluno);
