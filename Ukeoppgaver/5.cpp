/**
* Task 5
*/

#include "iostream"
#include "../own/LesData2.h"
#include "iomanip"
using namespace std;

const int STRLEN = 40;              ///< Max.tekstlengde.
const int MAXFORELESNINGER = 10;    ///< Max.antall forelesninger

struct Forelesning{
    char emne[STRLEN/2],
        foreleser[STRLEN],
        sted[STRLEN/2];
    int timeStart, minuttStart,
        timeSlutt, minuttslutt;
};

void forelesningLesData(Forelesning* f);
void forelesningSkrivData(const Forelesning* f);

/**
* Main program start:
*/
int main(){
    Forelesning fl[MAXFORELESNINGER];  // Creates MAXF. structs

    forelesningLesData(fl);
    forelesningSkrivData(fl);

    return 0;
}


/**
 * Leser inn data om én forelesning
 * @param f - forelesningens data
 */
void forelesningLesData(Forelesning* f){

    cout << "Navn paa emne?";
    cin.getline(f->sted, STRLEN/2);
    cout << "\nForelesers navn: ";
    cin.getline(f->foreleser, STRLEN);
    cout << "\nSted: ";
    cin.getline(f->sted, STRLEN/2);

    cout << lesInt("\nTime start: ", 8, 18);
    cin >> f->timeStart; cin.ignore();
    cout << lesInt("\nMinuttstart: ", 0, 45);
    cin >> f->minuttStart; cin.ignore();
    cout << lesInt("\nTimeslutt: ", 0, 45);
    cin >> f->minuttStart; cin.ignore();
    cout << lesInt("\nOg i hvilket minutt: ", 0, 45);
    cin >> f->minuttslutt; cin.ignore();

}

/**
 * Skriver ut alle data om én forelesning
 * @param f - Structen som får skrevet ut data
 */
void forelesningSkrivData(const Forelesning* f){
    cout << "Dette er forelesningens data.";
    cout << setw(3) << fixed;
    cout    << "\nEmne: " << f->sted << "\nForelesers navn: " << f->foreleser << "\nSted for undervisning: " << f->sted
            << "\nTimestart: " << f->timeStart << "\nMinuttstart: " << f->minuttStart << "\nTimeslutt: "
            << f->timeSlutt << "\nMinuttslutt:" << f->minuttslutt;
}