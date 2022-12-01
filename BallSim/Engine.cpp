#include "Engine.h"
#include "SquareMatrix.hpp"
void Engine::update()
{
	
	for (std::size_t i = 0; i < balls.size();++i) {
		this->balls[i].update();
		//std::cout << balls[i].getId() << std::endl;
		// Detect if ball is out of range, for now we only check the left, right and floor
		if (balls[i].getPosition().y > inf.getYBound().upper) {
			balls[i].setYPosition(inf.getYBound().upper);
			balls[i].inverseYVelocity();
		}
		else if (balls[i].getPosition().x > inf.getXBound().upper) {
			balls[i].setXPosition(inf.getXBound().upper);
			balls[i].inverseXVelocity();
		}
		else if (balls[i].getPosition().x < inf.getXBound().lower) {
			balls[i].setXPosition(inf.getXBound().lower);
			balls[i].inverseXVelocity();
		}
		//Collision detection
		for (size_t j = i+1; j < balls.size(); ++j) {
			if (balls[i].intersects(balls[j])) {
				algebra::SquareMatrix<float> s(balls[i].getPosition(), balls[j].getPosition());
				sf::Vector2f v1 = balls[i].getVelocity(), v2 = balls[j].getVelocity();
				v1 = s * v1; 
				v2 = s * v2; 
				float t = v1.y;
				v1.y = v2.y;
				v2.y = t;
				auto m = s.T();
				v1 = m * v1;
				v2 = m * v2;
				balls[i].setVelocity(v1);
				balls[j].setVelocity(v2);
				balls[i].update();
				balls[j].update();
			}
		}
	}
}
void Engine::addBall(sf::Vector2f pos) {
	this->balls.push_back(Ball(pos, inf.getInitialVelocity(), inf.getInitialAcceleration(), this->inf.getBallRadius(), this->balls_created++));
}

void Engine::render(std::shared_ptr<sf::RenderWindow> w)
{
	w->clear();
	for (size_t i = 0; i < balls.size(); ++i) {
		balls[i].render(w);
	}
	w->display();
}
