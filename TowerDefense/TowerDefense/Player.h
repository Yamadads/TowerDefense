#pragma once

class Player
{
private:
	int health;
	int points;	

	Player();
	~Player();
public:

	int getHealth();
	void setHealth(int points);
	void addHealth(int points);
	void reduceHealth(int points);

	int getPoints();
	void setPoints(int newPoints);
	void addPoints(int points);
	
	static Player& getPlayer();
	static void destroyPlayer();
};

