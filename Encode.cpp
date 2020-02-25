#include "Encode.hpp"

Encode::~Encode(void) {}

Encode::Encode(void) {
    buffer = 0, bitsInBuffer = 0;
    low = 0.0, high = 0xFFFF;
    underflowBits = 0;
}

void Encode::printFreq(map<char, int> freq) {
    for (auto itr = freq.begin(); itr != freq.end(); ++itr)
        cout << itr->first << " " << itr->second << endl;
}

void Encode::buildTable(string data) {
    for (int t=0;t<data.length();++t) {
        ++freq[data[t]];
    }

    double prevProb = 0.0;
    int n = freq.size();
    for (auto itr = freq.begin(); itr != freq.end(); ++itr) {
        double prob = (double)freq[itr->first] / data.length();
        double currentProb = (double)(prevProb + prob);

        cumulativeOut[itr->first] = make_pair(prevProb, currentProb);
        // cout << cumulativeOut[].first << " " << cumulativeOut[ch].second << endl;

        // cout << itr->first << " " << prevProb << " " << currentProb << endl;
        prevProb = currentProb;
    }
}

void Encode::encodeSymbol(string data) {
    low = 0.0, high = 1.0;
    int in = -1;
    while (in != data.length()) {
        char ch = data[++in];
        // cout << cumulativeOut[ch].first << " " << cumulativeOut[ch].second << endl;

        double range = high - low;
        high = low + (range * (double) cumulativeOut[ch].second);
        low = low + (range * (double) cumulativeOut[ch].first);
    }
    // cout << low << " " << high << endl;
}

void Encode::writeTable(fstream& fileTable) {
    fileTable << "Character\tOccurences\tLow-Range\t\t\tHigh-Range" << endl;
    for (auto itr = freq.begin(); itr != freq.end(); ++itr) {
        fileTable << itr->first << "\t\t" << itr->second << "\t\t" << cumulativeOut[itr->first].first << "\t\t" << cumulativeOut[itr->first].second << endl;
    }
}

