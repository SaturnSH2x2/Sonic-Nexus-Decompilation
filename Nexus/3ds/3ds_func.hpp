#ifndef _3DS_FUNC_H
#define _3DS_FUNC_H

int  _3ds_init();
void _3ds_exit();

// framebuffer copy for SW rendering
void CopyFrameBuffer(u16* ptr);

#endif
