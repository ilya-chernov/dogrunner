#include <SFML/Graphics.hpp>
#include "functions.hpp"
//const int H = 12;
const int W = 40;
using namespace sf;
using namespace kt;



int main()
{
	String TileMap[12] = {

	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	"B                                B     B",
	"B                                B     B",
	"B                                B     B",
	"B                                B     B",
	"B         0000                BBBB     B",
	"B                                B     B",
	"BBB                              B     B",
	"B              BB                BB    B",
	"B              BB                      B",
	"B    B         BB         BB           B",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

	}; 

	float offsetX = 0, offsetY = 0; 
    RenderWindow window( VideoMode(600, 400), "Dog Runner Alpha");

	Texture t;
	t.loadFromFile("fang.png");

	float currentFrame=0;

    PLAYER p(t);

    Clock clock;

	RectangleShape rectangle( Vector2f(32,32));

    while (window.isOpen())
    {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time/700;
		
		if (time>20) time = 20;

		Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

	    if (Keyboard::isKeyPressed(Keyboard::Left)) 
		{
			p.dx = -0.1;

		}

	    if (Keyboard::isKeyPressed(Keyboard::Right)) 
		{
			p.dx = 0.1;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) 
		{
			if (p.onGround) { p.dy=-0.35; p.onGround=false;}
		}

		p.update(time);

		if (p.rect.left>600) offsetX = p.rect.left - 600;
        offsetY = p.rect.top - 300;

		window.clear(Color::White);


		 for (int i=0; i<12; i++)
			 for (int j=0; j<W ; j++)
			 { 
				  if (TileMap[i][j]=='B') rectangle.setFillColor(Color::Black);

			      if (TileMap[i][j]=='0')  rectangle.setFillColor(Color::Green);

				  if (TileMap[i][j]==' ') continue;

		          rectangle.setPosition(j*32-offsetX,i*32 - offsetY) ; 
		          window.draw(rectangle);
	       	 }
    
		window.draw(p.sprite);
        window.display();
    }

    return 0;
}