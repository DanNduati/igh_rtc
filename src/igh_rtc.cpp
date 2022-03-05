/*******************************************************************************
 * @file rtc_test.cpp
 * @brief RTC test script based on Arduino for Feather M0 EVM
 * @auther Nduati Daniel Chege
 * Copyright (C), Synnefa Green Ltd. All rights reserved.
 *******************************************************************************/
#include "Particle.h"
#include "include/igh_time.h"

SYSTEM_THREAD(ENABLED);
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup()
{
  Serial.begin(9600);
  igh_time_init();
}
void loop()
{

  Serial.print("Current DATETIME: ");
  Serial.print(igh_datetime().year(), DEC);
  Serial.print('/');
  Serial.print(igh_datetime().month(), DEC);
  Serial.print('/');
  Serial.print(igh_datetime().day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[igh_datetime().dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(igh_datetime().hour(), DEC);
  Serial.print(':');
  Serial.print(igh_datetime().minute(), DEC);
  Serial.print(':');
  Serial.print(igh_datetime().second(), DEC);
  Serial.println();

  Serial.print("Unix epoch time: ");
  Serial.print(igh_time_now());
  Serial.println();
  Serial.print("Is the time valid: ");
  if (igh_time_is_valid())
  {
    Serial.print("Yes!");
  }
  else
  {
    Serial.print("No!");
  }

  Serial.println();
  delay(2000);
}