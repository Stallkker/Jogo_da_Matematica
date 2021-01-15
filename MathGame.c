#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <locale.h>


FILE *scoreEasy;
FILE *scoreMedium;
FILE *scoreHard;


typedef struct game{
    
    int operation;
    int value1;
    int value2;

}math;



void mainMenu(int option);

void chooseDifficulty(int option);
void chooseScore(int option);

void easyGame(int option);
void mediumGame(int option);
void hardGame(int option);

void easyScore(int option);
void mediumScore(int option);
void hardScore(int option);


int main(){

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int option;

    mainMenu(option);

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
        mediumGame(option);
        break;
    case 3:
        hardGame(option);
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
        easyScore(option);
        break;
    case 2:
        mediumScore(option);
        break;
    case 3:
        hardScore(option);
        break;
    case 4:
        mainMenu(option);
    }
}



void easyGame(int option){

    scoreEasy = fopen("scoreEasy.txt", "a+");

    char name[10];

    math easy;
    
    short int lifes = 3;
    int points = 0;
    
    int answer;
    int question;

    printf("|-------------------------------------------|\n");
    printf("|------------  Escreva seu nome  -----------|\n");
    printf("|----------  Max de caracteres: 10  --------|\n");
    printf("|-------------------------------------------|\n");
    printf("|Nome: ");
    scanf("%s",&name);

    system("cls");

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
            printf("                 %d + %d = ?               \n",easy.value1,easy.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%d",&answer);

            if (answer == question){
                printf("\nResposta Certa!\n");
                printf("Resposta certa: %d\n",question);
                points ++;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\nResposta Errada!\n");
                printf("Resposta certa: %d\n",question);
                lifes --;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("\n!!!!!!!!!!!!!Game Over!!!!!!!!!!!!!\n");
                    
                    fprintf(scoreEasy,"%s %d\n",name, points);
                    fclose(scoreEasy);
                    
                    printf("Placar salvo!\n\n");
                    
                    system("pause");
                    system("cls");

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
            printf("                 %d - %d = ?               \n",easy.value1,easy.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%d",&answer);

            if (answer == question){
                printf("\nResposta Certa!\n");
                printf("Resposta certa: %d\n",question);
                points ++;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\nResposta Errada!\n");
                printf("Resposta certa: %d\n",question);
                lifes --;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("\n!!!!!!!!!!!!!Game Over!!!!!!!!!!!!!\n");
                    
                    fprintf(scoreEasy,"%s %d\n",name, points);
                    fclose(scoreEasy);
                    
                    printf("Placar salvo!\n\n");
                    
                    system("pause");
                    system("cls");

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
            printf("                 %d * %d = ?               \n",easy.value1,easy.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%d",&answer);

            if (answer == question){
                printf("\nResposta Certa!\n");
                printf("Resposta certa: %d\n",question);
                points ++;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\nResposta Errada!\n");
                printf("Resposta certa: %d\n",question);
                lifes --;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("\n!!!!!!!!!!!!!Game Over!!!!!!!!!!!!!\n");
                    
                    fprintf(scoreEasy,"%s %d\n",name, points);
                    fclose(scoreEasy);
                    
                    printf("Placar salvo!\n\n");
                    
                    system("pause");
                    system("cls");

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

        fprintf(scoreEasy,"%s %d\n",name, points);
        printf("\n!!!!!!!!!!!!!Placar salvo!!!!!!!!!!!!!\n\n");
        system("pause");
        system("cls");
    }

    fclose(scoreEasy);

    mainMenu(option);
}



void mediumGame(int option){
    scoreMedium = fopen("scoreMedium.txt", "a+");

    char name[10];

    math medium;
    
    short int lifes = 3;
    int points = 0;
    
    int answer;
    int question;

    printf("|-------------------------------------------|\n");
    printf("|------------  Escreva seu nome  -----------|\n");
    printf("|----------  Max de caracteres: 10  --------|\n");
    printf("|-------------------------------------------|\n");
    printf("|Nome: ");
    scanf("%s",&name);

    system("cls");

    do{
        
        medium.operation = rand() % 3;

        switch(medium.operation){

        case 0:       
            medium.value1 = rand() % 101;
            medium.value2 = rand() % 101;
            question = (medium.value1 + medium.value2);
                
            printf("|-------------------------------------------|\n");
            printf("|---------------   Responda   --------------|\n");
            printf("|-------------------------------------------|\n");
            printf("                 %d + %d = ?               \n",medium.value1,medium.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%d",&answer);

            if (answer == question){
                printf("\nResposta Certa!\n");
                printf("Resposta certa: %d\n",question);
                points ++;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\nResposta Errada!\n");
                printf("Resposta certa: %d\n",question);
                lifes --;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("\n!!!!!!!!!!!!!Game Over!!!!!!!!!!!!!\n");
                    
                    fprintf(scoreMedium,"%s %d\n",name, points);
                    fclose(scoreMedium);
                    
                    printf("Placar salvo!\n\n");
                    
                    system("pause");
                    system("cls");

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
            medium.value1 = rand() % 101;
            medium.value2 = rand() % 101;
            question = (medium.value1 - medium.value2);
                
            printf("|-------------------------------------------|\n");
            printf("|---------------   Responda   --------------|\n");
            printf("|-------------------------------------------|\n");
            printf("                 %d - %d = ?               \n",medium.value1,medium.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%d",&answer);

            if (answer == question){
                printf("\nResposta Certa!\n");
                printf("Resposta certa: %d\n",question);
                points ++;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\nResposta Errada!\n");
                printf("Resposta certa: %d\n",question);
                lifes --;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("\n!!!!!!!!!!!!!Game Over!!!!!!!!!!!!!\n");
                    
                    fprintf(scoreMedium,"%s %d\n",name, points);
                    fclose(scoreMedium);
                    
                    printf("Placar salvo!\n\n");
                    
                    system("pause");
                    system("cls");

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
            medium.value1 = rand() % 101;
            medium.value2 = rand() % 101;
            question = (medium.value1 * medium.value2);
                
            printf("|-------------------------------------------|\n");
            printf("|---------------   Responda   --------------|\n");
            printf("|-------------------------------------------|\n");
            printf("                 %d * %d = ?               \n",medium.value1,medium.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%d",&answer);

            if (answer == question){
                printf("\nResposta Certa!\n");
                printf("Resposta certa: %d\n",question);
                points ++;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\nResposta Errada!\n");
                printf("Resposta certa: %d\n",question);
                lifes --;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("\n!!!!!!!!!!!!!Game Over!!!!!!!!!!!!!\n");
                    
                    fprintf(scoreMedium,"%s %d\n",name, points);
                    fclose(scoreMedium);
                    
                    printf("Placar salvo!\n\n");
                    
                    system("pause");
                    system("cls");

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
    
    if (scoreMedium == NULL){
    
        printf("Comunique o administrador!\n");
        system("pause");
        exit(0);
    
    }else{

        fprintf(scoreMedium,"%s %d\n",name, points);
        printf("\n!!!!!!!!!!!!!Placar salvo!!!!!!!!!!!!!\n\n");
        system("pause");
        system("cls");
    }

    fclose(scoreMedium);

    mainMenu(option);
}



void hardGame(int option){
    scoreHard = fopen("scoreHard.txt", "a+");

    char name[10];

    math hard;
    
    short int lifes = 3;
    int points = 0;
    
    int answer;
    int question;

    printf("|-------------------------------------------|\n");
    printf("|------------  Escreva seu nome  -----------|\n");
    printf("|----------  Max de caracteres: 10  --------|\n");
    printf("|-------------------------------------------|\n");
    printf("|Nome: ");
    scanf("%s",&name);

    system("cls");

    do{
        
        hard.operation = rand() % 3;

        switch(hard.operation){

        case 0:       
            hard.value1 = rand() % 1001;
            hard.value2 = rand() % 1001;
            question = (hard.value1 + hard.value2);
                
            printf("|-------------------------------------------|\n");
            printf("|---------------   Responda   --------------|\n");
            printf("|-------------------------------------------|\n");
            printf("                 %d + %d = ?               \n",hard.value1,hard.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%d",&answer);

            if (answer == question){
                printf("\nResposta Certa!\n");
                printf("Resposta certa: %d\n",question);
                points ++;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\nResposta Errada!\n");
                printf("Resposta certa: %d\n",question);
                lifes --;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("\n!!!!!!!!!!!!!Game Over!!!!!!!!!!!!!\n");
                    
                    fprintf(scoreHard,"%s %d\n",name, points);
                    fclose(scoreHard);
                    
                    printf("Placar salvo!\n\n");
                    
                    system("pause");
                    system("cls");

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
            hard.value1 = rand() % 1001;
            hard.value2 = rand() % 1001;
            question = (hard.value1 - hard.value2);
                
            printf("|-------------------------------------------|\n");
            printf("|---------------   Responda   --------------|\n");
            printf("|-------------------------------------------|\n");
            printf("                 %d - %d = ?               \n",hard.value1,hard.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%d",&answer);

            if (answer == question){
                printf("\nResposta Certa!\n");
                printf("Resposta certa: %d\n",question);
                points ++;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\nResposta Errada!\n");
                printf("Resposta certa: %d\n",question);
                lifes --;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("\n!!!!!!!!!!!!!Game Over!!!!!!!!!!!!!\n");
                    
                    fprintf(scoreHard,"%s %d\n",name, points);
                    fclose(scoreHard);
                    
                    printf("Placar salvo!\n\n");
                    
                    system("pause");
                    system("cls");

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
            hard.value1 = rand() % 1001;
            hard.value2 = rand() % 1001;
            question = (hard.value1 * hard.value2);
                
            printf("|-------------------------------------------|\n");
            printf("|---------------   Responda   --------------|\n");
            printf("|-------------------------------------------|\n");
            printf("                 %d * %d = ?               \n",hard.value1,hard.value2);
            printf("|-------------------------------------------|\n");
            printf("|Resposta:  ");
            scanf("%d",&answer);

            if (answer == question){
                printf("\nResposta Certa!\n");
                printf("Resposta certa: %d\n",question);
                points ++;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                system("pause");
            }else{
                printf("\nResposta Errada!\n");
                printf("Resposta certa: %d\n",question);
                lifes --;
                    
                printf("\nVidas: %d\n",lifes);
                printf("Pontos: %d\n",points);
                    
                if (lifes == 0){
                    printf("\n!!!!!!!!!!!!!Game Over!!!!!!!!!!!!!\n");
                    
                    fprintf(scoreHard,"%s %d\n",name, points);
                    fclose(scoreHard);
                    
                    printf("Placar salvo!\n\n");
                    
                    system("pause");
                    system("cls");

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
    
    if (scoreHard == NULL){
    
        printf("Comunique o administrador!\n");
        system("pause");
        exit(0);
    
    }else{

        fprintf(scoreHard,"%s %d\n",name, points);
        printf("\n!!!!!!!!!!!!!Placar salvo!!!!!!!!!!!!!\n\n");
        system("pause");
        system("cls");
    }

    fclose(scoreHard);

    mainMenu(option);
}


void easyScore(int option){
            
    scoreEasy = fopen("scoreEasy.txt", "a+");
    
    char stringFile[100];
    char *pointerFile;

    printf("|-------------------------------------------|\n");
    printf("|-----------  Score modo Facil  ------------|\n");
    printf("|-------------------------------------------|\n");

    while(!feof(scoreEasy)){
      pointerFile = fgets(stringFile, 100, scoreEasy);
      
      if(pointerFile){
	    printf("                 %s",pointerFile);
      }
    }

    printf("\n");

    fclose(scoreEasy);
    system("pause");
    system("cls");
    mainMenu(option);

}

void mediumScore(int option){
    scoreMedium = fopen("scoreMedium.txt", "a+");
    
    char stringFile[100];
    char *pointerFile;

    printf("|-------------------------------------------|\n");
    printf("|-----------  Score modo Facil  ------------|\n");
    printf("|-------------------------------------------|\n");

    while(!feof(scoreMedium)){
      pointerFile = fgets(stringFile, 100, scoreMedium);
      
      if(pointerFile){
	    printf("                 %s",pointerFile);
      }
    }

    printf("\n");

    fclose(scoreMedium);
    system("pause");
    system("cls");
    mainMenu(option);
}

void hardScore(int option){
    scoreHard = fopen("scoreHard.txt", "a+");
    
    char stringFile[100];
    char *pointerFile;

    printf("|-------------------------------------------|\n");
    printf("|-----------  Score modo Facil  ------------|\n");
    printf("|-------------------------------------------|\n\n");

    while(!feof(scoreHard)){
      pointerFile = fgets(stringFile, 100, scoreHard);
      
      if(pointerFile){
	    printf("                  %s",pointerFile);
      }
    }

    printf("\n");

    fclose(scoreHard);
    system("pause");
    system("cls");
    mainMenu(option);
}