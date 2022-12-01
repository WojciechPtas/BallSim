#ifndef BALLSIM_STATE
#define BALLSIM_STATE
#include <SFML/Graphics.hpp>
struct Bound {
	float lower=0.f;
	float upper;
	Bound(float p_lower, float p_upper) {
		lower = p_lower;
		upper = p_upper;
	}
};
class BallSim_State {
private:
	const sf::Vector2i window_size=sf::Vector2i(1400,800);
	const float ball_radius = 20.f;
	const Bound yBound = Bound(0.f, window_size.y - ball_radius * 2 - 10.f);
	const Bound xBound = Bound(10.f, window_size.x-ball_radius*2-10.f);
	const unsigned int framerate = 60;
	const sf::Vector2f initial_velocity = sf::Vector2f(0.f, 0.f);
	const sf::Vector2f initial_acceleration = sf::Vector2f(0.f, 1.f);
	const float gravity_acceleretation = 1.f;

public:

	const sf::Vector2i getWinSize() { return window_size; }
	const float getBallRadius() { return ball_radius; }
	const float getGravityAcceleration() { return gravity_acceleretation; }
	const sf::Vector2f getInitialVelocity() { return initial_velocity; }
	const sf::Vector2f getInitialAcceleration() { return initial_acceleration; }
	const Bound getYBound() { return yBound; }
	const Bound getXBound() { return xBound; }

};

#endif