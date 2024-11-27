#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <windows.h>



int main() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    //A, B cords
    float A =0, B=0;
    float i, j;

    int k;

    //120
    float z[1760];
    char b[1760];

    std::cout<<"\x1b[2J";

    //donut calculation
    while (true){
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for(j = 0; j<6.28; j += 0.07){
            for(i = 0; i<6.28; i += 0.02) {
                float c = sin(i), //matrix calculations
                    d = cos(j),
                    e = sin(A),
                    f = sin(j),
                    g = cos(A),
                    h = d + 2,
                    D = 1 / (c * h * e + f * g + 5),
                    l = cos(i),
                    m = cos(B),
                    n = sin(B),
                    t = c * h * g - f * e;
                
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

    std::cout<<"\x1b[H";

    for(k = 0; k<1761; k++){
        putchar(k % 80 ? b[k] : 10);
    }
    fflush(stdout);
    A += 0.03;
    B += 0.02;
    Sleep(30);
    }

    return 0;
}
