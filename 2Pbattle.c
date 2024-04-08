// 必要なライブラリの宣言
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

// プレイヤーのステータスを格納する構造体、共用体
typedef struct player
{
    char name[12];
    int hp,mp,att,def,mag,res,luck;
}pl;
typedef union
{
    char name[12];
    int n[3];
}gen;

// メイン関数
int main(void){

    // 必要な変数
    int i,j,ad1,ad2,dd1,dd2,md1,md2,rd1,rd2;
    char a[1],a2[1],b[1],b2[1];
    a[0]='0';
    b[0]='0';
    gen z1,z2;
    pl pl1,pl2;

    // プレイヤー1の名前入力
    printf("プレイヤー1の名前を11文字以内で入力:");
    for(i=0;i<=10;i++){
        scanf("%c",&z1.name[i]);
        if(z1.name[i]=='\n')break;
    }
    for(j=i;j<=10;j++){
        z1.name[j]=' ';
    }
    z1.name[11]='\0';
    printf("\n");
    printf("キャラクター名:");
    for(i=0;i<=10;i++){
        printf("%c",z1.name[i]);
    }

    // プレイヤー1のステータスを決定
    pl1.hp=(int)fabs((double)z1.n[0])%1000+1;
    pl1.mp=(int)fabs((double)z1.n[0])*3%100+1;
    pl1.att=(int)fabs((double)z1.n[1])%100+1;
    pl1.def=(int)fabs((double)z1.n[2])%100+1;
    pl1.mag=(pl1.mp*pl1.att)%100;
    pl1.res=(pl1.def*pl1.mag)%100;
    printf("\n");
    printf("HP:%d\n",pl1.hp);
    printf("MP:%d\n",pl1.mp);
    printf("ATTACK:%d\n",pl1.att);
    printf("DEFENCE:%d\n",pl1.def);
    printf("MAGERY:%d\n",pl1.mag);
    printf("RESIST:%d\n",pl1.res);
    pl1.luck=(z1.n[0]+z1.n[1]+z1.n[2])%10;
    if(pl1.luck<0){
        pl1.luck*=-1;
    }
    pl1.luck+=3;
    ad1=pl1.att;
    dd1=pl1.def;
    md1=pl1.mag;
    rd1=pl1.res;
    printf("LUCK:%d\n",pl1.luck);

    // プレイヤー2の名前を入力
    printf("プレイヤー2の名前を11文字以内で入力:");
    for(i=0;i<=10;i++){
        scanf("%c",&z2.name[i]);
        if(z2.name[i]=='\n')break;
    }
    for(j=i;j<=10;j++){
        z2.name[j]=' ';
    }
    z2.name[11]='\0';
    printf("\n");
    printf("キャラクター名:");
    for(i=0;i<=10;i++){
        printf("%c",z2.name[i]);
    }

    // プレイヤー2のステータスを決定
    pl2.hp=(int)fabs((double)z2.n[0])%1000+1;
    pl2.mp=(int)fabs((double)z2.n[0])*3%100+1;
    pl2.att=(int)fabs((double)z2.n[1])%100+1;
    pl2.def=(int)fabs((double)z2.n[2])%100+1;
    pl2.mag=(pl2.mp*pl2.att)%100;
    pl2.res=(pl2.def*pl2.mag)%100;
    printf("\n");
    printf("HP:%d\n",pl2.hp);
    printf("MP:%d\n",pl2.mp);
    printf("ATTACK:%d\n",pl2.att);
    printf("DEFENCE:%d\n",pl2.def);
    printf("MAGERY:%d\n",pl2.mag);
    printf("RESIST:%d\n",pl2.res);
    pl2.luck=(z2.n[0]+z2.n[1]+z2.n[2])%10;
    if(pl2.luck<0){
        pl2.luck*=-1;
    }
    pl2.luck+=3;
    ad2=pl2.att;
    dd2=pl2.def;
    md2=pl2.mag;
    rd2=pl2.res;
    printf("LUCK:%d\n",pl2.luck);

    // ターン制の対戦フェイズ
    printf("\n対戦開始!!\n");
    while((pl1.hp>0)&&(pl2.hp>0))
    {
        // プレイヤー1の行動
        printf("プレイヤー1 HP:%d\n",pl1.hp);
        printf("プレイヤー2 HP:%d\n",pl2.hp);
        printf("\nプレイヤー1は行動を選んでください\n");
        printf("攻撃(a):防御(b):呪文(c):");
        a2[0]=a[0];
        pl1.att=ad1;
        pl1.def=dd1;
        pl1.mag=md1;
        pl1.res=rd1;
        scanf(" %c",&a[0]);
        if((a[0]=='b')&&(a2[0]=='b')){
            printf("\n防御失敗!\n");
            pl1.def=0;
            pl1.res=0;
        } 
        else{
            if(a[0]=='a')
            {
                printf("\nプレイヤー1は攻撃した!\n");
                if((int)((double)rand()/(RAND_MAX+1.0)*pl2.luck)+1==1){
                    printf("\nプレイヤー2は攻撃を回避した!\n");
                }
                else{
                    if((int)((double)rand()/(RAND_MAX+1.0)*pl1.luck)+1==1){
                        printf("\n急所に当たった!!\n");
                        pl1.att*=3;
                    }
                    if(b[0]=='b')
                    {
                        if(pl1.att<pl2.def){
                            printf("\nプレイヤー2は攻撃を防いだ!\n");
                        }
                        else{
                            pl2.hp-=pl1.att-pl2.def;
                            printf("\nプレイヤー2に%dのダメージ!\n",pl1.att-pl2.def);
                        }
                    }
                    else
                    {
                    pl2.hp-=pl1.att;
                    printf("\nプレイヤー2に%dのダメージ!\n",pl1.att);
                    }
                }
            }
            else if(a[0]=='b'){
                printf("\nプレイヤー1は守りの体勢に入った!\n");
            }
            else if(a[0]=='c'){
                printf("\nプレイヤー1は呪文を唱えた!\n");
                if((int)((double)rand()/(RAND_MAX+1.0)*pl2.luck)+1==1){
                    printf("\nプレイヤー2は攻撃を回避した!\n");
                }
                else{
                    if((int)((double)rand()/(RAND_MAX+1.0)*pl1.luck)+1==1){
                        printf("\n急所に当たった!!\n");
                        pl1.mag*=3;
                    }
                    if(b[0]=='b'){
                        if(pl1.mag<pl2.res){
                            printf("\nプレイヤー2は攻撃を防いだ!\n");
                        }
                        else{
                            pl2.hp-=pl1.mag-pl2.res;
                            printf("\nプレイヤー2に%dのダメージ!\n",pl1.mag-pl2.res);
                        }
                    }
                    else{
                        pl2.hp-=pl1.mag;
                        printf("\nプレイヤー2に%dのダメージ!\n",pl1.mag);

                    }
                }
            }
            else{
                printf("\n攻撃(防御)失敗!!\n");
            }
        }
        if(pl2.hp<0)break;

        // プレイヤー2の行動
        printf("\nプレイヤー2は行動を選んでください\n");
        printf("攻撃(a):防御(b):呪文(c):");
        b2[0]=b[0];
        pl2.att=ad2;
        pl2.def=dd2;
        pl2.mag=md2;
        pl2.res=rd2;
        scanf(" %c",&b[0]);
        if((b[0]=='b')&&(b2[0]=='b')){
            printf("\n防御失敗!\n");
            pl2.def=0;
            pl2.res=0;
        }
        else{
            pl2.att=ad2;
            pl2.mag=md2;
            if(b[0]=='a')
            {
                printf("\nプレイヤー2は攻撃した!\n");
                if((int)((double)rand()/(RAND_MAX+1.0)*pl1.luck)+1==1){
                    printf("\nプレイヤー1は攻撃を回避した!\n");
                }
                else{
                    if((int)((double)rand()/(RAND_MAX+1.0)*pl2.luck)+1==1){
                        printf("\n急所に当たった!!\n");
                        pl2.att*=3;
                    }
                    if(a[0]=='b')
                    {
                        if(pl2.att<pl1.def){
                            printf("\nプレイヤー1は攻撃を防いだ!\n");
                        }
                        else{
                            pl1.hp-=pl2.att-pl1.def;
                            printf("\nプレイヤー1に%dのダメージ!\n",pl2.att-pl1.def);
                        }
                    }
                    else{
                        pl1.hp-=pl2.att;
                        printf("\nプレイヤー1に%dのダメージ!\n",pl2.att);
                    }
                }
            }
            else if(b[0]=='b'){
                printf("\nプレイヤー2は守りの体勢に入った!\n");
            }
            else if(b[0]=='c'){
                printf("\nプレイヤー2は呪文を唱えた!\n");
                if((int)((double)rand()/(RAND_MAX+1.0)*pl1.luck)+1==1){
                    printf("\nプレイヤー1は攻撃を回避した!\n");
                }
                else{
                    if((int)((double)rand()/(RAND_MAX+1.0)*pl2.luck)+1==1){
                        printf("\n急所に当たった!!\n");
                        pl2.mag*=3;
                    }
                    if(a[0]=='b'){
                        if(pl2.mag<pl1.res){
                            printf("\nプレイヤー1は攻撃を防いだ!\n");
                        }
                        else{
                            pl1.hp-=pl2.mag-pl1.res;
                            printf("\nプレイヤー1に%dのダメージ!\n",pl2.mag-pl1.res);
                        }
                    }
                    else{
                        pl1.hp-=pl2.mag;
                        printf("\nプレイヤー1に%dのダメージ!\n",pl2.mag);

                    }
                }
            }
            else{
                printf("\n攻撃(防御)失敗!!\n");
            }
        }
    }

    // 対戦終了
    printf("\n対戦終了!!\n");
    printf("勝者 ");
    if(pl1.hp<0)
    {
        for(i=0;i<=10;i++){
            printf("%c",z2.name[i]);
        }
    }
    if(pl2.hp<0){
        for(i=0;i<=10;i++){
            printf("%c",z1.name[i]);
        }
    }
    printf("\n");
    return 0;
}