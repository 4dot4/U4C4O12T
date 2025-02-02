#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "pico/bootrom.h"
// // Biblioteca gerada pelo arquivo .pio durante a compilação.
#include "ws2818b.pio.h"

#define LED_COUNT 25
#define LED_PIN 7

// mapeamento de hardware
const uint RED = 13;   //LED RGB

const uint buttonA = 5;  //botão conectado ao GPIO 5
const uint  buttonB = 6;
uint volatile ledCounter = 0;
static volatile uint32_t last_time = 0; // variável auxiliar 
static volatile char flag = 0;

PIO np_pio;
uint sm;
struct pixel_t
{
    uint8_t G, R, B;
};
typedef struct pixel_t npLED_t;
npLED_t leds[LED_COUNT];

// Prototipação da função de interrupção
static void gpio_irq_handler(uint gpio, uint32_t events);
void init_leds(void);
void clear_leds(void);
void set_led(int index, uint8_t r, uint8_t g, uint8_t b);
void write_leds(void);

int main()
{
    stdio_init_all();
  
    gpio_init(RED);              // Inicializa o pino do LED
    gpio_set_dir(RED, GPIO_OUT); // Configura o pino como saída
                                      
    gpio_init(buttonA);// Inicializa o botão
    gpio_set_dir(buttonA, GPIO_IN); // Configura o pino como entrada
    gpio_pull_up(buttonA);          // Habilita o pull-up interno
    
    gpio_init(buttonB);// Inicializa o botão
    gpio_set_dir(buttonB, GPIO_IN); // Configura o pino como entrada
    gpio_pull_up(buttonB);          // Habilita o pull-up interno

    init_leds();
    // interrupção por borda de descida
    gpio_set_irq_enabled_with_callback(buttonA, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(buttonB, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    while (true) {
        
        gpio_put(RED, !gpio_get(RED));
        sleep_ms(200); // para piscar o led 5 vezes por segundo devemos esperar 200ms por piscada, 1000ms / 5 = 200ms

        
        // 24, 23, 22, 21, 20
        // 15, 16, 17, 18, 19
        // 14, 13, 12, 11, 10
        // 5,  6,  7,  8,  9
        // 4,  3,  2,  1,  0
        
        switch (ledCounter)
        {
        case 0: 
            clear_leds();
            for (int i = 0; i < 5; i++){
                set_led(i,255,0,0);
            }
            for (int i = 20; i < 25; i++){
                set_led(i,255,0,0);
            }
            set_led(5,255,0,0);
            set_led(14,255,0,0);
            set_led(15,255,0,0);

            set_led(9,255,0,0);
            set_led(10,255,0,0);
            set_led(19,255,0,0);
            write_leds();
        
            break;
        case 1:
            /* code */
            clear_leds();
            set_led(16,0,255,0);
            set_led(22,0,255,0);
            set_led(17,0,255,0);
            set_led(12,0,255,0);
            set_led(7,0,255,0);
            set_led(2,0,255,0);
            set_led(3,0,255,0);
            set_led(1,0,255,0);
            write_leds();
            break;
        case 2:
           /* code */
            clear_leds();
            for (int i = 20; i < 25; i++){
                set_led(i,0,0,255);
            }
            set_led(19,0,0,255);
            for (int i = 10; i < 15; i++){
                set_led(i,0,0,255);
            }
            set_led(5,0,0,255);
            for (int i = 0; i < 5; i++){
                set_led(i,0,0,255);
            }
            write_leds();
           break;
        case 3:
            /* code */
            clear_leds();
            for (int i = 20; i < 25; i++){
                set_led(i,0,255,255);
            }
            set_led(19,0,255,255);
            for (int i = 10; i < 15; i++){
                set_led(i,0,255,255);
            }
            set_led(9,0,255,255);
            for (int i = 0; i < 5; i++){
                set_led(i,0,255,255);
            }
            write_leds();
           break;
        case 4:
           /* code */
           clear_leds();
           set_led(24,255,255,0);
           set_led(20,255,255,0);
           set_led(15,255,255,0);
           set_led(19,255,255,0);
            for(int i = 10; i < 15; i++){
                set_led(i,255,255,0);
            }
            set_led(9,255,255,0);
            set_led(0,255,255,0);
            write_leds();
           break;
        case 5:
           /* code */
           clear_leds();
             for (int i = 20; i < 25; i++){
                set_led(i,255,0,255);
            }
            set_led(15,255,0,255);
            for (int i = 10; i < 15; i++){
                set_led(i,255,0,255);
            }
            set_led(9,255,0,255);
            for (int i = 0; i < 5; i++){
                set_led(i,255,0,255);
            }
           write_leds();
           break;
        case 6:
           /* code */
           clear_leds();
            for (int i = 20; i < 25; i++){
                set_led(i,50,50,255);
            }
            set_led(15,50,50,255);
            for (int i = 10; i < 15; i++){
                set_led(i,50,50,255);
            }
            set_led(9,50,50,255);
            set_led(5,50,50,255);
            for (int i = 0; i < 5; i++){
                set_led(i,50,50,255);
            }
           write_leds();
           break;
        case 7:
           /* code */
           clear_leds();
            for (int i = 20; i < 25; i++){
                set_led(i,250,100,100);
            }
            set_led(15,250,100,100);
            set_led(19,250,100,100);
            set_led(10,250,100,100);
            set_led(9,250,100,100);
            set_led(0,250,100,100);
           write_leds();
           break;
        case 8:
           /* code */
           clear_leds();
            for (int i = 20; i < 25; i++){
                set_led(i,50,200,255);
            }
            set_led(15,50,200,255);
            set_led(19,50,200,255);
            for (int i = 10; i < 15; i++){
                set_led(i,50,200,255);
            }
            set_led(5,50,200,255);
            set_led(9,50,200,255);
            for (int i = 0; i < 5; i++){
                set_led(i,50,200,255);
            }
           write_leds();
           break;
        case 9:
           /* code */
           clear_leds();
            for (int i = 20; i < 25; i++){
                set_led(i,255,255,255);
            }
            set_led(15,255,255,255);
            set_led(19,255,255,255);
            for (int i = 10; i < 15; i++){
                set_led(i,255,255,255);
            }
            
            set_led(9,255,255,255);
            for (int i = 0; i < 5; i++){
                set_led(i,255,255,255);
            }
           write_leds(); 
           break;
        default:
            break;
        }
        write_leds();
    }
}

void gpio_irq_handler(uint gpio, uint32_t events)
{
    // Obtém o tempo atual em microssegundos
    uint32_t current_time = to_us_since_boot(get_absolute_time());
  
    // Verifica se passou tempo suficiente desde o último evento
    if (current_time - last_time > 200000) // 200 ms de debouncing
    {
        last_time = current_time; // Atualiza o tempo do último evento
        switch (gpio)
        {
        case buttonA:

            ledCounter + 1 > 9 ? 0 : ledCounter++;
            break;
        case buttonB:
            ledCounter - 1 >= 0 ? ledCounter-- : 0;
        default:
            break;
        }
    }
}

void init_leds(void) //funcao para incilializar a matriz de leds 
{
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;
    sm = pio_claim_unused_sm(np_pio, true);
    ws2818b_program_init(np_pio, sm, offset, LED_PIN, 800000.f);
    for (int i = 0; i < LED_COUNT; i++)
    {
        leds[i].R = leds[i].G = leds[i].B = 0;
    }
}
void clear_leds(void) //funcao para limpar a cor para apagar todos os leds
{
    for (int i = 0; i < LED_COUNT; i++)
    {
        set_led(i, 0, 0, 0);
    }
}
void set_led(int index, uint8_t r, uint8_t g, uint8_t b) // funcao para  colocar uma cor em um led especifico
{
    if (index < LED_COUNT)
    {
        leds[index].R = r;
        leds[index].G = g;
        leds[index].B = b;
    }
}
void write_leds(void) //funcao para escrever a configuracao dos leds 
{
    for (int i = 0; i < LED_COUNT; i++)
    {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
}