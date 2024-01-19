#include "TXLib.h"

int main()
{
txCreateWindow (1920, 1080);

    txSetColor (TX_WHITE, 5);
    HDC carR =txLoadImage("car/·Ë·ËÍ‡RIGHT.bmp");
    HDC carU =txLoadImage("car/·Ë·ËÍ‡UP.bmp");
    HDC carD =txLoadImage("car/·Ë·ËÍ‡DOWN.bmp");
    HDC carL =txLoadImage("car/·Ë·ËÍ‡LEFT.bmp");
    HDC car = carR;
    HDC location=txLoadImage("ÎÓÍ‡.bmp");

    int xCar = 100; int Vcar = 15; int yCar = 100;
    int xL = 0; int yL = 0;

     if (car == carR|| car == carL )
        {
            txTransparentBlt (txDC(), xCar, yCar, 190, 95, car, 0, 0, TX_WHITE);
        }
    else if (car == carU || car == carD )
        {
            txTransparentBlt (txDC(), xCar, yCar, 95, 190, car, 0, 0, TX_WHITE);
        }


    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txBitBlt(txDC(),xL,yL,4860,2896,location);
        txBegin();
        txSetFillColor (TX_WHITE);

        if(GetAsyncKeyState ('W'))
        {
           car=carU;
           yCar -= Vcar;
           yL += Vcar;
        }
        if(GetAsyncKeyState ('S'))
        {
            car = carD;
            yCar = yCar + Vcar;
              yL -= Vcar;
        }
        if(GetAsyncKeyState ('A'))
        {
            car = carL;
            xCar = xCar - Vcar;
            xL+=Vcar;
        }
        if(GetAsyncKeyState ('D'))
        {
            car = carR;
            xCar = xCar + Vcar;
            xL-=Vcar;
        }
        txEnd();
        txSleep(10);
    }
txDeleteDC(car);
txDeleteDC(carU);
txDeleteDC(carD);
txDeleteDC(carL);
txDeleteDC(carR);
txDeleteDC(location);
txDisableAutoPause();
txTextCursor (false);
return 0;
}
