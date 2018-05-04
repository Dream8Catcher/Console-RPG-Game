#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

class Bullet
{
private:
	int X;
    int Y;
public:
    Bullet(){}
	Bullet(int _X, int _Y): X (_X), Y(_Y)
	{}
	~Bullet(){}
	void setX(int _X) {X = _X;}
	void setY(int _Y) {Y = _Y;}
	int getX() const {return X;}
	int getY() const {return Y;}
};


#endif // WEAPON_H_INCLUDED
