#include "date.h"

#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include "../rc.h"
using namespace std;


inline bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 ==0;
}
inline RC string_to_date(const char *str, int &date)
{
    int year = 0, month = 0, day = 0;
    int ret = sscanf(str, "%d-%d-%d", &year, &month, &day);
    if(ret!=3){
        return RC::INVALID_ARGUMENT;
    }
    if (year < 1900 || year > 9999 ||
        (month <= 0 || month > 12) ||
        (day <= 0 || day > 31))
        return RC::INVALID_ARGUMENT;
    
    int max_day_in_month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    const int max_day = max_day_in_month[month-1];
    if(day > max_day)
        return RC::INVALID_ARGUMENT;
    if(month == 2 && !is_leap_year(year) && day > 28)
        return RC::INVALID_ARGUMENT;
    date = year * 10000 + month * 100 + day;
    return RC::SUCCESS;
}

inline string date_to_string(int &date)
{
    char str[16]={0};
    snprintf(str, 11, "%04d-%02d-%02d", date/10000, (date/100)%100, date%100);
    return string(str);
}

bool check_date(int y, int m, int d) {
    static int mon[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = is_leap_year(y);
    return y>0
        && m>0 && m<=12
        && d>0 && d<=mon[m-1] + (m==2 && leap);
}
