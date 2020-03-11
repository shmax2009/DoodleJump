#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <platform.h>
#include <gamestate.h>
#ifndef GAMEDRAW_H
#define GAMEDRAW_H
class GameDraw
{
    /*Gamedraw();
    ~Gamedraw();*/

  public:
  SoundBuffer buffer; 
  Sound sound;
  Texture hero_texture;
  Texture hero1_texture;
  Texture hero2_texture;
  Platform platform[game.count_platform];
  Font font;
  Text text;
  Texture Fone_texture;
  Sprite fone;
  Texture Fone1_texture;
  Sprite fone1;
  Sprite fone2;
  Event ev{};
}
#endif