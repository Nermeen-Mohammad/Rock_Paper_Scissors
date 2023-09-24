

#include <iostream>
#include<cstdlib>
using namespace std;

enum enGameChoice { Rock= 1, Paper = 2, ٍScissors = 3 };
enum enWinner     { Player = 1, Computer = 2, Draw = 3 };

struct strGameResults {

    short GameRound = 0;
    short PlayerWinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";


};

struct strRoundInfo {
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

short ReadHowManyRounds(string message)
{
    short HowManyRounds = 1;
    do
    {
        cout << message;
        cin >> HowManyRounds;
    } while (HowManyRounds < 0 && HowManyRounds >= 10);
    return HowManyRounds;
}

int RandomNumber(int From, int To)
{
    int RandomNumber = rand() % (To - From + 1) + From;
    return RandomNumber;
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = { "Player", "Computer", "No Winner" };
    return arrWinnerName[Winner - 1];
}

enGameChoice ReadPlayerChoice()
{
    short choice = 1;
    do
    {
        cout << "\n Your Choice: [1]:Rock, [2]:Paper, [3]:Scissors? ";
        cin >> choice;

    } while (choice < 1 || choice>3);
    return enGameChoice(choice);
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

string ChoiceName(enGameChoice Choice)
{
    string arrChoice[3] = { "Rock","Paper"," Scissors" };
    return arrChoice[Choice - 1];
}

enWinner WhoWonTheRound(strRoundInfo RoundInfo)
{

    if (RoundInfo.ComputerChoice == RoundInfo.PlayerChoice)
    {
        return  enWinner::Draw;
    }
    switch (RoundInfo.PlayerChoice)
    {
    case enGameChoice::Rock:
    {
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
            return enWinner::Computer;
    }
    break;

    case enGameChoice::ٍScissors: {
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
            return enWinner::Computer;
    }
                                break;
    case  enGameChoice::Paper: {
        if (RoundInfo.ComputerChoice == enGameChoice::ٍScissors)
            return enWinner::Computer;
    }
                             break;
    }
    return enWinner::Player;
}

void PrintRoundResult(strRoundInfo RoundInfo)
{
    cout << "\n_ _ _ _ _ _ _ _ _ _ _ [" << RoundInfo.RoundNumber << "] _ _ _ _ _ _ _ _ _ _ _\n\n";
    cout << "Player Choice: " << ChoiceName(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner: [" << RoundInfo.RoundNumber << "]\n";
        cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";

}

enWinner WhiWonTheGame(short PlayerWinTimes, short  ComputerWinTimes)
{
    if (PlayerWinTimes > ComputerWinTimes)
        return enWinner::Player;
    else if (PlayerWinTimes < ComputerWinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;

}

strGameResults FillGameResults(int HowManyRounds, short PlayerWinTimes, short  ComputerWinTimes, short DrawTimes)   
{
    strGameResults GameResult;
    GameResult.GameRound = HowManyRounds;
    GameResult.PlayerWinTimes = PlayerWinTimes;
    GameResult.ComputerWinTimes = ComputerWinTimes;
    GameResult.DrawTimes = DrawTimes;
    GameResult.GameWinner = WhiWonTheGame(PlayerWinTimes, ComputerWinTimes);
    GameResult.WinnerName = WinnerName(GameResult.GameWinner);

    return GameResult;
}

strGameResults PlayGame(short HowManyRounds)
{
    strRoundInfo RoundInfo;
    short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
    
    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
       
        cout <<"\nRound [" << GameRound << "] begins : \n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.PlayerChoice = ReadPlayerChoice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else if (RoundInfo.Winner == enWinner::Player)
            PlayerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResult(RoundInfo);
}
   return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOgTabs)
{
    string t = "";
    for (int i = 1; i <= NumberOgTabs; i++) {
        t = t + '\t';
        cout << t;
    }
    return t;
}

void ShowGameOverScreen()
{
    cout << Tabs(2) << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n";
    cout << Tabs(2) << "                       +++  G a m e O v e r  +++\n";
    cout << Tabs(2) << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n";
}

void SetWinnerScreenColor(enWinner winner)

    {
        switch (winner)
        {
        case enWinner::Computer:
            system("color 4f");
            cout << "\a";
            break;


        case enWinner::Player:
            system("color 2f");
            break;

        default:
            system("color 6f");
            break;

        }
    }

void ShowFinalGameResult(strGameResults GameResults)
{
    cout << Tabs(2) << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _[Game Result]_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
    cout << Tabs(2) << "Game Rounds         : " << GameResults.GameRound << endl;
    cout << Tabs(2) << "Player Won Times    : " << GameResults.PlayerWinTimes << endl;
    cout << Tabs(2) << "Computer Won Times  : " << GameResults.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw Times          : " << GameResults.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner        : " << GameResults.WinnerName << endl;
    cout << Tabs(2) << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";

    SetWinnerScreenColor(GameResults.GameWinner);
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';
    do {
        ResetScreen();
        strGameResults GameResult = PlayGame(ReadHowManyRounds("How many rounds 1 to 10 ? "));
        ShowGameOverScreen();
        ShowFinalGameResult(GameResult);

        cout << endl << Tabs(3) << "Do you wat to play again? Y/N ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));
    
    StartGame();

}
