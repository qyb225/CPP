
polynomial::polynomial() {
    level = 0;
    coefficient = 0;
}

polynomial::polynomial(int a, int b) {
    coefficient = a;
    level = b;
}

void polynomial::set_coefficient(int n) {
    coefficient = n;
}

void polynomial::set_level(int n) {
    level = n;
}

int polynomial::get_coefficient() {
    return coefficient;
}

int polynomial::get_level() {
    return level;
}

bool polynomial::operator==(polynomial & other) {
	return other.coefficient == coefficient && other.level == level;
}

bool polynomial::operator!=(polynomial & other) {
	return other.coefficient != coefficient || other.level != level;
}
