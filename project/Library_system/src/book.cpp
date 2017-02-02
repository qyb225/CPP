#include "book.h"
#include "date.h"
#include "user.h"
#include <string>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

book::book() {
    num_total = 0;
    num_loan = 0;
    num_existence = 0;
}

book::book(basicInfo info, int num) {
    num_total = num;
    num_existence = num;
    num_loan = 0;
    basic_info = info;
}

book::book(string n): basic_info(n) {
    num_total = 0;
    num_loan = 0;
    num_existence = 0;
}

void book::add_loan_info(loanInfo info) {
    loan_info.push_back(info);
}

void book::change_total(int num) {
    num_total = num;
    num_existence = num_total - num_loan;
}

void book::change_info(basicInfo& info) {
    basic_info = info;
}

void book::book_loan(string borrower, string id, date t) {
    ++num_loan;
    --num_existence;
    add_loan_info(loanInfo(borrower, id, t, "Loan", false));
}

void book::book_back(string borrower, string id, date t, bool over) {
    --num_loan;
    ++num_existence;
    add_loan_info(loanInfo(borrower, id, t, "Return", over));
}

int book::get_total() const {
    return num_total;
}

int book::get_loan() const {
    return num_loan;
}

int book::get_existence() const {
    return num_existence;
}

basicInfo book::get_basic_info() const {
    return basic_info;
}

vector<loanInfo>& book::get_loan_info() {
    return loan_info;
}


basicInfo::basicInfo(string name, string auth, date t, string id) {
    book_name = name;
    book_author = auth;
    publish_t = t;
    book_ISBN = id;
}

bool operator<(const basicInfo & a, const basicInfo & b) {
    return a.book_name < b.book_name;
}

loanInfo::loanInfo(string b, string id, date t, string rec, bool over) {
    borrower = b;
    s_id = id;
    system_time = t;
    record = rec;
    overtime = over;
}

ostream& operator<<(ostream & os, const basicInfo & info) {
    os << "|" << setw(20) << info.book_name 
       << "|" << setw(15) << info.book_author
       << "|" << " " << info.publish_t 
       << "|" << setw(10) << info.book_ISBN << "|";
    return os;
}

ostream& operator<<(ostream & os, const book & b) {
    os << b.basic_info
       << setw(6) << b.num_total << "|"
       << setw(6) << b.num_loan << "|"
       << setw(6) << b.num_existence << "|";
    return os;
}

bool operator<(const book & a, const book & b) {
    return a.basic_info < b.basic_info;
}

ostream& operator<<(ostream & os, const loanInfo & info) {
    os << "|" << " " << info.system_time
       << "|" << setw(10) << info.borrower
       << "|" << setw(10) << info.s_id
       << "|" << setw(7) << info.record << "|";
    if (info.overtime)
        os << setw(8) << "Yes" << "|";
    else
        os << setw(8) << "No" << "|";
    return os;
}
