#include "conversation_hud.h"

ConversationHUD::ConversationHUD(SDL_Renderer* renderer) :
    renderer_(renderer) {
  //Initialize renderer color
  SDL_SetRenderDrawColor( renderer_, 0x00, 0xFF, 0xFF, 0xFF );
}

void ConversationHUD::UpdateConversation(ConversationEvent e) {
  if(*event_ == e) {
    return;
  }


}
