/**
* Trying out random functions in C++
 *
 * To get better aquainted with what to use at which points in time.
 *
 * @author Bendik S. Kristoffersen
*/

#include "iostream"
#include "iomanip"
#include "string"
#include "vector"
#include "LesData2.h"
using namespace std;


struct Lego{
    int pieces,
        code;
    string nameLego;
    // string& nvn, reference operator
    Lego(const int p, const int c, const string& nvn) { pieces = p; code = c; nameLego = nvn; }
};


void writeVector(vector <int> vect);
void addLego(int a, int b, string c);

/*
 * Main program start:
 */
int main(){
    int i;

    // Showing different way to create/define vectors:
    vector <int> tall;                  // empty vector
    vector <int> tall2(100);         // initialized 100-long int vector

    vector <int> tall3 {2, 5, 7};       // With vector, unlike array, dont have to '='

    vector <int> tall4(20, 7); // Will print 20 7's.
    vector <int> tall5(tall3);           // Vector tall5 copies tall3
    vector <char> letters(10, 'x'); // 10 x's
    vector <string> name(10);         // Vector with 10 empty strings

    // Can increase length of a vector infinitely many times, but only when needed
    // which is huge. Don't have to know length. Simply push_back and add element at the back of the list

    cout << "'tall3':";
    for (i = 0; i < 3; i++){
        cout << ' ' << tall3[i];
    }
    cout << "\n\n";

    cout << "'tall3': ";
    for (i = 0; i < tall3.size(); i++){
        cout << ' ' << tall3[i];
    }
    cout << "\n\n";

    cout << "'tall4': ";        // Range-based for loop
    for (int val : tall4){
        cout << ' ' << val;
    }
    cout << "\n\n";


    // ****************************************************************

    int value;
    cout << "Input 5 numbers: \n";
    for (i = 0; i < 5; i++){
        value = lesInt("\tNumber", 0, 1000);
        tall.push_back(value);      // As 'tall' is initiall empty, add new elements at back
    }

    cout << "\n'tall':\n";
    for (i = 0; i < tall.size(); i++){
        cout << ' ' << tall[i];
    }
    cout << "\n\n";

    tall.pop_back();    // pop_back removes last element in vector
    tall.pop_back();    // since two pop_back's, only 3 out of original 5 digits remain

    cout << "\n'tall'\n";
    for (i = 0; i < tall.size(); i++){
        cout << ' ' << tall[i];
    }
    cout << "\n\n";

    tall.clear(); // pretty implicit or

    cout << "\n'tall' size after being cleared: " << tall.size() << "\n\n";

    if (tall.empty()) cout << "'tall' is completely empty!!!\n\n";

    cout << "\n'tall2' has room for " << tall2.capacity() << " elements.\n\n";

    // *******************************************************************************

    Lego l = {900, 25, "Toy"};
    Lego* legoptr;

    vector <Lego> legos;

    legos.push_back(l);  // Adds existing
                                // New = malloc in C
    legoptr = new Lego(2000, 25, "BatMobile");
    legos.push_back(*legoptr);  // Adds COPY of newly made
    delete legoptr;             // Same as free from C
    legoptr = nullptr;

    legoptr = new Lego(7600, 69, "StarDestroyer");
    legos.push_back(*legoptr);
    delete legoptr;
    legoptr = nullptr;

    cout << "Element in legos: " << legos.size() << "\n\n";

    cout << "'legos' content: \n";
    for (i = 0; i < legos.size(); i++){
        cout << setw(3);
        cout << "\nAmount of pieces: " << legos[i].pieces << ", Code: " <<
                    legos[i].code << ",\nand the name of legopiece:\t" << legos[i].nameLego;
    }
    cout << "\n\n";

// ****************************************************************************

    vector <Lego*> legos2;

    for (i = 0; i <= 5; i++){               // + i to increment package number
        legos2.push_back(new Lego(1800, 26 + i, "Star"));
    }
    legoptr = new Lego(4300, 36, "Millenium Falcon");  // New struct
    legos2.push_back(legoptr);                                    // Pointer to nr. 6

    // *************************************************************************
    // ** NB: In vector there are pointers. NB NB NB
    // ** Both what we point to and the pointer needs to be deleted, when
    // ** we want to remove something from the vector
    // *************************************************************************

    cout << "Number of elements in 'legos2: " << legos2.size() << "\n\n";

    cout << "'legos' content:\n";
    for (i = 0; i < legos2.size(); i++){
        cout << "\nAmount of pieces: " << legos2[i]->pieces << ",\t\n code: " << legos2[i]->code <<
                                            "\n and name of piece: " << legos2[i]->nameLego;
    } cout << "\n\n";

    for (i = 0; i < legos2.size(); i++){    // Delete all the OBJECTS pointed to
        delete legos2[i];
    }
    legos2.clear();                        // Delete the POINTER
    cout << "Number of elements POINTED to in 'legos2': " // Empty vector
            << legos2.size() << "\n\n";

    return 0;
}


// Functions

/*
 * Asks user for input about new lego
 *
 */
void addLego(){

}