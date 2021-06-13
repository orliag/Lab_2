#include <iostream>
#include <math.h>

using namespace std;

class poly {
private:
	int size = 0;
	int* mas = new int[size];

public:
	poly() {}

	poly(const poly& adress) {
		this->size = adress.size;
		this->mas = new int[adress.size];
		for (int i = 0; i < adress.size; i++) {
			this->mas[i] = adress.mas[i];
		}
	}

	void set() {

		int n;
		cout << "poly size: ";
		cin >> n;
		size = n;

		delete[] mas;
		mas = new int[size];
		for (int i = size - 1; i >= 0; i--) {
			cout << "Num " << i << ": ";
			cin >> mas[i];
		}
	}

	void stat() {
		if (size > 2) {
			cout << mas[size - 1] << " X^" << size - 1 << " ";

			for (int i = size - 2; i > 1; i--) {
				if (mas[i] > 0) {
					cout << " + " << fabs(mas[i]) << " X^" << i << " ";
				}
				else if (mas[i] < 0) {
					cout << " - " << fabs(mas[i]) << " X^" << i << " ";
				}
			}
			if (mas[1] > 0) {
				cout << " + " << fabs(mas[1]) << " X ";
			}
			else if (mas[1] < 0) {
				cout << " - " << fabs(mas[1]) << " X ";
			}

			if (mas[0] > 0) {
				cout << " + " << fabs(mas[0]);
			}
			else if (mas[0] < 0) {
				cout << " - " << fabs(mas[0]);
			}
		}
		else if (size == 2) {
			cout << mas[1] << " X ";

			if (mas[0] > 0) {
				cout << " + " << fabs(mas[0]);
			}
			else if (mas[0] < 0) {
				cout << " - " << fabs(mas[0]);
			}
		}
		else {
			cout << mas[0];
		}	

		cout << endl;

	}

	poly& operator = (const poly& adress) {
		this->size = adress.size;

		delete[] this->mas;

		this->mas = new int[adress.size];
		for (int i = 0; i < adress.size; i++) {
			this->mas[i] = adress.mas[i];
		}
		return *this;
	}

	bool operator == (const poly& adress) {
		if (this->size != adress.size) {
			return false;
		}

		for (int i = 0; i < size; i++) {
			if (this->mas[i] != adress.mas[i]) {
				return false;
			}
		}

		return true;
	}

	bool operator != (const poly& adress) {
		if (this->size != adress.size) {
			return true;
		}

		for (int i = 0; i < size; i++) {
			if (this->mas[i] != adress.mas[i]) {
				return true;
			}
		}

		return false;
	}

	poly operator + (const poly& adress) {
		poly buf;

		if (this->size > adress.size) {
			buf = *this;
			for (int i = 0; i < adress.size; i++) {
				buf.mas[i] += adress.mas[i];
			}
		}
		else {
			buf = adress;
			for (int i = 0; i < this->size; i++) {
				buf.mas[i] += this->mas[i];
			}
		}

		return buf;
	}

	poly operator - (const poly& adress) {
		poly buf;

		if (this->size > adress.size) {
			buf = *this;
			for (int i = 0; i < adress.size; i++) {
				buf.mas[i] -= adress.mas[i];
			}
			return buf;
		}
		else {
			buf = adress;
			for (int i = 0; i < this->size; i++) {
				buf.mas[i] -= this->mas[i];
			}
			return -buf;
		}
	}

	poly operator-() {
		poly buf = *this;
		for (int i = 0; i < buf.size; i++) {
			buf.mas[i] = -buf.mas[i];
		}
		return buf;
	}

	poly& operator += (const poly& adress) {
		*this = *this + adress;
		return *this;
	}

	poly& operator -= (const poly& adress) {
		*this = *this - adress;
		return *this;
	}

	poly operator * (int n) {
		poly buf = *this;
		for (int i = 0; i < this->size; i++) {
			buf.mas[i] *= n;
		}
		return buf;
	}

	poly operator / (int n) {
		poly buf = *this;
		for (int i = 0; i < this->size; i++) {
			buf.mas[i] /= n;
		}
		return buf;
	}

	poly& operator *= (int n) {
		*this = *this * n;
		return *this;
	}

	poly& operator /= (int n) {
		*this = *this / n;
		return *this;
	}

	poly operator << (int n) {
		poly buf = *this;
		delete[] buf.mas;
		buf.size = this->size + n;
		buf.mas = new int[buf.size];
		for (int i = 0; i < n; i++) {
			buf.mas[i] = 0;
		}
		for (int i = n; i < buf.size; i++) {
			buf.mas[i] = this->mas[i - n];
		}
		return buf;
	}

	poly operator >> (int n) {
		poly buf = *this;
		delete[] buf.mas;
		buf.size = this->size - n;
		buf.mas = new int[buf.size];
		for (int i = 0; i < buf.size; i++) {
			buf.mas[i] = this->mas[i + n];
		}
		return buf;
	}

	int operator [](int index) {
		return this->mas[index];
	}

	~poly() {
		delete[] mas;
	}
};

int main() {

	poly first;
	first.set();
	first *= 5;
	first.stat();

	poly second;
	second.set();
	second.stat();

	if (second == first) {
		cout << "EEEEEEEEEEEEEEHAHHHHHAAAAAA!!!" << endl;
	}else if (second != first) {
		cout << "(((" << endl;
	}

	poly third = first - second;
	third.stat();

	second -= first;
	second.stat();

	first = first << 2;
	first.stat();
	first = first >> 3;
	first.stat();

	cout << first[0] << endl;
	return 0;
}


