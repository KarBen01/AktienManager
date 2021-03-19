#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Stock
{
    string open, high, low, close ,adjclose, volume;
    string date;

};

void create()
{
    //import function comes here
}

void read_record()
{
    fstream file;  // file stream

    // open a CSV file for input
    file.open("MSFT.csv", ios::in);

    // if file is open then display the contents
    if (file)
    {

        Stock currStock; // one data record
        std::string input; //holds input of file as string


        //display report header
        std::cout << endl << std::left << std::setw(12) << "Date"
                << std::left << std::setw(12) << "OPEN"
                << std::left << std::setw(12) << "HIGH"
                << std::left << std::setw(12) << "LOW"
                << std::left << std::setw(12) << "CLOSE"
                << std::left << std::setw(12) << "ADJ CLOSE"
                << std::left << std::setw(12) << "VOLUME"
                << std::endl;


        //until reach end-of-file, read and display each record
        while (std::getline(file, input))
        {

            std::getline(file, currStock.date, ',');
            std::getline(file, currStock.open, ',');
            std::getline(file, currStock.high, ',');
            std::getline(file, currStock.low, ',');
            std::getline(file, currStock.close, ',');
            std::getline(file, currStock.adjclose, ',');
            std::getline(file, currStock.volume);

            cout << currStock.date << "  " << currStock.open << "  " << currStock.high << "  " << currStock.low << "  " << currStock.close << "  " << currStock.adjclose << "  " << currStock.volume << endl;

        }
    }
    else // could not open the file, tell the user
    {
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
            create();
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
