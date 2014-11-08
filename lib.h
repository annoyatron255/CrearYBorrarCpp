// main.cpp
int draw();
int setupMouse();
// gfx.cpp
int gfxinit(int x, int y);
int fillRect(SDL_Rect rect, int r, int g, int b);
int close();
int update();
int clearScreen();
// input.cpp
int windowEvent();
int key();
int inputLoop();
// general.cpp
int overlap(SDL_Rect rect1, SDL_Rect rect2);
int touching(SDL_Rect rect1, SDL_Rect rect2);
int checkDeath();
// enemy.cpp
SDL_Rect updateai(SDL_Rect rect, int dir);
SDL_Rect checkOnScreen(SDL_Rect rect);
int changeDir(SDL_Rect rect, int currentDir);
int randDir();
//timer.cpp
int timeStart();
int timePassed();

// Variables
extern const int screenx;
extern const int screeny;
extern bool done;
extern SDL_Rect player;
extern SDL_Rect enemy[];
extern int enumber;
extern double espeed;
//extern int direction;
