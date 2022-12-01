#ifndef ENGINE
#define ENGINE
#include <vector>
#include <iostream>
#include "Ball.hpp"
#include "BallSim_state.h"
class Engine
{
private:
	std::vector<Ball> balls;
	unsigned int balls_created;
	BallSim_State& inf;
public:
	Engine(BallSim_State& i) : balls(std::vector<Ball>()), balls_created(0), inf(i) { balls.reserve(1000); };
	void update();
	void addBall(sf::Vector2f v);
	void render(std::shared_ptr<sf::RenderWindow> w);
};

#endif
