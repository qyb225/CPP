#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <conio.h>
#include <cctype>
#include "book.h"
#include "date.h"
#include "user.h"
#include "myless.h"
#include "function.h"
#include "book.cpp"
#include "date.cpp"
#include "user.cpp"
#include "myless.cpp"
#include "function.cpp"

using namespace std;

typedef multimap<string, book, my_less> ALLBOOKS;
typedef map<string, user> USER;
typedef map<string, administrator> ADMIN;

int main() {

    ALLBOOKS books;
    USER users;
    ADMIN admins;
    int choose0 = 0;
    string input;

    load(books);
    load(users); //unfinished
    load(admins); //unfinished
    while (choose0 != -1) {
        int choose1;
        print_start();
        cin >> input;
        choose0 = atoi(input.c_str());
        if (input == "0")
            choose0 = -1;
        if (1 == choose0) {
            print_second();
            cin >> input;
            choose1 = atoi(input.c_str());
            if (input == "0")
                choose1 = -1;
            switch (choose1) {
            case 1: sign_in_user(users, books);
                break;
            case 2: sign_up_user(users);
                break;
            case 3: forget_user_password(users);
                break;
            case -1:
                break;
            default: print_tips(-4);
                break;     
            }
        }
        else if (2 == choose0) {
            print_second();
            cin >> input;
            choose1 = atoi(input.c_str());
            if (input == "0")
                choose1 = -1;
            switch (choose1) {
            case 1: sign_in_admin(admins, users, books);
                break;
            case 2: sign_up_admin(admins);
                break;
            case 3: forget_admin_password(admins);
                break;
            case -1://save(users); save(admins);
                break;
            default: print_tips(-4);
                break;    
            }
        }
        else if (-1 == choose0)
            print_tips(-5);
        else
            print_tips(-4);
    }
    save(books); 
    save(users); //unfinished
    save(admins); //unfinished
    return 0;
}