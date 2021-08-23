
typedef struct NO* ArvRB;

ArvRB* cria_ArvRB();
void libera_ArvRB(ArvRB* raiz);

int insere_ArvRB(ArvRB* raiz,int valor);
int remove_ArvRB(ArvRB *raiz, int valor);

int VeriVazia_ArvRB(ArvRB *raiz);
int QtdNO_ArvRB(ArvRB *raiz);
int Altura_ArvRB(ArvRB *raiz);

int consulta_ArvRB(ArvRB *raiz, int valor);


void PreOrdem_ArvRB(ArvRB *raiz, int H);

