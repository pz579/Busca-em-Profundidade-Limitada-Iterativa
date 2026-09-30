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
    //Criando as variáveis que formarão a fila
    int a,b,c,d,e;  //TODO: fazer FILA sem usar varias variáveis, aumentar o tamanho pra 10
    int atendido;
    int dir, esq;
    int incompleto = 0;  //FLAG, levantamos a bandeira se houver um problema
    int filaVazia;

    printf("Por favor digite a posicao do boneco (0-100): "); //perguntar
    scanf("%d",&a); //armazenar em a

    //esvaziar o restante
    b = -1;
    c = -1;
    d = -1;
    e = -1;

    printf("FILA INICIAL:\t|%d|%d|%d|%d|%d|\n", a,b,c,d,e);

    filaVazia = 0;   //Sabemos que a fila não está vazia aqui, lembrando que 0 é FALSO

    while (filaVazia == 0)
    {
        atendido = a;
        a=b; b=c; c=d; d=e; e=-1;

        printf("Atendido: %d\n", atendido);
        printf("FILA DEPOIS:\t|%d|%d|%d|%d|%d|\n", a,b,c,d,e);

        //printf("Testando a anotacao dos primos\n");
        int aux = ehPrimo(atendido);  //se for 1 é primo se for 0 não é
        if (aux == 1)
        {
            if (incompleto)
            {
                printf("%d eh Primo, MAS CUIDADO, pulamos alguns numeros");
            }
            else
            {
                printf("%d eh a solucao!");
            }
            return 0;
        }
        else //atendido não é solução
        {
            //Adicionando os próximos estados na fila
            dir = atendido +2;
            esq = atendido -5;

            //Evitar esses if aninhados HORRIVEIS!!!!1!!!
            if (a == -1)
            {
                a = dir;
                b = esq;
            }
            else //a nao esta vazio
                if (b == -1)
                {
                    b = dir;
                    c = esq;
                }
                else  //do b para tras nao esta vazio
                    if (c == -1)
                    {
                        c = dir;
                        d = esq;
                    }
                else  //do c para tras nao esta vazio
                    if (d == -1)
                    {
                        d = dir;
                        e = esq;
                    }
                else   //do d para tras nao esta vazio
                    if (e == -1)
                    {
                        e = dir;
                        incompleto = 1; //lembrando programa de que um valor nao entrou na fila
                    }
                else
                    {
                        incompleto = 1; //lembrando programa de que um valor nao entrou na fila
                    }




        } // fim atendido nao eh solucao

        printf("\nFILA(%d):\t|%d|%d|%d|%d|%d|\n", incompleto, a,b,c,d,e);

        if (a == -1) //Se a fila estiver vazia anotar pra parar o while
        {
            filaVazia=1;
        }
    }

    if (incompleto)
    {
        printf("Não encontramos solução! MAS não pudemos testar todas elas!");
    }
    else
    {
        printf("Não encontramos solução!");
    }


    return 0;
}