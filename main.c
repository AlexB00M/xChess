#include "App.h"

int main(int argc, char *argv[]) {
    App *app = appCreate(argc, argv, "Chess");
    if (!app) {
        return 1;
    }

    appLoopStart(app);
    return 0;
}
