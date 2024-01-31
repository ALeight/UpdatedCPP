#include "iostream"
using namespace std;

struct Tid{
    int time;
    int minutt;
    int sekund;
};


struct Tid storst(const struct Tid tid1, const struct Tid tid2) {
    int total1 = tid1.time * 3600 + tid1.minutt * 60 + tid1.sekund;
    int total2 = tid2.time * 3600 + tid2.minutt * 60 + tid2.sekund;

    if (total1 > total2){
        return tid1;
    } else
        return tid2;
}

/**
 * Main program start:
 */

int main(){
    Tid tid1, tid2, tid3, tid4;

    tid1 = {15, 24, 11};
    tid2 = {12, 26, 8};
    tid3 = {13, 54, 11};
    tid4 = {14, 25, 25};

    int total1 = storst(tid1, tid2).time * 3600 + storst(tid1, tid2).minutt * 60 + storst(tid1, tid2).sekund;
    int total2 = storst(tid3, tid4).time * 3600 +
                 storst(tid3, tid4).minutt * 60 + storst(tid3, tid4).sekund;

    if (total1 > total2){
        cout << "Biggest timestamp is:\n";
        cout << storst(tid1, tid2).time << ":" << storst(tid1, tid2).minutt
             << ":" << storst(tid1, tid2).sekund << "\n";
    } else {
        cout << "Biggest timestamp is:\n";
        cout <<  storst(tid3, tid4).time << ":" << storst(tid4, tid4).minutt
             << ":" << storst(tid4, tid4).sekund << "\n";
    }

/*
    if (Tid(tid2, tid1)){
        cout << "'tid2' timestamp is biggest.\n";
    } else
        cout << "'tid3' timestamp is biggest.\n";

    if (Tid(tid3, tid4)){
        cout << "'tid3' timestamp is biggest.\n";
    } else
        cout << "'tid4' timestamp is biggest.\n";

    if (Tid(tid2, tid3)){
        cout << "'tid2' timestamp is biggest.\n";
    } else
        cout << "'tid3' timestamp is biggest.\n";

    if (Tid(tid4, tid1)){
        cout << "'tid4' timestamp is biggest.\n";
    } else
        cout << "'tid1' timestamp is biggest.\n";

    // cout << "Tidspunktet er: " << tid1.time << ":" << tid1.minutt << ":" << tid1.sekund;
*/

    return 0;
}