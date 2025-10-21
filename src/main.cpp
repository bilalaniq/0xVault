#include "app-window.h"
#include <sodium.h>
#include <nlohmann/json.hpp>

int main(int argc, char **argv)
{
    auto ui = AppWindow::create();

    
    ui->run();
    return 0;
}