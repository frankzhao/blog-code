//
//  main.cpp
//  OpenGLExample
//
//  Created by Frank Zhao on 14/04/2014.
//  Copyright (c) 2014 Frank Zhao. All rights reserved.
//

#ifdef WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

using namespace std;

float rotation_x = 0, rotation_y = 0;

void display() {
    // Clear the colour and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // Reset transformations
    
    glRotatef(rotation_y, 1.0, 0.0, 0.0);
    glRotatef(rotation_x, 0.0, 1.0, 0.0);
    
    // Draw cube
    // front
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0); // green
    glVertex3f(  3.0,  3.0, -3.0 );
    glVertex3f(  3.0, -3.0, -3.0 );
    glVertex3f( -3.0, -3.0, -3.0 );
    glVertex3f( -3.0,  3.0, -3.0 );
    glEnd();
    
    // left
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0); // red
    glVertex3f( -3.0,  3.0, -3.0 );
    glVertex3f( -3.0,  3.0,  3.0 );
    glVertex3f( -3.0, -3.0,  3.0 );
    glVertex3f( -3.0, -3.0, -3.0 );
    glEnd();
    
    // right
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0); // red
    glVertex3f( 3.0,  3.0,  3.0 );
    glVertex3f( 3.0, -3.0,  3.0 );
    glVertex3f( 3.0, -3.0, -3.0 );
    glVertex3f( 3.0,  3.0, -3.0 );
    glEnd();
    
    // top
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1); // blue
    glVertex3f( -3.0,  3.0, -3.0 );
    glVertex3f( -3.0,  3.0,  3.0 );
    glVertex3f(  3.0,  3.0,  3.0 );
    glVertex3f(  3.0,  3.0, -3.0 );
    glEnd();
    
    // bottom
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1); // blue
    glVertex3f( -3.0, -3.0, -3.0 );
    glVertex3f( -3.0, -3.0,  3.0 );
    glVertex3f(  3.0, -3.0,  3.0 );
    glVertex3f(  3.0, -3.0, -3.0 );
    glEnd();
    
    // back
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0); // green
    glVertex3f(  3.0,  3.0, 3.0 );
    glVertex3f(  3.0, -3.0, 3.0 );
    glVertex3f( -3.0, -3.0, 3.0 );
    glVertex3f( -3.0,  3.0, 3.0 );
    glEnd();
    
    glFlush();
}

// Arrow keys for rotation
void rotate (int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            rotation_y -= 5;
            break;
        case GLUT_KEY_DOWN:
            rotation_y += 5;
            break;
        case GLUT_KEY_LEFT:
            rotation_x -= 5;
            break;
        case GLUT_KEY_RIGHT:
            rotation_x += 5;
            break;
        default:
            break;
    }
    
    // Update display
    glutPostRedisplay();
}

int main (int argc, char **argv){
    glutInit(&argc, argv);
    
    // Initialise a dingle buffer display mode with RGB and depth
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowPosition(0,0);    // Set initial window position to top right
    glutInitWindowSize(400,400);    // Size of initial window
    glutCreateWindow ("GLUT");      // Window title
    
    glEnable(GL_DEPTH_TEST);    // Enable depth rendering
    glDepthFunc(GL_LESS);       // Incoming depth needs to be less than stored
    
    glClearColor(0.0, 0.0, 0.0, 0.0);   // Black background
    glMatrixMode(GL_PROJECTION);        // Setup the drawing volume
    glLoadIdentity();                   // Start with the identity matrix
    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);   // Create a 10x10x10 world
    
    glutDisplayFunc(display);   // Method to run for displaying
    glutSpecialFunc(rotate);    // Key handling for rotations
    
    glutMainLoop();
    
    return 0;
}