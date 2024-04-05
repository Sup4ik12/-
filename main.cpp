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
    HDC LU;                                                 //������ ���� �� ������
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
struct Icon
{
    int x;
    int y;
    int w;
    int h;
    HDC image;
    bool draw;

    void paint()
    {
        if(draw == true)
        {
            txTransparentBlt(txDC(),x,y,w,h,image,0,0,RGB(50,201,72));
        }
    }
};
struct dialog
{
    int x;
    int y;
    int w;
    int h;
    HDC image;
    const char* text;
    int r;
    COLORREF colorVny;
    COLORREF colorVne;

    void draw()
    {
        txBitBlt(txDC(),x,y,w,h,image);
        txSetColor(colorVne);
        txSetFillColor(colorVny);
        txSelectFont ("Comic Sans MS", r);
        txDrawText(x+20,y+25,x+w-25,y+h-100,text);
    }
};
int main()
{
    txCreateWindow (1920, 1080);
    txSetColor (TX_WHITE, 5);

    string page = "menu";

    HDC location=txLoadImage("����/����.bmp");
    HDC house=txLoadImage("����/���.bmp");
    HDC kushat=txLoadImage("����/�����.bmp");
    cat cat = {txLoadImage("cat/catR.bmp"),txLoadImage("cat/catL.bmp"),txLoadImage("cat/catU.bmp"),txLoadImage("cat/catD.bmp"),txLoadImage("cat/catRD.bmp"),txLoadImage("cat/catLD.bmp"),txLoadImage("cat/catRU.bmp"),txLoadImage("cat/catLU.bmp"),cat.R,83.3,83.3,800,425,15,cat.v/1.5,cat.v,cat.v/1.5};
    HDC granny=txLoadImage("������.bmp");
    HDC Lose=txLoadImage("�����������.bmp");
    HDC plate=txLoadImage("���������.bmp");
    HDC cat2 = txLoadImage("cat/�����.bmp");

    int xL = -50; int yL = 0;
    int nKad = 0;
    int nK = 0;
    bool popil = false;
    int r = 0.7;

    Icon c1 = {590,450,200,200,txLoadImage("������/���������.bmp"),false};
    Icon c2 = {590,450,200,200,txLoadImage("������/�����������.bmp"),true};

    dialog DI = {1,1,720,469,txLoadImage("������.bmp"),"d",50,RGB(150, 108, 33),RGB(133, 98, 37)};

    button btnSt = {500,250,150,75,"�����",TX_WHITE,TX_RED,30};
    button btnHe = {750,500,150,75,"��������",TX_WHITE,TX_RED,30};
    button btnEx = {1000,750,150,75,"����",TX_WHITE,TX_RED,30};
    button btnV1 = {850,700,200,75,"���",RGB(227, 185, 109),RGB(133, 98, 37),100};
    button btnV2 = {600,700,200,75,"*��������*",RGB(227, 185, 109),RGB(133, 98, 37),38};

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

        if(GetAsyncKeyState ('P'))
            {
               page = "exit";
            }

         //����
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
            txDrawText(500,500,1000,1000,"�� ��� ���-������");
            if( txMouseButtons() == 1 and
                btnEx.x < txMouseX() and txMouseX() < btnEx.w + btnEx.x and
                btnEx.y < txMouseY() and txMouseY() < btnEx.y + btnEx.h)
            {
                page = "menu";
            }
        }

        //����
        if(page == "street")
        {
            txBitBlt(txDC(),xL,yL,1920,1080,location);
            txTransparentBlt(txDC(),cat.x,cat.y, cat.w,cat.h,cat.image, 83.3*nKad, 0,RGB(150,150,100));
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
                    page = "�����";
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
        DI.x = 550; DI.y = 475; DI.r = 50; DI.draw(); DI.text = "������ �������, ��� �� ��� �������?";
        btnV1.draw();
        btnV2.draw();
        nKad=0;
        if( txMouseButtons() == 1 and
                btnV1.x < txMouseX() and txMouseX() < btnV1.w + btnV1.x and
                btnV1.y < txMouseY() and txMouseY() < btnV1.y + btnV1.h)
            {
                DI.draw(); DI.text = "�� ����� ��������� �����, ����� \n" "� ���� ������� �����";
                txSleep(2000);
                page = "havat";
            }
        if( txMouseButtons() == 1 and
                btnV2.x < txMouseX() and txMouseX() < btnV2.w + btnV2.x and
                btnV2.y < txMouseY() and txMouseY() < btnV2.y + btnV2.h)
            {
            DI.draw();  DI.text = "� ���� �� ������ �� ����\n" "� ���� � ���� ����������, ��� �� ����";
            nKad = 2;
            txSleep(4500);
            page = "lose";
            }
        }


        if(page == "lose")
        {
        txSetFillColor(TX_BLACK);
        txClear();
        txTransparentBlt(txDC(),200,200, 800,800,Lose, 0, 0,RGB(0,0,255));
        txSelectFont ("Comic Sans MS", 150);
        txSetColor(TX_WHITE,4);
        txTextOut(980,310,"�� ��������)");
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
                    DI.draw(); DI.text = "�� ��� �������";
                    txSleep(2500);
                    page = "street";

                }


        }
        if(page == "�����")
        {
            txBitBlt(txDC(),xL,yL,1920,1080,location);
            nKad = 0;
            txTransparentBlt(txDC(),cat.x,cat.y, cat.w,cat.h,cat.image, 83.3*nKad, 0,RGB(150,150,100));
            txTransparentBlt(txDC(),650,386,93,50,cat2,0,0,RGB(0,0,0));

            if(GetAsyncKeyState ('A') and cat.x > 820)
            {
                cat.image = cat.L;
                cat.x -= cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if (cat.x < 820)
            {
                DI.draw();  DI.text = "?"; DI.x = 800; DI.y = 475;
                c1.paint(); c2.paint(); c1.draw = false; c2.draw = true;
                txSleep(750);
                DI.draw(); DI.text = "�� ������ ���� ����� ���������, \n" "����� ���������� ����� �� ���� ���";
                txSleep(1999);
                DI.draw();
            }
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
txDeleteDC(DI.image);
txDeleteDC(granny);
txDeleteDC(Lose);
txDeleteDC(plate);
txDeleteDC(kushat);
txDeleteDC(cat2);
txDeleteDC(c1.image);
txDeleteDC(c2.image);
txDisableAutoPause();
txTextCursor (false);
return 0;
}
