#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <platform.h>
#include <gamestate.h>
class Gamedraw  
{

  
  buffer.loadFromFile("jump.wav");
  sound.setBuffer(buffer);
  hero_texture.loadFromFile("./hero.png");
  hero1_texture.loadFromFile("./hero1.png");
  hero2_texture.loadFromFile("./atack.png");
  hero.setTexture(hero_texture);
  hero.setScale(0.27, 0.27);
  hero.setPosition(game.window_width / 2 - hero.getGlobalBounds().width / 2, game.window_width / 4 * 3 - hero.getGlobalBounds().height / 2);
  Platform platform[game.count_platform];
  for(int i=0;i<game.count_platform;i++) {
    platform[i].setPlType(rand()%2);
  }

  for(int i=0;i<(game.count_platform / 2);i++)
  {
    platform[i].x = rand() % r1 - 28;
    platform[i].y = rand() % r2 - 28;
    platform[i].set_position();
  }
  for(int i=(game.count_platform / 2);i<game.count_platform;i++)
  {
    platform[i].x=rand() % r1 -28;
    platform[i].y=rand() % r2 -28-400;
    platform[i].set_position();
     
  }
  getr=posy_min(game.count_platform,platform);
  hero.setPosition(platform[getr].x,platform[getr].y-60);
  font.loadFromFile("./score.ttf");
  text.setFont(font);
  text.setCharacterSize(50);
  text.setPosition(game.window_width-100, 5);
  text.setFillColor(Color::Black);
  Fone_texture.loadFromFile("fone.png");
  fone.setTexture(Fone_texture);
  fone.setScale(1.15,1);
  Fone1_texture.loadFromFile("fone.png");
  fone1.setTexture(Fone1_texture);
  fone1.setScale(1.15,1);
  fone1.setPosition(0,-750);
  fone2.setTexture(Fone1_texture);
  fone2.setScale(1.15,1);
  fone2.setPosition(0,0);


};
