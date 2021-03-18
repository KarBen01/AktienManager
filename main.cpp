#include <iostream>
#include <fstream>

using namespace std;


void saveCSV() {

    ofstream myfile;
    myfile.open ("example.csv");
    myfile << "This is the first cell in the first column.\n";
    myfile << "a,b,c,\n";
    myfile << "c,s,v,\n";
    myfile << "1,2,3.456\n";
    myfile << "semi;colon";
    myfile.close();
}

void loadCSV() {

}

int MenuInput(char InputValue) {

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
            saveCSV();
            break;
        }
        case '7': {
            //LOAD
            break;
        }
        case '8': {
            //QUIT
            return 1;
        }
        default: {
            cout << "Please choose a valid function" << endl;
        }
    }
    return 0;
}

int main() {
    cout << "Hello, World!" << std::endl;
    int ReturnValue = 0;
    while(ReturnValue != 1) {
        ReturnValue = MenuInput(ReturnValue);
    }
    return 0;
}
