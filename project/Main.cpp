#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
    // Inicjalizacja GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Tworzenie okna
    GLFWwindow* window = glfwCreateWindow(800, 800, "Puste okno", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Nie uda³o siê utworzyæ okna GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Inicjalizacja GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Nie uda³o siê za³adowaæ GLAD" << std::endl;
        return -1;
    }

    // Ustawienie widoku
    glViewport(0, 0, 800, 800);

    // G³ówna pêtla renderuj¹ca
    while (!glfwWindowShouldClose(window))
    {
        // Czyszczenie ekranu
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Zakoñczenie dzia³ania
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
