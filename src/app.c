//
//  app.c
//  K2
//
//  Created by Justin Bowes on 2013-08-23.
//  Copyright (c) 2013 Informi Software Inc. All rights reserved.
//

#include "app.h"
#include "view_fade.h"

app_t app = {
	.name = "K2 test app",
	.exit = false
};

static bool quit_request(SDL_Event *event) {
	bool exit = false;
	switch (event->type) {
		case SDL_QUIT:
			exit = true;
			break;
		case SDL_WINDOWEVENT:
			exit = (event->window.event == SDL_WINDOWEVENT_CLOSE);
			break;
	}
	
	if (exit) {
		app.exit = true;
		SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
	}
	return exit;
}

void app_init(void) {
	config_init();
	display_init();
	score_init();
	timer_blit_init();
	event_init();
	window_init();
	keyboard_init();
	audio_init();
	process_init();
	view_init();
	sprites_init();
	timer_init(&game.ticks, config.frame_interval, 10 * config.frame_interval);
	
	event_add_handler(NULL, quit_request, SDL_QUIT);
	event_add_handler(NULL, quit_request, SDL_WINDOWEVENT);	

	view_push(&view_fade);	
	view_fade_in((SDL_Color) {0});

	
	game_init();
}

void app_destroy() {
//	config_destroy();
//	display_destroy();
//	event_destroy();
//	window_destroy();
//	score_destroy();
	timer_blit_destroy();
	keyboard_destroy();
	audio_destroy();
//	process_destroy();
//	view_destroy();
//	timer_destroy();
//	game_destroy();
	sprites_destroy();
}