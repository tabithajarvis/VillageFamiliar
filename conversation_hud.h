#ifndef CONVERSATION_HUD_H
#define CONVERSATION_HUD_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>

#include "conversation.h"

class ConversationHUD {
  public:
    ConversationHUD(SDL_Renderer *renderer);
    bool Initialize();
    void UpdateConversation(ConversationEvent e);

  private:
    void HandleKeypress(SDL_Event *e);

    SDL_Renderer* renderer_ = nullptr;
    ConversationEvent *event_ = nullptr;
    TTF_Font *font_ = nullptr;
    SDL_Texture *text_area_ = nullptr;
    SDL_Texture *name_area_ = nullptr;
};

#endif CONVERSATION_HUD_H
