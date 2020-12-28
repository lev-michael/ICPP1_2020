#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "App.h"


int main()
{
    App* app = new App();
    app->run();
    delete app;
    _CrtDumpMemoryLeaks();
    return 0;
}

