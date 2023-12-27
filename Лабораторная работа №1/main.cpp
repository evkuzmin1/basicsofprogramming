#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void performAddition(double num1, double num2) {
    cout << "Result => : " << num1 + num2 << endl;
}

void performSubtraction(double num1, double num2) {
    cout << "Result => : " << num1 - num2 << endl;
}

void performMultiplication(double num1, double num2) {
    cout << "Result => : " << num1 * num2 << endl;
}

void performDivision(double num1, double num2) {
    if (num2 != 0) {
        cout << "Result => : " << num1 / num2 << endl;
    }
    else {
        cout << "Error: Division by zero" << endl;
    }
}

void performExponentiation(double num1, double num2) {
    cout << "Result => : " << pow(num1, num2) << endl;
}



void performMatrixMultiplication() {
    int row1, column1, row2, column2;
    int Mat1[10][10];
    int Mat2[10][10];

Back3:
    cout << endl << "Enter the number of rows in Matrix 1: ";
    cin >> ws >> row1;
    cout << endl << "Enter the number of columns in Matrix 1: ";
    cin >> ws >> column1;
    cout << endl << "Enter the number of rows in Matrix 2: ";
    cin >> ws >> row2;
    cout << endl << "Enter the number of columns in Matrix 2: ";
    cin >> ws >> column2;

    if (!cin) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "You have entered an incorrect number" << endl;
    }

    if (column1 != row2) {
        cout << endl << "ERROR: Incompatible matrix dimensions for multiplication" << endl;
        goto Back3;
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column1; j++) {
            cout << endl << "(MAT 1 \n\nEnter the element of row " << i + 1
                << " column " << j + 1 << ":";
            cin >> ws >> Mat1[i][j];
            if (!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "You have entered an incorrect number" << endl;
            }
        }
    }

    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < column2; j++) {
            cout << endl << "(MAT 2 \n\nEnter the element of row " << i + 1
                << " column " << j + 1 << ":";
            cin >> ws >> Mat2[i][j];

            if (!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "You have entered an incorrect number" << endl;
            }
        }
    }

    int resultMatrix[10][10];
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column2; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < column1; k++) {
                resultMatrix[i][j] += Mat1[i][k] * Mat2[k][j];
            }
            cout << setw(4) << resultMatrix[i][j] << setw(4);
        }
        cout << endl;
    }

    cout << "------------------------------------------------------------------------------------------------------";
    goto Back3;
}

int main() {
    puts("Enter the type (trigonometric or simple or matrix)");
    puts("Also, you can exit ==> exit");
    string type;
    cin >> ws >> type;

    if (type == "exit") {
        return 0;
    }

    if (type == "simple") {
    Back1:
        puts("Enter an expression");
        puts("support: '*' '/' '+' '-' '^'");
        double num1 = 0, num2 = 0;
        char oper;

        cin >> ws >> num1;
        cin >> ws >> oper;
        cin >> ws >> num2;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR" << endl;
        }
        if (oper == '+') {
            performAddition(num1, num2);
        }
        else if (oper == '-') {
            performSubtraction(num1, num2);
        }
        else if (oper == '*') {
            performMultiplication(num1, num2);
        }
        else if (oper == '/') {
            performDivision(num1, num2);
        }
        else if (oper == '^') {
            performExponentiation(num1, num2);
        }
        else {
            cout << "Invalid operator" << endl;
        }

        cout << "" << endl;
        goto Back1;
    }

    

    if (type == "matrix") {
        performMatrixMultiplication();
    }

    else {
        cout << "ERROR" << endl;
    }

    return 0;
}