#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#define HASHTABLE_SIZE 1511


using namespace std;




struct StockData {
    string open, high, low, close, adjclose, volume, date;
};

struct Stock {
    string name, WKN, shorty;
    struct StockData Data[30];
};

struct Stock *hashtableName[HASHTABLE_SIZE];
struct Stock *hashtableShorty[HASHTABLE_SIZE];

int getIndex(string &tohash) {
    int length = tohash.length();
    unsigned long long hashvalue = 0;
    for (int i = 0; i < length; i++) {
        hashvalue += tohash[i] * pow(31, (length - 1 - i));
    }
    //cout << hashvalue << endl;
    int index = hashvalue % HASHTABLE_SIZE;
    //cout << index << endl;
    return index;
}

unsigned long long getHashValue(string &tohash){
    int length = tohash.length();
    unsigned long long hashvalue = 0;
    for (int i = 0; i < length; i++) {
        hashvalue += tohash[i] * pow(31, (length - 1 - i));
    }
    return hashvalue;
}

void add_record() {

    /*zum testen ob der hashvalue stimmt
    string testvalue;
    cout << endl << ":";
    cin >> testvalue;
    hashing(testvalue);*/



    auto *newStock = new Stock;
    int index_add;
    int newnameindex;
    int newshortyindex;

    do {
        cout << "Stock-Name: ";
        cin >> newStock->name;
        cout << endl;
    } while (newStock->name.length() == 0);

    do {
        cout << "Stock-WKN: ";
        cin >> newStock->WKN;
        cout << endl;
    } while (newStock->WKN.length() == 0);

    do {
        cout << "Stock-Abbreviation: ";
        cin >> newStock->shorty;
        cout << endl;
    } while (newStock->shorty.length() == 0);

    int nameindex = getIndex(newStock->name);
    int shortyindex = getIndex(newStock->shorty);

    if(hashtableName[nameindex] == nullptr){
        hashtableName[nameindex] = newStock;
    }
    else{
        index_add = 0;
        do{
            index_add++;
            newnameindex = nameindex + pow(index_add, 2);
        } while (hashtableName[newnameindex] != nullptr);
        hashtableName[newnameindex] = newStock;
    }

    if(hashtableShorty[shortyindex] == nullptr){
        hashtableShorty[shortyindex] = newStock;
    }
    else{
        index_add = 0;
        do{
            index_add++;
            newshortyindex = shortyindex + pow(index_add, 2);
        } while (hashtableShorty[newshortyindex] != nullptr);
        hashtableShorty[newshortyindex] = newStock;
    }


    //debug test
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        if (hashtableName[i] != nullptr) {
            cout << "IndexName: " << i << endl;
            cout << hashtableName[i]->name << "  " << hashtableName[i]->WKN << "  " << hashtableName[i]->shorty << endl;
        }
    }
    for (int i = 0; i < HASHTABLE_SIZE; i++) {

        if (hashtableShorty[i] != nullptr) {
            cout << "IndexShorty: " << i << endl;
            cout << hashtableShorty[i]->name << "  " << hashtableShorty[i]->WKN << "  " << hashtableShorty[i]->shorty
                 << endl;
        }

    }
}

char NameORShort() {
    char InputValue;
    do{
        cout << "Do you want to search by 1 - NAME or 2 - TICKER" << endl;
        cin >> InputValue;
    } while (InputValue != '1' && InputValue != '2');


    return InputValue;
}

void searchStock() {
    string shorty;
    string name;
    int shortyindex;
    int nameindex;
    unsigned long long namehashvalue;
    unsigned long long shortyhashvalue;
    int index_add = 0;
    switch (NameORShort()) {
        case '1': {
            cout << "Enter the Name: ";
            cin >> name;
            nameindex = getIndex(name);
            namehashvalue = getHashValue(name);
            if (hashtableName[nameindex] != nullptr) {
                if (getHashValue(hashtableName[nameindex]->name) == namehashvalue) {
                    cout << endl << "---------------------------------------" << endl
                    << "Stock-Name: " << hashtableName[nameindex]->name << endl
                    << "Stock-WKN: " << hashtableName[nameindex]->WKN << endl
                    << "Stock-Abbrevation: " << hashtableName[nameindex]->shorty << endl
                    << "---------------------------------------" << endl;
                } else {
                    //mach ma while schleife draus while(getIndex(hashtableName[nameindex]->name) != nameindex) schaut er index + pow 1 2 dann index + pow 2 2 dann index pow 3 2 .....
                    cout << "IST ANDERE POS - muss quadratisch weiter gehen" << endl;

                }
            } else {
                cout << "NIX DA BRUDER" << endl;
            }
            break;
        }
        case '2': {
            cout << "Enter the Ticker: ";
            cin >> shorty;
            shortyindex = getIndex(shorty);
            shortyhashvalue = getHashValue(shorty);
            if (hashtableShorty[shortyindex] != nullptr) {
                if (getHashValue(hashtableShorty[shortyindex]->shorty) == shortyhashvalue) {
                    cout << endl << "---------------------------------------" << endl
                         << "Stock-Name: " << hashtableShorty[shortyindex]->name << endl
                         << "Stock-WKN: " << hashtableShorty[shortyindex]->WKN << endl
                         << "Stock-Abbrevation: " << hashtableShorty[shortyindex]->shorty << endl
                         << "---------------------------------------" << endl;
                } else {
                    cout << "IST ANDERE POS" << endl;
                }
            } else {
                cout << "NIX DA BRUDER" << endl;
            }
        }
        break;
    }
}

void write_record() {

    string filename;

    do {
        cout << "Please enter a filename: ";
        cin >> filename;
    } while (filename.length() == 0);

    ofstream file;
    file.open(filename + ".csv");
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

            cout << currStock.date << "  " << currStock.open << "  " << currStock.high << "  " << currStock.low << "  "
                 << currStock.close << "  " << currStock.adjclose << "  " << currStock.volume << endl;
        }
    } else {
        // could not open the file, tell the user
        cout << "Error opening file.\n";
    }
}

char MenuInput(char InputValue) {

    cout << "1 - ADD    2 - DEL    3 - IMPORT    4 - SEARCH" << endl;
    cout << "5 - PLOT    6 - SAVE    7 - LOAD    8 - QUIT" << endl << ": ";
    cin >> InputValue;
    cout << endl;

    switch (InputValue) {
        case '1': {
            add_record();
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
            searchStock();
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
    while (ReturnValue != '1') {
        ReturnValue = MenuInput(ReturnValue);
    }

    return 0;
}
