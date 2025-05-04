#include "Lin.h"
#include "Lin_Cfg.h"

/**
 * @brief Kh?i t?o m�-dun LIN.
 * @param Config Con tr? d?n c?u tr�c c?u h�nh LIN.
 */
void Lin_Init(const Lin_ConfigType* Config) {
    // Ki?m tra c?u h�nh h?p l?
    if (Config == NULL) {
        return; // Tr? v? n?u c?u h�nh kh�ng h?p l?
    }

    // B?t clock cho c�c port GPIO v� UART s? d?ng cho LIN
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);

    // C?u h�nh ch�n Tx (PA9) v� Rx (PA10) cho UART s? d?ng cho LIN
    GPIO_InitTypeDef GPIO_InitStructure;

    // Ch�n Tx
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // Ch�n Rx
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // C?u h�nh UART cho LIN
    USART_InitTypeDef USART_InitStructure;
    USART_InitStructure.USART_BaudRate = Config->Lin_BaudRate; // T?c d? truy?n t? c?u h�nh
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    // ... ti?p t?c c?u h�nh USART
}