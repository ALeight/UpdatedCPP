/*
 * Lego information storage
 *
 * The purpose of this project is to write my own project
 * using what we learn in class, to get a better grasp,
 * and to actually have to think for myself, what I want to create
 *
 * PS: I f***ing love Lego
 *
 * @author Bendik S. Kristoffersen
 */

#include "iostream"
#include "iomanip"
#include "string"
#include "vector"
#include "LesData2.h"
using namespace std;


const int maxProd = 300;     ///< Max. products in sortiment


struct Lego {
    string namelego;
    int pieces, code,
            age, price;
    // Last part is CONSTRUCTOR: within a struct opposed to CLASS
    Lego(const string& nvn, const int p, const int c, const int a, const int pr)
    { namelego = nvn; pieces = p; code = c; age = a; price = pr; }
};


// Function declarations
void addLego();
int findLego(const string& nvn);
void adjustPrice();
string reviewProduct(string s);


vector <Lego*> gLego;       ///< Datastructur with all Legos


/*
 * Main program start:
 */
int main(){
    Lego* ptrlego;

    vector <Lego> legos;

    ptrlego = new Lego("Star Destroyer", 5600, 2323, 15, 1200);
    legos.push_back(*ptrlego); // Append item to last index
    delete ptrlego;            // Delete = free memory, same as free in C
    ptrlego = nullptr;         // Common courtesy, avoid crashes

    ptrlego = new Lego("Millenium Falcon", 4800, 2423, 15, 900);
    legos.push_back(*ptrlego);
    delete ptrlego;
    ptrlego = nullptr;

    cout << setw(3) << "Number of elements:\n" << legos.size() << "\n\n";

    cout << setw(3) << "\nThe contents so far:\n";
    for (auto & lego : legos){ // Range-based, goes through ALL legos
        cout << "\nName: " << lego.namelego << ",\namount of pieces: " << lego.pieces <<
             "\nProduct code: " << lego.code << "\nRecommended age: " << lego.age <<
             "\nAnd the price of this product: " << lego.price << "$";
    } cout << "\n\n";


    return 0;
}


/*
 * Adds a new Lego to the product sortiment
 */
void addLego(){
    string name;
    Lego* newLego;

    cout << "\tNew lego's name: "; getline(cin, name);
    // Need to confirm lego not already in sortiment
    if (newLego->namelego != 0)

}


/*
 * Find (if possible) the Lego entered
 *
 * @param nvn - Name of Lego
 */
int findLego(const string& nvn){
    for (int i = 0; i < gLego.size(); i++){
        if (gLego[i]->namelego(nvn)) return i;
    }
    return -1;
}


/*
 * Adjusts the price of the product, if discount or other
 */
void adjustPrice(){

}


/*
 * Lists out review of the product
 *
 * @param s - the string containing the review
 */
string reviewProduct(string s){

}