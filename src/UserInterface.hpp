#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"Defines.hpp"
#include<iostream>
#include<cstring>
#include<fstream>
#include"InputForm.hpp"
#include"Logics.hpp"

#ifndef CONVERTOR_SRC_USERINTERFACE_HPP_
#define CONVERTOR_SRC_USERINTERFACE_HPP_

struct Files {
  std::ifstream fonts_in;
  std::ifstream songs_in;
  std::ifstream themes_file;
};

struct Boxes {
  sf::RectangleShape mask_box;
  sf::RectangleShape font_name;
  sf::RectangleShape font_size;
  sf::RectangleShape font_size_visual;
  sf::RectangleShape song_name;
  sf::RectangleShape song_volume;
  sf::RectangleShape song_volume_visual;
  sf::RectangleShape sfx_volume;
  sf::RectangleShape sfx_volume_visual;

  sf::RectangleShape scroll_rect;
};
struct Theme {
  sf::Color back;
  sf::Color hover;
  sf::Color muted;
  sf::Color text;
  sf::Color button_clicked;
};
struct Colors {
  sf::Color back;
  sf::Color hover;
  sf::Color muted;
  sf::Color text;
  sf::Color button_clicked;
  sf::Color default_text_color;
  sf::Color default_background_color;
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
  sf::Sprite spr_clear;
  sf::Sprite spr_delete;
  sf::Sprite spr_equal;

  sf::Sprite spr_history;
  sf::Sprite spr_mode;
  sf::Sprite spr_music;
  sf::Sprite spr_themes;
  sf::Sprite spr_sfx;
  sf::Sprite spr_settings;
  sf::Sprite spr_clear_history;

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
  bool is_input = true;
  bool is_dark_mode = false;
  bool is_music = true;
  bool is_sfx = true;
  bool is_settings = false;
  bool requestAnswer = false;
  bool is_history = false;
  bool made_change = false;
  bool in_the_slide_song_vol = false;
  bool in_the_slide_sfx_vol = false;
  bool in_the_slide_font = false;
  bool in_the_scroll_button = false;
  bool is_scroll_button = false;
  bool theme_pressed = false;
  bool is_scroll_hovered = false;
};
struct Volumes {
  int music = 100;
  int music_settings = 100;
  int sfx = 100;
  int sfx_settings = 100;

};
struct BaseData {
  //the Aliases array that is used to store the content of the `dictionary` file
  Aliases aliases[MAX_ENTRIES];

  sf::RectangleShape output_line;
  Theme themes[MAX_NR_THEMES];
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

  sf::Text output;
  sf::Text history;
  sf::String history_string;
  InputForm input_form;

  sf::String output_string;
  Volumes volumes;
  int number_of_fonts;
  int number_of_songs;
  int number_of_themes;
  int font_index = 0;
  int song_index = 0;
  int theme_index = 0;
  int font_size = 24;
  bool initial_setup = true;
  sf::Texture texture;
  //the `dimension`(the number of entries that happens to be in the dictionary file)
  int dimension = 0;
  int nr_lines = 0;
  int line_height = 0;
  int scroll_line_height = 0;
  int distance_from_mouse = -1;

  int limit_top = 0;
  int limit_bottom = 0;

  sf::Texture cross_texture;
  sf::RectangleShape cross_background;
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
void resetOutput(BaseData &base_data);
void setTheme(BaseData &base_data);
void setupAliases(BaseData &base_data, std::ifstream &fin);
void setFontSlideDim(BaseData &base_data);
void setSongVolumeSlideDim(BaseData &base_data);
void setSFXVolumeSlideDim(BaseData &base_data);
void clearHistory(BaseData &base_data);
void requestHistory(BaseData &base_data);
#endif