#include <SFML/Graphics.hpp>
#include <iostream>
#include "windows.h"

int main()
{

    int resolutionx = 1500;
    int resolutiony = 1500;
    // create the window
    sf::RenderWindow window(sf::VideoMode(resolutionx, resolutiony), "My window");
    
    sf::CircleShape shape (50.f);
    shape.setFillColor(sf::Color(150, 50, 250));
    int trueresolutionx = resolutionx - 100;

    int trueresolutiony = resolutiony - 100;
    int i = 0;
    int curentx = 0;
    int curenty = 0;
    int newx = 0;
    int newy = 0;
    int dx = 10;
    int dy = 3;


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
       
        
        window.draw(shape);
        //shape.setPosition(243.f, 368.f);
        Sleep(2);
        newx = curentx + dx;
        curentx = newx;
        newy = curenty + dy;
        curenty = newy;
        if (newx >= trueresolutionx)
        {
            dx = -dx;
        }
      
        if (newy >= trueresolutiony)
        {
            dy = -dy;
        }
        if (newx <= 0)
        {
            dx = -dx;
        }

        if (newy <= 0)
        {
            dy = -dy;
        }

        shape.setPosition(newx, newy);





        
        //shape.move(50.f, 50.f);
        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}