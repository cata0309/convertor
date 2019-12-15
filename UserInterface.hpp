#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"Defines.hpp"
#include<iostream>
#include<cstring>
#include<fstream>
struct UIData {
  //////////////////////////////////////// Declarari variabile resurse ////////////////////////////////////////
  struct{
    std::ifstream fonts_in;
    std::ifstream songs_in;
  }files;
  struct {
    sf::RectangleShape font;
    sf::RectangleShape font_size;
    sf::RectangleShape input;
    sf::RectangleShape output;
    sf::RectangleShape song;
    sf::RectangleShape volume;
  } boxes;
  struct {
    sf::Color back;
    sf::Color text;
  } colors;

  //font-uri
  struct {
    sf::Font font;
    bool applied = false;
    char name[MAX_FONT_NAME];
  } fonts[MAX_NR_FONTS];
  //melodiile de fundal
  struct {
    sf::Music song;
    bool playing = false;
    char name[MAX_SONG_NAME];
  } songs[MAX_SONGS];
  //sunete
  struct {
    sf::Sound click;
    sf::Sound error;
    sf::Sound typing;
  } sounds;
  struct {
    sf::SoundBuffer click;
    sf::SoundBuffer error;
    sf::SoundBuffer typing;
  } sound_buffers;

  struct {
    sf::Sprite spr_delete;
    sf::Sprite spr_equal;
    sf::Sprite spr_left_font;
    sf::Sprite spr_left_font_size;
    sf::Sprite spr_left_song;
    sf::Sprite spr_left_vol;
    //sprite folosit pentru butonul de muzica
    sf::Sprite spr_mode;
    sf::Sprite spr_music;
    //sprite folosit pentru butonul de setari
    sf::Sprite spr_right_font;
    sf::Sprite spr_right_font_size;
    sf::Sprite spr_right_song;
    sf::Sprite spr_right_vol;
    sf::Sprite spr_settings;
  } sprites;
  struct {
    sf::Text label_settings;
    sf::Text label_font;
    sf::Text label_font_size;
    sf::Text label_song_name;
    sf::Text label_volume;

    sf::Text font_name;
    sf::Text font_size;
    sf::Text song_name;
    sf::Text song_volume;

    sf::Text input;
    sf::Text output;

  } texts;

  //variabile ce vor avea rolul de intrerupatoare
  //switch_dark_mode=false daca a fost apasat butonul de schimbare a interfatei la modul dark
  bool switch_dark_mode = false;
  //switch_music=false daca a fost apasat butonul de muzica pentru a inchide muzica
  bool switch_music = true;
  //switch_settings=true daca a fost apasat butonul de setari si va aparea interfata cu setari
  bool switch_settings = false;

  char input[MAX_INPUT];
  //variabila ce va tine valoarea volumului la care va fi setat initial muzica
  int volume = 100;
  int number_of_fonts;
  int number_of_songs;
  int font_index = 0;
  int font_size = 24;
  int song_index = 0;
  //textura globala
  sf::Texture texture;
};

void updateTextFontSize(UIData &);
void updateTextFonts(UIData &);
void updateTextColor(UIData &);
void setTextPositions(UIData &);
void setLabelTextPositions(UIData &ui_data);

void loadResources(UIData &, bool &);

void setBoxesDetails(UIData &);
void setBoxesFillColor(UIData &);
void setBoxesOutlineColor(UIData &);
void setBoxesOutlineThickness(UIData &);
void setBoxesPositions(UIData &);
void setBoxesSizes(UIData &);

void setSpritesDetails(UIData &);
void setSpritesPositions(UIData &);
void setSpritesScale(UIData &, float);
void setSpritesTextures(UIData &);

void setupUI(UIData &);
void drawUI(UIData &, sf::RenderWindow &);
void updateSettingsView(UIData &);

void changeMusicSprite(UIData &);
void changeModeSprites(UIData &);
void changeSong(UIData &, bool);
void changeFont(UIData &, bool);
void changeSize(UIData &, bool);
void changeVolume(UIData &, bool);
void convertIToC(int, char *);
bool contains(sf::FloatRect &, sf::Vector2i &);

void setVolume(UIData&);
void handleEvents(sf::RenderWindow&,sf::Event&,UIData&);