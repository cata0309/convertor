#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"Defines.hpp"
#include<cstring>
#include<iostream>
#include<fstream>
std::ifstream fonts_in("fonts.txt");
std::ifstream songs_in("songs.txt");

struct UIData {
  //////////////////////////////////////// Declarari variabile resurse ////////////////////////////////////////
  sf::Color back_color;
  sf::Color text_color;
  char input[MAXINPUT];
  struct {
    sf::Sprite delete_sprite;
    sf::Sprite equal_sprite;
    sf::Sprite left_font;
    sf::Sprite left_fontsize;
    sf::Sprite left_song;
    sf::Sprite left_vol;
    //sprite folosit pentru butonul de muzica
    sf::Sprite music_sprite;
    sf::Sprite mode_sprite;
    //sprite folosit pentru butonul de setari
    sf::Sprite right_font;
    sf::Sprite right_fontsize;
    sf::Sprite right_song;
    sf::Sprite right_vol;
    sf::Sprite settings_sprite;
  } sprites;
  int number_of_songs;
  int number_of_fonts;
  //melodiile de fundal
  struct {
    sf::Music song;
    bool playing = false;
    char name[MAXLENGTHSONGNAME];
  } songs[MAXSONGS];
  //font
  struct {
    sf::Font font;
    bool setted = false;
    char name[MAXLENGHTFONTNAME];
  } fonts[MAXFONTS];
  //sunete
  sf::SoundBuffer bf_error;
  sf::SoundBuffer bf_typing;
  sf::SoundBuffer bf_click;
  //textura globala
  sf::Texture texture;
  sf::Sound error;
  sf::Sound typing;
  sf::Sound click;
  //variabila ce va tine valoarea volumului la care va fi setat initial muzica
  float volume = 100.f;
  //variabile ce vor avea rolul de intrerupatoare
  //settings_switch=true daca a fost apasat butonul de setari si va aparea interfata cu setari
  bool settings_switch = false;
  //music_switch=false daca a fost apasat butonul de muzica pentru a inchide muzica
  bool music_switch = true;
  //dark_mode=false daca a fost apasat butonul de schimbare a interfatei la modul dark
  bool dark_mode = false;
  sf::Text song_name;
  sf::Text song_volume;
  sf::Text font_name;
  sf::Text font_size;

  int width_left_buttons;
  int width_right_buttons;
};
void change_mode(UIData &);
void change_music(UIData &);
void initial_sprites_setup(UIData &);
void load_resources(UIData &, bool &);

int main() {
  //////////////////////////////////////// Crearea ferestrei ////////////////////////////////////////
  //se seteaza nivelul antialiasing mare pentru ca obiectele/formele geometrice sa nu fie desenate pixelat
  sf::ContextSettings csettings;
  csettings.antialiasingLevel = 16;
  //crearea ferestrei
  bool success = true;
  struct UIData ui_data;
  load_resources(ui_data, success);
  if (!success) {
    std::cerr << "Nu au putut fi incarcate resursele!";
    return -1;
  }
  initial_sprites_setup(ui_data);
  ui_data.songs[2].song.play();
  ui_data.songs[2].playing = true;
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Default, csettings);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type==sf::Event::EventType::Closed) {
        window.close();
      } else if (event.type==sf::Event::MouseButtonPressed) {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        sf::FloatRect music_pos = ui_data.sprites.music_sprite.getGlobalBounds();
        if (mouse_pos.x >= music_pos.left && mouse_pos.x <= music_pos.left + music_pos.width
            && mouse_pos.y >= music_pos.top && mouse_pos.y <= music_pos.top + music_pos.height) {
          ui_data.music_switch = !ui_data.music_switch;
        }
      }

    }
    if (ui_data.music_switch) {
      ui_data.sprites.music_sprite.setTextureRect(sf::IntRect(640, 1600, 320, 320));
    } else {
      ui_data.sprites.music_sprite.setTextureRect(sf::IntRect(320, 960, 320, 320));
    }
    if (ui_data.music_switch) {
      ui_data.volume = 100.f;
    } else {
      ui_data.volume = 0.f;
    }

    for (unsigned i = 0; i < 3; ++i)
      if (ui_data.songs[i].playing) {
        ui_data.songs[i].song.setVolume(ui_data.volume);
      }
    window.clear(sf::Color::White);
//    window.draw(music_sprite);
    window.display();

  }
  return 0;
}
void change_mode(UIData &ui_data) {
  if (ui_data.dark_mode) {
    ui_data.sprites.delete_sprite.setTextureRect(sf::IntRect(0, 0, 320, 320));
    ui_data.sprites.equal_sprite.setTextureRect(sf::IntRect(0, 640, 320, 320));

    ui_data.sprites.left_font.setTextureRect(sf::IntRect(0, 1280, 320, 320));
    ui_data.sprites.left_fontsize.setTextureRect(sf::IntRect(0, 1280, 320, 320));
    ui_data.sprites.left_song.setTextureRect(sf::IntRect(0, 1280, 320, 320));
    ui_data.sprites.left_vol.setTextureRect(sf::IntRect(0, 1280, 320, 320));
    if (ui_data.music_switch) {
      ui_data.sprites.music_sprite.setTextureRect(sf::IntRect(320, 1280, 320, 320));
    } else {
      ui_data.sprites.music_sprite.setTextureRect(sf::IntRect(960, 0, 320, 320));
    }
    ui_data.sprites.mode_sprite.setTextureRect(sf::IntRect(320, 0, 320, 320));
    ui_data.sprites.right_font.setTextureRect(sf::IntRect(1600, 0, 320, 320));
    ui_data.sprites.right_fontsize.setTextureRect(sf::IntRect(1600, 0, 320, 320));
    ui_data.sprites.right_song.setTextureRect(sf::IntRect(1600, 0, 320, 320));
    ui_data.sprites.right_vol.setTextureRect(sf::IntRect(1600, 0, 320, 320));
    ui_data.sprites.settings_sprite.setTextureRect(sf::IntRect(320, 640, 320, 320));
  } else {
    {
      ui_data.sprites.delete_sprite.setTextureRect(sf::IntRect(0, 320, 320, 320));
      ui_data.sprites.equal_sprite.setTextureRect(sf::IntRect(0, 960, 320, 320));
      ui_data.sprites.left_font.setTextureRect(sf::IntRect(0, 1600, 320, 320));
      ui_data.sprites.left_fontsize.setTextureRect(sf::IntRect(0, 1600, 320, 320));
      ui_data.sprites.left_song.setTextureRect(sf::IntRect(0, 1600, 320, 320));
      ui_data.sprites.left_vol.setTextureRect(sf::IntRect(0, 1600, 320, 320));
      if (ui_data.music_switch) {
        ui_data.sprites.music_sprite.setTextureRect(sf::IntRect(320, 1600, 320, 320));
      } else {
        ui_data.sprites.music_sprite.setTextureRect(sf::IntRect(1280, 0, 320, 320));
      }
      ui_data.sprites.mode_sprite.setTextureRect(sf::IntRect(640, 0, 320, 320));
      ui_data.sprites.right_font.setTextureRect(sf::IntRect(320, 320, 320, 320));
      ui_data.sprites.right_fontsize.setTextureRect(sf::IntRect(320, 320, 320, 320));
      ui_data.sprites.right_song.setTextureRect(sf::IntRect(320, 320, 320, 320));
      ui_data.sprites.right_vol.setTextureRect(sf::IntRect(320, 320, 320, 320));
      ui_data.sprites.settings_sprite.setTextureRect(sf::IntRect(320, 960, 320, 320));
    }
  }
}
void change_music(UIData &ui_data) {
  if (ui_data.dark_mode) {
    if (ui_data.music_switch) {
      ui_data.sprites.music_sprite.setTextureRect(sf::IntRect(320, 1280, 320, 320));
    } else {
      ui_data.sprites.music_sprite.setTextureRect(sf::IntRect(960, 0, 320, 320));
    }
  } else {
    if (ui_data.music_switch) {
      ui_data.sprites.music_sprite.setTextureRect(sf::IntRect(320, 1600, 320, 320));
    } else {
      ui_data.sprites.music_sprite.setTextureRect(sf::IntRect(1280, 0, 320, 320));
    }
  }
}

void initial_sprites_setup(UIData &ui_data) {
  ui_data.sprites.delete_sprite.setTexture(ui_data.texture);
  ui_data.sprites.equal_sprite.setTexture(ui_data.texture);
  ui_data.sprites.left_font.setTexture(ui_data.texture);
  ui_data.sprites.left_fontsize.setTexture(ui_data.texture);
  ui_data.sprites.left_song.setTexture(ui_data.texture);
  ui_data.sprites.left_vol.setTexture(ui_data.texture);
  ui_data.sprites.music_sprite.setTexture(ui_data.texture);
  ui_data.sprites.mode_sprite.setTexture(ui_data.texture);
  ui_data.sprites.right_font.setTexture(ui_data.texture);
  ui_data.sprites.right_fontsize.setTexture(ui_data.texture);
  ui_data.sprites.right_song.setTexture(ui_data.texture);
  ui_data.sprites.right_vol.setTexture(ui_data.texture);
  ui_data.sprites.settings_sprite.setTexture(ui_data.texture);
  change_mode(ui_data);
  ui_data.sprites.delete_sprite.scale(sf::Vector2f(0.15, 0.15));
  ui_data.sprites.equal_sprite.scale(sf::Vector2f(0.15, 0.15));
  ui_data.sprites.left_font.scale(sf::Vector2f(0.15, 0.15));
  ui_data.sprites.left_fontsize.scale(sf::Vector2f(0.15, 0.15));
  ui_data.sprites.left_song.scale(sf::Vector2f(0.15, 0.15));
  ui_data.sprites.left_vol.scale(sf::Vector2f(0.15, 0.15));
  ui_data.sprites.music_sprite.scale(sf::Vector2f(0.15, 0.15));
  ui_data.sprites.mode_sprite.scale(sf::Vector2f(0.15, 0.15));
  ui_data.sprites.right_font.scale(sf::Vector2f(0.15, 0.15));
  ui_data.sprites.right_fontsize.scale(sf::Vector2f(0.15, 0.15));
  ui_data.sprites.right_song.scale(sf::Vector2f(0.15, 0.15));
  ui_data.sprites.right_vol.scale(sf::Vector2f(0.15, 0.15));
  ui_data.sprites.settings_sprite.scale(sf::Vector2f(0.15, 0.15));
}

void load_resources(UIData &ui_data, bool &success) {
  //incarcarea fonturilor
  if (!fonts_in.is_open()) {
    std::cerr << "Fisierul cu detaliile despre fonturi nu a putut fi deschis !";
    std::exit(1);
  }

  fonts_in >> ui_data.number_of_fonts;
  for (unsigned i = 0; i < ui_data.number_of_fonts && success; ++i) {
    char path[MAXPATH];
    char name[MAXLENGHTFONTNAME];
    fonts_in >> path >> name;
    if (!ui_data.fonts[i].font.loadFromFile(path)) {
      std::cerr << "Nu a putut fi incarcat font-ul: " << name << '\n';
      success = false;
    }
    strcpy(ui_data.fonts[i].name, name);
  }
//incarcarea melodiilor
  if (!songs_in.is_open()) {
    std::cerr << "Fisierul cu detaliile despre sunete nu a putut fi deschis !";
    std::exit(1);
  }
  songs_in >> ui_data.number_of_songs;
  for (unsigned i = 0; i < ui_data.number_of_songs && success; ++i) {
    char path[MAXPATH];
    char name[MAXLENGTHSONGNAME];
    songs_in >> path >> name;
    if (!ui_data.songs[i].song.openFromFile(path)) {
      std::cerr << "Nu a putut fi incarcata melodia: " << name << '\n';
      success = false;
    }
    strcpy(ui_data.songs[i].name, name);
  }

  //incarcarea sunetelor

  if (!ui_data.bf_error.loadFromFile(ERROR)) {
    std::cerr << "Nu a putut fi incarcat sunetul de eroare: error.wav\n";
    success = false;
  }
  if (!ui_data.bf_typing.loadFromFile(TYPE)) {
    std::cerr << "Nu a putut fi incarcat sunetul de tastare: stroke.wav\n";
    success = false;
  }
  if (!ui_data.bf_click.loadFromFile(CLICK)) {
    std::cerr << "Nu a putut fi incarcat sunetul de click: click.wav\n";
    success = false;
  }
  if (!ui_data.texture.loadFromFile(GLOB_TEXTURE)) {
    std::cerr << "Nu a putut fi incarcata textura globala\n";
    success = false;
  }
  //face ca textura sa fie desenata fin
  ui_data.texture.setSmooth(true);
  //face ca textura sa nu se repete in cadrul unui sprite ci sa fie intinsa
  ui_data.texture.setRepeated(false);
  //setare ca muzica sa mearga la nesfarsit
//  for (unsigned i = 0; i < 4; ++i)
//    songs[i].song.setLoop(true);
  //setarea sunetelor
  ui_data.error.setBuffer(ui_data.bf_error);
  ui_data.typing.setBuffer(ui_data.bf_typing);
  ui_data.click.setBuffer(ui_data.bf_click);
}