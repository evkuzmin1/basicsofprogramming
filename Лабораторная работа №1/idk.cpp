#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


void performSimpleOperation(double num1, char oper, double num2) {
    double result;
    if (oper == '+')
        result = num1 + num2;
    else if (oper == '-')
        result = num1 - num2;
    else if (oper == '*')
        result = num1 * num2;
    else if (oper == '/')
        result = num1 / num2;
    else if (oper == '^')
        result = pow(num1, num2);
    else {
        cout << "Invalid operator" << endl;
        return;
    }
    cout << "Result => : " << result << endl;
}

void performTrigonometricOperation(double num, const string& oper) {
    double result;
    if (oper == "cos")
        result = cos(num);
    else if (oper == "sin")
        result = sin(num);
    else if (oper == "ctg")
        result = cos(num) / sin(num);
    else if (oper == "tg")
        result = sin(num) / cos(num);
    else {
        cout << "Invalid operator" << endl;
        return;
    }
    cout << "Result => : " << result << endl;
}

void performMatrixOperation() {
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

        performSimpleOperation(num1, oper, num2);
        cout << "" << endl;
        goto Back1;
    }

    if (type == "trigonometric") {
    Back2:
        puts("Enter an expression");
        puts("support: 'cos' 'sin' 'tg' 'ctg' ");
        double num1 = 0;
        string oper;

        cin >> ws >> num1;
        cin >> ws >> oper;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR" << endl;
        }

        performTrigonometricOperation(num1, oper);
        cout << "" << endl;
        goto Back2;
    }

    if (type == "matrix") {
        performMatrixOperation();
        
    }

    else {
        cout << "ERROR" << endl;
    }

    return 0;
}