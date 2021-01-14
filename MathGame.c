#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <locale.h>


typedef struct game{
    
    int operation;
    int value1;
    int value2;
    int value3;

}math;



void mainMenu(int option);

void chooseDifficulty(int option);
void chooseScore(int option);

void easyGame(int option);
void mediumGame();
void hardGame();
void legendGame();

void easyScore();
void mediumScore();
void hardScore();
void legendScore();


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


    FILE *scoreEasy;
    FILE *scoreMedium;
    FILE *scoreHard;
    FILE *scoreLegend;

    

    scoreEasy = fopen("scoreEasy.txt", "a");

    if (scoreEasy == NULL){
    
        printf("ERRO! O arquivo não foi aberto!\n");
    
    }else{

        printf("O arquivo foi aberto com sucesso!");
    
    }


    fclose(scoreEasy);
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
        printf("|           4- Lenda                        |\n");
        printf("|           5- Voltar                       |\n");
        printf("|-------------------------------------------|\n");
        printf("|Opção:  ");
        scanf("%d",&option);
        
        system("cls");
    }while(option <= 0 || option >= 6);

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
        legendGame();
        break;
    case 5:
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
        printf("|           4- Score Lenda                  |\n");
        printf("|           5- Voltar                       |\n");
        printf("|-------------------------------------------|\n");
        printf("|Opção:  ");
        scanf("%d",&option);
        
        system("cls");
    }while(option <= 0 || option >= 6);

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
        legendScore();
        break;
    case 5:
        mainMenu(option);
    }
}



void easyGame(int option){
    math easy;
    
    short int lifes = 3;
    int points = 0;
    
    float answer;
    float question;

    do{
        
        easy.operation = rand() % 4;

        switch(easy.operation){
        case 0:           
            easy.value1 = rand() % 11;
            easy.value2 = rand() % 11;
            question = (easy.value1 + easy.value2);
                
            printf("|-------------------------------------------|\n");
            printf("|---------------   Responda   --------------|\n");
            printf("|-------------------------------------------|\n");
            printf("|                 %d + %d = ?               \n",easy.value1,easy.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%f",&answer);

            if (answer == question){
                printf("\n|Resposta Certa!\n");
                printf("Resposta certa: %f",question);
                points ++;
                    
                printf("Vidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\n|Resposta Errada!");
                printf("Resposta certa: %f",question);
                lifes --;
                    
                printf("Vidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("Game Over");

                    system("pause");
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
            printf("|                 %d - %d = ?               \n",easy.value1,easy.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%f",&answer);

            if (answer == question){
                printf("\n|Resposta Certa!\n");
                printf("Resposta certa: %f",question);
                points ++;
                    
                printf("Vidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\n|Resposta Errada!");
                printf("Resposta certa: %f",question);
                lifes --;
                    
                printf("Vidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("Game Over");

                    system("pause");
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
            printf("|                 %d * %d = ?               \n",easy.value1,easy.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%f",&answer);

            if (answer == question){
                printf("\n|Resposta Certa!\n");
                printf("Resposta certa: %f",question);
                points ++;
                    
                printf("Vidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\n|Resposta Errada!");
                printf("Resposta certa: %f",question);
                lifes --;
                    
                printf("Vidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("Game Over");

                    system("pause");
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

        case 3:    
            easy.value1 = rand() % 11;
            easy.value2 = rand() % 11;
            question = (easy.value1 / easy.value2);
                
            printf("|-------------------------------------------|\n");
            printf("|---------------   Responda   --------------|\n");
            printf("|-------------------------------------------|\n");
            printf("|                 %d / %d = ?               \n",easy.value1,easy.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%f",&answer);

            if (answer == question){
                printf("\n|Resposta Certa!\n");
                printf("Resposta certa: %f",question);
                points ++;
                    
                printf("Vidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\n|Resposta Errada!");
                printf("Resposta certa: %f",question);
                lifes --;
                    
                printf("Vidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("Game Over");

                    system("pause");
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
        }

    }while(option == 1);
    
    mainMenu(option);
}

void mediumGame(){

}

void hardGame(){

}

void legendGame(){

}

void easyScore(){

}

void mediumScore(){

}

void hardScore(){

}

void legendScore(){

}