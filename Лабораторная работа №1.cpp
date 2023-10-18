#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	puts("Enter the type (trigonometric or simple or matrix)");
	puts("Also you can exit ==> exit");
	string type;
	cin >> ws >> type;

	if (type == "exit") {
		return 0;
	}

	if (type == "simple") {

	Back1:

		puts("Enter an expression");
		puts("support: '*' '/' '+' '-' '^'");
		double num1 = 0, num2 = 0, result = 0;
		char oper;


		cin >> ws >> num1;
		cin >> ws >> oper;
		cin >> ws >> num2;

		if (!cin) 
		{
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "ERROR" << endl;
		}

		if (oper == '+') {
			result = num1 + num2;
			cout << "Result => : " << result << endl;
			goto Back1;
		}
		if (oper == '-') {
			result = num1 - num2;
			cout << "Result => : " << result << endl;
			goto Back1;
		}
		if (oper == '*') {
			result = num1 * num2;
			cout << "Result => : " << result << endl;
			goto Back1;
		}
		if (oper == '/') {
			result = num1 / num2;
			cout << "Result => : " << result << endl;
			goto Back1;
		}
		if (oper == '^') {
			result = pow(num1, num2);
			cout << "Result => : " << result << endl;
			goto Back1;
		}
		

	 
	}
	if (type == "trigonometric") {

	Back2:

		puts("Enter an expression");
		puts("support: 'cos' 'sin' 'tg' 'ctg' ");
		string oper;
		double num1 = 0;


		cin >> ws >> num1;
		cin >> ws >> oper;

		if (!cin)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR" << endl;
		}

		if (oper == "cos") {
			cout << "Result => : " << cos(num1) << endl;
			goto Back2;

		}
		if (oper == "sin") {
			cout << "Result => : " << sin(num1) << endl;
			goto Back2;

		}
		if (oper == "ctg") {
			cout << "Result => : " << cos(num1) / sin(num1) << endl;
			goto Back2;

		}
		if (oper == "tg") {
			cout << "Result => : " << sin(num1) / cos(num1) << endl;
			goto Back2;

		}
		
		


	}

	if (type == "matrix") {
		int row1, column1, row2, column2;
		int Mat1[10][10];
		int Mat2[10][10];

	Back3:
		cout << endl << "Enter the numer of rows in Matrix 1 : ";
		cin >> ws >> row1;
		cout << endl << "Enter the numer of colums in Matrix 1 : ";
		cin >> ws >> column1;
		cout << endl << "Enter the numer of rows in Matrix 2 : ";
		cin >> ws >> row2;
		cout << endl << "Enter the numer of colums in Matrix 2 : ";
		cin >> ws >> column2;

		if (!cin)
		{

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "You have entered an incorrect number" << endl;

		}




		if (column1 != column2) {
			cout << endl << "ERROR" << endl;
			goto Back3;
		}
		if (row1 != row2) {
			cout << endl << "ERROR" << endl;
		}
		for (int i = 0; i < row1; i++) {
			for (int j = 0; j < column1; j++) {
				cout << endl << "(MAT 1 \n\nEnter the element of row" << i + 1
					<< "column" << j + 1 << ":";
				cin >> ws >> Mat1[i][j];
				if (!cin)
				{

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "You have entered an incorrect number" << endl;

				}
			}
		}
		for (int i = 0; i < row2; i++) {
			for (int j = 0; j < column2; j++) {
				cout << endl << "(MAT 2 \n\nEnter the element of row" << i + 1
					<< "column" << j + 1 << ":";
				cin >> ws >> Mat2[i][j];

				if (!cin)
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "You have entered an incorrect number" << endl;
				}
			}
		}

		for (int i = 0; i < row1; i++) {
			for (int j = 0; j < column2; j++) {
				cout << setw(4) << Mat1[i][j] + Mat2[i][j] << setw(4);

			}
			cout << endl;

		}
		cout << "------------------------------------------------------------------------------------------------------";
		goto Back3;
		return 0;
	}


	else {
		cout << "ERROR";
	}
	return 0;
}