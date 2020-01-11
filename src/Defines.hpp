#ifndef CONVERTOR_SRC_DEFINES_HPP_
#define CONVERTOR_SRC_DEFINES_HPP_

//#define WIDTH 960
//#define HEIGHT 720

#define WIDTH 1024 //the width of the window
#define HEIGHT 768 //the height of the window

//#define WIDTH 1280
//#define HEIGHT 960
#define TITLE "Interactive calculator"//the title of the window

#define MAX_NR_FONTS 10//the maximum numbers of fonts that can be loaded
#define MAX_NR_SONGS 10//the maximum numbers of songs that can be loaded
#define MAX_SONG_NAME 20//the maximum size of a name of a song
#define MAX_FONT_NAME 30//the maximum size of a name of a font
#define MAX_PATH 70//the maximum path of a variable that stores a path to a file
#define MAX_CLICKS_STROKES 5//maximum strokes that can be played simultaneous
#define MAX_NR_THEMES 10//maximum number of themes that can be loaded
#define IMG_REAL 96//the dimension x and y as the image
#define IMG_SCALED 48//the dimension x and y that we render
#define X_TIMES 0.5//the scaling factor IMG_SCALED=X_TIMES*IMG_REAL

#define ERROR "assets/sounds/error.wav"
#define TYPE "assets/sounds/stroke.wav"
#define CLICK "assets/sounds/click.wav"
#define GLOB_TEXTURE "assets/images/texture.png"
#define PADDING 8 //the distance between the top buttons and the margins of the window
#define THICKNESS 3 //the thickness of the outline of the boxes
#define VERTICAL_PADDING 10 //the distance between the boxes in the seconds

#define MIN_DIM_FONT 20 // the minimum font size
#define MAX_DIM_FONT 27//the maximum font size

#define POS_HIST_BOX_X 48 //the x position of the history text
#define POS_HIST_BOX_Y 48 //the y position of the history text

#define SCROLL_LINES 1 //the numbers of lines to scroll when UP/DOWN arrows are clicked
#endif //CONVERTOR_SRC_DEFINES_HPP_