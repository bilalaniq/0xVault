#include "app-window.h" // This will be generated from your .slint file

int main() {
    // Create the main window component
    auto main_window = MainWindow::create();
    
    // Run the main event loop
    main_window->run();
    
    return 0;
}