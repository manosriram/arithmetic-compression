#include "Decode.hpp"

void Decode::decodeSymbol(map<char, int> freq, double finalOut, map<char, pair<double, double> > cumulativeOut) {
    string outF;
    while (true) {
        pair<char, double> now = findRangeSymbol(freq, finalOut, cumulativeOut);

        outF += now.first;

        finalOut = now.second;

        if (now.first == '$') break;
    }
    cout << outF;
}

pair<char, double> Decode::findRangeSymbol(map<char, int> freq, double range, map<char, pair<double, double> > cumulativeOut) {
    for (auto itr = freq.begin();itr != freq.end(); ++itr) {
        if (range >= cumulativeOut[itr->first].first && range <= cumulativeOut[itr->first].second) {

            double rn = cumulativeOut[itr->first].second - cumulativeOut[itr->first].first;
            range -= cumulativeOut[itr->first].first;
            range /= rn;
            return make_pair(itr->first, range);
        }
    }
}
