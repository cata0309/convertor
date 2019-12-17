#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"Defines.hpp"
#include<iostream>
#include<cstring>
#include<fstream>
struct Files {
  std::ifstream fonts_in;
  std::ifstream songs_in;
};
struct Boxes {
  sf::RectangleShape font_name;
  sf::RectangleShape font_size;
  sf::RectangleShape input;
  sf::RectangleShape output;
  sf::RectangleShape song_name;
  sf::RectangleShape song_volume;
  sf::RectangleShape sfx_volume;
};
struct Colors {
  sf::Color back;
  sf::Color text;
  sf::Color hover;
  sf::Color muted;
  sf::Color dark_color;
  sf::Color light_color;
  sf::Color settings_clicked;

  sf::Color before_hover_settings=sf::Color::Transparent;
  sf::Color before_hover_music=sf::Color::Transparent;
  sf::Color before_hover_sfx=sf::Color::Transparent;
  sf::Color before_hover_mode=sf::Color::Transparent;

  sf::Color before_hover_left_music_volume=sf::Color::Transparent;
  sf::Color before_hover_right_music_volume=sf::Color::Transparent;
  sf::Color before_hover_left_sfx_volume=sf::Color::Transparent;
  sf::Color before_hover_right_sfx_volume=sf::Color::Transparent;
  sf::Color before_hover_left_song_name=sf::Color::Transparent;
  sf::Color before_hover_right_song_name=sf::Color::Transparent;
  sf::Color before_hover_left_font_name=sf::Color::Transparent;
  sf::Color before_hover_right_font_name=sf::Color::Transparent;
  sf::Color before_hover_left_font_size=sf::Color::Transparent;
  sf::Color before_hover_right_font_size=sf::Color::Transparent;
  sf::Color before_hover_delete=sf::Color::Transparent;
  sf::Color before_hover_equal=sf::Color::Transparent;
};
struct FontList {
  sf::Font font;
  bool applied = false;
  char name[MAX_FONT_NAME];
};
struct SongList {
  sf::Music song;
  bool playing = false;
  char name[MAX_SONG_NAME];
};
struct Sounds {
  sf::Sound click[MAX_CLICKS_STROKES];
  sf::Sound error;
  sf::Sound typing[MAX_CLICKS_STROKES];
};
struct SoundBuffers {
  sf::SoundBuffer click;
  sf::SoundBuffer error;
  sf::SoundBuffer typing;
};

struct Sprites {
  sf::Sprite spr_delete;
  sf::Sprite spr_equal;

  sf::Sprite spr_mode;
  sf::Sprite spr_music;
  sf::Sprite spr_sfx;
  sf::Sprite spr_settings;

  sf::Sprite spr_left_song_vol;
  sf::Sprite spr_right_song_vol;
  sf::Sprite spr_left_sfx_vol;
  sf::Sprite spr_right_sfx_vol;
  sf::Sprite spr_left_song_name;
  sf::Sprite spr_right_song_name;
  sf::Sprite spr_left_font_name;
  sf::Sprite spr_right_font_name;
  sf::Sprite spr_left_font_size;
  sf::Sprite spr_right_font_size;
};

struct SettingsTexts {
  sf::Text label_settings;
  sf::Text label_font_name;
  sf::Text label_font_size;
  sf::Text label_song_name;
  sf::Text label_song_volume;
  sf::Text label_sfx_volume;

  sf::Text font_name;
  sf::Text font_size;
  sf::Text song_name;
  sf::Text song_volume;
  sf::Text sfx_volume;
};

struct Switches {
  bool is_dark_mode = false;
  bool is_music = true;
  bool is_sfx = true;
  bool is_settings = false;
  bool requestAnswer = false;
};
struct Volumes {
  int music = 100;
  int music_settings = 100;
  int sfx = 100;
  int sfx_settings = 100;

};
struct BaseData {
  Files files;
  Boxes boxes;
  Colors colors;
  FontList font_list[MAX_NR_FONTS];
  SongList song_list[MAX_NR_SONGS];
  Sounds sounds;
  SoundBuffers sound_buffers;
  Sprites sprites;
  SettingsTexts settings_texts;
  Switches switches;
  sf::Text input;
  sf::Text output;
  char input_text[MAX_INPUT];
  char output_text[MAX_OUTPUT];
  Volumes volumes;
  int number_of_fonts;
  int number_of_songs;
  int font_index = 0;
  int song_index = 0;
  int font_size = 24;
  bool initial_setup=true;
  sf::Texture texture;
  bool before_hover_color_capture=true;
  bool entered=true;
};
void navigateSongVolume(BaseData &, bool);
void setSongVolume(BaseData &);
void navigateSFXVolume(BaseData &, bool);
void setSFXVolume(BaseData &);

void navigateSongName(BaseData &, bool);
void setSongToPlay(BaseData &);

void navigateTextFont(BaseData &, bool);
void setTextFont(BaseData &);

void navigateTextFontSize(BaseData &, bool);
void setTextFontSize(BaseData &);

void loadAssets(BaseData &, bool &);

bool contains(sf::FloatRect, sf::Vector2i);
void convertIToC(int, char *);

void playClick(Sounds &);
void playTyping(Sounds &);

void drawStaticElements(BaseData &, sf::RenderWindow &);

void setBoxesDetails(BaseData &);

void updateBoxesAndTextsOutlineColor(BaseData &);
void changeMode(BaseData &);
void initialSetup(BaseData &);
void setSpritesDetails(BaseData &);
void setLabelsTextsPositions(BaseData &base_data);
void updateSettingsView(BaseData &);
void handleEvents(sf::RenderWindow &, sf::Event &, BaseData &);
