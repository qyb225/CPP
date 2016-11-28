using namespace std;

// No.1: output functions.
void out_table();
void get_help();
void out_tips();
void out_polynomial(polynomial *, int);
void out_monomial(polynomial *, int);

// No.2: Input analysing functions.
polynomial * polynomial_analyse(int &);
int coefficient_analyse(string, int);
int level_analyse(string, int);
int pow10(int);

// No.3: Smplify functions.
void simplification();
void polynomial_simple(polynomial *, int &);
void polynomial_sort(polynomial *, int);
void polynomial_alike_packing(polynomial *, int &);
void pop_zero(polynomial *, int &);

// No.4: Add functions.
void add();
void polynomial_add(polynomial *, int, polynomial *, int, polynomial *);

// No.5: Subtract functions.
void subtract();
void polynomial_subtract(polynomial *, int, polynomial *, int, polynomial *);

// No.6: Multiply functions.
void multiply();
void polynomial_multiply(polynomial *, int, polynomial *, int, polynomial *);

// No.7: Derivative functions.
void derivative();
void polynomial_derivative(polynomial *, int, polynomial *);

// No.8: Judge functions.
void equal_judge();
bool polynomial_equal(polynomial *, int &, polynomial *, int &);

// No.9: Point calculating functions.
void point_calculate();
int point_value(polynomial *, int, int);
