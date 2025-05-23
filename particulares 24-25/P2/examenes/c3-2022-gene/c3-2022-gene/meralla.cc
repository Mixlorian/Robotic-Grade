#include <iostream>
using namespace std;


int main(){
	string s = "";
	char c = 'a';
	
	s = s + c;
	cout << s << endl;
	s = c + s;
	cout << s << endl;
	
	int x = 3;
	s = s + to_string(x);
	cout << s << endl;
	
	
	return 0;	
}
