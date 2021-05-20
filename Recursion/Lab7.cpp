#include <iostream>
using namespace std;

int countDigititerative(int num){
	int count = 0;
	while(num != 0){
		num = num / 10;
		count++;
	}
	return count;
}

int countDigitrecursive(int num){
	if (num == 0)
		return 0;
	return 1 + countDigitrecursive(num / 10);
}

bool hasDecreasingOddDigits(int n, int prev){
	if(n == 0)
		return true;
	int s = n % 10;
	if(s % 2 == 1){
		if(s < prev)
			return true & hasDecreasingOddDigits(n/10, s);
		else
			return false;
	}
	else
		return true & hasDecreasingOddDigits(n/10, prev);		
}

int countOnes(int n){
	if(n == 0)
		return 0;
	else
		return (n & 1) + countOnes(n >> 1);
}


int main(){
	int num;
	char opt = 'y' ;
	int dig, dig_rec;
	do{
		cout << "Enter the number" << endl;
		cin >> num;
		dig = countDigititerative(num);
		dig_rec = countDigitrecursive(num);
		cout << "For number " << num << endl;
		cout << "The number of digits(iterative): " << dig << endl ;
		cout << "The number of digits(revursive): " << dig_rec << endl;
		if(hasDecreasingOddDigits(num,10))
			cout << "Decreasing odd digits(true/false): True"<< endl;
		else
			cout << "Decreasing odd digits(true/false): False"<< endl;
		cout << "The number of ones in binary representation: "<< countOnes(num) << endl;
		cout << "Press y to continue" << endl;
		cin >> opt;
	}while(opt == 'y');
	
	
}
