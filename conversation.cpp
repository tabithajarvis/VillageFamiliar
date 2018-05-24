#include "conversation.h"

#include <fstream>

namespace {
  constexpr int kMaxLineSize = 300;
}

std::vector<std::string> split(std::string str, char delimiter) {
  std::vector<std::string> v;

  std::stringstream ss(str);
  std::string token;
  while (std::getline(ss, token, delimiter)) {
      printf("Token: %s\n", token.c_str());
      v.push_back(token);
  }

  return v;
}

Conversation::Conversation (std::string file_name) {
  //Open the map
    printf("Filename: %\n", file_name.c_str());

    std::ifstream convo;

    convo.open(file_name.c_str());
    if (!convo) {
      printf("Failed to load conversation");
    }

    char line[kMaxLineSize];
    while (!convo.eof()){
      convo.getline(line, kMaxLineSize);
      printf("Line: %s\n", line);
      auto v = split(line, ':');

      if (v.size() == 2)
        conversation_events_.push_back(ConversationEvent(v[0], v[1]));
    }

    convo.close();
}

ConversationEvent Conversation::Event() {
  return (conversation_events_.at(iter_));
}

void Conversation::Continue() {
  iter_++;

  if (iter_ >= conversation_events_.size()) {
      iter_ = 0;
    finished_ = true;
  }
}
