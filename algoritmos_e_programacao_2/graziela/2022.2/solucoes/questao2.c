#include <stdio.h>
#define MAX 20

struct tipoData
{
	int d, m, a;	// dia, mes, ano
};

struct tipoProd
{
	
	char nome[MAX+1];	
	double preco;		
	tipoData dtvenc;	
	int estoque;		
};


void listaVencidos(tipoData dt, int n, tipoProd v[]);


int estoqueMin(int n, tipoProd v[]);

int main()
{
	int n;

	// leitura de n e dos n produtos
	scanf("%d", &n);

	tipoProd produto[n];
	for(int i = 0; i < n; i++)
	{
		scanf(" %[^\n]", produto[i].nome);
		scanf("%lf", &produto[i].preco);
		
		
		scanf("%d/%d/%d", &produto[i].dtvenc.d, &produto[i].dtvenc.m, &produto[i].dtvenc.a );
		scanf("%d", &produto[i].estoque );
	}
	
	tipoData dt;
	scanf("%d/%d/%d", &dt.d, &dt.m, &dt.a);

	listaVencidos(dt, n, produto);

	// impressao do produto em estoque minimo
	int produtoEstoqueMinimo = estoqueMin(n, produto);
	if(produtoEstoqueMinimo == -1)
	{
		printf("\nProdutos inexistentes");
	}
	else
	{
		printf("\n%s - %.2f - %d\n", produto[produtoEstoqueMinimo].nome, (produto[produtoEstoqueMinimo].preco*produto[produtoEstoqueMinimo].estoque), produto[produtoEstoqueMinimo].estoque);
	}
	
	return 0;
}

void listaVencidos(tipoData dt, int n, tipoProd v[])
{
	for(int i=0; i<n; i++)
	{
		if(v[i].dtvenc.a < dt.a || v[i].dtvenc.a == dt.a && v[i].dtvenc.m < dt.m || v[i].dtvenc.a == dt.a && v[i].dtvenc.m == dt.m && v[i].dtvenc.d <= dt.d )
		{
			printf("%s %d/%d/%d\n", v[i].nome, v[i].dtvenc.d, v[i].dtvenc.m, v[i].dtvenc.a);
		}
	}
}

int estoqueMin(int n, tipoProd v[])
{	
	int indice = -1;
	double maiorValor = -1; 
	for(int i=0; i<n; i++)
	{
		if(v[i].estoque <= 5)
		{	
			double valor;
			valor = (v[i].estoque * v[i].preco);

			if (valor>maiorValor)
			{
				maiorValor = valor;
				indice = i;
			}
		}
	}
	return indice;
}