# EP1 — Compactação e Descompactação de Strings

![C](https://img.shields.io/badge/language-C-blue.svg)
![Status](https://img.shields.io/badge/status-concluído-brightgreen.svg)

Exercício Programa da disciplina **Projeto e Analise de Algoritimo**
Prof. Antonio Luiz Basile — Universidade Presbiteriana Mackenzie

## 👥 Grupo

| Nome | RA |
|------|----|
| `Bruno Matheus Garutti Pinto` | `10736747` |
| `Gabrieli Souza Santos` | `10732702` |
| `Stella Farias Viera` | `10732983` |


## 📋 Sobre o projeto

Este repositório contém três programas em C, cada um em seu próprio arquivo-fonte,
que compactam e descompactam strings recebidas via linha de comando (sem uso de
arquivos para entrada ou saída).

| Arquivo | Programa | O que faz |
|---|---|---|
| [`ex1.c`](./ex1.c) | `ex1` | Compacta caracteres **iguais e consecutivos** no formato `char+quantidade` |
| [`ex2.c`](./ex2.c) | `ex2` | Descompacta o formato gerado pelo `ex1` |
| [`ex3.c`](./ex3.c) | `ex3` | Compacta **padrões (substrings) repetidos**, não só caracteres únicos |

## ▶️ Uso e exemplos

### Exercício 1 — `ex1`

Compacta blocos de caracteres repetidos consecutivos.

```bash
./ex1 "aaaaaaabbbbbaaaaaaaaaa"
# > a7-b5-a10

./ex1 "abcabc"
# > a1-b1-c1-a1-b1-c1
```

### Exercício 2 — `ex2`

Faz o processo inverso do `ex1`: recebe a string compactada e devolve a original.

```bash
./ex2 "a7-b5-a10"
# > aaaaaaabbbbbaaaaaaaaaa

./ex2 "a6-b15-c1-d1"
# > aaaaaabbbbbbbbbbbbbbbcd
```

### Exercício 3 — `ex3`

Generaliza o `ex1`: em vez de compactar apenas caracteres isolados, encontra o
**padrão de tamanho variável** que, repetido, cobre a maior quantidade possível
de caracteres a partir de cada posição (em caso de empate, prevalece o padrão
mais curto).

```bash
./ex3 "xyzxyzxyzababababababababababab"
# > xyz3-ab11

./ex3 "ababababababaaaaaaaaaaaaaaa"
# > ab6-a15

./ex3 "abcabcabcabcxyxyxyccccccc"
# > abc4-xy3-c7

./ex3 "antonioantonioantoniocarloscarlos"
# > antonio3-carlos2
```

## 🧠 Como o `ex3` decide o padrão

Para cada posição `i` da string ainda não processada, o algoritmo:

1. Testa todos os tamanhos de padrão `p` (de 1 até metade do restante da string);
2. Para cada `p`, conta quantas cópias consecutivas (`k`) do trecho `s[i..i+p)` aparecem em seguida;
3. Só considera o padrão válido se `k >= 2` (repetição real);
4. Escolhe o par `(p, k)` que cobre o maior número de caracteres (`p * k`);
5. Em caso de empate, fica com o menor `p`;
6. Se nenhum padrão se repete, o caractere é emitido sozinho, com contagem `1` (igual ao `ex1`).

O processo se repete a partir da posição seguinte até o fim da string.

## 📁 Estrutura do repositório

```
.
├── ex1.c
├── ex2.c
├── ex3.c
└── README.md
```

## ⚠️ Observações

- As entradas são sempre recebidas por **linha de comando** (`argv`), e a saída é impressa no **monitor** — nenhum arquivo é lido ou escrito pelos programas.
- Os três programas são independentes entre si: cada um possui sua própria `main` e pode ser compilado e executado isoladamente.
