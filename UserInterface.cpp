#include "UserInterface.hpp"

void changeModeSprites(UIData &ui_data) {
  ui_data.switch_dark_mode = !ui_data.switch_dark_mode;
  if (ui_data.switch_dark_mode) {
    ui_data.colors.back = sf::Color(41, 40, 38);
    ui_data.colors.text = sf::Color(200, 200, 200);
    ui_data.sprites.spr_delete.setTextureRect(sf::IntRect(0, 0, IMG_REAL, IMG_REAL));
    ui_data.sprites.spr_equal.setTextureRect(sf::IntRect(0, 640, IMG_REAL, IMG_REAL));
    ui_data.sprites.spr_left_font.setTextureRect(sf::IntRect(0, 1280, IMG_REAL, IMG_REAL));
    ui_data.sprites.spr_left_font_size.setTextureRect(sf::IntRect(0, 1280, IMG_REAL, IMG_REAL));
    ui_data.sprites.spr_left_song.setTextureRect(sf::IntRect(0, 1280, IMG_REAL, IMG_REAL));
    ui_data.sprites.spr_left_vol.setTextureRect(sf::IntRect(0, 1280, IMG_REAL, IMG_REAL));
    if (ui_data.switch_music) {
      ui_data.sprites.spr_music.setTextureRect(sf::IntRect(320, 1280, IMG_REAL, IMG_REAL));
    } else {
      ui_data.sprites.spr_music.setTextureRect(sf::IntRect(960, 0, IMG_REAL, IMG_REAL));
    }
    ui_data.sprites.spr_mode.setTextureRect(sf::IntRect(320, 0, IMG_REAL, IMG_REAL));
    ui_data.sprites.spr_right_font.setTextureRect(sf::IntRect(1600, 0, IMG_REAL, IMG_REAL));
    ui_data.sprites.spr_right_font_size.setTextureRect(sf::IntRect(1600, 0, IMG_REAL, IMG_REAL));
    ui_data.sprites.spr_right_song.setTextureRect(sf::IntRect(1600, 0, IMG_REAL, IMG_REAL));
    ui_data.sprites.spr_right_vol.setTextureRect(sf::IntRect(1600, 0, IMG_REAL, IMG_REAL));
    ui_data.sprites.spr_settings.setTextureRect(sf::IntRect(320, 640, IMG_REAL, IMG_REAL));

  } else {
    {
      ui_data.colors.back = sf::Color(200, 200, 200);
      ui_data.colors.text = sf::Color(41, 40, 38);
      ui_data.sprites.spr_delete.setTextureRect(sf::IntRect(0, 320, IMG_REAL, IMG_REAL));
      ui_data.sprites.spr_equal.setTextureRect(sf::IntRect(0, 960, IMG_REAL, IMG_REAL));
      ui_data.sprites.spr_left_font.setTextureRect(sf::IntRect(0, 1600, IMG_REAL, IMG_REAL));
      ui_data.sprites.spr_left_font_size.setTextureRect(sf::IntRect(0, 1600, IMG_REAL, IMG_REAL));
      ui_data.sprites.spr_left_song.setTextureRect(sf::IntRect(0, 1600, IMG_REAL, IMG_REAL));
      ui_data.sprites.spr_left_vol.setTextureRect(sf::IntRect(0, 1600, IMG_REAL, IMG_REAL));
      if (ui_data.switch_music) {
        ui_data.sprites.spr_music.setTextureRect(sf::IntRect(320, 1600, IMG_REAL, IMG_REAL));
      } else {
        ui_data.sprites.spr_music.setTextureRect(sf::IntRect(1280, 0, IMG_REAL, IMG_REAL));
      }
      ui_data.sprites.spr_mode.setTextureRect(sf::IntRect(640, 0, IMG_REAL, IMG_REAL));
      ui_data.sprites.spr_right_font.setTextureRect(sf::IntRect(320, 320, IMG_REAL, IMG_REAL));
      ui_data.sprites.spr_right_font_size.setTextureRect(sf::IntRect(320, 320, IMG_REAL, IMG_REAL));
      ui_data.sprites.spr_right_song.setTextureRect(sf::IntRect(320, 320, IMG_REAL, IMG_REAL));
      ui_data.sprites.spr_right_vol.setTextureRect(sf::IntRect(320, 320, IMG_REAL, IMG_REAL));
      ui_data.sprites.spr_settings.setTextureRect(sf::IntRect(320, 960, IMG_REAL, IMG_REAL));
    }
  }
  setBoxesOutlineColor(ui_data);
}
void drawUI(UIData &ui_data, sf::RenderWindow &window) {
  window.clear(ui_data.colors.back);

  window.draw(ui_data.sprites.spr_mode);
  window.draw(ui_data.sprites.spr_music);
  window.draw(ui_data.sprites.spr_settings);
  if (ui_data.switch_settings) {

    window.draw(ui_data.sprites.spr_left_font);
    window.draw(ui_data.boxes.font);
    window.draw(ui_data.sprites.spr_right_font);

    window.draw(ui_data.sprites.spr_left_font_size);
    window.draw(ui_data.boxes.font_size);
    window.draw(ui_data.sprites.spr_right_font_size);

    window.draw(ui_data.sprites.spr_left_song);
    window.draw(ui_data.boxes.song);
    window.draw(ui_data.sprites.spr_right_song);

    window.draw(ui_data.sprites.spr_left_vol);
    window.draw(ui_data.boxes.volume);
    window.draw(ui_data.sprites.spr_right_vol);

    window.draw(ui_data.texts.song_volume);
    window.draw(ui_data.texts.song_name);
    window.draw(ui_data.texts.font_name);
    window.draw(ui_data.texts.font_size);

    window.draw(ui_data.texts.label_volume);
    window.draw(ui_data.texts.label_song_name);
    window.draw(ui_data.texts.label_font_size);
    window.draw(ui_data.texts.label_font);

    updateSettingsView(ui_data);

  } else {
    window.draw(ui_data.sprites.spr_delete);
    window.draw(ui_data.sprites.spr_equal);
    window.draw(ui_data.boxes.input);
    window.draw(ui_data.boxes.output);
  }
  window.display();
}

void setSpritesDetails(UIData &ui_data) {
  setSpritesTextures(ui_data);
  changeModeSprites(ui_data);
  setSpritesScale(ui_data, 0.15);
  setSpritesPositions(ui_data);
}
void setSpritesPositions(UIData &ui_data) {
  ui_data.sprites.spr_settings.setPosition(WIDTH - (PADDING + IMG_SCALED), PADDING);
  ui_data.sprites.spr_music.setPosition(WIDTH - 2*(PADDING + IMG_SCALED), PADDING);

  ui_data.sprites.spr_mode.setPosition(WIDTH - 3*(PADDING + IMG_SCALED), PADDING);

  ui_data.sprites.spr_delete.setPosition(100, 100);
  ui_data.sprites.spr_equal.setPosition(100, 100);

  ui_data.sprites.spr_left_font.setPosition(ui_data.boxes.font.getPosition().x - PADDING - IMG_SCALED - THICKNESS,
                                            ui_data.boxes.font.getPosition().y - THICKNESS);
  ui_data.sprites.spr_right_font.setPosition(
      ui_data.boxes.font.getPosition().x + PADDING + ui_data.boxes.font.getSize().x + THICKNESS,
      ui_data.boxes.font.getPosition().y - THICKNESS);

  ui_data.sprites.spr_left_font_size.setPosition(
      ui_data.boxes.font_size.getPosition().x - PADDING - IMG_SCALED - THICKNESS,
      ui_data.boxes.font_size.getPosition().y - THICKNESS);
  ui_data.sprites.spr_right_font_size.setPosition(
      ui_data.boxes.font_size.getPosition().x + PADDING + ui_data.boxes.font_size.getSize().x + THICKNESS,
      ui_data.boxes.font_size.getPosition().y - THICKNESS);

  ui_data.sprites.spr_left_song.setPosition(ui_data.boxes.song.getPosition().x - PADDING - IMG_SCALED - THICKNESS,
                                            ui_data.boxes.song.getPosition().y - THICKNESS);
  ui_data.sprites.spr_right_song.setPosition(
      ui_data.boxes.song.getPosition().x + PADDING + ui_data.boxes.song.getSize().x + THICKNESS,
      ui_data.boxes.song.getPosition().y - THICKNESS);

  ui_data.sprites.spr_left_vol.setPosition(ui_data.boxes.volume.getPosition().x - PADDING - IMG_SCALED - THICKNESS,
                                           ui_data.boxes.volume.getPosition().y - THICKNESS);
  ui_data.sprites.spr_right_vol.setPosition(
      ui_data.boxes.volume.getPosition().x + PADDING + ui_data.boxes.volume.getSize().x + THICKNESS,
      ui_data.boxes.volume.getPosition().y - THICKNESS);

}

void setSpritesScale(UIData &ui_data, float x_times) {
  ui_data.sprites.spr_delete.scale(sf::Vector2f(x_times, x_times));
  ui_data.sprites.spr_equal.scale(sf::Vector2f(x_times, x_times));
  ui_data.sprites.spr_left_font.scale(sf::Vector2f(x_times, x_times));
  ui_data.sprites.spr_left_font_size.scale(sf::Vector2f(x_times, x_times));
  ui_data.sprites.spr_left_song.scale(sf::Vector2f(x_times, x_times));
  ui_data.sprites.spr_left_vol.scale(sf::Vector2f(x_times, x_times));
  ui_data.sprites.spr_music.scale(sf::Vector2f(x_times, x_times));
  ui_data.sprites.spr_mode.scale(sf::Vector2f(x_times, x_times));
  ui_data.sprites.spr_right_font.scale(sf::Vector2f(x_times, x_times));
  ui_data.sprites.spr_right_font_size.scale(sf::Vector2f(x_times, x_times));
  ui_data.sprites.spr_right_song.scale(sf::Vector2f(x_times, x_times));
  ui_data.sprites.spr_right_vol.scale(sf::Vector2f(x_times, x_times));
  ui_data.sprites.spr_settings.scale(sf::Vector2f(x_times, x_times));
}
void setSpritesTextures(UIData &ui_data) {
  ui_data.sprites.spr_delete.setTexture(ui_data.texture);
  ui_data.sprites.spr_equal.setTexture(ui_data.texture);
  ui_data.sprites.spr_left_font.setTexture(ui_data.texture);
  ui_data.sprites.spr_left_font_size.setTexture(ui_data.texture);
  ui_data.sprites.spr_left_song.setTexture(ui_data.texture);
  ui_data.sprites.spr_left_vol.setTexture(ui_data.texture);
  ui_data.sprites.spr_music.setTexture(ui_data.texture);
  ui_data.sprites.spr_mode.setTexture(ui_data.texture);
  ui_data.sprites.spr_right_font.setTexture(ui_data.texture);
  ui_data.sprites.spr_right_font_size.setTexture(ui_data.texture);
  ui_data.sprites.spr_right_song.setTexture(ui_data.texture);
  ui_data.sprites.spr_right_vol.setTexture(ui_data.texture);
  ui_data.sprites.spr_settings.setTexture(ui_data.texture);
}

void setBoxesDetails(UIData &ui_data) {
  setBoxesFillColor(ui_data);
  setBoxesSizes(ui_data);
  setBoxesOutlineColor(ui_data);
  setBoxesOutlineThickness(ui_data);
  setBoxesPositions(ui_data);
}
void setBoxesFillColor(UIData &ui_data) {
  ui_data.boxes.input.setFillColor(sf::Color::Transparent);
  ui_data.boxes.output.setFillColor(sf::Color::Transparent);
  ui_data.boxes.font.setFillColor(sf::Color::Transparent);
  ui_data.boxes.font_size.setFillColor(sf::Color::Transparent);
  ui_data.boxes.song.setFillColor(sf::Color::Transparent);
  ui_data.boxes.volume.setFillColor(sf::Color::Transparent);
}
void setBoxesOutlineColor(UIData &ui_data) {
  ui_data.boxes.input.setOutlineColor(ui_data.colors.text);
  ui_data.boxes.output.setOutlineColor(ui_data.colors.text);
  ui_data.boxes.font.setOutlineColor(ui_data.colors.text);
  ui_data.boxes.font_size.setOutlineColor(ui_data.colors.text);
  ui_data.boxes.song.setOutlineColor(ui_data.colors.text);
  ui_data.boxes.volume.setOutlineColor(ui_data.colors.text);
}
void setBoxesOutlineThickness(UIData &ui_data) {
  ui_data.boxes.input.setOutlineThickness(THICKNESS);
  ui_data.boxes.output.setOutlineThickness(THICKNESS);
  ui_data.boxes.font.setOutlineThickness(THICKNESS);
  ui_data.boxes.font_size.setOutlineThickness(THICKNESS);
  ui_data.boxes.song.setOutlineThickness(THICKNESS);
  ui_data.boxes.volume.setOutlineThickness(THICKNESS);
}

void setLabelTextPositions(UIData &ui_data) {
  float vertical_pos = (HEIGHT - 7.7*IMG_SCALED - 7*VERTICAL_PADDING)/2;
  ui_data.texts.label_volume.setPosition((WIDTH - ui_data.texts.label_volume.getLocalBounds().width)/2, vertical_pos);
  vertical_pos += 2*(IMG_SCALED + VERTICAL_PADDING);
  ui_data.texts.label_song_name.setPosition((WIDTH - ui_data.texts.label_song_name.getGlobalBounds().width)/2,
                                            vertical_pos);
  vertical_pos += 2*(IMG_SCALED + VERTICAL_PADDING);
  ui_data.texts.label_font.setPosition((WIDTH - ui_data.texts.label_font.getGlobalBounds().width)/2, vertical_pos);
  vertical_pos += 2*(IMG_SCALED + VERTICAL_PADDING);
  ui_data.texts.label_font_size.setPosition((WIDTH - ui_data.texts.label_font_size.getGlobalBounds().width)/2,
                                            vertical_pos);

}
void setTextPositions(UIData &ui_data) {

  float vertical_pos = (HEIGHT - 8*IMG_SCALED - 7*VERTICAL_PADDING)/2.f;
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);
  ui_data.texts.song_volume.setPosition(100, vertical_pos);
  vertical_pos += 2*(IMG_SCALED + VERTICAL_PADDING);
  ui_data.texts.song_name.setPosition(100, vertical_pos);
  vertical_pos += 2*(IMG_SCALED + VERTICAL_PADDING);
  ui_data.texts.font_name.setPosition(100, vertical_pos);
  vertical_pos += 2*(IMG_SCALED + VERTICAL_PADDING);
  ui_data.texts.font_size.setPosition(100, vertical_pos);
}

void setBoxesPositions(UIData &ui_data) {
  float vertical_pos = (HEIGHT - 8*IMG_SCALED - 7*VERTICAL_PADDING)/2.f;
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);
  ui_data.boxes.volume.setPosition((WIDTH - ui_data.boxes.volume.getSize().x)/2, vertical_pos);
  vertical_pos += 2*(IMG_SCALED + VERTICAL_PADDING);
  ui_data.boxes.song.setPosition((WIDTH - ui_data.boxes.song.getSize().x)/2, vertical_pos);
  vertical_pos += 2*(IMG_SCALED + VERTICAL_PADDING);
  ui_data.boxes.font.setPosition((WIDTH - ui_data.boxes.font.getSize().x)/2, vertical_pos);
  vertical_pos += 2*(IMG_SCALED + VERTICAL_PADDING);
  ui_data.boxes.font_size.setPosition((WIDTH - ui_data.boxes.font_size.getSize().x)/2, vertical_pos);

  ui_data.boxes.input.setPosition(IMG_SCALED + PADDING, 2*IMG_SCALED);
  ui_data.boxes.output.setPosition(100, 100);
}

void setupUI(UIData &ui_data) {
  setBoxesDetails(ui_data);
  setSpritesDetails(ui_data);
  ui_data.texts.label_font.setString("FONT:");
  ui_data.texts.label_song_name.setString("MELODIE:");
  ui_data.texts.label_volume.setString("VOLUM:");
  ui_data.texts.label_settings.setString("SETARI");
  ui_data.texts.label_font_size.setString("MARIME FONT:");
  updateSettingsView(ui_data);

  ui_data.songs[ui_data.song_index].song.play();
  ui_data.songs[ui_data.song_index].playing = true;
  changeModeSprites(ui_data);
}
void updateTextFontSize(UIData &ui_data) {
  ui_data.texts.label_font.setCharacterSize(ui_data.font_size);
  ui_data.texts.label_font_size.setCharacterSize(ui_data.font_size);
  ui_data.texts.label_settings.setCharacterSize(ui_data.font_size);
  ui_data.texts.label_song_name.setCharacterSize(ui_data.font_size);
  ui_data.texts.label_volume.setCharacterSize(ui_data.font_size);

  ui_data.texts.font_name.setCharacterSize(ui_data.font_size);
  ui_data.texts.font_size.setCharacterSize(ui_data.font_size);
  ui_data.texts.song_name.setCharacterSize(ui_data.font_size);
  ui_data.texts.song_volume.setCharacterSize(ui_data.font_size);

  ui_data.texts.input.setCharacterSize(ui_data.font_size);
  ui_data.texts.output.setCharacterSize(ui_data.font_size);
}

void updateTextColor(UIData &ui_data) {

  ui_data.texts.label_font.setFillColor(ui_data.colors.text);
  ui_data.texts.label_font_size.setFillColor(ui_data.colors.text);
  ui_data.texts.label_settings.setFillColor(ui_data.colors.text);
  ui_data.texts.label_song_name.setFillColor(ui_data.colors.text);
  ui_data.texts.label_volume.setFillColor(ui_data.colors.text);

  ui_data.texts.font_name.setFillColor(ui_data.colors.text);
  ui_data.texts.font_size.setFillColor(ui_data.colors.text);
  ui_data.texts.song_name.setFillColor(ui_data.colors.text);
  ui_data.texts.song_volume.setFillColor(ui_data.colors.text);

  ui_data.texts.input.setFillColor(ui_data.colors.text);
  ui_data.texts.output.setFillColor(ui_data.colors.text);
}
void updateSettingsView(UIData &ui_data) {
  ui_data.texts.font_name.setString(ui_data.fonts[ui_data.font_index].name);
  ui_data.texts.song_name.setString(ui_data.songs[ui_data.song_index].name);
  char sir[20];
  convertIToC(ui_data.font_size, sir);
  ui_data.texts.font_size.setString(sir);

  convertIToC(ui_data.volume, sir);
  ui_data.texts.song_volume.setString(sir);

  ui_data.texts.input.setString(ui_data.input);
  updateTextFonts(ui_data);
  updateTextColor(ui_data);
  updateTextFontSize(ui_data);
  setTextPositions(ui_data);
  setLabelTextPositions(ui_data);
}

void changeFont(UIData &ui_data, bool decrement) {
  ui_data.font_index = ((decrement) ? ((ui_data.font_index==0) ? ui_data.number_of_fonts - 1 : ui_data.font_index - 1)
                                    : ((ui_data.font_index==ui_data.number_of_fonts - 1) ? 0 : ui_data.font_index + 1));
}
void changeMusicSprite(UIData &ui_data) {
  ui_data.switch_music = !ui_data.switch_music;
  if (ui_data.switch_dark_mode) {
    if (ui_data.switch_music) {
      ui_data.sprites.spr_music.setTextureRect(sf::IntRect(320, 1280, IMG_REAL, IMG_REAL));
    } else {
      ui_data.sprites.spr_music.setTextureRect(sf::IntRect(960, 0, IMG_REAL, IMG_REAL));
    }
  } else {
    if (ui_data.switch_music) {
      ui_data.sprites.spr_music.setTextureRect(sf::IntRect(320, 1600, IMG_REAL, IMG_REAL));
    } else {
      ui_data.sprites.spr_music.setTextureRect(sf::IntRect(1280, 0, IMG_REAL, IMG_REAL));
    }
  }
}
void changeSize(UIData &ui_data, bool decrement) {
  if (decrement) {
    if (ui_data.font_size - 1 >= MIN_DIM_FONT) {
      ui_data.font_size -= 1;
    }
  } else {
    if (ui_data.font_size + 1 <= MAX_DIM_FONT) {
      ui_data.font_size += 1;
    }
  }
}
void changeSong(UIData &ui_data, bool decrement) {
  ui_data.songs[ui_data.song_index].song.stop();
  ui_data.songs[ui_data.song_index].playing = false;

  ui_data.song_index = ((decrement) ? ((ui_data.song_index==0) ? ui_data.number_of_songs - 1 : ui_data.song_index - 1)
                                    : ((ui_data.song_index==ui_data.number_of_songs - 1) ? 0 : ui_data.song_index + 1));
  ui_data.texts.song_name.setString(ui_data.songs[ui_data.song_index].name);
  ui_data.songs[ui_data.song_index].song.play();
  ui_data.songs[ui_data.song_index].playing = true;
}
void changeVolume(UIData &ui_data, bool decrement) {
  int st = 0, dr = 100;
  if (decrement) {
    if (ui_data.volume - 1 >= st) {
      ui_data.volume -= 1;
    }

  } else {
    if (ui_data.volume + 1 <= dr) {
      ui_data.volume += 1;
    }
  }
}
void convertIToC(int nr, char *c) {
  char sir[4];
  int lung = 0;
  do {
    sir[lung++] = char(48 + nr%10);
    nr /= 10;
  } while (nr!=0);
  sir[lung] = '\0';
  for (size_t i = 0; sir[i]; ++i) {
    c[strlen(sir) - 1 - i] = sir[i];
  }
  c[strlen(sir)] = '\0';
}
void loadResources(UIData &ui_data, bool &success) {


  //incarcarea fonturilor
  ui_data.files.fonts_in.open("fonts.txt");
  if (!ui_data.files.fonts_in.is_open()) {
    std::cerr << "Fisierul cu detaliile despre fonturi nu a putut fi deschis !";
    std::exit(1);
  }
  ui_data.files.fonts_in >> ui_data.number_of_fonts;
  for (unsigned i = 0; i < ui_data.number_of_fonts && success; ++i) {
    char path[MAX_PATH];
    char name[MAX_FONT_NAME];
    ui_data.files.fonts_in >> path >> name;
    if (!ui_data.fonts[i].font.loadFromFile(path)) {
      std::cerr << "Nu a putut fi incarcat font-ul: " << name << '\n';
      success = false;
    }
    strcpy(ui_data.fonts[i].name, name);
  }
  ui_data.files.songs_in.open("songs.txt");
//incarcarea melodiilor
  if (!ui_data.files.songs_in.is_open()) {
    std::cerr << "Fisierul cu detaliile despre sunete nu a putut fi deschis !";
    std::exit(1);
  }
  ui_data.files.songs_in >> ui_data.number_of_songs;
  for (unsigned i = 0; i < ui_data.number_of_songs && success; ++i) {
    char path[MAX_PATH];
    char name[MAX_SONG_NAME];
    ui_data.files.songs_in >> path >> name;
    if (!ui_data.songs[i].song.openFromFile(path)) {
      std::cerr << "Nu a putut fi incarcata melodia: " << name << '\n';
      success = false;
    }
    ui_data.songs[i].song.setLoop(true);
    strcpy(ui_data.songs[i].name, name);
  }
  //incarcarea sunetelor
  if (!ui_data.sound_buffers.error.loadFromFile(ERROR)) {
    std::cerr << "Nu a putut fi incarcat sunetul de eroare: error.wav\n";
    success = false;
  }
  if (!ui_data.sound_buffers.typing.loadFromFile(TYPE)) {
    std::cerr << "Nu a putut fi incarcat sunetul de tastare: stroke.wav\n";
    success = false;
  }
  if (!ui_data.sound_buffers.click.loadFromFile(CLICK)) {
    std::cerr << "Nu a putut fi incarcat sunetul de click: click.wav\n";
    success = false;
  }
  if (!ui_data.texture.loadFromFile(GLOB_TEXTURE)) {
    std::cerr << "Nu a putut fi incarcata textura globala\n";
    success = false;
  }
  //face ca textura sa fie desenata fin
  ui_data.texture.setSmooth(true);
  //face ca textura sa nu se repete in cadrul unui  ci sa fie intinsa
  ui_data.texture.setRepeated(false);
  //setare ca muzica sa mearga la nesfarsit
//  for (unsigned i = 0; i < 4; ++i)
//    songs[i].song.setLoop(true);
  //setarea sunetelor
  ui_data.sounds.error.setBuffer(ui_data.sound_buffers.error);
  ui_data.sounds.typing.setBuffer(ui_data.sound_buffers.typing);
  ui_data.sounds.click.setBuffer(ui_data.sound_buffers.click);
}
void setBoxesSizes(UIData &ui_data) {
  sf::Vector2f general_size = sf::Vector2f(5*IMG_SCALED, IMG_SCALED - 2*THICKNESS);
  sf::Vector2f input_size = sf::Vector2f(WIDTH - 5*IMG_SCALED, (HEIGHT - 4*IMG_SCALED)/2.f);
  sf::Vector2f output_size;
  ui_data.boxes.input.setSize(input_size);
  ui_data.boxes.output.setSize(output_size);
  ui_data.boxes.font.setSize(general_size);
  ui_data.boxes.font_size.setSize(general_size);
  ui_data.boxes.song.setSize(general_size);
  ui_data.boxes.volume.setSize(general_size);
}
void updateTextFonts(UIData &ui_data) {
  ui_data.texts.label_font.setFont(ui_data.fonts[ui_data.font_index].font);
  ui_data.texts.label_font_size.setFont(ui_data.fonts[ui_data.font_index].font);
  ui_data.texts.label_settings.setFont(ui_data.fonts[ui_data.font_index].font);
  ui_data.texts.label_song_name.setFont(ui_data.fonts[ui_data.font_index].font);
  ui_data.texts.label_volume.setFont(ui_data.fonts[ui_data.font_index].font);

  ui_data.texts.font_name.setFont(ui_data.fonts[ui_data.font_index].font);
  ui_data.texts.font_size.setFont(ui_data.fonts[ui_data.font_index].font);
  ui_data.texts.song_name.setFont(ui_data.fonts[ui_data.font_index].font);
  ui_data.texts.song_volume.setFont(ui_data.fonts[ui_data.font_index].font);

  ui_data.texts.input.setFont(ui_data.fonts[ui_data.font_index].font);
  ui_data.texts.output.setFont(ui_data.fonts[ui_data.font_index].font);
}

bool contains(sf::FloatRect &area, sf::Vector2i &point) {
  return (point.x >= area.left && point.x <= area.left + area.width
      && point.y >= area.top && point.y <= area.top + area.height);
}
void setVolume(UIData &ui_data) {
  float vol_inter;
  if (ui_data.switch_music) {
    vol_inter = float(ui_data.volume);
  } else {
    vol_inter = 0.f;
  }
  bool finish = false;
  for (unsigned i = 0; i < ui_data.number_of_songs && !finish; ++i)
    if (ui_data.songs[i].playing) {
      ui_data.songs[i].song.setVolume(vol_inter);
      finish = true;
    }
}

void handleEvents(sf::RenderWindow &window, sf::Event &event, UIData &ui_data) {
  while (window.pollEvent(event)) {

    if (event.type==sf::Event::Closed) {
      window.close();
    }
    if (event.type==sf::Event::MouseButtonPressed) {
      sf::Vector2i mouse = sf::Mouse::getPosition(window);

      sf::FloatRect area_settings = ui_data.sprites.spr_settings.getGlobalBounds();
      if (contains(area_settings, mouse)) {
        ui_data.switch_settings = !ui_data.switch_settings;
      }
      sf::FloatRect area_music = ui_data.sprites.spr_music.getGlobalBounds();
      if (contains(area_music, mouse)) {
//        char sir[20];
//        if (ui_data.switch_music) {
//          convertIToC(0, sir);
//        } else {
//          convertIToC(ui_data.volume, sir);
//        }
//        ui_data.texts.song_volume.setString(sir);
        updateSettingsView(ui_data);
        changeMusicSprite(ui_data);
      }

      sf::FloatRect area_light = ui_data.sprites.spr_mode.getGlobalBounds();
      if (contains(area_light, mouse)) {
        changeModeSprites(ui_data);
      }
      if (ui_data.switch_settings) {

        sf::FloatRect area_left_vol = ui_data.sprites.spr_left_vol.getGlobalBounds();
        if (contains(area_left_vol, mouse)) {
          changeVolume(ui_data, true);
          if (ui_data.volume==0) {
            changeMusicSprite(ui_data);
          }
        }
        sf::FloatRect area_right_vol = ui_data.sprites.spr_right_vol.getGlobalBounds();
        if (contains(area_right_vol, mouse)) {
          if (!ui_data.switch_music) {
            changeMusicSprite(ui_data);
          }
          changeVolume(ui_data, false);
        }
        sf::FloatRect area_vol = ui_data.boxes.volume.getGlobalBounds();
        if (contains(area_vol, mouse)) {
          float step = (area_vol.width)/(102.f);
          int volume_test = int((mouse.x - ui_data.boxes.volume.getPosition().x)/step);
          if (volume_test >= 0 && volume_test <= 100) {
            ui_data.volume = volume_test;

            if (ui_data.switch_music) {
              if (volume_test==0) { changeMusicSprite(ui_data);
              }
            } else {
              changeMusicSprite(ui_data);
            }
          }

        }

        sf::FloatRect area_left_song = ui_data.sprites.spr_left_song.getGlobalBounds();
        if (contains(area_left_song, mouse)) {
          changeSong(ui_data, true);
        }

        sf::FloatRect area_right_song = ui_data.sprites.spr_right_song.getGlobalBounds();
        if (contains(area_right_song, mouse)) {
          changeSong(ui_data, false);
        }

        sf::FloatRect area_left_font = ui_data.sprites.spr_left_font.getGlobalBounds();
        if (contains(area_left_font, mouse)) {
          changeFont(ui_data, true);
          updateSettingsView(ui_data);
        }
        sf::FloatRect area_right_font = ui_data.sprites.spr_right_font.getGlobalBounds();
        if (contains(area_right_font, mouse)) {
          changeFont(ui_data, false);
          updateSettingsView(ui_data);
        }

        sf::FloatRect area_left_font_size = ui_data.sprites.spr_left_font_size.getGlobalBounds();
        if (contains(area_left_font_size, mouse)) {
          changeSize(ui_data, true);
          updateSettingsView(ui_data);
        }
        sf::FloatRect area_right_font_size = ui_data.sprites.spr_right_font_size.getGlobalBounds();
        if (contains(area_right_font_size, mouse)) {
          changeSize(ui_data, false);
          updateSettingsView(ui_data);
        }

        sf::FloatRect area_font = ui_data.boxes.font_size.getGlobalBounds();
        if (contains(area_font, mouse)) {
          float step = (area_font.width)/(8.f);
          int font_size_test = int((mouse.x - ui_data.boxes.font_size.getPosition().x)/step) + 20;
          std::cout << font_size_test << "\n";
          if (font_size_test >= MIN_DIM_FONT && font_size_test <= MAX_DIM_FONT) {
            ui_data.font_size = font_size_test;
            updateSettingsView(ui_data);
          }
        }

      } else {
        sf::FloatRect area_equal = ui_data.sprites.spr_equal.getGlobalBounds();
        if (contains(area_equal, mouse)) {
        }
        sf::FloatRect area_delete = ui_data.sprites.spr_delete.getGlobalBounds();
        if (contains(area_delete, mouse)) {
        }
      }

    }
  }
}