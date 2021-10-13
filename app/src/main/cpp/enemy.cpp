//
// Created by student03 on 2020/11/05.
//
#include "enemy.h"
#include "DxLib.h"
#include "player.h"
#include "cmath"
#include "vector"
#include "thread"
#include <random>
#define PI    3.1415926535897932384626433832795f
std::vector<double> vect[7];

enemy::enemy(){

}
enemy::enemy(int x,int y,int type,int* kyara,int* tama_gra,player* pl){
    enemy::graph=kyara;
    enemy::x=x;
    enemy::type=type;
    enemy::y=y;
    enemy::tama_gra=tama_gra;
    enemy::pl=pl;

};
VECTOR normal(VECTOR v){
    float norm2=std::sqrt(v.x * v.x + v.y * v.y);
    float mag=1/norm2;
    float x=v.x*mag;
    float y=v.y*mag;
    VECTOR ret=VECTOR{x,y};
    return ret;
}
void enemy::control(){
    ene_frame+=1;
    if(!isdead) {
        switch (type) {
            //�E�A�E���ɐi�݁A3�����x���ˁA��ʊO�Ɉړ�
            case 0:
                if (ene_frame <= 5) {
                    enemy_vector.x = 6;
                    enemy_vector.y = 18;
                } else if (ene_frame == 30) {
                    double _rad = atan2(pl->y - y, pl->x - x);
                    std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                    tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                    enemy_vector.x = -18;
                    enemy_vector.y = 10;
                } else if (ene_frame == 55) {
                    double _rad = atan2(pl->y - y, pl->x - x);
                    std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                    tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                } else if (ene_frame == 70) {
                    enemy_vector.x = 17;
                    enemy_vector.y = 5;
                    double _rad = atan2(pl->y - y, pl->x - x);
                    std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                    tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                } else if (ene_frame == 120) {

                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //�E�A�E���ɐi�݁A3�����x���ˁA��ʊO�Ɉړ�
            case 1:
                if (ene_frame <= 5) {
                    enemy_vector.x = -9;
                    enemy_vector.y = 18;
                } else if (ene_frame == 30) {
                    double _rad = atan2(pl->y - y, pl->x - x);
                    std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                    tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                    enemy_vector.x = 15;
                    enemy_vector.y = 2;
                } else if (ene_frame == 55) {
                    double _rad = atan2(pl->y - y, pl->x - x);
                    std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                    tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                } else if (ene_frame == 70) {
                    enemy_vector.x = -17;
                    enemy_vector.y = 7;
                    double _rad = atan2(pl->y - y, pl->x - x);
                    std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                    tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                } else if (ene_frame == 120) {

                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //���ɐi�݁A�E�ɕY���悤�Ɉړ��B���ԂŁA�~�`�ɔ���
            case 2:
                if (ene_frame <= 5) {
                    enemy_vector.x = 0;
                    enemy_vector.y = 15;
                } else if (ene_frame == 40) {
                    int kosu = 15;
                    int kakudo = 0;
                    float hanni = 2;
                    for (double i = 0; i < kosu; i++) {
                        double _rad = ((i / kosu) * PI * hanni) + kakudo;
                        float fx = (360 * cos(_rad)) + x;
                        float fy = (360 * sin(_rad)) + y;
                        //komes.push_back(kome((float)x, (float)y, image, VECTOR{ (float)(center_x - x) / 140,(float)(center_y - y) / 140 }, false, 0));
                        tamas.push_back(
                                tama(x, y, std::vector<double>{(fx - x) / 60, (fy - y) / 60},
                                     tama_gra, pl, false));
                    }
                    enemy_vector.x = 17;
                    enemy_vector.y = -7;
                } else if (ene_frame == 80) {
                    enemy_vector.x = 17;
                    enemy_vector.y = 7;
                } else if (ene_frame == 120) {
                    enemy_vector.x =17;
                    enemy_vector.y = -7;
                } else if (ene_frame == 160) {
                    enemy_vector.x = 17;
                    enemy_vector.y = 7;
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //��,���ɐi�݁A���ɕY���悤�Ɉړ�����A���ԂŁA�e�𔭎˂���B
            case 3:
                if (ene_frame <= 5) {
                    enemy_vector.x = 0;
                    enemy_vector.y = 6;
                } else if (ene_frame == 40) {
                    int kosu = 15;
                    int kakudo = 0;
                    float hanni = 2;
                    for (double i = 0; i < kosu; i++) {
                        double _rad = ((i / kosu) * PI * hanni) + kakudo;
                        float fx = (360 * cos(_rad)) + x;
                        float fy = (360 * sin(_rad)) + y;
                        //komes.push_back(kome((float)x, (float)y, image, VECTOR{ (float)(center_x - x) / 140,(float)(center_y - y) / 140 }, false, 0));
                        tamas.push_back(
                                tama(x, y, std::vector<double>{(fx - x) / 60, (fy - y) / 60},
                                     tama_gra, pl, false));
                    }
                    enemy_vector.x = -17;
                    enemy_vector.y = -7;
                } else if (ene_frame == 80) {
                    enemy_vector.x = -17;
                    enemy_vector.y = 7;
                } else if (ene_frame == 120) {
                    enemy_vector.x = -17;
                    enemy_vector.y = -7;
                } else if (ene_frame == 160) {
                    enemy_vector.x = -17;
                    enemy_vector.y = 7;
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //�C�ӁA�ォ�牺�֏����ړ�������A���~��ɉ��ɔ��˂���B
            case 4:
                if (ene_frame <= 5) {
                    enemy_vector.x = 0;
                    enemy_vector.y = 17;
                } else if (ene_frame == 30) {
                    double kosu = 8.0;
                    double kakudo = 0.3;
                    double hanni = 1;
                    for (double i = 0.0; i < kosu; i++) {
                        double _rad = ((i / kosu) * DX_PI * hanni) + kakudo;
                        double fx = (360 * cos(_rad)) + (float) x;
                        double fy = (360 * sin(_rad)) + (float) y;
                        std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                        //komes.push_back(kome((float)x, (float)y, image, VECTOR{ (float)(center_x - x) / 140,(float)(center_y - y) / 140 }, false, 0));
                        tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                    }

                    enemy_vector.x = 0;
                    enemy_vector.y = 0;
                } else if (ene_frame == 80) {
                    enemy_vector.x = -0;
                    enemy_vector.y = -17;
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //������E�A�r���ŉ~�`�ɔ���
            case 5:
                if (ene_frame == 5) {
                    enemy_vector.x = 18;
                } else if (ene_frame == 60) {
                    int kosu = 20;
                    for (double i = 0; i < kosu; i++) {
                        double _rad = ((i / kosu) * PI * 2) + 0;
                        //float fx = (10 * cos(_rad)) + x;
                        //float fy = (10 * sin(_rad)) + y;
                        std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                        tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                    }
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //�E���獶�A�r���ŉ~�`�ɔ���
            case 6:
                if (ene_frame <= 5) {
                    enemy_vector.x = -20;
                } else if (ene_frame == 60) {
                    int kosu = 20;
                    for (double i = 0; i < kosu; i++) {
                        double _rad = ((i / kosu) * PI * 2) + 0;
                        std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                        tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                    }
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //�ォ�牺�A�����_�������S�ɂT�񔭎�
            case 7:
                if (ene_frame <= 5) {
                    health=10;
                    enemy_vector.x = 0;
                    enemy_vector.y = 17;
                } else if (ene_frame == 30) {
                    enemy_vector.x = 0;
                    enemy_vector.y = 0;
                    std::random_device rnd;
                    std::mt19937 mt(rnd());
                    std::uniform_real_distribution<> rand100(0, 10);
                    int kosu = 2;
                    srand(time(NULL));
                    double _rad = ((90.00 / 360.00) * PI * 2.00);
                    double _rad1 = ((91.00 / 360.00) * PI * 2.00);
                    double _rad2 = ((93.00 / 360.00) * PI * 2.00);
                    double _rad3 = ((96.00 / 360.00) * PI * 2.00);
                    double _rad4 = ((99.00 / 360.00) * PI * 2.00);
                    double _rad5 = ((101.00 / 360.00) * PI * 2.00);
                    double _rad6 = ((102.00 / 360.00) * PI * 2.00);
                    std::vector<double> v = {18.00 * cos(_rad), 18.00 * sin(_rad)};
                    std::vector<double> v1 = {18.00 * cos(_rad1), 18.00 * sin(_rad1)};
                    std::vector<double> v2 = {18.00 * cos(_rad2), 18.00 * sin(_rad2)};
                    std::vector<double> v3 = {18.00 * cos(_rad3), 18.00 * sin(_rad3)};
                    std::vector<double> v4 = {18.00 * cos(_rad4), 18.00 * sin(_rad4)};
                    std::vector<double> v5 = {18.00 * cos(_rad5), 18.00 * sin(_rad5)};
                    std::vector<double> v6 = {18.00 * cos(_rad6), 18.00 * sin(_rad6)};
                    vect[0] =v;
                    vect[1]=v1;
                    vect[2]=v2;
                    vect[3]=v3;
                    vect[4]=v4;
                    vect[5]=v5;
                    vect[6]=v6;
                    tamas.push_back(tama(x, y, vect[0], tama_gra, pl, false));
                    tamas.push_back(tama(x, y, vect[2], tama_gra, pl, false));
                    tamas.push_back(tama(x, y, vect[4], tama_gra, pl, false));
                    tamas.push_back(tama(x, y, vect[6], tama_gra, pl, false));
                } else if (ene_frame == 90) {
                    tamas.push_back(tama(x, y, vect[1], tama_gra, pl, false));
                } else if (ene_frame == 95) {
                    tamas.push_back(tama(x, y, vect[2], tama_gra, pl, false));
                } else if (ene_frame == 100) {
                    tamas.push_back(tama(x, y, vect[3], tama_gra, pl, false));
                } else if (ene_frame == 105) {
                    tamas.push_back(tama(x, y, vect[4], tama_gra, pl, false));
                } else if (ene_frame == 110) {
                    tamas.push_back(tama(x, y, vect[5], tama_gra, pl, false));
                }else if (ene_frame == 115) {
                    tamas.push_back(tama(x, y, vect[6], tama_gra, pl, false));
                }else if (ene_frame == 120) {
                    tamas.push_back(tama(x, y, vect[5], tama_gra, pl, false));
                }else if (ene_frame == 125) {
                    tamas.push_back(tama(x, y, vect[4], tama_gra, pl, false));
                }else if (ene_frame == 130) {
                    tamas.push_back(tama(x, y, vect[3], tama_gra, pl, false));
                }else if (ene_frame == 135) {
                    tamas.push_back(tama(x, y, vect[2], tama_gra, pl, false));
                }else if (ene_frame == 140) {
                    tamas.push_back(tama(x, y, vect[1], tama_gra, pl, false));
                }else if (ene_frame == 145) {
                    tamas.push_back(tama(x, y, vect[0], tama_gra, pl, false));
                }else if (ene_frame == 150) {
                    tamas.push_back(tama(x, y, vect[1], tama_gra, pl, false));
                }else if (ene_frame == 155) {
                    tamas.push_back(tama(x, y, vect[2], tama_gra, pl, false));
                }else if (ene_frame == 160) {
                    tamas.push_back(tama(x, y, vect[3], tama_gra, pl, false));
                }else if (ene_frame == 165) {
                    tamas.push_back(tama(x, y, vect[4], tama_gra, pl, false));
                }else if (ene_frame == 170) {
                    tamas.push_back(tama(x, y, vect[5], tama_gra, pl, false));
                }else if (ene_frame == 175) {
                    tamas.push_back(tama(x, y, vect[6], tama_gra, pl, false));
                }else if (ene_frame == 165) {
                    tamas.push_back(tama(x, y, vect[2], tama_gra, pl, false));
                }
                else if (ene_frame == 200) {
                    enemy_vector.x = 0;
                    enemy_vector.y = -15;
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //�~�`�ɑ傫�ȋʂ�z�u��A�~�`�ɋ�������
            case 8:
                if(ene_frame<=5){
                    ext=4;
                    health=150;
                    enemy_vector.x=0;
                    enemy_vector.y=8;
                }else if(ene_frame<=99){
                    kaiwa=1;
                    show_ani=true;
                }else if(ene_frame>=100&&ene_frame<=145){
                    ene_ani++;
                    enemy_vector.x=0;
                    enemy_vector.y=0;
                }else if(ene_frame==146){
                    show_ani=false;
                }else if(ene_frame<=300){
                    kaiwa=2;
                }else if(ene_frame<=450){
                    kaiwa=3;
                }else if(ene_frame<=600){
                    kaiwa=4;
                }else if(ene_frame<=750){
                    kaiwa=5;
                }else if(ene_frame<=900){
                    kaiwa=0;
                    //�����Ă��Ȃ��̂ŁA������ʂɖ߂����Ⴄ�I���Ⴀ�ˁI
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
        }
    }
}

void enemy::draw(){
    //DrawFormatString((float)pl->x,(float)pl->y,GetColor(255,255,255),"%d",pl->y);
    if(!isdead){
        DrawRotaGraphF((int)x,(int)y,ext,0,*graph,1);
        if(show_ani){
            SetDrawBlendMode(DX_BLENDMODE_ALPHA,ene_ani);
            DrawRotaGraphF((int)x+1,(int)y+1,3.0+(ene_ani/6.0),0,*graph,1);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND,200);
        }
    }
    if(kaiwa==1){
        SetFontSize(500);
        DrawGraph(120,1230,LoadGraph("reimu_mu.png"),1);
        DrawGraph(120,1600,LoadGraph("serihu1.png"),1);
        //DrawFormatString(200,1600,GetColor(0,0,0),"������Ƌ�C���₽����ˁB");
    }else if(kaiwa==2){
        SetFontSize(500);
        DrawGraph(120,1230,LoadGraph("tiruno_ko.jpg"),1);
        DrawGraph(120,1600,LoadGraph("serihu2.png"),1);
        //DrawFormatString(200,1900,GetColor(255,255,255),"�˂��I������Ƃ��񂽁I�N�ɋ�����ē������́I�H");
    }else if(kaiwa==3){
        DrawGraph(120,1230,LoadGraph("reimu_ko.png"),1);
        DrawGraph(120,1600,LoadGraph("serihu3.png"),1);
    }else if(kaiwa==4){
        DrawGraph(120,1230,LoadGraph("tiruno_at.jpg"),1);
        DrawGraph(120,1600,LoadGraph("serihu4.png"),1);
    }else if(kaiwa==5){
        DrawGraph(120,1230,LoadGraph("reimu_eg.png"),1);
        DrawGraph(120,1600,LoadGraph("serihu5.png"),1);
    }

}
enemy::~enemy() {

}
