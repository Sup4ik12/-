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
    HDC LU;                                                 //ВЫТАЩИ ЛОКУ ИЗ АРХИВА
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
  int colorVny;
  int colorVne;
  int r;

  void draw()
    {
     txSetColor(colorVne);
     txSetFillColor(colorVny);
     txSelectFont ("Comic Sans MS", r);
     txRectangle(x,y,x+w,y+h);
     txDrawText(x, y, x+w, y+h, text);
    }
};
int main()
{
    txCreateWindow (1920, 1080);
    txSetColor (TX_WHITE, 5);

    string page = "menu";

    HDC location=txLoadImage("лока/лока.bmp");
    HDC house=txLoadImage("лока/дом.bmp");
    HDC kushat=txLoadImage("лока/кушац.bmp");
    cat cat = {txLoadImage("cat/catR.bmp"),txLoadImage("cat/catL.bmp"),txLoadImage("cat/catU.bmp"),txLoadImage("cat/catD.bmp"),txLoadImage("cat/catRD.bmp"),txLoadImage("cat/catLD.bmp"),txLoadImage("cat/catRU.bmp"),txLoadImage("cat/catLU.bmp"),cat.R,83.3,83.3,800,425,15,cat.v/1.5,cat.v,cat.v/1.5};
    HDC granny=txLoadImage("бабуля.bmp");
    HDC dialog=txLoadImage("диалог.bmp");
    HDC Lose=txLoadImage("котПлакПлак.bmp");
    HDC plate=txLoadImage("тарелочка.bmp");
    HDC cat2 = txLoadImage("cat/кошка.bmp");
    HDC Icat = txLoadImage("иконки/котИконка.bmp");
    HDC Icat2= txLoadImage("иконки/кошкаИконка.bmp");

    int xL = -30; int yL = 0;
    int nKad = 0;
    int nK = 0;
    bool popil = false;
    int r = 0.7;


    button btnSt = {500,250,150,75,"СТАРТ",TX_WHITE,TX_RED,30};
    button btnHe = {750,500,150,75,"ПАМАГИТЕ",TX_WHITE,TX_RED,30};
    button btnEx = {1000,750,150,75,"УЙТИ",TX_WHITE,TX_RED,30};
    button btnV1 = {600,575,200,75,"МЯУ",RGB(227, 185, 109),RGB(133, 98, 37),100};
    button btnV2 = {600,700,200,75,"*ЗАШИПЕТЬ*",RGB(227, 185, 109),RGB(133, 98, 37),38};

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
         //меню
        if(page == "menu")
        {
            btnSt.draw();
            btnHe.draw();
            btnEx.draw();
            if( txMouseButtons() == 1 and
                btnSt.x < txMouseX() and txMouseX() < btnSt.w + btnSt.x and
                btnSt.y < txMouseY() and txMouseY() < btnSt.y + btnSt.h)
            {
                page = "street";
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
            txSetColor(TX_WHITE);
            txDrawText(500,500,1000,1000,"ну сам как-нибудь");
            if( txMouseButtons() == 1 and
                btnEx.x < txMouseX() and txMouseX() < btnEx.w + btnEx.x and
                btnEx.y < txMouseY() and txMouseY() < btnEx.y + btnEx.h)
            {
                page = "menu";
            }
        }

        //игра
        if(page == "street")
        {
            txBitBlt(txDC(),xL,yL,1920,1080,location);
            txTransparentBlt(txDC(),cat.x,cat.y, cat.w,cat.h,cat.image, 83.3*nKad, 0,RGB(150,150,100));
            if(GetAsyncKeyState ('P'))
            {
               page = "exit";
            }
          /*  if(xL>0)
            {
                cat.vL=0;
                cat.v=15;
                yL=0;
            }
            if(yL>0)
            {
                cat.vL1=0;
                cat.v1=15;
                yL=0;
            }

            if(cat.x-xL>800)
            {
                cat.v=0;
                cat.vL=15;
            }
            if(cat.y-yL>425)
            {
                cat.v1=0;
                cat.vL1=15;
            }    */
            if(GetAsyncKeyState ('W') and !GetAsyncKeyState ('D') and !GetAsyncKeyState ('A'))
            {
               cat.image=cat.U;
               cat.y -= cat.v;
               nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('S') and !GetAsyncKeyState ('D') and !GetAsyncKeyState ('A'))
            {
                cat.image = cat.D;
                cat.y += cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('A') and !GetAsyncKeyState ('S') and !GetAsyncKeyState ('W'))
            {
                cat.image = cat.L;
                cat.x -= cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;

            }
            if(GetAsyncKeyState ('D') and !GetAsyncKeyState ('S') and !GetAsyncKeyState ('W'))
            {
                cat.image = cat.R;
                cat.x += cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('D') and GetAsyncKeyState ('S'))
            {
                cat.image = cat.RD;
                cat.x += cat.v;
                cat.y += cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('D') and GetAsyncKeyState ('W'))
            {
                cat.image = cat.RU ;
                cat.x += cat.v;
                cat.y -= cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('A') and GetAsyncKeyState ('S'))
            {
                cat.image = cat.LD ;
                cat.x -= cat.v;
                cat.y += cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('A') and GetAsyncKeyState ('W'))
            {
                cat.image = cat.LU ;
                cat.x -= cat.v;
                cat.y -= cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(!GetAsyncKeyState ('S') and !GetAsyncKeyState ('A') and !GetAsyncKeyState ('W') and !GetAsyncKeyState ('D'))
                {
                    nKad = 0;
                }
            if (txMouseButtons() == 2 and
                1725 <= txMouseX() and txMouseX() <= 1805 and
                320 <= txMouseY() and txMouseY() <= 400 and
                1700 <= cat.x and cat.x <= 1775 and
                350 <= cat.y and cat.y <= 380)
            {
                page = "dom";
            }
            if (popil == true)
            {
                txTransparentBlt(txDC(),650,386,93,50,cat2,0,0,RGB(0,0,0));
                if(cat.x < 1130 and cat.y < 530)
                {
                    page = "сцена";
                }
            }

            sprintf(xC, "X - %d", cat.x);
            sprintf(yC, "Y - %d", cat.y);
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

        if(page == "dom")
        {
        txBitBlt(txDC(),0,0,1920,1080,house);
        txTransparentBlt(txDC(),150,450, 350,350,granny, 350*nKad, 0,RGB(150,150,150));
        txBitBlt(txDC(),550,475,720,469,dialog);
        btnV1.draw();
        btnV2.draw();
        nKad=0;
        txSetColor(RGB(133, 98, 37));
        txSetFillColor(RGB(150, 108, 33));
        txSelectFont ("Comic Sans MS", 50);
        txTextOut(570,500,"Привет котенок, что ты тут делаешь?");

        if( txMouseButtons() == 1 and
                btnV1.x < txMouseX() and txMouseX() < btnV1.w + btnV1.x and
                btnV1.y < txMouseY() and txMouseY() < btnV1.y + btnV1.h)
            {
                txBitBlt(txDC(),550,475,720,469,dialog);
                txDrawText(570,500,1250,950,"Ой какой миленький котик, давай \n" "я тебе молочка налью");
                txSleep(2000);
                page = "havat";
            }
        if( txMouseButtons() == 1 and
                btnV2.x < txMouseX() and txMouseX() < btnV2.w + btnV2.x and
                btnV2.y < txMouseY() and txMouseY() < btnV2.y + btnV2.h)
            {
            txBitBlt(txDC(),550,475,720,469,dialog);
            nKad = 2;
            txDrawText(570,500,1250,950,"С ЧЕГО ТЫ ШИПИШЬ НА МЕНЯ\n" "А ЕСЛИ У ТЕБЯ БЕШЕННОСТЬ, КЫШ ОТ СЮДА");
            txSleep(4500);
            page = "lose";
            }




        int xMouse = txMouseX();
        int yMouse = txMouseY();
        sprintf(xM, "Xm - %d", xMouse);
        sprintf(yM, "Ym - %d", yMouse);
        txTextOut(500,530,xM);
        txTextOut(500,560,yM);
        }


        if(page == "lose")
        {
        txSetFillColor(TX_BLACK);
        txClear();
        txTransparentBlt(txDC(),200,200, 800,800,Lose, 0, 0,RGB(0,0,255));
        txSelectFont ("Comic Sans MS", 150);
        txSetColor(TX_WHITE,4);
        txTextOut(980,310,"Ты проиграл)");
        txSleep(4000);
        page = "exit";
        }

        if(page == "havat")
        {
            popil = true;
            txBitBlt(txDC(),0,0,1920,1080,kushat);
            txTransparentBlt(txDC(),833,751, 375,257,plate, 375*nK, 0,RGB(0,0,255));
            if(txMouseButtons() == 1)
            {
                nK += 1;
            }
            if (nK > 4)
                {
                    txBitBlt(txDC(),0,0,1920,1080,house);
                    txTransparentBlt(txDC(),150,450, 350,350,granny, 350*nKad, 0,RGB(150,150,150));
                    txBitBlt(txDC(),550,475,720,469,dialog);
                    txTextOut(570,500,"Ну иди погуляй");
                    txSleep(2500);
                    page = "street";

                }


        }
        if(page == "сцена")
        {
            txBitBlt(txDC(),xL,yL,1920,1080,location);
            nKad = 0;
            txTransparentBlt(txDC(),cat.x,cat.y, cat.w,cat.h,cat.image, 83.3*nKad, 0,RGB(150,150,100));
            txTransparentBlt(txDC(),650,386,93,50,cat2,0,0,RGB(0,0,0));
            while (cat.x > 820)
                {
                txBegin();
                    if(GetAsyncKeyState ('A'))
                        {
                            cat.image = cat.L;
                            cat.x -= cat.v;
                            nKad += 1;
                            if (nKad>=3) nKad=0;
                        }
                txEnd();
                txSleep(10);
                }
            txBitBlt (txDC(),800,475,720,469,dialog);
            txTransparentBlt(txDC(),590,450,200,200,Icat,0,0,RGB(50,201,72));
            txTransparentBlt(txDC(),590,450,200,175,Icat2,0,0,RGB(50,201,72));
            txSetColor(RGB(133, 98, 37));
            txSetFillColor(RGB(150, 108, 33));
            txSelectFont ("Comic Sans MS", 50);
            txTextOut(570,500,"?");




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
txDeleteDC(dialog);
txDeleteDC(granny);
txDeleteDC(Lose);
txDeleteDC(plate);
txDeleteDC(kushat);
txDeleteDC(cat2);
txDeleteDC(Icat);
txDeleteDC(Icat2);
txDisableAutoPause();
txTextCursor (false);
return 0;
}
