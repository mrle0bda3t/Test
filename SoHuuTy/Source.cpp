#include<iostream>
using namespace std;
int UCLN(int a, int b) {
	a = abs(a);
	b = abs(b);
	if (a == 0 && b != 0) {
		return 0;
	}
	else if (a != 0 && b == 0) {
		return -1;
	}
	else if (a == 0 && b == 0) {
		return -2;
	}
	else {
		while (a != b) {
			if (a > b) {
				a = a - b;
			}
			else b = b - a;
		}
		return a;
	}
}
class HuuTi {
	friend ostream& operator<<(ostream&, HuuTi&);
	friend istream& operator>>(istream&, HuuTi&);
private:
	int ts;
	int ms;
public:
	HuuTi(int = 0, int = 1);
	HuuTi operator+(HuuTi a);
	HuuTi operator-(HuuTi a);
	HuuTi operator*(HuuTi a);
	HuuTi operator/(HuuTi a);
	int operator==(HuuTi a);
	int operator!=(HuuTi a);
	int operator<(HuuTi a);
	int operator>(HuuTi a);
	void Rutgon();
};
HuuTi::HuuTi(int _ts, int _ms) {
	ts = _ts;
	ms = _ms;
}
void HuuTi::Rutgon() {
	int x = UCLN(ts, ms);
	if (x == 0) {
		ts = 0;
		ms = 1;
	}
	else if (x == -1) {
		ts = 1;
		ms = 0;
	}
	else if (x == -2) {
		ts = 0;
		ms = 0;
	}
	else {
		ts = ts / x;
		ms = ms / x;
	}
}
HuuTi HuuTi::operator+(HuuTi a) {
	HuuTi kq;
	kq.ts = ts * a.ms + ms * a.ts;
	kq.ms = ms * a.ms;
	kq.Rutgon();
	return kq;
}
HuuTi HuuTi::operator-(HuuTi a) {
	HuuTi kq;
	kq.ts = ts * a.ms - ms * a.ts;
	kq.ms = ms * a.ms;
	kq.Rutgon();
	return kq;
}
HuuTi HuuTi::operator*(HuuTi a) {
	HuuTi kq;
	kq.ts = ts * a.ts;
	kq.ms = ms * a.ms;
	kq.Rutgon();
	return kq;
}
HuuTi HuuTi::operator/(HuuTi a) {
	HuuTi kq;
	kq.ts = ts * a.ms;
	kq.ms = ms * a.ts;
	kq.Rutgon();
	return kq;
}
int HuuTi::operator==(HuuTi a) {
	this->Rutgon();
	a.Rutgon();
	if (ts == a.ts && ms == a.ms) {
		return 1;
	}
	else return 0;
}
int HuuTi::operator!=(HuuTi a) {
	this->Rutgon();
	a.Rutgon();
	if (ts != a.ts || ms != a.ms) {
		return 1;
	}
	return 0;
}
int HuuTi::operator<(HuuTi a) {
	if (ts * a.ms - ms * a.ts < 0) {
		return 1;
	}
	else return 0;
}
int HuuTi::operator>(HuuTi a) {
	if (ts * a.ms - ms * a.ts > 0) {
		return 1;
	}
	else return 0;
}
ostream& operator<<(ostream& os, HuuTi& a) {
	if (a.ts == 0 && a.ms != 0) {
		os << 0 << endl;
	}
	else if (a.ts == 0 && a.ms == 0) {
		os << 0 << endl;
	}
	else if (a.ts != 0 && a.ms == 0) {
		cout << "Mau so khong hop le" << endl;
	}
	else {
		if (a.ts % a.ms == 0) {
			os << a.ts / a.ms << endl;
		}
		else {
			os << a.ts << "/" << a.ms << endl;
		}
	}
	return os;
}
istream& operator>>(istream& is, HuuTi& a) {
	cout << "Nhap tu so : ";
	cin >> a.ts;
	cout << "Nhap mau so : ";
	cin >> a.ms;
	return is;
}
int main() {
	int luachon;
	int k = 0;
	HuuTi a1, a2;
	cout << "1.Nhap so huu ti\n2.Xuat so huu ti\n3.Cong 2 so huu ti\n4.Tru 2 so huu ti\n5.Nhan 2 so huu ti\n6.Chia 2 so huu ti\n7.Phep toan so sanh\n8.Thoat\n";
	while (k == 0) {
		cout << "Hay nhap lua chon : ";
		cin >> luachon;
		switch (luachon) {
		case 1: {
			cin >> a1;
			cin >> a2;
			break;
		}
		case 2: {
			cout << a1;
			cout << a2;
			break;
		}
		case 3: {
			HuuTi b = a1 + a2;
			cout << "Tong : " << b;
			break;
		}
		case 4: {
			HuuTi b = a1 - a2;
			cout << "Hieu : " << b;
			break;
		}
		case 5: {
			HuuTi b = a1 * a2;
			cout << "Tich : " << b;
			break;
		}
		case 6: {
			HuuTi b = a1 / a2;
			cout << "Thuong : " << b;
			break;
		}
		case 7: {
			if (a1 < a2) {
				cout << a1 << "< " << a2 << endl;
			}
			else if (a1 > a2) {
				cout << a1 << "> " << a2 << endl;
			}
			else if (a1 == a2) {
				cout << "Hai so bang nhau" << endl;
			}
			break;
		}
		case 8: {
			k = 1;
			break;
		}
		}
	}
}