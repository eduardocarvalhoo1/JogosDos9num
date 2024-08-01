#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void abertura() { // Abertura do jogo
    char iniciar;
    // Desenho da abertura do jogo
    printf("       _ \n");
    printf("   ,'" "`.  ,  ---  {Bem vindo ao jogo dos nove números! \n");
    printf(" /        \\_       Pressione ENTER para começar!}\n");
    printf("'-.( . . ).-'\n");
    printf("    \\(_)/ \n");
    printf("     )o(\n");
    printf("     ''' ");
    printf("\n");
    scanf("%c", &iniciar);
}

int jogarnovamente() { // Pergunta se o usuario deseja jogar novamente
    int opcao;  // Opção do usuário
    
    do {
        printf("\nDeseja jogar novamente? Digite 1 para sim ou 0 para não: ");
        scanf("%d", &opcao);
        if (opcao > 1 || opcao < 0) {
            printf("\nNúmero da opção incorreto.\n"); // Apresenta a mensagem de erro
        }
    } while (opcao > 1 || opcao < 0); // Repete enquanto o usuário digitar um número inválido
    
    return opcao; // Retorna a opção do usuário
}

void rodada() {
    // Declaração de variáveis
    int dado1 = 0, dado2 = 0;
    int jogador = 1;
    int cobertos[4] = { 0, 0, 0, 0}; 
    int ganhou = 0; // Se ganhou = 1 um dos jogadores ganhou.
    int soma = 0; 
    int q;  // Variavel que recebe quantos numeros o jogador vai cobrir
    char tabuleiro [] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    while(ganhou == 0) { // Enquanto ninguém ganhar o loop continua
        // Exibe o tabuleiro mantendo os numeros que foram cobertos
        if(jogador == 1) {
            printf("\nOs seguintes números estão descobertos: ");
            for(int i = 0; i < 9; i++) {
                if(cobertos[0] == tabuleiro[i] || cobertos[1] == tabuleiro[i] || cobertos[2] == tabuleiro[i] || cobertos[3] == tabuleiro[i]) {
                    tabuleiro[i] = 0;
                    if(tabuleiro[i] == 0) { // Cobre os valores
                        printf("O "); 
                    }
                } 
                else {
                    printf("%d ", tabuleiro[i]);
                }
            }
            printf("\n"); // Deixa uma linha em branco
            // Joga dos dados
            // Atribui as variaveis dados um numero aleatorio de 1 até 6
                srand(time(NULL));
                dado1 = rand() % 6 + 1; 
                dado2 = rand() % 6 + 1;
                
            printf("\nResultado dos dados: %d e %d\n", dado1, dado2); // Exibe o resulado dos dados
            printf("\n");
            
            while(jogador == 1) { // Enquanto for a vez do jogador 1 o loop continua
                printf("Quantos números serão cobertos (1 - 4)? Jogador 1: ");
                scanf("%d", &q);
                
                if (q > 4) { // Se o usuário digitar um valor maior que 4 apresenta a mensagem de erro
                    printf("Erro! Você não pode cobrir mais que 4 números. Informe a quantidade novamente.\n");
                } 
                else if (q < 0) { // Se o usuário digitar um valor negativo apresenta a mensagem de erro
                    printf("Erro! O número digitado é negativo. Informe a quantidade novamente.\n");
                } 
                else if (q == 0) { // Se o usuário nao cobrir nenhum número apresenta a mensagem de Fim de jogo
                    printf("Fim de jogo!! O jogador 1 não conseguiu cobrir nenhum número!\n");
                    ganhou = 1; // para o loop
                    jogador = 2; // Passa para o jogador 2
                } 
                else { // Se não tiver nenhum erro ou ninguém ganhar o jogo continua
                    soma = 0; // Reinicializa a soma para cada jogada
                    // Armazena as variaveis no vetor
                    for (int i = 0; i < q; i++) { 
                        printf("Qual o %dº número? Jogador 1: ", i + 1);
                        scanf("%d", &cobertos[i]);
                        soma = soma + cobertos[i];
                        
                        // Verifica se foi digitado 2 numeros iguais
                        if (i > 0 && cobertos[i - 1] == cobertos[i]) {
                            printf("Erro! Número repetido. Informe os números novamente.\n");
                            i = q + 1; // Para o loop
                            jogador = 1; // Mantém a vez no jogador 1
                            // Limpa os cobertos
                            cobertos [0] = 0;
                            cobertos [1] = 0;
                            cobertos [2] = 0;
                            cobertos [3] = 0;
                        }
                    } 
                    if (soma != dado1 + dado2) { // Se a soma dos numeros for diferente da soma dos dados exibe a mensagem de erro
                        printf("Erro! A soma dos números não e igual a soma dos dados. Informe os números novamente.\n");
                        jogador = 1;
                    } 
                    else if (soma == dado1 + dado2) { // Se a soma estiver correta
                        jogador = 2; // Passa para vez do jogador 2
                    }
                }
            }
        } 
        // Jogador 2
        else if(jogador == 2) {
            // Exibe o tabuleiro mantendo os numeros que foram cobertos
            printf("\nOs seguintes números estão descobertos: ");
            for(int i = 0; i < 9; i++) {
                if(cobertos[0] == tabuleiro[i] || cobertos[1] == tabuleiro[i] || cobertos[2] == tabuleiro[i] || cobertos[3] == tabuleiro[i]) {
                    tabuleiro[i] = 0;
                    if(tabuleiro[i] == 0) { // Cobre os numeros
                        printf("O ");
                    }
                } 
                else {
                    tabuleiro[i] = i + 1;
                    printf("%d ", tabuleiro[i]);
                }
            }
            printf("\n"); // Deixa uma linha em branco
            
            // Joga os dados
            srand(time(NULL));
            dado1 = rand() % 6 + 1; 
            dado2 = rand() % 6 + 1;
            printf("\nResultado dos dados: %d e %d\n", dado1, dado2);
            printf("\n");
            
            while(jogador == 2) { // Enquanto jogador = 2 continua o loop
                printf("Quantos números serão cobertos (1 - 4)? Jogador 2: ");
                scanf("%d", &q);
                
                if (q > 4) { // Se o usuário digitar um valor maior que 4 apresenta a mensagem de erro
                    printf("Erro! Você não pode cobrir mais que 4 números. Informe a quantidade novamente.\n");
                } 
                else if (q < 0) { // Se o usuário digitar um valor negativo apresenta a mensagem de erro
                    printf("Erro! O número digitado é negativo. Informe a quantidade novamente.\n");
                } 
                else if (q == 0) { // Se o jogador não conseguir cobrir nenhum numero ele perde
                    printf("Fim de jogo!! O jogador 2 não conseguiu cobrir nenhum número!\n");
                    ganhou = 1; // Para o loop
                    jogador = 1;
                } 
                else {
                    soma = 0; // Reinicializa a soma para cada jogada
                    for (int i = 0; i < q; i++) { 
                        printf("Qual o %do número? Jogador 2: ", i + 1);
                        scanf("%d", &cobertos[i]);
                        soma = soma + cobertos[i];
                        // Verifica se foi digitado 2 numeros iguais
                        if (i > 0 && cobertos[i - 1] == cobertos[i]) {
                            printf("Erro! Número repetido. Informe os números novamente.\n");
                            i = q + 1; // Para o loop
                            jogador = 2; // Mantem a vez no jogador 2
                            // Limpa o tabuleiro
                            cobertos [0] = 0;
                            cobertos [1] = 0;
                            cobertos [2] = 0;
                            cobertos [3] = 0;
                        }
                    } 
                    if (soma != dado1 + dado2) { // Se a soma dos numeros for diferente da soma dos dados exibe a mensagem de erro
                        printf("Erro! A soma dos números não e igual a soma dos dados. Informe os números novamente.\n");
                        jogador = 2; // Mantem a vez no jogador 2
                    } 
                    else if (soma == dado1 + dado2) {
                        jogador = 1; // Passa a vez para o jogador 1
                    }
                }
            }
        }
    }
}

int main() {
    
    int op = 0; // Opção do jogador

    abertura(); // Chama o procedimento de abertura do jogo

    do {
        rodada(); // Chama o procedimento com toda a logica do jogo
        op = jogarnovamente(); // Obtém a opção do usuário
    } while (op == 1); // Repete enquanto o usuário digitar 1 para continuar jogando

    return 0;
}




