#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define new new
#endif

#include "App.h"


int main()
{
    App* app = new App();
    app->run();
    delete app;
    _CrtDumpMemoryLeaks();
    return 0;
}

