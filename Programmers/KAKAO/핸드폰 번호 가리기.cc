#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {

	int len = phone_number.size();

	for (int i = len - 5; i >= 0; --i) {
		phone_number[i] = '*';
	}
	return phone_number;
}