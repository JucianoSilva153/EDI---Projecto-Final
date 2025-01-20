typedef struct produto
{
    char *Tipo;
    float Peso;
} Produto;


Produto* InicializarProduto();
Produto* CriarProduto(char* tipo, float peso);