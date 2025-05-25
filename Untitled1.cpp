#include <iostream>
#include <cmath>
using namespace std;

bool coTrongMang(int p, int x[], int n);
bool con(int a[], int n, int b[], int m);
bool bang(int a[], int n, int b[], int m);
void hop(int a[], int n, int b[], int m, int c[]);
void giao(int a[], int n, int b[], int m, int c[]);
void hieu(int a[], int n, int b[], int m, int c[]);

int main() {
	int a[] = {1,2,9}, b[] = {1,2,3}, c[] = {2,1};
	int la = sizeof(a), lb =3, lc = 2;
	cout << la << endl;
	 
	// Kiem tra ham CON
	if (con(a,la,b,lb)) {
		cout << "a la tap con cua b" << endl;
	} 
	else {
		cout << "a khong phai con cua b"<<endl;
	}
	
	// Kiem tra ham BANG
	if (bang(a,la,b,lb)) {
		cout << "a bang b"<<endl;
	} 
	else {
		cout << "a khong bang b"<<endl;
	}
	
	// Ham HOP
	int p[] = {};
	cout << "a hop b:" << endl;
	hop(a,la,b,lb,p);
	cout << endl;
	
	// Giao
	int g[] = {};
	cout << "a giao b:" << endl;
	giao(a,la,b,lb,g);
	 
	// Hieu
	int h[] = {};
	cout << "a hieu b:" << endl;
	hieu(a,la,b,lb,g);
}

bool coTrongMang(int p, int x[], int n) {
	for (int i = 0; i<n;i++) {
		if (p == x[i]) {
			break;
		}
		else {
			if (i == n -1) {
				return false;
			}
		}
	}
	return true;
}

bool con(int a[], int n, int b[], int m) {
	for (int i = 0; i < n; i++) {
		return coTrongMang(a[i],b,m);
	}		 
	return true;
}

bool bang(int a[], int n, int b[], int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] != b[j]) {
				return false;
				break;	
			}
		}	
	}
	return true;
}

void hop(int a[], int n, int b[], int m, int c[]) {
	for (int i = 0; i < n; i++) {
		c[i] = a[i];
	}
	int k = n;
	cout << k << " ";
	
	for (int i =0;i<m;i++) {
		if (coTrongMang(b[i],a,n) == false) {
			c[k] = b[i];
			k++;
		}
	}
	cout << k << " ";
	
	
	for (int i =0;i<k;i++) {
		cout << c[i] << " ";
	}
}

void giao(int a[], int n, int b[], int m, int c[]) {
	int k = 0;
	for (int i=0;i<n;i++) {
		if (coTrongMang(a[i],b,m)) {
			c[k] = a[i];
			k++;
		}
	}
	for (int i = 0; i<k;i++) {
		cout << c[i] << " ";
	}
}

void hieu(int a[], int n, int b[], int m, int c[]) {
	int k = 0;
	for (int i = 0;i<n; i++) {
		if (coTrongMang(a[i],b,m)==false) {
			c[k] = a[i];
			k++;
		}
	}
	if (k==0) {
		cout << "Rong";
	}
	else {
		for (int i = 0; i<k;i++) {
			cout << c[i] << " ";
	}
	}
	
}
