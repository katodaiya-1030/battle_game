// 必要なライブラリの宣言
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

// プレイヤーのステータスや名前を格納する構造体、共用体
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
    int i,j,ad1,ad2,dd1,dd2,md1,md2,rd1,rd2,level=0;
    char a[1],a2[1],b[1],b2[1];
    a[0]='0';
    b[0]='0';
    gen z1,z2;
    pl player,enemy;

    // プレイヤーの名前入力
    srand((unsigned int)time(NULL));
    printf("プレイヤーの名前を11文字以内で入力:");
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

    // プレイヤーのステータス算出
    player.hp=(int)fabs((double)z1.n[0])%1000+1;
    player.mp=(int)fabs((double)z1.n[0])*3%100+1;
    player.att=(int)fabs((double)z1.n[1])%100+1;
    player.def=(int)fabs((double)z1.n[2])%100+1;
    player.mag=(player.mp*player.att)%100;
    player.res=(player.def*player.mag)%100;
    printf("\n");
    printf("HP:%d\n",player.hp);
    printf("MP:%d\n",player.mp);
    printf("ATTACK:%d\n",player.att);
    printf("DEFENCE:%d\n",player.def);
    printf("MAGERY:%d\n",player.mag);
    printf("RESIST:%d\n",player.res);
    player.luck=(z1.n[0]+z1.n[1]+z1.n[2])%10;
    if(player.luck<0){
        player.luck*=-1;
    }
    player.luck+=5;
    ad1=player.att;
    dd1=player.def;
    md1=player.mag;
    rd1=player.res;
    printf("LUCK:%d\n",player.luck);
    printf("\n");

    // 難易度設定
    while((level<1)||(level>5))
    {
        printf("敵を選んで下さい(1:スライム 2:ゴブリン 3:ドラゴン 4:ゴーレム 5:デーモン)→");
        scanf(" %d",&level);
        printf("\n");
    }
    if(level==1)
    {
        printf("スライムが現れた!!\n");
        enemy.hp=100;
        enemy.mp=25;
        enemy.att=25;
        enemy.def=25;
        enemy.mag=25;
        enemy.res=25;
        enemy.luck=2;
        printf("\n");
        printf("HP:%d\n",enemy.hp);
        printf("MP:%d\n",enemy.mp);
        printf("ATTACK:%d\n",enemy.att);
        printf("DEFENCE:%d\n",enemy.def);
        printf("MAGERY:%d\n",enemy.mag);
        printf("RESIST:%d\n",enemy.res);
        printf("LUCK:%d\n",enemy.luck);
        ad2=enemy.att;
        md2=enemy.mag;
    }
    if(level==2)
    {
        printf("ゴブリンが現れた!!\n");
        enemy.hp=250;
        enemy.mp=5;
        enemy.att=125;
        enemy.def=50;
        enemy.mag=5;
        enemy.res=50;
        enemy.luck=25;
        printf("\n");
        printf("HP:%d\n",enemy.hp);
        printf("MP:%d\n",enemy.mp);
        printf("ATTACK:%d\n",enemy.att);
        printf("DEFENCE:%d\n",enemy.def);
        printf("MAGERY:%d\n",enemy.mag);
        printf("RESIST:%d\n",enemy.res);
        printf("LUCK:%d\n",enemy.luck);
        ad2=enemy.att;
        md2=enemy.mag;
    }
    if(level==3)
    {
        printf("ドラゴンが現れた!!\n");
        enemy.hp=300;
        enemy.mp=50;
        enemy.att=75;
        enemy.def=75;
        enemy.mag=75;
        enemy.res=75;
        enemy.luck=15;
        printf("\n");
        printf("HP:%d\n",enemy.hp);
        printf("MP:%d\n",enemy.mp);
        printf("ATTACK:%d\n",enemy.att);
        printf("DEFENCE:%d\n",enemy.def);
        printf("MAGERY:%d\n",enemy.mag);
        printf("RESIST:%d\n",enemy.res);
        printf("LUCK:%d\n",enemy.luck);
        ad2=enemy.att;
        md2=enemy.mag;
    }
    if(level==4)
    {
        printf("ゴーレムが現れた!!\n");
        enemy.hp=500;
        enemy.mp=5;
        enemy.att=75;
        enemy.def=150;
        enemy.mag=25;
        enemy.res=150;
        enemy.luck=25;
        printf("\n");
        printf("HP:%d\n",enemy.hp);
        printf("MP:%d\n",enemy.mp);
        printf("ATTACK:%d\n",enemy.att);
        printf("DEFENCE:%d\n",enemy.def);
        printf("MAGERY:%d\n",enemy.mag);
        printf("RESIST:%d\n",enemy.res);
        printf("LUCK:%d\n",enemy.luck);
        ad2=enemy.att;
        md2=enemy.mag;
    }
    if(level==5)
    {
        printf("デーモンが現れた!!\n");
        enemy.hp=400;
        enemy.mp=100;
        enemy.att=75;
        enemy.def=75;
        enemy.mag=150;
        enemy.res=75;
        enemy.luck=25;
        printf("\n");
        printf("HP:%d\n",enemy.hp);
        printf("MP:%d\n",enemy.mp);
        printf("ATTACK:%d\n",enemy.att);
        printf("DEFENCE:%d\n",enemy.def);
        printf("MAGERY:%d\n",enemy.mag);
        printf("RESIST:%d\n",enemy.res);
        printf("LUCK:%d\n",enemy.luck);
        ad2=enemy.att;
        dd2=enemy.def;
        md2=enemy.mag;
        rd2=enemy.res;
    }

    // 対戦
    printf("\n対戦開始!!\n");
    while((player.hp>0)&&(enemy.hp>0))
    {

        // プレイヤーの行動
        printf("プレイヤー HP:%d\n",player.hp);
        printf("敵 HP:%d\n",enemy.hp);
        printf("\nプレイヤーは行動を選んでください\n");
        printf("攻撃(a):防御(b):呪文(c):");
        player.att=ad1;
        player.def=dd1;
        player.mag=md1;
        player.res=rd1;
        a2[0]=a[0];
        scanf(" %c",&a[0]);
        if((a[0]=='b')&&(a2[0]=='b')){
            printf("\nプレイヤーは防御に失敗した!\n");
            player.def=0;
            player.res=0;
        } 
        else{
            if(a[0]=='a')
            {
                printf("\nプレイヤーは攻撃した!\n");
                if((int)((double)rand()/(RAND_MAX+1.0)*enemy.luck)+1==1){
                    printf("\n敵は攻撃を回避した!\n");
                }
                else{
                    if((int)((double)rand()/(RAND_MAX+1.0)*player.luck)+1==1){
                        printf("\n急所に当たった!!\n");
                        player.att*=3;
                    }
                    if(b[0]=='b')
                    {
                        if(player.att<enemy.def){
                            printf("\n敵は攻撃を防いだ!\n");
                        }
                        else{
                            enemy.hp-=player.att-enemy.def;
                            printf("\n敵に%dのダメージ!\n",player.att-enemy.def);
                        }
                    }
                    else
                    {
                    enemy.hp-=player.att;
                    printf("\n敵に%dのダメージ!\n",player.att);
                    }
                }
            }
            else if(a[0]=='b'){
                printf("\nプレイヤーは守りの体勢に入った!\n");
            }
            else if(a[0]=='c'){
                printf("\nプレイヤーは呪文を唱えた!\n");
                if((int)((double)rand()/(RAND_MAX+1.0)*enemy.luck)+1==1){
                    printf("\n敵は攻撃を回避した!\n");
                }
                else{
                    if((int)((double)rand()/(RAND_MAX+1.0)*player.luck)+1==1){
                        printf("\n急所に当たった!!\n");
                        player.mag*=3;
                    }
                    if(b[0]=='b'){
                        if(player.mag<enemy.res){
                            printf("\n敵は攻撃を防いだ!\n");
                        }
                        else{
                            enemy.hp-=player.mag-enemy.res;
                            printf("\n敵に%dのダメージ!\n",player.mag-enemy.res);
                        }
                    }
                    else{
                        enemy.hp-=player.mag;
                        printf("\n敵に%dのダメージ!\n",player.mag);

                    }
                }
            }
            else{
                printf("\n攻撃(防御)失敗!!\n");
            }
        }
        if(enemy.hp<=0)break;

        // 敵の行動
        printf("\n敵のターン!!\n");
        enemy.att=ad2;
        enemy.def=dd2;
        enemy.mag=md2;
        enemy.res=rd2;
        b2[0]=b[0];
        if((int)((double)rand()/(RAND_MAX+1.0)*3)+1==1) b[0]='a';
        else if((int)((double)rand()/(RAND_MAX+1.0)*3)+1==2) b[0]='b';
        else b[0]='c';
        if((b[0]=='b')&&(b2[0]=='b')){
            printf("\n敵は防御に失敗した!\n");
            enemy.def=0;
            enemy.res=0;
        }
        else{
            if(b[0]=='a')
            {
                printf("\n敵は攻撃した!\n");
                if((int)((double)rand()/(RAND_MAX+1.0)*player.luck)+1==1){
                    printf("\nプレイヤーは攻撃を回避した!\n");
                }
                else{
                    if((int)((double)rand()/(RAND_MAX+1.0)*enemy.luck)+1==1){
                        printf("\n急所に当たった!!\n");
                        enemy.att*=3;
                    }
                    if(a[0]=='b')
                    {
                        if(enemy.att<player.def){
                            printf("\nプレイヤーは攻撃を防いだ!\n");
                        }
                        else{
                            player.hp-=enemy.att-player.def;
                            printf("\nプレイヤーに%dのダメージ!\n",enemy.att-player.def);
                        }
                    }
                    else{
                        player.hp-=enemy.att;
                        printf("\nプレイヤーに%dのダメージ!\n",enemy.att);
                    }
                }
            }
            else if(b[0]=='b'){
                printf("\n敵は守りの体勢に入った!\n");
            }
            else if(b[0]=='c'){
                printf("\n敵は呪文を唱えた!\n");
                if((int)((double)rand()/(RAND_MAX+1.0)*player.luck)+1==1){
                    printf("\nプレイヤーは攻撃を回避した!\n");
                }
                else{
                    if((int)((double)rand()/(RAND_MAX+1.0)*enemy.luck)+1==1){
                        printf("\n急所に当たった!!\n");
                        enemy.mag*=3;
                    }
                    if(a[0]=='b'){
                        if(enemy.mag<player.res){
                            printf("\nプレイヤーは攻撃を防いだ!\n");
                        }
                        else{
                            player.hp-=enemy.mag-player.res;
                            printf("\nプレイヤーに%dのダメージ!\n",enemy.mag-player.res);
                        }
                    }
                    else{
                        player.hp-=enemy.mag;
                        printf("\nプレイヤーに%dのダメージ!\n",enemy.mag);

                    }
                }
            }
            else{
                printf("\n攻撃(防御)失敗!!\n");
            }
        }
    }

    // 対戦終了
    if(player.hp<=0)
    {
        printf("\n負けてしまった......");
    }
    if(enemy.hp<=0){
        printf("\n敵を倒した!!");
    }
    printf("\n");
    return 0;
}