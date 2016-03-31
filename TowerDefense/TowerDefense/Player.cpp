#include "Player.h"

Player::Player(){
	health = 100;
	points = 0;
}

Player::~Player(){
}

int Player::getHealth(){
	return health;
}

void Player::setHealth(int points){
	health = points;
	if (health < 0){
		health = 0;
	}
	if (health > 100){
		health = 100;
	}
}

void Player::addHealth(int points){
	health += points;
	if (health > 100){
		health = 100;
	}
}

void Player::reduceHealth(int points){
	health -= points;
	if (health < 0){
		health = 0;
	}
}

int Player::getPoints(){
	return points;
}

void Player::setPoints(int newPoints){
	points = newPoints;
}

void Player::addPoints(int points){
	this->points += points;
}