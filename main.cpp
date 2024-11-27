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
void updateFlags(uint32_t);
void displayRegisters();
void toUpper(string&);

uint32_t reg[8]= {0};
uint8_t N=0,Z=0,C=0,V=0;

void updateFlags(uint32_t answer){
    Z = (answer==0);
    N = (answer &0x80000000) != 0;
    C = (answer < 0);
    V = false;
}

void mov(int rd, uint32_t imm){
    reg[rd] = imm;
    cout << "Mov r" << rd << ", #0x" << hex << imm << endl;
    displayRegisters();
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
    int r1,r2,r3;
    uint32_t imm;

    iss >> op;
    toUpper(op);

    if(op == "MOV"){
        iss >> temp >> r1 >> temp >> imm;
        mov(r1, imm);
    }
    if(op == "ADDS"){
        iss >> temp >> r1 >> temp >> r2 >> temp >> r3;
        addition(r1,r2,r3);
    }
    if(op == "SUBS"){
        iss >> temp >> r1 >> temp >> r2 >> temp >> r3;
        subtraction(r1,r2,r3);
    }
    if(op == "ANDS"){
        iss >> temp >> r1 >> temp >> r2 >> temp >> r3;
        andOp(r1,r2,r3);
    }
    if(op == "ORR"){
        iss >> temp >> r1 >> temp >> r2 >> temp >> r3;
        orOp(r1,r2,r3);
    }
    if(op == "XOR"){
        iss >> temp >> r1 >> temp >> r2 >> temp >> r3;
        xorOp(r1,r2,r3);
    }      
    else if (op == "LSRS") {
        iss >> temp >> r1 >> temp >> r1 >> temp >> imm;
        lsrOp(r1, r2, imm);
    }
    else if (op == "LSLS") {
        iss >> temp >> r1 >> temp >> r1 >> temp >> imm;
        lslOp(r1, r2, imm);
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
    updateFlags(reg[rd]);
    cout << "ADD r" << rd << ", r" << rn << ", r" << rm << endl;
    displayRegisters();
}

void subtraction(int rd, int rm, int rn){
    reg[rd] = reg[rn]-reg[rm];
    updateFlags(reg[rd]);
    cout << "SUB r" << rd << ", r" << rn << ", r" << rm << endl;
    displayRegisters();
}

void andOp(int rd, int rn, int rm) {
    reg[rd] = reg[rn] & reg[rm];
    updateFlags(reg[rd]);
    cout << "AND r" << rd << ", r" << rn << ", r" << rm << endl;
    displayRegisters();
}

void orOp(int rd, int rn, int rm) {
    reg[rd] = reg[rn] | reg[rm];
    updateFlags(reg[rd]);
    cout << "ORR r" << rd << ", r" << rn << ", r" << rm << endl;
    displayRegisters();
}

void xorOp(int rd, int rn, int rm) {
    reg[rd] = reg[rn] ^ reg[rm];
    updateFlags(reg[rd]);
    cout << "XOR r" << rd << ", r" << rn << ", r" << rm << endl;
    displayRegisters();
}

void lslOp(int rd, int rn, uint32_t imm) {
    reg[rd] = reg[rn] << imm;
    updateFlags(reg[rd]);
    cout << "LSL r" << rd << ", r" << rn << ", #" << imm << endl;
    displayRegisters();
}


void lsrOp(int rd, int rn, uint32_t imm) {
    reg[rd] = reg[rn] >> imm;
    updateFlags(reg[rd]);
    cout << "LSR r" << rd << ", r" << rn << ", #" << imm << endl;
    displayRegisters();
}

void cmpOp(int rd, int rn, int rm) {
    int answer = reg[rn] - reg[rm];
    updateFlags(reg[rd]);
    cout << "LSR r"  << rn << ", r" << rm << endl;
    displayRegisters();
}

void tstOp(int rd, int rn, int rm) {
    int answer = reg[rn] & reg[rm];
    updateFlags(reg[rd]);
    cout << "TST r"  << rn << ", r" << rm << endl;
    displayRegisters();
}