#include <iostream>
#include <string>
#include <algorithm>

char alphabet(unsigned long long index) {
	char alphabet[20] = { '0','1','2','3','4','5','6','7',
		'8','9','A','B','C','D','E','F','G','H','I','J' };
	return alphabet[index];
}


unsigned long long to_dec(const std::string& number, unsigned long long p) {

	unsigned long long ch;
	int number_one;
	int lite;

	if (number[0] <= '9') {
		number_one = number[0] - '0';
	}
	else {
		number_one = number[0] - 'A' + 10;
	}

	unsigned long long one = number_one;
	for (int i = 1; i <= number.size() - 1; ++i) {

		if (number[i] <= '9') {
			lite = number[i] - '0';
		}
		else {
			lite = number[i] - 'A' + 10;
		}

		if (number_one < p && lite < p) {
			one = one * p + lite;
		}
		else {
			return 0;
		}
	}
	return one;
}


std::string un_dec(unsigned long long number, unsigned long long q) {

	if (q == 10) {
		return std::to_string (number);
	}

	std::string str;
	while (number != 0) {
		str += alphabet(number%q);
		number /= q;
	}
	std::reverse(str.begin(), str.end());
	return str;
}


int main() {
	std::string number;
	unsigned long long p;
	unsigned long long q;
	std::cin >> number >> p >> q;

	if (number == "0"){
		std::cout << 0 << std::endl;
		return 0;
	}

	unsigned long long dec = to_dec(number,p);
	if (dec == 0){
		std::cout << "wrong integer" << std::endl;
		return 0;
	}

	std::string str = un_dec(dec, q);
	std::cout << str << std::endl;

	return 0;
}
