#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ROJO_T     "\x1b[31m"
#define CYAN_T     "\x1b[36m"
#define BLANCO_T   "\x1b[37m"
#define AZUL_T     "\x1b[34m"
#define AMARILLO_T "\x1b[33m"


typedef struct{
	int x;
	int y;
	int corazones;
	int vidas;
	int score;

}NAVE;

typedef struct{
    int x;
    int y;

}ASTEROIDE;

void Bienvenida();
void instrucciones();
void Winner(NAVE *n);
void Loser(NAVE *n);

void gotoxy(int x, int y);
void OcultarCursor();
void Pintar_Limites();

void PintarNave(NAVE *n);
void BorrarNave(NAVE *n);
void MoverNave(NAVE *n);
void PintarCorazones(NAVE *n);
void QuitarCorazones(NAVE *n);
void Morir(NAVE *n);

void PintarAsteroide(ASTEROIDE *a);
void MoverAsteroide(ASTEROIDE *a);
void PintarAsteroide_b(ASTEROIDE *a);
void MoverAsteroide_b(ASTEROIDE *a);


void ChoqueAsteroide(NAVE *n, ASTEROIDE *a);
void Score(NAVE *n);


int main(){
    int op = 1;
    do{
    Bienvenida();
    instrucciones();
    system("cls");

	OcultarCursor();
	Pintar_Limites();
	//Creamos la nave---
	NAVE Nave;
	Nave.x = 35;
	Nave.y = 30;
	Nave.corazones = 3;
	Nave.vidas = 3;
	Nave.score = 0;
	PintarNave(&Nave);
	PintarCorazones(&Nave);
    //------------------

    //Crear Asteroides Malos--------
    ASTEROIDE ast1,ast2,ast3,ast4;
    ast1.x = 10;
    ast1.y = 4;
    ast2.x = 4;
    ast2.y = 8;
    ast3.x = 15;
    ast3.y = 10;
    ast4.x = 6;
    ast4.y = 8;
    //Crear Asteroides Buenos(Plasma)------------------------
    ASTEROIDE astb;
    astb.x = 8;
    astb.y = 4;

	bool GameOver = false;
	while(!GameOver){

        MoverAsteroide(&ast1); ChoqueAsteroide(&Nave, &ast1);
        MoverAsteroide(&ast2); ChoqueAsteroide(&Nave, &ast2);
        MoverAsteroide(&ast3); ChoqueAsteroide(&Nave, &ast3);
        MoverAsteroide(&ast4); ChoqueAsteroide(&Nave, &ast4);
        MoverAsteroide_b (&astb); ChoqueAsteroide_b(&Nave, &astb);

        Morir(&Nave);
		MoverNave(&Nave);
		Sleep(30);
        if(Nave.vidas == 0||Nave.score == 20) GameOver = true;
	}
	if(Nave.vidas == 0)
        Loser(&Nave);
    if(Nave.score == 20)
        Winner(&Nave);
    printf("\n\n¿Deseas Volver a Jugar? 0)no 1)si :   ");
    scanf("%d",&op);
    }while(op!= 0);

}


void Bienvenida(){
    system("cls");
    printf("\n \n                       Bienvenido Soldado Espacial! \n \n \n \n");
    Sleep(1000);
    printf("  Necesitamos tu ayuda!!\n  Actualmente en el espacio se encuentran esferas de plasma. \n  Necesitamos que las recolectes y las traigas aqui \n ");
    Sleep(2500);
    printf(" Se Que Es Una Mision Muy Peligrosa");
    Sleep(1000);
    printf(",Pero Tu Eres Nuestro Mejor Soldado.  \n");
    printf("  Y el Unico Capaz De Completar La Mision.  \n \n \n \n");
    Sleep(2500);
    printf("                             Buena Suerte.");
    Sleep(1000);
    printf("\n \n \n \n   Presiona Cualquier Tecla Para Continuar...");
    getch();
}

void instrucciones(){
        system("cls");
        printf("\n \n \n \n \n \n                         -----INSTRUCCIONES-----");
        Sleep(1000);
        printf("\n \n Recolectar los orbes de plasma evitando los meteoritos\n Para Ganar debes recolectar 20 orbes de plasma en total");
        Sleep(1000);
        printf("\n \n \n              ARRIBA:W\nIZQUIERDA:A   ABAJO:S   DERECHA:D");
        printf(BLANCO_T"\n\n\n METEORITOS: %c", 79);
        printf("\n ORBE DE PLASMA: ");printf(CYAN_T"%c",184);
        printf(BLANCO_T"\n \n \n \n Presiona Cualquier Tecla Para Continuar...");
        getch();


}

void Winner(NAVE *n){
        system("cls");
        printf("\n \n \n \n \n \n                         -----FELICIDADES!-----");
        Sleep(1000);
        printf("\n \n                                Score: %d", n->score);
        Sleep(1000);
        printf("\n \n \n \n                          BUEN TRABAJO");
        Sleep(1000);
        printf(", Heroe.");
        Sleep(1000);
        getch();
}

void Loser(NAVE *n){
        system("cls");
        printf("\n \n \n \n \n \n                             -----PERDISTE-----");
        Sleep(1000);
        printf("\n \n \n \n                            SUERTE PARA LA PROXIMA.");
        Sleep(1000);
        printf("\n \n                             PUNTUACION FINAL: %d", n->score);
        getch();

}

void gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos);

}

void OcultarCursor(){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = false;

	SetConsoleCursorInfo(hCon, &cci);
}

void Pintar_Limites(){
    //Lineas Horizontales
    for(int i = 2;i<78;i++){
        gotoxy(i,3); printf("%c",205);
        gotoxy(i,33); printf("%c",205);
    }
    //Lineas Verticales
    for(int i = 4;i<33;i++){
        gotoxy(2,i);printf("%c",186);
        gotoxy(77,i);printf("%c",186);
    }
    //Esquinas
    gotoxy(2,3);printf("%c",201);
    gotoxy(2,33);printf("%c",200);
    gotoxy(77,3);printf("%c",187);
    gotoxy(77,33);printf("%c",188);

}

void PintarNave(NAVE *n){
	fflush(stdin);
	gotoxy(n->x,n->y); printf(ROJO_T"  %c",65);
	gotoxy(n->x,n->y+1); printf(AZUL_T" %c%c%c",124,207,124);
	gotoxy(n->x,n->y+2); printf(BLANCO_T"%c%c%c%c%c",204,190,177,190,185);
}

void BorrarNave(NAVE *n){
	gotoxy(n->x,n->y);   printf("        ");
	gotoxy(n->x,n->y+1); printf("        ");
	gotoxy(n->x,n->y+2); printf("        ");
}

void MoverNave(NAVE *n){
	if(kbhit()){
		char tecla = getch();
		BorrarNave(n);
		if(tecla == 'a' && (n->x )> 3) n->x--;
		if(tecla == 'd' && ((n->x)+8)< 77) n->x++;
		if(tecla == 'w' && (n->y) > 4) n->y--;
		if(tecla == 's' && ((n->y)+3) < 33) n->y++;
		PintarNave(n);
		PintarCorazones(n);
}
}

void PintarCorazones(NAVE *n){
    gotoxy(50,2);printf("VIDAS: %d",n->vidas);
    gotoxy(64,2);printf("SALUD");
    gotoxy(70,2);printf("      ");
    gotoxy(3,2); printf("SCORE: %d",n->score);
    for(int i = 0;i < (n->corazones);i++){
        gotoxy(70+i,2);printf("%c",254);
    }

}

void QuitarCorazones(NAVE *n){
 n->corazones--;
}

void Morir(NAVE *n){
    if((n->corazones) == 0){
        BorrarNave(n);
        gotoxy((n->x),(n->y));  printf(ROJO_T"   **  ");
        gotoxy((n->x),(n->y)+1);printf(AMARILLO_T"  **** ");
        gotoxy((n->x),(n->y)+2);printf(ROJO_T"   **  ");
        Sleep(200);

        BorrarNave(n);
        gotoxy((n->x),(n->y));  printf(AMARILLO_T" * ** *");
        gotoxy((n->x),(n->y)+1);printf(AMARILLO_T"  **** ");
        gotoxy((n->x),(n->y)+2);printf(AMARILLO_T" * ** *");
        Sleep(200);

        BorrarNave(n);
        n->vidas--;
        n->corazones = 3;
        PintarCorazones(n);
        PintarNave(n);


    }

}

void PintarAsteroide(ASTEROIDE *a){
    gotoxy(a->x,a->y);printf(BLANCO_T "%c",79);
}

void MoverAsteroide(ASTEROIDE *a){
    gotoxy(a->x,a->y);printf(" ");
    a->y++;
    if((a->y)>32){
        a->x = rand()%71 + 4;
        a->y = 4;
    }
    PintarAsteroide(a);
}

void ChoqueAsteroide(NAVE *n, ASTEROIDE *a){
    if((a->x) >= n->x && a->x < (n->x)+5 && (a->y) >= (n->y) && (a->y) <= (n->y)+2){
        QuitarCorazones(n);
        BorrarNave(n);
        PintarNave(n);
        PintarCorazones(n);
        a->x = rand()%71 + 4;
        a->y = 4;

    }
}

void PintarAsteroide_b(ASTEROIDE *a){
    gotoxy(a->x,a->y);printf(CYAN_T"%c",184);
}

void MoverAsteroide_b(ASTEROIDE *a){
    gotoxy(a->x,a->y);printf(" ");
    a->y++;
    if((a->y)>32){
        a->x = rand()%71 + 4;
        a->y = 4;
    }
    PintarAsteroide_b(a);
}

void ChoqueAsteroide_b(NAVE *n, ASTEROIDE *a){
    if((a->x) >= n->x && a->x < (n->x)+5 && (a->y) >= (n->y) && (a->y) <= (n->y)+2){
        BorrarNave(n);
        PintarNave(n);
        PintarCorazones(n);
        a->x = rand()%71 + 4;
        a->y = 4;
        n->score++;

    }
}

