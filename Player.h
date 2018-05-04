#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <vector>
#include "Bullet.h"

class Player
{
private:
	int X = 17, Y = 0;
public:
	Player(){};
	~Player(){};
	std::vector<Bullet*> bull;
	void setX(int _X) {X = _X;}
	void setY(int _Y) {Y = _Y;}
	int getX() const {return X;}
	int getY() const {return Y;}
	void resetXY(){ setX(17); setY(0); }
};

#endif // PLAYER_H_INCLUDED
