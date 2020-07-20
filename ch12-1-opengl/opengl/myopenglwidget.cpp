#include "myopenglwidget.h"
#include <QOpenGLShaderProgram>

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

void MyOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    QOpenGLShader * vshader = new QOpenGLShader(QOpenGLShader::Vertex,this);
    const char * vsrc =
            "in vec4 vPosition;"
            "void main() {\n"
            "gl_Position = vPosition;\n"
            "}\n";
    vshader->compileSourceCode(vsrc);

    QOpenGLShader * fshader = new QOpenGLShader(QOpenGLShader::Fragment,this);
    const char * fsrc =
            "void main() {\n"
            "gl_FragColor = vec4(1.0,1.0,1.0,1.0);\n"
            "}\n";
    fshader->compileSourceCode(fsrc);

    program = new QOpenGLShaderProgram;
    program->addShader(vshader);
    program->addShader(fshader);
    program->link();
    program->bind();
}

void MyOpenGLWidget::paintGL()
{
    int w = width();
    int h = height();
    int side = qMin(w,h);
    glViewport((w-side)/2,(h-side)/2,side,side);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    GLfloat vertices[] = {
        -0.8,0.8,
        -0.8,-0.8,
        0.8,-0.8,
        0.8,0.8
    };

    vbo.create();
    vbo.bind();
    vbo.allocate(vertices,8*sizeof (GLfloat));

    GLuint vPosition = program->attributeLocation("vPosition");
    //glVertexAttribPointer(vPosition,2,GL_FLOAT,GL_FALSE,0,vertices);
    program->setAttributeBuffer(vPosition,GL_FLOAT,0,2,0);
    glEnableVertexAttribArray(vPosition);
    glDrawArrays(GL_TRIANGLE_FAN,0,4);
}

void MyOpenGLWidget::resizeGL(int w, int h)
{

}
