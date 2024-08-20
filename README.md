# Simulação de Corrida de Sapos

Este projeto é uma simulação simples de uma corrida de sapos, implementada em C++. O objetivo é simular uma corrida onde sapos competem para ver quem chega primeiro a uma distância pré-definida.

## Descrição

A classe `Sapo` representa um sapo que pode pular uma distância aleatória em cada iteração. O programa cria uma lista de sapos, realiza a corrida e declara o vencedor quando um sapo atinge a distância total da corrida.

## Funcionalidades

- **Classe `Sapo`**:
  - **Atributos**:
    - `nome`: Nome do sapo.
    - `identificador`: Identificador único do sapo.
    - `distanciaPercorrida`: Distância total percorrida pelo sapo.
    - `quantidadePulos`: Número total de pulos dados pelo sapo.
    - `provasDisputadas`: Número total de provas disputadas pelo sapo.
    - `vitorias`: Número total de vitórias do sapo.
    - `empates`: Número total de empates do sapo.
    - `quantidadeTotalPulos`: Quantidade total de pulos dados por todos os sapos.
    - `distanciaTotalCorrida`: Distância total da corrida (atributo estático).
  - **Métodos**:
    - `pular()`: Incrementa a distância percorrida de forma aleatória.
    - **Construtor**: Inicializa um novo sapo com o nome e identificador fornecidos.

- **Função `realizarCorrida()`**:
  - Simula a corrida entre todos os sapos e declara o vencedor.

## Como Usar

1. **Compilar**: Compile o código usando um compilador C++ compatível. Por exemplo, com `g++`:
   ```sh
   g++ -o corrida_sapos corrida_sapos.cpp
