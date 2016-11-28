#include "book.h"
#include "date.h"
#include "user.h"
#include "myless.h"
#include "function.h"
#include <string>
#include <algorithm>
using namespace std;

bool my_less::operator()(string s1, string s2) {
    int l1 = s1.size();
    int l2 = s2.size();
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    int count = 0;
    for (int i = 0; i < l1; ++i) {
        if (s1[i] > 'z' || s1 [i] < 'a') {
            s1.erase(i, 1);
            --i;
            --l1;
        }
    }
    for (int i = 0; i < l2; ++i) {
        if (s2[i] > 'z' || s2 [i] < 'a') {
            s2.erase(i, 1);
            --i;
            --l2;
        }
    }
    if (s1[0] != s2[0])
        return s1 < s2;
    if (l1 < l2) {
        for (int i = 0; i < l1; ++i) {
            if (s2.find(s1[i]) != string::npos)
                ++count;
        }
        if ((double)count / l1 >= 0.75)
            return false;
        else {
            for (int i = 0; i < l1; ++i) {
                if (s1[i] != s2[i]) {
                    if (i == 0)
                        return s1 < s2;
                    if (s1[i] != s2[i - 1] && s1[i] != s2[i + 1])
                        return s1 < s2;
                }
            }
            return false;
        }
    }
    else if (l2 < l1) {
        for (int i = 0; i < l2; ++i) {
            if (s1.find(s2[i]) != string::npos)
                ++count;
        }
        if ((double)count / l2 >= 0.7)
            return false;
        else {
            for (int i = 0; i < l2; ++i) {
                if (s2[i] != s1[i]) {
                    if (i == 0)
                        return s1 < s2;
                    if (s2[i] != s1[i - 1] && s2[i] != s1[i + 1])
                        return s1 < s2;
                }
            }
            return false;
        }
    }
    else {
        for (int i = 0; i < l1; ++i) {
            if (s2.find(s1[i]) != string::npos)
                ++count;
        }
        if ((double)count / l1 >= 0.7)
            return false;
        else {
            for (int i = 1; i < l1 - 1; ++i) {
                if (s1[i] != s2[i]) {
                    if (s1[i] != s2[i - 1] && s1[i] != s2[i + 1])
                        return s1 < s2;
                }
            }
            return false;
        }
    }
    return s1 < s2;
}

