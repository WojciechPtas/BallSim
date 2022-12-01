#ifndef BALL
#define BALL
#include <stdlib.h>     
#include <time.h> 
#include <SFML/Graphics.hpp>
#include "BallSim_state.h"

class Ball {
private:
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    std::unique_ptr<sf::CircleShape> circle;
    unsigned int id;
public:
    Ball() : velocity({0.f,0.f}), acceleration({0.f,0.f}), circle(nullptr), id(0) {};

    Ball(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f acc, float radius, unsigned int id)  {
        this->circle = std::make_unique<sf::CircleShape>(radius);
        srand(time(NULL));
        this->circle->setFillColor(sf::Color::Color(rand()%255, rand() % 255, rand() % 255, 255));
        this->setPosition(pos);
        this->setVelocity(vel);
        this->setAcceleration(acc);
        this->id = id;
    }
    void setVelocity(sf::Vector2f a) {
        this->velocity = a;
    }
    sf::Vector2f getVelocity() { return this->velocity; }
    void inverseYVelocity(float scale=1.f) { this->velocity.y *= (-1)*scale; }
    void inverseXVelocity(float scale=1.f) { this->velocity.x *= (-1)*scale; }
    void setAcceleration(sf::Vector2f a) {
        this->acceleration = a;
    }
    void setYAcceleration(float a) {
        this->acceleration.y = a;
    }
    void setXAcceleration(float a) {
        this->acceleration.x = a;
    }
    void setXPosition(float a) {
        this->circle->setPosition(a, this->circle->getPosition().y);
    }
    void setYPosition(float a) {
        this->circle->setPosition(this->circle->getPosition().x, a);
    }
    sf::Vector2f getPosition() { return this->circle->getPosition(); }
    void update() {
        this->velocity.x += this->acceleration.x;
        this->velocity.y += this->acceleration.y;
        this->circle->move(this->velocity);
        //std::cout << this->velocity.y << std::endl;             //
        if (this->circle->getPosition().y > 650.f) {            // It should be dealt with in engine
            this->velocity.y = this->velocity.y * (-1);
            this->setPosition({ this->circle->getPosition().x, 650.f });
        //std:cout << "change\n";                                                //
        }                                                       //
    }
    void render(std::shared_ptr<sf::RenderTarget> win) {
        win->draw(*(this->circle));
    }
    void setPosition(sf::Vector2f a) {
        this->circle->setPosition(a);
    }
    unsigned long getId() { return this->id; }
    bool intersects(const Ball& b) {
        float distance = (float)sqrt(pow((circle->getPosition().x - b.circle->getPosition().x), 2) + pow((circle->getPosition().y - b.circle->getPosition().y), 2));
        return distance <= (b.circle->getRadius() + this->circle->getRadius());
    }

};
#endif