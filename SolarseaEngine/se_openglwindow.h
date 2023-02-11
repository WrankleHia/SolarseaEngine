#ifndef SE_OPENGLWINDOW_H
#define SE_OPENGLWINDOW_H

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtOpenGL/QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>

class SE_OpenGLWindow : public QOpenGLWidget, QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    explicit SE_OpenGLWindow(QWidget *parent = nullptr);
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
private:
    unsigned int VBO;
    unsigned int VAO;
    unsigned int shaderProgram;
signals:

};

#endif // SE_OPENGLWINDOW_H
