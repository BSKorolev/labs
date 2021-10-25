

#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;
int main()
{
	char S[100];
	char c;
	int x=1;
	bool flag = false;
	cin >> S;
	cin >> c;

	for (int i = 0; i < strlen(S); i++)
         if (S[i] == c)
		 {
			flag = true;
			x = i+1;
			break;
		 }



	if (flag)

		cout << x;

	else

		cout << "takogo simvola net";
}


