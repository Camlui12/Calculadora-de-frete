#include <stdio.h>
#include <string.h>
#include <time.h>

void ler_pedido(int *produto, int *regiao);
float calcular_valorFrete(int produto, int regiao, int *data_entrega);
float valorcompra_Total(float valor_Frete, int produto, float *valor_Produto);
void data_hora(struct tm *info);
void imprimir_datahora(struct tm *info);

int main(){
    struct tm info;
    int produto, regiao, codigo_produto, data_entrega;
    float valor_Frete, valor_Total, valor_Produto;
    ler_pedido(&produto, &regiao);
    valor_Frete = calcular_valorFrete(produto, regiao, &data_entrega);
    valor_Total = valorcompra_Total(valor_Frete, produto, &valor_Produto);
    data_hora(&info);
    printf("\tResumo da compra\n");
    imprimir_datahora(&info);
    switch(produto){
        case 1:
            codigo_produto = 001;
            break;
        case 2:
            codigo_produto = 002;
            break;
        case 3:
            codigo_produto = 003;
            break;
    }
    printf("Codigo do produto: %d\n", codigo_produto);
    printf("Valor do produto: R$%.2f\n", valor_Produto);
    printf("Valor do Frete: R$%.2f\n", valor_Frete);
    printf("Valor total da compra: R$%.2f\n", valor_Total);
    printf("Data prevista para entrega: %d dias uteis\n", data_entrega);

}

void ler_pedido(int *produto, int *regiao){
    printf("Ola, Bem-Vindo a TechVortex. O que deseja comprar?\n 1 - Computador\n 2 - Mouse\n 3 - Teclado\n");
    scanf("%d", produto);

    printf("Qual a regiao que voce reside?\n 1 - Sul\n 2 - Sudeste\n 3 - Norte\n 4 - Nordeste\n");
    scanf("%d", regiao);

}

float calcular_valorFrete(int produto, int regiao, int *data_entrega){
    float valor_Frete;
    if(produto == 1){
        switch(regiao){
            case 1:
                valor_Frete = 50.0;
                break;
            case 2:
                valor_Frete = 45.0;
                break;
            case 3:
                valor_Frete = 55.0;
                break;
            case 4:
                valor_Frete = 60.0;
                break;
        }
        switch(regiao){
            case 1:
                *data_entrega = 4;
                break;
            case 2:
                *data_entrega = 2;
                break;
            case 3:
                *data_entrega = 5;
                break;
            case 4:
                *data_entrega = 8;
                break;
        }
        return valor_Frete;
    }else{
        switch(regiao){
            case 1:
                valor_Frete = 30.0;
                break;
            case 2:
                valor_Frete = 25.0;
                break;
            case 3:
                valor_Frete = 35.0;
                break;
            case 4:
                valor_Frete = 40.0;
                break;
        }
        switch(regiao){
            case 1:
                *data_entrega = 4;
                break;
            case 2:
                *data_entrega = 2;
                break;
            case 3:
                *data_entrega = 5;
                break;
            case 4:
                *data_entrega = 8;
                break;
        }
        return valor_Frete;
    }
}

float valorcompra_Total(float valor_Frete, int produto, float *valor_Produto){
    float valor_Total;
    switch(produto){
        case 1:
            *valor_Produto = 6127.99;
            break;
        case 2:
            *valor_Produto = 412.99;
            break;
        case 3:
            *valor_Produto = 1721.99;
            break;
    }
    valor_Total = valor_Frete + *valor_Produto;
    return valor_Total;
}

void data_hora(struct tm *info){
    time_t t;
    time(&t);
    *info = *localtime(&t);
}

void imprimir_datahora(struct tm *info){
    printf("Data e hora da compra: %02d/%02d/%04d %02d:%02d:%02d\n",
        info->tm_mday, info->tm_mon + 1, info->tm_year + 1900,
        info->tm_hour, info->tm_min, info->tm_sec);
}
