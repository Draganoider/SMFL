#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "windows.h"
#include <math.h> 
#include <cmath>


int trueRandom(int max)
{
    return rand() * max / 32767;
}

int main()
{
    const int N = 10;
    const int D = 50;


    int initX[N];
    int initY[N];
    
    bool p = false;
    int resolutionx = 1200;
    int resolutiony = 1500;
    // create the window
    sf::RenderWindow window(sf::VideoMode(resolutionx, resolutiony), "My window");
    
    
    int trueresolutionx = resolutionx - D*2;
    int trueresolutiony = resolutiony - D*2;

    sf::CircleShape shape[N];
    int curentx[N];
    int curenty[N];
    int newx[N];
    int newy[N];
    int dx[N];
    int dy[N];
    int Mvector[N];

    for (int i = 0; i < N; i++)
    {
        shape[i] = sf::CircleShape(D);
        shape[i].setFillColor(sf::Color(150, 50, 250));

        curentx[i] = 0;
        curenty[i] = 0;
        newx[i] = 0;
        newy[i] = 0;
        dx[i] = trueRandom(5) + 1;
        dy[i] = trueRandom(5) + 1;


        initX[i] = trueRandom(resolutionx - D*2) + D;
        initY[i] = trueRandom(resolutiony - D*2) + D;

        Mvector[i] = 0;

    }

    


  /*  sf::CircleShape shape1(100.f);
    shape1.setFillColor(sf::Color::Black);*/









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
       
        if (!p)
        {
            for (int i = 0; i < N; i++)
            {
                curentx[i] = initX[i];
                curenty[i] = initY[i];

                shape[i].setPosition(initX[i], initY[i]);
                
            }
            p = true;
        }

        for (int i = 0; i < N; i++) {


            //shape.setPosition(243.f, 368.f);
            Sleep(2);

            newx[i] = curentx[i] + dx[i];
            curentx[i] = newx[i];
            newy[i] = curenty[i] + dy[i];
            curenty[i] = newy[i];

            if (newx[i] >= trueresolutionx)
            {
                dx[i] = -dx[i];
            }

            if (newy[i] >= trueresolutiony)
            {
                dy[i] = -dy[i];
            }

            if (newx[i] <= 0)
            {
                dx[i] = -dx[i];
            }

            if (newy[i] <= 0)
            {
                dy[i] = -dy[i];
            }


            shape[i].setPosition(newx[i], newy[i]);


            window.draw(shape[i]);


            for (int k = 0; k < N; k++) {
                for (int j = k + 1; j < N; j++) {

                    if (k == j) continue;

                    double val = sqrt(pow((curentx[j] - curentx[k]), 2) + pow((curenty[j] - curenty[k]), 2));

                    if (val <= D * 2 + 10)
                    {
                        dx[k] = -dx[k];
                        dy[k] = -dy[k];

                        dx[j] = -dx[j];
                        dy[j] = -dy[j];
                    }

                }
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

