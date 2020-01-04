#include "UserInterface.hpp"
#include<sstream>
void requestOutput(BaseData &base_data) {
  bool success = true;
  double result = 0;
  std::string intermediate = base_data.input_form.input.toAnsiString();
  if (intermediate.length()==0) {
    success = false;
  } else {
    char *input = new char[intermediate.length() + 1];
    strcpy(input, intermediate.c_str());
    processingInput(input, success, result, base_data.aliases, base_data.dimension);
    delete[]input;
  }

  if (success) {
    std::ostringstream strs;
    strs << result;
    base_data.output_string = strs.str();


//base_data.output_string = std::to_string(result);
  } else {
    base_data.output_string = "WRONG INPUT !";
  }
  base_data.output.setString(base_data.output_string);
  base_data.output.setPosition((WIDTH - 4*IMG_SCALED - 5*THICKNESS - base_data.output.getLocalBounds().width)/2,
                               4.25*IMG_SCALED - base_data.font_size - THICKNESS);

}

void setSpritesDetails(BaseData &base_data) {
  //texturi
  base_data.sprites.spr_delete.setTexture(base_data.texture);
  base_data.sprites.spr_equal.setTexture(base_data.texture);
  base_data.sprites.spr_left_font_name.setTexture(base_data.texture);
  base_data.sprites.spr_left_font_size.setTexture(base_data.texture);
  base_data.sprites.spr_left_song_name.setTexture(base_data.texture);
  base_data.sprites.spr_left_song_vol.setTexture(base_data.texture);
  base_data.sprites.spr_music.setTexture(base_data.texture);
  base_data.sprites.spr_sfx.setTexture(base_data.texture);
  base_data.sprites.spr_left_sfx_vol.setTexture(base_data.texture);
  base_data.sprites.spr_right_sfx_vol.setTexture(base_data.texture);
  base_data.sprites.spr_mode.setTexture(base_data.texture);
  base_data.sprites.spr_right_font_name.setTexture(base_data.texture);
  base_data.sprites.spr_right_font_size.setTexture(base_data.texture);
  base_data.sprites.spr_right_song_name.setTexture(base_data.texture);
  base_data.sprites.spr_right_song_vol.setTexture(base_data.texture);
  base_data.sprites.spr_settings.setTexture(base_data.texture);
  base_data.sprites.spr_clear.setTexture(base_data.texture);
  base_data.sprites.spr_history.setTexture(base_data.texture);
  base_data.sprites.spr_themes.setTexture(base_data.texture);

  //positions
  base_data.sprites.spr_settings.setPosition(WIDTH - (PADDING + IMG_SCALED), PADDING);
  base_data.sprites.spr_music.setPosition(WIDTH - 2*(PADDING + IMG_SCALED), PADDING);
  base_data.sprites.spr_sfx.setPosition(WIDTH - 3*(PADDING + IMG_SCALED), PADDING);
  base_data.sprites.spr_mode.setPosition(WIDTH - 4*(PADDING + IMG_SCALED), PADDING);
  base_data.sprites.spr_history.setPosition(WIDTH - 5*(PADDING + IMG_SCALED), PADDING);
  base_data.sprites.spr_themes.setPosition(WIDTH - 6*(PADDING + IMG_SCALED), PADDING);
  base_data.sprites.spr_equal.setPosition(WIDTH - (PADDING + IMG_SCALED), 2*IMG_SCALED + THICKNESS + 2);
  base_data.sprites.spr_delete.setPosition(WIDTH - 2*(PADDING + IMG_SCALED), 2*IMG_SCALED + THICKNESS + 2);
  base_data.sprites.spr_clear.setPosition(WIDTH - 3*(PADDING + IMG_SCALED), 2*IMG_SCALED + THICKNESS + 2);

  base_data.sprites.spr_left_song_vol.setPosition(
      base_data.boxes.song_volume.getPosition().x - PADDING - IMG_SCALED - THICKNESS,
      base_data.boxes.song_volume.getPosition().y - THICKNESS);
  base_data.sprites.spr_right_song_vol.setPosition(
      base_data.boxes.song_volume.getPosition().x + PADDING + base_data.boxes.song_volume.getSize().x + THICKNESS,
      base_data.boxes.song_volume.getPosition().y - THICKNESS);

  base_data.sprites.spr_left_sfx_vol.setPosition(
      base_data.boxes.sfx_volume.getPosition().x - PADDING - IMG_SCALED - THICKNESS,
      base_data.boxes.sfx_volume.getPosition().y - THICKNESS);
  base_data.sprites.spr_right_sfx_vol.setPosition(
      base_data.boxes.sfx_volume.getPosition().x + PADDING + base_data.boxes.sfx_volume.getSize().x + THICKNESS,
      base_data.boxes.sfx_volume.getPosition().y - THICKNESS);

  base_data.sprites.spr_left_song_name.setPosition(
      base_data.boxes.song_name.getPosition().x - PADDING - IMG_SCALED - THICKNESS,
      base_data.boxes.song_name.getPosition().y - THICKNESS);
  base_data.sprites.spr_right_song_name.setPosition(
      base_data.boxes.song_name.getPosition().x + PADDING + base_data.boxes.song_name.getSize().x + THICKNESS,
      base_data.boxes.song_name.getPosition().y - THICKNESS);

  base_data.sprites.spr_left_font_name.setPosition(
      base_data.boxes.font_name.getPosition().x - PADDING - IMG_SCALED - THICKNESS,
      base_data.boxes.font_name.getPosition().y - THICKNESS);
  base_data.sprites.spr_right_font_name.setPosition(
      base_data.boxes.font_name.getPosition().x + PADDING + base_data.boxes.font_name.getSize().x + THICKNESS,
      base_data.boxes.font_name.getPosition().y - THICKNESS);

  base_data.sprites.spr_left_font_size.setPosition(
      base_data.boxes.font_size.getPosition().x - PADDING - IMG_SCALED - THICKNESS,
      base_data.boxes.font_size.getPosition().y - THICKNESS);
  base_data.sprites.spr_right_font_size.setPosition(
      base_data.boxes.font_size.getPosition().x + PADDING + base_data.boxes.font_size.getSize().x + THICKNESS,
      base_data.boxes.font_size.getPosition().y - THICKNESS);

//images

  base_data.sprites.spr_delete.setTextureRect(sf::IntRect(0, 0, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_equal.setTextureRect(sf::IntRect(0, 96, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_left_font_name.setTextureRect(sf::IntRect(0, 192, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_left_font_size.setTextureRect(sf::IntRect(0, 192, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_left_song_name.setTextureRect(sf::IntRect(0, 192, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_left_song_vol.setTextureRect(sf::IntRect(0, 192, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_left_sfx_vol.setTextureRect(sf::IntRect(0, 192, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_mode.setTextureRect(sf::IntRect(0, 288, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_music.setTextureRect(sf::IntRect(0, 576, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_sfx.setTextureRect(sf::IntRect(0, 672, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_right_font_name.setTextureRect(sf::IntRect(0, 384, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_right_font_size.setTextureRect(sf::IntRect(0, 384, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_right_song_name.setTextureRect(sf::IntRect(0, 384, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_right_song_vol.setTextureRect(sf::IntRect(0, 384, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_right_sfx_vol.setTextureRect(sf::IntRect(0, 384, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_settings.setTextureRect(sf::IntRect(0, 480, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_clear.setTextureRect(sf::IntRect(0, 768, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_history.setTextureRect(sf::IntRect(0, 864, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_themes.setTextureRect(sf::IntRect(0, 960, IMG_REAL, IMG_REAL));
//scaling

  base_data.sprites.spr_delete.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_equal.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_left_font_name.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_left_font_size.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_left_song_name.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_left_song_vol.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_left_sfx_vol.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_music.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_sfx.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_mode.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_right_font_name.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_right_font_size.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_right_song_name.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_right_song_vol.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_right_sfx_vol.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_settings.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_clear.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_history.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_themes.scale(sf::Vector2f(X_TIMES, X_TIMES));
}
void setLabelsTextsPositions(BaseData &base_data) {
  float vertical_pos = (HEIGHT - 10*IMG_SCALED - 5*VERTICAL_PADDING)/2.f + 4;
  base_data.settings_texts.label_song_volume.setPosition(
      (WIDTH - base_data.settings_texts.label_song_volume.getLocalBounds().width)/2,
      vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);
  base_data.settings_texts.song_volume.setPosition(
      (WIDTH - base_data.settings_texts.song_volume.getLocalBounds().width)/2, vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);

  base_data.settings_texts.label_sfx_volume.setPosition(
      (WIDTH - base_data.settings_texts.label_sfx_volume.getLocalBounds().width)/2,
      vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);
  base_data.settings_texts.sfx_volume.setPosition(
      (WIDTH - base_data.settings_texts.sfx_volume.getLocalBounds().width)/2, vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);

  base_data.settings_texts.label_song_name.setPosition(
      (WIDTH - base_data.settings_texts.label_song_name.getGlobalBounds().width)/2,
      vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);
  base_data.settings_texts.song_name.setPosition((WIDTH - base_data.settings_texts.song_name.getLocalBounds().width)/2,
                                                 vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);

  base_data.settings_texts.label_font_name.setPosition(
      (WIDTH - base_data.settings_texts.label_font_name.getGlobalBounds().width)/2,
      vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);
  base_data.settings_texts.font_name.setPosition((WIDTH - base_data.settings_texts.font_name.getLocalBounds().width)/2,
                                                 vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);

  base_data.settings_texts.label_font_size.setPosition(
      (WIDTH - base_data.settings_texts.label_font_size.getGlobalBounds().width)/2,
      vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);
  base_data.settings_texts.font_size.setPosition((WIDTH - base_data.settings_texts.font_size.getLocalBounds().width)/2,
                                                 vertical_pos);

}

void updateSettingsView(BaseData &base_data) {
  base_data.settings_texts.font_name.setString(base_data.font_list[base_data.font_index].name);
  base_data.settings_texts.song_name.setString(base_data.song_list[base_data.song_index].name);
  char sir[20];
  convertIToC(base_data.font_size, sir);
  base_data.settings_texts.font_size.setString(sir);
  convertIToC(base_data.volumes.music_settings, sir);
  base_data.settings_texts.song_volume.setString(sir);
  convertIToC(base_data.volumes.sfx_settings, sir);
  base_data.settings_texts.sfx_volume.setString(sir);

  setLabelsTextsPositions(base_data);
}

void initialSetup(BaseData &base_data) {
  setBoxesDetails(base_data);
  setSpritesDetails(base_data);
  setTextFont(base_data);
  setSFXVolume(base_data);
  setSFXVolumeSlideDim(base_data);
  setSongVolume(base_data);
  setSongVolumeSlideDim(base_data);
  setTextFontSize(base_data);
  setSongToPlay(base_data);
  base_data.initial_setup = false;
  base_data.settings_texts.label_font_name.setString("FONT:");
  base_data.settings_texts.label_song_name.setString("SONG:");
  base_data.settings_texts.label_song_volume.setString("SONG VOLUME:");
  base_data.settings_texts.label_sfx_volume.setString("SFX VOLUME:");
  base_data.settings_texts.label_settings.setString("SETTINGS");
  base_data.settings_texts.label_font_size.setString("FONT SIZE:");

  base_data.settings_texts.font_size.setOutlineThickness(THICKNESS - 1);
  base_data.settings_texts.sfx_volume.setOutlineThickness(THICKNESS - 1);
  base_data.settings_texts.song_volume.setOutlineThickness(THICKNESS - 1);
  setTheme(base_data);
  base_data.output_line.setSize(sf::Vector2f((WIDTH - 5*IMG_SCALED - 5*THICKNESS), 2));
  base_data.output_line.setOutlineThickness(0);
  base_data.output_line.setPosition(IMG_SCALED, 4.25*IMG_SCALED + THICKNESS);

  updateSettingsView(base_data);
  changeMode(base_data);

  sf::Vector2f position = sf::Vector2f(IMG_SCALED, 2*IMG_SCALED + 2.6*THICKNESS);
  sf::Vector2f box_size = sf::Vector2f(WIDTH - 5*IMG_SCALED - 5*THICKNESS, IMG_SCALED - 2*THICKNESS);
  setupTextBox(base_data.input_form, box_size, position, base_data.font_list[base_data.font_index].font,
               sf::Color::Transparent, base_data.colors.text, THICKNESS_FORM, MAX_CHARS_VIEW, base_data.font_size);

}

void changeMode(BaseData &base_data) {

  base_data.colors.back =
      (base_data.switches.is_dark_mode) ? base_data.colors.default_text_color
                                        : base_data.colors.default_background_color;
  base_data.colors.text =
      (base_data.switches.is_dark_mode) ? base_data.colors.default_background_color
                                        : base_data.colors.default_text_color;
  base_data.sprites.spr_delete.setColor(base_data.colors.text);
  base_data.sprites.spr_equal.setColor(base_data.colors.text);
  base_data.sprites.spr_left_song_vol.setColor(base_data.colors.text);
  base_data.sprites.spr_right_song_vol.setColor(base_data.colors.text);
  base_data.sprites.spr_left_sfx_vol.setColor(base_data.colors.text);
  base_data.sprites.spr_right_sfx_vol.setColor(base_data.colors.text);
  base_data.sprites.spr_left_song_name.setColor(base_data.colors.text);
  base_data.sprites.spr_right_song_name.setColor(base_data.colors.text);
  base_data.sprites.spr_left_font_name.setColor(base_data.colors.text);
  base_data.sprites.spr_right_font_name.setColor(base_data.colors.text);
  base_data.sprites.spr_left_font_size.setColor(base_data.colors.text);
  base_data.sprites.spr_right_font_size.setColor(base_data.colors.text);
  base_data.sprites.spr_history.setColor(base_data.colors.text);
  base_data.sprites.spr_themes.setColor(base_data.colors.text);
  base_data.sprites.spr_clear.setColor(base_data.colors.text);

  base_data.boxes.song_volume_visual.setFillColor(base_data.colors.text);
  base_data.boxes.sfx_volume_visual.setFillColor(base_data.colors.text);
  base_data.boxes.font_size_visual.setFillColor(base_data.colors.text);

  base_data.input_form.text.setFillColor(base_data.colors.text);
  base_data.input_form.back_box.setOutlineColor(base_data.colors.text);
  base_data.output.setFillColor(base_data.colors.text);

  base_data.output_line.setFillColor(base_data.colors.text);

  if (base_data.switches.is_music)
    base_data.sprites.spr_music.setColor(base_data.colors.text);
  else
    base_data.sprites.spr_music.setColor(base_data.colors.muted);

  base_data.sprites.spr_mode.setColor(base_data.colors.text);

  if (base_data.switches.is_sfx)
    base_data.sprites.spr_sfx.setColor(base_data.colors.text);
  else
    base_data.sprites.spr_sfx.setColor(base_data.colors.muted);
  if (!base_data.switches.is_settings)
    base_data.sprites.spr_settings.setColor(base_data.colors.text);
  else
    base_data.sprites.spr_settings.setColor(base_data.colors.settings_clicked);
  updateBoxesAndTextsOutlineColor(base_data);
}

void handleEvents(sf::RenderWindow &window, sf::Event &event, BaseData &base_data) {

  while (window.pollEvent(event)) {

    if (event.type==sf::Event::Closed) {
      window.close();
    }
    if (event.type==sf::Event::KeyPressed && !base_data.switches.is_settings) {

      if (base_data.input_form.focus) {
        if (event.key.code==sf::Keyboard::Right) {
          playTyping(base_data.sounds);
          if (base_data.input_form.insert_position < 0) {
            base_data.input_form.insert_position++;
            base_data.input_form.ruler++;

            if (base_data.input_form.ruler==base_data.input_form.max_chars_view)
              base_data.input_form.start_index++, base_data.input_form.ruler--;

          }
        } else if (event.key.code==sf::Keyboard::Left) {
          playTyping(base_data.sounds);
          if (-base_data.input_form.insert_position < base_data.input_form.input.getSize()) {
            base_data.input_form.ruler--;
            base_data.input_form.insert_position--;

            if (base_data.input_form.ruler==-1 && base_data.input_form.start_index > 0)
              base_data.input_form.start_index--, base_data.input_form.ruler++;

          }

        }
      }

    }
    if (event.type==sf::Event::TextEntered && base_data.input_form.focus && !base_data.switches.is_settings) {
      char c = static_cast<char>(event.text.unicode);
      playTyping(base_data.sounds);
      //clears output area
      if (int(c==13)) {
        base_data.switches.requestAnswer = true;
        requestOutput(base_data);
      } else {
        base_data.switches.requestAnswer = false;
        resetOutput(base_data);
        handleKeyEvent(base_data.input_form, c);
      }
    }
    sf::Vector2i mouse = sf::Mouse::getPosition(window);

    if (event.type==sf::Event::MouseButtonPressed) {
//////////////////////////////////////// Music volume box interaction ////////////////////////////////////////
      bool previous_focus = base_data.input_form.focus;
      base_data.input_form.focus = mouse.x >= base_data.input_form.back_box.getPosition().x &&
          mouse.x <= base_data.input_form.back_box.getPosition().x + base_data.input_form.back_box.getSize().x &&
          mouse.y >= base_data.input_form.back_box.getPosition().y &&
          mouse.y <= base_data.input_form.back_box.getPosition().y + base_data.input_form.back_box.getSize().y;

      if (!previous_focus && base_data.input_form.focus) {
        playClick(base_data.sounds);
      }
      sf::FloatRect area_vol_slide = base_data.boxes.song_volume.getGlobalBounds();
      if (contains(area_vol_slide, mouse)) {
        playClick(base_data.sounds);
        float step = (area_vol_slide.width)/(102.f);
        int volume_test = int((mouse.x - base_data.boxes.song_volume.getPosition().x)/step);
        if (volume_test >= 0 && volume_test <= 100) {
          if (!base_data.switches.is_music) {
            base_data.switches.is_music = true;
          }
          base_data.volumes.music = volume_test;
          setSongVolume(base_data);

        }
      }
      //////////////////////////////////////// SFX volume box interaction ////////////////////////////////////////

      sf::FloatRect area_sfx_slide = base_data.boxes.sfx_volume.getGlobalBounds();
      if (contains(area_sfx_slide, mouse)) {
        playClick(base_data.sounds);
        float step = (area_sfx_slide.width)/(102.f);
        int volume_test = int((mouse.x - base_data.boxes.sfx_volume.getPosition().x)/step);
        if (volume_test >= 0 && volume_test <= 100) {
          if (!base_data.switches.is_sfx) {
            base_data.switches.is_sfx = true;
          }
          base_data.volumes.sfx = volume_test;
          setSFXVolume(base_data);
        }
      }
      //////////////////////////////////////// Font size box interaction ////////////////////////////////////////

      sf::FloatRect area_font_slide = base_data.boxes.font_size.getGlobalBounds();
      if (contains(area_font_slide, mouse)) {
        playClick(base_data.sounds);
        float step = (area_font_slide.width)/(8.f);
        int font_size_test = int((mouse.x - base_data.boxes.font_size.getPosition().x)/step) + 20;
        if (font_size_test >= MIN_DIM_FONT && font_size_test <= MAX_DIM_FONT) {
          base_data.font_size = font_size_test;

          setTextFontSize(base_data);
        }
      }
    }

//////////////////////////////////////// Settings button interaction ////////////////////////////////////////

    if (base_data.colors.before_hover_settings==sf::Color::Transparent) {
      base_data.colors.before_hover_settings = base_data.sprites.spr_settings.getColor();
    }
    sf::FloatRect area_settings_button = base_data.sprites.spr_settings.getGlobalBounds();
    if (contains(area_settings_button, mouse)) {
      base_data.sprites.spr_settings.setColor(base_data.colors.hover);
      if (event.type==sf::Event::MouseButtonPressed) {
        playClick(base_data.sounds);
        base_data.switches.is_settings = !base_data.switches.is_settings;
        if (!base_data.switches.is_settings) {
          base_data.sprites.spr_settings.setColor(base_data.colors.text);
          base_data.colors.before_hover_settings = base_data.colors.text;
        } else {
          base_data.sprites.spr_settings.setColor(base_data.colors.settings_clicked);
          base_data.colors.before_hover_settings = base_data.colors.settings_clicked;
        }
      }
    } else {
      base_data.sprites.spr_settings.setColor(base_data.colors.before_hover_settings);
      base_data.colors.before_hover_settings = sf::Color::Transparent;
    }
////////////////////////////////////////   ////////////////////////////////////////
    if (base_data.colors.before_hover_clear==sf::Color::Transparent) {
      base_data.colors.before_hover_clear = base_data.sprites.spr_clear.getColor();
    }
    sf::FloatRect area_clear_button = base_data.sprites.spr_clear.getGlobalBounds();
    if (contains(area_clear_button, mouse)) {
      base_data.sprites.spr_clear.setColor(base_data.colors.hover);
      if (event.type==sf::Event::MouseButtonPressed) {
        playClick(base_data.sounds);
        resetInputForm(base_data.input_form, MAX_CHARS_VIEW);
        resetOutput(base_data);
      }
    } else {
      base_data.sprites.spr_clear.setColor(base_data.colors.before_hover_clear);
      base_data.colors.before_hover_clear = sf::Color::Transparent;
    }

////////////////////////////////////////   ////////////////////////////////////////
    if (base_data.colors.before_hover_delete==sf::Color::Transparent) {
      base_data.colors.before_hover_delete = base_data.sprites.spr_delete.getColor();
    }
    sf::FloatRect area_delete_button = base_data.sprites.spr_delete.getGlobalBounds();
    if (contains(area_delete_button, mouse)) {
      base_data.sprites.spr_delete.setColor(base_data.colors.hover);
      if (event.type==sf::Event::MouseButtonPressed) {
        playClick(base_data.sounds);
        deleteKey(base_data.input_form);
        resetOutput(base_data);
        base_data.input_form.focus = true;
      }
    } else {
      base_data.sprites.spr_delete.setColor(base_data.colors.before_hover_delete);
      base_data.colors.before_hover_delete = sf::Color::Transparent;
    }

    //////////////////////////////////////// Music button interaction ////////////////////////////////////////

    if (base_data.colors.before_hover_music==sf::Color::Transparent) {
      base_data.colors.before_hover_music = base_data.sprites.spr_music.getColor();
    }
    sf::FloatRect area_music_button = base_data.sprites.spr_music.getGlobalBounds();
    if (contains(area_music_button, mouse)) {
      base_data.sprites.spr_music.setColor(base_data.colors.hover);
      if (event.type==sf::Event::MouseButtonPressed) {
        base_data.switches.is_music = !base_data.switches.is_music;
        if (base_data.switches.is_music)
          base_data.colors.before_hover_music = base_data.colors.text;
        else
          base_data.colors.before_hover_music = base_data.colors.muted;
        setSongVolume(base_data);
        playClick(base_data.sounds);
        updateSettingsView(base_data);
      }
    } else {
      base_data.sprites.spr_music.setColor(base_data.colors.before_hover_music);
      base_data.colors.before_hover_music = sf::Color::Transparent;
    }

    //////////////////////////////////////// SFX volume button interaction ////////////////////////////////////////
    if (base_data.colors.before_hover_sfx==sf::Color::Transparent) {
      base_data.colors.before_hover_sfx = base_data.sprites.spr_sfx.getColor();
    }
    sf::FloatRect area_sfx_button = base_data.sprites.spr_sfx.getGlobalBounds();
    if (contains(area_sfx_button, mouse)) {
      base_data.sprites.spr_sfx.setColor(base_data.colors.hover);
      if (event.type==sf::Event::MouseButtonPressed) {
        base_data.switches.is_sfx = !base_data.switches.is_sfx;
        if (base_data.switches.is_sfx)
          base_data.colors.before_hover_sfx = base_data.colors.text;
        else
          base_data.colors.before_hover_sfx = base_data.colors.muted;
        setSFXVolume(base_data);
        playClick(base_data.sounds);
        updateSettingsView(base_data);
      }
    } else {
      base_data.sprites.spr_sfx.setColor(base_data.colors.before_hover_sfx);
      base_data.colors.before_hover_sfx = sf::Color::Transparent;
    }

//////////////////////////////////////// Mode button interaction ////////////////////////////////////////

    if (base_data.colors.before_hover_mode==sf::Color::Transparent) {
      base_data.colors.before_hover_mode = base_data.sprites.spr_mode.getColor();
    }

    sf::FloatRect area_mode_button = base_data.sprites.spr_mode.getGlobalBounds();
    if (contains(area_mode_button, mouse)) {
      base_data.sprites.spr_mode.setColor(base_data.colors.hover);
      if (event.type==sf::Event::MouseButtonPressed) {
        base_data.switches.is_dark_mode = !base_data.switches.is_dark_mode;
        playClick(base_data.sounds);
        changeMode(base_data);
        base_data.colors.before_hover_mode = base_data.colors.text;
      }
    } else {
      base_data.sprites.spr_mode.setColor(base_data.colors.before_hover_mode);
      base_data.colors.before_hover_mode = sf::Color::Transparent;
    }

    //////////////////////////////////////// Theme button interaction ////////////////////////////////////////

    if (base_data.colors.before_hover_themes==sf::Color::Transparent) {
      base_data.colors.before_hover_themes = base_data.sprites.spr_themes.getColor();
    }

    sf::FloatRect area_themes_button = base_data.sprites.spr_themes.getGlobalBounds();
    if (contains(area_themes_button, mouse)) {
      base_data.sprites.spr_themes.setColor(base_data.colors.hover);
      if (event.type==sf::Event::MouseButtonPressed) {
        base_data.theme_index++;
        if (base_data.theme_index==base_data.number_of_themes)
          base_data.theme_index = 0;
        setTheme(base_data);
        playClick(base_data.sounds);
        changeMode(base_data);
        base_data.colors.before_hover_themes = base_data.colors.text;
      }
    } else {
      base_data.sprites.spr_themes.setColor(base_data.colors.before_hover_themes);
      base_data.colors.before_hover_themes = sf::Color::Transparent;
    }

    if (base_data.switches.is_settings) {

      //////////////////////////////////////// Left volume music button interaction /////////////////////////////////////
      if (base_data.colors.before_hover_left_music_volume==sf::Color::Transparent) {
        base_data.colors.before_hover_left_music_volume = base_data.sprites.spr_left_song_vol.getColor();
      }

      sf::FloatRect area_left_vol_music = base_data.sprites.spr_left_song_vol.getGlobalBounds();
      if (contains(area_left_vol_music, mouse)) {
        base_data.sprites.spr_left_song_vol.setColor(base_data.colors.hover);
        if (event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateSongVolume(base_data, true);
        }
      } else {
        base_data.sprites.spr_left_song_vol.setColor(base_data.colors.before_hover_left_music_volume);
        base_data.colors.before_hover_left_music_volume = sf::Color::Transparent;
      }

      //////////////////////////////////////// Right volume music button interaction ////////////////////////////////////////
      if (base_data.colors.before_hover_right_music_volume==sf::Color::Transparent) {
        base_data.colors.before_hover_right_music_volume = base_data.sprites.spr_right_song_vol.getColor();
      }

      sf::FloatRect area_right_vol_music = base_data.sprites.spr_right_song_vol.getGlobalBounds();
      if (contains(area_right_vol_music, mouse)) {
        base_data.sprites.spr_right_song_vol.setColor(base_data.colors.hover);
        if (event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateSongVolume(base_data, false);
        }
      } else {
        base_data.sprites.spr_right_song_vol.setColor(base_data.colors.before_hover_right_music_volume);
        base_data.colors.before_hover_right_music_volume = sf::Color::Transparent;
      }

      //////////////////////////////////////// Left volume SFX button interaction ////////////////////////////////////////

      if (base_data.colors.before_hover_left_sfx_volume==sf::Color::Transparent) {
        base_data.colors.before_hover_left_sfx_volume = base_data.sprites.spr_left_sfx_vol.getColor();
      }

      sf::FloatRect area_left_vol_sfx = base_data.sprites.spr_left_sfx_vol.getGlobalBounds();
      if (contains(area_left_vol_sfx, mouse)) {
        base_data.sprites.spr_left_sfx_vol.setColor(base_data.colors.hover);
        if (event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateSFXVolume(base_data, true);
        }
      } else {
        base_data.sprites.spr_left_sfx_vol.setColor(base_data.colors.before_hover_left_sfx_volume);
        base_data.colors.before_hover_left_sfx_volume = sf::Color::Transparent;
      }

      //////////////////////////////////////// Right volume SFX button interaction ////////////////////////////////////////
      if (base_data.colors.before_hover_right_sfx_volume==sf::Color::Transparent) {
        base_data.colors.before_hover_right_sfx_volume = base_data.sprites.spr_right_sfx_vol.getColor();
      }

      sf::FloatRect area_right_vol_sfx = base_data.sprites.spr_right_sfx_vol.getGlobalBounds();
      if (contains(area_right_vol_sfx, mouse)) {
        base_data.sprites.spr_right_sfx_vol.setColor(base_data.colors.hover);
        if (event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateSFXVolume(base_data, false);
        }
      } else {
        base_data.sprites.spr_right_sfx_vol.setColor(base_data.colors.before_hover_right_sfx_volume);
        base_data.colors.before_hover_right_sfx_volume = sf::Color::Transparent;
      }
//////////////////////////////////////// Left song name button interaction ////////////////////////////////////////

      if (base_data.colors.before_hover_left_song_name==sf::Color::Transparent) {
        base_data.colors.before_hover_left_song_name = base_data.sprites.spr_left_song_name.getColor();
      }

      sf::FloatRect area_left_song_name = base_data.sprites.spr_left_song_name.getGlobalBounds();
      if (contains(area_left_song_name, mouse)) {
        base_data.sprites.spr_left_song_name.setColor(base_data.colors.hover);
        if (event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateSongName(base_data, true);
        }
      } else {
        base_data.sprites.spr_left_song_name.setColor(base_data.colors.before_hover_left_song_name);
        base_data.colors.before_hover_left_song_name = sf::Color::Transparent;
      }

//////////////////////////////////////// Right song name button interaction ////////////////////////////////////////

      if (base_data.colors.before_hover_right_song_name==sf::Color::Transparent) {
        base_data.colors.before_hover_right_song_name = base_data.sprites.spr_right_song_name.getColor();
      }

      sf::FloatRect area_right_song_name = base_data.sprites.spr_right_song_name.getGlobalBounds();
      if (contains(area_right_song_name, mouse)) {
        base_data.sprites.spr_right_song_name.setColor(base_data.colors.hover);
        if (event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateSongName(base_data, false);
        }
      } else {
        base_data.sprites.spr_right_song_name.setColor(base_data.colors.before_hover_right_song_name);
        base_data.colors.before_hover_right_song_name = sf::Color::Transparent;
      }

//////////////////////////////////////// Left font name button interaction ////////////////////////////////////////

      if (base_data.colors.before_hover_left_font_name==sf::Color::Transparent) {
        base_data.colors.before_hover_left_font_name = base_data.sprites.spr_left_font_name.getColor();
      }

      sf::FloatRect area_left_font_name = base_data.sprites.spr_left_font_name.getGlobalBounds();
      if (contains(area_left_font_name, mouse)) {
        base_data.sprites.spr_left_font_name.setColor(base_data.colors.hover);
        if (event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateTextFont(base_data, true);
        }
      } else {
        base_data.sprites.spr_left_font_name.setColor(base_data.colors.before_hover_left_font_name);
        base_data.colors.before_hover_left_font_name = sf::Color::Transparent;
      }

//////////////////////////////////////// Right font name button interaction ////////////////////////////////////////

      if (base_data.colors.before_hover_right_font_name==sf::Color::Transparent) {
        base_data.colors.before_hover_right_font_name = base_data.sprites.spr_right_font_name.getColor();
      }

      sf::FloatRect area_right_font_name = base_data.sprites.spr_right_font_name.getGlobalBounds();
      if (contains(area_right_font_name, mouse)) {
        base_data.sprites.spr_right_font_name.setColor(base_data.colors.hover);
        if (event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateTextFont(base_data, false);
        }
      } else {
        base_data.sprites.spr_right_font_name.setColor(base_data.colors.before_hover_right_font_name);
        base_data.colors.before_hover_right_font_name = sf::Color::Transparent;
      }


//////////////////////////////////////// Left font size button interaction ////////////////////////////////////////

      if (base_data.colors.before_hover_left_font_size==sf::Color::Transparent) {
        base_data.colors.before_hover_left_font_size = base_data.sprites.spr_left_font_size.getColor();
      }

      sf::FloatRect area_left_font_size = base_data.sprites.spr_left_font_size.getGlobalBounds();
      if (contains(area_left_font_size, mouse)) {
        base_data.sprites.spr_left_font_size.setColor(base_data.colors.hover);
        if (event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateTextFontSize(base_data, true);
        }
      } else {
        base_data.sprites.spr_left_font_size.setColor(base_data.colors.before_hover_left_font_size);
        base_data.colors.before_hover_left_font_size = sf::Color::Transparent;
      }

//////////////////////////////////////// Right font size button interaction ////////////////////////////////////////

      if (base_data.colors.before_hover_right_font_size==sf::Color::Transparent) {
        base_data.colors.before_hover_right_font_size = base_data.sprites.spr_right_font_size.getColor();
      }

      sf::FloatRect area_right_font_size = base_data.sprites.spr_right_font_size.getGlobalBounds();
      if (contains(area_right_font_size, mouse)) {
        base_data.sprites.spr_right_font_size.setColor(base_data.colors.hover);
        if (event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateTextFontSize(base_data, false);
        }
      } else {
        base_data.sprites.spr_right_font_size.setColor(base_data.colors.before_hover_right_font_size);
        base_data.colors.before_hover_right_font_size = sf::Color::Transparent;
      }

    } else {
//////////////////////////////////////// Equal button interaction ////////////////////////////////////////

      if (base_data.colors.before_hover_equal==sf::Color::Transparent) {
        base_data.colors.before_hover_equal = base_data.sprites.spr_equal.getColor();
      }

      sf::FloatRect area_equal = base_data.sprites.spr_equal.getGlobalBounds();
      if (contains(area_equal, mouse)) {
        base_data.sprites.spr_equal.setColor(base_data.colors.hover);
        if (event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          base_data.switches.requestAnswer = true;
          base_data.input_form.focus = true;
          requestOutput(base_data);
        }
      } else {
        base_data.sprites.spr_equal.setColor(base_data.colors.before_hover_equal);
        base_data.colors.before_hover_equal = sf::Color::Transparent;
      }
//////////////////////////////////////// Delete button interaction ////////////////////////////////////////

      if (base_data.colors.before_hover_delete==sf::Color::Transparent) {
        base_data.colors.before_hover_delete = base_data.sprites.spr_delete.getColor();
      }

      sf::FloatRect area_delete = base_data.sprites.spr_delete.getGlobalBounds();
      if (contains(area_delete, mouse)) {
        base_data.sprites.spr_delete.setColor(base_data.colors.hover);
        if (event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);

        }
      } else {
        base_data.sprites.spr_delete.setColor(base_data.colors.before_hover_delete);
        base_data.colors.before_hover_delete = sf::Color::Transparent;
      }

    }
  }
}

void navigateSongVolume(BaseData &base_data,
                        bool decrement) {
  int st = 0, dr = 100;
  if (decrement) {
    if (base_data.volumes.music - 1 >= st) {
      base_data.volumes.music -= 1;
    }
  } else {
    if (base_data.volumes.music + 1 <= dr) {
      base_data.volumes.music += 1;
    }
  }
  base_data.switches.is_music = base_data.volumes.music!=0;
  setSongVolume(base_data);

}
void setSongVolume(BaseData &base_data) {
  float volume_temp;
  if (base_data.switches.is_music)
    base_data.switches.is_music = base_data.volumes.music!=0;
  if (base_data.switches.is_music) {
    volume_temp = float(base_data.volumes.music);
    base_data.volumes.music_settings = base_data.volumes.music;
  } else {
    base_data.volumes.music_settings = 0;
    volume_temp = 0.f;
  }
  if (base_data.switches.is_music)
    base_data.sprites.spr_music.setColor(base_data.colors.text);
  else
    base_data.sprites.spr_music.setColor(base_data.colors.muted);
  base_data.song_list[base_data.song_index].song.setVolume(volume_temp);

  if (!base_data.initial_setup) {
    updateSettingsView(base_data);
  }
  setSongVolumeSlideDim(base_data);
}

void navigateSFXVolume(BaseData &base_data, bool decrement) {
  int st = 0, dr = 100;
  if (decrement) {
    if (base_data.volumes.sfx - 1 >= st) {
      base_data.volumes.sfx -= 1;
    }
  } else {
    if (base_data.volumes.sfx + 1 <= dr) {
      base_data.volumes.sfx += 1;
    }
  }
  base_data.switches.is_sfx = base_data.volumes.sfx!=0;
  setSFXVolume(base_data);

}
void setSFXVolume(BaseData &base_data) {
  float vol_inter;
  if (base_data.switches.is_sfx)
    base_data.switches.is_sfx = base_data.volumes.sfx!=0;

  if (base_data.switches.is_sfx) {
    vol_inter = float(base_data.volumes.sfx);
    base_data.volumes.sfx_settings = base_data.volumes.sfx;
  } else {
    base_data.volumes.sfx_settings = 0;
    vol_inter = 0.f;
  }
  if (base_data.switches.is_sfx)
    base_data.sprites.spr_sfx.setColor(base_data.colors.text);
  else
    base_data.sprites.spr_sfx.setColor(base_data.colors.muted);
  for (unsigned index = 0; index < MAX_CLICKS_STROKES; ++index) {
    base_data.sounds.click[index].setVolume(vol_inter);
    base_data.sounds.typing[index].setVolume(vol_inter);
  }
  if (!base_data.initial_setup) {
    updateSettingsView(base_data);
  }
  setSFXVolumeSlideDim(base_data);
}
void navigateSongName(BaseData &base_data,
                      bool decrement) {
  base_data.song_list[base_data.song_index].song.stop();
  base_data.song_list[base_data.song_index].playing = false;
  base_data.song_index =
      (decrement) ? ((base_data.song_index==0) ? base_data.number_of_songs - 1 : base_data.song_index - 1)
                  : ((base_data.song_index==base_data.number_of_songs - 1) ? 0 : base_data.song_index
          + 1);
  setSongToPlay(base_data);
}

void setSongToPlay(BaseData &base_data) {
  base_data.settings_texts.song_name.setString(base_data.song_list[base_data.song_index].name);
  base_data.song_list[base_data.song_index].song.play();
  base_data.song_list[base_data.song_index].playing = true;
  if (!base_data.initial_setup) {
    updateSettingsView(base_data);
  }
}
void navigateTextFont(BaseData &base_data,
                      bool decrement) {

  base_data.font_index =
      ((decrement) ? ((base_data.font_index==0) ? base_data.number_of_fonts - 1 : base_data.font_index - 1)
                   : ((base_data.font_index==base_data.number_of_fonts - 1) ? 0 : base_data.font_index + 1));
  setTextFont(base_data);
}

void setTextFont(BaseData &base_data) {
  base_data.settings_texts.label_font_name.setFont(base_data.font_list[base_data.font_index].font);
  base_data.settings_texts.label_font_size.setFont(base_data.font_list[base_data.font_index].font);
  base_data.settings_texts.label_sfx_volume.setFont(base_data.font_list[base_data.font_index].font);
  base_data.settings_texts.label_settings.setFont(base_data.font_list[base_data.font_index].font);
  base_data.settings_texts.label_song_name.setFont(base_data.font_list[base_data.font_index].font);
  base_data.settings_texts.label_song_volume.setFont(base_data.font_list[base_data.font_index].font);
  base_data.settings_texts.font_name.setFont(base_data.font_list[base_data.font_index].font);
  base_data.settings_texts.font_size.setFont(base_data.font_list[base_data.font_index].font);
  base_data.settings_texts.song_name.setFont(base_data.font_list[base_data.font_index].font);
  base_data.settings_texts.song_volume.setFont(base_data.font_list[base_data.font_index].font);
  base_data.settings_texts.sfx_volume.setFont(base_data.font_list[base_data.font_index].font);

  base_data.output.setFont(base_data.font_list[base_data.font_index].font);
  if (!base_data.initial_setup) {
    updateSettingsView(base_data);
    base_data.output.setPosition((WIDTH - 4*IMG_SCALED - 5*THICKNESS - base_data.output.getLocalBounds().width)/2,
                                 4.25*IMG_SCALED - base_data.font_size - THICKNESS);
  }
}
void navigateTextFontSize(BaseData &base_data,
                          bool decrement) {
  if (decrement) {
    if (base_data.font_size - 1 >= MIN_DIM_FONT) {
      base_data.font_size -= 1;
    }
  } else {
    if (base_data.font_size + 1 <= MAX_DIM_FONT) {
      base_data.font_size += 1;
    }
  }
  setTextFontSize(base_data);
}

void setTextFontSize(BaseData &base_data) {
  base_data.settings_texts.song_volume.setCharacterSize(base_data.font_size);
  base_data.settings_texts.sfx_volume.setCharacterSize(base_data.font_size);
  base_data.settings_texts.song_name.setCharacterSize(base_data.font_size);
  base_data.settings_texts.font_name.setCharacterSize(base_data.font_size);
  base_data.settings_texts.font_size.setCharacterSize(base_data.font_size);

  base_data.settings_texts.label_song_volume.setCharacterSize(base_data.font_size);
  base_data.settings_texts.label_sfx_volume.setCharacterSize(base_data.font_size);
  base_data.settings_texts.label_song_name.setCharacterSize(base_data.font_size);
  base_data.settings_texts.label_settings.setCharacterSize(base_data.font_size);
  base_data.settings_texts.label_font_name.setCharacterSize(base_data.font_size);
  base_data.settings_texts.label_font_size.setCharacterSize(base_data.font_size);

  base_data.input_form.text.setCharacterSize(base_data.font_size);
  base_data.output.setCharacterSize(base_data.font_size);
  if (!base_data.initial_setup) {
    updateSettingsView(base_data);
    base_data.output.setPosition((WIDTH - 4*IMG_SCALED - 5*THICKNESS - base_data.output.getLocalBounds().width)/2,
                                 4.25*IMG_SCALED - base_data.font_size - THICKNESS);

  }
  setFontSlideDim(base_data);
}

void loadAssets(BaseData &base_data, bool &success) {
  //loading the fonts
  base_data.files.fonts_in.open("fonts.txt");
  if (!base_data.files.fonts_in.is_open()) {
    std::cerr << "The file responsable with the fonts details cannot be opened!";
    std::exit(1);
  }
  base_data.files.fonts_in >> base_data.number_of_fonts;
  for (unsigned i = 0; i < base_data.number_of_fonts && success; ++i) {
    char path[MAX_PATH];
    char name[MAX_FONT_NAME];
    base_data.files.fonts_in >> path >> name;
    if (!base_data.font_list[i].font.loadFromFile(path)) {
      std::cerr << "The font cannot be loaded: " << name << '\n';
      success = false;
    }
    strcpy(base_data.font_list[i].name, name);
  }
  base_data.files.songs_in.open("songs.txt");
//incarcarea melodiilor
  if (!base_data.files.songs_in.is_open()) {
    std::cerr << "The file responsable with the songs details cannot be opened !";
    std::exit(1);
  }
  base_data.files.songs_in >> base_data.number_of_songs;
  for (unsigned i = 0; i < base_data.number_of_songs && success; ++i) {
    char path[MAX_PATH];
    char name[MAX_SONG_NAME];
    base_data.files.songs_in >> path >> name;
    if (!base_data.song_list[i].song.openFromFile(path)) {
      std::cerr << "The song cannot be opened: " << name << '\n';
      success = false;
    }
    base_data.song_list[i].song.setLoop(true);
    strcpy(base_data.song_list[i].name, name);
  }
  //incarcarea sunetelor
  if (!base_data.sound_buffers.error.loadFromFile(ERROR)) {
    std::cerr << "The error sound cannot be opened: error.wav!\n";
    success = false;
  }
  if (!base_data.sound_buffers.typing.loadFromFile(TYPE)) {
    std::cerr << "The type sound cannot be opened: stroke.wav!\n";
    success = false;
  }
  if (!base_data.sound_buffers.click.loadFromFile(CLICK)) {
    std::cerr << "The click sound cannot be opened: click.wav!\n";
    success = false;
  }
  if (!base_data.texture.loadFromFile(GLOB_TEXTURE)) {
    std::cerr << "The global texture cannot be opened!\n";
    success = false;
  }
  base_data.texture.setSmooth(true);
  base_data.texture.setRepeated(false);
  base_data.sounds.error.setBuffer(base_data.sound_buffers.error);
  for (unsigned index = 0; index < MAX_CLICKS_STROKES; ++index) {
    base_data.sounds.typing[index].setBuffer(base_data.sound_buffers.typing);
    base_data.sounds.click[index].setBuffer(base_data.sound_buffers.click);
  }
  base_data.files.themes_file.open("themes.txt");
  if (!base_data.files.themes_file.is_open()) {
    std::cerr << "The file responsable with the themes cannot be opened !";
    std::exit(1);
  }
  base_data.files.themes_file >> base_data.number_of_themes;

  for (unsigned index = 0; index < base_data.number_of_themes; ++index) {
    int red, green, blue;

    base_data.files.themes_file >> red;
    base_data.files.themes_file >> green;
    base_data.files.themes_file >> blue;
    base_data.themes[index].back = sf::Color(red, green, blue);

    base_data.files.themes_file >> red;
    base_data.files.themes_file >> green;
    base_data.files.themes_file >> blue;
    base_data.themes[index].hover = sf::Color(red, green, blue);

    base_data.files.themes_file >> red;
    base_data.files.themes_file >> green;
    base_data.files.themes_file >> blue;
    base_data.themes[index].muted = sf::Color(red, green, blue);

    base_data.files.themes_file >> red;
    base_data.files.themes_file >> green;
    base_data.files.themes_file >> blue;
    base_data.themes[index].text = sf::Color(red, green, blue);

    base_data.files.themes_file >> red;
    base_data.files.themes_file >> green;
    base_data.files.themes_file >> blue;
    base_data.themes[index].settings_clicked = sf::Color(red, green, blue);
  }
}

void drawStaticElements(BaseData &base_data,
                        sf::RenderWindow &window) {
  window.draw(base_data.sprites.spr_mode);
  window.draw(base_data.sprites.spr_music);
  window.draw(base_data.sprites.spr_sfx);
  window.draw(base_data.sprites.spr_settings);
  window.draw(base_data.sprites.spr_history);
  window.draw(base_data.sprites.spr_themes);

  if (base_data.switches.is_settings) {
    window.draw(base_data.settings_texts.label_song_volume);
    window.draw(base_data.sprites.spr_left_song_vol);
    window.draw(base_data.boxes.song_volume_visual);
    window.draw(base_data.boxes.song_volume);
    window.draw(base_data.settings_texts.song_volume);
    window.draw(base_data.sprites.spr_right_song_vol);

    window.draw(base_data.settings_texts.label_sfx_volume);
    window.draw(base_data.sprites.spr_left_sfx_vol);
    window.draw(base_data.boxes.sfx_volume_visual);
    window.draw(base_data.boxes.sfx_volume);
    window.draw(base_data.settings_texts.sfx_volume);
    window.draw(base_data.sprites.spr_right_sfx_vol);

    window.draw(base_data.settings_texts.label_song_name);
    window.draw(base_data.sprites.spr_left_song_name);
    window.draw(base_data.boxes.song_name);
    window.draw(base_data.settings_texts.song_name);
    window.draw(base_data.sprites.spr_right_song_name);

    window.draw(base_data.settings_texts.label_font_name);
    window.draw(base_data.sprites.spr_left_font_name);
    window.draw(base_data.boxes.font_name);
    window.draw(base_data.settings_texts.font_name);
    window.draw(base_data.sprites.spr_right_font_name);

    window.draw(base_data.settings_texts.label_font_size);
    window.draw(base_data.sprites.spr_left_font_size);
    window.draw(base_data.boxes.font_size_visual);
    window.draw(base_data.boxes.font_size);
    window.draw(base_data.settings_texts.font_size);
    window.draw(base_data.sprites.spr_right_font_size);
  } else {
    window.draw(base_data.input_form.back_box);
    window.draw(base_data.input_form.text);
    window.draw(base_data.output_line);

    if (base_data.switches.requestAnswer) {
      window.draw(base_data.output);
    }

    window.draw(base_data.sprites.spr_delete);
    window.draw(base_data.sprites.spr_equal);
    window.draw(base_data.sprites.spr_clear);
  }
  window.display();
}

void updateBoxesAndTextsOutlineColor(BaseData &base_data) {
  base_data.boxes.song_volume.setOutlineColor(base_data.colors.text);
  base_data.boxes.sfx_volume.setOutlineColor(base_data.colors.text);
  base_data.boxes.song_name.setOutlineColor(base_data.colors.text);
  base_data.boxes.font_name.setOutlineColor(base_data.colors.text);
  base_data.boxes.font_size.setOutlineColor(base_data.colors.text);

  base_data.settings_texts.song_volume.setFillColor(base_data.colors.text);
  base_data.settings_texts.sfx_volume.setFillColor(base_data.colors.text);
  base_data.settings_texts.song_name.setFillColor(base_data.colors.text);
  base_data.settings_texts.font_name.setFillColor(base_data.colors.text);
  base_data.settings_texts.font_size.setFillColor(base_data.colors.text);

  base_data.settings_texts.font_size.setOutlineColor(base_data.colors.back);
  base_data.settings_texts.song_volume.setOutlineColor(base_data.colors.back);
  base_data.settings_texts.sfx_volume.setOutlineColor(base_data.colors.back);

  base_data.settings_texts.label_song_volume.setFillColor(base_data.colors.text);
  base_data.settings_texts.label_sfx_volume.setFillColor(base_data.colors.text);
  base_data.settings_texts.label_song_name.setFillColor(base_data.colors.text);
  base_data.settings_texts.label_settings.setFillColor(base_data.colors.text);
  base_data.settings_texts.label_font_name.setFillColor(base_data.colors.text);
  base_data.settings_texts.label_font_size.setFillColor(base_data.colors.text);
}
bool contains(sf::FloatRect area, sf::Vector2i point) {
  return (point.x >= area.left && point.x <= area.left + area.width
      && point.y >= area.top && point.y <= area.top + area.height);
}
void convertIToC(int number, char *str) {
  char str_temp[4];
  int dimension = 0;
  do {
    str_temp[dimension++] = char(48 + number%10);
    number /= 10;
  } while (number!=0);
  str_temp[dimension] = '\0';
  for (size_t i = 0; str_temp[i]; ++i) {
    str[strlen(str_temp) - 1 - i] = str_temp[i];
  }
  str[strlen(str_temp)] = '\0';
}
void playClick(Sounds &sounds) {
  for (int index = 0; index < MAX_CLICKS_STROKES; ++index) {
    if (sounds.click[index].getStatus()==sf::SoundSource::Stopped) {
      sounds.click[index].play();
      return;
    }
  }
}
void playTyping(Sounds &sounds) {
  for (int index = 0; index < MAX_CLICKS_STROKES; ++index) {
    if (sounds.typing[index].getStatus()==sf::SoundSource::Stopped) {
      sounds.typing[index].play();
      return;
    }
  }
}

void setBoxesDetails(BaseData &base_data) {
  base_data.boxes.song_volume.setFillColor(sf::Color::Transparent);
  base_data.boxes.song_volume_visual.setFillColor(base_data.colors.text);
  base_data.boxes.sfx_volume.setFillColor(sf::Color::Transparent);
  base_data.boxes.sfx_volume_visual.setFillColor(base_data.colors.text);
  base_data.boxes.song_name.setFillColor(sf::Color::Transparent);
  base_data.boxes.font_name.setFillColor(sf::Color::Transparent);
  base_data.boxes.font_size.setFillColor(sf::Color::Transparent);
  base_data.boxes.font_size_visual.setFillColor(base_data.colors.text);

  base_data.boxes.song_volume.setOutlineThickness(THICKNESS);
  base_data.boxes.song_volume_visual.setOutlineThickness(0);
  base_data.boxes.sfx_volume.setOutlineThickness(THICKNESS);
  base_data.boxes.sfx_volume_visual.setOutlineThickness(0);
  base_data.boxes.song_name.setOutlineThickness(THICKNESS);
  base_data.boxes.font_name.setOutlineThickness(THICKNESS);
  base_data.boxes.font_size.setOutlineThickness(THICKNESS);
  base_data.boxes.font_size_visual.setOutlineThickness(0);

  sf::Vector2f general_size = sf::Vector2f(5*IMG_SCALED, IMG_SCALED - 2*THICKNESS);
  base_data.boxes.song_volume.setSize(general_size);
  base_data.boxes.song_volume_visual.setSize(general_size);
  base_data.boxes.sfx_volume.setSize(general_size);
  base_data.boxes.sfx_volume_visual.setSize(general_size);
  base_data.boxes.song_name.setSize(general_size);
  base_data.boxes.font_name.setSize(general_size);
  base_data.boxes.font_size.setSize(general_size);
  setFontSlideDim(base_data);
  float vertical_pos = (HEIGHT - 10*IMG_SCALED - 5*VERTICAL_PADDING)/2.f;
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);
  base_data.boxes.song_volume.setPosition((WIDTH - general_size.x)/2, vertical_pos);
  base_data.boxes.song_volume_visual.setPosition((WIDTH - general_size.x)/2, vertical_pos);
  vertical_pos += 2*(IMG_SCALED + VERTICAL_PADDING);
  base_data.boxes.sfx_volume.setPosition((WIDTH - general_size.x)/2, vertical_pos);
  base_data.boxes.sfx_volume_visual.setPosition((WIDTH - general_size.x)/2, vertical_pos);
  vertical_pos += 2*(IMG_SCALED + VERTICAL_PADDING);
  base_data.boxes.song_name.setPosition((WIDTH - general_size.x)/2, vertical_pos);
  vertical_pos += 2*(IMG_SCALED + VERTICAL_PADDING);
  base_data.boxes.font_name.setPosition((WIDTH - general_size.x)/2, vertical_pos);
  vertical_pos += 2*(IMG_SCALED + VERTICAL_PADDING);
  base_data.boxes.font_size.setPosition((WIDTH - general_size.x)/2, vertical_pos);
  base_data.boxes.font_size_visual.setPosition((WIDTH - general_size.x)/2, vertical_pos);
}
void resetOutput(BaseData &base_data) {
  base_data.output_string.clear();
  base_data.output.setString(base_data.output_string);
  ///

}
void setTheme(BaseData &base_data) {
  base_data.colors.hover = base_data.themes[base_data.theme_index].hover;
  base_data.colors.muted = base_data.themes[base_data.theme_index].muted;
  base_data.colors.default_text_color = base_data.themes[base_data.theme_index].text;
  base_data.colors.default_background_color = base_data.themes[base_data.theme_index].back;
  base_data.colors.settings_clicked = base_data.themes[base_data.theme_index].settings_clicked;
  base_data.colors.text = base_data.themes[base_data.theme_index].text;
  base_data.colors.back = base_data.themes[base_data.theme_index].back;

}
void setupAliases(BaseData &base_data, std::ifstream &fin) {
  fin >> base_data.dimension;
  char word[MAX_KEY_DIM];
  int value;
  for (int i = 0; i < base_data.dimension; ++i) {
    fin >> word;
    fin >> value;
    std::string s(word);
    base_data.aliases[i].letters = s;
    base_data.aliases[i].digits = value;
  }
  fin.close();
}

void setFontSlideDim(BaseData &base_data) {
  double step_slide = 5*IMG_SCALED/7.f;
  base_data.boxes.font_size_visual.setSize(sf::Vector2f(step_slide*(base_data.font_size - MIN_DIM_FONT),
                                                        IMG_SCALED - 2*THICKNESS));
}
void setSongVolumeSlideDim(BaseData &base_data) {
  double step_slide = 5*IMG_SCALED/100.f;
  base_data.boxes.song_volume_visual.setSize(sf::Vector2f(step_slide*(base_data.volumes.music_settings),
                                                          IMG_SCALED - 2*THICKNESS));
}
void setSFXVolumeSlideDim(BaseData &base_data) {
  double step_slide = 5*IMG_SCALED/100.f;
  base_data.boxes.sfx_volume_visual.setSize(sf::Vector2f(step_slide*(base_data.volumes.sfx_settings),
                                                         IMG_SCALED - 2*THICKNESS));
}