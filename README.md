# Trabalho de Aquecimento

## Introdução

Neste trabalho, o objetivo é criar um sistema que possibilite a funcionalidade de autocompletar
e oferecer sugestões de palavras aos usuários. Para atingir essa finalidade, adotaremos a
estrutura da árvore binária como base. Além disso iremos discutir 2 possibilidades de otimização. Utilizando uma árvore AVl e implementando uma codificação de Huffman.

### Observações

- O valor de K pode ser alterado dentro do arquivo `main.cpp`.
- Dentro das pasta `dataset` se encontra os arquivo `input.txt` e `stopwords.txt`.
- Os textos onde as palavras serão buscas devem estar dentro da pasta `./textos`.


## Implementação

Para construção do programa foi implementado as seguintes estruturas:

### 1. Árvore Binária Padrão
Uma Árvore Binária é uma estrutura de dados hierárquica que consiste em nós, onde cada nó tem no máximo dois filhos. Além disso todos os nós na subarvore esquerda são menor que o nó pai, de maneira análoga todo os nós da subarvore a direita são maiores que o pai. Esse propriedade da árvore binária é a base para duas aplicações principais, ordenação e busca binária.

O processo de inserção escolhido consiste em buscar em percorrer a árvore recursivamente, indo para a esquerda caso o item seja menor que o nó atual e direita caso o contrário, esse processo terminal a encontrar um nó vazio.

Para o exibir os nós da árvore optamos por implementar o caminhamento em in-ordem. Esse processo consiste em exibir toda a subarvore esquerda de um nó, o valor do próprio nó e a subarvore direita, estritamente nessa ordem. Ao fim, teremos todos os valores em ordem crescente.


### 2. Codificação de Huffman
A implementação da codificação de Huffman se baseia na construção de uma Árvore de Huffman, onde os símbolos mais frequentes em um conjunto de dados são representados por caminhos mais curtos na árvore, enquanto os símbolos menos frequentes têm caminhos mais longos. 

Na implementação, começamos criando uma árvore binária onde cada nó representa um símbolo e sua frequência de ocorrência. Os nós são organizados em uma fila de prioridade onde os nós com menor frequência têm prioridade, esse trabalho optamos por utlizar a estrutura priority_queue para gerenciar nossa fila.

O proximo passo para a construção da Árvore de Huffman envolve a fusão de nós de menor frequência em um novo nó pai, continuando até que tenhamos uma única árvore. 

Para buscar os códigos na ávore percorremos a árvore atribuindo códigos binários aos símbolos com base nos caminhos da raiz até as folhas. Sempre que caminhamo a esquerda adicionamos o digito 0 e ao ir para direito o digito 1.

### 3. Árvore AVL
Uma Árvore AVL é uma estrutura de dados em forma de árvore binária que mantém um equilíbrio automático, garantindo que a altura da subárvore esquerda e direita de qualquer nó não difira em mais do que 1 nível. 

A implementação de uma Árvore AVL requer que cada nó contenha informações sobre seu fator de equilíbrio, que é a diferença entre a altura da subárvore direita e esquerda. Na nossa implementação nomeados essa propriedade de altura.

Quando uma inserção ou remoção é realizada, a árvore é reequilibrada conforme necessário, através de rotações de nós, para garantir que o fator de equilíbrio de cada nó esteja dentro dos limites aceitáveis. 

Existem quatro tipos principais de rotações em uma Árvore AVL.

**Rotação à Direita (Right Rotation - RR)** Essa rotação é aplicada quando a subárvore direita de um nó está mais alta do que a subárvore esquerda, resultando em um fator de equilíbrio igual a -2. A rotação à direita é usada para restaurar o equilíbrio, movendo o nó desequilibrado para a direita.

**Rotação à Esquerda (Left Rotation - LL)** Essa rotação é o oposto da rotação à direita e é aplicada quando a subárvore esquerda de um nó está mais alta do que a subárvore direita, resultando em um fator de equilíbrio igual a 2. A rotação à esquerda é usada para restaurar o equilíbrio, movendo o nó desequilibrado para a esquerda.

**Rotação Dupla à Direita (Double Right Rotation - RL)** Essa rotação é uma combinação de uma rotação à esquerda seguida por uma rotação à direita. Ela é aplicada quando o fator de equilíbrio de um nó está igual a -2 e o fator de equilíbrio de seu filho esquerdo está igual a 1. A rotação dupla à direita é usada para restaurar o equilíbrio.

**Rotação Dupla à Esquerda (Double Left Rotation - LR)** Essa rotação é o oposto da rotação dupla à direita e é aplicada quando o fator de equilíbrio de um nó está igual a 2 e o fator de equilíbrio de seu filho direito está igual a -1. A rotação dupla à esquerda é usada para restaurar o equilíbrio.

## Resultados

### Saída

## Conclusão

## COMPILAÇÃO E EXECUÇÃO
O algoritmo disponibilizado inclui um arquivo Makefile que facilita o processo de compilação e execução. Abaixo estão as diretrizes para compilar e executar o programa:
| Comando                | Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
| `make clean`          | Remove os arquivos gerados na última compilação, incluindo os arquivos na pasta "build".       |
| `make`                | Compila o programa usando o compilador `gcc` e coloca o resultado na pasta "build".             |
| `make run`            | Executa o programa compilado na pasta "build".                                                   |

## Contatos
<div style="display: inline-block;">
<a href="https://t.me/vini_apereira">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>
<a href="https://www.linkedin.com/in/vinicius-alves-pereira-913254236/">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>
</div>
<p> </p>
<a style="color:black" href="mailto:vinicius.apereira04@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>vinicius.apereira04@gmail.com</i>
</a>
