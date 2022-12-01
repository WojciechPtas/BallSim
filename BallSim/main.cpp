#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.hpp"
#include "SquareMatrix.hpp"
#include "BallSim_state.h"
#include "Engine.h"
using namespace algebra;
using namespace std;
 
int main()
{
    BallSim_State b;
    std::shared_ptr<sf::RenderWindow> win = std::make_shared<sf::RenderWindow> (sf::VideoMode(b.getWinSize().x,b.getWinSize().y), "SFMl works!");
    win->setFramerateLimit(60);
    Engine en(b);
    

    while (win->isOpen()) {
        sf::Event event;
        while (win->pollEvent(event)) {
            switch (event.type)
            {
                // window closed
            case sf::Event::Closed:
                win->close();
                break;

                // key pressed
            case sf::Event::MouseButtonPressed:
                
                if (event.mouseButton.button = sf::Mouse::Right) {
                    en.addBall(sf::Vector2f( (float)event.mouseButton.x, (float)event.mouseButton.y ));
                }
                break;

                // we don't process other types of events
            default:
                break;
            }
        }
        en.update();
        en.render(win);
    }
    
    
    
    
    
    //SquareMatrixf s(1, 1, 2, 4);
    //SquareMatrixf a(3, 0, 0, 4);
    //sf::Vector2f b(0, 0), b1(3,4);
    //SquareMatrixf c(b,b1);
    //sf::Vector2f d = c * b1;
    ////sf::Vector2f d1 = c.inverse() * d;
    //std::cout << a[1][1];
}