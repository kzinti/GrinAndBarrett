#pragma once

class Grin {
	int xPos, yPos, spriteState; 
	map<string, int> grinState;
	void moveRight();
	void moveLeft();
	void stand();
	void leftOrRight();
	void shoot();
	void showHide(string show);
	
public:
	Grin(void);
    ~Grin(void);
	void move();
	void draw();
};

