#include <iostream>
#include <thread>
#include <chrono> //-- para controlar el retardo
#include "CFigura.h"
#include "CCirculo.h"
#include "CRectangulo.h"
#include "CPoligono.h"
#include "CmCirculos.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(2200, 1200), "SFML works!");
    srand(time(nullptr));

    CCirculo C1(&window,50.f,70.f, 70.f,2,2,sf::Color::Cyan );
    CRectangulo R1(&window, 80.f, 40.f,35.f,35.f, 1,1,sf::Color::Green);
    CPoligono   T1(&window, 30.f,3.f, 10.f,10.f,7,7,sf::Color::Yellow );
    CPoligono   P1(&window, 30.f,5.f, 90.f,90.f,5,5,sf::Color::Magenta);
    CPoligono   O1(&window, 30.f,8.f, 40.f,40.f,6,6,sf::Color::Red );
    CFigura     *pFigura= nullptr;

    pFigura = new CPoligono(&window,80.f,7,45.f,45.f, 4,4,sf::Color::Yellow);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
              window.close();
            }
        }

        window.clear();
        C1.Muestrate();
        R1.Muestrate();
        T1.Muestrate();
        P1.Muestrate();
        O1.Muestrate();
        pFigura->Muestrate();
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        C1.Muevete();
        R1.Muevete();
        T1.Muevete();
        P1.Muevete();
        O1.Muevete();
        pFigura->Muevete();
    }
    delete pFigura;
    pFigura= nullptr;
    return 0;
}