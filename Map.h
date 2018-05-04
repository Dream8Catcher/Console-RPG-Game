#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "Player.h"

class MainMap
{
private:
	static const int width = 30;
    static const int height = 20;
    int StartMap[height][width];
public:
    Player player;
	int Map[height][width];
	MainMap();
	~MainMap(){};
	void DrawMap();
	void SwapMap();
};

#endif // MAP_H_INCLUDED
