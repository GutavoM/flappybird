/*Vers�o beta desenvolvida por Thiago Felski Pereira para disciplina de Algoritmos*/
#include <iostream>
#include <windows.h>
#include <conio.h> ///para o getch()
#include <time.h>
///https://stackoverflow.com/questions/34474627/linux-equivalent-for-conio-h-getch

using namespace std;


/**
    F L A P B I R D (M2 Algoritmos)
    - Lembrando: n�o permitido o uso de fun��es e vari�veis compostas como structs, vetores e matrizes
    - Corrigir os rastros (p�ssaro e obst�culos)
    - Implementar colis�o
    - Implementar pontua��o (mais um ponto para cada obst�culo superado)
    - Fazer 2 obst�culos simult�neos (obstaculo1 e obstaculo2)
    - Deixar a pontua��o vis�vel durante todo o jogo
    - Definir marcos para acelerar a velocidade
*/



int main()
{
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    //IN�CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, ACIMA.


    int bird_x=5, bird_y=10;
    int obstaculo_x[2], obstaculo_y[2];
    int tecla;
    int placar_x = 1, placar_y = 23, placar = 0;
    int over_x = 40, over_y = 23;
    int sleep = 160;
    int chao_x, chao_y = 21, teto_x, teto_y = 0;
    obstaculo_x[0]=50;
    obstaculo_x[1]=100;
    obstaculo_y[1]= 100;
    obstaculo_y[0]= 100;


    srand(time(NULL));
    int tunel[2];
    tunel[0] = 3+ rand()%16;
    tunel[1] = 3+ rand()%16;



    while (true) { //esse la�o faz o jogo rodar para sempre


        ///DESENHO DO CEN�RIO
    cout<<"------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"------------------------------------------------------------------------------------------------------------------------";

        // POSICIONA O PLACAR
        coord.X = placar_x;
        coord.Y = placar_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "PLACAR: " << placar;

        ///POSICIONA O P�SSARO

        coord.X = bird_x;    coord.Y = bird_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<char(190);

        ///POSICIONA O OBST�CULO

        // OBSTACULO 1

        obstaculo_y[0]=1;
        while(obstaculo_y[0]<20){

            coord.X = obstaculo_x[0];    coord.Y = obstaculo_y[0];
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y[0]<tunel[0]-2 || obstaculo_y[0]>tunel[0]){
                cout<<char(219);
            } else {
                cout<<" ";
            }

            obstaculo_y[0]++;

        //OBSTACULO 2
        }
        obstaculo_y[1]=1;
        while(obstaculo_y[1]<20){

            coord.X = obstaculo_x[1];    coord.Y = obstaculo_y[1];
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y[1]<tunel[1]-2 || obstaculo_y[1]>tunel[1]){
                cout<<char(219);
            } else {
                cout<<" ";
            }

            obstaculo_y[1]++;
        }

        // REPOSI��O DE OBSTACULOS

        if (obstaculo_x[0]==0)
        {
            tunel[0] = 3+ rand()%16;
            obstaculo_x[0]= 120;
        }

        if (obstaculo_x[1]==0)
        {
            tunel[1] = 3+ rand()%16;
            obstaculo_x[1]= 120;
        }




        ///VERIFICA COLIS�O
        int mod;
        if (obstaculo_x[0] < obstaculo_x [1])
            mod=0;
        else mod=1;

        if (obstaculo_x[mod] == bird_x)
        {
            if (bird_y<tunel[mod]-2 || bird_y>tunel[mod])
            {
                coord.X = over_x;
                coord.Y = over_y;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                cout << "Game Over" << endl << endl << endl;
                return 0;
            }
            else
            {
                placar++;
                if (placar % 5 == 0)
                    sleep = sleep - (sleep/5);
            }
        }

        if (bird_y <= 0 or bird_y >= 20)
        {
            coord.X = over_x;
            coord.Y = over_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout << "Game Over" << endl << endl<< endl;
            return 0;
        }



        ///VERIFICA COMANDO DO JOGADOR
        if (kbhit()) { ///verifica se uma tecla foi pressionada
            tecla=getch(); //verifica comando do jogador
        }

        if ( tecla=='w' ){
            bird_y--;
            tecla='0';
        } else {
            bird_y++;
        }

        ///P�SSARO CAI 1 POSI��O SE N�O FOI PRESSIONADO PARA SUBIR

        ///OBST�CULO AVAN�A UMA POSI��O PARA ESQUERDA
        obstaculo_x[0]--;
        obstaculo_x[1]--;

        ///TEMPO DE ESPERA

        Sleep(sleep);
        system("cls");


    }





    return 0;
}
