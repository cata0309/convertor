# Calculator in romana

# not yet(in engleza, in franceza)

## Current supporting OS's
- GNU/Linux
## Dependencies list
- cmake >= 3.15
- bash 
- Linux(until I add the SFML Windows libraries)

### Build instructions

`./run` or `cmake . && make play`in a terminal emulator opened at the project folder

## LIST TO DO
## Graphics
- [ ] Icon for the executable

- [ ] Text color:

- [ ] Background color:

- [x] Assets(48 x 48 scaled, 320 x 320 real bundled in one image with Free Texture Packer): 
		
   (dynamic color changing(must be WHITE !!!))
   
   - [x] settings button  
        - [x] '<' left button 
        - [x] '>' right button
	     - [x] '=' equal button
        - [x] mode button
        - [x] delete button
       - [x] music button
        - [x] sfx button
        - [x] clear input box button
## Repository/Code
- [ ] Create a proper master branch
- [x] Create a devel branch
- [x] Add dependencies list to the README.md
- [ ] Integrate the logic with the graphics
- [ ] Make the number translations correct
- [ ] Handle errors and 'try again''s make the input editable 
- [ ] Clean the code(remove what is not needed or what is done too much, simplify)
- [ ] Write documentation and proper README.md
- [ ] Sort the functions alphabetically
- [ ] Rethink a  the naming convention
- [x] Add build instructions to README.md
- [ ] Rethink the defines

##  Features

- [ ] Add support for Window build
- [x] Make the settings volume_music number to be updated to zero when muted via button/buttons or click in the box
- [ ] Make visual representation of the click in the box at volume_music and font_list
- [ ] Add stroke like background and draw behind the visual representation of the boxes that do not follow the mouse_pos, they follow the new data created  
- [x] Center all the text in the settings, in their boxes
- [ ] Draw settings label in the top left corner
- [ ] Add platform dependent build(Windows/Linux)
- [ ] Make some STANDALONE executables
- [ ] Make a SourceTrail project
- [ ] Add DEBUG mode(Drawing all the frontier lines of boxes sizes, FPS numbers,Mouse position highlight)
## Fonts
- [ ] Rethink the font_list and what are suitable
- [ ] Add more font_list, max 10, alphabetically ordered
## Music
- [ ] Add more song_list, max 10, alphabetically ordered
## Language definitions
- [ ] Romanian
- [ ] English
- [ ] French