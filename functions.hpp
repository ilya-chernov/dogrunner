#pragma once
#include<SFML\Graphics.hpp>
const int H = 12;
using namespace sf;
namespace kt
{
	class PLAYER {

	public:

		float dx, dy;
		FloatRect rect;
		bool onGround;
		Sprite sprite;
		float currentFrame;

		String TileMap[H] = {

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

		PLAYER(Texture& image);

		void update(float time);

		void Collision(int dir);
	
	};
}
