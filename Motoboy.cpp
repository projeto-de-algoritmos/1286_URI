#include <bits/stdc++.h>
using namespace std;

#define MAX_PIZZAS 40
#define MAX_PEDIDOS 30
#define MAX_TEMPO 100

// pesos e valores
int Qnt_pizzas[MAX_PIZZAS];
int tempo_total[MAX_PEDIDOS];

// matriz de memoização
int memo[MAX_TEMPO][MAX_TEMPO];

int knapsack(int pedidos, int pizzas)
{

    // Caso o item não exista ou não mais caiba na mochila
    // nenhum valor será agregado
    if (pedidos < 0 || pizzas <= 0)
        return 0;

    // Caso este estado já tenha sido resolvido
    if (memo[pedidos][pizzas] != -1)
        return memo[pedidos][pizzas];

    // Caso o item estoure a capacidade da mochila
    // O item não será carregado
    if (Qnt_pizzas[pedidos] > pizzas)
        return memo[pedidos][pizzas] = knapsack(pedidos - 1, pizzas);

    // Caso contrário o valor ótimo será o maior valor entre a decisão
    // de não carregar o item e carregar o item
    return memo[pedidos][pizzas] = max(knapsack(pedidos - 1, pizzas), knapsack(pedidos - 1, pizzas - Qnt_pizzas[pedidos]) + tempo_total[pedidos]);
}

int main()
{

    ios::sync_with_stdio(0);
    
    int numero_de_pedidos;
    while (cin >> numero_de_pedidos)
    {
        if (!numero_de_pedidos)
            return 0;
        // Inicialização da matriz de memoização com -1
        memset(memo, -1, sizeof memo);
        int maximo_pizzas;
        cin >> maximo_pizzas;

        for (int i = 0; i < numero_de_pedidos; ++i)
        {
            cin >> tempo_total[i] >> Qnt_pizzas[i];
        }
        cout << knapsack(numero_de_pedidos - 1, maximo_pizzas) << " min.\n";

        // for (int i = 0; i < MAX_TEMPO; i++)
        // {
        //     for (int j = 0; j < MAX_TEMPO; j++)
        //     {
        //         cout << memo[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }

    return 0;
}