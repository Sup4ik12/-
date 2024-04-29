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
        if(draw)
        {
            txTransparentBlt(txDC(),x,y,w,h,image,0,0,RGB(50,201,72));
        }
        else
        {
            txTransparentBlt(txDC(),x,y,w,h,image,200,0,RGB(50,201,72));
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
        txSetColor(colorVne);
        txSetFillColor(colorVny);
        txBitBlt(txDC(),x,y,w,h,image);
        txSelectFont ("Comic Sans MS", r);
        txDrawText(x+20,y+25,x+w-25,y+h-100,text);
    }
};
struct gran
{
    int x;
    int y;
    int w;
    int h;
    int n;
    HDC image;
    void draw()
    {
        txTransparentBlt(txDC(),x,y, w,h,image, w*n, 0,RGB(150,150,150));
    }
};
struct hpBar
{
    int x;
    int y;
    HDC image;
    int w;
    int h;
    int hp;
    void draw()
    {
        char str[50];
        sprintf(str,"%d",hp);
        txTransparentBlt(txDC(),x,y, w,h,image, 0, 0,TX_WHITE);
        txSetColor(RGB(201,16,16));
        txSetFillColor(RGB(234,19,19));
        txRectangle(x+92,y+17,x+92+hp*2.6,y+83);
        txSetColor(RGB(26,2,7));
        txSetFillColor(RGB(26,2,7));
        txSelectFont ("Bahnschrift", 45);
        txDrawText(x+25,y+27,x+83,y+66,str);
    }
};
struct Prizrak
{
    int x;
    int y;
    int w;
    int h;
    HDC L;
    HDC R;
    HDC image;
    int n;
    int x1;
    int y1;
    int t;
    int v;
    void draw()
    {
        int vx = (abs(x1-x))/t;
        int vy = (abs(y1-y))/t;
        txTransparentBlt(txDC(),x,y, w,h,image, w*n, 0,RGB(34,177,76));
        if(x1 > x and y1 > y)
        {
            image = R;
            x += vx;
            y += vy;
            n += 1;
            if (n>=4) n=0;
        }
        if(x1 > x and y1 < y)
        {
            image = R;
            x += vx;
            y -= vy;
            n += 1;
            if (n>=4) n=0;
        }
        if(x1 < x and y1 > y)
        {
            image = L;
            x -= vx;
            y += vy;
            n += 1;
            if (n>=4) n=0;
        }
        if(x1 < x and y1 < y)
        {
            image = L;
            x -= vx;
            y -= vy;
            n += 1;
            if (n>=4) n=0;
        }
        if(abs(x1-x)<= 400)
        {
            vx = v;
        }
        if(abs(y1-y) <= 400)
        {
            vy = v;
        }


    }
};
struct plant
{
    int x;
    int y;
    int w;
    int h;
    HDC image;
    int x1;
    int y1;
    int w1;
    int h1;
    int mouse;
    int n;

    void draw()
    {
        if((x1+30<x+w) and
            (x1+w1-30>x) and
            (y1+30<y+h) and
            (y1+h1-30>y) and
            (mouse == 1))
        {
            txTransparentBlt(txDC(),x-10000,y, w,h,image, 0, 0,RGB(0,0,255));
        }
        else
        {
            txTransparentBlt(txDC(),x,y, w,h,image, 0, 0,RGB(0,0,255));
        }
    }
};

int main()
{
    txCreateWindow (1920, 1080);
    txSetColor (TX_WHITE, 5);

    string page = "menu";

    //локации
    HDC location=txLoadImage("лока/лока.bmp");
    HDC house=txLoadImage("лока/дом.bmp");
    HDC kushat=txLoadImage("лока/кушац.bmp");
    HDC kv1=txLoadImage("лока/квест1.bmp");
    HDC end1 = txLoadImage("лока/конец1.bmp");

    //персонажи
    cat cat = {txLoadImage("cat/catR.bmp"),txLoadImage("cat/catL.bmp"),txLoadImage("cat/catU.bmp"),txLoadImage("cat/catD.bmp"),txLoadImage("cat/catRD.bmp"),txLoadImage("cat/catLD.bmp"),txLoadImage("cat/catRU.bmp"),txLoadImage("cat/catLU.bmp"),cat.R,83.3,83.3,800,425,15,cat.v/1.5,cat.v,cat.v/1.5};
    HDC cat2 = txLoadImage("cat/кошка.bmp");
    HDC sleep = txLoadImage("cat/sleep.bmp");
    gran G = {150,450,350,350,0,txLoadImage("бабуля.bmp")};
    Prizrak ghost = {250,250,107.75,120,txLoadImage("ghost/ghostL.bmp"),txLoadImage("ghost/ghostR.bmp"),ghost.R,0,cat.x,cat.y,9,1};
    Prizrak ghost1 = {1500,250,107.75,120,txLoadImage("ghost/ghostL.bmp"),txLoadImage("ghost/ghostR.bmp"),ghost.R,0,cat.x,cat.y,10,2};
    Prizrak ghost2 = {750,800,107.75,120,txLoadImage("ghost/ghostL.bmp"),txLoadImage("ghost/ghostR.bmp"),ghost.R,0,cat.x,cat.y,6,2.5};

    //концовки
    HDC Lose=txLoadImage("концовки/котПлакПлак.bmp");
    HDC Victory=txLoadImage("концовки/котУраУра.bmp");
    HDC Alone=txLoadImage("концовки/котХныкХнык.bmp");

    //прочее
    HDC plate=txLoadImage("тарелочка.bmp
    Icon c1 = {590,450,200,200,txLoadImage("иконки/котИконка.bmp"),true};
    Icon c2 = {590,450,200,175,txLoadImage("иконки/кошкаИконка.bmp"),true};
    dialog DI = {1,1,720,469,txLoadImage("диалог.bmp"),"d",50,RGB(150, 108, 33),RGB(133, 98, 37)};
    hpBar helf = {210,850,txLoadImage("hpBar.bmp"),373,100,30};
    button btnSt = {500,250,150,75,"СТАРТ",TX_WHITE,TX_RED,30};
    button btnHe = {750,500,150,75,"ПАМАГИТЕ",TX_WHITE,TX_RED,30};
    button btnEx = {1000,750,150,75,"УЙТИ",TX_WHITE,TX_RED,30};
    button btnV1 = {850,700,200,75,"МЯУ",RGB(227, 185, 109),RGB(133, 98, 37),100};
    button btnV2 = {600,700,200,75,"*ЗАШИПЕТЬ*",RGB(227, 185, 109),RGB(133, 98, 37),38};

    //растения


    int xL = 0; int yL = 0;
    int nKad = 0;
    int nK = 0;
    int da = 0;
    bool popil = false;
    bool sten = false;
    int kadr = 0;
    int time = 600;
    bool kvest = false;
    bool fight = false;
    bool vibor = false;

    char str[50];


    char a[50];
    char b[50];
    cat.drawCat();

    while (page != "exit")
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txBegin();
        txSetFillColor (TX_WHITE);

        if(helf.hp == 0)
        {
            txSleep(2000);
            page = "lose";
        }

        if(GetAsyncKeyState ('P'))
            {
               page = "exit";
            }

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
            helf.draw();
            if(GetAsyncKeyState ('T'))
            {
                ghost.x = 1000;
                ghost.y = 750;
                fight = true;
            }
            if(GetAsyncKeyState ('F'))
            {
                fight = false;
            }
            if(GetAsyncKeyState ('L') and GetAsyncKeyState ('O'))
            {
                time = 1;
            }
            txTransparentBlt(txDC(),cat.x,cat.y, cat.w,cat.h,cat.image, 83.3*nKad, 0,RGB(150,150,100));
            if(GetAsyncKeyState ('W') and !GetAsyncKeyState ('D') and !GetAsyncKeyState ('A'))
            {
                cat.image=cat.U;
                cat.y -= cat.v;
                ghost.x1 = cat.x;
               ghost.y1 = cat.y;
                ghost1.x1 = cat.x;
               ghost1.y1 = cat.y;
                ghost2.x1 = cat.x;
               ghost2.y1 = cat.y;
               nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('S') and !GetAsyncKeyState ('D') and !GetAsyncKeyState ('A'))
            {
                cat.image = cat.D;
                cat.y += cat.v;
                ghost.x1 = cat.x;
               ghost.y1 = cat.y;
                ghost1.x1 = cat.x;
               ghost1.y1 = cat.y;
                ghost2.x1 = cat.x;
               ghost2.y1 = cat.y;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('A') and !GetAsyncKeyState ('S') and !GetAsyncKeyState ('W'))
            {
                cat.image = cat.L;
                cat.x -= cat.v;
                ghost.x1 = cat.x;
               ghost.y1 = cat.y;
                ghost1.x1 = cat.x;
               ghost1.y1 = cat.y;
                ghost2.x1 = cat.x;
               ghost2.y1 = cat.y;
                nKad += 1;
                if (nKad>=3) nKad=0;

            }
            if(GetAsyncKeyState ('D') and !GetAsyncKeyState ('S') and !GetAsyncKeyState ('W'))
            {
                cat.image = cat.R;
                cat.x += cat.v;
                ghost.x1 = cat.x;
               ghost.y1 = cat.y;
                ghost1.x1 = cat.x;
               ghost1.y1 = cat.y;
                ghost2.x1 = cat.x;
               ghost2.y1 = cat.y;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('D') and GetAsyncKeyState ('S'))
            {
                cat.image = cat.RD;
                cat.x += cat.v;
                cat.y += cat.v;
                ghost.x1 = cat.x;
               ghost.y1 = cat.y;
                ghost1.x1 = cat.x;
               ghost1.y1 = cat.y;
                ghost2.x1 = cat.x;
               ghost2.y1 = cat.y;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('D') and GetAsyncKeyState ('W'))
            {
                cat.image = cat.RU ;
                cat.x += cat.v;
                cat.y -= cat.v;
                ghost.x1 = cat.x;
               ghost.y1 = cat.y;
                ghost1.x1 = cat.x;
               ghost1.y1 = cat.y;
                ghost2.x1 = cat.x;
               ghost2.y1 = cat.y;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('A') and GetAsyncKeyState ('S'))
            {
                cat.image = cat.LD ;
                cat.x -= cat.v;
                cat.y += cat.v;
                ghost.x1 = cat.x;
               ghost.y1 = cat.y;
                ghost1.x1 = cat.x;
               ghost1.y1 = cat.y;
                ghost2.x1 = cat.x;
               ghost2.y1 = cat.y;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }
            if(GetAsyncKeyState ('A') and GetAsyncKeyState ('W'))
            {
                cat.image = cat.LU ;
                cat.x -= cat.v;
                cat.y -= cat.v;
                ghost.x1 = cat.x;
               ghost.y1 = cat.y;
                ghost1.x1 = cat.x;
               ghost1.y1 = cat.y;
                ghost2.x1 = cat.x;
               ghost2.y1 = cat.y;
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
            if(sten == true)
            {
                popil = false;
            }
            if(fight == true and time !=0)
            {
                ghost.draw();
                ghost1.draw();
                ghost2.draw();
                txSetColor(TX_WHITE);
                time -= 1;
                txSelectFont ("Comic Sans MS", 50);
                sprintf(str,"0:%d",time/10);
                txTextOut(340,240,str);

                if (((cat.x+30<ghost.x+ghost.w) &&
                    (cat.x+cat.w-30>ghost.x) &&
                    (cat.y+30<ghost.y+ghost.h) &&
                    (cat.y+cat.h-30>ghost.y)) or
                    ((cat.x+30<ghost1.x+ghost1.w) &&
                    (cat.x+cat.w-30>ghost1.x) &&
                    (cat.y+30<ghost1.y+ghost1.h) &&
                    (cat.y+cat.h-30>ghost1.y)) or
                    ((cat.x+30<ghost2.x+ghost2.w) &&
                    (cat.x+cat.w-30>ghost2.x) &&
                    (cat.y+30<ghost2.y+ghost2.h) &&
                    (cat.y+cat.h-30>ghost2.y)))
                {
                    helf.hp -= 1;
                }
            }
            if(fight == true and time <= 0)
            {
                txBitBlt(txDC(),0,0,1920,1080,end1);
                txTransparentBlt(txDC(),830,400, 886,600,sleep, 886*da, 0,RGB(150,150,100));
                time -= 1;
                da += 1;
                txSleep(150);
                if(da>3)
                {
                    da = 0;
                }
                if(time <= -50)
                {
                    page = "alone";
                }

            }

            int x = txMouseX();
            int y = txMouseY();
            sprintf(a,"%d",x);
            sprintf(b,"%d",y);
            txTextOut(500,400,a);
            txTextOut(500,420,b);

        }

        if(page == "dom")
        {
            if (sten == false)
            {
                txBitBlt(txDC(),0,0,1920,1080,house);
                G.draw();
                DI.x = 550; DI.y = 475; DI.r = 50; DI.text = "Привет котенок, что ты тут делаешь?"; DI.draw();
                btnV1.draw();
                btnV2.draw();
                nKad=0;
                if( txMouseButtons() == 1 and
                        btnV1.x < txMouseX() and txMouseX() < btnV1.w + btnV1.x and
                        btnV1.y < txMouseY() and txMouseY() < btnV1.y + btnV1.h)
                    {
                        DI.text = "Ой какой миленький котик, давай \n" "я тебе молочка налью";  DI.draw();
                        G.n = 2;
                        txSleep(2000);
                        page = "havat";
                    }
                if( txMouseButtons() == 1 and
                        btnV2.x < txMouseX() and txMouseX() < btnV2.w + btnV2.x and
                        btnV2.y < txMouseY() and txMouseY() < btnV2.y + btnV2.h)
                    {
                        DI.text = "С ЧЕГО ТЫ ШИПИШЬ НА МЕНЯ\n" "А ЕСЛИ У ТЕБЯ БЕШЕННОСТЬ, КЫШ ОТ СЮДА"; DI.draw();
                        G.n = 1;
                        txSleep(4500);
                        helf.hp = 0;
                    }
            }
            if(sten == true and page == "dom" and kvest == false and fight == false)
            {
                txBitBlt(txDC(),0,0,1920,1080,house);
                G.n = 0; G.draw();
                DI.x = 550; DI.y = 475; DI.r = 50;
                DI.text = "Чего вернулся, только поел жe";  DI.draw();
                txSleep(1900);
                DI.text = "."; DI.draw();
                txSleep(750);
                DI.text = ".."; DI.draw();
                txSleep(750);
                DI.text = "..."; DI.draw();
                txSleep(750);
                DI.text = "...."; DI.draw();
                txSleep(750);
                DI.text = "Aaaa, ты поселиться чтоли хочешь\n" "ко мне?"; DI.draw();
                vibor = true;
                while (vibor == true)
                {
                    txBegin();
                    txBitBlt(txDC(),0,0,1920,1080,house);
                    DI.draw();
                    c1.x = 340; c1.draw = true; c1.paint();
                    btnV1.text = "кивнуть"; btnV2.text = "убежать"; btnV1.r = 50; btnV2.r = 50; btnV1.draw(); btnV2.draw();
                    if( txMouseButtons() == 1 and
                        btnV1.x < txMouseX() and txMouseX() < btnV1.w + btnV1.x and
                        btnV1.y < txMouseY() and txMouseY() < btnV1.y + btnV1.h)
                    {
                        c1.draw = false;
                        G.x = 150; G.draw();
                        DI.text = "Ко мне просто так не заселиться \n" "тебе предстоит пройти испытания"; DI.draw();
                        txSleep(3500);
                        DI.text = "Ну, приступим"; DI.draw();
                        txSleep(2500);
                        DI.text = "первым испытанием будет"; DI.draw();
                        txSleep(2500);
                        DI.text = "СБОР УРОЖАЯ"; DI.draw();
                        txSleep(1500);
                        DI.text = "Пойдем за мной"; DI.draw();
                        txSleep(2500);
                        kvest = true;
                        vibor = false;
                        page = "kvest1";

                    }
                    if( txMouseButtons() == 1 and
                        btnV2.x < txMouseX() and txMouseX() < btnV2.w + btnV2.x and
                        btnV2.y < txMouseY() and txMouseY() < btnV2.y + btnV2.h)
                    {
                        c1.draw = false;
                        G.x = 150; G.draw();
                        DI.text = "А, просто встретится. Ну ладно \n" "иди гуляй"; DI.draw();
                        txSleep(2500);
                        fight = true;
                        vibor = false;
                        page = "street";
                    }
                    txEnd();
                    txSleep(10);
                }
            }
        }


        if(page == "lose")
        {
            txSetFillColor(TX_BLACK);
            txClear();
            txTransparentBlt(txDC(),200,200, 800,800,Lose, 0, 0,RGB(0,0,255));
            txSelectFont ("Comic Sans MS", 150);
            txSetColor(TX_WHITE,4);
            txTextOut(980,310,"Ты проиграл!(");
            txSleep(4000);
            page = "exit";
        }
        if(page == "victory")
        {
            txSetFillColor(TX_BLACK);
            txClear();
            txTransparentBlt(txDC(),200,200, 800,800,Victory, 0, 0,RGB(0,255,0));
            txSelectFont ("Comic Sans MS", 150);
            txSetColor(TX_WHITE,4);
            txTextOut(980,310,"Ты выиграл!)");
            txSleep(4000);
            page = "exit";
        }
        if(page == "alone")
        {
            txSetFillColor(TX_BLACK);
            txClear();
            txTransparentBlt(txDC(),200,200, 800,800,Alone, 0, 0,RGB(255,0,0));
            txSelectFont ("Comic Sans MS", 40);
            txSetColor(TX_WHITE,4);
            txDrawText(980,310,1500,800,"Ты по прежнему выиграл\n" "к тебе перестали приставать\n" "призраки, но ты остался один, совсем один..." );
            txSleep(10000);
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
                    G.draw();
                    DI.text = "Ну иди погуляй"; DI.draw();
                    txSleep(2500);
                    page = "street";
                    helf.hp = 100;

                }


        }
        if(page == "сцена")
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

            if (cat.x < 820 and kadr == 0)
            {
                DI.text = "?"; DI.x = 800; DI.y = 475;  DI.draw();
                c2.paint();
                txSleep(1000);
                DI.text = "Ты должно быть здесь новенький, \n" "такой расскраски котов не было еще"; DI.draw();
                txSleep(3999);
                kadr = 1;
            }
            if(kadr == 1)
            {
                txClear();
                txBitBlt(txDC(),xL,yL,1920,1080,location);
                txTransparentBlt(txDC(),cat.x,cat.y, cat.w,cat.h,cat.image, 83.3*nKad, 0,RGB(150,150,100));
                txTransparentBlt(txDC(),650,386,93,50,cat2,0,0,RGB(0,0,0));
                c1.paint();
                DI.text = "Ага, не успел осмотреться \n" "уже бабушка какая-то покормила"; DI.draw();
                txSleep(3999);
                kadr = 2;
            }
            if(kadr == 2)
            {
                c2.paint();
                DI.text = "О, это наша кормилица, она всех котят кормит.\n" "Кстати, тебе нужно найти укрытие к вечеру, по ночам у нас опасно коты бездомные ходят. \n " " Иди сходи к бабуле, может к ней получится поселиться"; DI.draw();
                txSleep(4500);
                sten = true;
            }
            if (sten == true)
            {
                page = "street";
            }
        }
        if(page == "kvest1")
        {
        txBitBlt(txDC(),0,0,1920,1080,kv1);

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
txDeleteDC(G.image);
txDeleteDC(Lose);
txDeleteDC(plate);
txDeleteDC(kushat);
txDeleteDC(cat2);
txDeleteDC(c1.image);
txDeleteDC(c2.image);
txDeleteDC(helf.image);
txDeleteDC(ghost.L);
txDeleteDC(ghost.R);
txDeleteDC(ghost.image);
txDeleteDC(Victory);
txDeleteDC(Alone);
txDisableAutoPause();
txTextCursor (false);
return 0;
}
