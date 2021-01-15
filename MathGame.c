#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <locale.h>


FILE *scoreEasy;


typedef struct game{
    
    int operation;
    int value1;
    int value2;

}math;



void mainMenu(int option);

void chooseDifficulty(int option);
void chooseScore(int option);

void easyGame(int option);
void mediumGame();
void hardGame();

void easyScore();
void mediumScore();
void hardScore();


int main(){

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int option;

    mainMenu(option);
/*
    
  
  for (i=0; i < 10; i++)
  {
    // gerando valores aleatórios na faixa de 0 a 100
    printf("%d ", rand() % 100);
  }



    FILE *scoreMedium;
    FILE *scoreHard;
    FILE *scoreLegend;
    
*/
    return 0;
}



void mainMenu(int option){
    do{
        printf("|-------------------------------------------|\n");
        printf("|----------  Jogo da Matemática  -----------|\n");
        printf("|-------------------------------------------|\n");
        printf("|            1- Jogar                       |\n");
        printf("|            2- Ver Score                   |\n");
        printf("|            3- Sair                        |\n");
        printf("|-------------------------------------------|\n");
        printf("|Opção:  ");
        scanf("%d",&option);
        
        system("cls");
    }while(option <= 0 || option >= 4);

    switch (option){
    case 1:
        chooseDifficulty(option);
        break;
    case 2:
        chooseScore(option);
        break;
    default:
        exit(0);
    }
}



void chooseDifficulty(option){
    do{
        printf("|-------------------------------------------|\n");
        printf("|---------- Escolha a Dificuldade ----------|\n");
        printf("|-------------------------------------------|\n");
        printf("|           1- Facil                        |\n");
        printf("|           2- Médio                        |\n");
        printf("|           3- Dificil                      |\n");
        printf("|           4- Voltar                       |\n");
        printf("|-------------------------------------------|\n");
        printf("|Opção:  ");
        scanf("%d",&option);
        
        system("cls");
    }while(option <= 0 || option >= 5);

    switch (option){
    case 1:
        easyGame(option);
        break;
    case 2:
        mediumGame();
        break;
    case 3:
        hardGame();
        break;
    case 4:
        mainMenu(option);
    }
}



void chooseScore(option){  
    do{
        printf("|-------------------------------------------|\n");
        printf("|---------- Escolha a Dificuldade ----------|\n");
        printf("|-------------------------------------------|\n");
        printf("|           1- Score Facil                  |\n");
        printf("|           2- Score Médio                  |\n");
        printf("|           3- Score Dificil                |\n");
        printf("|           4- Voltar                       |\n");
        printf("|-------------------------------------------|\n");
        printf("|Opção:  ");
        scanf("%d",&option);
        
        system("cls");
    }while(option <= 0 || option >= 5);

    switch (option){
    case 1:
        easyScore();
        break;
    case 2:
        mediumScore();
        break;
    case 3:
        hardScore();
        break;
    case 4:
        mainMenu(option);
    }
}



void easyGame(int option){

    scoreEasy = fopen("scoreEasy.txt", "a");

    math easy;
    
    short int lifes = 3;
    int points = 0;
    
    int answer;
    int question;

    do{
        
        easy.operation = rand() % 3;

        switch(easy.operation){

        case 0:       
            easy.value1 = rand() % 11;
            easy.value2 = rand() % 11;
            question = (easy.value1 + easy.value2);
                
            printf("|-------------------------------------------|\n");
            printf("|---------------   Responda   --------------|\n");
            printf("|-------------------------------------------|\n");
            printf("|                 %d + %d = ?               |\n",easy.value1,easy.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%d",&answer);

            if (answer == question){
                printf("\nResposta Certa!\n");
                printf("Resposta certa: %d\n",question);
                points ++;
                    
                printf("Vidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\nResposta Errada!\n");
                printf("Resposta certa: %d\n",question);
                lifes --;
                    
                printf("Vidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("Game Over\n");

                    system("pause");
                    points = 0;
                    mainMenu(option);
                }

                system("pause");
            }

            system("cls");
                
            printf("|-------------------------------------------|\n");
            printf("|----------   Desejá continuar?   ----------|\n");
            printf("|-------------------------------------------|\n");
            printf("|             1- Sim                        |\n");
            printf("|             2- Não                        |\n");
            printf("|-------------------------------------------|\n");
            printf("|Opção:  ");
            scanf("%d",&option);

            system("cls");
            break;

        case 1:           
            easy.value1 = rand() % 11;
            easy.value2 = rand() % 11;
            question = (easy.value1 - easy.value2);
                
            printf("|-------------------------------------------|\n");
            printf("|---------------   Responda   --------------|\n");
            printf("|-------------------------------------------|\n");
            printf("|                 %d - %d = ?               |\n",easy.value1,easy.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%d",&answer);

            if (answer == question){
                printf("\nResposta Certa!\n");
                printf("Resposta certa: %d\n",question);
                points ++;
                    
                printf("Vidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\nResposta Errada!\n");
                printf("Resposta certa: %d\n",question);
                lifes --;
                    
                printf("Vidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("Game Over\n");

                    system("pause");
                    points = 0;
                    mainMenu(option);
                }
                
                system("pause");
            }

            system("cls");
                
            printf("|-------------------------------------------|\n");
            printf("|----------   Desejá continuar?   ----------|\n");
            printf("|-------------------------------------------|\n");
            printf("|             1- Sim                        |\n");
            printf("|             2- Não                        |\n");
            printf("|-------------------------------------------|\n");
            printf("|Opção:  ");
            scanf("%d",&option);

            system("cls");
            break;

        case 2:           
            easy.value1 = rand() % 11;
            easy.value2 = rand() % 11;
            question = (easy.value1 * easy.value2);
                
            printf("|-------------------------------------------|\n");
            printf("|---------------   Responda   --------------|\n");
            printf("|-------------------------------------------|\n");
            printf("|                 %d * %d = ?               |\n",easy.value1,easy.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%d",&answer);

            if (answer == question){
                printf("\nResposta Certa!\n");
                printf("Resposta certa: %d\n",question);
                points ++;
                    
                printf("Vidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\nResposta Errada!\n");
                printf("Resposta certa: %d\n",question);
                lifes --;
                    
                printf("Vidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("Game Over\n");

                    system("pause");
                    points = 0;
                    mainMenu(option);
                }
                
                system("pause");
            }

            system("cls");
                
            printf("|-------------------------------------------|\n");
            printf("|----------   Desejá continuar?   ----------|\n");
            printf("|-------------------------------------------|\n");
            printf("|             1- Sim                        |\n");
            printf("|             2- Não                        |\n");
            printf("|-------------------------------------------|\n");
            printf("|Opção:  ");
            scanf("%d",&option);

            system("cls");
            break;
        }

    }while(option == 1);
    
    if (scoreEasy == NULL){
    
        printf("Comunique o administrador!\n");
        system("pause");
        exit(0);
    
    }else{

        printf("Placar salvo!\n");
        system("pause");
    }

    fclose(scoreEasy);

    mainMenu(option);
}

void mediumGame(){

}

void hardGame(){

}


void easyScore(){

}

void mediumScore(){

}

void hardScore(){

}

void legendScore(){

}