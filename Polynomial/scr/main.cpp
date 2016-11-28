#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "my_class.h"
#include "my_function.h"
#include "my_class.cpp"
#include "my_function.cpp"

using namespace std;

int main() {
    int choose = -1;

    while (choose != 0) {
        out_table(); 
        cin >> choose;
        switch(choose) {
        case 1: simplification();
            break;
        case 2: add();
            break;
        case 3: subtract();
            break;
        case 4: multiply(); 
            break;
        case 5: derivative(); 
            break;
        case 6: equal_judge(); 
            break;
        case 7: point_calculate();
            break;
        case 8: get_help();
            break;
        case 0: cout << "Goodbye!" << endl;
            system("pause");
            break;
        default: cout << "Input ERROR! Please try again!" << endl;
            system("pause");
            break;
        }
    }
    return 0;
}
