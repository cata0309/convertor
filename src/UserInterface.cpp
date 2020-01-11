#include "UserInterface.hpp"
#include<sstream>
#include<cstring>
void requestOutput(BaseData &base_data) {
  bool success = true;
  double result = 0;
  std::string intermediate = base_data.input_form.input.toAnsiString();
  std::ostringstream temp;
  std::string old_text;
  std::ifstream history_in("history.txt");
  if (!history_in.eof())
    while (std::getline(history_in, old_text))
      temp << old_text << "\n";
  history_in.close();
  std::ofstream history_out("history.txt", std::ios::out | std::ios::trunc);
  history_out << base_data.input_form.input.toAnsiString() << "\n";
  int dimension_first_dic = base_data.dimension - base_data.dimension_second_dic;
  if (intermediate.length()==0) {
    success = false;
  } else {
    char *input = new char[intermediate.length() + 1];
    strcpy(input, intermediate.c_str());
    if (base_data.switches.english_language) {
      for (int i = 0; i < dimension_first_dic; ++i) {
        std::cout << base_data.aliases[i].letters << ":" << base_data.aliases[i].digits << "\n";
      }
      processEnInput(input, success, result, base_data.aliases, dimension_first_dic);
    } else {
      for (int i = dimension_first_dic; i < base_data.dimension; ++i) {
        std::cout << base_data.aliases[i].letters << ":" << base_data.aliases[i].digits << "\n";
      }
      processRoInput(input, success, result, (base_data.aliases + dimension_first_dic), base_data.dimension_second_dic);
    }
    delete[]input;
  }

  if (success) {
//    std::ostringstream strs;
//    strs << result;
    std::cout << "result:" << result << "\n";
    base_data.output_string = /*strs.str();*/std::to_string(result);
  } else {
    base_data.output_string = "WRONG INPUT !";
  }
  base_data.output.setString(base_data.output_string);
  base_data.output.setPosition(int(WIDTH - 4*IMG_SCALED - 5*THICKNESS - base_data.output.getLocalBounds().width)/2,
                               4*IMG_SCALED - base_data.font_size - THICKNESS);

  history_out << base_data.output_string.toAnsiString() << "\n";
  history_out << temp.str();
  history_out.close();

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
  base_data.sprites.spr_clear_history.setTexture(base_data.texture);
  base_data.sprites.spr_language.setTexture(base_data.texture);
  base_data.sprites.spr_history.setTexture(base_data.texture);
  base_data.sprites.spr_themes.setTexture(base_data.texture);

  //positions

//  base_data.cross_background.setFillColor(sf::Color::Red);
  base_data.sprites.spr_settings.setPosition(WIDTH - (PADDING + IMG_SCALED), PADDING);
  base_data.sprites.spr_music.setPosition(WIDTH - 2*(PADDING + IMG_SCALED), PADDING);
  base_data.sprites.spr_sfx.setPosition(WIDTH - 3*(PADDING + IMG_SCALED), PADDING);
  base_data.sprites.spr_mode.setPosition(WIDTH - 4*(PADDING + IMG_SCALED), PADDING);
  base_data.sprites.spr_history.setPosition(WIDTH - 5*(PADDING + IMG_SCALED), PADDING);
  base_data.sprites.spr_themes.setPosition(WIDTH - 6*(PADDING + IMG_SCALED), PADDING);

  base_data.sprites.spr_equal.setPosition(WIDTH - (PADDING + IMG_SCALED), 2*IMG_SCALED + THICKNESS + 2);
  base_data.sprites.spr_delete.setPosition(WIDTH - 2*(PADDING + IMG_SCALED), 2*IMG_SCALED + THICKNESS + 2);
  base_data.sprites.spr_clear.setPosition(WIDTH - 3*(PADDING + IMG_SCALED), 2*IMG_SCALED + THICKNESS + 2);

  base_data.sprites.spr_language.setPosition(WIDTH - 7*(PADDING + IMG_SCALED), PADDING);
  base_data.sprites.spr_clear_history.setPosition(WIDTH - 8*(PADDING + IMG_SCALED), PADDING);
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
  base_data.sprites.spr_clear_history.setTextureRect(sf::IntRect(0, 768, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_history.setTextureRect(sf::IntRect(0, 864, IMG_REAL, IMG_REAL));
  base_data.sprites.spr_themes.setTextureRect(sf::IntRect(0, 960, IMG_REAL, IMG_REAL));
  switchLanguageSprite(base_data);
//scaling
  base_data.sprites.spr_language.scale(sf::Vector2f(X_TIMES, X_TIMES));
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
  base_data.sprites.spr_clear_history.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_history.scale(sf::Vector2f(X_TIMES, X_TIMES));
  base_data.sprites.spr_themes.scale(sf::Vector2f(X_TIMES, X_TIMES));
}
void setLabelsTextsPositions(BaseData &base_data) {
  int vertical_pos = (HEIGHT - 10*IMG_SCALED - 5*VERTICAL_PADDING)/2.f + 4;
  base_data.settings_texts.label_song_volume.setPosition(
      int(WIDTH - base_data.settings_texts.label_song_volume.getLocalBounds().width)/2,
      vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);
  base_data.settings_texts.song_volume.setPosition(
      int(WIDTH - base_data.settings_texts.song_volume.getLocalBounds().width)/2, vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);

  base_data.settings_texts.label_sfx_volume.setPosition(
      int(WIDTH - base_data.settings_texts.label_sfx_volume.getLocalBounds().width)/2,
      vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);
  base_data.settings_texts.sfx_volume.setPosition(
      int(WIDTH - base_data.settings_texts.sfx_volume.getLocalBounds().width)/2, vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);

  base_data.settings_texts.label_song_name.setPosition(
      int(WIDTH - base_data.settings_texts.label_song_name.getGlobalBounds().width)/2,
      vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);
  base_data.settings_texts.song_name.setPosition(
      int(WIDTH - base_data.settings_texts.song_name.getLocalBounds().width)/2,
      vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);

  base_data.settings_texts.label_font_name.setPosition(
      int(WIDTH - base_data.settings_texts.label_font_name.getGlobalBounds().width)/2,
      vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);
  base_data.settings_texts.font_name.setPosition(
      int(WIDTH - base_data.settings_texts.font_name.getLocalBounds().width)/2,
      vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);

  base_data.settings_texts.label_font_size.setPosition(
      int(WIDTH - base_data.settings_texts.label_font_size.getGlobalBounds().width)/2,
      vertical_pos);
  vertical_pos += (IMG_SCALED + VERTICAL_PADDING);
  base_data.settings_texts.font_size.setPosition(
      int(WIDTH - base_data.settings_texts.font_size.getLocalBounds().width)/2,
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
  requestHistory(base_data);
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
  base_data.settings_texts.label_settings.setPosition(POS_HIST_BOX_X, POS_HIST_BOX_Y);

  base_data.history.setPosition(POS_HIST_BOX_X, POS_HIST_BOX_Y + 2*PADDING);
  base_data.history.setString(base_data.history_string);

  base_data.output_line.setSize(sf::Vector2f((WIDTH - 5*IMG_SCALED - 5*THICKNESS), 2));
  base_data.output_line.setOutlineThickness(0);
  base_data.output_line.setPosition(IMG_SCALED, 4.25*IMG_SCALED + THICKNESS);

  updateSettingsView(base_data);
  changeMode(base_data);

  sf::Vector2f position = sf::Vector2f(IMG_SCALED, 2*IMG_SCALED + 3*THICKNESS);
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
  base_data.sprites.spr_clear_history.setColor(base_data.colors.text);
  base_data.sprites.spr_language.setColor(base_data.colors.text);
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

  if (base_data.switches.theme_pressed || base_data.initial_setup)
    base_data.sprites.spr_mode.setColor(base_data.colors.text);
  if (!base_data.switches.is_history)
    base_data.sprites.spr_history.setColor(base_data.colors.text);
  else
    base_data.sprites.spr_history.setColor(base_data.colors.button_clicked);

  if (base_data.switches.is_sfx)
    base_data.sprites.spr_sfx.setColor(base_data.colors.text);
  else
    base_data.sprites.spr_sfx.setColor(base_data.colors.muted);
  if (!base_data.switches.is_settings)
    base_data.sprites.spr_settings.setColor(base_data.colors.text);
  else
    base_data.sprites.spr_settings.setColor(base_data.colors.button_clicked);

  updateBoxesAndTextsOutlineColor(base_data);

}

void handleEvents(sf::RenderWindow &window, sf::Event &event, BaseData &base_data) {

  while (window.pollEvent(event)) {
    sf::Vector2i mouse = sf::Mouse::getPosition(window);
    if (event.type==sf::Event::Closed) {
      window.close();
    }
    if (event.type==sf::Event::KeyPressed) {
      // Using Ctrl + V to paste a string into SFML
      if (event.key.control && event.key.code==sf::Keyboard::V) {
        sf::String strclip = sf::Clipboard::getString();
        //TODO REMOVE NEW LINE CHARACTER
//        for(int i=0;i<strclip.getSize();++i)
//          if(int(strclip[i])==13)
//          {strclip.erase(i-1,1);
//            i--;
//          }

        base_data.input_form.input.insert(base_data.input_form.input.getSize(), strclip);
        for (int i = 0; i < base_data.input_form.input.getSize(); i++) {
          base_data.input_form.ruler++;
          if (base_data.input_form.ruler==base_data.input_form.max_chars_view)
            base_data.input_form.start_index++, base_data.input_form.ruler--;
        }
      }
    }

    if (base_data.switches.is_input) {
      if (event.type==sf::Event::KeyPressed && base_data.input_form.focus) {

        switch (event.key.code) {
          case sf::Keyboard::Right:playTyping(base_data.sounds);
            if (base_data.input_form.insert_position < 0) {
              base_data.input_form.insert_position++;
              base_data.input_form.ruler++;

              if (base_data.input_form.ruler==base_data.input_form.max_chars_view)
                base_data.input_form.start_index++, base_data.input_form.ruler--;

            }
            break;
          case sf::Keyboard::Left:playTyping(base_data.sounds);
            if (-base_data.input_form.insert_position < base_data.input_form.input.getSize()) {
              base_data.input_form.ruler--;
              base_data.input_form.insert_position--;

              if (base_data.input_form.ruler==-1 && base_data.input_form.start_index > 0)
                base_data.input_form.start_index--, base_data.input_form.ruler++;

            }

            break;
          default:break;
        }
      }
      if (event.type==sf::Event::TextEntered && base_data.input_form.focus) {
        char c = static_cast<char>(event.text.unicode);
        playTyping(base_data.sounds);
        //clears output area
        if (int(c==13)) {
          base_data.switches.requestAnswer = true;
          base_data.switches.made_change = true;
          requestOutput(base_data);
        } else {
          base_data.switches.requestAnswer = false;
          resetOutput(base_data);
          handleKeyEvent(base_data.input_form, c);
        }
      }

      if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || event.type==sf::Event::MouseButtonReleased) {
//////////////////////////////////////// Music volume box interaction ////////////////////////////////////////
        bool previous_focus = base_data.input_form.focus;
        base_data.input_form.focus = mouse.x >= base_data.input_form.back_box.getPosition().x &&
            mouse.x <= base_data.input_form.back_box.getPosition().x + base_data.input_form.back_box.getSize().x &&
            mouse.y >= base_data.input_form.back_box.getPosition().y &&
            mouse.y <= base_data.input_form.back_box.getPosition().y + base_data.input_form.back_box.getSize().y;

        if (!previous_focus && base_data.input_form.focus) {
          playClick(base_data.sounds);
        }

      }

    }

    if (base_data.switches.is_history) {
      if (contains(base_data.boxes.scroll_rect.getGlobalBounds(), mouse)) {
        base_data.boxes.scroll_rect.setFillColor(base_data.colors.hover);
        base_data.switches.is_scroll_hovered = true;
        if (event.type==sf::Event::MouseButtonPressed) {
          base_data.line_height = base_data.history.getLocalBounds().height/base_data.nr_lines;
          base_data.scroll_line_height = (double) (base_data.limit_bottom - base_data.limit_top)
              /(base_data.nr_lines + 1 - (HEIGHT - base_data.boxes.mask_box.getSize().y)/base_data.line_height);

          base_data.switches.in_the_scroll_button = true;
          playClick(base_data.sounds);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
          if (base_data.distance_from_mouse==-1) {
            base_data.distance_from_mouse = mouse.y - base_data.boxes.scroll_rect.getGlobalBounds().top;
          }
          base_data.boxes.scroll_rect.setFillColor(base_data.colors.button_clicked);
        }
        if (event.type==sf::Event::MouseButtonReleased) {
          base_data.switches.in_the_scroll_button = false;
          base_data.distance_from_mouse = -1;
        }
      } else {
        base_data.switches.is_scroll_hovered = false;
        if (!base_data.switches.in_the_scroll_button)
          base_data.distance_from_mouse = -1;
      }
      if (event.type==sf::Event::MouseButtonReleased && base_data.switches.in_the_scroll_button) {
        base_data.switches.in_the_scroll_button = false;
        base_data.distance_from_mouse = -1;
      }
      if (base_data.switches.in_the_scroll_button) {
        if (base_data.history.getLocalBounds().height + base_data.history.getPosition().y > HEIGHT) {
          int lines = (base_data.boxes.scroll_rect.getPosition().y >= base_data.limit_top ? (
              base_data.boxes.scroll_rect.getPosition().y - base_data.limit_top) : 0)/base_data.line_height;

          base_data.history.setPosition(base_data.history.getPosition().x,
                                        POS_HIST_BOX_Y
                                            - lines*SCROLL_LINES*base_data.line_height);
          int positionY = base_data.limit_top
              + ((mouse.y >= base_data.limit_top ? (mouse.y - base_data.limit_top) : 0)/base_data.scroll_line_height)
                  *base_data.scroll_line_height
              + base_data.distance_from_mouse;
          std::cout << "positionY: " << positionY << " mouseY: " << mouse.y << "\n";
          base_data.boxes.scroll_rect.setFillColor(base_data.colors.button_clicked);
//          if (positionY - base_data.distance_from_mouse >= base_data.limit_top
//              && positionY - base_data.distance_from_mouse <=)
          base_data.boxes.scroll_rect.setPosition(base_data.boxes.scroll_rect.getPosition().x,
                                                  positionY - base_data.distance_from_mouse);
        }
      } else {
        if (!base_data.switches.is_scroll_hovered)
          base_data.boxes.scroll_rect.setFillColor(base_data.colors.text);
      }

      if (event.type==sf::Event::KeyPressed) {
        if (base_data.history.getLocalBounds().height > HEIGHT) {
          if (base_data.nr_lines!=0) {
            base_data.line_height = base_data.history.getLocalBounds().height/base_data.nr_lines;
            base_data.scroll_line_height = (double) (base_data.limit_bottom - base_data.limit_top)
                /(base_data.nr_lines - (HEIGHT - base_data.boxes.mask_box.getSize().y)/base_data.line_height);
            std::cout << "nr_lines:" << base_data.nr_lines << " line_height:" << base_data.line_height << " top:"
                      << base_data.limit_top << " bottom:" << base_data.limit_bottom << " scroll line height:"
                      << base_data.scroll_line_height << "\n";
          }
          switch (event.key.code) {

            case sf::Keyboard::Down:
              if (base_data.history.getLocalBounds().height + base_data.history.getPosition().y > HEIGHT) {
                playTyping(base_data.sounds);
                base_data.history.setPosition(base_data.history.getPosition().x,
                                              base_data.history.getPosition().y - SCROLL_LINES*base_data.line_height);
                base_data.boxes.scroll_rect.setPosition(base_data.boxes.scroll_rect.getPosition().x,
                                                        base_data.boxes.scroll_rect.getPosition().y
                                                            + SCROLL_LINES*base_data.scroll_line_height);
                std::cout << "posy:" << base_data.boxes.scroll_rect.getPosition().y << "\n";
              }
              break;
            case sf::Keyboard::Up:
              if (base_data.history.getPosition().y!=POS_HIST_BOX_Y + 2*PADDING) {
                playTyping(base_data.sounds);
                base_data.history.setPosition(base_data.history.getPosition().x,
                                              base_data.history.getPosition().y + SCROLL_LINES*base_data.line_height);
                base_data.boxes.scroll_rect.setPosition(base_data.boxes.scroll_rect.getPosition().x,
                                                        base_data.boxes.scroll_rect.getPosition().y
                                                            - SCROLL_LINES*base_data.scroll_line_height);

              }
              break;
            default:break;
          }
        }
      }
      ////////////////////////////////////////   ////////////////////////////////////////

      if (contains(base_data.sprites.spr_clear_history.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_clear_history.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          clearHistory(base_data);
          base_data.line_height = 0;
          base_data.scroll_line_height = 0;
          base_data.boxes.scroll_rect.setPosition(base_data.boxes.scroll_rect.getPosition().x, base_data.limit_top);
        }
      } else {
        base_data.sprites.spr_clear_history.setColor(base_data.colors.text);
      }

    }


//////////////////////////////////////// Settings button interaction ////////////////////////////////////////


    if (contains(base_data.sprites.spr_settings.getGlobalBounds(), mouse)) {
      base_data.sprites.spr_settings.setColor(base_data.colors.hover);
      if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
        playClick(base_data.sounds);

        base_data.switches.is_settings = !base_data.switches.is_settings;
        if (!base_data.switches.is_settings) {

          base_data.switches.is_input = true;

        } else {
          base_data.switches.is_input = false;
          if (base_data.switches.is_history) {
            base_data.switches.is_history = false;
            base_data.sprites.spr_history.setColor(base_data.colors.text);

          }
        }
      }
    } else {
      if (!base_data.switches.is_settings)
        base_data.sprites.spr_settings.setColor(base_data.colors.text);
      else
        base_data.sprites.spr_settings.setColor(base_data.colors.button_clicked);

    }

    if (contains(base_data.sprites.spr_language.getGlobalBounds(), mouse)) {
      base_data.sprites.spr_language.setColor(base_data.colors.hover);
      if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
        playClick(base_data.sounds);
        base_data.switches.english_language = !base_data.switches.english_language;
        if (base_data.switches.english_language) {
          std::cout << "SWITCHED TO ENGLISH\n";
        } else {
          std::cout << "SWITCHED TO ROMANIAN\n";
        }

        switchLanguageSprite(base_data);
        resetInputForm(base_data.input_form, MAX_CHARS_VIEW);
        resetOutput(base_data);
      }
    } else {
      base_data.sprites.spr_language.setColor(base_data.colors.text);
    }
    //////////////////////////////////////// Settings button interaction ////////////////////////////////////////

    if (contains(base_data.sprites.spr_history.getGlobalBounds(), mouse)) {
      base_data.sprites.spr_history.setColor(base_data.colors.hover);
      if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
        playClick(base_data.sounds);
        base_data.switches.is_history = !base_data.switches.is_history;
        if (!base_data.switches.is_history) {
          base_data.switches.is_input = true;

        } else {
          if (base_data.switches.made_change) {
            requestHistory(base_data);
            base_data.switches.made_change = false;
          }
          base_data.switches.is_input = false;
          if (base_data.switches.is_settings) {
            base_data.switches.is_settings = false;
            base_data.sprites.spr_settings.setColor(base_data.colors.text);
          }

        }
      }
    } else {
      if (!base_data.switches.is_history)
        base_data.sprites.spr_history.setColor(base_data.colors.text);
      else
        base_data.sprites.spr_history.setColor(base_data.colors.button_clicked);
    }

    //////////////////////////////////////// Music button interaction ////////////////////////////////////////

    if (contains(base_data.sprites.spr_music.getGlobalBounds(), mouse)) {
      base_data.sprites.spr_music.setColor(base_data.colors.hover);
      if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
        base_data.switches.is_music = !base_data.switches.is_music;
        setSongVolume(base_data);
        playClick(base_data.sounds);
        updateSettingsView(base_data);
      }
    } else {
      if (base_data.switches.is_music)
        base_data.sprites.spr_music.setColor(base_data.colors.text);
      else
        base_data.sprites.spr_music.setColor(base_data.colors.muted);

    }

    //////////////////////////////////////// SFX volume button interaction ////////////////////////////////////////

    if (contains(base_data.sprites.spr_sfx.getGlobalBounds(), mouse)) {
      base_data.sprites.spr_sfx.setColor(base_data.colors.hover);
      if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed
          && event.type==sf::Event::MouseButtonPressed) {
        base_data.switches.is_sfx = !base_data.switches.is_sfx;

        setSFXVolume(base_data);
        playClick(base_data.sounds);
        updateSettingsView(base_data);
      }
    } else {
      if (base_data.switches.is_sfx)
        base_data.sprites.spr_sfx.setColor(base_data.colors.text);
      else
        base_data.sprites.spr_sfx.setColor(base_data.colors.muted);

    }

//////////////////////////////////////// Mode button interaction ////////////////////////////////////////



    if (contains(base_data.sprites.spr_mode.getGlobalBounds(), mouse)) {
      base_data.sprites.spr_mode.setColor(base_data.colors.hover);
      if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
        base_data.switches.is_dark_mode = !base_data.switches.is_dark_mode;
        playClick(base_data.sounds);
        changeMode(base_data);
      }
    } else {
      base_data.sprites.spr_mode.setColor(base_data.colors.text);
    }

    //////////////////////////////////////// Theme button interaction ////////////////////////////////////////

    if (contains(base_data.sprites.spr_themes.getGlobalBounds(), mouse)) {
      base_data.sprites.spr_themes.setColor(base_data.colors.hover);
      if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
        base_data.theme_index++;
        if (base_data.theme_index==base_data.number_of_themes)
          base_data.theme_index = 0;
        setTheme(base_data);
        playClick(base_data.sounds);
        base_data.switches.theme_pressed = true;
        changeMode(base_data);
        base_data.switches.theme_pressed = false;

      }
    } else {
      base_data.sprites.spr_themes.setColor(base_data.colors.text);
    }

    if (base_data.switches.is_settings) {

      if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || event.type==sf::Event::MouseButtonReleased) {
//////////////////////////////////////// Music volume box interaction ////////////////////////////////////////
        if (contains(base_data.boxes.song_volume.getGlobalBounds(), mouse)) {
          if (event.type==sf::Event::MouseButtonPressed) {
            base_data.switches.in_the_slide_song_vol = true;
            playClick(base_data.sounds);
          }

          if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && base_data.switches.in_the_slide_song_vol) {
            float step = (base_data.boxes.song_volume.getGlobalBounds().width)/(102.f);
            int volume_test = int((mouse.x - base_data.boxes.song_volume.getPosition().x)/step);
            if (volume_test >= 0 && volume_test <= 100) {
              if (!base_data.switches.is_music) {
                base_data.switches.is_music = true;
              }
              base_data.volumes.music = volume_test;
              setSongVolume(base_data);

            }
          }
          if (event.type==sf::Event::MouseButtonReleased) {
            base_data.switches.in_the_slide_song_vol = false;
          }
        }
//        else {
//          base_data.switches.in_the_slide_song_vol = false;
//        }
        //////////////////////////////////////// SFX volume box interaction ////////////////////////////////////////

        if (contains(base_data.boxes.sfx_volume.getGlobalBounds(), mouse)) {
          if (event.type==sf::Event::MouseButtonPressed) {
            base_data.switches.in_the_slide_sfx_vol = true;
            playClick(base_data.sounds);
          }

          if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && base_data.switches.in_the_slide_sfx_vol) {
            float step = (base_data.boxes.sfx_volume.getGlobalBounds().width)/(102.f);
            int volume_test = int((mouse.x - base_data.boxes.sfx_volume.getPosition().x)/step);
            if (volume_test >= 0 && volume_test <= 100) {
              if (!base_data.switches.is_sfx) {
                base_data.switches.is_sfx = true;
              }
              base_data.volumes.sfx = volume_test;
              setSFXVolume(base_data);
            }
          }
          if (event.type==sf::Event::MouseButtonReleased) {
            base_data.switches.in_the_slide_sfx_vol = false;
          }
        }
//        else {
//          base_data.switches.in_the_slide_sfx_vol = false;
//        }
        //////////////////////////////////////// Font size box interaction ////////////////////////////////////////

        if (contains(base_data.boxes.font_size.getGlobalBounds(), mouse)) {
          if (event.type==sf::Event::MouseButtonPressed) {
            base_data.switches.in_the_slide_font = true;
            playClick(base_data.sounds);
          }
          if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && base_data.switches.in_the_slide_font) {

            float step = (base_data.boxes.font_size.getGlobalBounds().width)/(8.f);
            int font_size_test = int((mouse.x - base_data.boxes.font_size.getPosition().x)/step) + 20;
            if (font_size_test >= MIN_DIM_FONT && font_size_test <= MAX_DIM_FONT) {
              base_data.font_size = font_size_test;

              setTextFontSize(base_data);
            }
          }
          if (event.type==sf::Event::MouseButtonReleased) {
            base_data.switches.in_the_slide_font = false;
          }
        }
//        else {
//          base_data.switches.in_the_slide_font = false;
//        }
      }



      //////////////////////////////////////// Left volume music button interaction /////////////////////////////////////

      if (contains(base_data.sprites.spr_left_song_vol.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_left_song_vol.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateSongVolume(base_data, true);
        }
      } else {
        base_data.sprites.spr_left_song_vol.setColor(base_data.colors.text);
      }

      //////////////////////////////////////// Right volume music button interaction ////////////////////////////////////////


      if (contains(base_data.sprites.spr_right_song_vol.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_right_song_vol.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateSongVolume(base_data, false);
        }
      } else {
        base_data.sprites.spr_right_song_vol.setColor(base_data.colors.text);
      }

      //////////////////////////////////////// Left volume SFX button interaction ////////////////////////////////////////


      if (contains(base_data.sprites.spr_left_sfx_vol.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_left_sfx_vol.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateSFXVolume(base_data, true);
        }
      } else {
        base_data.sprites.spr_left_sfx_vol.setColor(base_data.colors.text);
      }

      //////////////////////////////////////// Right volume SFX button interaction ////////////////////////////////////////

      if (contains(base_data.sprites.spr_right_sfx_vol.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_right_sfx_vol.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateSFXVolume(base_data, false);
        }
      } else {
        base_data.sprites.spr_right_sfx_vol.setColor(base_data.colors.text);
      }
//////////////////////////////////////// Left song name button interaction ////////////////////////////////////////


      if (contains(base_data.sprites.spr_left_song_name.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_left_song_name.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateSongName(base_data, true);
        }
      } else {
        base_data.sprites.spr_left_song_name.setColor(base_data.colors.text);
      }

//////////////////////////////////////// Right song name button interaction ////////////////////////////////////////

      if (contains(base_data.sprites.spr_right_song_name.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_right_song_name.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateSongName(base_data, false);
        }
      } else {
        base_data.sprites.spr_right_song_name.setColor(base_data.colors.text);
      }

//////////////////////////////////////// Left font name button interaction ////////////////////////////////////////


      if (contains(base_data.sprites.spr_left_font_name.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_left_font_name.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateTextFont(base_data, true);
        }
      } else {
        base_data.sprites.spr_left_font_name.setColor(base_data.colors.text);
      }

//////////////////////////////////////// Right font name button interaction ////////////////////////////////////////

      if (contains(base_data.sprites.spr_right_font_name.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_right_font_name.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateTextFont(base_data, false);
        }
      } else {
        base_data.sprites.spr_right_font_name.setColor(base_data.colors.text);
      }


//////////////////////////////////////// Left font size button interaction ////////////////////////////////////////


      if (contains(base_data.sprites.spr_left_font_size.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_left_font_size.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateTextFontSize(base_data, true);
        }
      } else {
        base_data.sprites.spr_left_font_size.setColor(base_data.colors.text);
      }

//////////////////////////////////////// Right font size button interaction ////////////////////////////////////////

      if (contains(base_data.sprites.spr_right_font_size.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_right_font_size.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          navigateTextFontSize(base_data, false);
        }
      } else {
        base_data.sprites.spr_right_font_size.setColor(base_data.colors.text);
      }

    }
    if (base_data.switches.is_input) {
//////////////////////////////////////// Equal button interaction ////////////////////////////////////////


      if (contains(base_data.sprites.spr_equal.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_equal.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          base_data.switches.requestAnswer = true;
          base_data.input_form.focus = true;
          base_data.switches.made_change = true;
          requestOutput(base_data);
        }
      } else {
        base_data.sprites.spr_equal.setColor(base_data.colors.text);
      }
//////////////////////////////////////// Delete button interaction ////////////////////////////////////////

      if (contains(base_data.sprites.spr_delete.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_delete.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);

        }
      } else {
        base_data.sprites.spr_delete.setColor(base_data.colors.text);
      }
////////////////////////////////////////   ////////////////////////////////////////


      if (contains(base_data.sprites.spr_clear.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_clear.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          resetInputForm(base_data.input_form, MAX_CHARS_VIEW);
          resetOutput(base_data);
        }
      } else {
        base_data.sprites.spr_clear.setColor(base_data.colors.text);
      }

////////////////////////////////////////   ////////////////////////////////////////

      if (contains(base_data.sprites.spr_delete.getGlobalBounds(), mouse)) {
        base_data.sprites.spr_delete.setColor(base_data.colors.hover);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && event.type==sf::Event::MouseButtonPressed) {
          playClick(base_data.sounds);
          deleteKey(base_data.input_form);
          resetOutput(base_data);
          base_data.input_form.focus = true;
        }
      } else {
        base_data.sprites.spr_delete.setColor(base_data.colors.text);
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
  base_data.song_list[base_data.song_index].song.setVolume(base_data.volumes.music_settings);
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

  base_data.history.setFont(base_data.font_list[base_data.font_index].font);
  base_data.input_form.text.setFont(base_data.font_list[base_data.font_index].font);
  base_data.output.setFont(base_data.font_list[base_data.font_index].font);
  if (!base_data.initial_setup) {
    updateSettingsView(base_data);
    base_data.output.setPosition(int(WIDTH - 4*IMG_SCALED - 5*THICKNESS - base_data.output.getLocalBounds().width)/2,
                                 4*IMG_SCALED - base_data.font_size - THICKNESS);
  }
  if (base_data.nr_lines!=0)
    base_data.line_height = base_data.history.getLocalBounds().height/base_data.nr_lines;

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
  base_data.settings_texts.label_settings.setCharacterSize(base_data.font_size + 5);
  base_data.settings_texts.label_font_name.setCharacterSize(base_data.font_size);
  base_data.settings_texts.label_font_size.setCharacterSize(base_data.font_size);

  base_data.history.setCharacterSize(base_data.font_size);

  base_data.input_form.text.setCharacterSize(base_data.font_size);
  base_data.output.setCharacterSize(base_data.font_size);
  if (!base_data.initial_setup) {
    updateSettingsView(base_data);
    base_data.output.setPosition(int(WIDTH - 4*IMG_SCALED - 5*THICKNESS - base_data.output.getLocalBounds().width)/2,
                                 4*IMG_SCALED - base_data.font_size - THICKNESS);
  }
  if (base_data.nr_lines!=0)
    base_data.line_height = base_data.history.getLocalBounds().height/base_data.nr_lines;

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
  base_data.files.fonts_in.close();
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
  base_data.files.songs_in.close();
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
    base_data.themes[index].button_clicked = sf::Color(red, green, blue);

  }
  base_data.files.themes_file.close();

}

void drawStaticElements(BaseData &base_data,
                        sf::RenderWindow &window) {

  if (base_data.switches.is_history) {
    window.draw(base_data.history);
    window.draw(base_data.boxes.mask_box);
    window.draw(base_data.boxes.scroll_rect);
    window.draw(base_data.sprites.spr_clear_history);

  } else if (base_data.switches.is_settings) {
    window.draw(base_data.settings_texts.label_settings);
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
  window.draw(base_data.sprites.spr_mode);
  window.draw(base_data.sprites.spr_music);
  window.draw(base_data.sprites.spr_sfx);
  window.draw(base_data.sprites.spr_settings);
  window.draw(base_data.sprites.spr_history);
  window.draw(base_data.sprites.spr_themes);
  window.draw(base_data.sprites.spr_language);
  window.display();
}

void updateBoxesAndTextsOutlineColor(BaseData &base_data) {
  base_data.boxes.mask_box.setFillColor(base_data.colors.back);
  base_data.boxes.scroll_rect.setFillColor(base_data.colors.text);
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
  base_data.history.setFillColor(base_data.colors.text);
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
  base_data.boxes.scroll_rect.setOutlineThickness(0);
  base_data.boxes.mask_box.setOutlineThickness(0);
  base_data.boxes.mask_box.setPosition(0, 0);
  base_data.boxes.song_volume.setOutlineThickness(THICKNESS);
  base_data.boxes.song_volume_visual.setOutlineThickness(0);
  base_data.boxes.sfx_volume.setOutlineThickness(THICKNESS);
  base_data.boxes.sfx_volume_visual.setOutlineThickness(0);
  base_data.boxes.song_name.setOutlineThickness(THICKNESS);
  base_data.boxes.font_name.setOutlineThickness(THICKNESS);
  base_data.boxes.font_size.setOutlineThickness(THICKNESS);
  base_data.boxes.font_size_visual.setOutlineThickness(0);

  base_data.boxes.scroll_rect.setSize(sf::Vector2f(20, 50));
  base_data.limit_top = 4*PADDING + IMG_SCALED;
  base_data.limit_bottom = HEIGHT - 2*PADDING - IMG_SCALED;
  base_data.boxes.scroll_rect.setPosition(WIDTH - 20, base_data.limit_top);

  sf::Vector2f general_size = sf::Vector2f(5*IMG_SCALED, IMG_SCALED - 2*THICKNESS);

  base_data.boxes.mask_box.setSize(sf::Vector2f(WIDTH, IMG_SCALED + 2*PADDING + 4.6));
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
  base_data.colors.button_clicked = base_data.themes[base_data.theme_index].button_clicked;
  base_data.colors.text = base_data.themes[base_data.theme_index].text;
  base_data.colors.back = base_data.themes[base_data.theme_index].back;

}
void setupAliases(BaseData &base_data, std::ifstream &fin) {
  fin >> base_data.dimension_second_dic;
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
void clearHistory(BaseData &base_data) {
  base_data.history_string.clear();
  base_data.history.setString(base_data.history_string);
  std::ofstream temp("history.txt", std::ios::out | std::ios::trunc);
  temp.close();
}
void requestHistory(BaseData &base_data) {
  base_data.history_string.clear();
  base_data.nr_lines = 0;
  bool sentence = true;
  std::ifstream history("history.txt");
  std::string line;
  while (std::getline(history, line)) {

    if (sentence) {
      base_data.nr_lines += 3;
      base_data.history_string = base_data.history_string + "QUESTION:\n";
      base_data.history_string = base_data.history_string + line + "\n";
    } else {
      base_data.nr_lines += 2;
      base_data.history_string = base_data.history_string + "ANSWER:\n";
      base_data.history_string = base_data.history_string + line + "\n\n";
    }
    sentence = !sentence;
  }
  base_data.history.setString(base_data.history_string);
  history.close();
}
void switchLanguageSprite(BaseData &base_data) {
  if (base_data.switches.english_language) {
    base_data.sprites.spr_language.setTextureRect(sf::IntRect(0, 1152, IMG_REAL, IMG_REAL));
  } else {
    base_data.sprites.spr_language.setTextureRect(sf::IntRect(0, 1056, IMG_REAL, IMG_REAL));
  }
}
