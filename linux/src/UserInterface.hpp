#include "Defines.hpp"
#include "InputForm.hpp"
#include "LogicsEnglish.hpp"
#include "LogicsRomanian.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#ifndef CONVERTOR_SRC_USERINTERFACE_HPP_
#define CONVERTOR_SRC_USERINTERFACE_HPP_
struct Files {
  std::ifstream fonts_in;
  std::ifstream songs_in;
  std::ifstream themes_file;
};
struct Boxes {
  sf::RectangleShape font_name;
  sf::RectangleShape font_size;
  sf::RectangleShape font_size_visual;
  sf::RectangleShape mask_box_bottom;
  sf::RectangleShape mask_box_top;
  sf::RectangleShape scroll_rect;
  sf::RectangleShape sfx_volume;
  sf::RectangleShape sfx_volume_visual;
  sf::RectangleShape song_name;
  sf::RectangleShape song_volume;
  sf::RectangleShape song_volume_visual;
};
struct Theme {
  sf::Color back;
  sf::Color button_clicked;
  sf::Color hover;
  sf::Color muted;
  sf::Color text;
};
struct Colors {
  sf::Color back;
  sf::Color button_clicked;
  sf::Color default_background_color;
  sf::Color default_text_color;
  sf::Color hover;
  sf::Color muted;
  sf::Color text;
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
  sf::Sprite spr_bottom_left_corner;
  sf::Sprite spr_bottom_right_corner;
  sf::Sprite spr_clear;
  sf::Sprite spr_clear_history;
  sf::Sprite spr_delete;
  sf::Sprite spr_einstein;
  sf::Sprite spr_equal;
  sf::Sprite spr_history;
  sf::Sprite spr_language;
  sf::Sprite spr_left_font_name;
  sf::Sprite spr_left_font_size;
  sf::Sprite spr_left_sfx_vol;
  sf::Sprite spr_left_song_name;
  sf::Sprite spr_left_song_vol;
  sf::Sprite spr_mode;
  sf::Sprite spr_music;
  sf::Sprite spr_right_font_name;
  sf::Sprite spr_right_font_size;
  sf::Sprite spr_right_sfx_vol;
  sf::Sprite spr_right_song_name;
  sf::Sprite spr_right_song_vol;
  sf::Sprite spr_settings;
  sf::Sprite spr_sfx;
  sf::Sprite spr_themes;
  sf::Sprite spr_top_left_corner;
  sf::Sprite spr_top_right_corner;
};
struct SettingsTexts {
  sf::Text font_name;
  sf::Text font_size;
  sf::Text label_font_name;
  sf::Text label_font_size;
  sf::Text label_settings;
  sf::Text label_sfx_volume;
  sf::Text label_song_name;
  sf::Text label_song_volume;
  sf::Text sfx_volume;
  sf::Text song_name;
  sf::Text song_volume;
};
struct Switches {
  bool is_answer_requested = false;
  bool is_change_made = false;
  bool is_dark_mode = false;
  bool is_english_language = true;
  bool is_history_screen = false;
  bool is_initial_setup = true;
  bool is_input_screen = true;
  bool is_music = true;
  bool is_scroll_button = false;
  bool is_scroll_hovered = false;
  bool is_settings_screen = false;
  bool is_sfx = true;
  bool is_the_scroll_button = false;
  bool is_the_slide_font = false;
  bool is_the_slide_sfx_vol = false;
  bool is_the_slide_song_vol = false;
  bool is_theme_pressed = false;
};
struct Volumes {
  int music = 100;
  int music_settings = 100;
  int sfx = 100;
  int sfx_settings = 100;
};

struct BaseData {
  Aliases aliases[MAX_ENTRIES];
  Boxes boxes;
  Colors colors;
  Files files;
  FontList font_list[MAX_NR_FONTS];
  InputForm input_form;
  SettingsTexts settings_texts;
  SongList song_list[MAX_NR_SONGS];
  SoundBuffers sound_buffers;
  Sounds sounds;
  Sprites sprites;
  Switches switches;
  Theme themes[MAX_NR_THEMES];
  Volumes volumes;
  sf::RectangleShape output_line;
  sf::String instruction_ro_string;
  sf::String instruction_en_string;
  sf::String history_string;
  sf::String output_string;
  sf::String time_string;
  sf::Text history;
  sf::Text instruction;
  sf::Text label_history;
  sf::Text label_input;
  sf::Text output;
  sf::Text time;
  sf::Texture einstein_text;
  sf::Texture texture;
  double line_height = 0;
  double scroll_line_height = 0;
  int brightness_factor = 30;
  int dimension = 0;
  int dimension_second_dic = 0;
  int distance_from_mouse = -1;
  int font_index = 0;
  int font_size = 24;
  int limit_bottom = 0;
  int limit_top = 0;
  int maximum_scrolled_lines = 0;
  int nr_lines = 0;
  int number_of_fonts;
  int number_of_songs;
  int number_of_themes;
  int scrolled_lines = 0;
  int song_index = 0;
  int theme_index = 0;
};
bool contains(sf::FloatRect, sf::Vector2i);
void changeInstructionPosition(BaseData &base_data);
void changeMode(BaseData &);
void changeUILanguage(BaseData &base_data);
void changeViewedInstructions(BaseData &base_data);
void clearHistory(BaseData &base_data);
void convertIToC(int, char *);
void drawStaticElements(BaseData &, sf::RenderWindow &);
void dumpSettings(BaseData &base_data);
void handleEvents(sf::RenderWindow &, sf::Event &, BaseData &);
void initialSetup(BaseData &);
void loadAssets(BaseData &, bool &);
void loadInstructions(BaseData &base_data);
void loadSettings(BaseData &base_data);
void navigateSFXVolume(BaseData &, bool);
void navigateSongName(BaseData &, bool);
void navigateSongVolume(BaseData &, bool);
void navigateTextFont(BaseData &, bool);
void navigateTextFontSize(BaseData &, bool);
void playClick(Sounds &);
void playTyping(Sounds &);
void requestHistory(BaseData &base_data);
void requestOutput(BaseData &base_data);
void resetHistoryPosition(BaseData &base_data);
void resetOutput(BaseData &base_data);
void setBoxesDetails(BaseData &);
void setFontSlideDim(BaseData &base_data);
void setLabelsTextsPositions(BaseData &base_data);
void setSFXVolume(BaseData &);
void setSFXVolumeSlideDim(BaseData &base_data);
void setSongToPlay(BaseData &);
void setSongVolume(BaseData &);
void setSongVolumeSlideDim(BaseData &base_data);
void setSpritesDetails(BaseData &);
void setTextFont(BaseData &);
void setTextFontSize(BaseData &);
void setTheme(BaseData &base_data);
void setupAliases(BaseData &base_data, std::ifstream &fin);
void switchLanguageSprite(BaseData &base_data);
void transformString(std::string &str, int &number_of_lines);
void updateBoxesAndTextsOutlineColor(BaseData &);
void updateHistoryPosition(BaseData &base_data);
void updateScrollDetails(BaseData &base_data);
void updateSettingsView(BaseData &);
#endif