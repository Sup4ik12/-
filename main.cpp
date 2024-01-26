#include "TXLib.h"

struct Cat
{
    HDC R;
    HDC L;
    HDC U;
    HDC D;
    HDC RD;
    HDC LD;
    HDC RU;
    HDC LU;
    HDC image;
    int w;
    int h;
    int x;
    int y;
    int z;
};
int main()
{
txCreateWindow (1920, 1080);

    txSetColor (TX_WHITE, 5);
    HDC carR =txLoadImage("car/áèáèêàRIGHT.bmp");
    HDC carU =txLoadImage("car/áèáèêàUP.bmp");
    HDC carD =txLoadImage("car/áèáèêàDOWN.bmp");
    HDC carL =txLoadImage("car/áèáèêàLEFT.bmp");
    HDC location=txLoadImage("ëîêà.bmp");
    HDC catR = txLoadImage("catR.bmp");
    HDC catRD = txLoadImage("catRD.bmp");
    HDC cat = catR;

    Cat cat = {txLoadImage("catR.bmp"),};

    int xCat = 100; int Vcat = 15; int yCat = 100;
    int xL = 0; int yL = 0;
    int nKad = 0;

     if (cat == carR|| cat == carL )
        {
            txTransparentBlt (txDC(), xCat, yCat, 190, 95, cat, 0, 0, TX_WHITE);
        }
    else if (cat == carU || cat == carD )
        {
            txTransparentBlt (txDC(), xCat, yCat, 95, 190, cat, 0, 0, TX_WHITE);
        }


    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txBitBlt(txDC(),xL,yL,4860,2896,location);
        txBegin();
        txSetFillColor (TX_WHITE);

        txTransparentBlt(txDC(),xCat,yCat, 150,121,cat, 150*nKad, 0,RGB(150,150,100));


        if(GetAsyncKeyState ('W'))
        {
           cat=carU;
           yCat -= Vcat;
           yL += Vcat;
        }
        if(GetAsyncKeyState ('S'))
        {
            cat = carD;
            yCat = yCat + Vcat;
              yL -= Vcat;
        }
        if(GetAsyncKeyState ('A'))
        {
            cat = carL;
            xCat = xCat - Vcat;
            xL+=Vcat;
        }
        if(GetAsyncKeyState ('D'))
        {
            cat = catR;
            xCat +=Vcat;
            xL-=Vcat;
            nKad += 1;
            if (nKad>=3) nKad=0;
        }
        if(GetAsyncKeyState ('D') and GetAsyncKeyState ('S'))
        {
            cat = catRD ;
            xCat +=0.5*Vcat;
            yCat +=0.5*Vcat;
            xL-=Vcat;
            nKad += 1;
            if (nKad>=3) nKad=0;
        }
        txEnd();
        txSleep(10);
    }
txDeleteDC(cat);
txDeleteDC(carU);
txDeleteDC(carD);
txDeleteDC(carL);
txDeleteDC(carR);
txDeleteDC(location);
txDisableAutoPause();
txTextCursor (false);
return 0;
}
