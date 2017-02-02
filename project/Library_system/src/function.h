#ifndef FUNCTION_H
#define FUNCTION_H
#include "book.h"
#include "user.h"
#include "myless.h"
#include <map>
using namespace std;

typedef multimap<string, book, my_less> ALLBOOKS;
typedef map<string, user> USER;
typedef map<string, administrator> ADMIN;
typedef pair<ALLBOOKS::iterator, ALLBOOKS::iterator> PAIR_BOOKS;

void print_start();
void save(ALLBOOKS & books);
void save(USER &); //unfinished
void save(ADMIN &); //unfinished
void load(ALLBOOKS & books);
void load(USER &); //unfinished
void load(ADMIN &); //unfinished
void print_tips(int);
void print_second();
void print_third(int);
void sign_up_user(USER &);
void sign_up_admin(ADMIN &);
void sign_in_user(USER &, ALLBOOKS &);
void sign_in_admin(ADMIN &, USER &, ALLBOOKS &);
void forget_user_password(USER &);
void forget_admin_password(ADMIN &);
void user_operation(user &, ALLBOOKS &);
void admin_operation(administrator &, USER &, ALLBOOKS &);
PAIR_BOOKS search_books(user &, ALLBOOKS &);
void borrow_books(user &, ALLBOOKS &);
void return_books(user &);
void ad_get_loan_info(administrator &, ALLBOOKS &);
void add_new_books(administrator &, ALLBOOKS &);
void modify_book_info(administrator &, ALLBOOKS &);
void help_borrow(administrator &, USER &, ALLBOOKS &);
void help_return(administrator &, USER &, ALLBOOKS &);
void black_sb(administrator &, USER &);
void white_sb(administrator &, USER &);


void print_book_title();
void print_book_bottom();
void print_loan_title();
void print_loan_bottom();

void print_borrow_title();
void print_borrow_bottom();

void print_borec_title();
void print_borec_bottom();


#endif