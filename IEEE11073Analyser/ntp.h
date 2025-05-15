/***************************************************************************//**
  \file ntp.h

  \brief

  \author
    Atmel Corporation: http://www.atmel.com \n
    Support email: avr@atmel.com

  Copyright (c) 2008 , Atmel Corporation. All rights reserved.
  Licensed under Atmel's Limited License Agreement (BitCloudTM).

  \internal
*******************************************************************************/
#ifndef _NTP_H
#define _NTP_H

/******************************************************************************
                    Includes section
******************************************************************************/
//#include <types.h>
//#include <halSleepTimerClock.h>
#include "phd_types.h"

/******************************************************************************
                    Defines section
******************************************************************************/

// # of seconds since 1 jan 2000; don't change value
#define secondsSince2000	3155673600

typedef struct TimeDate_t
{
  uint16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
} TimeDate_t;

typedef struct BOTime_t
{
  uint32_t seconds;
  uint16_t fractionSeconds;
  int16_t offset;
} BOTime_t;


/******************************************************************************
                    Functions' prototypes section
******************************************************************************/

uint32_t getSystemSeconds();
RelativeTime getRelativeTime();
bool systemClockSet(void);
void setBOTime(BOTime_t boTime);
void setBOTimeOffset(uint16_t boTimeOffset);
void setAbsoluteTime(AbsoluteTime absoluteTime);
void setBOOffset(int16_t boOffset);
int16_t getBOOffset(void);
void setTimeDate(TimeDate_t timeDate, uint16_t offset);

BOTime_t getBOTime(void);
uint32_t getLocalTime();
TimeDate_t getLocalTimeDate();
AbsoluteTime getAbsoluteTime();

void resetTime();
bool checkDateTime(BOTime_t botime);

AbsoluteTime boTime2AbsoluteTime(BOTime_t boTime);
BOTime_t absoluteTime2boTime(AbsoluteTime absoluteTime);
uint16_t getYearDays(uint16_t year);
uint32_t daysSince1900(TimeDate_t timeDate);
uint32_t secondsSince1900(TimeDate_t timeDate);
uint8_t dayOfWeek(TimeDate_t timeDate);
TimeDate_t seconds2TimeDate(uint32_t seconds);
TimeDate_t boTime2TimeDate(BOTime_t boTime);
uint8_t bcdInt(uint8_t x);
uint8_t intBcd(uint8_t x);
// use: BcTime_t GetSystemTicks(void);
#define GetSystemTicks HAL_GetSystemTicks
// use: uint32_t GetSystemTickFreqency(void);
#define GetSystemTickFreqency halSleepTimerFrequency

#endif /*_NTP_H*/

// eof ntp.h
