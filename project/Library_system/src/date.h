#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class date {
private:
    int year;
    int month;
    int day;
public:
    date();
    date(int, int, int);
    void set_year(int);
    void set_month(int);
    void set_day(int);
    int get_year() const;
    int get_month() const;
    int get_day() const;
    bool operator<=(const date&);
    friend date add_days(date, int);
    friend bool is_leap_year(int);
    friend ostream& operator<<(ostream &, const date &);
};

bool is_leap_year(int);
date add_days(date, int);
ostream& operator<<(ostream &, const date &);

#endif