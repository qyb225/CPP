#ifndef BOOK_H
#define BOOK_H
#include "date.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct basicInfo {
    string book_name;
    string book_author;
    string book_ISBN;
    date publish_t;
    basicInfo() {}
    basicInfo(string, string a = "", date t = date(), string i = "");
};

struct loanInfo {
    string borrower;
    string s_id;
    date system_time;
    string record;
    bool overtime;
    loanInfo() {}
    loanInfo(string, string, date, string, bool over = false);
};

class book {
private:
    basicInfo basic_info;
    int num_total;
    int num_loan;
    int num_existence;
    vector<loanInfo> loan_info;
public:
    book();
    book(string);
    book(basicInfo, int);
    void add_loan_info(loanInfo);
    void change_total(int);
    void change_info(basicInfo &);
    void book_loan(string, string, date);
    void book_back(string, string, date, bool);
    int get_total() const;
    int get_loan() const;
    int get_existence() const;
    basicInfo get_basic_info() const;
    vector<loanInfo>& get_loan_info();
    friend bool operator<(const book &, const book &);
    friend ostream& operator<<(ostream &, const book &);
};

ostream& operator<<(ostream &, const basicInfo &);
ostream& operator<<(ostream &, const loanInfo &);
ostream& operator<<(ostream &, const book &);
bool operator<(const book &, const book &);
bool operator<(const basicInfo &, const basicInfo &);

void print_book_title();
void print_book_bottom();
void print_loan_title();
void print_loan_bottom();
#endif