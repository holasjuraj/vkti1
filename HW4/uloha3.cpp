#include <iostream>
using namespace std;

int main() {
	int c;
	cin >> c;
	if(c == 0){
		cout << "1 0" << endl;
		return 0;
	}
	else if(c <= 98){
		cout << (c + 2) << ' ' << (c * 2) << endl;
		int endIndex = c + 1;
		for(int i = 1; i <= c; i++){
			cout << "0 " << i << endl;
			cout << i << ' ' << endIndex << endl;
		}
		return 0;
	}
	
	int maxBit = 0, ones = 0;
	for(int i = 1; i < 20; i++){
		if((c&(1 << i)) != 0){
			ones++;
			maxBit = i;
		}
	}
	
	// pocet vrcholov
	int n = maxBit*2 + 2;
	cout << n << ' ';
	// pocet hran
	cout << (maxBit*4 - 2  +  ones*2 + ((c%2==1) ? 1 : 0)) << endl;
	
	// strikovacka
	for(int i = n-2; i > 2; i--){
		cout << i << ' ' << (((i-1)/2)*2) << endl;
		cout << i << ' ' << (((i-1)/2)*2 - 1) << endl;
	}
	cout << "1 " << (n-1) << endl;
	cout << "2 " << (n-1) << endl;
	
	// napojenie zaciatku na strikovacku
	for(int i = 1; i <= maxBit; i++){
		if((c&(1 << i)) != 0){
			cout << "0 " << (i*2) << endl;
			cout << "0 " << (i*2 - 1) << endl;
		}
	}
	if(c%2 == 1){
		cout << "0 " << (n-1) << endl;
	}
	
	return 0;
}