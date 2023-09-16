# Trabalho de Aquecimento

## Introdução

### Observações

- O programa considerará todos os arquivos dentro da pasta "dataset" como entrada, independentemente do nome. Com exceção do arquivo "stopwords.data", que contém termos a serem ignorados na listagem. Este arquivo não deve ter seu nome alterado.
- O valor de K pode ser alterado dentro do arquivo `main.cpp`.

## Implementação

Para construção do programa foi implementado as seguintes estruturas:

### 1. Árvore Binária Padrão
Selecionará as palavras mais relevantes e relacionadas à pesquisa em cada texto. A relevância de uma palavra corresponde a sua ocorrência e proximidade à palavra buscada.

### 2. Codificação de Huffman
Para otimizar a árvore binária padrão. Será calculado códigos para cada palavra e em seguida serão organizados na
estrutura da árvore com base nesses códigos. 

### 3. Árvore AVL
Implementaremos uma árvore AVL e repetiremos o processo de análise.
Compararemos o tempo médio de processamento entre a construção da estrutura e a
geração de saída em comparação com as abordagens anteriores.

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
