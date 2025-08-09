<p align="left">
	<img src="https://img.shields.io/badge/license-Unlicense-blue.svg" alt="License: Unlicense">
	<img src="https://img.shields.io/badge/language-C-blue.svg" alt="C Language">
</p>

# Controle de Estoque em C — Estrutura de Dados (UENP)

Este repositório reúne dois projetos desenvolvidos para a disciplina de Estrutura de Dados na [Universidade Estadual do Norte do Paraná (UENP)](https://uenp.edu.br/). Os projetos simulam um sistema de controle de estoque, utilizando diferentes estruturas de dados para fins didáticos e comparativos.

## Projetos

- **Trabalho-Lista**: Controle de estoque implementado com listas encadeadas.
- **Trabalho-Arvore**: Controle de estoque implementado com árvores binárias.

Cada projeto possui arquivos de entrada e saída, código-fonte modularizado em C e um makefile para automação da compilação.

## Estrutura

```
Trabalho_Farmacia/
├── Trabalho-Lista/
│   ├── entrada.txt
│   ├── estoque.c
│   ├── estoque.h
│   ├── makefile
│   ├── saida.txt
│   └── trabalho1.c
├── Trabalho-Arvore/
│   ├── entrada.txt
│   ├── estoque.c
│   ├── estoque.h
│   ├── makefile
│   ├── saida.txt
│   └── trabalho2.c
└── README.md
```

## Como compilar e executar

Cada diretório possui um `makefile` para facilitar a compilação. Utilize os comandos abaixo conforme o projeto desejado:

### Trabalho-Lista
```sh
cd Trabalho-Lista
make
./trabalho1
```

### Trabalho-Arvore
```sh
cd Trabalho-Arvore
make
./trabalho2
```

## Licença

Distribuído sob a [The Unlicense](LICENSE). Uso livre para qualquer finalidade.