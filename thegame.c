#include "thegame.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char *Choices[3] = {"Rock", "Paper", "Scissors"};

int HowManyRounds()
{
    int rounds;
    char *str;
    do{
        str = "How many rounds you want to play ?\n\0";
        ft_putstr(str);
        scanf("%d", &rounds);
    }while (rounds < 0);
    return rounds;    
}
void Start_Round(int num)
{
    ft_putstr("--->Start Round : ");
    ft_putnbr(num);
    ft_putchar('\n');
}

int ComputerChoice()
{
    int Choice;
    srand(time(NULL));
    Choice = rand() % 3;
    return Choice;
}
int UserChoice()
{
    int Choice;
    do{ 
        ft_putstr("Your Choice (1- Rock/ 2- Paper/ 3- Scissors): ");
        ft_putchar('\n');
        scanf("%d", &Choice);
    }while (Choice > 3 || Choice <= 0);
    return (Choice - 1);
}
void ShowingChoices(int Computer, int User)
{
    ft_putstr("Computer : ");
    ft_putstr(Choices[Computer]);
    ft_putchar('\n');
    ft_putstr("User : ");
    ft_putstr(Choices[User]);
    ft_putchar('\n');
}
char *TheRoundResult(int Computer, int User)
{
    if (User == 0)
    {
        if (Computer == 0)
            return "Draw";
        else if (Computer == 1 )
            return "Lose";
        else 
            return "Win";
    }
    if (User == 1)
    {
        if (Computer == 0)
            return "Win";
        else if (Computer == 1)
            return "Draw";
        else 
            return "Lose";
    }
    else 
    {
        if (Computer == 0)
            return "Lose";
        else if (Computer == 1)
            return "Win";
        else 
            return "Draw";
    }
}
void ResetTheColors()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wAttributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | 0; // Set green background and text
    SetConsoleTextAttribute(hConsole, wAttributes);
}
void WinColorMode()
{ 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wAttributes = FOREGROUND_BLUE | BACKGROUND_GREEN; // Set green background and text
    SetConsoleTextAttribute(hConsole, wAttributes);
    
}
void LoseColorMode()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wAttributes = 0 | BACKGROUND_RED;
    SetConsoleTextAttribute(hConsole, wAttributes);
}
void TieColorMode()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wAttributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN;
    SetConsoleTextAttribute(hConsole, wAttributes);
}
void ColorEffects(char *RoundResult)
{
    if (RoundResult == "Win")
    {
        WinColorMode();
        ft_putstr(RoundResult);
        ft_putchar('\n'); 
    }
    else if (RoundResult == "Lose")
    {
        LoseColorMode();
        ft_putstr(RoundResult);
        ft_putchar('\n');
    }
    else 
    {
        TieColorMode();
        ft_putstr(RoundResult);
        ft_putchar('\n');
    }
}

void PlayWinSound() {
    Beep(523, 200);
    Beep(587, 200);
    Beep(659, 200);
    Beep(784, 400);
}
void PlayLoseSound() {
    Beep(784, 200);  
    Beep(659, 200);
    Beep(523, 400); 
}
void PlayDrawSound() {
    Beep(659, 200);
    Beep(659, 200); 
    Beep(659, 400);
}
void SoundEffects(char *RoundResult)
{
    if (RoundResult == "Win")
        PlayWinSound();
    else if (RoundResult == "Lose")
        PlayLoseSound();
    else 
        PlayDrawSound();
}
void FinalColorAndSoundsEffects(int Score1, int Score2)
{
    if (Score1 > Score2)
    {
        LoseColorMode();
        PlayLoseSound();
    }
    else if (Score2 > Score1)\
    {
        WinColorMode();
        PlayWinSound();
    }
    else 
    {
        TieColorMode();
        PlayDrawSound();
    }
}
void PrintingTheFinalScore(int Score1, int Score2)
{
    Beep(750, 800);
    FinalColorAndSoundsEffects(Score1, Score2);
    ft_putstr("\t\t\t\tFINAL SCORE :\n");
    ft_putstr("\t\t\t-------------------------------\n");
    ft_putstr("\t\t\t>The Computer : ");
    ft_putnbr(Score1);
    ft_putstr("\n\t\t\t>The User : ");
    ft_putnbr(Score2);
    ft_putchar('\n');
    ft_putchar('\n');
}
void GameInEachRound(int Choice)
{
    ShowingChoices(ComputerChoice(), Choice);
    ColorEffects(TheRoundResult(ComputerChoice(), Choice));
    SoundEffects(TheRoundResult(ComputerChoice(), Choice));
}
void GameMode(int num)
{
    int i;
    int ComputerScore;
    int UserScore;
    int UsChoice;
    int CopChoice;
    char *str1;
    char *str2;
    str1 = "Win";
    str2 = "Lose";
    ComputerScore = 0;
    UserScore = 0;
    i = 1;
    while (i <= num)
    {
        Start_Round(i);
        UsChoice = UserChoice();
        CopChoice = ComputerChoice();
        GameInEachRound(UsChoice);
        if (ft_strcmp(TheRoundResult(CopChoice, UsChoice), str1) == 0)
            UserScore++;
        else if (ft_strcmp(TheRoundResult(CopChoice, UsChoice), str2) == 0)
            ComputerScore++;
        i++;
    }
    PrintingTheFinalScore(ComputerScore, UserScore);
}
char AskAboutPlaying()
{
    char c;
    do {
        ft_putstr("Do you want to play ?[y/n]\n");
        scanf(" %c",&c);
    }while (((c != 'y' && c != 'Y') && (c != 'n' && c != 'N')));
    ResetTheColors();
    system("cls");
    return c;
}
void GameStart()
{
    char c;
    int num;
    c = AskAboutPlaying();
    while (c != 'n' && c != 'N')
    {
        num = HowManyRounds();
        GameMode(num); 
        c = AskAboutPlaying(); 
    }   
}

int main()
{
    GameStart();
}