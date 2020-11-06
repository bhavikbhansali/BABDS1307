/*
 * DS1307.h
 * library for Seeed RTC module
 *
 * Copyright (c) 2013 seeed technology inc.
 * Author        :   FrankieChu 
 * Create Time   :   Jan 2013
 * Change Log    :
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __BABDS1307_H__
#define __BABDS1307_H__

#include <Arduino.h>

#define DS1307_I2C_ADDRESS 0x68

#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6
#define SUN 7

class DS1307
{
private:
    uint8_t decToBcd(uint8_t val);
    uint8_t bcdToDec(uint8_t val);

public:
    void begin();
    void startClock(void);
    void stopClock(void);
    void setTime(void);
    void getTime(void);
    void fillByHMS(uint8_t _rtc_hour, uint8_t _rtc_minute, uint8_t _rtc_second);
    void fillByYMD(uint16_t _rtc_year, uint8_t _rtc_month, uint8_t _rtc_day);
    void fillDayOfWeek(uint8_t _rtc_dow);
    uint8_t rtc_second;
    uint8_t rtc_minute;
    uint8_t rtc_hour; 
    uint8_t rtc_dayOfWeek;// day of week, 1 = Monday
    uint8_t rtc_dayOfMonth;
    uint8_t rtc_month;
    uint16_t rtc_year;
};

#endif
