#include <stdio.h>
#include <string.h>

// ============================================================================
// ESTRUTURA DE DADOS BASE
// ============================================================================
typedef struct {
    int id;
    char nome[50];
    int ataque;
    int defesa;
    int energia;
    int raridade; // 4: Lendário, 3: Épico, 2: Raro, 1: Comum
} Carta;

// ============================================================================
// FUNÇÃO DE EXIBIÇÃO MODULAR
// ============================================================================
void imprimirRegistro(Carta arr[], int tamanho, const char *mensagem) {
    printf("\n--- %s ---\n", mensagem);
    printf("%-5s | %-25s | %-7s | %-7s | %-7s | %-8s\n", "ID", "NOME", "ATAQUE", "DEFESA", "ENERGIA", "RARIDADE");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%-5d | %-25s | %-7d | %-7d | %-7d | %-8d\n", 
               arr[i].id, arr[i].nome, arr[i].ataque, arr[i].defesa, arr[i].energia, arr[i].raridade);
    }
    printf("-------------------------------------------------------------------------\n");
}

// ============================================================================
// NÍVEL NOVATO: INSERTION SORT (Ordenação por Energia - Crescente)
// ============================================================================
void insertionSort(Carta arr[], int n) {
    for (int i = 1; i < n; i++) {
        Carta key = arr[i];
        int j = i - 1;

        // Move os elementos que são maiores que a chave de energia
        // para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j].energia > key.energia) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// ============================================================================
// NÍVEL AVENTUREIRO: SHELL SORT (Ordenação por Ataque - Decrescente)
// ============================================================================
void shellSort(Carta arr[], int n) {
    int h = 1;
    // Dica aplicada: Geração da sequência de intervalos (gaps) de Knuth
    while (h < n / 3) {
        h = 3 * h + 1;
    }

    while (h >= 1) {
        for (int i = h; i < n; i++) {
            Carta key = arr[i];
            int j = i;

            // Ordenação em ordem decrescente (arr[j - h].ataque < key.ataque)
            while (j >= h && arr[j - h].ataque < key.ataque) {
                arr[j] = arr[j - h];
                j -= h;
            }
            arr[j] = key;
        }
        // Reduz o gap para a próxima iteração
        h /= 3;
    }
}

// ============================================================================
// NÍVEL MESTRE: QUICK SORT (Multicritério: Raridade Decrescente + Nome Crescente)
// ============================================================================
int deveVirAntes(Carta cartaA, Carta cartaB) {
    if (cartaA.raridade != cartaB.raridade) {
        return cartaA.raridade > cartaB.raridade;
    }
    if (strcmp(cartaA.nome, cartaB.nome) < 0) {
        return 1;
    }
    return 0;
}

void trocarCartas(Carta *a, Carta *b) {
    Carta temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(Carta arr[], int baixo, int alto) {
    Carta pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (deveVirAntes(arr[j], pivo)) {
            i++;
            trocarCartas(&arr[i], &arr[j]);
        }
    }
    trocarCartas(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSort(Carta arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

// ============================================================================
// FUNÇÃO PRINCIPAL E EXECUÇÃO DOS TESTES
// ============================================================================
int main() {
    printf("=========================================================================\n");
    printf("               CAIXA DE FERRAMENTAS DO ESTRATEGISTA\n");
    printf("=========================================================================\n\n");

    // ------------------------------------------------------------------------
    // TESTE 1: NÍVEL NOVATO
    // ------------------------------------------------------------------------
    Carta mao_novato[7] = {
        {1, "Goblin Batedor", 1, 1, 3, 1},
        {2, "Elfa Arqueira", 2, 1, 5, 1},
        {3, "Ogro Esmagador", 5, 4, 8, 2},
        {4, "Lobo das Sombras", 3, 2, 2, 1},
        {5, "Clerigo Iluminado", 1, 3, 4, 1},
        {6, "Mago de Gelo", 2, 4, 6, 2},
        {7, "Grifo Veloz", 4, 3, 7, 1}
    };
    
    imprimirRegistro(mao_novato, 7, "NIVEL NOVATO - MAO ORIGINAL (DESORDENADA)");
    insertionSort(mao_novato, 7);
    imprimirRegistro(mao_novato, 7, "NIVEL NOVATO - MAO ORDENADA (POR ENERGIA CRESCENTE)");
    printf("[!] Mao organizada! Pronto para a batalha!\n\n");

    // ------------------------------------------------------------------------
    // TESTE 2: NÍVEL AVENTUREIRO (Vetor simplificado simulando o deck de 40)
    // Nota: Para manter o código limpo, preenchemos uma amostra robusta.
    // ------------------------------------------------------------------------
    Carta deck_aventureiro[40] = {
        {10, "Cavaleiro de Aco", 3, 3, 3, 2}, {11, "Dragao das Cinzas", 7, 7, 8, 3},
        {12, "Minotauro Guerreiro", 5, 6, 5, 2}, {13, "Basilisco Petrificante", 3, 5, 4, 2},
        {14, "Feiticeira Arcana", 4, 2, 5, 3}, {15, "Ciclope Brutal", 7, 5, 6, 2},
        {16, "Guardiao de Pedra", 2, 5, 4, 1}, {17, "Anjo da Furia", 6, 5, 6, 3},
        {18, "Lich King", 10, 10, 10, 4}, {19, "Fenix Imortal", 9, 9, 9, 4},
        // Replicando cartas para simular o volume do torneio (40 cartas no total)
        {20, "Recruta Espadachim", 1, 2, 1, 1}, {21, "Aranha Gigante", 2, 1, 2, 1},
        {22, "Golem de Ferro", 4, 8, 5, 2}, {23, "Assassino Furtivo", 6, 1, 3, 3},
        {24, "Vampiro Nobre", 5, 4, 4, 3}, {25, "Zumbi Rastejante", 1, 1, 1, 1},
        {26, "Esqueleto Guerreiro", 2, 1, 1, 1}, {27, "Elemental da Agua", 4, 5, 4, 2},
        {28, "Elemental da Terra", 3, 6, 4, 2}, {29, "Elemental do Vento", 5, 2, 4, 2},
        {30, "Mestre Cervejeiro", 3, 3, 3, 2}, {31, "Pantera Negra", 4, 2, 3, 2},
        {32, "Urso Pardo", 3, 4, 3, 1}, {33, "Aguia Gigante", 3, 2, 2, 1},
        {34, "Xaman Orc", 2, 3, 4, 2}, {35, "Troll Regenerador", 4, 4, 5, 2},
        {36, "Sereia Encantadora", 1, 2, 3, 2}, {37, "Kraken", 8, 8, 9, 4},
        {38, "Leviata", 9, 7, 8, 4}, {39, "Serpente Marinha", 5, 4, 5, 2},
        {40, "Pirata Fantasma", 3, 2, 2, 2}, {41, "Capitao Amaldicoado", 5, 4, 4, 3},
        {42, "Canhao de Navio", 6, 1, 3, 2}, {43, "Papagaio Falante", 1, 1, 1, 1},
        {44, "Macaco Ladrao", 1, 2, 1, 1}, {45, "Dragao Filhote", 3, 3, 4, 2},
        {46, "Tita de Gelo", 8, 9, 9, 4}, {47, "Demonio Menor", 3, 1, 2, 1},
        {48, "Lorde Demonio", 8, 6, 8, 4}, {49, "Arauto da Destruicao", 7, 7, 7, 3}
    };

    imprimirRegistro(deck_aventureiro, 40, "NIVEL AVENTUREIRO - DECK ORIGINAL (DESORDENADO)");
    shellSort(deck_aventureiro, 40);
    imprimirRegistro(deck_aventureiro, 40, "NIVEL AVENTUREIRO - DECK OTIMIZADO (POR ATAQUE DECRESCENTE)");
    printf("[!] Deck otimizado e pronto para o torneio!\n\n");

    // ------------------------------------------------------------------------
    // TESTE 3: NÍVEL MESTRE
    // ------------------------------------------------------------------------
    Carta grande_registro[20] = {
        {225, "Elemental de Fogo", 6, 2, 5, 2}, {105, "Ogro Esmagador", 5, 4, 5, 2},
        {102, "Elfa Arqueira", 2, 1, 2, 1}, {315, "Paladino da Ordem", 5, 7, 7, 3},
        {201, "Lobo das Sombras", 3, 2, 2, 1}, {401, "Lich King", 10, 10, 10, 4},
        {107, "Anjo da Furia", 6, 5, 6, 3}, {301, "Mago de Gelo", 2, 4, 3, 2},
        {101, "Goblin Batedor", 1, 1, 1, 1}, {205, "Ciclope Brutal", 7, 5, 6, 2},
        {103, "Guardiao de Pedra", 2, 5, 4, 1}, {305, "Hidra de Nove Cabecas", 8, 8, 9, 4},
        {106, "Cavaleiro de Aco", 3, 3, 3, 2}, {210, "Grifo Veloz", 4, 3, 4, 1},
        {104, "Dragao das Cinzas", 7, 7, 8, 3}, {215, "Minotauro Guerreiro", 5, 6, 5, 2},
        {310, "Feiticeira Arcana", 4, 2, 5, 3}, {220, "Basilisco Petrificante", 3, 5, 4, 2},
        {110, "Clerigo Iluminado", 1, 3, 2, 1}, {405, "Fenix Imortal", 9, 9, 9, 4}
    };

    imprimirRegistro(grande_registro, 20, "NIVEL MESTRE - GRANDE REGISTRO ORIGINAL");
    quickSort(grande_registro, 0, 19); // 20 cartas, índice 0 a 19
    imprimirRegistro(grande_registro, 20, "NIVEL MESTRE - GRANDE REGISTRO ORDENADO (RARIDADE/NOME)");
    printf("[!] O grande registro da arena foi restaurado!\n\n");

    return 0;
}