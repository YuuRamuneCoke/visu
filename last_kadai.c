#include<stdio.h>
#include<windows.h>
#include <conio.h>
#pragma comment(lib, "winmm.lib")
#include <mmsystem.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "read_bitmap.h"
#define imageWidth 8
#define imageHeight 8

//画像関係
int ReadBitMapData();
void polarview(void);
void resetview(void);
unsigned char image1[imageHeight][imageWidth][4];
unsigned char image2[imageHeight][imageWidth][4];
float distance, twist, elevation, azimuth;
float nearw = 1.0, farw = 1.0, fovy = 1.0;
int tid = 3;
void initTexture(void);

MCIDEVICEID playSound(char* strFile);
void stopSound(MCIDEVICEID stopID);

// ウィンドウのサイズ
int width = 800;
int height = 600;

// 線の始点と終点の座標
float startX = 0.0f;
float startY = -0.4f;
float endX = 0.0f;
float endY = 4.0f;

float start2X = 0.0f;
float start2Y = 4.0f;
float end2X = -0.55f;
float end2Y = 4.0f;

float start3X = -0.55f;
float start3Y = 4.0f;
float end3X = -0.55f;
float end3Y = 4.7f;

float start4X = -0.55f;
float start4Y = 4.7f;
float end4X = -0.2f;
float end4Y = 5.0f;

float start5X = -0.2f;
float start5Y = 5.0;
float end5X = -0.2f;
float end5Y = 12.75f;

float start6X = -0.2f;
float start6Y = 12.75f;
float end6X = 0.2f;
float end6Y = 12.75f;

float start7X = 0.2f;
float start7Y = 12.75f;
float end7X = 0.2f;
float end7Y = 13.15f;

float start8X = 0.2f;
float start8Y = 13.15f;
float end8X = 4.8f;
float end8Y = 13.15f;

float start9X = 4.8f;
float start9Y = -0.11f;
float end9X = 4.8f;
float end9Y = 0.4f;

float start10X = 4.8f;
float start10Y = 0.4f;
float end10X = 5.15f;
float end10Y = 0.7f;

float start11X = 5.15f;
float start11Y = 0.7f;
float end11X = 7.8f;
float end11Y = 0.7f;

float start12X = 7.8f;
float start12Y = 0.7f;
float end12X = 7.8f;
float end12Y = -1.2f;

float start13X = 7.8f;
float start13Y = -1.2f;
float end13X = 6.8f;
float end13Y = -1.2f;

float start14X = 6.8f;
float start14Y = -1.2f;
float end14X = 6.8f;
float end14Y = -10.0f;

float dist = 0.0; /*視点の移動量1*/
float dist2 = 0.0;/*視点の移動量2*/
float dist3 = -0.2;/*視点の移動量3*/
float dist4 = 0.0; /*視点の移動量1*/
float dist5 = 0.0;/*視点の移動量2*/
float dist6 = 0.0;/*視点の移動量3*/
float dist7= 0.0; /*視点の移動量1*/
float dist8 = 0.0;/*視点の移動量2*/
float dist9 = 0.0;/*視点の移動量3*/
float theta = 0.0; /*物体の回転角度*/


// 点の座標
float x = 0.0f;
float y = -0.4f;

// 点の速度
float speed = 0.010f;

float speed2 = 0.013f;

float speed3 = 0.020f;

float count = 0.0f;
float count2 = -0.4f;
float count3 = -0.2f;
float count4 = -0.11f;
float count5 = 0.2f;
float count6 = 0.0f;
float count7 = 0.0f;
float count8 = 0.0f;
float count9 = 0.0f;

// 楕円の中心座標と半径
const float centerX = 0.5;
const float centerY = 0.0;
const float radiusX = 0.44;
const float radiusY = 0.20;

float center2Y = 0.0f;


//音楽の変数
char* strFile;
MCIDEVICEID playID[1];

int scount = 0;




// アニメーションの更新処理
void update(int value) {
     //点の座標を更新

    scount++;

    center2Y -= speed;

    //線1中の動き
    if (endY >= -0.4 && count < 0.55f && count2 != -1) {
        startY -= speed2;
        endY -= speed2;

        start2Y -= speed2;
        end2Y -= speed2;

        start3Y -= speed2;
        end3Y -= speed2;

        start4Y -= speed2;
        end4Y -= speed2;

        start5Y -= speed2;
        end5Y -= speed2;

        start6Y -= speed2;
        end6Y -= speed2;

        start7Y -= speed2;
        end7Y -= speed2;

        start8Y -= speed2;
        end8Y -= speed2;
    }


    //線２中の動き
    if (endY <= -0.4 && count >= -0.55f) {
        x += -speed;
        count += -speed;
    }

    //線3中の動き
    if (count < -0.55f && end3Y >= -0.4 && count2 != -1) {

        x = -0.55f;

        startY -= speed2;
        endY -= speed2;

        start2Y -= speed2;
        end2Y -= speed2;

        start3Y -= speed2;
        end3Y -= speed2;

        start4Y -= speed2;
        end4Y -= speed2;

        start5Y -= speed2;
        end5Y -= speed2;

        start6Y -= speed2;
        end6Y -= speed2;

        start7Y -= speed2;
        end7Y -= speed2;

        start8Y -= speed2;
        end8Y -= speed2;
    }

    //線４中の動き
    if (end3Y < -0.4 && count2 < -0.05f) {

        x += 0.013f;
        y += 0.011f;
        count2 += 0.013f;
    }

    //線5中の動き
    if (count2 >= -0.05f && start5Y >= -9.0f && count != 0 ) {

        x = -0.2f;
        y = -0.1f;


        start3Y -= speed2;
        end3Y -= speed2;

        start4Y -= speed2;
        end4Y -= speed2;

        start5Y -= speed2;
        end5Y -= speed2;

        start6Y -= speed2;
        end6Y -= speed2;

        start7Y -= speed2;
        end7Y -= speed2;

        start8Y -= speed2;
        end8Y -= speed2;

    }

    //線6中の動き
    if (end5Y <= -0.1f && count3 <= 0.2f) {

        startY = 100000000.0f;
        endY = 1000000000.0f;

        start3Y = 1000000000.0f;
        end3Y = 1000000000.0f;

        count = 0;
        count2 = -1;

        end5Y = -0.1068;

        start6Y = -0.1068;
        end6Y = -0.1068;

        start7Y = -0.1068;
        end7Y = 0.2931;

        start8Y = 0.2931;
        end8Y = 0.2931;

        x += speed;
        count3 += speed;
    }

    //線7中の動き
    if (count3 > 0.2f && end7Y >= -0.1068) {

        start5Y -= speed2;
        end5Y -= speed2;

        start6Y -= speed2;
        end6Y -= speed2;

        start7Y -= speed2;
        end7Y -= speed2;

        start8Y -= speed2;
        end8Y -= speed2;
    }

    //線8中の動き
    if (end7Y < -0.1068 && count4 == -0.11f){

        start5X -= speed2;
        end5X -= speed2;

        start6X -= speed2;
        end6X -= speed2;

        start7X -= speed2;
        end7X -= speed2;

        start8X -= speed2;
        end8X -= speed2;

        start9X -= speed2;
        end9X -= speed2;

        start10X -= speed2;
        end10X -= speed2;

        start11X -= speed2;
        end11X -= speed2;

        start12X -= speed2;
        end12X -= speed2;

        start13X -= speed2;
        end13X -= speed2;

        start14X -= speed2;
        end14X -= speed2;
    }

    //線9中の動き
    if (end8X <= 0.2f && count4 <= 0.4f) {

        y += speed;
        count4 += speed;
    }

    //線10中の動き
    if (count4 > 0.4f && count5 <= 0.55) {

        x += 0.013f;
        y += 0.0105f;
        count5 += 0.013f;
    }

    //線11中の動き
    if (count5 > 0.55 && count6 == 0.0f) {

        start7X -= speed2;
        end7X -= speed2;

        start8X -= speed2;
        end8X -= speed2;

        start9X -= speed2;
        end9X -= speed2;

        start10X -= speed2;
        end10X -= speed2;

        start11X -= speed2;
        end11X -= speed2;

        start12X -= speed2;
        end12X -= speed2;

        start13X -= speed2;
        end13X -= speed2;

        start14X -= speed2;
        end14X -= speed2;

        count7++;
    }

    //線12中の動き
    if (count7 >= 204 && count9 == 0.0) {

        count6 = 1;


        start11Y += speed3;
        end11Y += speed3;

        start12Y += speed3;
        end12Y += speed3;

        start13Y += speed3;
        end13Y += speed3;

        start14Y += speed3;
        end14Y += speed3;

        count8++;


    }

    //線13中の動き
    if (count8 >= 95 && count9 <= 49) {

        x -= speed3;
        count9++;

    }

    if (count9 > 49) {

        start12Y += speed3;
        end12Y += speed3;

        start13Y += speed3;
        end13Y += speed3;

        start14Y += speed3;
        end14Y += speed3;

    }

    // 画面を再描画
    glutPostRedisplay();

    // 次の更新を予約
    glutTimerFunc(16, update, 0);
}


// 描画処理
void display(void) {
    // 画面をクリア
    glClear(GL_COLOR_BUFFER_BIT);

    if (scount == 315) {
        glClearColor(0.3, 0.0, 0.0, 1.0);
    }
    else if (scount == 524) {
        glClearColor(0.6, 0.6, 0.6, 1.0);
    }
    else if (scount == 630) {
        glClearColor(0.0, 0.6, 0.6, 1.0);
    }
    else if (scount == 655) {
        glClearColor(0.6, 0.6, 0.0, 1.0);
    }
    else if (scount == 680) {
        glClearColor(0.3, 0.0, 0.0, 1.0);
    }
    else if (scount == 1150) {
        glClearColor(0.0, 0.0, 0.0, 1.0);
    }
    else if (scount == 1575) {
        glClearColor(0.8, 0.8, 0.8, 1.0);
    }
    else if (scount == 1776) {
        glClearColor(0.5, 0.0, 0.0, 1.0);
    }
    else if (scount == 1883) {
        glClearColor(0.0, 0.0, 0.5, 1.0);
    }
    else if (scount == 1897) {
        glClearColor(0.0, 0.0, 0.0, 1.0);
    }
    else if (scount == 1910) {
        glClearColor(0.5, 0.0, 0.0, 1.0);
    }
    else if (scount == 1924) {
        glClearColor(0.0, 0.5, 0.0, 1.0);
    }
    else if (scount == 1936) {
        glClearColor(0 ,0, 0, 1.0);
    }



    if((scount >= 112 && scount <= 241) || (scount >= 269 && scount <= 1080)){
        //立方体の地面
        glColor4f(0.9f, 0.9f, 0.9f, 4.0f); // 塗りつぶしの色（グレー）
        glBegin(GL_POLYGON);

        for (int i = 0; i < 360; i++) {
            float angle = i * 3.1415 / 180.0f;
            float x2 = centerX + radiusX * cos(angle);
            float y2 = centerY + radiusY * sin(angle);
            glVertex2f(x2,y2);
        }
        glEnd();

    }

    if ((scount >= 215 && scount <= 241) ||( scount >= 269 && scount <= 1080 ) ){
        //立方体
        glPushMatrix();
        gluLookAt(0.0, 0.0, 0.0,
            0.0, -0.2, 1.0,
            0.0, 1.0, 0.0);
        glPushMatrix();
        glTranslatef(-0.5, 0.5, 0.0);
        glRotatef(theta, 0.0, 0.5, 0.0);
        glColor3f(0.6, 0.6, 0.6);
        glutSolidCube(0.2); // サイズ1の立方体を描画
        glPopMatrix();
        glPopMatrix();
    }

    if ((scount >= 162 && scount <= 241) || (scount >= 269 && scount <= 1080) ) {
        //立方体影
        glPushMatrix();
        gluLookAt(0.0, 0.0, 0.0,
            0.0, -10, 1.0,
            0.0, 1.0, 0.0);
        glPushMatrix();
        glTranslatef(-0.5, 0.1, 0.0);
        glRotatef(theta, 0.0, 0.5, 0.0);
        glColor3f(0.2, 0.2, 0.2);
        glutSolidCube(0.17); // サイズ1の立方体を描画 
        glPopMatrix();
        glPopMatrix();
    }

    //エフェクト1
    if (scount >= 260 && scount <= 350) {
        glPushMatrix();
        gluLookAt(0.0, 0.0, 0.0,
            0.0, -0.2, 1.0,
            0.0, 1.0, 0.0);
        glTranslatef(-0.1, 0.1, 0.0);
        glRotatef(theta, 0.0, 0.0, 0.0);
        glColor3f(0.4, 0.5, 0.0);
        glutWireCube(dist3 + 0.2); // サイズ1の立方体を描画
        glPopMatrix();
    }



    if (scount >= 470 && scount <= 1000) {

        //立方体
        glPushMatrix();
        gluLookAt(0.0, 0.0, 0.0,
            0.0, -1.0, 1.0,
            0.0, 1.0, 0.0);
        glTranslatef(0.5, -dist + 1.0, 0.0);
        glRotatef(theta, 0.0, 0.1, 0.0);
        glColor4f(0.6, 0.0, 0.5,0.7);
        glutWireCube(0.3); // サイズ1の立方体を描画
        glPopMatrix();

        glPushMatrix();
        gluLookAt(0.0, 0.0, 0.0,
            0.0,-1.0, 1.0,
            0.0, 1.0, 0.0);
        glTranslatef(0.7, -dist + 2.7, 0.0);
        glRotatef(theta, 0.0, 0.1, 0.0);
        glColor4f(0.6, 0.6, 0.0, 0.7);
        glutWireCube(0.3); // サイズ1の立方体を描画
        glPopMatrix();

        glPushMatrix();
        gluLookAt(0.0, 0.0, 0.0,
            0.0, -1.0, 1.0,
            0.0, 1.0, 0.0);
        glTranslatef(-0.4, -dist + 1.7, 0.0);
        glRotatef(theta, 0.0, -0.1, 0.0);
        glColor4f(0.0, 0.6, 0.2, 0.7);
        glutWireCube(0.3); // サイズ1の立方体を描画
        glPopMatrix();

        glPushMatrix();
        gluLookAt(0.0, 0.0, 0.0,
            0.0, -1.0, 1.0,
            0.0, 1.0, 0.0);
        glTranslatef(-0.2, -dist + 3.5, 0.0);
        glRotatef(theta, 0.0, -0.1, 0.0);
        glColor4f(0.6, 0.0, 0.0, 0.7);
        glutWireCube(0.3); // サイズ1の立方体を描画
        glPopMatrix();


    }

    if (scount >= 730 && scount <= 1050) {
        glPushMatrix();
        glTranslatef(sin(dist2) - 0.2, 0.2, 0.0);
        glRotatef(theta, 0.2, 0, 0.0);
        glColor3f(0, 1.0, 0.0);
        glutSolidSphere(1.0, 2, 2); /*球*/
        glPopMatrix();


        glPushMatrix();
        glTranslatef(sin(-dist2) + 0.2, -0.4, 0.0);
        glRotatef(theta, 0.2, -1.0, 0.0);
        glColor3f(0.5, 0.0, 0.5);
        glutSolidSphere(1.4, 2, 2); /*球*/
        glPopMatrix();


        glPushMatrix();
        glTranslatef(sin(dist2) - 0.3, 0.5, 0.0);
        glRotatef(theta, 0.2, -1.0, 0.0);
        glColor3f(0.2, 0.1, 0.4);
        glutSolidSphere(1.5, 2, 2); /*球*/
        glPopMatrix();

        glPushMatrix();
        glTranslatef(sin(dist2) - 0.3, -0.5, 0.0);
        glRotatef(theta, 0.6, -1.0, 0.0);
        glColor3f(0.6, 0.1, 0.4);
        glutSolidSphere(1.2, 1.5, 1.5); /*球*/
        glPopMatrix();
    }

    if (scount >= 1170 && scount <= 1550) {

        glColor4f(0.9f, 0.9f, 0.9f, 4.0f); // 塗りつぶしの色（グレー）
        glBegin(GL_POLYGON);

        for (int i = 0; i < 360; i++) {
            float angle = i * 3.1415 / 180.0f;
            float x2 = -0.5 + radiusX * cos(angle);
            float y2 = 0.1 + radiusY * sin(angle);
            glVertex2f(x2, y2);
        }
        glEnd();

        //立方体
        glPushMatrix();
        gluLookAt(0.0, 0.0, 0.0,
            0.0, -0.2, 1.0,
            0.0, 1.0, 0.0);
        glPushMatrix();
        glTranslatef(0.5, 0.5, 0.0);
        glRotatef(1.4*theta, 0.0, -0.5, 0.0);
        glColor3f(0.6, 0.6, 0.6);
        glutSolidCube(0.2); // サイズ1の立方体を描画
        glPopMatrix();
        glPopMatrix();

        //立方体影
        glPushMatrix();
        gluLookAt(0.0, 0.0, 0.0,
            0.0, -10, 1.0,
            0.0, 1.0, 0.0);
        glPushMatrix();
        glTranslatef(0.5, 1.0, 0.0);
        glRotatef(1.4*theta, 0.0, -0.5, 0.0);
        glColor3f(0.2, 0.2, 0.2);
        glutSolidCube(0.17); // サイズ1の立方体を描画 
        glPopMatrix();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(-dist3 + 1.2, -0.1, 0.0);
        glRotatef(20 * theta, 0, 1.0, 0.0);
        glColor3f(0.2, 0.1, 0.4);
        glutWireSphere(0.5, 40, 40); /*球*/
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.6 * dist3 + 4.5, -0.6, 0.0);
        glRotatef(20 * theta, 0.4, 1.0, 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glutWireSphere(0.2, 40, 40); /*球*/
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-2.7*dist3 + 3.2, -0.1, 0.0);
        glRotatef(20 * theta, 1.0, 1.0, 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glutWireSphere(0.15, 40, 40); /*球*/
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.8 * dist3 + 2.5, 0.5, 0.0);
        glRotatef(20 * theta, 0, 1.0, 0.0);
        glColor3f(0.4, 1.0, 0.0);
        glutWireSphere(0.3, 40, 40); /*球*/
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-2.1*dist3 + 5.6, 0.1, 0.0);
        glRotatef(20 * theta, 1.0, 1.0, 0.0);
        glColor3f(0.1, 0.3, 0.3);
        glutWireSphere(0.15, 40, 40); /*球*/
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.2 * dist3 + 6.1, -0.7, 0.0);
        glRotatef(20 * theta, 0, 1.0, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glutWireSphere(0.3, 40, 40); /*球*/
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3.4*dist3 + 6.5, 0.0, 0.0);
        glRotatef(20 * theta, 1.0, 1.0, 0.0);
        glColor3f(0.8, 1.0, 1.0);
        glutWireSphere(0.25, 40, 40); /*球*/
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3.7 * dist3 + 7.0, -0.4, 0.0);
        glRotatef(20 * theta, 0, 1.0, 0.0);
        glColor3f(0.4, 0.8, 0.1);
        glutWireSphere(0.2, 40, 40); /*球*/
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-4.1*dist3 + 3.2, -0.7, 0.0);
        glRotatef(20 * theta, 1.0, 1.0, 0.0);
        glColor3f(0.0, 0.1, 0.4);
        glutWireSphere(0.15, 40, 40); /*球*/
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3.8 * dist3 + 2.5, 0.5, 0.0);
        glRotatef(20 * theta, 0, 1.0, 0.0);
        glColor3f(0.4, 0.1, 0.7);
        glutWireSphere(0.3, 40, 40); /*球*/
        glPopMatrix();

    }




    // 線を描画
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex3f(startX, startY,-0.3);
    glVertex3f(endX, endY,-0.3);
    glEnd();

    // 線2を描画
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start2X, start2Y);
    glVertex2f(end2X, end2Y);
    glEnd();


    // 線3を描画
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start3X, start3Y);
    glVertex2f(end3X, end3Y);
    glEnd();

    // 線4を描画
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start4X, start4Y);
    glVertex2f(end4X, end4Y);
    glEnd();

    // 線5を描画
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start5X, start5Y);
    glVertex2f(end5X, end5Y);
    glEnd();

    // 線6を描画
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start6X, start6Y);
    glVertex2f(end6X, end6Y);
    glEnd();

    // 線7を描画
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start7X, start7Y);
    glVertex2f(end7X, end7Y);
    glEnd();

    // 線8を描画
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start8X, start8Y);
    glVertex2f(end8X, end8Y);
    glEnd();

    // 線9を描画
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start9X, start9Y);
    glVertex2f(end9X, end9Y);
    glEnd();

    // 線10を描画
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start10X, start10Y);
    glVertex2f(end10X, end10Y);
    glEnd();

    // 線11を描画
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start11X, start11Y);
    glVertex2f(end11X, end11Y);
    glEnd();

    // 線12を描画
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start12X, start12Y);
    glVertex2f(end12X, end12Y);
    glEnd();

    // 線13を描画
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start13X, start13Y);
    glVertex2f(end13X, end13Y);
    glEnd();

    // 線14を描画
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start14X, start14Y);
    glVertex2f(end14X, end14Y);
    glEnd();


    // 判定点を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 0.0f); // 赤色
    glVertex2f(x, y);
    glEnd();



    //ここからノーツの描画↓↓


    // ノーツ1を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 赤色
    glVertex2f(startX, endY - 2.9f);
    glEnd();
    // ノーツ2を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(startX, endY - 2.23f);
    glEnd();
    // ノーツ3を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(startX, endY -1.55f);
    glEnd();
    //ノーツ4を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(startX, endY - 1.2f);
    glEnd();
    //ノーツ5を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(startX, endY - 0.85f);
    glEnd();
    //ノーツ6を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(startX, endY - 0.2f);
    glEnd();
    //ノーツ7を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start2X - 0.35f, end2Y);
    glEnd();
    //ノーツ8を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start3X, end3Y - 0.25f);
    glEnd();
    //ノーツ9を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start5X, start5Y);
    glEnd();
    //ノーツ9を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start5X, start5Y + 0.8f);
    glEnd();
    //ノーツ10を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(start5X, start5Y + 2.1f);
    glEnd();
    //ノーツ11を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(start5X, start5Y + 2.45f);
    glEnd();
    //ノーツ12を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(start5X, start5Y + 2.8f);
    glEnd();
    //ノーツ13を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start5X, start5Y + 3.45f);
    glEnd();
    //ノーツ14を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start5X, start5Y + 4.15f);
    glEnd();
    //ノーツ15を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start5X, start5Y + 4.85f);
    glEnd();
    //ノーツ16を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start5X, start5Y + 5.45f);
    glEnd();
    //ノーツ17を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start5X, start5Y + 6.15f);
    glEnd();
    //ノーツ18を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start5X, start5Y + 6.8f);
    glEnd();
    //ノーツ19を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start5X, start5Y + 6.95f);
    glEnd();
    //ノーツ20を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start5X, start5Y + 7.1f);
    glEnd();
    //ノーツ21を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(start5X, end5Y - 0.33f);
    glEnd();
    //ノーツ22を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(start6X, start6Y);
    glEnd();
    //ノーツ23を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(start6X + 0.3f, end6Y);
    glEnd();
    //ノーツ24を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start8X + 0.2f, start8Y);
    glEnd();
    //ノーツ25を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start8X + 0.9f, start8Y);
    glEnd();
    //ノーツ26を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start8X + 1.6f, start8Y);
    glEnd();
    //ノーツ27を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(start8X + 1.9f, start8Y);
    glEnd();
    //ノーツ28を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start8X + 2.25f, start8Y);
    glEnd();
    //ノーツ29を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start8X + 2.9f, start8Y);
    glEnd();
    //ノーツ30を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start8X + 3.6f, start8Y);
    glEnd();
    //ノーツ31を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(end8X - 0.4f,start8Y);
    glEnd();
    //ノーツ32を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(end8X , start8Y);
    glEnd();
    //ノーツ33を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(start9X , start9Y + 0.3f);
    glEnd();
    //ノーツ34を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start11X , start11Y);
    glEnd();
    //ノーツ35を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start11X + 0.7f, start11Y);
    glEnd();
    //ノーツ36を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start11X + 1.05f, start11Y);
    glEnd();
    //ノーツ37を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start11X + 1.4f, start11Y);
    glEnd();
    //ノーツ38を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start11X + 2.05f, start11Y);
    glEnd();
    //ノーツ39を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(start11X + 2.35f, start11Y);
    glEnd();
    //ノーツ40を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(end11X, start11Y);
    glEnd();
    //ノーツ41を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // 白色
    glVertex2f(end12X, start12Y - 1.14f);
    glEnd();
    //ノーツ42を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(start13X - 0.1f, start13Y);
    glEnd();
    //ノーツ43を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(start13X - 0.4f, start13Y);
    glEnd();
    //ノーツ44を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(start13X - 0.7f, start13Y);
    glEnd();
    //ノーツ45を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(start14X, start14Y);
    glEnd();
    //ノーツ46を描画
    glPointSize(18.0f); // 点のサイズを設定
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // 赤色
    glVertex2f(start14X, start14Y - 0.3f);
    glEnd();
 
    // バッファの入れ替え
    glutSwapBuffers();
}

/*イベントがなければidleがつねに実行される*/
void idle(void)
{
    if (scount >= 470 && scount <= 1000) {
        dist += 0.0005;
    }

    if (scount > 730 && scount <= 1050) {
        dist2 += 0.0012;
    }

    if (scount >= 1150 && scount <= 1550) {
        dist3 += 0.002;

    }

    if (scount >= 1136 && scount <= 1518) {
        dist4 += 0.0001;

    }
    theta = fmod(theta + 0.1, 360.0);/*回転角を０°～３６０°まで0.5°づつ増加させる）*/
    glutPostRedisplay();/*ディスプレイコールバックバック関数(display)を実行*/
}

//キーボードの処理
void myKbd(unsigned char key, int x, int y)
{
    switch (key) {
    case 'f':
        printf("\ffキーが押されました(scountの値がは%dです)\n",scount);
        break;
    case 'j':
        printf("\fjキーが押されました\n");
        break;
    }
    glutPostRedisplay();/*キー操作を描画に反映*/
}

unsigned char bitmap1[imageHeight][imageWidth] =
{
    {0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00},
    {0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00},
    {0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00},
    {0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff},
    {0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff},
    {0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff},
    {0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff}
};

unsigned char bitmap2[imageHeight][imageWidth] =
{
    {0x00,0x00,0x00,0xff,0xff,0x00,0x00,0x00},
    {0x00,0x00,0xff,0xff,0xff,0xff,0x00,0x00},
    {0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00},
    {0x00,0x00,0xff,0xff,0xff,0xff,0x00,0x00},
    {0x00,0x00,0x00,0xff,0xff,0x00,0x00,0x00}
};

void makeImage1(void)
{
    int i, j, c;

    for (i = 0; i < imageHeight; i++) {
        for (j = 0; j < imageWidth; j++) {
            c = bitmap1[i][j];
            image1[i][j][0] = (unsigned char)c;
            image1[i][j][1] = (unsigned char)c;
            image1[i][j][2] = (unsigned char)c;
            image1[i][j][3] = (unsigned char)128;
        }
    }
}

void makeImage2(void)
{
    int i, j, c;

    for (i = 0; i < imageHeight; i++) {
        for (j = 0; j < imageWidth; j++) {
            c = bitmap2[i][j];
            image2[i][j][0] = (unsigned char)c;
            image2[i][j][1] = (unsigned char)0;
            image2[i][j][2] = (unsigned char)0;
            image2[i][j][3] = (unsigned char)128;
        }
    }
}

void initTexture1(void)
{
    makeImage1();

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glBindTexture(GL_TEXTURE_2D, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, imageWidth, imageHeight, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, image1);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

}

void initTexture2(void)
{
    makeImage2();

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glBindTexture(GL_TEXTURE_2D, 2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, imageWidth, imageHeight, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, image2);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

}

void initTexture3(void)
{
    unsigned char* image3[1];
    int imageHeightb, imageWidthb;


    if (!ReadBitMapData("back.bmp", &imageWidthb, &imageHeightb, image3)) {
        printf("Error! \n");
        exit(0);
    }

    glBindTexture(GL_TEXTURE_2D, 3);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, imageWidthb, imageHeightb, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, *image3);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
}

void myInit(char* progname)
{
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(width, height);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("Music Animation");


    glClearColor(0.0, 0.0, 0.0, 1.0);

    resetview();
    initTexture1();
    initTexture2();
    initTexture3();
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHT0);
}

// ウィンドウのリサイズ処理
void resize(int w, int h) {

    float aspect = (float)width / (float)height;
    // ウィンドウ全体をビューポートにする
    glViewport(0, 0, w, h);
    // 透視投影行列を設定
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // モデルビュー行列を設定
    gluPerspective(fovy, aspect, nearw, farw);
    glMatrixMode(GL_MODELVIEW);
}

void polarview(void)
{
    glTranslatef(0.0, 0.0, -distance);

}


void resetview(void)
{
    distance = 3.0;
    twist = 0.0;
    elevation = -30.0;
    azimuth = 30.0;
}


MCIDEVICEID playSound(char* strFile)
{
    static MCI_OPEN_PARMS mop;
    mop.dwCallback = (DWORD)NULL;
    mop.lpstrDeviceType = (LPCSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;
    mop.lpstrElementName = strFile;
    mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID | MCI_OPEN_ELEMENT, (DWORD)&mop);
    mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, 0);
    return mop.wDeviceID;
}


int main(int argc, char** argv) {
    // OpenGLの初期化
    glutInit(&argc, argv);
    myInit(argv[0]);

    // 描画関数の登録
    glutDisplayFunc(display);

    //idle実行
    glutIdleFunc(idle);

    glutKeyboardFunc(myKbd);/*一般キーのコールバック関数の登録*/

    // ウィンドウのリサイズ時に呼ばれる関数の登録
    glutReshapeFunc(resize);

    // アニメーションの更新関数の登録
    glutTimerFunc(0, update, 0);

    //音源を流す
    strFile = "C:music2.WAV";
    playID[0] = playSound(strFile);


    // メインループの開始
    glutMainLoop();
}


