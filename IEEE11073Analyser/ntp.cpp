/**********************************************************************//**
  \file ntp.c

**************************************************************************/

#include <stdafx.h>
#include "phd_types.h"
//#include <types.h>
//#include <stdlib.h>
#include "ntp.h"
//#include "appTimer.h"
//#include "device.h"
#include "time.h"

BcTime_t systemTicksOffset = 0;
BcTime_t systemTicksCurrentTime = 0;
int16_t systemBOTimeOffset = 0;
bool systemBOTimeSet = false;


uint32_t halSleepTimerFrequency(void)
{
	return 1024;
}

uint64_t HAL_GetSystemTicks(void)
{
	return clock() / CLOCKS_PER_SEC * halSleepTimerFrequency();
}

void adjustSensorReadingTime(BOTime_t adjustBOTime,bool advance)
{
}

/***********************************************************************************
  Return number of seconds since system last reset

  Parameters:

  Return:
		seconds

 ***********************************************************************************/
uint32_t getSystemSeconds()
{
	return (uint32_t)(GetSystemTicks() / GetSystemTickFreqency());
}

/***********************************************************************************
  Return relative time since system last reset

  Parameters:

  Return:
		seconds

 ***********************************************************************************/
RelativeTime getRelativeTime()
{
	BcTime_t ticks;
// mask to provide positive only value
// multiply by 8 to suffice for relative time 1/8192
	ticks = GetSystemTicks();
	ticks = ticks & 0x0FFFFFFF;
	ticks = ticks * 8;
	return (RelativeTime)ticks;
}

/***********************************************************************************
  Set current date/time in BOTime format

  Parameters:
    boTime

  Return:

 ***********************************************************************************/
void setBOTime(BOTime_t boTime)
{
	BOTime_t currentBOTime;
	BOTime_t adjustBOTime;

/*
	we do not alter the system ticks counter, instead we count system ticks relative
	to the desired BO time. So we store the tick count at the moment we set the
	time. In that we can find the elapsed ticks since setting the time and
	thus calculate the current time
	*/

	currentBOTime = getBOTime();
// store the tick count corresponding to the moment we store the time
	systemTicksOffset = GetSystemTicks();
// and store BO time as system ticks (to make arithmetic easier)
	systemTicksCurrentTime = (BcTime_t)boTime.seconds * GetSystemTickFreqency();
// fractionSeconds
	systemTicksCurrentTime += ((BcTime_t)boTime.fractionSeconds * GetSystemTickFreqency())/65536;
// and store the BO ofset	
	systemBOTimeOffset = boTime.offset;
	systemBOTimeSet = true;
// adjust any existing readings
	if (currentBOTime.seconds > boTime.seconds) {
	// adjust backwards
		adjustBOTime.seconds = currentBOTime.seconds - boTime.seconds;
		adjustBOTime.offset = currentBOTime.offset - boTime.offset;
		adjustSensorReadingTime(adjustBOTime,false);
	}
	else {
	// adjust backwards
		adjustBOTime.seconds = boTime.seconds - currentBOTime.seconds;
		adjustBOTime.offset = boTime.offset - currentBOTime.offset;
		adjustSensorReadingTime(adjustBOTime,true);
	}
}

/***********************************************************************************
  Set current the BOTime offset

  Parameters:
    boTime offset

  Return:

 ***********************************************************************************/
void setBOTimeOffset(uint16_t boTimeOffset)
{
// store the BO ofset	
	systemBOTimeOffset = boTimeOffset;
}

/***********************************************************************************
  Return if clock has been set

  Parameters:

  Return:
    clock set

 ***********************************************************************************/
bool systemClockSet(void)
{
	return systemBOTimeSet;
}

/***********************************************************************************
  Return current date/time in BOTime format

  Parameters:

  Return:
    boTime

 ***********************************************************************************/
BOTime_t getBOTime(void)
{
	BOTime_t boTime;
	BcTime_t elapsedTicks;
	BcTime_t totalTicks;
	uint32_t ticksFreq = GetSystemTickFreqency();

// get elapsed ticks since storing the time
	elapsedTicks = GetSystemTicks() - systemTicksOffset;
// current time = set time + time elapsed
	totalTicks = systemTicksCurrentTime + elapsedTicks;
	boTime.seconds = (uint32_t)(totalTicks / ticksFreq);
	totalTicks -= boTime.seconds * ticksFreq;
	boTime.fractionSeconds = (uint16_t)((totalTicks * 65536) / ticksFreq);
// and retrieve the offset
	boTime.offset = systemBOTimeOffset;
	return boTime;
}

/***********************************************************************************
  Set boOffset

  Parameters:
    boOffset

  Return:

 ***********************************************************************************/
void setBOOffset(int16_t boOffset)
{
	systemBOTimeOffset = boOffset;
}

/***********************************************************************************
  Get boOffset

  Parameters:

  Return:
    boOffset

 ***********************************************************************************/
int16_t getBOOffset(void)
{
	return systemBOTimeOffset;
}

/***********************************************************************************
  Set current date/time from AbsoluteTime format

  Parameters:
    time

  Return:

 ***********************************************************************************/
void setAbsoluteTime(AbsoluteTime absoluteTime)
{
	BOTime_t boTime;

	boTime = absoluteTime2boTime(absoluteTime);
	setBOTime(boTime);
}

/***********************************************************************************
  Set time in TimeDate format

  Parameters:
    timeDate

  Return:

 ***********************************************************************************/
void setTimeDate(TimeDate_t timeDate, uint16_t offset)
{
	BOTime_t boTime;

	boTime.seconds = secondsSince1900(timeDate);
	boTime.fractionSeconds = 0;
	boTime.offset = offset;
	setBOTime(boTime);
}

/***********************************************************************************
  Return local date/time in NTP seconds format

  Parameters:

  Return:
    current local time in seconds

 ***********************************************************************************/
uint32_t getLocalTime()
{
 	BOTime_t boTime;

	boTime = getBOTime();
	return boTime.seconds + (int32_t)boTime.offset*60;
}

/***********************************************************************************
  Return current date/time in TimeDate format

  Parameters:

  Return:
    current time

 ***********************************************************************************/
TimeDate_t getLocalTimeDate()
{
 	BOTime_t boTime;

	boTime = getBOTime();
	return boTime2TimeDate(boTime);
}

/***********************************************************************************
  Return current date/time in AbsoluteTime format

  Parameters:

  Return:
    current time

 ***********************************************************************************/
AbsoluteTime getAbsoluteTime()
{
 	BOTime_t boTime;

	boTime = getBOTime();
	return boTime2AbsoluteTime(boTime);
}

/***********************************************************************************
  Can be used to set to a preset time

  Parameters:

  Return:

 ***********************************************************************************/
void resetTime()
{
	AbsoluteTime absoluteTime;

	absoluteTime.century = 0x20;
	absoluteTime.year = 0x00;
	absoluteTime.day = 0x01;
	absoluteTime.month = 0x01;
	absoluteTime.hour = 0x00;
	absoluteTime.minute = 0x00;
	absoluteTime.second = 0x00;
	absoluteTime.sec_fractions = 0x00;
	setAbsoluteTime(absoluteTime);
}

/***********************************************************************************
  Check if valid date/time (>= 1 jan 2000)

  Parameters:
	absoluteTime

  Return:
	valid: true

 ***********************************************************************************/
bool checkDateTime(BOTime_t botime)
{
	uint32_t seconds;

	seconds = botime.seconds + (int32_t)botime.offset*60;
	return (seconds > secondsSince2000);
}

/***********************************************************************************
  Return convert boTime format to AbsoluteTime format

  Parameters:
	time

  Return:
    time

 ***********************************************************************************/
AbsoluteTime boTime2AbsoluteTime(BOTime_t botime)
{
	AbsoluteTime absoluteTime;
	TimeDate_t timedate;

	timedate = boTime2TimeDate(botime);
	absoluteTime.century = bcdInt(timedate.year / 100);
	absoluteTime.year = bcdInt(timedate.year % 100);
	absoluteTime.month = bcdInt(timedate.month);
	absoluteTime.day = bcdInt(timedate.day);
	absoluteTime.hour = bcdInt(timedate.hour);
	absoluteTime.minute = bcdInt(timedate.minute);
	absoluteTime.second = bcdInt(timedate.second);
	// leave 1/100 secs blank
	absoluteTime.sec_fractions = 0x00;
	return absoluteTime;
}

/***********************************************************************************
  Return convert AbsoluteTime format to boTime format

  Parameters:
	time

  Return:
    time

 ***********************************************************************************/
BOTime_t absoluteTime2boTime(AbsoluteTime absoluteTime)
{
	BOTime_t botime;
	TimeDate_t timedate;

	timedate.second = intBcd(absoluteTime.second);
	timedate.minute = intBcd(absoluteTime.minute);
	timedate.hour = intBcd(absoluteTime.hour);
	timedate.day = intBcd(absoluteTime.day);
	timedate.month = intBcd(absoluteTime.month);
	timedate.year = intBcd(absoluteTime.year);
	timedate.year += intBcd(absoluteTime.century) * 100;
	botime.seconds = secondsSince1900(timedate);
	// leave 1/100 secs blank
	botime.fractionSeconds = 0;
	botime.offset = 0;

	return botime;
}

/***********************************************************************************
  Calculate number of days in the given year

  Parameters:
    year

  Return:
    days

 ***********************************************************************************/
uint16_t getYearDays(uint16_t year)
{
	if (((year % 4) == 0 && (year % 100) != 0) || (year % 400) == 0)
		return 366;
	return 365;
}

/***********************************************************************************
  Calculate number of days since 1-Jan-1900.
  - Ignores UTC leap seconds.

  Parameters:
    y m d as TimeDate_t

  Return:
    seconds

 ***********************************************************************************/

uint8_t monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

uint32_t daysSince1900(TimeDate_t timeDate)
{
  uint32_t days = 0;
  uint16_t year = 1900;
  uint16_t month = 0;
  uint16_t yearDays;

  while (year < timeDate.year) {
    yearDays = getYearDays(year);
    days+= yearDays;
    year++;
  }
  yearDays = getYearDays(year);
  monthDays[1] = yearDays - 337;
  timeDate.month--;
  while (month < timeDate.month) {
    days+= monthDays[month];
    month++;
  }
  days+= timeDate.day - 1;
  return days;
}

/***********************************************************************************
  Calculate number of seconds since 1-Jan-1900.
  - Ignores UTC leap seconds.

  Parameters:
    y m d as TimeDate_t

  Return:
    seconds

 ***********************************************************************************/
uint32_t secondsSince1900(TimeDate_t timeDate)
{
	uint32_t days;

	days = daysSince1900(timeDate);
	return ((days * 24 + timeDate.hour) * 60 + timeDate.minute) * 60 + timeDate.second;
}

/***********************************************************************************
  Calculate day of week

  Parameters:
    y m d as TimeDate_t

  Return:
    seconds

 ***********************************************************************************/
uint8_t dayOfWeek(TimeDate_t timeDate)
{
	uint32_t days;

	days = daysSince1900(timeDate);
	return days % 7;
}

/***********************************************************************************
  Calculate date from seconds since 1-Jan-1900.
  - Ignores UTC leap seconds.

  Parameters:
    seconds

  Return:
    y m d h m s

 ***********************************************************************************/
TimeDate_t boTime2TimeDate(BOTime_t boTime)
{
	return seconds2TimeDate(boTime.seconds + (int32_t)boTime.offset*60);
}

TimeDate_t seconds2TimeDate(uint32_t seconds)
{
  TimeDate_t timeDate;
  uint32_t minutes;
  uint32_t hours;
  uint32_t days;
  uint16_t yearDays;

  timeDate.second = seconds % 60;
  minutes = seconds / 60;
  timeDate.minute = minutes % 60;
  hours = minutes / 60;
  timeDate.hour = hours % 24;
  days = hours / 24;
  timeDate.year = 1900;
  yearDays = getYearDays(timeDate.year);
  while (days >= yearDays) {
    days-= yearDays;
    timeDate.year++;
	yearDays = getYearDays(timeDate.year);
  }
  timeDate.month = 0;
  monthDays[1] = yearDays - 337;
  while (days >= monthDays[timeDate.month]) {
    days-= monthDays[timeDate.month];
    timeDate.month++;
  }
  timeDate.month++;
  timeDate.day = (uint8_t)(days + 1);
  return timeDate;
}

/***********************************************************************************
  Convert BCD to integer

  Parameters:

  Return:

 ***********************************************************************************/
uint8_t bcdInt(uint8_t x)
{
	uint8_t y1 = x / 10 * 16;
	uint8_t y2 = x % 10;
	return y1 + y2;
}

/***********************************************************************************
  Convert integer to BCD

  Parameters:

  Return:

 ***********************************************************************************/
uint8_t intBcd(uint8_t x)
{
	uint8_t y1 = x / 16 * 10;
 	uint8_t y2 = x % 16;
	return y1 + y2;
}


//eof ntp.c
