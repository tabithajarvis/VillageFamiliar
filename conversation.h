#ifndef CONVERSATION_H
#define CONVERSATION_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>

struct ConversationEvent {
  std::string character;
  std::string dialog;

  ConversationEvent(std::string c, std::string d) {
    character = c;
    dialog = d;
  }

  bool operator==(const ConversationEvent &other) const {
    if (character.compare(other.character) == 0 &&
        dialog.compare(other.dialog) == 0) {
      return true;
    }

    return false;
  }
};

class Conversation {
  public:
    Conversation(std::string file_name);
    void Continue();
    ConversationEvent Event();
    bool finished() { return finished_; }

  private:
    std::vector<ConversationEvent> conversation_events_;
    int iter_ = 0;
    bool finished_ = false;

};

#endif CONVERSATION_H
