# 🚀 Projeto: Interrupções e Controle de LEDs com RP2040 e BitDogLab

## 📌 Enunciado
Este projeto tem como objetivo consolidar o entendimento sobre o uso de **interrupções** no microcontrolador **RP2040**, bem como explorar as funcionalidades da placa **BitDogLab** através da interação entre botões e LEDs.

## 🎯 Objetivos
- Compreender o funcionamento e a aplicação de **interrupções** em microcontroladores.
- Implementar **debouncing via software** para eliminar o efeito de bouncing em botões.
- Controlar LEDs comuns e LEDs **endereçáveis WS2812**.
- Estudar e utilizar **resistores de pull-up internos** para acionamento de botões.
- Desenvolver um projeto funcional que combina **hardware e software**.

---

## 🔧 Componentes Utilizados
- **Placa de Desenvolvimento**: BitDogLab (RP2040)
- **Matriz 5x5 de LEDs WS2812** (endereçáveis), conectada à **GPIO 7**
- **LED RGB** (pinos conectados às GPIOs **11, 12 e 13**)
- **Botão A** (GPIO **5**)
- **Botão B** (GPIO **6**)

---

## ⚡ Funcionalidades do Projeto
1. **Piscar LED RGB**
   - O LED vermelho do **LED RGB** pisca **5 vezes por segundo** (frequência de 5 Hz).

2. **Incrementação de Números (Botão A)**
   - Cada vez que o **Botão A** (GPIO 5) for pressionado, o número exibido na matriz de LEDs **aumenta em 1**.

3. **Decrementação de Números (Botão B)**
   - Cada vez que o **Botão B** (GPIO 6) for pressionado, o número exibido na matriz de LEDs **diminui em 1**.

4. **Exibição de Números na Matriz de LEDs WS2812**
   - Os LEDs da matriz exibem **números de 0 a 9**.
   - O formato pode ser **digital (segmentos iluminados)** ou um **estilo criativo**, desde que os números sejam legíveis.

---

## 🛠️ Implementação Técnica
- **Interrupções GPIO**
  - Configuradas para detectar **borda de descida** no acionamento dos botões.
  - Função de interrupção **modifica variáveis globais** para alterar o estado do sistema.

- **Debouncing via Software**
  - Implementado por meio de **verificação de tempo decorrido** entre eventos (200 ms de intervalo).

- **Controle de LEDs WS2812**
  - Biblioteca de controle utilizada para comunicação com LEDs endereçáveis.
  - Exibição de números formatados na matriz **5x5**.

---

## 🔄 Fluxo de Execução
1. O programa inicia e começa a piscar o **LED vermelho**.
2. Os botões A e B são monitorados via **interrupções**.
3. Quando pressionados, o valor na matriz de LEDs **aumenta ou diminui**.
4. O sistema atualiza a exibição do número na matriz em tempo real.

---

## 🚀 Como Rodar o Projeto
### 📌 Pré-requisitos
- Placa **BitDogLab** com microcontrolador **RP2040**
- Ambiente de desenvolvimento configurado (**Raspberry Pi Pico SDK**, **CMake**, **Toolchain ARM**)
- Biblioteca de controle para **WS2812**

### 📌 Passos
1. Clone o repositório e entre na pasta do projeto:
   ```sh
   git clone https://github.com/seu-repositorio.git
   cd seu-repositorio
   ```
2. Compile o código:
   ```sh
   mkdir build && cd build
   cmake ..
   make
   ```
3. Envie o firmware para a placa:
   - Conecte a **BitDogLab** ao PC enquanto pressiona o botão **BOOTSEL**.
   - Arraste o arquivo `.uf2` gerado para a unidade montada no sistema.
4. O projeto estará rodando na placa! 🎉

---

## 🎥 Demonstração
Confira o funcionamento do projeto no vídeo abaixo:

[![Vídeo do Projeto](https://img.youtube.com/vi/SEU_VIDEO_ID/maxresdefault.jpg)](https://www.youtube.com/watch?v=SEU_VIDEO_ID)

---

## 📜 Licença
Este projeto é de código aberto sob a licença **MIT**.

## 🤝 Contribuições
Sinta-se à vontade para contribuir! Abra uma **issue** ou envie um **pull request**.

---

📩 Para dúvidas ou sugestões, entre em contato!

✨ Desenvolvido com paixão pela comunidade de makers! 🚀

