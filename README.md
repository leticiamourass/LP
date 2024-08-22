# 🐸 Simulação de Corrida de Sapos

Este projeto implementa uma simulação simples de corrida de sapos usando C++. Cada sapo na corrida tem um nome, um identificador, e diferentes estatísticas como a distância percorrida, quantidade de pulos, provas disputadas, vitórias e empates. A corrida é realizada até que um dos sapos percorra uma distância total definida.

## 📝 Funcionalidades

- **Simulação de Corrida**: Vários sapos competem em uma corrida onde saltam distâncias aleatórias até que um vença.
- **Estatísticas dos Sapos**: Cada sapo acumula estatísticas ao longo das corridas, como número de vitórias, empates e quantidade total de pulos.
- **Reinício da Corrida**: Após o término de uma corrida, as estatísticas são atualizadas, e a corrida pode ser reiniciada.

## 🚀 Como Executar

1. Clone o repositório para sua máquina local:
   ```bash
   git clone https://github.com/seu-usuario/seu-repositorio.git
   
2. Navegue até o diretório do projeto:
cd seu-repositorio

3. Compile o código:
g++ -o corrida_de_sapos main.cpp

4. Execute o programa:
./corrida_de_sapos

5. Siga as instruções na tela para adicionar sapos e iniciar a corrida.

## 📊 Exemplo de Saída
Digite o número de sapos participantes: 3

Digite o nome do sapo 1: Frodo

Digite o nome do sapo 2: Sam

Digite o nome do sapo 3: Pippin

O sapo Frodo pulou! Distância percorrida: 1.75 metros.

O sapo Sam pulou! Distância percorrida: 1.23 metros.

O sapo Pippin pulou! Distância percorrida: 1.84 metros.

...

O sapo Pippin venceu a corrida!
Pressione Enter para reiniciar a corrida...

## 🔧 Estrutura do Código
Classe Sapo: Representa cada sapo na corrida, com atributos e métodos para gerenciar suas estatísticas e comportamento durante a corrida.

Função realizarCorrida: Gerencia a lógica da corrida, incluindo os pulos dos sapos e a determinação do vencedor.

Função main: Ponto de entrada do programa, responsável por configurar a corrida e iniciar a simulação.
