#include <SFML/Graphics.hpp>
#include <iostream>
#include "windows.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");
    
    sf::CircleShape shape (50.f);
    shape.setFillColor(sf::Color(150, 50, 250));

    int i = 0;
    


    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Cyan);
        if (i <= 34)
        {


            

            window.draw(shape);
            Sleep(10);
            sf::Vector2f position = shape.getPosition();
            if (i <= 17)
            {
                shape.move(50.f, 50.f);
            }
            if (i >= 17)
            {
                shape.move(-50.f, -50.f);
            }

            i++;
            if (i >= 34)
            {
                i = i - 33;
            }
        }
        
        //shape.move(50.f, 50.f);
        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}