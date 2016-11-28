#include "book.h"
#include "date.h"
#include "user.h"
#include "myless.h"
#include "function.h"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <cstdlib>
#include <iomanip>
using namespace std;

typedef multimap<string, book, my_less> ALLBOOKS;
typedef map<string, user> USER;
typedef map<string, administrator> ADMIN;
typedef pair<ALLBOOKS::iterator, ALLBOOKS::iterator> PAIR_BOOKS;


void admin_operation(administrator & me, USER & users, ALLBOOKS & books) {
    int choose = 0;
    string input;
    while (choose != -1) {
        print_third(1);
        cin >> input;
        choose = atoi(input.c_str());
        if (input == "0")
            choose = -1;
        switch (choose) {
        case 1: search_books(me, books);
            system("pause");
            break;
        case 2: borrow_books(me, books);
            break;
        case 3: return_books(me);
            break;
        case 4: cout << me << endl;
            system("pause");
            break;
        case 5: me.get_borrowed_books();
            system("pause");
            break;
        case 6: me.get_borrow_info();
            system("pause");
            break;
        case 7: add_new_books(me, books);
            break;
        case 8: ad_get_loan_info(me, books);
            system("pause");
            break;
        case 9: modify_book_info(me, books);
            break;
        case 10: help_borrow(me, users, books);
            break;
        case 11: help_return(me, users, books);
            break;
        case 12: black_sb(me, users);
            break;
        case 13: white_sb(me, users);
            break;
        case -1:
            break;
        default: print_tips(-4);
            break;
        }
    }
}

void save(USER &) {}
void load(ALLBOOKS & books) {
    ifstream fin("book.dat", ios::in);
    string str_file;
    if (!fin) {
        cerr << "can't" << endl;
        return;
    }
    while (getline(fin, str_file)) {
        int i;
        string name;
        string isbn;
        string author;
        date pub_d;
        int y, m, d;
        int total, loan, ex;
        i = str_file.find_first_of(",");
        name = str_file.substr(0, i);
        str_file.erase(0, i + 1);
        i = str_file.find_first_of(",");
        author = str_file.substr(0, i);
        str_file.erase(0, i + 1);
        i = str_file.find_first_of(",");
        isbn = str_file.substr(0, i);
        str_file.erase(0, i + 1);

        i = str_file.find_first_of(",");
        y = atoi(str_file.substr(0, i).c_str());
        str_file.erase(0, i + 1);

        i = str_file.find_first_of(",");
        m = atoi(str_file.substr(0, i).c_str());
        str_file.erase(0, i + 1);

        i = str_file.find_first_of(",");
        d = atoi(str_file.substr(0, i).c_str());
        str_file.erase(0, i + 1);

        total = atoi(str_file.c_str());

        book cbook(basicInfo(name, author, date(y, m, d), isbn), total);
        books.insert(make_pair(name, cbook));

    }
    fin.close();
}
void load(USER &) {}

void save(ALLBOOKS & books) {
    ofstream fout;

    fout.open("book.dat", ios::out);
    if (!fout) {
        cerr << "Can't open the file!" << endl;
        return;
    }
    for (ALLBOOKS::iterator i = books.begin(); i != books.end(); ++i) {
        fout << i -> second.get_basic_info().book_name << ',';
        fout << i -> second.get_basic_info().book_author << ',';
        fout << i -> second.get_basic_info().book_ISBN << ',';//.c_str(), cbook.get_basic_info().book_ISBN.size());
        fout << i -> second.get_basic_info().publish_t.get_year() << ',';
        fout << i -> second.get_basic_info().publish_t.get_month() << ',';
        fout << i -> second.get_basic_info().publish_t.get_day() << ',';
        fout << i -> second.get_total() << endl;
    }
    fout.close();
}



void save(ADMIN &) {}
void black_sb(administrator & me, USER & users) {
    string id;
    USER::iterator i;
    string choose = "";
    print_tips(17);
    cin >> id;
    i = users.find(id);
    if (i == users.end())
        print_tips(-8);
    else {
        cout << i -> second << endl;
        print_tips(18);
        while (choose != "y" && choose != "Y"
            && choose != "n" && choose != "N") {
            cin >> choose;
            if (choose == "y" || choose == "Y") {
                me.black_sb(i -> second);
                print_tips(0);
            }
        }
    }
}

void load(ADMIN &) {}
void white_sb(administrator & me, USER & users) {
    string id;
    USER::iterator i;
    string choose = "";
    print_tips(17);
    cin >> id;
    i = users.find(id);
    if (i == users.end())
        print_tips(-8);
    else {
        cout << i -> second << endl;
        print_tips(19);
        while (choose != "y" && choose != "Y"
            && choose != "n" && choose != "N") {
            cin >> choose;
            if (choose == "y" || choose == "Y") {
                me.white_sb(i -> second);
                print_tips(0);
            }
        }
    }
}


void help_borrow(administrator & me, USER & users, ALLBOOKS & books) {
    string id;
    USER::iterator i;
    print_tips(17);
    cin >> id;
    i = users.find(id);
    if (i == users.end())
        print_tips(-8);
    else {
        cout << users[id] << endl;
        print_tips(0);
        borrow_books(users[id], books);
    }
}

void help_return(administrator & me, USER & users, ALLBOOKS & books) {
    string id;
    USER::iterator i;
    print_tips(17);
    cin >> id;
    i = users.find(id);
    if (i == users.end())
        print_tips(-8);
    else {
        cout << users[id] << endl;
        print_tips(0);
        return_books(users[id]);
    }
}

void modify_book_info(administrator & me, ALLBOOKS & books) {
    int num;
    int total;
    PAIR_BOOKS p = search_books(me, books);
    if (p.first == books.end() || p.first == p.second)
        return;
    ALLBOOKS::iterator it = p.first;
    print_tips(15);
    cin >> num;
    if (0 == num)
        return;
    for (int i = 0; i < num - 1 && it != p.second; ++i)
        ++it;
    if (it == p.second) {
        print_tips(-4);
        return;
    }
    me.user::search_book_info(it -> second);
    print_tips(13);
    print_tips(14);
    cin >> total;
    if (total >= it -> second.get_loan()) {
        it -> second.change_total(total);
        me.user::search_book_info(it -> second);
        print_tips(0);
    }
    else {
        print_tips(-7);
    }
    return;
}

void print_tips(int n) {
    switch (n) {
    case -9:
        cout << "The user is in the Blacklist! Can't borrow any books!" << endl;
        system("pause");
        break; 
    case -8:
        cout << "Can't find this user!" << endl;
        break;
    case -7:
        cout << "Number limited!" << endl;
        system("pause");
        break;
    case -6:
        cout << "Can't find this book!" << endl;
        system("pause");
        break;
    case -5:
        cout << "Goodbye!" << endl;
        system("pause");
        break;
    case -4:
        cout << "You can't choose this one!" << endl;
        system("pause");
        break;
    case -3:
        cout << "Can't confirm your identity! You can't Modify password!" << endl;
        system("pause");
        break;
    case -2:
        cout << "ERROR! Wrong Account Number or Password!" << endl;
        system("pause");
        break;
    case -1:
        cout << "ERROR! Two password is different!" << endl;
        system("pause");
        break;
    case 0:
        cout << "Completed!" << endl;
        system("pause");
        break;
    case 1:
        cout << "Please enter your Name..." << endl;
        break;
    case 2:
        cout << "Please enter your Student ID..." << endl;
        break;
    case 3:
        cout << "Please enter the Password..." << endl;
        break;
    case 4:
        cout << "Please enter the Password again..." << endl;
        break;
    case 5:
        cout << "Your Account Number is your Student ID" << endl;
        break;
    case 6:
        cout << "Identity confirmed!" << endl;
        system("pause");
        break;
    case 7:
        cout << "Please enter the number you want to borrow..." << endl;
        cout << "Tip: Enter 0 to back to your HomePage" << endl;
        break;
    case 8:
        cout << "Please enter the number you want to return..." << endl;
        cout << "Tip: Enter 0 to back to your HomePage" << endl;
        break;
    case 9:
        cout << "Please enter the Book Name..." << endl;
        break;
    case 10:
        cout << "Please enter the Author..." << endl;
        break;
    case 11:
        cout << "Please enter the publish date...(Eg:2001.1.1)" << endl;
        break;
    case 12:
        cout << "Please enter the ISBN of this book..." << endl;
        break;
    case 13:
        cout << "Please enter the total number..." << endl;
        break;
    case 14:
        cout << "Notice: The new total number should >= number of loan books" << endl;
        break;
    case 15:
        cout << "Please choose a book..." << endl;
        cout << "Tip: Enter 0 to back to your HomePage" << endl;
        break;
    case 16:
        cout << "Please enter the number of book you wanna choose..." << endl;
        cout << "Tip: Enter 0 to back to your HomePage" << endl;
        break;
    case 17:
        cout << "Please enter the student ID..." << endl;
        break;
    case 18:
        cout << "Notice: The user in the blacklist can't borrow books!" << endl;
        cout << "Are you sure you want to do this? (y/n)" << endl;
        break;
    case 19:
        cout << "The owing record of this user will be cleared." << endl;
        cout << "Are you sure you want to pull this user OUT the blacklist? (y/n)" << endl;
        break;
    }
}
void print_third(int n) {
    if (0 == n) {
        cout << "+----------------------------------------+" << endl;
        cout << "|                                        |" << endl;
        cout << "| 1. Search Books                        |" << endl;
        cout << "| 2. Borrow Books                        |" << endl;
        cout << "| 3. Return Books                        |" << endl;
        cout << "| 4. Personal Information                |" << endl;
        cout << "| 5. Books in My Hand Now                |" << endl;
        cout << "| 6. History Borrowed Record             |" << endl;
        cout << "|                                        |" << endl;
        cout << "| 0. Log off                             |" << endl;
        cout << "|                                        |" << endl;
        cout << "+----------------------------------------+" << endl;
    }
    else if (1 == n) {
        cout << "+----------------------------------------+" << endl;
        cout << "|                                        |" << endl;
        cout << "| 1. Search Books                        |" << endl;
        cout << "| 2. Borrow Books                        |" << endl;
        cout << "| 3. Return Books                        |" << endl;
        cout << "| 4. Personal Information                |" << endl;
        cout << "| 5. Books in My Hand Now                |" << endl;
        cout << "| 6. History Borrowed Record             |" << endl;
        cout << "|                                        |" << endl;
        cout << "|  ----  Administrator Privilege  ----   |" << endl;
        cout << "|                                        |" << endl;
        cout << "| 7.  Add New Kind of Books              |" << endl;
        cout << "| 8.  Search Books Loan Records          |" << endl;
        cout << "| 9.  Change the Number of Books         |" << endl;
        cout << "| 10. Help Common User Borrow Books      |" << endl;
        cout << "| 11. Help Common User Return Books      |" << endl;
        cout << "| 12. Pull Someone into the Blacklist    |" << endl;
        cout << "| 13. Pull Someone out the Blacklist     |" << endl;
        cout << "|                                        |" << endl;
        cout << "| 0.  Log off                            |" << endl;
        cout << "|                                        |" << endl;
        cout << "+----------------------------------------+" << endl;
    }
}


void add_new_books(administrator & me, ALLBOOKS & books) {
    string name;
    string isbn;
    string publish;
    string author;
    int total, d[3];
    int i = 0, j = 0;
    print_tips(9);
    getline(cin, name);
    getline(cin, name);
    print_tips(10);
    getline(cin, author);
    //getline(cin, author);
    print_tips(11);
    cin >> publish;
    while (i < publish.size()) {
        if (publish[i] == '.') {
            d[j++] = atoi(publish.substr(0, i).c_str());
            publish.erase(0, i + 1);
            i = 0;
        }
        if (i == publish.size() - 1) {
            d[j++] = atoi(publish.c_str());
            break;
        }
        ++i;
    }
    print_tips(12);
    cin >> isbn;
    print_tips(13);
    cin >> total;
    book new_book(basicInfo(name, author, date(d[0], d[1], d[2]), isbn), total);
    books.insert(make_pair(name, new_book));
    me.user::search_book_info(new_book);
    print_tips(0);
    return;
}


void user_operation(user & me, ALLBOOKS & books) {
    int choose = 0;
    string input;
    while (choose != -1) {
        print_third(0);
        cin >> input;
        choose = atoi(input.c_str());
        if (input == "0")
            choose = -1;
        switch (choose) {
        case 1: search_books(me, books);
            system("pause");
            break;
        case 2: borrow_books(me, books);
            break;
        case 3: return_books(me);
            break;
        case 4: cout << me << endl;
            system("pause");
            break;
        case 5: me.get_borrowed_books();
            system("pause");
            break;
        case 6: me.get_borrow_info();
            system("pause");
            break;
        case -1:
            break;
        default: print_tips(-4);
            break;
        }
    }
}

void ad_get_loan_info(administrator & me, ALLBOOKS & books) {
    int num;
    PAIR_BOOKS p = search_books(me, books);
    if (p.first == books.end() || p.first == p.second)
        return;
    ALLBOOKS::iterator it = p.first;
    print_tips(16);
    cin >> num;
    if (0 == num)
        return;
    for (int i = 0; i < num - 1 && it != p.second; ++i)
        ++it;
    if (it == p.second)
        print_tips(-4);
    else {
        me.search_book_info(it -> second);
    }
    return;
}

void return_books(user & me) {
    int num;
    date now;
    borrowed * pbook = NULL;
    pbook = me.get_borrowed_books(); //all the book I have!
    print_tips(8);
    cin >> num;
    if (num == 0)
        return;
    --num;
    me.return_book(*((pbook + num) -> a_book),now, num );
    print_tips(0);
    return;
}

void borrow_books(user & me, ALLBOOKS & books) {
    int num;
    if (me.get_black()) {
        print_tips(-9);
        return;
    }
    PAIR_BOOKS p = search_books(me, books);
    if (p.first == books.end() || p.first == p.second)
        return;
    ALLBOOKS::iterator it = p.first;
    print_tips(7);
    cin >> num;
    if (0 == num)
        return;
    for (int i = 0; i < num - 1 && it != p.second; ++i)
        ++it;
    if (it == p.second) {
        print_tips(-4);
        return;
    }
    else {
        if (me.get_num_borrowed() < 50) {
            if (it -> second.get_existence() > 0) {
                me.borrow_book(it -> second, date());
                //it -> second.book_loan(me.get_name(), me.get_ID(), date());
                print_tips(0);
            }
            else
                print_tips(-7);
        }
        else 
            print_tips(-7);
    }
}


PAIR_BOOKS search_books(user & me, ALLBOOKS & books) {
    string name;
    PAIR_BOOKS p;
    print_tips(9);
    getline(cin, name);
    getline(cin, name);
    p = books.equal_range(name);
    if (p.first != books.end() && p.first != p.second) {
        me.search_book_info(p.first, p.second);
    }
    else
        print_tips(-6);
    return p;
}


void print_start() {
    cout << endl << "+-------------------------------------------------------------+" << endl;
    cout << "|      Welcome to the Main Menu of SYSU library system!       |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "|                      +               +                      |" << endl;
    cout << "|     _      +        |||             |||        +      _     |" << endl;
    cout << "|    |||    |||      =====           =====      |||    |||    |" << endl;
    cout << "|   = = ==== = =======| |=============| |======= = ==== = =   |" << endl;
    cout << "|    | |    | |       | |   S Y S U   | |       | |    | |    |" << endl;
    cout << "|   =| |====| |=======| |=============| |=======| |====| |=   |" << endl;
    cout << "|    | |/  \\| |/     \\| |/           \\| |/     \\| |/  \\| |    |" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "|    | |    | |       | |             | |       | |    | |    |" << endl;
    }
    cout << "|   _| |_  _| |_     _| |_           _| |_     _| |_  _| |_   |" << endl;
    cout << "|   |||||  |||||     |||||           |||||     |||||  |||||   |" << endl;
    cout << "|  =========================================================  |" << endl;
    cout << "| =========================================================== |" << endl;
    cout << "|=============================================================|" << endl;
    cout << "|                                                             |" << endl; 
    cout << "|      Please choose the type                                 |" << endl;
    cout << "|                                                             |" << endl;
    cout << "|      1. common user                                         |" << endl;
    cout << "|      2. administrator                                       |" << endl;
    cout << "|                                                             |" << endl;
    cout << "|      0. Quit                                                |" << endl;
    cout << "|                                                             |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
}

void print_second() {
    cout << "+---------------------------------+" << endl;
    cout << "|                                 |" << endl;
    cout << "| 1. Sign in                      |" << endl;
    cout << "| 2. Sign up                      |" << endl;
    cout << "| 3. Foreget password             |" << endl;
    cout << "|                                 |" << endl;
    cout << "| 0. Back to main menu            |" << endl;
    cout << "|                                 |" << endl;
    cout << "+---------------------------------+" << endl;
}

void sign_up_user(USER & users) {
    string name, id, password, password_r;
    char c;
    print_tips(1);
    cin >> name;
    print_tips(2);
    cin >> id;
    print_tips(3);
    while ((c = getch()) != '\r') {
        if (c =='\b') {
            putch(c);
            putch(' ');
            putch(c);
            if (!password.empty()) 
                password = password.erase(password.size() - 1, 1);
        }
        else if (isprint(c)) {
            putch('*');
            password += c;
        }
    }
    cout << endl;
    print_tips(4);
    while ((c = getch()) != '\r') {
        if (c =='\b') {
            putch(c);
            putch(' ');
            putch(c);
            if (!password_r.empty()) 
                password_r = password_r.erase(password_r.size() - 1,1);
        }
        else if (isprint(c)) {
            putch('*');
            password_r += c;
        }
    }
    cout << endl;
    if (password == password_r) {
        users.insert(make_pair(id, user(name, id, password)));
        print_tips(0);
        print_tips(5);
    }
    else
        print_tips(-1);
    return;
}
void sign_up_admin(ADMIN & admins) {
    string name, id, password, password_r;
    char c;
    print_tips(1);
    cin >> name;
    print_tips(2);
    cin >> id;
    print_tips(3);
    while ((c = getch()) != '\r') {
        if (c =='\b') {
            putch(c);
            putch(' ');
            putch(c);
            if (!password.empty()) 
                password = password.erase(password.size() - 1, 1);
        }
        else if (isprint(c)) {
            putch('*');
            password += c;
        }
    }
    cout << endl;
    print_tips(4);
    while ((c = getch()) != '\r') {
        if (c =='\b') {
            putch(c);
            putch(' ');
            putch(c);
            if (!password_r.empty()) 
                password_r = password_r.erase(password_r.size()-1,1);
        }
        else if (isprint(c)) {
            putch('*');
            password_r += c;
        }
    }
    cout << endl;
    if (password == password_r) {
        admins.insert(make_pair(id, administrator(name, id, password)));
        print_tips(0);
        print_tips(5);
    }
    else
        print_tips(-1);
    return;
}

void sign_in_user(USER & users, ALLBOOKS & books) {
    string id, password;
    USER::iterator i;
    char c;
    print_tips(2);
    cin >> id;
    i = users.find(id);
    if (i != users.end()) {
        print_tips(3);
        while ((c = getch()) != '\r') {
            if (c =='\b') {
                putch(c);
                putch(' ');
                putch(c);
                if (!password.empty()) 
                    password = password.erase(password.size() -1, 1);
            }
            else if (isprint(c)) {
                putch('*');
                password += c;
            }
        }
        cout << endl;
        if (users[id].password_cmp(password)) {
            print_tips(0);
            user_operation(i -> second, books);
        }
        else
            print_tips(-2);
    }
    else
        print_tips(-2);
    return;
}


void sign_in_admin(ADMIN & admins, USER & users, ALLBOOKS & books) {
    string id, password;
    ADMIN::iterator i;
    char c;
    print_tips(2);
    cin >> id;
    i = admins.find(id);
    if (i != admins.end()) {
        print_tips(3);
        while ((c = getch()) != '\r') {
            if (c =='\b') {
                putch(c);
                putch(' ');
                putch(c);
                if (!password.empty())
                    password = password.erase(password.size() -1, 1);
            }
            else if (isprint(c)) {
                putch('*');
                password += c;
            }
        }
        cout << endl;
        if (admins[id].password_cmp(password)) {
            print_tips(0);
            admin_operation(i -> second, users, books);
        }
        else
            print_tips(-2);
    }
    else
        print_tips(-2);
    return;
}

void forget_user_password(USER & users) {
    string id, password, name, password_r;
    USER::iterator i;
    char c;
    print_tips(2);
    cin >> id;
    i = users.find(id);
    if (i != users.end()) {
        print_tips(1);
        cin >> name;
        if ((i -> second).get_name() == name) {
            print_tips(6);
            print_tips(3);
            while ((c = getch()) != '\r') {
                if (c =='\b') {
                    putch(c);
                    putch(' ');
                    putch(c);
                    if (!password.empty()) 
                        password = password.erase(password.size()-1,1);
                }
                else if (isprint(c)) {
                    putch('*');
                    password += c;
                }
            }   
            cout << endl;
            print_tips(4);
            while ((c = getch()) != '\r') {
                if (c =='\b') {
                    putch(c);
                    putch(' ');
                    putch(c);
                    if (!password_r.empty()) 
                        password_r = password_r.erase(password_r.size()-1,1);
                }
                else if (isprint(c)) {
                    putch('*');
                    password_r += c;
                }
            }
            cout << endl;
            if (password == password_r) {
                (i -> second).set_password(password);
                print_tips(0);
            }
            else
                print_tips(-1);
        }
        else
            print_tips(-3);
    }
    else
        print_tips(-2);
}

void forget_admin_password(ADMIN & admins) {
    string id, password, name, password_r;
    ADMIN::iterator i;
    char c;
    print_tips(2);
    cin >> id;
    i = admins.find(id);
    if (i != admins.end()) {
        print_tips(1);
        cin >> name;
        if ((i -> second).get_name() == name) {
            print_tips(6);
            print_tips(3);
            while ((c = getch()) != '\r') {
                if (c =='\b') {
                    putch(c);
                    putch(' ');
                    putch(c);
                    if (!password.empty()) 
                        password = password.erase(password.size() - 1, 1);
                }
                else if (isprint(c)) {
                    putch('*');
                    password += c;
                }
            }   
            cout << endl;
            print_tips(4);
            while ((c = getch()) != '\r') {
                if (c =='\b') {
                    putch(c);
                    putch(' ');
                    putch(c);
                    if (!password_r.empty()) 
                        password_r = password_r.erase(password_r.size() - 1, 1);
                }
                else if (isprint(c)) {
                    putch('*');
                    password_r += c;
                }
            }
            cout << endl;
            if (password == password_r) {
                (i -> second).set_password(password);
                print_tips(0);
            }
            else
                print_tips(-1);
        }
        else
            print_tips(-3);
    }
    else
        print_tips(-2);
}

void print_loan_title() {
    cout << "+-----------+----------+----------+-------+--------+" << endl;
    cout << "|" << setw(11) << "Date"
         << "|" << setw(10) << "Borrower"
         << "|" << setw(10) << "Student ID"
         << "|" << setw(7) << "Record"
         << "|" << setw(8) << "Overtime" << "|" << endl;
    cout << "+-----------+----------+----------+-------+--------+" << endl;
}

void print_loan_bottom() {
    cout << "+-----------+----------+----------+-------+--------+" << endl;
}

void print_book_title() {
    cout << "+----+--------------------+---------------+";
    cout << "-----------+----------+------+------+------+" << endl;
    cout << "| No."
         << "|" << setw(20) << "Book Name"
         << "|" << setw(15) << "Author"
         << "|" << setw(11) << "Publish"
         << "|" << setw(10) << "ISBN" 
         << "|" << setw(6) << "Total"
         << "|" << setw(6) << "Loan"
         << "|" << setw(6) << "Rest" << "|" << endl;
    cout << "+----+--------------------+---------------+";
    cout << "-----------+----------+------+------+------+" << endl;
}
void print_book_bottom() {
    cout << "+----+--------------------+---------------+";
    cout << "-----------+----------+------+------+------+" << endl;
}

void print_borrow_title() {
    cout << "+----+--------------------+-----------+-----------+"
         << "--------+" << endl;
    cout << "| No.|" << setw(20) << "Book Name"
         << "|" << setw(11) << "Borrow Date"
         << "|" << setw(11) << "Date Limit"
         << "|" << setw(8) << "Overtime" << "|" << endl;
    cout << "+----+--------------------+-----------+-----------+"
         << "--------+" << endl;
}

void print_borrow_bottom() {
    cout << "+----+--------------------+-----------+-----------+"
         << "--------+" << endl;
}

void print_borec_title() {
    cout << "+-----------+--------------------+"
         << "-------+--------+" << endl;
    cout << "|" << setw(11) << "Time" 
         << "|" << setw(20) << "Book Name"
         << "|" << setw(7) << "Record"
         << "|" << setw(8) << "Overtime" << "|" << endl;
    cout << "+-----------+--------------------+"
         << "-------+--------+" << endl;
}

void print_borec_bottom() {
    cout << "+-----------+--------------------+"
         << "-------+--------+" << endl;
}
