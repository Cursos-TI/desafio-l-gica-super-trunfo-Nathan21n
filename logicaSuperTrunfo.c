#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países

int main() {

  // Área para definição das variáveis para armazenar as propriedades das cidades
  char estado1[3], estado2[3];  // armazena a letra do estado 
  char codigo1[5], codigo2[5];  // letra do estado seguida de um númerp de 1 a 4 (ex: A01, B03)
  char cidade1[30], cidade2[30];  // nome da cidade
  unsigned long int populacao1, populacao2;  // Nº de habitantes
  float area1, area2;  // área da cidade em Km²
  float pib1, pib2;  // Produto intenro bruto
  int pontos_turisticos1, pontos_turisticos2;  // Nº de pontos turísticos
  float densidade_populacional1, densidade_populacional2 ;// vai receber o valor da densidade populacional
  float inverso_densidade1, inverso_densidade2; // usado para calcular o inverso da densidade populacional
  float per_capita1, per_capita2; // vai receber o PIB per capita
  float super_poder1, super_poder2; /* Para cada carta, calcule o "Super Poder" somando 
  todos os atributos numéricos (população, área, PIB, número de pontos turísticos, PIB per
  capita e o inverso da densidade populacional – quanto menor a densidade, maior o "poder").*/
  int escolha1, escolha2; // vai receber o a opção que o jogador deseja comparar
  int resposta;
  float atributoA1, atributoB1, atributoA2, atributoB2; // vai guardar os valores a serem somados 
  float somaAtributos1, somaAtributos2; // vai somar os valores escolhidos pelo jogados
  //************************ Área para entrada de dados ************************//

  // Entrada de dados da carta 1

  printf("------------------------------------------------\n");
  printf("                  DADOS CARTA 1                 \n");
  printf("------------------------------------------------\n");

  printf("\nDigite a letra do estado (entre A e H): \n");
  scanf("%s", estado1); 

  printf("Digite o código da carta: \n");
  scanf("%s", codigo1); 

  getchar(); // consome o '\n' deixado pelo scanf

  printf("Nome da cidade: \n");
  fgets(cidade1, sizeof(cidade1), stdin); // permite armazenar nomes compostos
  cidade1[strcspn(cidade1, "\n")] = '\0'; // remove o '\n'

  printf("Digite a população da cidade: \n");
  scanf("%lu", &populacao1);

  printf("Digite a área (km²) da cidade: \n");
  scanf("%f", &area1);
    
  printf("Digite o PIB anual da cidade: \n");
  scanf("%f", &pib1);

  printf("Digite o número de pontos turísticos da cidade: \n");
  scanf("%d", &pontos_turisticos1);

  densidade_populacional1 = (float) populacao1 / area1; // calcula a densidade

  per_capita1 = (pib1 * 1000000000) / (float) populacao1; // calcula o PIB per capita

  inverso_densidade1 = 1.0 / densidade_populacional1;

  super_poder1 = (float) populacao1 + area1 + pib1 + (float) pontos_turisticos1 + per_capita1 + inverso_densidade1;

  // Entrada de dados da carta 2

  printf("\n");
  printf("------------------------------------------------\n");
  printf("                  DADOS CARTA 2                 \n");
  printf("------------------------------------------------\n");

  printf("\nDigite a letra do estado (entre A e H): \n");
  scanf("%s", estado2);

  printf("Digite o código da carta: \n");
  scanf("%s", codigo2);

  getchar(); 
  printf("Nome da cidade: \n");
  fgets(cidade2, sizeof(cidade2), stdin); 
  cidade2[strcspn(cidade2, "\n")] = '\0'; 

  printf("Digite a população da cidade: \n");
  scanf("%lu", &populacao2);

  printf("Digite a área (km²) da cidade: \n");
  scanf("%f", &area2);
    
  printf("Digite o PIB anual da cidade: \n");
  scanf("%f", &pib2);

  printf("Digite o número de pontos turísticos da cidade: \n");
  scanf("%d", &pontos_turisticos2);

  densidade_populacional2 = (float) populacao2 / area2;

  per_capita2 = (pib2 * 1000000000) / (float) populacao2;

  inverso_densidade2 = 1.0 / densidade_populacional2;

  super_poder2 = (float) populacao2 + area2 + pib2 + (float) pontos_turisticos2 + per_capita2 + inverso_densidade2;

  // ************************ Área para escolhe os atributos comparados ************************ //

  printf("------------------------------------------------\n");
  printf("             COMPARANDO ATRIBUTOS               \n");
  printf("------------------------------------------------\n");

  // Comparação do atributo população

  printf("\nESCOLHA O 1º ATRIBUTO QUE DESEJA COMPARAR: ");
  printf("\n\n1 - População");
  printf("\n2 - Área");
  printf("\n3 - PIB");
  printf("\n4 - Número de pontos turísticos");
  printf("\n5 - Densidade populacional");
  printf("\n6 - PIB Per Capita");
  printf("\n7 - Super poder\n");

  printf("\nDigite sua escolha: ");
  scanf("%d", &escolha1); // recebe o atributo que vai ser comparado

  
  printf("\nESCOLHA O 2º ATRIBUTO QUE DESEJA COMPARAR: ");
  printf("\n\n1 - População");
  printf("\n2 - Área");
  printf("\n3 - PIB");
  printf("\n4 - Número de pontos turísticos");
  printf("\n5 - Densidade populacional");
  printf("\n6 - PIB Per Capita");
  printf("\n7 - Super poder\n");

  printf("\nDigite sua escolha: ");
  scanf("%d", &escolha2); // recebe o atributo que vai ser comparado
  printf("\n------------------------------------------------");

  if (escolha1 == escolha2) { 
      printf("\nOS ATRIBUTOS COMPARADOS NÃO PODEM SER IGUAIS!");
      printf("\n------------------------------------------------");
      printf("\nDigite o 1º atributo a ser comparado: ");
      scanf("%d", &escolha1);
      printf("Digite o 2º atributo a ser comparado: ");
      scanf("%d", &escolha2);
      printf("\n------------------------------------------------");
  }

  // ************************ Área para saída dos atributos comparados (escolha 1) ************************ //

  switch (escolha1) {
    case 1:
        if (populacao1 > populacao2) {
            printf("\nNúmero de habitantes de %s: %lu", cidade1, populacao1);
            printf("\nNúmero de habitantes de %s: %lu", cidade2, populacao2);
            printf("\n%lu > %lu \n%s VENCEU!", populacao1, populacao2, cidade1);
        } else if (populacao2 > populacao1) {
            printf("\nNúmero de habitantes de %s: %lu", cidade1, populacao1);
            printf("\nNúmero de habitantes de %s: %lu", cidade2, populacao2);
            printf("\n%lu < %lu \n%s VENCEU!", populacao1, populacao2, cidade2);            
        } else {
            printf("\nNúmero de habitantes de %s: %lu", cidade1, populacao1);
            printf("\nNúmero de habitantes de %s: %lu", cidade2, populacao2);
            printf("\n%lu = %lu \nEMPATOU!", populacao1, populacao2);
        }

        atributoA1 = (float) populacao1;
        atributoA2 = (float) populacao2;

        break;
    case 2:
        if (area1 > area2) {
            printf("\nÁrea de %s: %.2f km²", cidade1, area1);
            printf("\nÁrea de %s: %.2f km²", cidade2, area2);
            printf("\n%.2f > %.2f \n%s VENCEU!", area1, area2, cidade1);
        } else if (area2 > area1) {
            printf("\nÁrea de %s: %.2f km²", cidade1, area1);
            printf("\nÁrea de %s: %.2f km²", cidade2, area2);
            printf("\n%.2f < %.2f \n%s VENCEU!", area1, area2, cidade2);           
        } else {
            printf("\nÁrea de %s: %.2f km²", cidade1, area1);
            printf("\nÁrea de %s: %.2f km²", cidade2, area2);
            printf("\n%.2f = %.2f \nEMPATOU!", area1, area2); 
        }

        atributoA1 = area1;
        atributoA2 = area2;

        break;
    case 3:
        if (pib1 > pib2) {
            printf("\nPIB de %s: %.2f", cidade1, pib1);
            printf("\nPIB de %s: %.2f", cidade2, pib2);
            printf("\n%.2f > %.2f \n%s VENCEU!", pib1, pib2, cidade1);
        } else if (pib2 > pib1) {
            printf("\nPIB de %s: %.2f", cidade1, pib1);
            printf("\nPIB de %s: %.2f", cidade2, pib2);
            printf("\n%.2f < %.2f \n%s VENCEU!", pib1, pib2, cidade2);           
        } else {
            printf("\nPIB de %s: %.2f", cidade1, pib1);
            printf("\nPIB de %s: %.2f", cidade2, pib2);
            printf("\n%.2f = %.2f \nEMPATOU!", pib1, pib2);
        } 

        atributoA1 = pib1 * 1000000000;
        atributoA2 = pib2 * 1000000000;

        break;
    case 4:
        if (pontos_turisticos1 > pontos_turisticos2) {
            printf("\nNúmero de pontos turísticos de %s: %d", cidade1, pontos_turisticos1);
            printf("\nNúmero de pontos turísticos de %s: %d", cidade2, pontos_turisticos2);
            printf("\n%d > %d \n%s VENCEU!", pontos_turisticos1, pontos_turisticos2, cidade1);
        } else if (pontos_turisticos2 > pontos_turisticos1) {
            printf("\nNúmero de pontos turísticos de %s: %d", cidade1, pontos_turisticos1);
            printf("\nNúmero de pontos turísticos de %s: %d", cidade2, pontos_turisticos2);
            printf("\n%d < %d \n%s VENCEU!", pontos_turisticos1, pontos_turisticos2, cidade2);           
        } else {
            printf("\nNúmero de pontos turísticos de %s: %d", cidade1, pontos_turisticos1);
            printf("\nNúmero de pontos turísticos de %s: %d", cidade2, pontos_turisticos2);
            printf("\n%d = %d \nEMPATOU!", pontos_turisticos1, pontos_turisticos2); 
        }

        atributoA1 = (float) pontos_turisticos1;
        atributoA2 = (float) pontos_turisticos2;

        break;
    case 5:
        if (densidade_populacional1 > densidade_populacional2) {
            printf("\nDensidade populacional de %s: %.2f hab/km²", cidade1, densidade_populacional1);
            printf("\nDensidade populacional de %s: %.2f hab/km²", cidade2, densidade_populacional2);
            printf("\n%.2f > %.2f \n%s VENCEU!", densidade_populacional1, densidade_populacional2, cidade2);
        } else if (densidade_populacional2 > densidade_populacional1) {
            printf("\nDensidade populacional de %s: %.2f hab/km²", cidade1, densidade_populacional1);
            printf("\nDensidade populacional de %s: %.2f hab/km²", cidade2, densidade_populacional2);
            printf("\n%.2f < %.2f \n%s VENCEU!", densidade_populacional1, densidade_populacional2, cidade1);           
        } else {
            printf("\nDensidade populacional de %s: %.2f hab/km²", cidade1, densidade_populacional1);
            printf("\nDensidade populacional de %s: %.2f hab/km²", cidade2, densidade_populacional2);
            printf("\n%.2f = %.2f \nEMPATOU!", densidade_populacional1, densidade_populacional2); 
        }

        atributoA1 = densidade_populacional1;
        atributoA2 = densidade_populacional2;

        break;
    case 6:
        if (per_capita1 > per_capita2) {
            printf("\nPIB Per Capita de %s: R$ %.2f", cidade1, per_capita1);
            printf("\nPIB Per Capita de %s: R$ %.2f", cidade2, per_capita2);
            printf("\n%.2f > %.2f \n%s VENCEU!", per_capita1, per_capita2, cidade1);
        } else if (per_capita2 > per_capita1) {
            printf("\nPIB Per Capita de %s: R$ %.2f", cidade1, per_capita1);
            printf("\nPIB Per Capita de %s: R$ %.2f", cidade2, per_capita2);
            printf("\n%.2f < %.2f \n%s VENCEU!", per_capita1, per_capita2, cidade2);           
        } else {
            printf("\nPIB Per Capita de %s: R$ %.2f", cidade1, per_capita1);
            printf("\nPIB Per Capita de %s: R$ %.2f", cidade2, per_capita2);
            printf("\n%.2f = %.2f \nEMPATOU!", per_capita1, per_capita2); 
        }

        atributoA1 = per_capita1;
        atributoA2 = per_capita2;

        break;
    case 7:
        if (super_poder1 > super_poder2) {
            printf("\nSuper Poder de %s: %.2f", cidade1, super_poder1);
            printf("\nSuper Poder de %s: %.2f", cidade2, super_poder2);
            printf("\n%.2f > %.2f \n%s VENCEU!", super_poder1, super_poder2, cidade1);
        } else if (super_poder2 > super_poder1) {
            printf("\nSuper Poder de %s: %.2f", cidade1, super_poder1);
            printf("\nSuper Poder de %s: %.2f", cidade2, super_poder2);
            printf("\n%.2f < %.2f \n%s VENCEU!", super_poder1, super_poder2, cidade2);           
        } else {
            printf("\nSuper Poder de %s: %.2f", cidade1, super_poder1);
            printf("\nSuper Poder de %s: %.2f", cidade2, super_poder2);
            printf("\n%.2f = %.2f \nEMPATOU!", super_poder1, super_poder2); 
        }

        atributoA1 = super_poder1;
        atributoA2 = super_poder2;

        break;
    default:
        printf("\n                 VALOR INVÁLIDO!");
  }

  // ************************ Área para saída dos atributos comparados (escolha 2) ************************ //

  printf("\n------------------------------------------------");
  switch (escolha2) {
    case 1:
        if (populacao1 > populacao2) {
            printf("\nNúmero de habitantes de %s: %lu", cidade1, populacao1);
            printf("\nNúmero de habitantes de %s: %lu", cidade2, populacao2);
            printf("\n%lu > %lu \n%s VENCEU!", populacao1, populacao2, cidade1);
        } else if (populacao2 > populacao1) {
            printf("\nNúmero de habitantes de %s: %lu", cidade1, populacao1);
            printf("\nNúmero de habitantes de %s: %lu", cidade2, populacao2);
            printf("\n%lu < %lu \n%s VENCEU!", populacao1, populacao2, cidade2);            
        } else {
            printf("\nNúmero de habitantes de %s: %lu", cidade1, populacao1);
            printf("\nNúmero de habitantes de %s: %lu", cidade2, populacao2);
            printf("\n%lu = %lu \nEMPATOU!", populacao1, populacao2);
        }

        atributoB1 = (float) populacao1;
        atributoB2 = (float) populacao2;

        break;
    case 2:
        if (area1 > area2) {
            printf("\nÁrea de %s: %.2f km²", cidade1, area1);
            printf("\nÁrea de %s: %.2f km²", cidade2, area2);
            printf("\n%.2f > %.2f \n%s VENCEU!", area1, area2, cidade1);
        } else if (area2 > area1) {
            printf("\nÁrea de %s: %.2f km²", cidade1, area1);
            printf("\nÁrea de %s: %.2f km²", cidade2, area2);
            printf("\n%.2f < %.2f \n%s VENCEU!", area1, area2, cidade2);           
        } else {
            printf("\nÁrea de %s: %.2f km²", cidade1, area1);
            printf("\nÁrea de %s: %.2f km²", cidade2, area2);
            printf("\n%.2f = %.2f \nEMPATOU!", area1, area2); 
        }

        atributoB1 = area1;
        atributoB2 = area2;

        break;
    case 3:
        if (pib1 > pib2) {
            printf("\nPIB de %s: %.2f", cidade1, pib1);
            printf("\nPIB de %s: %.2f", cidade2, pib2);
            printf("\n%.2f > %.2f \n%s VENCEU!", pib1, pib2, cidade1);
        } else if (pib2 > pib1) {
            printf("\nPIB de %s: %.2f", cidade1, pib1);
            printf("\nPIB de %s: %.2f", cidade2, pib2);
            printf("\n%.2f < %.2f \n%s VENCEU!", pib1, pib2, cidade2);           
        } else {
            printf("\nPIB de %s: %.2f", cidade1, pib1);
            printf("\nPIB de %s: %.2f", cidade2, pib2);
            printf("\n%.2f = %.2f \nEMPATOU!", pib1, pib2);
        } 

        atributoB1 = pib1 * 1000000000;
        atributoB2 = pib2 * 1000000000;

        break;
    case 4:
        if (pontos_turisticos1 > pontos_turisticos2) {
            printf("\nNúmero de pontos turísticos de %s: %d", cidade1, pontos_turisticos1);
            printf("\nNúmero de pontos turísticos de %s: %d", cidade2, pontos_turisticos2);
            printf("\n%d > %d \n%s VENCEU!", pontos_turisticos1, pontos_turisticos2, cidade1);
        } else if (pontos_turisticos2 > pontos_turisticos1) {
            printf("\nNúmero de pontos turísticos de %s: %d", cidade1, pontos_turisticos1);
            printf("\nNúmero de pontos turísticos de %s: %d", cidade2, pontos_turisticos2);
            printf("\n%d < %d \n%s VENCEU!", pontos_turisticos1, pontos_turisticos2, cidade2);           
        } else {
            printf("\nNúmero de pontos turísticos de %s: %d", cidade1, pontos_turisticos1);
            printf("\nNúmero de pontos turísticos de %s: %d", cidade2, pontos_turisticos2);
            printf("\n%d = %d \nEMPATOU!", pontos_turisticos1, pontos_turisticos2); 
        }

        atributoB1 = (float) pontos_turisticos1;
        atributoB2 = (float) pontos_turisticos2;

        break;
    case 5:
        if (densidade_populacional1 > densidade_populacional2) {
            printf("\nDensidade populacional de %s: %.2f hab/km²", cidade1, densidade_populacional1);
            printf("\nDensidade populacional de %s: %.2f hab/km²", cidade2, densidade_populacional2);
            printf("\n%.2f > %.2f \n%s VENCEU!", densidade_populacional1, densidade_populacional2, cidade2);
        } else if (densidade_populacional2 > densidade_populacional1) {
            printf("\nDensidade populacional de %s: %.2f hab/km²", cidade1, densidade_populacional1);
            printf("\nDensidade populacional de %s: %.2f hab/km²", cidade2, densidade_populacional2);
            printf("\n%.2f < %.2f \n%s VENCEU!", densidade_populacional1, densidade_populacional2, cidade1);           
        } else {
            printf("\nDensidade populacional de %s: %.2f hab/km²", cidade1, densidade_populacional1);
            printf("\nDensidade populacional de %s: %.2f hab/km²", cidade2, densidade_populacional2);
            printf("\n%.2f = %.2f \nEMPATOU!", densidade_populacional1, densidade_populacional2); 
        }

        atributoB1 = densidade_populacional1;
        atributoB2 = densidade_populacional2;

        break;
    case 6:
        if (per_capita1 > per_capita2) {
            printf("\nPIB Per Capita de %s: R$ %.2f", cidade1, per_capita1);
            printf("\nPIB Per Capita de %s: R$ %.2f", cidade2, per_capita2);
            printf("\n%.2f > %.2f \n%s VENCEU!", per_capita1, per_capita2, cidade1);
        } else if (per_capita2 > per_capita1) {
            printf("\nPIB Per Capita de %s: R$ %.2f", cidade1, per_capita1);
            printf("\nPIB Per Capita de %s: R$ %.2f", cidade2, per_capita2);
            printf("\n%.2f < %.2f \n%s VENCEU!", per_capita1, per_capita2, cidade2);           
        } else {
            printf("\nPIB Per Capita de %s: R$ %.2f", cidade1, per_capita1);
            printf("\nPIB Per Capita de %s: R$ %.2f", cidade2, per_capita2);
            printf("\n%.2f = %.2f \nEMPATOU!", per_capita1, per_capita2); 
        }
         
        atributoB1 = per_capita1;
        atributoB2 = per_capita2;

        break;
    case 7:
        if (super_poder1 > super_poder2) {
            printf("\nSuper Poder de %s: %.2f", cidade1, super_poder1);
            printf("\nSuper Poder de %s: %.2f", cidade2, super_poder2);
            printf("\n%.2f > %.2f \n%s VENCEU!", super_poder1, super_poder2, cidade1);
        } else if (super_poder2 > super_poder1) {
            printf("\nSuper Poder de %s: %.2f", cidade1, super_poder1);
            printf("\nSuper Poder de %s: %.2f", cidade2, super_poder2);
            printf("\n%.2f < %.2f \n%s VENCEU!", super_poder1, super_poder2, cidade2);           
        } else {
            printf("\nSuper Poder de %s: %.2f", cidade1, super_poder1);
            printf("\nSuper Poder de %s: %.2f", cidade2, super_poder2);
            printf("\n%.2f = %.2f \nEMPATOU!", super_poder1, super_poder2); 
        }

        atributoB1 = super_poder1;
        atributoB2 = super_poder2;
        break;
    default:
        printf("\n                 VALOR INVÁLIDO!");
  }

  printf("\n");
  printf("------------------------------------------------\n");

  //************************ Área para exibição da soma dos atributos ************************// 

  // somam os atributos escolhidos
  somaAtributos1 = atributoA1 + atributoB1;
  somaAtributos2 = atributoA2 + atributoB2;

  if (super_poder1 > super_poder2) {
            printf("\nSoma dos atributos de %s: %.2f", cidade1, somaAtributos1);
            printf("\nSoma dos atributos de %s: %.2f", cidade2, somaAtributos2);
            printf("\n%.2f > %.2f \n%s VENCEU!", somaAtributos1, somaAtributos2, cidade1);
  } else if (super_poder2 > super_poder1) {
            printf("\nSoma dos atributos de %s: %.2f", cidade1, somaAtributos1);
            printf("\nSoma dos atributos de %s: %.2f", cidade2, somaAtributos2);
            printf("\n%.2f < %.2f \n%s VENCEU!", somaAtributos1, somaAtributos2, cidade2);           
  } else {
            printf("\nSoma dos atributos de %s: %.2f", cidade1, somaAtributos1);
            printf("\nSoma dos atributos de %s: %.2f", cidade2, somaAtributos2);
            printf("\n%.2f = %.2f \nEMPATOU!", somaAtributos1, somaAtributos2); 
  }
  printf("\n------------------------------------------------\n");


  //************************ Área para exibição dos dados da cidade ************************// 

  // Saída de dados da carta 1

  printf("Deseja ver os dados das cartas? 1(SIM) 2(NÃO): ");
  scanf("%d", &resposta);

  if (resposta == 1) {

    printf("\n");
    printf("------------------------------------------------\n");
    printf("                     CARTA 1                    \n");
    printf("------------------------------------------------\n");

    printf("\nESTADO: %s", estado1);
    printf("\nCÓDIGO DA CARTA: %s", codigo1);
    printf("\nNOME DA CIDADE: %s", cidade1);
    printf("\nPOPULAÇÃO: %lu", populacao1);
    printf("\nÁREA: %.2f km²", area1);
    printf("\nPIB: %.2f bilhões de reais", pib1);
    printf("\nNÚMERO DE PONTOS TURÍSTICOS: %d", pontos_turisticos1);
    printf("\nDENSIDADE POPULACIONAL: %.2f hab/km²", densidade_populacional1);
    printf("\nPIB PER CAPITA: R$ %.2f", per_capita1);
    printf("\nSUPER PODER: %.2f", super_poder1);
    printf("\n\n");

    // Saída de dados da carta 2

    printf("------------------------------------------------\n");
    printf("                     CARTA 2                    \n");
    printf("------------------------------------------------\n");

    printf("\nESTADO: %s", estado2);
    printf("\nCÓDIGO DA CARTA: %s", codigo2);
    printf("\nNOME DA CIDADE: %s", cidade2);
    printf("\nPOPULAÇÃO: %lu", populacao2);
    printf("\nÁREA: %.2f km²", area2);
    printf("\nPIB: %.2f bilhões de reais", pib2);
    printf("\nNÚMERO DE PONTOS TURÍSTICOS: %d", pontos_turisticos2);
    printf("\nDENSIDADE POPULACIONAL: %.2f hab/km²", densidade_populacional2);
    printf("\nPIB PER CAPITA: R$ %.2f", per_capita2);
    printf("\nSUPER PODER: %.2f", super_poder2);
    printf("\n\n");
    printf("------------------------------------------------\n");
  } else {
    printf("------------------------------------------------\n");
    printf("                  FIM DE JOGO!                  \n");
    printf("------------------------------------------------\n");
  }
  return 0;
}
