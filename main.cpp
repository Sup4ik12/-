#include "TXLib.h"

struct cat
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
    int v;
    void drawCat()
    {
    if (image == R|| image == L )
        {
            txTransparentBlt (txDC(), x, y, w, h, image, 0, 0, TX_WHITE);
        }
    else if (image == U || image == D )
        {
            txTransparentBlt (txDC(), x, y, h, w, image, 0, 0, TX_WHITE);
        }
    }
};
int main()
{
txCreateWindow (1920, 1080);

    txSetColor (TX_WHITE, 5);
    HDC location=txLoadImage("лока.bmp");
    cat cat = {txLoadImage("cat/catR.bmp"),txLoadImage("cat/catL.bmp"),txLoadImage("cat/catU.bmp"),txLoadImage("cat/catD.bmp"),txLoadImage("cat/catRD.bmp"),txLoadImage("cat/catLD.bmp"),txLoadImage("cat/catRU.bmp"),txLoadImage("cat/catLU.bmp"),cat.R,150,150,100,100,15};

    int xL = 0; int yL = 0;
    int nKad = 0;

    cat.drawCat();

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txBitBlt(txDC(),xL,yL,4860,2896,location);
        txBegin();
        txSetFillColor (TX_WHITE);

        txTransparentBlt(txDC(),cat.x,cat.y, cat.w,cat.h,cat.image, 150*nKad, 0,RGB(150,150,100));


        if(GetAsyncKeyState ('W'))
        {
           cat.image=cat.U;
           cat.y -= cat.v;
           yL += cat.v;
           nKad += 1;
            if (nKad>=3) nKad=0;
        }
        if(GetAsyncKeyState ('S'))
        {
            cat.image = cat.D;
            cat.y+=cat.v;
              yL -= cat.v;
              nKad += 1;
            if (nKad>=3) nKad=0;
        }
        if(GetAsyncKeyState ('A'))
        {
            cat.image = cat.L;
            cat.x -=cat.v;
            xL+=cat.v;
            nKad += 1;
            if (nKad>=3) nKad=0;

        }
        if(GetAsyncKeyState ('D'))
        {
            cat.image = cat.R;
            cat.x +=cat.v;
            xL-=cat.v;
            nKad += 1;
            if (nKad>=3) nKad=0;
        }
        if(GetAsyncKeyState ('D') and GetAsyncKeyState ('S'))
        {
            cat.image = cat.RD ;
            cat.x +=0.5*cat.v;
            cat.y +=0.5*cat.v;
            xL-=cat.v;
            nKad += 1;
            if (nKad>=3) nKad=0;
        }
        if(GetAsyncKeyState ('D') and GetAsyncKeyState ('W'))
        {
            cat.image = cat.RU ;
            cat.x +=0.5*cat.v;
            cat.y -=0.5*cat.v;
            xL-=cat.v;
            nKad += 1;
            if (nKad>=3) nKad=0;
        }
        if(GetAsyncKeyState ('A') and GetAsyncKeyState ('S'))
        {
            cat.image = cat.LD ;
            cat.x -=0.5*cat.v;
            cat.y +=0.5*cat.v;
            xL-=cat.v;
            nKad += 1;
            if (nKad>=3) nKad=0;
        }
        if(GetAsyncKeyState ('A') and GetAsyncKeyState ('W'))
        {
            cat.image = cat.LU ;
            cat.x -=0.5*cat.v;
            cat.y -=0.5*cat.v;
            xL-=cat.v;
            nKad += 1;
            if (nKad>=3) nKad=0;
        }
        txEnd();
        txSleep(10);
    }
txDeleteDC(cat.image);
txDeleteDC(cat.U);
txDeleteDC(cat.D);
txDeleteDC(cat.L);
txDeleteDC(cat.R);
txDeleteDC(cat.RU);
txDeleteDC(cat.RD);
txDeleteDC(cat.LU);
txDeleteDC(cat.LD);
txDeleteDC(location);
txDisableAutoPause();
txTextCursor (false);
return 0;
}
