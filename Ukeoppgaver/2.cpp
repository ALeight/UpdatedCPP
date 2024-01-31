#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

const int MINTEMP   = -70;   ///<  Absolutt laveste mulige temperatur.
const int MAXTEMP   =  70;   ///<  Absolutt høyeste mulige temperatur.
const int MAXNEDBOR = 200;   ///<  Absolutt høyeste mulige nedbør pr.døgn.
const int MINDAGER  =   5;   ///<  Minimum antall dager i en måned.
const int MAXDAGER  =  31;   ///<  Maksimum antall dager i en måned.

/**
 *  Hovedprogrammet:
 */
int main ()  {
    char svar;
    int  antDager,
        min,
        max,
        nedbor,
        totMin,
        totMax,
        totNedbor;
    int  alleMin,
        alleMax,
        alleNedbor;

    cout << "\nLese inn verdata for en maaned (J/n): ";
    cin >> svar;

    while (svar != 'N'  &&  svar != 'n') {
        do {
            cout << "Antall dager i maaneden (" << MINDAGER << "-" << MAXDAGER <<"): ";
            cin >> antDager;
        } while (antDager < MINDAGER  ||  antDager > MAXDAGER);

        for (int i = 0;  i < antDager;  i++)  {
            cout << "\nDag nr." << i + 1 << ": ";

            do {
                cout << "\tMinimumstemp (" << MINTEMP << "til " << MAXTEMP << "):";
                cin >> min;
            } while(min < MINTEMP ||  min > MAXTEMP);
            alleMin = min;

            do {
                cout << "\tMaksimumstemp (" << min << " til " << MAXTEMP << "): ";
                cin >> max;
            } while(max < min  ||  max > MAXTEMP);
            alleMax = max;

            do {
                cout << "\tNedbor (0 til " << MAXNEDBOR << "): ";
                cin >> nedbor;
            } while(nedbor < 0  ||  nedbor > MAXNEDBOR);
            alleNedbor = nedbor;
        }


        cout << "\n\nGjennomsnittlig min.temp: "<< (float)totMin/antDager <<" grader C\n";
        cout << "Gjennomsnittlig max.temp: "<< (float)totMax/antDager << "grader C\n";
        cout << "Gjennomsnittlig nedbor:   "<< fixed << setprecision(2) << (float)totNedbor/antDager <<" mm\n";
        cout <<"Total nedbor i maaneden:   "<< totNedbor <<" mm\n", totNedbor;

        cout << "\nLese inn verdata for en maaned til (J/n): ";
        cin >> svar;
    }

    cout << "\n\n\nHa en fortsatt god (ver(syk))dag!\n\n";

    return 0;
}