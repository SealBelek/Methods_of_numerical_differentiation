//
//  main.c
//  lab2
//
//  Created by barry on 26.01.2018.
//  Copyright © 2018 barry. All rights reserved.
//
#include <stdio.h>
#include <math.h>
#define X 0
#define Y 1.4142
#define X1 1

void method_euler(double, FILE*);
void method_euler_mod(double, FILE*);
void method_euler_improve(double, FILE*);
void method_runge_kutt(double, FILE*);
double f (double, double);
double f1 (double, double);
int main(void) {
    FILE *file = fopen("file.txt", "w");
    int i = 0;
    double h, step[3] = {0.5, 0.1, 0.01}, x, xP;
    for(i = 0; i < 3; i++) {
        x = X;
        h = step[i];
        fprintf(file, "h = %lf\n", h);
        xP = x + X1;
        fprintf(file, "x = ");
        while (x <= xP){
            fprintf(file, "%lf ", x);
            x += h;
        }
        fprintf(file, "\ny_e = ");
        method_euler(h, file);
        fprintf(file, "\ny_em = ");
        method_euler_mod(h, file);
        fprintf(file, "\ny_ei = ");
        method_euler_improve(h, file);
        fprintf(file, "\ny_rk = ");
        method_runge_kutt(h, file);
    }
    fclose(file);
    return 0;
}
void method_euler(double h, FILE *file) {
    
    double x = X, y = Y;
    fprintf(file, "%lf ", y);
    double xP = x + X1;
    while (x <= xP){
        y = y + h * f(x, y);
        fprintf(file, "%lf ", y);
        x += h;
    }
    fprintf(file, "\n\n");
}
void method_euler_mod(double h, FILE *file) {
    double x = X, y = Y;
    fprintf(file, "%lf ", y);
    double xP = x + X1, y1, x1;
    while (x <= xP) {
        x1 = x + h/2;
        y1 = y + h/2 * f1(x, y);
        y = y + h + f(x1, y1);
        x += h;
        fprintf(file, "%lf ", y);
    }
    fprintf(file, "\n\n");
}
void method_euler_improve(double h, FILE *file) {
    double x = X, y = Y;
    fprintf(file, "%lf ", y);
    double xP = x + X1, y1;
    while (x <= xP) {
        y1 = y+h * f1(x, y);
        x += h;
        y = y + h * ((f(x, y) + f(x+h, y1))/2);
        fprintf(file, "%lf ", y);
 }
 fprintf(file, "\n\n");
}
void method_runge_kutt(double h, FILE *file) {
    double x = X, y = Y, k1, k2, k3, k4;
    fprintf(file, "%lf ", y);
    double xP = x + X1;
    while (x <= xP) {
        k1 = f(x, y); k2 = f(x + h/2, y + h*k1/2); k3 = f(x+h/2, y+h*k2/2); k4 = f(x+h, y+h*k3);
        y = y + h/6 * (k1 + 2 * k2 + 2 * k3 + k4);
        x += h;
        fprintf(file, "%lf ", y);
    }
    fprintf(file, "\n\n");
}
double f (double x, double y) {
    return 2 * pow(x, 3) * y - 2 * y * x;
}
double f1 (double x, double y) {
    return 2 * (3 * pow(x, 2) * y + pow(x, 3) * f(x,y)) - 2 * (f(x, y) * x + y);
}




















