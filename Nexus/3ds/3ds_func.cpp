#include "../RetroEngine.hpp"

int _3ds_init() {
	gfxInitDefault();

	if (Engine.useC2DRender) {
		// TODO: set up Citro2D stuff
	} else {
		gfxSetScreenFormat(GFX_TOP, GSP_RGB565_OES);
	}

#if RETRO_USING_SDL1_AUDIO
	SDL_Init(SDL_INIT_AUDIO);	
#endif
}

void _3ds_exit() {
	if (Engine.useC2DRender) {
		// TODO: stuff
	}

	gfxExit();
}

// basically copied from the RSDKv3/4 port
void CopyFrameBuffer(u16* ptr) {
	u16* fb = (u16*) gfxGetFramebuffer(GFX_TOP, GFX_LEFT, 0, 0);

	// TODO: center this
	const int screenSize = SCREEN_XSIZE * SCREEN_YSIZE;
	for (int y = 0; y < SCREEN_YSIZE; y++) {
		for (int x = 0; x < SCREEN_XSIZE; x++) {
	    		fb[((x * 240) + (240 - y - 1))] = *ptr++;
		}
	}
}
