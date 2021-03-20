#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Stock {
    string name, WKN, shorty;
};

struct StockData {
    string open, high, low, close ,adjclose, volume, date;
};

void add_record() {

    Stock newStock;

    do {
        cout << "Stock-Name: ";
        cin >> newStock.name;
    } while(newStock.name.length() == 0);

    do {
        cout << "Stock-WKN: ";
        cin >> newStock.WKN;
    } while(newStock.WKN.length() == 0);

    do {
        cout << "Stock-Abbreviation: ";
        cin >> newStock.shorty;
    } while(newStock.shorty.length() == 0);

    //hashing(newStock.name);
    //hashing(newStock.shorty);
}

void write_record() {

    string filename;

    do {
        cout << "Please enter a filename: ";
        cin >> filename;
    } while (filename.length() == 0);

    ofstream file;
    file.open (filename + ".csv");
    file << "Spalte A; Spalte B; Spalte C\n";
    file << "a;b;c\n";
    file << "1,25;3.456;45";
    file.close();
}

void read_record() {

    fstream file;  // file stream

    // open a CSV file for input
    file.open("MSFT.csv", ios::in);

    // if file is open then display the contents
    if (file) {

        StockData currStock; // one data record
        string input; //holds input of file as string

        //display report header
        cout << endl << left << setw(12) << "Date"
                << left << setw(12) << "OPEN"
                << left << setw(12) << "HIGH"
                << left << setw(12) << "LOW"
                << left << setw(12) << "CLOSE"
                << left << setw(12) << "ADJ CLOSE"
                << left << setw(12) << "VOLUME"
                << endl;


        //until reach end-of-file, read and display each record
        while (getline(file, input)) {

            getline(file, currStock.date, ',');
            getline(file, currStock.open, ',');
            getline(file, currStock.high, ',');
            getline(file, currStock.low, ',');
            getline(file, currStock.close, ',');
            getline(file, currStock.adjclose, ',');
            getline(file, currStock.volume);

            cout << currStock.date << "  " << currStock.open << "  " << currStock.high << "  " << currStock.low << "  " << currStock.close << "  " << currStock.adjclose << "  " << currStock.volume << endl;
        }
    }
    else {
        // could not open the file, tell the user
        cout << "Error opening file.\n";
    }
}

char MenuInput(char InputValue) {

    cout << "1 - ADD    2 - DEL    3 - IMPORT    4 - SEARCH" << endl;
    cout << "5 - PLOT    6 - SAVE    7 - LOAD    8 - QUIT" << endl << ": ";
    cin >> InputValue;

    switch (InputValue) {
        case '1': {
            //ADD
            break;
        }
        case '2': {
            //DEL
            break;
        }
        case '3': {
            //IMPORT
            break;
        }
        case '4': {
            //SEARCH
            break;
        }
        case '5': {
            //PLOT
            break;
        }
        case '6': {
            //SAVE
            write_record();
            break;
        }
        case '7': {
            //LOAD
            read_record();
            break;
        }
        case '8': {
            //QUIT
            return '1';
        }
        default: {
            cout << "Please choose a valid function" << endl;
        }
    }
    return '0';
}

int main() {
    cout << "Hello, World!" << std::endl;
    char ReturnValue = '0';
    while(ReturnValue != '1') {
        ReturnValue = MenuInput(ReturnValue);
    }

    return 0;
}
