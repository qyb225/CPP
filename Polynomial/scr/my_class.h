class polynomial {
private:
    int coefficient;
    int level;
public:
    polynomial();
    polynomial(int, int);
    void set_coefficient(int);
    void set_level(int);
    int get_coefficient();
    int get_level();
    bool operator==(polynomial &);
    bool operator!=(polynomial &);
};
