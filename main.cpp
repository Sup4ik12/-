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
    HDC LU;                                                 //¬€“¿Ÿ» ÀŒ ” »« ¿–’»¬¿
    HDC image;
    int w;
    int h;
    int x;
    int y;
    int v;
    int v1;
    int vL;
    int vL1;
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
struct button
{
  int x;
  int y;
  int w;
  int h;
  const char* text;

  void draw()
    {
     txSetColor(TX_RED);
     txSetFillColor(TX_WHITE);
     txRectangle(x,y,x+w,y+h);
     txDrawText(x, y, x+w, y+h, text);
    }
};
int main()
{
    txCreateWindow (1920, 1080);
    txSetColor (TX_WHITE, 5);

    string page = "menu";

    HDC location=txLoadImage("ÎÓÍ‡/ÎÓÍ‡.bmp");
    cat cat = {txLoadImage("cat/catR.bmp"),txLoadImage("cat/catL.bmp"),txLoadImage("cat/catU.bmp"),txLoadImage("cat/catD.bmp"),txLoadImage("cat/catRD.bmp"),txLoadImage("cat/catLD.bmp"),txLoadImage("cat/catRU.bmp"),txLoadImage("cat/catLU.bmp"),cat.R,150,150,800,425,15,cat.v/1.5,cat.v,cat.v/1.5};

    int xL = 0; int yL = 0;
    int nKad = 0;

    button btnSt = {500,250,150,75,"—“¿–“"};
    button btnHe = {750,500,150,75,"œ¿Ã¿√»“≈"};
    button btnEx = {1000,750,150,75,"”…“»"};

    cat.drawCat();

    char xC[50];
    char yC[50];
    char yM[50];
    char xM[50];


    while (page != "exit")
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txBegin();
        txSetFillColor (TX_WHITE);
         //ÏÂÌ˛
        if(page == "menu")
        {
            btnSt.draw();
            btnHe.draw();
            btnEx.draw();
            if( txMouseButtons() == 1 and
                btnSt.x < txMouseX() and txMouseX() < btnSt.w + btnSt.x and
                btnSt.y < txMouseY() and txMouseY() < btnSt.y + btnSt.h)
            {
                page = "game";
            }
            if( txMouseButtons() == 1 and
                btnHe.x < txMouseX() and txMouseX() < btnHe.w + btnHe.x and
                btnHe.y < txMouseY() and txMouseY() < btnHe.y + btnHe.h)
            {
                page = "help";
            }
            if( txMouseButtons() == 1 and
                btnEx.x < txMouseX() and txMouseX() < btnEx.w + btnEx.x and
                btnEx.y < txMouseY() and txMouseY() < btnEx.y + btnEx.h)
            {
                page = "exit";
            }
        }

        if(page == "help")
        {
            btnEx.draw();
            txDrawText(500,500,1000,1000,"ÌÛ Ò‡Ï Í‡Í-ÌË·Û‰¸");
            if( txMouseButtons() == 1 and
                btnEx.x < txMouseX() and txMouseX() < btnEx.w + btnEx.x and
                btnEx.y < txMouseY() and txMouseY() < btnEx.y + btnEx.h)
            {
                page = "menu";
            }
        }

        //Ë„‡
        if(page == "game")
        {
            txBitBlt(txDC(),xL,yL,4860,2896,location);
            txTransparentBlt(txDC(),cat.x,cat.y, cat.w,cat.h,cat.image, 150*nKad, 0,RGB(150,150,100));
            if(GetAsyncKeyState ('P'))
            {
               page = "exit";
            }

            if(xL>0)
            {
                cat.vL=0;
                cat.vL1=0;
                cat.v=15;
                cat.v1=15;
            }
            if(yL>0)
            {
                cat.vL=0;
                cat.vL1=0;
                cat.v=15;
                cat.v1=15;
            }
              if(cat.v == 15 and cat.x-xL>800 and cat.y-yL>425)
            {
                cat.v=0;
                cat.v1=0;
                cat.vL=15;
                cat.vL1=15;
            }


            if(GetAsyncKeyState ('W') and !GetAsyncKeyState ('D') and !GetAsyncKeyState ('A'))
            {
               cat.image=cat.U;
               cat.y -= cat.v;
               yL += cat.vL;
               nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('S') and !GetAsyncKeyState ('D') and !GetAsyncKeyState ('A'))
            {
                cat.image = cat.D;
                cat.y += cat.v;
                yL -= cat.vL;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('A') and !GetAsyncKeyState ('S') and !GetAsyncKeyState ('W'))
            {
                cat.image = cat.L;
                xL+=cat.vL;
                cat.x -= cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;

            }
            if(GetAsyncKeyState ('D') and !GetAsyncKeyState ('S') and !GetAsyncKeyState ('W'))
            {
                cat.image = cat.R;
                xL-=cat.vL;
                cat.x += cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('D') and GetAsyncKeyState ('S'))
            {
                cat.image = cat.RD;
                xL-=cat.vL1;
                yL -= cat.vL1;
                cat.x += cat.v;
                cat.y += cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('D') and GetAsyncKeyState ('W'))
            {
                cat.image = cat.RU ;
                xL-=cat.vL1;
                yL += cat.vL1;
                cat.x += cat.v;
                cat.y -= cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('A') and GetAsyncKeyState ('S'))
            {
                cat.image = cat.LD ;
                xL+=cat.vL1;
                yL -= cat.vL1;
                cat.x -= cat.v;
                cat.y += cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('A') and GetAsyncKeyState ('W'))
            {
                cat.image = cat.LU ;
                xL+=cat.vL1;
                yL += cat.vL1;
                cat.x -= cat.v;
                cat.y -= cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(!GetAsyncKeyState ('S') and !GetAsyncKeyState ('A') and !GetAsyncKeyState ('W') and !GetAsyncKeyState ('D'))
                {
                    nKad = 0;
                }

            sprintf(xC, "X - %d", cat.x-xL);
            sprintf(yC, "Y - %d", cat.y-yL);
            int xMouse = txMouseX();
            int yMouse = txMouseY();
            sprintf(xM, "Xm - %d", xMouse);
            sprintf(yM, "Ym - %d", yMouse);
            txSetColor(TX_WHITE,5);
            txTextOut(500,500,yC);
            txTextOut(500,470,xC);
            txTextOut(500,530,xM);
            txTextOut(500,560,yM);

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
