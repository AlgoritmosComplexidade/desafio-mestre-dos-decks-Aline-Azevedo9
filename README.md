ALGORITMOS DE ORDENAÇÃO AVANÇADOS - Desafio Mestre dos Decks 🃏⚔️
Boas-vindas, estrategista! No reino de Algorithimia, a glória é alcançada através de épicos duelos de cartas. No entanto, uma coleção desorganizada é o caminho mais rápido para a derrota.

Sua missão neste desafio é criar a sua própria "caixa de ferramentas do estrategista" em linguagem C. Você deverá implementar algoritmos de ordenação para organizar suas cartas mágicas, partindo de métodos elementares até chegar aos poderosos algoritmos avançados utilizados em cenários reais da computação.

O desafio está dividido em três níveis: Novato, Aventureiro e Mestre. Cada nível exige que você lide com um volume maior de cartas e lógicas de ordenação mais complexas. Escolha o seu caminho!

🚨 Atenção:
O nível Novato é o nosso ponto de partida. Nele, utilizaremos a tática elementar da inserção para organizar uma pequena mão de cartas, focando na estabilidade e na simplicidade da lógica.

🎮 Nível Novato: A Tática da Inserção
Você está em seu primeiro duelo oficial! Você saca sua mão inicial, mas as cartas estão em completa desordem. Para planejar sua jogada, você precisa organizá-las rapidamente pelo custo de energia.

🚩 Objetivo:
Ordenar uma mão de 7 cartas com base no atributo Energia (ordem crescente).
⚙️ Funcionalidades do Sistema:
Estrutura de Dados: Utilizar a struct Carta contendo: id, nome, ataque, defesa, energia e raridade.
Algoritmo: Implementar o algoritmo Insertion Sort. O vetor de 7 cartas já está pré-definido no código.
Saída: O sistema deverá exibir a mão de cartas original (desordenada), aplicar a ordenação e exibir a mão organizada, finalizando com a mensagem: "Mão organizada! Pronto para a batalha!".
🛡️ Nível Aventureiro: Saltando para a Eficiência
Sua fama cresceu e você foi convidado para o primeiro grande torneio! Agora, organizar a mão não basta; você precisa otimizar o seu deck inteiro (40 cartas). O Insertion Sort seria lento aqui, então você usará uma evolução sua: tática dos saltos.

🆕 Diferenças em relação ao Nível Novato:
Volume de Dados: O vetor passa a conter 40 cartas (o deck do torneio).
Critério de Ordenação: As cartas devem ser ordenadas pelo Poder de Ataque, em ordem decrescente (da maior para a menor).
Algoritmo: Substituir o Insertion Sort pelo Shell Sort.
Dica: Utilize a sequência de intervalos (gaps) de Knuth para máxima eficiência.
📥 Saída de Dados:
Imprimir o deck original, o deck organizado e a mensagem final: "Deck otimizado e pronto para o torneio!".
🏆 Nível Mestre: A Ordenação Multicritério
Você atingiu o cargo máximo: guardião do "Grande Registro da Arena". Um decreto real exige que todo o catálogo de cartas seja ordenado para uma exibição pública, e as regras são estritas, exigindo o domínio de algoritmos avançados e critérios de desempate.

🆕 Diferenças em relação ao Nível Aventureiro:
Múltiplos Critérios: A ordenação não olha apenas para um número. Você deverá ordenar seguindo uma hierarquia:
Critério Primário: Ordenar por Raridade em ordem decrescente (Ex: 4 > 3 > 2 > 1).
Critério Secundário (Desempate): Se a raridade for igual, ordenar por Nome em ordem alfabética crescente.
Algoritmo: Implementar o Quick Sort, criando uma função de comparação customizada e chamando-a na etapa de particionamento.
📥 Saída de Dados:
Imprimir o Grande Registro antes da ordenação, depois da ordenação (comprovando os empates resolvidos pelo nome) e a mensagem final: "O grande registro da arena foi restaurado!".
💡 Boas Práticas: A modularidade é a arma de um programador de elite! Crie funções separadas para as lógicas de ordenação e comente seu código explicando o raciocínio por trás das trocas, gaps e particionamentos.

Que os algoritmos estejam ao seu favor. Boa sorte! 🚀
