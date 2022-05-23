#include "gesture.cpp"
#include <vector>

using namespace std;

/*
    GestureList: Consists of gestures present in the game - default list is { ROCK, PAPER, SCISSOR }

    Tests:
        vector<Gesture> GestureList::game_gestures = {};

        GestureList::init();
        cout << GestureList::get_random_gesture().get_gesture() << endl; // outputs a random gesture
        Gesture other("OTHER");
        cout << GestureList::validate_gesture(other) << endl; // false

        GestureList::init({"ROCK", "PAPER", "SCISSOR", "OTHER"});
        cout << GestureList::validate_gesture(other) << endl; // true
*/

class GestureList {
    public:
        // Default initialization with the list { ROCK, PAPER, SCISSOR }
        static void init();

        // Custom initializer with a list of gestures
        static void init(initializer_list<string> lst);

        // Get a random gesture from the list of gestures. (Used by the computer as its strategy)
        static Gesture get_random_gesture();

        // Validating the gesture of user. A valid gesture is one that is present in the gestures list.
        static bool validate_gesture(Gesture user_gesture);
    

    protected:
        // Protected constructor to prevent instantiation of class
        GestureList() {}

    private:
        // Data structure for storing gestures of game.
        static vector<Gesture> game_gestures;
};

void GestureList::init() { 
    game_gestures.push_back(Gesture("ROCK"));
    game_gestures.push_back(Gesture("PAPER"));
    game_gestures.push_back(Gesture("SCISSOR"));
}

inline void GestureList::init(initializer_list<string> lst) { 
    game_gestures.resize(lst.size());

    int idx = 0;
    for(auto symbol: lst) {
        game_gestures[idx] = Gesture(symbol);
        idx++;
    }
}

inline Gesture GestureList::get_random_gesture() { return game_gestures[rand() % game_gestures.size()]; }

bool  GestureList::validate_gesture(Gesture user_gesture) {
    // check if gesture provided by user is present in gesture list.
    for(auto gesture: game_gestures) {
        if(gesture == user_gesture) return true;
    }

    return false;
}
