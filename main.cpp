
#include <thread>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include<iostream>
#include<cmath>
using namespace sf;
using namespace std;

int posy_min( const int i,float arr[]) {
   int r=0;
   for(int f=1;f<i;f++){
  if(arr[r]<arr[f]) r=f;
   }
   return r;
}

class Platform: public Drawable
{

  public:
  Platform()
  {
    platform_texture_.loadFromFile("./plat.png");
    sprite_.setTexture(platform_texture_);
  }

  void set_position(const Vector2f point)
  {
    sprite_.setPosition(point);
  }

public:
  ~Platform() override;

private:
  Texture platform_texture_;
  Sprite sprite_;

protected:

  void draw(RenderTarget& target, RenderStates states) const override;
};

void Platform::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
target.draw(sprite_);
}

Platform::~Platform() = default;

int main()
{
  srand(static_cast<unsigned int>(time(nullptr)));
  const auto fps = 60.0f; // The number of updates each second

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
  hero_texture.loadFromFile("./hero.png");
  hero1_texture.loadFromFile("./hero1.png");
const int r1=451-57;
const int r2=500 -57;
float posx[40];
float posy[40];
Platform platform[40];
for(int i=0;i<20;i++){
  posx[i]=rand() % r1 - 28;
  posy[i]=rand() % r2 - 28;
  platform[i].set_position({posx[i],posy[i]});
}
for(int i=20;i<40;i++){
        posx[i]=rand() % r1 -28;
        posy[i]=rand() % r2 -28-400;
  platform[i].set_position({posx[i],posy[i]});
}

  //Spritesyhhhsssssh
  Sprite hero;
  hero.setTexture(hero_texture);
  hero.setScale(0.27, 0.27);
  
  hero.setPosition(window_width / 2 - hero.getGlobalBounds().width / 2, window_height / 4 * 3 - hero.getGlobalBounds().height / 2);
  int getr=0;
  getr=posy_min(20,posy);
  hero.setPosition(posx[getr],posy[getr]-60);
  //Texts & Fonts
  Font font;
  font.loadFromFile("./score.ttf");
  Text text;
  text.setFont(font);
  text.setCharacterSize(30);
  text.setPosition(10, 10);
  text.setFillColor(Color::Red);
   Texture Fone_texture;
   Fone_texture.loadFromFile("fone.png");
   Sprite fone;
   fone.setTexture(Fone_texture);
   fone.setScale(1.15,1);
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
  
  while (window.isOpen())

  {    
   herox=hero.getPosition().x;
   heroy=hero.getPosition().y;

   
    for(int i=0;i<40;i++){
       if((( (abs(posx[i]-herox)<30)) and ((posy[i]-(heroy)<70)and (posy[i]-(heroy)>60))) and(v_Hero<=0) ){ v_Hero=8;
          sound.play();}
           }
        
   for(int i=0;i<40;i++){
   //posx[i]=posx[i]+1;
   posy[i]=posy[i]+v_Hero;
   platform[i].set_position({posx[i],posy[i]});

   
   } 
    
    y_hero_now=hero.getPosition().y;
    if(hero.getPosition().x<=-10) hero.setPosition(449,y_hero_now);
     if(hero.getPosition().x>=450) hero.setPosition(-9,y_hero_now);

    while (window.pollEvent(ev))
    {
      if (ev.type == Event::Closed) window.close();
      //Check the key
      if (ev.type == Event::KeyPressed)
      {
        if (ev.key.code == Keyboard::Right)
        {
    hero.setTexture(hero_texture);
         hero.move(6,0);
        }



  if (ev.key.code == Keyboard::Left)
        {
  hero.setTexture(hero1_texture);
         hero.move(-6,0);
        }

      }
    }
    window.clear();
    window.draw(fone);
    for(int i=0;i<40;i++){
    window.draw(platform[i]);
    
    if(posy[i]>=700){
     posx[i]=rand() % r1 -28;
        posy[i]=0;
}
    }
    window.draw(hero);
    window.display();
    count_iterration++;
  
/*   if(v_Hero<=-8) v_Hero=8; else*/   v_Hero-=gravity;

  }

  return 0;
}
