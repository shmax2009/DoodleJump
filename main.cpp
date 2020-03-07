
#include <thread>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include<iostream>
#include<cmath>
#include<utils.h>
#include<platform.h>
#include<gamestate.h>
using namespace sf;
using namespace std;
int main()
{
  srand(static_cast<unsigned int>(time(nullptr)));
  const auto fps = 60.0f; // The number of updates each second
  const int count_platform=40;
  //h
  GameState game;
  float horisontal_speed = 0;
  int window_width = 450;
  int window_height = 700;
  SoundBuffer buffer; 
  buffer.loadFromFile("jump.wav");
  Sound sound;
  sound.setBuffer(buffer);
  //Load the textures
  RenderWindow window(VideoMode(window_width, window_height, 32), "Doodle Jump");
  window.setFramerateLimit(fps);
  //Textures
  Texture hero_texture;
  Texture hero1_texture;
  Texture hero2_texture;
  hero_texture.loadFromFile("./hero.png");
  hero1_texture.loadFromFile("./hero1.png");
  hero2_texture.loadFromFile("./atack.png");
  const int r1=451-57;  
  const int r2=500 -57;
  Platform platform[count_platform];
  for(int i=0;i<count_platform;i++) {
    platform[i].setPlType(rand()%2);
  }

  for(int i=0;i<(count_platform / 2);i++)
  {
    platform[i].x = rand() % r1 - 28;
    platform[i].y = rand() % r2 - 28;
    platform[i].set_position();
  }
  for(int i=(count_platform / 2);i<count_platform;i++)
  {
    platform[i].x=rand() % r1 -28;
    platform[i].y=rand() % r2 -28-400;
    platform[i].set_position();
  }

  //Spritesyhhhsssssh
  Sprite hero;
  hero.setTexture(hero_texture);
  hero.setScale(0.27, 0.27);
  
  hero.setPosition(window_width / 2 - hero.getGlobalBounds().width / 2, window_height / 4 * 3 - hero.getGlobalBounds().height / 2);
  int getr=0;
  getr=posy_min(count_platform,platform);
  hero.setPosition(platform[getr].x,platform[getr].y-60);
  //Texts & Fontsint herox=hero.getPosition().x;
    //Texts & Fonts
  Font font;
  font.loadFromFile("./score.ttf");
  Text text;
  text.setFont(font);
  text.setCharacterSize(50);
  text.setPosition(window_width-100, 5);
  text.setFillColor(Color::Black);
  Texture Fone_texture;
  Fone_texture.loadFromFile("fone.png");
  Sprite fone;
  fone.setTexture(Fone_texture);
  fone.setScale(1.15,1);
  Texture Fone1_texture;
  Fone1_texture.loadFromFile("fone.png");
  Sprite fone1;
  fone1.setTexture(Fone1_texture);
  fone1.setScale(1.15,1);
  fone1.setPosition(0,-750);
   Sprite fone2;
  fone2.setTexture(Fone1_texture);
  fone2.setScale(1.15,1);
  fone2.setPosition(0,0);
  //Create the sprites
  int y_hero_now=hero.getPosition().y;
  Event ev{};
  int count_iterration=1;
  bool is_time_for_gump=true; 
  int stall=0;
  int fg=1;
  int ai=0; 
  int n=26;
  double v_Hero=8;
  const double gravity=0.16;
  int herox=hero.getPosition().x;
  int heroy=hero.getPosition().y;
  //The game while
  int score=0;
  while (window.isOpen())
  { 
    fone.move(0,v_Hero);
    fone1.move(0,v_Hero);
    if(fone.getPosition().y>=750){ 
     
     fone.setPosition(0,-750);
     }
    if(fone1.getPosition().y>=750) { 
     
    fone1.setPosition(0,-750);
    }
herox=hero.getPosition().x;
    heroy=hero.getPosition().y;
    v_Hero = if_connect_then_jump(game,count_platform,v_Hero, sound,hero,platform);        
    move_hero(count_platform,platform,v_Hero,fone,fone1);
    if_out_of_screen(hero);
    while (window.pollEvent(ev))
    {
     
      if (ev.type == Event::Closed) window.close();
      //Check the key
      if (ev.type == Event::KeyPressed)
      {
        if (horisontal_speed < 15) {
        if (ev.key.code == Keyboard::Right)
        {
          hero.setTexture(hero_texture);
          //h
          horisontal_speed +=1;
        }
        }
        if (horisontal_speed > -15) {
        if (ev.key.code == Keyboard::Left)
        {
          hero.setTexture(hero1_texture);
          //h
          horisontal_speed -=1;
        }
        }

        if(ev.key.code==Keyboard::D)
        {
            hero.setTexture(hero2_texture); 
        }
        
      } 
    }  if(abs(horisontal_speed)>0.2){
        if(horisontal_speed > 0) {
          horisontal_speed -= 0.2;
        } else {
          if(horisontal_speed < 0) {
            horisontal_speed += 0.2;
          }
        }} else horisontal_speed = 0;



    text.setString(std::to_string((score)));
    if(count_iterration % 40 == 0)
    score += 1;

    hero.move(horisontal_speed, 0);
    draw(game,count_platform,r1,fone,fone1,fone2,hero,platform,text,window,0+count_iterration,10000-count_iterration,0+count_iterration,0);
    count_iterration++;
    v_Hero-=gravity;
    if_upper_screen_min_then_do(count_platform,platform,window);
    
  }
  return 0;
}
