using namespace std;

// No.1: output functions.

void out_table() {

    cout << endl;
    cout << "+-------------------------------------------------------+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                 Polynomial Calculator                 |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|   Enter 1 to smplify a polynomial.           p        |" << endl;
    cout << "|   Enter 2 to add 2 polynomials.              p + q    |" << endl;
    cout << "|   Enter 3 to subtract 2 polynomials.         p - q    |" << endl;
    cout << "|   Enter 4 to multiply 2 polynomials.         p * q    |" << endl;
    cout << "|   Enter 5 to get derivative of a polynomial. p'       |" << endl;
    cout << "|   Enter 6 to judge whether p,q are equal.    p == q ? |" << endl;
    cout << "|   Enter 7 to calculate the value when x = n. p(n)     |" << endl;
    cout << "|   Enter 8 to help.                                    |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                              +------------------------+" << endl;
    cout << "|   Enter 0 to QUIT.           |         NOTICE:        |" << endl;
    cout << "|                              |  You can enter 'B'     |" << endl;
    cout << "|   p, q: polynomial.          |  to back to the MENU   |" << endl;
    cout << "|                              |  anytime you like!     |" << endl;
    cout << "|                              |                        |" << endl;
    cout << "+------------------------------+------------------------+" << endl;
    cout << endl << "Enter the number you want to choose." << endl;
    return;
}

void get_help() {

    cout << "+--------------------------------------------------------+" << endl;
    cout << "|                   Introtuction                         |" << endl;
    cout << "|                                                        |" << endl;
    cout << "| 1. Smplify function:                                   |" << endl;
    cout << "| When you choose function 1, we will ask you to input a |" << endl;
    cout << "| polynomial. You just need to input a legal polynomial  |" << endl;
    cout << "| form. You don't need to input a simplified or sorted   |" << endl;
    cout << "| polynomial. Then the calculator will return you a      |" << endl;
    cout << "| simplified and sorted polynomial.                      |" << endl;
    cout << "|                                                        |" << endl;
    cout << "| 2. Add function (p + q):                               |" << endl;
    cout << "| When you choose function 2, we will ask you to input 2 |" << endl;
    cout << "| polynomials. You need to make sure that your input are |" << endl;
    cout << "| legal. Then the calculator will return the addition of |" << endl;
    cout << "| these two polynomial.                                  |" << endl;
    cout << "|                                                        |" << endl;
    cout << "| 3. Subtract function (p - q):                          |" << endl;
    cout << "| When you choose function 3, we will ask you to input 2 |" << endl;
    cout << "| polynomials. You need to make sure that your input are |" << endl;
    cout << "| legal. Then the calculator will return the subtraction |" << endl;
    cout << "| of these two polynomial.                               |" << endl;
    cout << "|                                                        |" << endl;
    cout << "| 4. Multiply function (p * q):                          |" << endl;
    cout << "| When you choose function 4, we will ask you to input 2 |" << endl;
    cout << "| polynomials. You need to make sure that your input are |" << endl;
    cout << "| legal. Then the calculator will return the multiplicat-|" << endl;
    cout << "| ion of these two polynomial. Notice: if one of your in-|" << endl;
    cout << "| put is (c, 0). You will get the polynomial of c * q,   |" << endl;
    cout << "| which 'c' is a constant.                               |" << endl;
    cout << "|                                                        |" << endl;
    cout << "| 5. Derivative function (p'):                           |" << endl;
    cout << "| When you choose function 5, we will ask you to input a |" << endl;
    cout << "| polynomial. You need to make sure that your input are  |" << endl;
    cout << "| legal. Then you will get the derivative of it.         |" << endl;
    cout << "|                                                        |" << endl;
    cout << "| 6. Equal-judging function (p == q ?)                   |" << endl;
    cout << "| When you choose function 6, we will ask you to input 2 |" << endl;
    cout << "| polynomials. You need to make sure that your input are |" << endl;
    cout << "| legal. Then you will know whether these two polynomial |" << endl;
    cout << "| are equal. If they are equal, you will get the sorted  |" << endl;
    cout << "| and simplified polynomial of them. If they aren't equal|" << endl;
    cout << "| , you will get the sorted and simplified polynomials of|" << endl;
    cout << "| them.                                                  |" << endl;
    cout << "|                                                        |" << endl;
    cout << "|* * * * * * * * * * * * * * * *  * * * * * * * * * * * *|" << endl;
    cout << "| Notice: the input must be legal and you can't input    |" << endl;
    cout << "| any space.                                             |" << endl;
    cout << "| Example 1. (3,2)(2,1) means 3x ^ 2 + 2x                |" << endl;
    cout << "| Example 2. (2,3)(2,2)(3,0) means 2x ^ 3 + 2x ^ 2  + 3  |" << endl;
    cout << "|* * * * * * * * * * * * * * * * * * * * * * * * *  * * *|" << endl;
    cout << "+--------------------------------------------------------+" << endl;

    system("pause");
    return;
}

inline void out_tips() {

    cout << endl << "Input standard: (a,b)(c,d)..." << endl;
    cout << "Notice: the input must be legal. You can't input space." << endl;
    cout << "E.g. (3,2)(2,1) means 3x ^ 2 + 2x" << endl << endl;

    system("pause");
    return;
}

void out_polynomial(polynomial * p, int n) {

    if (0 == n) {
        cout << 0 << endl << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        out_monomial(p, i);
    }

    cout << endl << endl;
    return;
}

void out_monomial(polynomial * p, int i) {

    if (0 == i) {

        if (1 != abs(p[i].get_coefficient())) {
            cout << p[i].get_coefficient();
        }
        else if (-1 == p[i].get_coefficient()) {
            cout << "-";
        }
        if (1 == p[i].get_level()) {
            cout << "x ";
        }
        else if (0 != p[i].get_level()) {
            cout << "x ^ " << p[i].get_level() << ' ';
        }
        else if (1 == abs(p[i].get_coefficient())) {
            cout << "1 ";
        }
        else {
            cout << " ";
        }
    }
    else {

        if (1 != abs(p[i].get_coefficient())) {

            if (p[i].get_coefficient() > 0) {
                cout << "+ " << p[i].get_coefficient();
            }
            else {
                cout << "- " << -1 * p[i].get_coefficient();
            }
        }
        else if (-1 == p[i].get_coefficient()) {
            cout << "- ";
        }
        else {
            cout << "+ ";
        }
        if (1 == p[i].get_level()) {
            cout << "x ";
        }
        else if (0 != p[i].get_level()) {
            cout << "x ^ " << p[i].get_level() << ' ';
        }
        else if (1 == abs(p[i].get_coefficient())) {
            cout << "1 ";
        }
        else {
            cout << " ";
        }
    }
    return;
}


// No.2: Input analysing functions.

polynomial * polynomial_analyse(int & count) {

    string str;
    int coefficient, level;
    polynomial * p = NULL;

    cin >> str;
    if (str.length() == 1 && str[0] == 'B') {
        return p;
    }
    cout << "Input completely!" << endl;
    system("pause");

    count = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ',') {
            count += 1;
        }
    }

    p = new polynomial[count];
    count = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ',') {
            coefficient = coefficient_analyse(str, i);
            level = level_analyse(str, i);            
            p[count].set_coefficient(coefficient);
            p[count].set_level(level);
            count += 1;
        }
    }
    return p;
}

int coefficient_analyse(string str, int i) {

    int count = 0;
    int total = 0;
    int j = 1;

    while (str[i - j] != '(') {
        if (str[i - j] == '-') {
            total = total * -1;
        }
        else {
            total += (str[i - j] - '0') * pow10(count++);
        }
        j++;
    }

    return total;
}

int level_analyse(string str, int i) {

    int count = 0;
    int total = 0;
    int j = 1;
    int k = 0;
    int l = 1;

    if (str[i + 1] == '-') {
        k = 1;
        l = -1;
    }

    while (str[i + j + k] != ')') {
        j++;
    }

    while (j > 1) {
        total += (str[i + j - 1 + k] - '0') * pow10(count++);
        j--;
    }

    total = total * l;
    return total;
}

int pow10(int n) {

    if (n == 0) {
        return 1;
    }

    else {
        return 10 * pow10(n - 1);
    }
}


// No.3: Smplify functions.

void simplification() {

    polynomial * p = NULL;
    int count = 0;

    cout << "+--------------------------------------------------+" << endl;
    cout << "| Please enter the polynomial you want to smplify. |" << endl;
    cout << "+--------------------------------------------------+" << endl;
    
    out_tips();
    p = polynomial_analyse(count);

    if (p == NULL) {
        return;
    }

    polynomial_simple(p, count);

    cout << endl << "The answer is:" << endl;
    out_polynomial(p, count);

    delete [] p;

    system("pause");
    return;
}

void polynomial_simple(polynomial * p, int & count) {

    polynomial_sort(p, count);
    polynomial_alike_packing(p, count);
    pop_zero(p, count);

    return; 
}

void polynomial_sort(polynomial * p, int n) {

    polynomial swap;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].get_level() < p[j + 1].get_level()) {
                swap = p[j];
                p[j] = p[j + 1];
                p[j + 1] = swap;
            }
        }
    }
    return;
}

void polynomial_alike_packing(polynomial * p, int & count) {

    for (int i = 0; i < count - 1; i++) {
        if ((p + i) -> get_level() == (p + i + 1) -> get_level()) {
            (p + i) -> set_coefficient((p + i) -> get_coefficient() + (p + i + 1) -> get_coefficient());
            for (int j = i + 1; j < count; j++) {
                p[j] = p[j + 1];
            }
            count -= 1;
            i -= 1;
        }
    }
    return; 
}

void pop_zero(polynomial * p, int & count) {

    for (int i = 0; i < count; i++) {
        if (0 == p[i].get_coefficient()) {
            for (int j = i; j < count - 1; j++) {
                p[j] = p[j + 1];
            }
            i--;
            count--;
        }
    }
    return;
}


// No.4: Add functions.

void add() {

    polynomial * p = NULL, *q = NULL;
    polynomial * ans = NULL;
    int count_p = 0, count_q = 0;
    int count_ans = 0;

    cout << "+---------------------+" << endl;
    cout << "| You will get p + q. |" << endl;
    cout << "+---------------------+" << endl;
    out_tips();
    cout << "First, please enter the polynomial p." << endl;
    p = polynomial_analyse(count_p);
    if (p == NULL) {
        return;
    }
    cout << "Next, please enter the polynomial q." << endl;
    q = polynomial_analyse(count_q);
    if (q == NULL) {
        delete [] p;
        return;
    }

    count_ans = count_q + count_p;
    ans = new polynomial[count_ans];
    polynomial_add(p, count_p, q, count_q, ans);

    delete [] p;
    delete [] q;

    polynomial_simple(ans, count_ans);

    cout << endl << "The answer is:" << endl;
    out_polynomial(ans, count_ans);

    delete [] ans;

    system("pause");
    return;
}

void polynomial_add(polynomial * p, int count_p, polynomial * q, int count_q, polynomial * ans) {

    int i = 0;

    while (i < count_p + count_q) {
        if (i < count_p) {
            ans[i] = p[i];
        }
        else {
            ans[i] = q[i - count_p];
        }
        i++;
    }
    return;
}


// No.5: Subtract functions.

void subtract() {

    polynomial * p = NULL, *q = NULL;
    polynomial * ans = NULL;
    int count_p = 0, count_q = 0;
    int count_ans = 0;

    cout << "+---------------------+" << endl;
    cout << "| You will get p - q. |" << endl;
    cout << "+---------------------+" << endl;
    out_tips();
    cout << "First, please enter the polynomial p." << endl;
    p = polynomial_analyse(count_p);
    if (p == NULL) {
        return;
    }
    cout << "Next, please enter the polynomial q." << endl;
    q = polynomial_analyse(count_q);
    if (q == NULL) {
        delete [] p;
        return;
    }

    count_ans = count_q + count_p;
    ans = new polynomial[count_ans];
    polynomial_subtract(p, count_p, q, count_q, ans);

    delete [] p;
    delete [] q;

    polynomial_simple(ans, count_ans);

    cout << endl << "The answer is:" << endl;
    out_polynomial(ans, count_ans);

    delete [] ans;

    system("pause");
    return;
}

void polynomial_subtract(polynomial * p, int count_p, polynomial * q, int count_q, polynomial * ans) {
    int i = 0;
    while (i < count_p + count_q) {
        if (i < count_p) {
            ans[i] = p[i];
        }
        else {
            ans[i].set_coefficient(-1 * q[i - count_p].get_coefficient());
            ans[i].set_level(q[i - count_p].get_level());
        }
        i++;
    }
    return;
}


// No.6: Multiply functions.

void multiply() {

    polynomial * p = NULL, *q = NULL;
    polynomial * ans = NULL;
    int count_p = 0, count_q = 0;
    int count_ans = 0;

    cout << "+---------------------+" << endl;
    cout << "| You will get p * q. |" << endl;
    cout << "+---------------------+" << endl;
    out_tips();
    cout << "First, please enter the polynomial p." << endl;
    p = polynomial_analyse(count_p);
    if (p == NULL) {
        return;
    }
    cout << "Next, please enter the polynomial q." << endl;
    q = polynomial_analyse(count_q);
    if (q == NULL) {
        delete [] p;
        return;
    }

    count_ans = count_q * count_p;
    ans = new polynomial[count_ans];
    polynomial_multiply(p, count_p, q, count_q, ans);

    delete [] p;
    delete [] q;

    polynomial_simple(ans, count_ans);

    cout << endl << "The answer is:" << endl;
    out_polynomial(ans, count_ans);

    delete [] ans;

    system("pause");
    return;
}

void polynomial_multiply(polynomial * p, int count_p, polynomial * q, int count_q, polynomial * ans) {

    int i = 0;

    for (int j = 0; j < count_p; j++) {
        for (int k = 0; k < count_q; k++) {
            ans[i].set_coefficient(p[j].get_coefficient() * q[k].get_coefficient());
            ans[i].set_level(p[j].get_level() + q[k].get_level());
            i++;
        }
    }
    return;
}


// No.7: Derivative functions.

void derivative() {

    polynomial *p = NULL, *ans = NULL;
    int count_p = 0, count_ans;

    cout << "+-----------------------------------+" << endl;
    cout << "| You will get the derivative of p. |" << endl;
    cout << "+-----------------------------------+" << endl;
    out_tips();
    cout << "Please enter the polynomial p." << endl;
    p = polynomial_analyse(count_p);
    if (p == NULL) {
        return;
    }

    count_ans = count_p;
    ans = new polynomial[count_ans];
    polynomial_derivative(p, count_ans, ans);
    polynomial_simple(ans, count_ans);

    cout << endl << "The answer is:" << endl;
    out_polynomial(ans, count_ans);

    delete [] p;
    delete [] ans;

    system("pause");
    return;
}

void polynomial_derivative(polynomial * p, int n, polynomial * ans) {

    for (int i = 0; i < n; i++) {
        if (0 == p[i].get_level()) {
            ans[i].set_coefficient(0);
            ans[i].set_level(0);
        }
        else if(0 == p[i].get_coefficient()) {
            ans[i].set_coefficient(0);
            ans[i].set_level(0);
        }
        else {
            ans[i].set_coefficient(p[i].get_level() * p[i].get_coefficient());
            ans[i].set_level(p[i].get_level() - 1);
        }
    }

    return;
}


// No.8: Judge functions.

void equal_judge() {

    polynomial * p = NULL, *q = NULL;
    int count_p = 0, count_q = 0;
    bool judge;

    cout << "+---------------------------------------------------------------+" << endl;
    cout << "| Input 2 polynomials, and you will know whether they're equal. |" << endl;
    cout << "+---------------------------------------------------------------+" << endl;
    out_tips();
    cout << "First, please enter the polynomial p." << endl;
    p = polynomial_analyse(count_p);
    if (p == NULL) {
        return;
    }
    cout << "Next, please enter the polynomial q." << endl;
    q = polynomial_analyse(count_q);
    if (q == NULL) {
        delete [] p;
        return;
    }

    polynomial_simple(p, count_p);
    polynomial_simple(q, count_q);

    judge = polynomial_equal(p, count_p, q, count_q);

    if (judge) {
        cout << endl << "Congratulations! p and q are equal!" << endl
             << "They are both:" << endl << endl;
        out_polynomial(p, count_p);
    } 

    else {
        cout << endl <<"Sorry! p and q aren't equal." << endl << endl;
        cout << "p: ";
        out_polynomial(p, count_p);
        cout << "q: ";
        out_polynomial(q, count_q);
    }

    delete [] p;
    delete [] q;

    system("pause");   
    return;
}

bool polynomial_equal(polynomial * p, int & count_p, polynomial * q, int & count_q) { 

    if (count_q != count_p) {
        return false;
    }

    else {
        for (int i = 0; i < count_p; i++) {
            if (p[i] != q[i]) {
                return false;
            }
        }
    }

    return true;
}


// No.9: Point calculating functions.

void point_calculate() {

    polynomial * p = NULL;
    int ans, n, count_p = 0;

    cout << "+-----------------------------------------------------------------------------+" << endl;
    cout << "| Input a polynomial and an inter, you will get the value when x = the inter. |" << endl;
    cout << "+-----------------------------------------------------------------------------+" << endl;
    out_tips();
    cout << "Please input the polynomial p." << endl;

    p = polynomial_analyse(count_p);
    if (p == NULL) {
        return;
    }
    cout << "Please enter a number." << endl;
    cin >> n;

    polynomial_simple(p, count_p);

    cout << "p: " ;
    out_polynomial(p, count_p);
    cout << "n: " << n << endl << endl;

    ans = point_value(p, count_p, n);   
    cout << "The value p(n) is: " << ans << '.' << endl << endl;

    delete [] p;

    system("pause");
    return;
}

int point_value(polynomial * p, int count_p, int n) {
    int ans = 0;
    for (int i = 0; i < count_p; i++) {
        ans += p[i].get_coefficient() * pow(n, p[i].get_level());
    }

    return ans;
}
