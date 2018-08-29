#include <allegro.h>
#include <math.h>

/** renk seçimini anlamadım 129. satır    clear_to_color ne işe yarıyor(59 ve 67. satır) neden y1 değil y1_1 440. satırı for döngüsüne alabiliriz 570. satırı for döngüsüne alabiliriz      */

void Ekran_Olustur();
void Renk_sec();
void Bitmap_yukle();
void aracsec_1();
void aracsec_2();
void Ekrani_hazirla_1();
void Ekrani_hazirla_2();
void Ekrani_hazirla_3();
void Ekrani_hazirla_4();
void Ekrani_hazirla_5();
void Ekrani_hazirla_6();
void Boyut_sec();
void Cizim_yap();


BITMAP *bmp,
       *cursor,
       *silgi,
       *araclar,
       *araclar2,
       *kalem,
       *ucgen,
       *boyakovasi,
       *kare,
       *kare_dolu,
       *cember,
       *daire,
       *cizgi,
       *ac,
       *yeni,
       *kayit,
       *cikis,
       *ana_ekran;
PALLETE pal;

int x1,x2,y1_1,y2;
int boyut;

int arac,Ana_renk,Arka_plan_renk,frame_color,cursor_x,cursor_y;


struct ilerigeri{


    BITMAP anaEkran;

    ilerigeri *ileri,*geri;



};




int main()
{
    Ekran_Olustur();

    arac=4;
    boyut=1;

    bmp=create_bitmap(900,650);
    show_mouse(screen);


    clear_to_color(bmp,makecol(255,0,0));
    Ana_renk=makecol(0,0,0);
    Arka_plan_renk=makecol(255,255,255);


    Bitmap_yukle();///Resimleri yükledik


    clear_to_color(ana_ekran,makecol(255,255,255));///Çizim Ekranını Temizledik

    while (!key[KEY_ESC])
    {
        acquire_screen();
        textprintf_centre_ex(bmp, font,30, 570, makecol(0, 0, 255),-1,"x: %d",mouse_x);
        textprintf_centre_ex(bmp, font,30, 580, makecol(0, 0, 255),-1,"y: %d",mouse_y);
        textprintf_centre_ex(bmp, font,30, 595, makecol(0, 255, 0),-1,"tool: %d",arac);
        textprintf_centre_ex(bmp, font,35, 610, makecol(255, 0, 0),-1,"boyut: %d",boyut);


        Ekrani_hazirla_1();
        Ekrani_hazirla_2();
        Ekrani_hazirla_3();
        Ekrani_hazirla_4();
        Ekrani_hazirla_5();
        Ekrani_hazirla_6();



        textprintf_centre_ex(bmp, font,30, 570, makecol(255, 255, 255),-1,"x: %d",mouse_x);
        textprintf_centre_ex(bmp, font,30, 580, makecol(255, 255, 255),-1,"y: %d",mouse_y);
        textprintf_centre_ex(bmp, font,30, 595, makecol(255, 255, 255),-1,"tool: %d",arac);
        textprintf_centre_ex(bmp, font,35, 610, makecol(255, 255, 255),-1,"boyut: %d",boyut);
        release_screen();


        if((mouse_x>78)&&(mouse_y<547))
            Cizim_yap();

        else if(mouse_x>0 && mouse_x<78 && mouse_y>215 && mouse_y<386)
            Renk_sec(); /// Renk seç

        else if(mouse_x>0 && mouse_x<78 && mouse_y>0 && mouse_y<210)
            aracsec_1();/// Sol üst malzeme kutusu

        else if(mouse_x>105 && mouse_y>550)
            aracsec_2();/// Alt malzeme kutusu

        else if(mouse_x>0 && mouse_x<78 && mouse_y>460 && mouse_y<547)
            Boyut_sec();/// Boyut seçimi

    }

    clear_keybuf();

    return 0;
}

END_OF_MAIN()




///---------------------------------Resimleri Yükleme Bölümü-----------------------------

void Bitmap_yukle ()
{

    araclar= load_bitmap("araclarbmp.bmp", NULL);
    araclar2= load_bitmap("araclar2bmp.bmp", NULL);
    silgi = load_bitmap("silgibmp.bmp", NULL);
   // araclar = load_bitmap("araclarbmp.bmp", NULL); üstte aynı satırdan var
    kalem = load_bitmap("kalembmp.bmp", NULL);
    ucgen = load_bitmap("ucgenbmp.bmp", NULL);
    boyakovasi = load_bitmap("boyakovasibmp.bmp", NULL);
    kare = load_bitmap("karebmp.bmp", NULL);
    kare_dolu = load_bitmap("karedolubmp.bmp", NULL);
    cember = load_bitmap("cemberbmp.bmp", NULL);
    daire = load_bitmap("dairebmp.bmp", NULL);
    cizgi = load_bitmap("cizgibmp.bmp", NULL);
    ac = load_bitmap("accbmp.bmp", NULL);
    kayit = load_bitmap("kayıtbmp.bmp", NULL);
    yeni = load_bitmap("yeni.bmp", NULL);
    cikis = load_bitmap("exitbmp.bmp", NULL);
    ana_ekran = load_bitmap("anaekranbmp.bmp", NULL);

}

///********************************************************************************************


/// ----------------------------------Uygulamanın Tasarım Ekranı-------------------------------

void Ekrani_hazirla_1()
{

    blit(bmp, screen,0, 0, 0, 0, 900, 650);
    blit(ana_ekran, screen,0, 0, 78, 0, 822, 547);

}

///*********************************************************************************************


///-----------------------------------Uygulamanın Araclar Ekranı---------------------------------

void Ekrani_hazirla_2()
{

    blit(araclar, bmp,       0, 0, 0,   550, 900, 100);

    hline(bmp,0,547,900,makecol(0,0,0));
    hline(bmp,0,548,900,makecol(0,0,0));
    hline(bmp,0,549,900,makecol(0,0,0));

    hline(bmp,390,550,496,makecol(0,0,0));
    hline(bmp,390,551,496,makecol(0,0,0));

    vline(bmp,76,550,650,makecol(0,0,0));
    vline(bmp,77,550,650,makecol(0,0,0));

    blit(kalem, bmp, 0, 0, 78,  562, 75, 75);
    vline(bmp,154,550,650,makecol(0,0,0));
    vline(bmp,155,550,650,makecol(0,0,0));

    blit(silgi, screen, 0, 0, 156, 562, 75, 75);
    vline(bmp,232,550,650,makecol(0,0,0));
    vline(bmp,233,550,650,makecol(0,0,0));

    blit(kare, screen, 0, 0, 234, 562, 75, 75);
    vline(bmp,310,550,650,makecol(0,0,0));
    vline(bmp,311,550,650,makecol(0,0,0));

    blit(kare_dolu, screen,  0, 0, 312, 562, 75, 75);
    vline(bmp,389,550,650,makecol(0,0,0));
    vline(bmp,390,550,650,makecol(0,0,0));
    vline(bmp,391,550,650,makecol(0,0,0));
    vline(bmp,392,550,650,makecol(0,0,0));

    rectfill(bmp, 392, 552, 492, 652, makecol(0,110,220));


    vline(bmp,493,550,650,makecol(0,0,0));
    vline(bmp,494,550,650,makecol(0,0,0));
    vline(bmp,495,550,650,makecol(0,50,0));
    vline(bmp,496,550,650,makecol(0,0,0));


    blit(ucgen, screen,      0, 0, 497, 562 , 75, 75);
    vline(bmp,573,550,650,makecol(0,0,0));
    vline(bmp,574,550,650,makecol(0,0,0));

    blit(boyakovasi, screen, 0, 0, 575, 562, 75, 75);
    vline(bmp,651,550,650,makecol(0,0,0));
    vline(bmp,652,550,650,makecol(0,0,0));

    blit(cember, screen,     0, 0, 653, 562, 75, 75);
    vline(bmp,729,550,650,makecol(0,0,0));
    vline(bmp,730,550,650,makecol(0,0,0));

    blit(daire, screen,      0, 0, 731, 562, 75, 75);
    vline(bmp,807,550,650,makecol(0,0,0));
    vline(bmp,808,550,650,makecol(0,0,0));

    blit(cizgi, screen,      0, 0, 809, 562, 90, 75);

}

///************************************************************************************


///-------------------------- Cikis, Yeni, Kayit,Kayit Acma Bölümü-------------------------------

void Ekrani_hazirla_3()
{
    blit(araclar2, bmp,       0, 0, 0,   0, 76, 547);
    vline(bmp,76,0,547,makecol(0,0,0));
    vline(bmp,77,0,547,makecol(0,0,0));
    vline(bmp,78,0,547,makecol(0,0,0));

    blit(cikis, bmp,       0, 0, 15,   0, 50, 50);
    hline(bmp,0,50,76,makecol(0,0,0));
    hline(bmp,0,51,76,makecol(0,0,0));

    blit(yeni, bmp,        0, 0, 15, 52,  50, 50);
    hline(bmp,0,103,76,makecol(0,0,0));
    hline(bmp,0,104,76,makecol(0,0,0));

    blit(ac, bmp,          0, 0, 15, 105, 50, 50);
    hline(bmp,0,156,76,makecol(0,0,0));
    hline(bmp,0,157,76,makecol(0,0,0));

    blit(kayit, bmp,       0, 0, 15, 158, 50, 50);
    hline(bmp,0,209,76,makecol(0,0,0));
    hline(bmp,0,210,76,makecol(0,0,0));

}

///***********************************************************************************************


///--------------------------------------Boyut Secim Ekranı---------------------------------------
void Ekrani_hazirla_4()
{

    hline(bmp,0,459,76,makecol(0,0,0));
    hline(bmp,0,460,76,makecol(0,0,0));

    circlefill(bmp,12,480,5,makecol(0,0,0));
    circlefill(bmp,53,480,15,makecol(0,0,0));
    circlefill(bmp,12,522,10,makecol(0,0,0));
    circlefill(bmp,53,522,20,makecol(0,0,0));

}

///*******************************************************************************************


///--------------------------------Boyut Secim Yeri------------------------------------------

void Boyut_sec()
{
    if(mouse_b==1)
    {
        if(mouse_x>0 && mouse_x<27 && mouse_y>462 && mouse_y<498)
            boyut=1;
        else if(mouse_x>27 && mouse_x<74 && mouse_y>462 && mouse_y<498)
            boyut=2;
        else if(mouse_x>0 && mouse_x<27 && mouse_y>498 && mouse_y<545)
            boyut=3;
        else if(mouse_x>27 && mouse_x<74 && mouse_y>498 && mouse_y<545)
            boyut=4;
    }


}

///***********************************************************************************************


///----------------------------------Renk Paleti Hazırlama----------------------------------------
void Ekrani_hazirla_5()
{


    rectfill(bmp, 5, 215, 35, 240, makecol(255,255,255));
    rectfill(bmp, 40, 215, 70, 240, makecol(255,0,0));

    rectfill(bmp, 5, 250, 35, 275, makecol(0,255,0));
    rectfill(bmp, 40, 250, 70, 275, makecol(0,0,255));

    rectfill(bmp, 5, 285, 35, 310, makecol(240,240,0));
    rectfill(bmp, 40, 285, 70, 310, makecol(255,0,255));

    rectfill(bmp, 5, 320, 35, 345, makecol(75,150,20));
    rectfill(bmp, 40, 320, 70, 345, makecol(225,100,20));

    rectfill(bmp, 5, 355, 35, 380, makecol(0,0,0));
    rectfill(bmp, 40, 355, 70, 380, makecol(25,150,200));


    rectfill(araclar2, 15, 390, 50, 435, Arka_plan_renk);
    rectfill(araclar2, 30, 410, 65, 455, Ana_renk);

}

///****************************************************************************************


///--------------------------------Secili Aracı Gösterme-----------------------------------

void Ekrani_hazirla_6()
{
    if(arac==4)
     blit(kalem, bmp, 0, 0, 405,  562, 75, 75);

     else if(arac==5)
     blit(silgi, bmp, 0, 0, 405,  562, 75, 75);

     else if(arac==6)
     blit(kare, bmp, 0, 0, 405,  562, 75, 75);

     else if(arac==7)
     blit(kare_dolu, bmp, 0, 0, 405,  562, 75, 75);

     else if(arac==8)
     blit(ucgen, bmp, 0, 0, 405,  562, 75, 75);

     else if(arac==9)
     blit(boyakovasi, bmp, 0, 0, 405,  562, 75, 75);

     else if(arac==10)
     blit(cember, bmp, 0, 0, 405,  562, 75, 75);

        else if(arac==11)
     blit(daire, bmp, 0, 0, 405,  562, 75, 75);

     else if(arac==12)
     blit(cizgi, bmp, 4, 0, 405,  562, 79, 75);

}

///****************************************************************************************


///---------------------------------Renk Secim Yeri----------------------------------------

void Renk_sec()
{
    if(getpixel(araclar2,mouse_x,mouse_y)!=frame_color)
        if(mouse_b==1)
            Ana_renk=getpixel(screen,mouse_x,mouse_y);
        else if(mouse_b==2)
            Arka_plan_renk=getpixel(screen,mouse_x,mouse_y);

    rectfill(araclar2, 15, 390, 50, 435, Arka_plan_renk);
    rectfill(araclar2, 30, 410, 65, 455, Ana_renk);

}

///*****************************************************************************************


///------------------------------Araclar Kullanılarak Çizim Yaptırılan Bölüm--------------------

void Cizim_yap()
{

    if (mouse_b==1)
    {
        if(arac==4)
        {
            if(boyut==1)
                circlefill(ana_ekran,mouse_x-78,mouse_y,5,Ana_renk);

            else if(boyut==2)
                circlefill(ana_ekran,mouse_x-78,mouse_y,10,Ana_renk);

            else if(boyut==3)
                circlefill(ana_ekran,mouse_x-78,mouse_y,15,Ana_renk);

            else if(boyut==4)
                circlefill(ana_ekran,mouse_x-78,mouse_y,20,Ana_renk);

        }



        else if(arac==5)
        {
            if(boyut==1)
                rectfill(ana_ekran,mouse_x-78,mouse_y,mouse_x-78+10,mouse_y+10,Arka_plan_renk);

            else if(boyut==2)
                rectfill(ana_ekran,mouse_x-78,mouse_y,mouse_x-78+17,mouse_y+17,Arka_plan_renk);

            else if(boyut==3)
                rectfill(ana_ekran,mouse_x-78,mouse_y,mouse_x-78+25,mouse_y+25,Arka_plan_renk);

            else if(boyut==4)
                rectfill(ana_ekran,mouse_x-78,mouse_y,mouse_x-78+37,mouse_y+37,Arka_plan_renk);
        }


        else if(arac==6)
        {
            x1=mouse_x;
            y1_1=mouse_y;

            while(1)
            {
                if(mouse_b!=1)
                {
                    x2=mouse_x;
                    y2=mouse_y;
                    break;
                }

            }

            if(boyut==1)
            {
                rect(ana_ekran,x1-78  ,y1_1  ,x2-78  ,y2  ,Ana_renk);
                rect(ana_ekran,x1-78+1,y1_1+1,x2-78-1,y2-1,Ana_renk);
            }


            else if(boyut==2)
            {


                rect(ana_ekran,x1-78  ,y1_1  ,x2-78  ,y2  ,Ana_renk);
                rect(ana_ekran,x1-78+1,y1_1+1,x2-78-1,y2-1,Ana_renk);
                rect(ana_ekran,x1-78+2,y1_1+2,x2-78-2,y2-2,Ana_renk);
                rect(ana_ekran,x1-78+3,y1_1+3,x2-78-3,y2-3,Ana_renk);

            }
            else if(boyut==3)
            {
                rect(ana_ekran,x1-78  ,y1_1  ,x2-78  ,y2  ,Ana_renk);
                rect(ana_ekran,x1-78+1,y1_1+1,x2-78-1,y2-1,Ana_renk);
                rect(ana_ekran,x1-78+2,y1_1+2,x2-78-2,y2-2,Ana_renk);
                rect(ana_ekran,x1-78+3,y1_1+3,x2-78-3,y2-3,Ana_renk);
                rect(ana_ekran,x1-78+4,y1_1+4,x2-78-4,y2-4,Ana_renk);
                rect(ana_ekran,x1-78+5,y1_1+5,x2-78-5,y2-5,Ana_renk);
            }

            else if(boyut==4)
            {
                rect(ana_ekran,x1-78  ,y1_1  ,x2-78  ,y2  ,Ana_renk);
                rect(ana_ekran,x1-78+1,y1_1+1,x2-78-1,y2-1,Ana_renk);
                rect(ana_ekran,x1-78+2,y1_1+2,x2-78-2,y2-2,Ana_renk);
                rect(ana_ekran,x1-78+3,y1_1+3,x2-78-3,y2-3,Ana_renk);
                rect(ana_ekran,x1-78+4,y1_1+4,x2-78-4,y2-4,Ana_renk);
                rect(ana_ekran,x1-78+5,y1_1+5,x2-78-5,y2-5,Ana_renk);
                rect(ana_ekran,x1-78+6,y1_1+6,x2-78-6,y2-6,Ana_renk);
                rect(ana_ekran,x1-78+7,y1_1+7,x2-78-7,y2-7,Ana_renk);
            }


        }

        else if(arac==7)
        {
            x1=mouse_x;
            y1_1=mouse_y;

            while(1)
            {
                if(mouse_b!=1)
                {
                    x2=mouse_x;
                    y2=mouse_y;
                    break;
                }

            }

            rectfill(ana_ekran,x1-78,y1_1,x2-78,y2,Ana_renk);

        }

        else if(arac==8)
        {
            x1=mouse_x-78;
            y1_1=mouse_y;

            while(1)
            {
                if(mouse_b!=1)
                {
                    x2=mouse_x-78;
                    y2=mouse_y;
                    break;
                }

            }
            double x_2,x_3,z1;

            z1=x1-x2;
            x_2=x1-fabs(z1);
            x_3=x1+fabs(z1);

            triangle(ana_ekran,x1,y1_1,x_2,y2,x_3,y2,Ana_renk);




        }

        else if(arac==9)
            floodfill(ana_ekran,mouse_x-78,mouse_y,Ana_renk);

        else if(arac==10)
        {
            x1=mouse_x-78;
            y1_1=mouse_y;

            while(1)
            {
                if(mouse_b!=1)
                {
                    x2=mouse_x-78;
                    y2=mouse_y;
                    break;
                }

            }
            double rx,ry;
            int cap_x,cap_y;

            rx=x1-x2;
            cap_x=fabs(rx);
            ry=y1_1-y2;
            cap_y=fabs(ry);

            if(boyut==1)
            {
                ellipse(ana_ekran,x1,y1_1,cap_x,cap_y,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+1,cap_y+1,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+2,cap_y+2,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+3,cap_y+3,Ana_renk);

            }


            else if(boyut==2)
            {
                ellipse(ana_ekran,x1,y1_1,cap_x,cap_y,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+1,cap_y+1,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+2,cap_y+2,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+3,cap_y+3,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+4,cap_y+4,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+5,cap_y+5,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+6,cap_y+6,Ana_renk);

            }

            else if(boyut==3)
            {
                ellipse(ana_ekran,x1,y1_1,cap_x,cap_y,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+1,cap_y+1,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+2,cap_y+2,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+3,cap_y+3,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+4,cap_y+4,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+5,cap_y+5,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+6,cap_y+6,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+7,cap_y+7,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+8,cap_y+8,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+9,cap_y+9,Ana_renk);

            }

            else if(boyut==4)
            {
                ellipse(ana_ekran,x1,y1_1,cap_x,cap_y,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+1,cap_y+1,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+2,cap_y+2,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+3,cap_y+3,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+4,cap_y+4,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+5,cap_y+5,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+6,cap_y+6,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+7,cap_y+7,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+8,cap_y+8,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+9,cap_y+9,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+10,cap_y+10,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+11,cap_y+11,Ana_renk);
                ellipse(ana_ekran,x1,y1_1,cap_x+12,cap_y+12,Ana_renk);

            }




        }

        else if(arac==11)
        {
            x1=mouse_x-78;
            y1_1=mouse_y;

            while(1)
            {
                if(mouse_b!=1)
                {
                    x2=mouse_x-78;
                    y2=mouse_y;
                    break;
                }
            }


            double rx,ry;
            int cap_x,cap_y;

            rx=x1-x2;
            cap_x=fabs(rx);
            ry=y1_1-y2;
            cap_y=fabs(ry);

            ellipsefill(ana_ekran,x1,y1_1,cap_x,cap_y,Ana_renk);

        }


        else if(arac==12)
        {
            x1=mouse_x;
            y1_1=mouse_y;

            while(1)
            {
                if(mouse_b!=1)
                {
                    x2=mouse_x;
                    y2=mouse_y;

                    break;
                }

            }

            if(boyut==1)
            {
                line(ana_ekran,x1-78,y1_1,x2-78,y2,Ana_renk);
                line(ana_ekran,x1-78,y1_1+1,x2-78,y2+1,Ana_renk);
            }

            else if(boyut==2)
            {
                line(ana_ekran,x1-78,y1_1,x2-78,y2,Ana_renk);
                line(ana_ekran,x1-78,y1_1+1,x2-78,y2+1,Ana_renk);
                line(ana_ekran,x1-78,y1_1+2,x2-78,y2+2,Ana_renk);
                line(ana_ekran,x1-78,y1_1+3,x2-78,y2+3,Ana_renk);
            }

            else if(boyut==3)
            {
                line(ana_ekran,x1-78,y1_1,x2-78,y2,Ana_renk);
                line(ana_ekran,x1-78,y1_1+1,x2-78,y2+1,Ana_renk);
                line(ana_ekran,x1-78,y1_1+2,x2-78,y2+2,Ana_renk);
                line(ana_ekran,x1-78,y1_1+3,x2-78,y2+3,Ana_renk);
                line(ana_ekran,x1-78,y1_1+4,x2-78,y2+4,Ana_renk);
                line(ana_ekran,x1-78,y1_1+5,x2-78,y2+5,Ana_renk);
            }

            else if(boyut==4)
            {
                line(ana_ekran,x1-78,y1_1,x2-78,y2,Ana_renk);
                line(ana_ekran,x1-78,y1_1+1,x2-78,y2+1,Ana_renk);
                line(ana_ekran,x1-78,y1_1+2,x2-78,y2+2,Ana_renk);
                line(ana_ekran,x1-78,y1_1+3,x2-78,y2+3,Ana_renk);
                line(ana_ekran,x1-78,y1_1+4,x2-78,y2+4,Ana_renk);
                line(ana_ekran,x1-78,y1_1+5,x2-78,y2+5,Ana_renk);
                line(ana_ekran,x1-78,y1_1+6,x2-78,y2+6,Ana_renk);
                line(ana_ekran,x1-78,y1_1+7,x2-78,y2+7,Ana_renk);
            }

        }

    }
}

///*************************************************************************************************


///------------------------------------Kayıt, Cikis vs Butonların işleri----------------------------

void aracsec_1()
{
    if(mouse_b==1)
    {

        if(mouse_x>15 && mouse_x<65 && mouse_y>5 && mouse_y<50)
            exit(-1);                                                   /// Kirmizi butona basılınca çıkış

        else if(mouse_x>15  && mouse_y>60 && mouse_y<100)
            clear_to_color(ana_ekran,Arka_plan_renk);     ///Yeni butonu

        else if(mouse_x>15 && mouse_x<65 && mouse_y>110 && mouse_y<150)
            blit((load_bitmap("Ödev.bmp", NULL)), ana_ekran,        0, 0, 0, 0, 822, 547);
        ///Katitli dosya aç


        else if(mouse_x>15 && mouse_x<65 && mouse_y>160 && mouse_y<205)
            save_bmp("Ödev.bmp",ana_ekran,pal); ///Kayit
    }

}

///******************************************************************************************************


///------------------------------------Çizim Aracları secim Yeri------------------------------------------
void aracsec_2()
{
    if(mouse_b==1)
    {
        if(mouse_x>80 && mouse_x<155 && mouse_y>565 && mouse_y<640)
            arac=4;

        else if(mouse_x>160 && mouse_x<230 && mouse_y>565 && mouse_y<640)
            arac=5;

        else if(mouse_x>240 && mouse_x<305 && mouse_y>565 && mouse_y<640)
            arac=6;

        else if(mouse_x>315 && mouse_x<380 && mouse_y>565 && mouse_y<640)
            arac=7;

        else if(mouse_x>500 && mouse_x<570 && mouse_y>565 && mouse_y<640)
            arac=8;

        else if(mouse_x>580 && mouse_x<645 && mouse_y>565 && mouse_y<640)
            arac=9;

        else if(mouse_x>655 && mouse_x<725 && mouse_y>565 && mouse_y<640)
            arac=10;

        else if(mouse_x>735 && mouse_x<800 && mouse_y>565 && mouse_y<640)
            arac=11;

        else if(mouse_x>810 && mouse_x<895 && mouse_y>565 && mouse_y<640)
            arac=12;
    }

}
///***************************************************************************************************


///--------------------------------------Uygulama Penceresi Hazırlık Yeri------------------------------

void Ekran_Olustur() {
	 int derinlik, kontrol;
    allegro_init();

    derinlik = desktop_color_depth();
    if (derinlik == 0) derinlik = 32;
    set_color_depth(derinlik);

    kontrol = set_gfx_mode(GFX_AUTODETECT_WINDOWED,900, 650, 0, 0);
    if (kontrol != 0)
    {
        allegro_message(allegro_error);
        exit(-1);
    }

    install_timer();
    install_keyboard();
    install_mouse();
    set_window_title("---Yusuf SATILMIS---Munir KARSLI----");
}

///******************************************************************************************************



