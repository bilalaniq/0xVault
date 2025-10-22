#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
    glfwInit();
    GLFWwindow* win = glfwCreateWindow(400, 400, "OpenGL Test", nullptr, nullptr);
    glfwMakeContextCurrent(win);
    glewInit();

    while(!glfwWindowShouldClose(win)) {
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);

        glPointSize(50.0f);      // Make the point big
        glBegin(GL_POINTS);
            glColor3f(1,1,1);
            glVertex2f(0.0f, 0.0f); // Center
        glEnd();

        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glfwDestroyWindow(win);
    glfwTerminate();
    return 0;
}
