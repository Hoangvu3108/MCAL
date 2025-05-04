/**************************************************************************************************/
/** @file Lin_GeneralTypes.h
 *  @brief C�c d?nh nghia chung cho LIN driver theo chu?n AUTOSAR
 *  @details File n�y ch?a c�c ki?u d? li?u v� d?nh nghia chung du?c s? d?ng trong LIN driver tr�n STM32F103.
 *  @version 1.0.1
 *  @date 2024-11-1
 *  @author Hoang Long Vu
 **************************************************************************************************/
#ifndef LIN_GENERAL_TYPES_H
#define LIN_GENERAL_TYPES_H

#include "Std_Types.h"

/**************************************************************************************************/
/** @typedef Lin_FramePidType
 *  @brief Ki?u d? li?u cho ID b?o v? h?p l? c?a LIN frame.
 */
typedef uint8_t Lin_FramePidType; /**< @brief Ph?m vi: 0...0xEF */

/** @typedef Lin_FrameCsModelType
 *  @brief Enum ch? d?nh m� h�nh checksum du?c s? d?ng cho frame LIN.
 */
typedef enum {
    LIN_ENHANCED_CS, /**< @brief M� h�nh checksum n�ng cao */
    LIN_CLASSIC_CS   /**< @brief M� h�nh checksum c? di?n */
} Lin_FrameCsModelType;

/** @typedef Lin_FrameResponseType
 *  @brief Enum ch? d?nh lo?i ph?n h?i c?a frame LIN.
 */
typedef enum {
    LIN_FRAMERESPONSE_TX,    /**< @brief Ph?n h?i du?c t?o t? node n�y */
    LIN_FRAMERESPONSE_RX,    /**< @brief Ph?n h?i du?c t?o t? node kh�c v� li�n quan d?n node n�y */
    LIN_FRAMERESPONSE_IGNORE /**< @brief Ph?n h?i du?c t?o t? node kh�c v� kh�ng li�n quan d?n node n�y */
} Lin_FrameResponseType;

/**************************************************************************************************/
/** @typedef Lin_FrameDlType
 *  @brief Ki?u ch? d?nh d? d�i d? li?u c?a frame LIN.
 */
typedef uint8_t Lin_FrameDlType; /**< @brief Ph?m vi: 1...8 */

/**************************************************************************************************/
/** @typedef Lin_StatusType
 *  @brief Enum d?i di?n cho tr?ng th�i c?a k�nh ho?c frame LIN.
 **************************************************************************************************/
typedef enum {
    LIN_NOT_OK,   /**< @brief L?i ph�t sinh trong qu� tr�nh ho?t d?ng */
    LIN_TX_OK,    /**< @brief Truy?n th�nh c�ng */
    LIN_RX_OK,    /**< @brief Nh?n ph?n h?i ch�nh x�c */
    LIN_TX_BUSY,   /**< @brief �ang truy?n */
		LIN_TX_HEADER_ERROR,     /**< @brief L?i trong qu� tr�nh truy?n header */
    LIN_TX_ERROR,            /**< @brief L?i trong qu� tr�nh truy?n ph?n h?i */
    LIN_RX_BUSY,             /**< @brief �ang nh?n d? li?u */
    LIN_RX_ERROR,            /**< @brief L?i trong qu� tr�nh nh?n d? li?u */
    LIN_RX_NO_RESPONSE,      /**< @brief Kh�ng nh?n du?c ph?n h?i */
    LIN_OPERATIONAL,         /**< @brief Tr?ng th�i ho?t d?ng b�nh thu?ng */
    LIN_CH_SLEEP             /**< @brief Tr?ng th�i sleep c?a k�nh */
} Lin_StatusType;

/**
 * @typedef Lin_SlaveErrorType
 * @brief Enum d?i di?n cho c�c l?i ph�t sinh trong qu� tr�nh nh?n h?i c?a node LIN.
 */
typedef enum {
    LIN_ERR_HEADER,          /**< @brief L?i trong header */
    LIN_ERR_RESP_STOPBIT,    /**< @brief L?i framing trong ph?n h?i */
    LIN_ERR_RESP_CHKSUM,     /**< @brief L?i checksum */
    LIN_ERR_RESP_DATABIT,    /**< @brief L?i gi?m s�t bit d? li?u trong ph?n h?i */
    LIN_ERR_NO_RESP,         /**< @brief Kh�ng c� ph?n h?i */
    LIN_ERR_INC_RESP         /**< @brief Ph?n h?i kh�ng ho�n ch?nh */
} Lin_SlaveErrorType;

#endif /* LIN_GENERAL_TYPES_H*/