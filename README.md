# Simulação de Corrida de Sapos

Este projeto é uma simulação de corrida de sapos em C++. O código simula uma corrida onde sapos competem para alcançar uma distância predefinida. A corrida continua até que pelo menos um sapo alcance a linha de chegada, e o programa determina se há um vencedor ou um empate.

## Descrição

O código define uma classe `Sapo` que representa um sapo participante da corrida. Cada sapo pode pular uma distância aleatória a cada iteração. O programa determina o vencedor com base no primeiro sapo a atingir a distância total da corrida ou indica um empate se mais de um sapo alcançar a distância simultaneamente.

## Funcionalidades

- **Classe `Sapo`**:
  - **Atributos**:
    - `nome`: Nome do sapo.
    - `identificador`: Identificador único do sapo.
    - `distanciaPercorrida`: Distância total percorrida pelo sapo durante a corrida.
    - `quantidadePulos`: Número total de pulos dados pelo sapo.
    - `provasDisputadas`: Número total de corridas disputadas pelo sapo.
    - `vitorias`: Número total de vitórias do sapo.
    - `empates`: Número total de empates do sapo.
    - `quantidadeTotalPulos`: Quantidade total de pulos dados por todos os sapos.
    - `distanciaTotalCorrida`: Distância total da corrida (definida como 100 unidades).
  - **Métodos**:
    - `pular()`: Incrementa a distância percorrida do sapo de forma aleatória.
    - `incrementarProvas()`: Incrementa o número de provas disputadas.
    - `incrementarVitorias()`: Incrementa o número de vitórias.
    - `incrementarEmpates()`: Incrementa o número de empates.
    - `resetarCorrida()`: Reseta a distância percorrida e a quantidade de pulos para uma nova corrida.

- **Função `realizarCorrida()`**:
  - Simula a corrida entre todos os sapos e declara o vencedor ou os empates.

## Compilação e Execução

Para compilar e executar o código, siga os seguintes passos:

1. **Compilar o Código**:
   - Utilize um compilador C++ para compilar o código. Por exemplo, com `g++`:
     ```sh
     g++ -o corrida_sapos corrida_sapos.cpp
     ```

2. **Executar o Programa**:
   - Execute o programa compilado:
     ```sh
     ./corrida_sapos
     ```

3. **Adicionar Mais Sapos**:
   - Para adicionar mais sapos à corrida, modifique o código na função `main()` e adicione novas instâncias de `Sapo` ao vetor `sapos`.

   ```cpp
   std::vector<Sapo> sapos = { Sapo("CrazyFrog", 1), Sapo("Cururu", 2), Sapo("Sapinho", 3) };
