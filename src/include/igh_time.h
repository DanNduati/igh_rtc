/*******************************************************************************
 * @file igh_time.h
 * @brief System RTC API
 * @auther Nduati Daniel Chege
 * Copyright (C), Synnefa Green Ltd. All rights reserved.
 *******************************************************************************/

#ifndef _IGH_TIME_H_
#define _IGH_TIME_H_
#include "RTClib.h"

// Public APIs
void igh_time_init(void);
boolean igh_time_is_valid(void);
uint32_t igh_time_now(void);
boolean igh_time_set(uint32_t unix_time);
DateTime igh_datetime(void);
#endif