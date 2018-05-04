#ifndef GAME_INCLUDED
#define GAME_INCLUDED
#include "Player.h"
#include "Map.h"

class Game
{
public:
	enum State {INGAME, PAUSE, DEATH, NOACTIVE};
	State state = NOACTIVE;
	MainMap _map_;
	Player *player = &_map_.player;
    Game (){};
    ~Game(){};
    void Start();
    void Restart();
    void MainMenu();
    void StarWarsIntro();
    void getDirection();
    void shot();
    void Pause();
};

#endif // GAME_INCLUDED