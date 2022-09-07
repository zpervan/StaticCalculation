#include <GLFW/glfw3.h>  // Will drag system OpenGL headers
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <stdio.h>

#include "Application/Backend/coefficient_service.h"
#include "Application/Core/configuration.h"
#include "Application/Core/event_system.h"
#include "Application/Core/paths.h"
#include "Application/GUI/Components/coefficient_database.h"
#include "Application/GUI/Core/main_window.h"
#include "Application/GUI/Core/menu_bar.h"
#include "Application/GUI/Elements/info_popup_window.h"

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int, char**)
{
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) return 1;

    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Create window with graphics context
    GLFWwindow* window =
        glfwCreateWindow(Configuration::WINDOW_WIDTH, Configuration::WINDOW_HEIGHT, "Statika - Torzo", NULL, NULL);

    if (window == NULL)
    {
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);  // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    /// @TODO: Add assets manager
    io.Fonts->AddFontFromFileTTF(Paths::ArialFontPath().c_str(), Configuration::FONT_SIZE);
    io.FontDefault = io.Fonts->Fonts[0];

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //    ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Core functionalities
    EventSystem event_system{};
    Backend::CoefficientService coefficient_service{};
    bool is_done{false};

    // Custom GUI components
    GUI::CoefficientDatabase coefficient_database{event_system, coefficient_service};
    GUI::InfoPopupWindow about_popup_window_{event_system};
    GUI::MainWindow main_window{event_system, coefficient_service};
    GUI::MenuBar menu_bar{event_system};

    // Main loop
    while (!glfwWindowShouldClose(window) && !is_done)
    {
        glfwPollEvents();

        /// @TODO: Create a window class and hide the boilerplate code
        if (event_system.Poll() == Events::Exit)
        {
            is_done = true;
        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // GUI components
        {
            menu_bar.Show();
            main_window.Show();

            if (event_system.Poll() == Events::CoefficientDatabase_OpenWindow)
            {
                coefficient_database.Show();
            }

            if (event_system.Poll() == Events::About_OpenWindow)
            {
                about_popup_window_.Show("Unesi nesto o aplikaciji");
            }
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(
            clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}