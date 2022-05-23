#include "game.cpp"
using namespace std;

/*
GameManager: Handles running the game N times, storing data about N games.

Test:   
    GameManager manager(2); // 2 games to be played
    manager.start();
*/

class GameManager {
    public:
        // Default constructor
        GameManager() : n_games { 0 } {}

        // Parametrized constructor
        GameManager(int n) : n_games { n } {}

        // Greets and collects names of players 
        vector<Player> greet();

        // start the collection of N games
        void start();

    private:
        // number of games to be played
        int n_games; 

        // data about games 
        vector<Game> games;
};

vector<Player> GameManager::greet() {
    cout << "Greeting" << endl;

    cout << "Enter your name: ";
    string user_name = "";
    cin >> user_name;

    Player user(user_name);
    Player computer("COMPUTER");

    vector<Player> players {user, computer};

    return players;
}

void GameManager::start() {
    vector<Player> players = greet();

    // start series of n_games games
    for(int game_no = 1; game_no <= n_games; game_no++) {
        cout << "Game " << game_no << " starting. Get ready!!!" << endl;
        sleep(2);
        Game game;
        game.play(players);
        game.get_result(game_no);
        games.push_back(game);
    }
}
