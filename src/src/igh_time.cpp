/*******************************************************************************
 * @file igh_time.cpp
 * @brief Application layer for rtc
 * @auther Nduati Daniel Chege
 * Copyright (C), Synnefa Green Ltd. All rights reserved.
 *******************************************************************************/
#include "Particle.h"
#include <Arduino.h>
#include "include/igh_time.h"

uint32_t SECOND_FROM_1970_TO_2021 = 1609459200; // will be used to validate time
RTC_PCF8523 rtc;

void igh_time_init(void)
{
    if (!rtc.begin())
    {
        Serial.println("Couldn't find RTC");
        while (1)
            ;
    }
    if (!rtc.initialized())
    {
        // set compiler date and time it the rtc isnt running
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

boolean igh_time_set(uint32_t unix_time)
{
    rtc.adjust(DateTime(unix_time));
    return 1;
}

uint32_t igh_time_now(void)
{
    DateTime now = rtc.now();
    return now.unixtime();
}

DateTime igh_datetime(void)
{
    DateTime now = rtc.now();
    return now;
}

boolean igh_time_is_valid(void)
{
    boolean isvalid = (igh_time_now() > SECOND_FROM_1970_TO_2021) ? 1 : 0;
    return isvalid;
}