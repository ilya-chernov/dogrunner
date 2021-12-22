#include <SFML/Graphics.hpp>
#include "functions.hpp"
//const int H = 12;
const int W = 40;
using namespace sf;

float offsetX = 0, offsetY = 0;
namespace kt
{
		float dx, dy;
		FloatRect rect;
		bool onGround;
		Sprite sprite;
		float currentFrame;

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
		
		PLAYER::PLAYER(Texture & image)
		{
			sprite.setTexture(image);
			rect = FloatRect(7 * 32, 9 * 32, 40, 50);

			dx = dy = 0.1;
			currentFrame = 0;
		}

		void PLAYER::update(float time)
		{

			rect.left += dx * time;
			Collision(0);

			if (!onGround) dy = dy + 0.0005 * time;
			rect.top += dy * time;
			onGround = false;
			Collision(1);


			currentFrame += 0.005 * time;
			if (currentFrame > 6) currentFrame -= 6;

			if (dx > 0) sprite.setTextureRect(IntRect(40 * int(currentFrame), 244, 40, 50));
			if (dx < 0) sprite.setTextureRect(IntRect(40 * int(currentFrame) + 40, 244, -40, 50));


			sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

			dx = 0;
		}

		void PLAYER::Collision(int dir)
		{
			for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
			{
				for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
				{
					if (TileMap[i][j] == 'B')
					{
						if ((dx > 0) && (dir == 0)) rect.left = j * 32 - rect.width;
						if ((dx < 0) && (dir == 0)) rect.left = j * 32 + 32;
						if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0;   onGround = true; }
						if ((dy < 0) && (dir == 1)) { rect.top = i * 32 + 32;   dy = 0; }
					}

					if (TileMap[i][j] == '0')
					{
						TileMap[i][j] = ' ';
					}

				}

			}
		}


}

