#include "book.h"
#include "date.h"
#include "user.h"
#include "myless.h"
#include "function.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
typedef multimap<string, book, my_less> ALLBOOKS;

int borrowed::lim_days = 30;
int user::lim_owe = 5;

borrowed::borrowed(book& abook, date & t) {
    borrow_t = t;
    return_t = add_days(t, lim_days);
    a_book = &abook;
    overtime = false;
}

borrowedInfo::borrowedInfo(date& t, string n, string aim, bool over) {
    date_t = t;
    book_name = n;
    record = aim;
    overtime = over;
}

user::user() {
    name = "";
    student_ID = "";
    is_black = false;
    num_borrowed = 0;
    num_owe = 0;
}

user::user(string n, string id, string p) {
    name = n;
    student_ID = id;
    password = p;
    is_black = false;
    num_borrowed = 0;
    num_owe = 0;
}

int user::get_num_borrowed() const {
    return num_borrowed;
}

bool user::password_cmp(string p) {
    return password == p;
}

void user::borrow_book(book& b, date f) {
    string book_n = b.get_basic_info().book_name;
    my_books[num_borrowed] = borrowed(b, f);
    ++num_borrowed;
    borrowed_info.push_back(borrowedInfo(f,book_n , "Borrow"));
    b.book_loan(name, student_ID, f);
}

borrowed* user::get_borrowed_books() {
    if (0 == num_borrowed) {
        cout << "You don't have any books!" << endl;
        return my_books;
    }
    print_borrow_title();
    for (int i = 0; i < num_borrowed; ++i) {
        cout << "|" << setw(3) << i + 1 << " " << my_books[i] << endl;
    }
    print_borrow_bottom();
    return my_books;
}

void user::return_book(book & b, date f, int i) {
    bool over = true;
    string book_n = b.get_basic_info().book_name;
    if (f <= my_books[i].return_t)
        over = false;
    b.book_back(name, student_ID, f, over);
    for (int j = i; j < num_borrowed - 1; ++j) {
        my_books[j] = my_books[j + 1];
    }
    --num_borrowed;
    
    borrowed_info.push_back(borrowedInfo(f, book_n, "Return", over));
    if (over) {
        ++num_owe;
        if (num_owe > lim_owe)
            black();
    }
}

bool user::get_black() const {
    return is_black;
}

void user::black() {
    is_black = true;
}

void user::white() {
    is_black = false;
    num_owe = 0;
}

void user::set_password(string p) {
    password = p;
}

int user::get_num_owe() {
    return num_owe;
}

int user::get_lim_owe() {
    return lim_owe;
}

string user::get_name() const {
    return name;
}
string user::get_ID() const {
    return student_ID;
}

bool operator<(const user & s1, const user & s2) {
    return s1.student_ID < s2.student_ID;
}

administrator::administrator() {}

administrator::administrator(string n, string id, string p): user(n, id, p) {}

void administrator::black_sb(user & sb) {
    sb.black();
}

void administrator::white_sb(user & sb) {
    sb.white();
}

void user::search_book_info(book & b) {
    cout << "Basic Information of << ";
    cout << b.get_basic_info().book_name << " >>:" << endl;
    print_book_title();
    cout << "|  1 ";
    cout << b << endl;
    print_book_bottom();
}

void user::search_book_info(ALLBOOKS::iterator f, ALLBOOKS::iterator l) {
    int count = 0;
    cout << "You may be interested in:" << endl;
    print_book_title(); 
    for (ALLBOOKS::iterator i = f; i != l; ++i) {
        cout << "|" << setw(3) << ++count << " " << i -> second << endl;
    }
    print_book_bottom();
}

void administrator::search_book_info(book & b) {
    vector<loanInfo> vec = b.get_loan_info();
    cout << "Basic Information of << ";
    cout << b.get_basic_info().book_name << " >>:" << endl;
    print_book_title();
    cout << "|  1 "<< b << endl;
    print_book_bottom();
    cout << "Loan Information of << ";
    cout << b.get_basic_info().book_name << " >>:" << endl;
    print_loan_title();
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << endl;
    print_loan_bottom();
}

ostream& operator<<(ostream & os, const user & p) {
    os << "+--------------------------------------+------------+" << endl;
    os << "|           User Information           |   ~~^^^~~  |" << endl;
    os << "|                                      |  + -- -- + |" << endl;
    os << "| Name:" << setw(5) << p.name; 
    os << "                           |  | O   O | |" << endl;
    os << "| Student ID:" << setw(9) << p.student_ID;
    os << "                 |  |   ]   | |" << endl;
    os << "|                                      |  |  ___  | |" << endl;
    os << "| Number of borrowed books:" << setw(3) << p.num_borrowed;
    os << "         |   +_____+  |" << endl;
    os << "|                                      |     | |    |" << endl;
    os << "|                                      +----+---+---+" << endl;
    os << "|                                                   |" << endl;
    os << "+---------------------------------------------------+" << endl;
    return os;
}

ostream& operator<<(ostream & os, const administrator & p) {
    os << "+--------------------------------------+------------+" << endl;
    os << "|      Administrator Information       |   ~~^^^~~  |" << endl;
    os << "|                                      |  + -- -- + |" << endl;
    os << "| Name:" << setw(5) << p.name; 
    os << "                           |  | O   O | |" << endl;
    os << "| Student ID:" << setw(9) << p.student_ID;
    os << "                 |  |   ]   | |" << endl;
    os << "|                                      |  |  ___  | |" << endl;
    os << "| Number of borrowed books:" << setw(3) << p.num_borrowed;
    os << "         |   +_____+  |" << endl;
    os << "|                                      |     | |    |" << endl;
    os << "| Notice: You got high privilege.      +----+---+---+" << endl;
    os << "|                                                   |" << endl;
    os << "+---------------------------------------------------+" << endl;
    return os;
}

ostream& operator<<(ostream & os, const borrowed & b) {
    os << "|" << setw(20) << b.a_book -> get_basic_info().book_name
       << "|" << " " << b.borrow_t
       << "|" << " " << b.return_t << "|";
    if (b.overtime)
        os << setw(8) << "Yes" << "|";
    else
        os << setw(8) << "No" << "|";
    return os;
}

ostream& operator<<(ostream & os, const borrowedInfo & info) {
    os << "|" << " " << info.date_t
       << "|" << setw(20) << info.book_name
       << "|" << setw(7) << info.record << "|";
    if (info.overtime)
        os << setw(8) << "Yes" << "|";
    else
        os << setw(8) << "No" << "|";
    return os;
}

void user::get_borrow_info() {
    vector<borrowedInfo>::iterator i;
    print_borec_title();
    for (i = borrowed_info.begin(); i != borrowed_info.end(); ++i) {
        cout << *i << endl;
    }
    print_borec_bottom();
    return;
}

