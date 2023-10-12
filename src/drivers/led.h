/*!
 *******************************************************************************
 * @file led.c
 *
 * @brief Implementation of LED driver
 *
 * This driver implements the LED functionality required for traffic junction
 *
 * @authors Shreyas Gokhale (shreyas.gokhale@gropyus.com)
 *
 * @date 11.10.2023
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2023 Gropyus GmbH
 * All rights reserved.
 *******************************************************************************
 */

#ifndef LED_H
#define LED_H

/*
 *******************************************************************************
 * Public Macros                                                               *
 *******************************************************************************
 */

/*
 *******************************************************************************
 * Public Data Types                                                           *
 *******************************************************************************
 */

// TODO: Use these
// color_t m_internal_color;
// bool m_led_state;


/*
 *******************************************************************************
 * Public Constants                                                            *
 *******************************************************************************
 */

/*
 *******************************************************************************
 * Public Function Prototypes                                                  *
 *******************************************************************************
 */

// TODO: Return a suitable return type

/**
 * @brief Initialises LED driver
 *
 * @return bool
 */
int led_initialize(void);

/**
 * @brief Turn on the LED
 * @return
 */
int led_turn_on(void);


/** @brief Turn the LED off
 *
 * @return
 */
int led_turn_off(void);


/**
 * @brief Get current LED color
 *
 * @param p_color
 * @return
 */

// TODO: Complete this function
// int led_get_color(color_t * const p_color);


#endif //LED_H
