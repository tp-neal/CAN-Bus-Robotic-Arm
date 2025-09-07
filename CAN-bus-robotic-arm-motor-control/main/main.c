#include <stdio.h>
#include <driver/gpio.h>

#define CAN_RX_PIN GPIO_NUM_18
#define CAN_TX_PIN GPIO_NUM_19
#define SERVO_PWM_PIN GPIO_NUM_20

void app_main(void) {
    // Set up CAN tranciever GPIO
    gpio_config_t can_rx_config = {
        .pin_bit_mask = CAN_RX_PIN,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    gpio_config_t can_tx_config = {
        .pin_bit_mask = CAN_TX_PIN,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    gpio_config_t servo_pwm_config = {
        .pin_bit_mask = SERVO_PWM_PIN,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    gpio_reset_pin(CAN_RX_PIN);
    gpio_reset_pin(CAN_TX_PIN);
    gpio_reset_pin(SERVO_PWM_PIN);
    
    gpio_config(&can_rx_config);
    gpio_config(&can_tx_config);
    gpio_config(&servo_pwm_config);

}