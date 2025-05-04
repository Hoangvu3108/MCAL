/**************************************************************************************************/
/** @file Lin_GeneralTypes.h
 *  @brief C�c d?nh nghia chung cho LIN driver theo chu?n AUTOSAR
 *  @details File n�y ch?a c�c ki?u d? li?u v� d?nh nghia chung du?c s? d?ng trong LIN driver tr�n STM32F103.
 *  @version 1.0.1
 *  @date 2024-11-1
 *  @author Hoang Long Vu
 **************************************************************************************************/
#ifndef LIN_CFG_H
#define LIN_CFG_H

#include "stm32f10x.h"                  // Device header

/**
 * @brief �?nh nghia c�c tr?ng th�i c?a k�nh LIN.
 */
//#define LIN_CH_SLEEP          0 /**< @brief Tr?ng th�i ng? c?a k�nh LIN. */
//#define LIN_CH_OPERATIONAL    1 /**< @brief Tr?ng th�i ho?t d?ng c?a k�nh LIN. */
//#define LIN_CH_SLEEP_PENDING  2 /**< @brief Tr?ng th�i dang ch? d? chuy?n v�o sleep. */

/**
 * @brief �?nh nghia s? lu?ng k�nh LIN t?i da.
 * @details Gi� tr? n�y c?n du?c c?u h�nh d?a tr�n h? th?ng th?c t?
 * v� kh? nang h? tr? c?a vi di?u khi?n.
 */
#define MAX_LIN_CHANNELS 2 /**< Gi� tr? n�y c� th? thay d?i t�y thu?c v�o s? lu?ng k�nh LIN m� h? th?ng h? tr?. */

/**
 * @brief �?nh nghia ID nh� cung c?p (Vendor ID).
 */

/**
 * @brief ID nh� cung c?p cho LIN driver.
 */
#define LIN_VENDOR_ID 123 /**< @brief ID nh� cung c?p cho LIN driver. */

/**
 * @brief �?nh nghia ID module (Module ID).
 */
#define LIN_MODULE_ID 456 /**< @brief ID module cho LIN driver. */

/**
 * @brief �?nh nghia phi�n b?n ph?n m?m (Software Version).
 */
#define LIN_SW_MAJOR_VERSION 1 /**< @brief Phi�n b?n ch�nh c?a ph?n m?m. */
#define LIN_SW_MINOR_VERSION 0 /**< @brief Phi�n b?n ph? c?a ph?n m?m. */
#define LIN_SW_PATCH_VERSION 0 /**< @brief Phi�n b?n s?a l?i c?a ph?n m?m. */

/**
 * @enum Lin_StatusType
 * @brief C�c tr?ng th�i kh�c nhau c?a k�nh LIN.
 */
typedef enum {
    LIN_CH_SLEEP,        /**< @brief Tr?ng th�i ng? c?a k�nh LIN. */
    LIN_CH_OPERATIONAL,  /**< @brief Tr?ng th�i ho?t d?ng c?a k�nh LIN. */
    LIN_CH_SLEEP_PENDING /**< @brief Tr?ng th�i dang ch? d? chuy?n v�o sleep. */
} Lin_StatusType;

/**
 * @struct LinChannelConfigType
 * @brief C?u tr�c ch?a th�ng tin c?u h�nh cho m?t k�nh LIN.
 */
typedef struct {
    uint32_t Lin_Baudrate;                  /**< @brief T?c d? truy?n d? li?u c?a k�nh LIN. */
    FunctionalState LinChannelWakeupSupport; /**< @brief H? tr? ph�t hi?n wake-up (ENABLE/DISABLE). */
    uint16_t Lin_ChannelID;                 /**< @brief ID c?a k�nh LIN. */
    GPIO_TypeDef* Lin_Port;                 /**< @brief C?ng GPIO c?a k�nh LIN. */
    uint16_t Lin_TxPin;                     /**< @brief Ch�n Tx c?a k�nh LIN. */
    uint16_t Lin_RxPin;                     /**< @brief Ch�n Rx c?a k�nh LIN. */
} LinChannelConfigType;


/**
 * @brief M?ng luu tr? tr?ng th�i c?a c�c k�nh LIN.
 */
Lin_StatusType LinChannelState[MAX_LIN_CHANNELS] = {
    LIN_CH_SLEEP, // Kh?i t?o tr?ng th�i ban d?u cho m?i k�nh
    LIN_CH_SLEEP  // Kh?i t?o cho k�nh th? hai n?u c?n
};

/**
 * @brief M?ng luu tr? c?u h�nh cho c�c k�nh LIN.
 * @details M?i ph?n t? trong m?ng ch?a th�ng tin c?u h�nh c?a m?t k�nh LIN,
 * bao g?m t?c d? baud, tr?ng th�i h? tr? wake-up, v� c�c ch�n GPIO li�n quan.
 */
LinChannelConfigType LinChannelConfig[MAX_LIN_CHANNELS] = {
    {
        .Lin_Baudrate = 19200,                  /**< @brief T?c d? baud cho k�nh LIN. */
        .LinChannelWakeupSupport = ENABLE,     /**< @brief H? tr? wake-up. */
        .Lin_ChannelID = 0,                     /**< @brief ID c?a k�nh LIN. */
        .Lin_Port = GPIOA,                      /**< @brief C?ng GPIO s? d?ng. */
        .Lin_TxPin = GPIO_Pin_9,                /**< @brief Ch�n Tx c?a k�nh. */
        .Lin_RxPin = GPIO_Pin_10                /**< @brief Ch�n Rx c?a k�nh. */
    }
    // Th�m c?u h�nh cho c�c k�nh kh�c n?u c?n
};

#endif /* LIN_CFG_H */
