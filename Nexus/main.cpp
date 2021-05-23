#include "RetroEngine.hpp"

int main(int argc, char *argv[])
{

#if RETRO_PLATFORM != RETRO_3DS
    for (int i = 0; i < argc; ++i) {
        if (StrComp(argv[i], "UsingCWD"))
            usingCWD = true;
    }
#else
    _3ds_init();
#endif
    printf("Sonic Nexus 3DS\n");
    hang();

    printf("Initializing engine...\n");
    Engine.Init();
    printf("Engine initialized.\n");
    hang();

    _3ds_setColorDepth();
    Engine.Run();

#if RETRO_PLATFORM == RETRO_3DS
    _3ds_exit();
#endif

    return 0;
}
