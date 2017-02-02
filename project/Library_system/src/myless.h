#ifndef MYLESS_H
#define MYLESS_H
#include <string>
using namespace std;
class my_less {
public:
    bool operator()(string s1, string s2);
};


#endif