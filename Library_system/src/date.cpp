#include "date.h"
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

date::date() {
    time_t  t;  
    tm *tp;
    t = time(NULL); 
    tp = localtime(&t);
    year = tp -> tm_year + 1900;
    month = tp -> tm_mon + 1;
    day = tp -> tm_mday;
}

date::date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
    if (month > 12)
        month = 1;
    if (day > 31)
        day = 1;
}

void date::set_year(int y) {
    year = y;
}

void date::set_month(int m) {
    month = m;
}

void date::set_day(int d) {
    day = d;
}

int date::get_year() const {
    return year;
}

int date::get_month() const {
    return month;
}

int date::get_day() const {
    return day;
}

date add_days(date d, int days) {
    int mon[12] = {31, 28, 31, 30, 31, 30,
                   31, 31, 30, 31, 30, 31};
    while (days >= 366) {
        if (is_leap_year(d.year))
            days -= 366;
        else
            days -= 365;
        d.year += 1;
    }
    if (is_leap_year(d.year))
        mon[1] = 29;
    while (days >= mon[d.month - 1]) {
        days -= mon[d.month - 1];
        d.month += 1;
        if (d.month > 12) {
            d.month -= 12;
            d.year += 1;
            if (is_leap_year(d.year))
                mon[1] = 29;
            else
                mon[1] = 28;
        }
    }
    if (days + d.day <= mon[d.month - 1]) {
        d.day += days;
    }
    else {
        d.day += days;
        d.day -= mon[d.month - 1];
        d.month += 1;
    }
    return d;
}

bool date::operator<=(const date& other) {
    if (year < other.year)
        return true;
    else if (year > other.year)
        return false;
    else {
        if (month < other.month)
            return true;
        else if (month > other.month)
            return false;
        else {
            if (day <= other.day)
                return true;
            else
                return false;
        }
    }
}

ostream& operator<<(ostream & os, const date & d) {
    string add_month = "";
    string add_days = "";
    if (d.day < 10)
        add_days = "0";
    if (d.month < 10)
        add_month = "0";
    os << d.year << "." << add_month << d.month
       << "." << add_days << d.day;
    return os;
}

bool is_leap_year(int year) {
    bool is;
    if (year % 100 == 0) {
        if (year % 400 == 0)
            is = true;
        else
            is = false;
    }
    else {
        if (year % 4 == 0)
            is = true;
        else
            is = false;
    }
    return is;
}
