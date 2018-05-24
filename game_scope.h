#ifndef GAME_SCOPE_H
#define GAME_SCOPE_H

class GameScope {
  public:
    virtual void HandleEvent() = 0;


  private:
    SDL_Window *game_window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;
    bool running_ = true;
    GameScope *game_scope_ = nullptr;

};

#endif GAME_SCOPE_H
