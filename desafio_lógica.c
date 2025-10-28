/**
 * @file super_trunfo_comparacao.c
 * @brief Programa Super Trunfo que cadastra, calcula e compara duas cartas.
 * @details Este programa cadastra duas cartas, calcula seus dados derivados
 * (densidade e PIB per capita) e compara um atributo para declarar um vencedor.
 * Desafio Nível Básico (Foco em if-else).
 */

#include <stdio.h> // Biblioteca padrão para funções de Entrada e Saída (printf, scanf)

int main() {
    // --- DECLARAÇÃO DE VARIÁVEIS ---

    // Variáveis para a Carta 1
    char estado1[3]; // Requisito pedia string, melhor usar 3 (ex: 'S', 'P', '\0')
    char codigo1[5];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1;      // NOVO: Para Densidade Populacional
    float pibPerCapita1;   // NOVO: Para PIB per capita

    // Variáveis para a Carta 2
    char estado2[3];
    char codigo2[5];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;      // NOVO
    float pibPerCapita2;   // NOVO

    // --- ENTRADA DE DADOS - CARTA 1 ---
    printf("--- Cadastro da Primeira Carta ---\n");

    printf("Digite o estado (ex: SP): ");
    scanf("%s", estado1); // Para string (char[])

    printf("Digite o codigo da carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1); // CORREÇÃO: Para ler nomes com espaço

    printf("Digite a populacao da cidade: ");
    scanf("%d", &populacao1);

    printf("Digite a area da cidade (em km2): ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade (em Bilhoes, ex: 50.5): "); // Instrução mais clara
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);
    
    // --- CÁLCULOS - CARTA 1 (NOVO) ---
    // Evitar divisão por zero
    if (area1 > 0) {
        densidade1 = (float)populacao1 / area1;
    } else {
        densidade1 = 0;
    }

    if (populacao1 > 0) {
        // Convertendo PIB (Bilhões) para valor real (ex: 50.5 -> 50,500,000,000)
        pibPerCapita1 = (pib1 * 1000000000.0) / (float)populacao1;
    } else {
        pibPerCapita1 = 0;
    }

    printf("\n");

    // --- ENTRADA DE DADOS - CARTA 2 ---
    printf("--- Cadastro da Segunda Carta ---\n");

    printf("Digite o estado (ex: RJ): ");
    scanf("%s", estado2);

    printf("Digite o codigo da carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2); // CORREÇÃO

    printf("Digite a populacao da cidade: ");
    scanf("%d", &populacao2);

    printf("Digite a area da cidade (em km2): ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade (em Bilhoes, ex: 30.2): ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- CÁLCULOS - CARTA 2 (NOVO) ---
    if (area2 > 0) {
        densidade2 = (float)populacao2 / area2;
    } else {
        densidade2 = 0;
    }

    if (populacao2 > 0) {
        pibPerCapita2 = (pib2 * 1000000000.0) / (float)populacao2;
    } else {
        pibPerCapita2 = 0;
    }

    // --- SAÍDA DE DADOS (Atualizada com novos cálculos) ---
    printf("\n\n--- Cartas Cadastradas ---\n");

    printf("\nCarta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade: %.2f hab/km2\n", densidade1);     // NOVO
    printf("PIB per capita: R$ %.2f\n", pibPerCapita1); // NOVO

    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade: %.2f hab/km2\n", densidade2);     // NOVO
    printf("PIB per capita: R$ %.2f\n", pibPerCapita2); // NOVO

    // --- COMPARAÇÃO DAS CARTAS (LÓGICA DO JOGO - NOVO) ---
    // O desafio pede para escolher UM atributo no código.
    // Vamos usar "População" (MAIOR vence).

    printf("\n\n--- Resultado da Disputa ---\n");
    printf("Atributo Comparado: Populacao\n");
    printf("Carta 1 (%s): %d\n", nomeCidade1, populacao1);
    printf("Carta 2 (%s): %d\n", nomeCidade2, populacao2);

    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } 
    else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } 
    else {
        printf("Resultado: Empate!\n");
    }

    /*
    // --- EXEMPLO DE COMPARAÇÃO 2: Densidade (MENOR vence) ---
    // Para testar, comente o bloco de "População" acima e descomente este aqui.

    printf("\n\n--- Resultado da Disputa ---\n");
    printf("Atributo Comparado: Densidade Populacional (Menor vence!)\n");
    printf("Carta 1 (%s): %.2f hab/km2\n", nomeCidade1, densidade1);
    printf("Carta 2 (%s): %.2f hab/km2\n", nomeCidade2, densidade2);

    if (densidade1 < densidade2) { // Note a lógica invertida: < (menor) vence
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } 
    else if (densidade2 < densidade1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } 
    else {
        printf("Resultado: Empate!\n");
    }
    */

    return 0; // Indica que o programa foi executado com sucesso.
}