

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;
#ifndef PLATFORM_H
#define PLATFORM_H

class Platform: public Drawable
{

  public:
  Platform();

  void setPlType(int kind);
  void set_position();

  float x;
  float y;
  float shift=1;
  int type;

  bool is_movable();


  void move();
  public:
    ~Platform() override;
  private:
    Texture platform_texture[3];
    Sprite sprite_;

   protected:
    void draw(RenderTarget& target, RenderStates states) const override;
};
#endif