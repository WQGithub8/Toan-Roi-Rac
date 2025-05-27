#include <iostream>
using namespace std;

bool tonTai(int phanTu, int a[100], int soPhanTu);
bool con(int a[100], int nA, int b[100], int nB);
bool bang(int a[100], int nA, int b[100], int nB);
void hop(int a[100], int nA, int b[100], int nB, int c[100], int &nC);
void giao(int a[100], int nA, int b[100], int nB, int c[100], int &nC);
void hieu(int a[100], int nA, int b[100], int nB, int c[100], int &nC);
void xuatMang(int a[100], int soPhanTu);

int main() {
	int a[10]={1,2}, b[10]={1,2,3}, c[10]={2,1};
	int nA = 2, nB = 3, nC = 2;
	
	//Kiem tra con
	if (con(a, nA, b, nB)) cout << "A CON B" << endl;
	else cout << "A KHONG LA CON B" << endl;
	
	//Kiem tra bang
	if (bang(a, nA, b, nB)) cout << "A BANG B" << endl;
	else cout << "A KHONG BANG B" << endl;
	
	//Hop cua hai mang A va B
	cout << "Hop cua A va B: ";
	hop(a, nA, b, nB, c, nC);
	xuatMang(c, nC);
	
	//Giao cua hai mang A va B
	cout << "Giao cua A va B: ";
	giao(a, nA, b, nB, c, nC);
	xuatMang(c, nC);
	
	//Hieu cua hai mang A va B
	cout << "Hieu cua A va B: ";
	hieu(a, nA, b, nB, c, nC);
	xuatMang(c, nC);
	return 0;
}

bool tonTai(int phanTu, int a[100], int soPhanTu) {
	for (int i = 0; i < soPhanTu; i++) {
		if (a[i] == phanTu) return true;
	}
	return false;
}

bool con(int a[100], int nA, int b[100], int nB) {
	for (int i = 0; i < nA; i++) {
		if (tonTai(a[i], b, nB) == false) return false;
	}
	return true;
}

bool bang(int a[100], int nA, int b[100], int nB) {
	if (nA != nB) return false;
	for (int i = 0; i < nA; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

void hop(int a[100], int nA, int b[100], int nB, int c[100], int &nC) {
	nC = 0;
	for (int i = 0; i < nA; i++) {
		c[nC] = a[i];
		nC++;
	} 
	for (int i = 0; i < nB; i++) {
		if (!tonTai(b[i], a, nA)) {
			c[nC] = b[i];
			nC++;	
		}
	} 
}
void giao(int a[100], int nA, int b[100], int nB, int c[100], int &nC) {
	nC = 0;
	for (int i = 0; i < nA; i++) {
		if (tonTai(a[i], b, nB)) {
			c[nC] = a[i];
			nC++;
		}
	}
}

void hieu(int a[100], int nA, int b[100], int nB, int c[100], int &nC) {
	nC = 0;
	for (int i = 0; i < nA; i++) {
		if (!tonTai(a[i], b, nB)) {
			c[nC] = a[i];
			nC++;
		}
	}
}

void xuatMang(int a[100], int soPhanTu) {
	if (soPhanTu == 0) cout << "Rong tuech!!!" << endl;
	else {
		for (int i = 0; i < soPhanTu; i++) {
			cout << a[i] << " ";
		}
		cout << endl;	
	}
}


