#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PINO_SERVOMOTOR 22 // GPIO do servomotor
#define PINO_LED_AZUL 12   // GPIO do LED azul
#define FREQUENCIA_PWM 50  // Frequência de 50Hz

// Função para configurar o PWM
void configurar_pwm(uint pino) {
    gpio_set_function(pino, GPIO_FUNC_PWM);
    uint fatia_pwm = pwm_gpio_to_slice_num(pino);
    pwm_config configuracao = pwm_get_default_config();
    pwm_config_set_clkdiv(&configuracao, 100.0f); // Ajuste para 50Hz
    pwm_config_set_wrap(&configuracao, 25000); // Ajuste para período de 20ms
    pwm_init(fatia_pwm, &configuracao, true);
}

// Função para ajustar a posição do servomotor
void ajustar_posicao_servo(uint pino, uint largura_pulso_us) {
    uint fatia_pwm = pwm_gpio_to_slice_num(pino);
    uint nivel_pwm = (largura_pulso_us * 25000) / 20000; // Conversão para PWM
    pwm_set_gpio_level(pino, nivel_pwm);
}

// Função para alterar a intensidade do LED azul
void ajustar_brilho_led(uint pino, uint intensidade) {
    uint fatia_pwm = pwm_gpio_to_slice_num(pino);
    uint valor_pwm = (intensidade * 65535) / 255; // Escala a intensidade para o intervalo de 0 a 65535
    pwm_set_gpio_level(pino, valor_pwm);
}

// Função de teste do servomotor
void testar_servomotor() {
    printf("Testando servomotor...\n");
    ajustar_posicao_servo(PINO_SERVOMOTOR, 500); // 0°
    sleep_ms(2000); // Espera 2 segundos
    ajustar_posicao_servo(PINO_SERVOMOTOR, 1470); // 90°
    sleep_ms(2000); // Espera 2 segundos
    ajustar_posicao_servo(PINO_SERVOMOTOR, 2400); // 180°
    sleep_ms(2000); // Espera 2 segundos
    printf("Servomotor testado com sucesso.\n");
}

// Função de teste do LED Azul
void testar_led_azul() {  
    printf("Testando LED Azul...\n"); 
    ajustar_brilho_led(PINO_LED_AZUL, 0);   // LED apagado
    sleep_ms(1000);
    ajustar_brilho_led(PINO_LED_AZUL, 127); // Intensidade média
    sleep_ms(1000);
    ajustar_brilho_led(PINO_LED_AZUL, 255); // Máximo brilho
    sleep_ms(1000);
    printf("LED Azul testado com sucesso.\n");
}

int main() {
    stdio_init_all();
    
    // Configura o servomotor
    configurar_pwm(PINO_SERVOMOTOR);

    // Configura o LED azul (pino 12)
    configurar_pwm(PINO_LED_AZUL);

    // Testes básicos para garantir que o hardware está funcionando corretamente
    testar_servomotor();
    testar_led_azul();

    while (true) {
        // Ajusta o servomotor para 180° (pino do servo)
        ajustar_posicao_servo(PINO_SERVOMOTOR, 2400);
        ajustar_brilho_led(PINO_LED_AZUL, 255); // Aumenta a intensidade do LED azul para máximo
        printf("Movendo para 180°\n");
        sleep_ms(5000);

        // Ajusta o servomotor para 90°
        ajustar_posicao_servo(PINO_SERVOMOTOR, 1470);
        ajustar_brilho_led(PINO_LED_AZUL, 127); // Intensidade média do LED azul
        printf("Movendo para 90°\n");
        sleep_ms(5000);

        // Ajusta o servomotor para 0°
        ajustar_posicao_servo(PINO_SERVOMOTOR, 500);
        ajustar_brilho_led(PINO_LED_AZUL, 0);   // Apaga o LED azul
        printf("Movendo para 0°\n");
        sleep_ms(5000);

        // Imprime a mensagem apenas uma vez
        printf("Movimentação suave de 0° a 180° e vice-versa\n");

        // Movimento suave do servo entre 0° e 180°
        for (int posicao = 500; posicao <= 2400; posicao += 5) {
            ajustar_posicao_servo(PINO_SERVOMOTOR, posicao);
            ajustar_brilho_led(PINO_LED_AZUL, (posicao - 500) / 10); // Ajusta a intensidade do LED conforme o servo se move
            sleep_ms(10);
        }
        for (int posicao = 2400; posicao >= 500; posicao -= 5) {
            ajustar_posicao_servo(PINO_SERVOMOTOR, posicao);
            ajustar_brilho_led(PINO_LED_AZUL, (posicao - 500) / 10); // Reduz a intensidade do LED conforme o servo volta
            sleep_ms(10);
        }
    }
}
