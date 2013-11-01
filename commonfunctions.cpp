#include "includes.h"


void GetSysLocalTime(SYSTEMTIME *pSysTime)
{
    assert(pSysTime);
    timeval lstLocalTimeVal;
    struct tm lstCalendarTime;
    gettimeofday(&lstLocalTimeVal, NULL);
    
    localtime_r(&lstLocalTimeVal.tv_sec, &lstCalendarTime);
    
    pSysTime->wDay = lstCalendarTime.tm_mday;
    pSysTime->wDayOfWeek = lstCalendarTime.tm_wday + 1;
    
    pSysTime->wMonth = lstCalendarTime.tm_mon + 1;
    pSysTime->wYear = lstCalendarTime.tm_year + POSIX_YEAR_OFFSET;
    pSysTime->wHour = lstCalendarTime.tm_hour;
    pSysTime->wMinute = lstCalendarTime.tm_min;
    pSysTime->wSecond = lstCalendarTime.tm_sec;
    pSysTime->wMilliseconds = MICROSECOND_TO_MILLISECOND(lstLocalTimeVal.tv_usec);
}
