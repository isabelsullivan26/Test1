#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdint>
using namespace std;

void getTheLine(const string& line){
    istringstream iss(line);
    string operation;
    //converts the numbers into 32 bit unsigned number
    uint32_t num1;
    uint32_t num2;
    
    //if the line doesn't read out in the format of OPERATION HEX HEX, return an error
    if (!(iss >> operation >> hex >> num1 >> hex >> num2)) {
        cout << "Error processing line: " << line << endl;
        return;
    }

    if (operation == "ADD") {
        //Adds the two hexidecimal numbers
        uint32_t result = num1 + num2;
        cout << operation << " 0x" << uppercase << hex << num1
             << " 0x" << uppercase << hex << num2 << ": "
             << "0x" << uppercase << hex << result << endl;
    } else {
        cout << "Unsupported operation: " << operation << endl;
    }
    cout << endl;
}

int main(){
    ifstream ifile("PA1.txt");
    if(!ifile.is_open()){
        cout << "Error opening file" << endl;
        return 0;
    }
    string line;
    while(getline(ifile,line)){
        getTheLine(line);
    }
    ifile.close();
    return 0;
}

