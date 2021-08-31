# EXERCICIO 5
• Faça um programa que armazene a informação de várias
pessoas.

typedef struct{
    char nome[30];
    int idade;
    int altura;
} Pessoa;

• O programa só deve sair quando o usuário disser que não
deseja mais entrar com os dados de outra pessoa.

• Antes de sair o programa deve apresentar, de forma
organizada, os dados de todas as pessoas.

# EXERCICIO 7

1. O programa deve armazenar no máximo 10 pessoas
2. Todas as variáveis que forem usadas no programa deve ser ponteiros. A única exceção é o
item 1 que deve ser uma variável global
Pessoa pessoas[10].
    1. Os ponteiros devem apontar para um buffer chamado pBuffer onde os dados devem ser armazenados. Por exemplo, um contador para um for deve ser um ponteiro para int e o int vai ficar armazenado dentro de pBuffer.
    2. Não pode usar struct dentro do pBuffer
3. Como sempre, entregar o código e o vídeo explicando o código, mostrando casos de teste e o resultado do DrMemory