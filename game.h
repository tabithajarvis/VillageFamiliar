#ifndef GAME_H
#define GAME_H


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <sstream>

#include "conversation.h"
#include "conversation_hud.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The dimensions of the level
const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;

class Game {
  public:
    Game();
    bool Initialize();
    void Update();
    void UpdateDisplay();

    bool running() { return running_; }

  private:
    void HandleKeypress(SDL_Event *e);

    SDL_Window *game_window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;
    bool running_ = true;
    Conversation *current_conversation_ = nullptr;
    ConversationHUD *conversation_hud_ = nullptr;

};

#endif GAME_H
