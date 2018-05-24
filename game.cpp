#include "game.h"

Game::Game() {}

bool Game::Initialize() {
  game_window_ = SDL_CreateWindow( "Village Familiar", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
  if (!game_window_) {
    printf( "Game window could not be created.");
    running_ = false;
  }

  renderer_ = SDL_CreateRenderer( game_window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
  if (!renderer_) {
    printf("Renderer could not be created.");
    running_ = false;
  }

  current_conversation_ = new Conversation("Conversations/startup.CONVO");
  conversation_hud_ = new ConversationHUD(renderer_);

	return running_;
}

void Game::Update() {
  //Event handler
	SDL_Event e;

  // Handle queued events
  while( SDL_PollEvent( &e ) != 0 ) {
    switch( e.type ) {
      case SDL_QUIT:
        running_ = false;
        break;
      case SDL_KEYDOWN:
        if ( e.key.repeat == 0 ) {
          HandleKeypress(&e);
        }
        break;

      default:
        break;
    }
  }

  UpdateDisplay();
}

void Game::HandleKeypress(SDL_Event *e) {
    //Adjust the velocity
    switch( e->key.keysym.sym ) {
        case SDLK_SPACE:
            current_conversation_->Continue();
            break;
        case SDLK_ESCAPE:
            running_ = false;
            break;

        default:
            break;
    }
}

void Game::UpdateDisplay() {
  conversation_hud_->UpdateConversation(current_conversation_->Event());
}

