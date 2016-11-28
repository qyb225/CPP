#ifndef USER_H
#define USER_H
#include "date.h"
#include "book.h"
#include "myless.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef multimap<string, book, my_less> ALLBOOKS;

struct borrowed {
    book * a_book;
    date borrow_t;
    date return_t;
    bool overtime;
    static int lim_days;
    borrowed() {}
    borrowed(book &, date &);
};

struct borrowedInfo {
    date date_t;
    string record;
    string book_name;
    bool overtime;
    borrowedInfo() {}
    borrowedInfo(date &, string, string, bool over = false);
};

class user {
private:
    string password;
protected:
    string name;
    string student_ID;
    bool is_black;
    borrowed my_books[50];
    int num_borrowed;
    int num_owe;
    vector<borrowedInfo> borrowed_info;
    static int lim_owe;
public:
    user();
    user(string, string, string);
    void borrow_book(book &, date);
    void return_book(book &, date, int);
    void search_book_info(book &);
    void search_book_info(ALLBOOKS::iterator, ALLBOOKS::iterator);
    void get_borrow_info();
    void black();
    void white();
    void set_password(string);
    bool password_cmp(string);
    bool get_black() const;
    string get_name() const;
    string get_ID() const;
    int get_num_owe();
    int get_lim_owe();
    int get_num_borrowed() const;
    borrowed * get_borrowed_books();
    friend bool operator<(const user &, const user &);
    friend ostream& operator<<(ostream &, const user &);
};

class administrator: public user {
public:
    administrator();
    administrator(string, string, string);
    void black_sb(user &);
    void white_sb(user &);
    void search_book_info(book &);
    void update_book_num(book &);
    void update_book_info(book &);
    void help_borrow(user &, book &);
    void help_return(user &, book &);
    friend ostream& operator<<(ostream &, const administrator &);
};

ostream& operator<<(ostream &, const user &);
ostream& operator<<(ostream &, const administrator &);
ostream& operator<<(ostream &, const borrowed &);
ostream& operator<<(ostream &, const borrowedInfo &);

#endif