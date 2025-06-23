# 🧠 Jogo de Lógica com Pilhas - Torre de Hanoi Adaptado

### Como Rodar


    make

    ./main.out


**Atividade Avaliada 4**  
**Valor:** 5.0 pontos no Segundo Bimestre  

---

## 🎯 Objetivo

Implementar um jogo de lógica, inspirado na **Torre de Hanoi**, utilizando a estrutura de dados **Pilha**. O objetivo é desenvolver o raciocínio lógico de crianças organizando pinos coloridos em colunas.

---

## 🧩 Descrição do Jogo

- O jogo possui **4 colunas (pilhas)** nomeadas `P1`, `P2`, `P3`, `P4`.
- Existem **duas posições auxiliares temporárias**: `Temp1` e `Temp2`.
- Cada pilha pode armazenar até **4 pinos**.
- Cada pino possui uma **cor** e só é possível **mover um pino por vez**.
- O jogo inicia com os pinos **dispostos aleatoriamente** entre as pilhas.
- O objetivo é **organizar todos os pinos da mesma cor** em uma única pilha.

---

## 🔁 Regras

1. O jogo possui **12 pinos**, divididos em **4 cores**.
2. Cada pilha (`P1` a `P4`) pode conter no máximo **4 pinos**.
3. Os temporários (`Temp1` e `Temp2`) armazenam **apenas 1 pino** cada.
4. É permitido movimentar **apenas um pino por vez**.
5. O posicionamento inicial dos pinos será feito de forma **aleatória**.

---

## 🧱 Níveis de Dificuldade

| Nível    | Configuração                             |
|----------|------------------------------------------|
| Fácil    | 4 pilhas + 2 temporários (`Temp1`, `Temp2`) |
| Médio    | 4 pilhas + 1 temporário (`Temp1`)        |
| Difícil  | 4 pilhas, **sem temporários**            |

---

## ⏱️ Medidor de Tempo

- Utilize a função `TIME` para registrar o **tempo total de jogo**.
- O tempo será utilizado para avaliar o desempenho dos jogadores.

---

## 🖥️ Interface do Jogo

- O jogo deve ter uma **interface via terminal**.
- Deve mostrar o estado atual das pilhas e dos temporários.
- O usuário poderá realizar movimentos como:

### Operações permitidas:

1. `PUSH` para pilha X e `POP` de pilha Y  
2. `PUSH` para pilha X e `POP` de um **temporário**  
3. `PUSH` de um **temporário** e `POP` para pilha X  

> **Dica:** os temporários podem ser implementados como **pilhas unitárias**, aceitando apenas um elemento.

---

## 📦 Entrega

- A atividade deverá ser entregue **pelo SIGAA**.
- Código-fonte comentado e funcionando via terminal.

---

**Bom trabalho!**
