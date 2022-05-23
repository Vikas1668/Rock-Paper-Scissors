#include <iostream>
using namespace std;

/*
Gesture:    Represents gestures like rock, paper and scissor.
            A gesture has a symbol.

        Tests: 
            Gesture rock("ROCK");
            Gesture paper("PAPER");
            Gesture scissor("SCISSOR");
            Gesture rock2("rock");

            cout << rock.get_gesture() << endl; // ROCK
            cout << (rock < paper) << endl; // 0
            cout << (paper < scissor) << endl; // 0
            cout << (rock < scissor) << endl; // 2
            cout << (rock < rock) << endl; // 1
            cout << (rock == rock2) << endl; // true
*/

class Gesture {
    public:
        // Default constructor 
        Gesture() : symbol { "" } {}

        // Parametrized constructor
        Gesture(string name);

        // eqaulity operator for two gestures. 
        // Returns true if symbol of boths Gestures is same else returns false 
        bool operator== (const Gesture &rhs);

        // comparator for two gestures. ROCK over SCISSOR, PAPER over ROCK and SCISSOR over PAPER
        // Returns 0 if first Gesture is less than, 1 if equal and 2 if greater.
        int operator< (const Gesture& gesture);

        // get the gesture
        string get_gesture();

    private:
        string symbol;
};

inline Gesture::Gesture(string name) {
    for(auto &ch: name) ch = toupper(ch);
    symbol = name;
}

inline bool Gesture::operator== (const Gesture &rhs) { return symbol == rhs.symbol; }

string Gesture::get_gesture() { return symbol; }

int Gesture::operator< (const Gesture& gesture) {
    if(*this == gesture) return 1;

    string other = gesture.symbol;  
    
    if(symbol == "ROCK") {    
        if(other == "SCISSOR") return 2;
        if(other == "PAPER") return 0;
    }

    if(symbol == "PAPER") {
        if(other == "ROCK") return 2;
        if(other == "SCISSOR") return 0;
    }

    if(symbol == "SCISSOR") {
        if(other == "ROCK") return 0;
        if(other == "PAPER") return 2;
    }

    return 1;
}
