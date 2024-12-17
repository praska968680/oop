#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
int main(){
//matrix A1
int A1[3][3];
int tx, ty;
cout<<"Enter values of tx and ty (translating factor):";
cin>>tx>>ty;
A1[0][0]= A1[1][1]= A1[2][2]= 1;
A1[0][1]= A1[0][2]= A1[1][0]= A1[1][2]= 0;
A1[2][0]= tx;
A1[2][1]= ty;
cout << "Matrix A1:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << A1[i][j] << " ";
        }
        cout << endl;
    }
    //matrix A3
    float A3[3][3];
float A;
cout<<"Enter values of A (angle for rotation)";
cin>>A;
A3[2][0]= A3[2][1]= A3[0][2]= A3[1][2]= 0;
A3[2][2]= 1;
A3[0][0]= cos(A*(3.142/180));
A3[0][1]= sin(A*(3.142/180));
A3[1][1]= cos(A*(3.142/180));
A3[1][0]= -sin(A*(3.142/180));
cout << "Matrix A3:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << A3[i][j] << " ";
        }
        cout << endl;
    }
    //matrix A4
    float A4[3][3];
A4[2][0]= A4[2][1]= A4[0][2]= A4[1][2]= 0;
A4[2][2]= 1;
A4[0][0]= cos(A*(3.142/180));
A4[0][1]= -sin(A*(3.142/180));
A4[1][1]= cos(A*(3.142/180));
A4[1][0]= sin(A*(3.142/180));
cout << "Matrix A4:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << A4[i][j] << " ";
        }
        cout << endl;
    }
    //matrix A2
int A2[3][3];
float sx, sy;
cout<<"Enter values of sx and sy (scaling factor):";
cin>>sx>>sy;
A2[2][0]= A2[2][1]= A2[0][1]= A2[0][2]= A2[1][0]= A2[1][2]= 0;
A2[2][2]= 1;
A2[0][0]= sx;
A2[1][1]= sy;
cout << "Matrix A:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << A2[i][j] << " ";
        }
        cout << endl;
    }
    //matrix B
    int B[4][3]={0};
int x1, y1, x2, y2, x3, y3, x4, y4;
cout<<"Enter values of x1 and y1: (square coordinates)";
cin>>x1>>y1;
cout<<"Enter values of x2 and y2:";
cin>>x2>>y2;
cout<<"Enter values of x3 and y3:";
cin>>x3>>y3;
cout<<"Enter values of x4 and y4:";
cin>>x4>>y4;
B[0][0]=x1;
B[0][1]=y1;
B[1][0]=x2;
B[1][1]=y2;
B[2][0]=x3;
B[2][1]=y3;
B[3][0]=x4;
B[3][1]=y4;
B[0][2]= B[1][2]= B[2][2]= B[3][2]= 1;
cout << "Matrix B:" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    //matrix C translation
    int C[4][3]={0};
    for(int i=0; i<4; i++){
    for(int j=0; j<3; j++){
    C[i][j]=B[i][0]*A1[0][j]+B[i][1]*A1[1][j]+B[i][2]*A1[2][j];
}
}
cout<<"Matrix C:"<< endl;
for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    //matrix D scaling
    int D[4][3]={0};
    for(int i=0; i<4; i++){
    for(int j=0; j<3; j++){
    D[i][j]=B[i][0]*A2[0][j]+B[i][1]*A2[1][j]+B[i][2]*A2[2][j];
}
}
cout<<"Matrix D:"<< endl;
for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }   
int op;
cout<<"Enter option:" ;
cin>>op;
int E[4][3]={0};
int F[4][3]={0};
    switch(op){
case 1:
//matrix E rotation clock
    for(int i=0; i<4; i++){
    for(int j=0; j<3; j++){
    E[i][j]=B[i][0]*A3[0][j]+B[i][1]*A3[1][j]+B[i][2]*A3[2][j];
}
}
cout<<"Matrix E:"<< endl;
for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << E[i][j] << " ";
        }
        cout << endl;
    }
    break;
    case 2:
    //matrix F rotation anticlock
    for(int i=0; i<4; i++){
    for(int j=0; j<3; j++){
    F[i][j]=B[i][0]*A4[0][j]+B[i][1]*A4[1][j]+B[i][2]*A4[2][j];
}
}
cout<<"Matrix F:"<< endl;
for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << F[i][j] << " ";
        }
        cout << endl;
    }
break;
}
    initwindow(400,400,"Sam");
    line(B[0][0], B[0][1], B[1][0], B[1][1]);
    line(B[1][0], B[1][1], B[2][0], B[2][1]);
    line(B[2][0], B[2][1], B[3][0], B[3][1]);
    line(B[3][0], B[3][1], B[0][0], B[0][1]);
    line(C[0][0], C[0][1], C[1][0], C[1][1]);
    line(C[1][0], C[1][1], C[2][0], C[2][1]);
    line(C[2][0], C[2][1], C[3][0], C[3][1]);
    line(C[3][0], C[3][1], C[0][0], C[0][1]);
    line(D[0][0], D[0][1], D[1][0], D[1][1]);
    line(D[1][0], D[1][1], D[2][0], D[2][1]);
    line(D[2][0], D[2][1], D[3][0], D[3][1]);
    line(D[3][0], D[3][1], D[0][0], D[0][1]);
    line(E[0][0], E[0][1], E[1][0], E[1][1]);
    line(E[1][0], E[1][1], E[2][0], E[2][1]);
    line(E[2][0], E[2][1], E[3][0], E[3][1]);
    line(E[3][0], E[3][1], E[0][0], E[0][1]);
    line(F[0][0], F[0][1], F[1][0], F[1][1]);
    line(F[1][0], F[1][1], F[2][0], F[2][1]);
    line(F[2][0], F[2][1], F[3][0], F[3][1]);
    line(F[3][0], F[3][1], F[0][0], F[0][1]);
    getch();
    return 0;
}
