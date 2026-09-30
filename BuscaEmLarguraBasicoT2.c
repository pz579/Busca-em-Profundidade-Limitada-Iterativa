#include <stdio.h>
#include <stdlib.h>

//Criando novo 'comando' que verifica se é primo
int ehPrimo(int numero) //nome do comando é ehPrimo e ele verifica um numero
{
    //anotando os 25 numeros primos
    int  primos[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    for (int i=0; i<25; i++)
    {
        if (primos[i] == numero)
        {
            return 1; //é PRIMO
        }
    }
    return 0; //não é PRIMO
}

int main()
{
    int pilha[20];

    int profundidade[20];

    int inicio;
    int topo;

    int estado;
    int prof;

    int dir;
    int esq;

    int limite = 0;
    int encontrou = 0;

    printf("Digite a posicao do boneco (0-100): ");
    scanf("%d", &inicio);

    while (encontrou == 0)
    {
        printf("\n==============================\n");
        printf("LIMITE DE PROFUNDIDADE: %d\n", limite);
        printf("==============================\n");

        topo = 0;

        pilha[topo] = inicio;
        profundidade[topo] = 0;
        topo++;

        printf("\nPILHA:");

        for (int i = 0; i < topo; i++)
        {
            printf("| %d (%d) | ", pilha[i], profundidade[i]);
        }

        printf("\n");

        while (topo > 0)
        {

            topo--;

            estado = pilha[topo];
            prof = profundidade[topo];

            printf("\nRetirado: %d | Profundidade: %d\n", estado, prof);

            printf("PILHA:");

            if (topo == 0)
            {
                printf("| vazia |");
            }
            else
            {
                for (int i = 0; i < topo; i++)
                {
                    printf("| %d (%d) | ", pilha[i], profundidade[i]);
                }
            }

            printf("\n");


            if (ehPrimo(estado) == 1)
            {
                printf("\n%d eh a solucao!\n", estado);
                printf("Profundidade: %d\n", prof);

                encontrou = 1;
                break;
            }


            if (prof == limite)
            {
                printf("Limite de profundidade atingido.\n");
                continue;
            }


            dir = estado + 2;

            if (dir <= 100)
            {
                if (topo < 20)
                {
                    pilha[topo] = dir;
                    profundidade[topo] = prof + 1;
                    topo++;

                    printf("\nEmpilhando: %d (%d)\n", dir, prof + 1);

                    printf("PILHA:");

                    for (int i = 0; i < topo; i++)
                    {
                        printf("| %d (%d) | ", pilha[i], profundidade[i]);
                    }

                    printf("\n");
                }
            }


            esq = estado - 5;

            if (esq >= 0)
            {
                if (topo < 20)
                {
                    pilha[topo] = esq;
                    profundidade[topo] = prof + 1;
                    topo++;

                    printf("\nEmpilhando: %d (%d)\n", esq, prof + 1);

                    printf("PILHA:");

                    for (int i = 0; i < topo; i++)
                    {
                        printf("| %d (%d) | ", pilha[i], profundidade[i]);
                    }

                    printf("\n");
                }
            }
        }

        limite++;

        if (limite > 100)
        {
            printf("\nNao encontramos solucao!\n");
            break;
        }
    }

    return 0;
}
