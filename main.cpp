#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdint>
using namespace std;

void addition(uint32_t, uint32_t, string);
void subtraction(uint32_t, uint32_t, string);
void andOp(uint32_t, uint32_t, string);
void orOp(uint32_t, uint32_t, string);
void xorOp(uint32_t, uint32_t, string);
void notOp(uint32_t, string);
void lsrOp(uint32_t, uint32_t, string);
void lslOp(uint32_t, uint32_t, string);
void asrOp(uint32_t, uint32_t, string);

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

    if (operation == "ADD" || operation == "ADDS") {
        //Adds the two hexidecimal numbers
        addition(num1, num2, operation);
    } else if (operation == "SUB" || operation == "SUBS"){
        subtraction(num1,num2,operation);
    } else if (operation == "AND" || operation == "ANDS"){
        andOp(num1,num2,operation);
    }else if (operation == "ORR" || operation == "ORRS" ){
        orOp(num1,num2,operation);
    } else if (operation == "XOR" || operation == "XORS" ){
        xorOp(num1,num2, operation);
    } else if (operation == "NOT" || operation == "NOTS" ){
        notOp(num1,operation);
    }else if (operation == "ASR" || operation == "ASRS" ){
        asrOp(num1,num2,operation);
    } else if (operation == "LSR" || operation == "LSRS" ){
        lsrOp(num1,num2,operation);
    } else if (operation == "LSL" || operation == "LSLS" ){
        lslOp(num1,num2,operation);
    }
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

void addition(uint32_t num1, uint32_t num2, string operation){
    uint32_t result = num1 + num2;
        cout << operation << " 0x" << uppercase << hex << num1
             << " 0x" << uppercase << hex << num2 << ": "
             << "0x" << uppercase << hex << result << endl;
    cout << endl;
}


void subtraction(uint32_t num1, uint32_t num2, string operation){
    uint32_t result = num1 - num2;
        cout << operation << " 0x" << uppercase << hex << num1
             << " 0x" << uppercase << hex << num2 << ": "
             << "0x" << uppercase << hex << result << endl;
    cout << endl;
}

void andOp(uint32_t num1, uint32_t num2, string operation){
    uint32_t result = num1 & num2;
        cout << operation << " 0x" << uppercase << hex << num1
             << " 0x" << uppercase << hex << num2 << ": "
             << "0x" << uppercase << hex << result << endl;
    cout << endl;
}

void orOp(uint32_t num1, uint32_t num2, string operation){
    uint32_t result = num1 | num2;
        cout << operation << " 0x" << uppercase << hex << num1
             << " 0x" << uppercase << hex << num2 << ": "
             << "0x" << uppercase << hex << result << endl;
    cout << endl;
}

void xorOp(uint32_t num1, uint32_t num2, string operation){
    uint32_t result = num1 ^ num2;
        cout << operation << " 0x" << uppercase << hex << num1
             << " 0x" << uppercase << hex << num2 << ": "
             << "0x" << uppercase << hex << result << endl;
    cout << endl;
}

void notOp(uint32_t num1, string operation){
    uint32_t result = ~num1;
        cout << operation << " 0x" << uppercase << hex << num1 << ": "
             << "0x" << uppercase << hex << result << endl;
    cout << endl;
}

void asrOp(uint32_t num1, uint32_t num2, string operation){
    uint32_t result = num1 >> num2;
        cout << operation << " 0x" << uppercase << hex << num1
             << " 0x" << uppercase << hex << num2 << ": "
             << "0x" << uppercase << hex << result << endl;
    cout << endl;
}

void lsrOp(uint32_t num1, uint32_t num2, string operation){
    uint32_t result = num1 >> num2;
        cout << operation << " 0x" << uppercase << hex << num1
             << " 0x" << uppercase << hex << num2 << ": "
             << "0x" << uppercase << hex << result << endl;
    cout << endl;
}

void lslOp(uint32_t num1, uint32_t num2, string operation){
    uint32_t result = num1 << num2;
        cout << operation << " 0x" << uppercase << hex << num1
             << " 0x" << uppercase << hex << num2 << ": "
             << "0x" << uppercase << hex << result << endl;
    cout << endl;
}