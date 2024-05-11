#pragma once
#include <string>
#include "../rc.h"

inline bool is_leap_year(int year);
inline RC string_to_date(const char *str, int &date);
inline std::string date_to_string(int &date);
bool check_date(int y, int m, int d);
