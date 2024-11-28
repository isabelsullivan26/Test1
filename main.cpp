#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdint>
using namespace std;

void mov(int, uint32_t);
void addition(int, int, int);
void subtraction(int, int, int);
void andOp(int, int, int);
void orOp(int, int, int);
void xorOp(int, int, int);
void lsrOp(int, int, uint32_t);
void lslOp(int, int, uint32_t);
void cmpOp(int, int, int);
void tstOp(int, int, int);
void updateFlags(uint32_t, bool, bool);
void displayRegisters();
void toUpper(string&);

uint32_t reg[8]= {0};
uint8_t N=0,Z=0,C=0,V=0;

void updateFlags(uint32_t answer, bool carry, bool sub){
    Z = (answer==0);
    N = (answer & 0x80000000) != 0;
    if (carry) {
        C = 1;  
    } else {
        C = 0;  
    }
    V = true;
}

void toUpper(string &str){
    for(char &ch : str){
        ch = toupper(ch);
    }
}

void getTheLine(const string& line){
   istringstream iss(line);
    string op;
    char temp;
    int r1 = 0, r2 = 0, r3 = 0;
    uint32_t imm = 0;

    // Get operation and convert to uppercase
    iss >> op;
    toUpper(op);

     if(op == "MOV"){
        iss >> temp >> r1 >> temp; 
        iss >> ws;
        if (iss.peek() == '#') {
            iss >> temp; 
            iss >> hex >> imm >> uppercase;
            mov(r1, imm);  
        }
    }
    else if (op == "ADDS") {
        char comma;
        iss >> temp >> r1 >> comma >> temp >> r2 >> comma >> temp>> r3;
        addition(r1, r2, r3);  //Call add operation
    }
    else if (op == "SUBS") {
        char comma;
        iss >> temp >> r1 >> comma >> temp >> r2 >> comma >> temp>> r3;
        subtraction(r1, r2, r3);  //Call sub operation
    }
    else if (op == "ANDS") {
        char comma;
        iss >> temp >> r1 >> comma >> temp >> r2 >> comma >> temp>> r3;
        andOp(r1, r2, r3);  //Call and operation
    }
    else if (op == "ORR") {
         char comma;
        iss >> temp >> r1 >> comma >> temp >> r2 >> comma >> temp>> r3;
        orOp(r1, r2, r3);  //Call or operation
    }
    else if (op == "XOR") {
         char comma;
        iss >> temp >> r1 >> comma >> temp >> r2 >> comma >> temp>> r3;
        xorOp(r1, r2, r3);  //Call XOR operation
    }
    else if (op == "LSRS") {
        char comma;
        iss >> temp >> r1 >> comma >> temp >> r2 >> comma >> temp>> imm;
        lsrOp(r1, r2, imm);  // Call LSRS operation
    }
    else if (op == "LSLS") {
         char comma;
        iss >> temp >> r1 >> comma >> temp >> r2 >> comma >> temp>> imm;
        lslOp(r1, r2, imm);  // Call LSLS operation
    }
    else {
        cout << "Unknown operation: " << op << endl;
    }
}

    void displayRegisters() {
    cout << "R0:0x" << setw(8) << setfill('0') << uppercase << hex << reg[0] << "  ";
    cout << "R1:0x" << setw(8) << setfill('0') << uppercase << hex << reg[1] << "  ";
    cout << "R2:0x" << setw(8) << setfill('0') << uppercase << hex << reg[2] << "  ";
    cout << "R3:0x" << setw(8) << setfill('0') << uppercase << hex << reg[3] << "  " << endl;
    cout << "R4:0x" << setw(8) << setfill('0') << uppercase << hex << reg[4] << "  ";
    cout << "R5:0x" << setw(8) << setfill('0') << uppercase << hex << reg[5] << "  ";
    cout << "R6:0x" << setw(8) << setfill('0') << uppercase << hex << reg[6] << "  ";
    cout << "R7:0x" << setw(8) << setfill('0') << uppercase << hex << reg[7] << endl;
    cout << "N = " << (int)N << " Z = " << (int)Z << " C = " << (int)C << " V = " << (int)V << endl;
}

int main(){
    ifstream ifile("PA3.txt");
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

//Addition
void addition(int rd, int rm, int rn){
    reg[rd] = reg[rn]+reg[rm];
    bool carry = (reg[rd] < reg[rn]);
    updateFlags(reg[rd], carry, false);
    cout << "ADDS R" << rd << ", R" << rn << ", R" << rm << endl;
    displayRegisters();
}

void mov(int rd, uint32_t imm){
    reg[rd] = imm;
    cout << "MOV R" << rd << ", #0x" << hex << imm << endl;
    displayRegisters();
}

void subtraction(int rd, int rm, int rn){
    reg[rd] = reg[rn]-reg[rm];
    bool carry = (reg[rn] < reg[rm]);
    updateFlags(reg[rd], !carry, true);
    cout << "SUB r" << rd << ", r" << rn << ", r" << rm << endl;
    displayRegisters();
}

void andOp(int rd, int rn, int rm) {
    reg[rd] = reg[rn] & reg[rm];
    updateFlags(reg[rd], false, false);
    cout << "AND r" << rd << ", r" << rn << ", r" << rm << endl;
    displayRegisters();
}

void orOp(int rd, int rn, int rm) {
    reg[rd] = reg[rn] | reg[rm];
    updateFlags(reg[rd], false, false);
    cout << "ORR r" << rd << ", r" << rn << ", r" << rm << endl;
    displayRegisters();
}

void xorOp(int rd, int rn, int rm) {
    reg[rd] = reg[rn] ^ reg[rm];
    updateFlags(reg[rd], false, false);
    cout << "XOR r" << rd << ", r" << rn << ", r" << rm << endl;
    displayRegisters();
}

void lslOp(int rd, int rn, uint32_t imm) {
    reg[rd] = reg[rn] << imm;
    bool c = (reg[rn] >> (32 - imm)) & 0x1; 
    updateFlags(reg[rd], c, false);
    cout << "LSL r" << rd << ", r" << rn << ", #" << imm << endl;
    displayRegisters();
}


void lsrOp(int rd, int rn, uint32_t imm) {
    reg[rd] = reg[rn] >> imm;
    updateFlags(reg[rd], true, false);
    cout << "LSR r" << rd << ", r" << rn << ", #" << imm << endl;
    displayRegisters();
}
