#include "Incs.hpp"
#include "Encode.hpp"
#include "Encode.cpp"
int main() {
    cout << fixed << setprecision(16);
    string data = "Bill Gates and Steve Jobs.";

    Encode enc;
    enc.buildTable(data);
    enc.printFreq(enc.freq);
    enc.encodeSymbol(data);
}

