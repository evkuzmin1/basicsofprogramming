#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib> 

using namespace std;

void clearScreen() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

struct Aircraft {
    string type;
    string flightNumber;
    int seatingCapacity;
    double maxTakeoffWeight;
    string status;

    void display() const {
        cout << left << setw(15) << type
            << setw(15) << flightNumber
            << setw(20) << seatingCapacity
            << setw(20) << maxTakeoffWeight
            << setw(15) << status << endl;
    }
};

void saveToFile(const vector<Aircraft>& aircrafts, const string& filename) {
    ofstream file(filename);
    for (const auto& aircraft : aircrafts) {
        file << aircraft.type << ","
            << aircraft.flightNumber << ","
            << aircraft.seatingCapacity << ","
            << aircraft.maxTakeoffWeight << ","
            << aircraft.status << endl;
    }
}

void loadFromFile(vector<Aircraft>& aircrafts, const string& filename) {
    ifstream file(filename);
    Aircraft aircraft;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        getline(iss, aircraft.type, ',');
        getline(iss, aircraft.flightNumber, ',');
        iss >> aircraft.seatingCapacity; iss.ignore();
        iss >> aircraft.maxTakeoffWeight; iss.ignore();
        getline(iss, aircraft.status);
        aircrafts.push_back(aircraft);
    }
}

template<typename T>
T getNumericInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        else {
            cout << "Error. Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

string getStringInput(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (!input.empty()) {
            return input;
        }
        else {
            cout << "Input can not be empty. Please enter some text.\n";
        }
    }
}

void printAircrafts(const vector<Aircraft>& aircrafts) {
    cout << left
        << setw(5) << "Index"
        << setw(15) << "Type"
        << setw(15) << "Flight Number"
        << setw(20) << "Seating Capacity"
        << setw(20) << "Max Takeoff Weight"
        << setw(15) << "Status" << endl;
    for (size_t i = 0; i < aircrafts.size(); ++i) {
        const auto& aircraft = aircrafts[i];
        cout << setw(5) << i
            << setw(15) << aircraft.type
            << setw(15) << aircraft.flightNumber
            << setw(20) << aircraft.seatingCapacity
            << setw(20) << aircraft.maxTakeoffWeight
            << setw(15) << aircraft.status << endl;
    }
}

void addAircraft(vector<Aircraft>& aircrafts) {
    Aircraft aircraft;
    aircraft.type = getStringInput("Enter aircraft type: ");
    aircraft.flightNumber = getStringInput("Enter flight number: ");
    aircraft.seatingCapacity = getNumericInput<int>("Enter seating capacity: ");
    aircraft.maxTakeoffWeight = getNumericInput<double>("Enter max takeoff weight: ");
    aircraft.status = getStringInput("Enter status: ");

    aircrafts.push_back(aircraft);
}

void editAircraft(vector<Aircraft>& aircrafts) {
    int index = getNumericInput<int>("Enter aircraft index to edit: ");
    if (index < 0 || index >= aircrafts.size()) {
        cout << "Wrong index!\n";
        return;
    }
    aircrafts[index].type = getStringInput("Enter new aircraft type: ");
    aircrafts[index].flightNumber = getStringInput("Enter new flight number: ");
    aircrafts[index].seatingCapacity = getNumericInput<int>("Enter new seating capacity: ");
    aircrafts[index].maxTakeoffWeight = getNumericInput<double>("Enter new max takeoff weight: ");
    aircrafts[index].status = getStringInput("Enter new status: ");
}

void deleteAircraft(vector<Aircraft>& aircrafts) {
    int index;
    printAircrafts(aircrafts);
    cout << "Enter aircraft index to delete: ";
    cin >> index;
    if (index < 0 || index >= aircrafts.size()) {
        cout << "Wrong index!\n";
        return;
    }
    aircrafts.erase(aircrafts.begin() + index);
}

void findAircraft(const vector<Aircraft>& aircrafts) {
    string searchType;
    cout << "Enter aircraft type to search for: ";
    cin >> searchType;
    bool found = false;
    for (const auto& aircraft : aircrafts) {
        if (aircraft.type == searchType) {
            aircraft.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No aircraft found this type " << searchType << ".\n";
    }
}

void showMenu() {

    cout << "---------------------------\n";
    cout << "1. Add Aircraft\n"
        << "2. Edit Aircraft\n"
        << "3. Delete Aircraft\n"
        << "4. Print Aircrafts\n"
        << "5. Find Aircraft by Type\n"
        << "6. Save and Exit\n"
        << "7. Clear \n"
        << "Enter your choice: \n\n";
}

bool processInput(vector<Aircraft>& aircrafts) {
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        addAircraft(aircrafts);
        break;
    case 2:
        editAircraft(aircrafts);
        break;
    case 3:
        deleteAircraft(aircrafts);
        break;
    case 4:
        printAircrafts(aircrafts);
        break;
    case 5:
        findAircraft(aircrafts);
        break;
    case 7:
        clearScreen();
        break;
    case 6:
        return false;
    default:
        cout << "Wrong choice => Try again.\n";
    }
    return true;
}

int main() {
    vector<Aircraft> aircrafts;
    string filename = "aircrafts.txt";
    loadFromFile(aircrafts, filename);

    bool running = true;
    while (running) {
        showMenu();
        running = processInput(aircrafts);
    }

    saveToFile(aircrafts, filename);
    return 0;
}