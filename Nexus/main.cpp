#include "RetroEngine.hpp"

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; ++i) {
        if (StrComp(argv[i], "UsingCWD"))
            usingCWD = true;
    }

#if RETRO_PLATFORM == RETRO_3DS
    _3ds_init();
#endif

    Engine.Init();
    Engine.Run();

#if RETRO_PLATFORM == RETRO_3DS
    _3ds_exit();
#endif

    return 0;
}
