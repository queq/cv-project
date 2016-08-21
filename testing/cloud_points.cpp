#include <opencv2/opencv.hpp>

// shame, needs windows.h on win, else problem with APIENTRY
//#include <windows.h>
#include <GL/gl.h>

using namespace std;
using namespace cv;

float pts[8*3] = {
    0.270598,0.254439,0.471311,
    0.270598,0.254439,0.518814,
    0.270598,0.282268,0.518814,
    0.270598,0.282268,0.471311,
    0.396951,0.254439,0.471311,
    0.396951,0.282268,0.471311,
    0.396951,0.282268,0.518814,
    0.396951,0.254439,0.518814
};

void on_opengl(void* param)
{
    glLoadIdentity();
    glPointSize(3);
    glBegin(GL_POINTS);
    for ( int i=0; i<8; i++ )
    {
        glColor3ub( i*20, 100+i*10, i*42 );
        glVertex3fv(&pts[i*3]);
    }
    glEnd();
}

int main(int argc, char *argv[])
{
    namedWindow("3d",CV_WINDOW_OPENGL|CV_WINDOW_NORMAL);
    setOpenGlDrawCallback("3d",on_opengl,0);
    waitKey(0);
    return 0;
}
