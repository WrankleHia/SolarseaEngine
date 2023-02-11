#include "se_openglwindow.h"
#include <solarapi>
using namespace std;


SE_OpenGLWindow::SE_OpenGLWindow(QWidget *parent)
    : QOpenGLWidget{parent}
{

}
const float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.5f,  0.5f, 0.0f,
};

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(135.0f, 206.0f, 235.0f, 1.0f);\n"
    "}\n\0";

void SE_OpenGLWindow::initializeGL()
{
    initializeOpenGLFunctions();

        objectCount(3);

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader,1,&vertexShaderSource,(nullptr));
        glCompileShader(vertexShader);
        int success;
        glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram,vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }


void SE_OpenGLWindow::resizeGL(int w, int h)
{

}

void SE_OpenGLWindow::paintGL()
{
    glClearColor(255.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,3);
}

