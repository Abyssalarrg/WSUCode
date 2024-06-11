#include <iostream>
#include <ctime> // for seeding the random number generator
#include <cstdlib> // for generatin random numbers with rand()
using namespace std;

int main() { //BEGIN INTRO
  srand(time(NULL));
  cout << "Welcome to your Grand Adventure! \n";
  cout << "You are a brand new Gladiator looking to make a name for themselves and a little bit of money along the way. \n";
  cout << "First off what is your name? \n";

  string playerName ="";
  cin >> playerName;

  cout << "Hello " << playerName << "! \n";
  cout << "As a new fighter you only have a little bit of Health and no Gold. \n";
  cout << "Every round you will be given the choice of battling a new enemy for gold and glory \n";
  cout << "\t or retreating home to safety with your newfound wealth and fame. \n";
  cout << "If your health reaches 0 you will be defeated and your adventure will end. \n";
  cout << "Now " << playerName << " are you ready to begin your adventure? (y/n) \n"; 

  char answerYN = ' ';
  cin >> answerYN;

  if(answerYN == 'y'){
    cout << "Great! Let's begin your adventure! \n";
  } else{
    cout << "Thats a shame. You would have been a mighty fine warrior. \n";
    return 0;
  }

  bool playerAdventure = true;
  int playerHealth = 30;
  int playerGold = 0;
  int rounds = rand() % 20 +1;
  int wins = 0;

  while(playerAdventure == true && playerHealth > 0 && rounds != 0){  //START OF COMBAT LOOP
    cout << "Warrior " << playerName << " you have " << playerHealth << " health and " << playerGold << " Gold. \n";
    cout << "There are " << rounds << " enemies left to defeat. \n";
    cout << "You have defeated " << wins << " enemies. \n";
    cout << "You carry on your adventure and find a worthy adversary. \n";

    int playerAttack = rand() % 20 +1;
    int opponentAttack = rand() % 20 +1;
    int gold = rand() % 12 +1;
    int damage = rand() % 8 +1;

    if(playerAttack > opponentAttack){ //PLAYER BEATS OPPONENT
      cout << "You block your opponents attack and deal " << damage << " damage. \n";
      cout << "You have defeated your adversary and gained " << gold << "gold. \n";
      playerGold = playerGold + gold;
      wins = wins + 1;
      rounds = rounds - 1;

      if(rounds == 0){ //CHECK IF ANY OPPONENTS REMAIN
        cout << "You were a mighty Warrior indeed! You have defeated all wiling combatants and retired home with " << playerGold << " gold and " << playerHealth << " health. \n";
        cout << "You have defeated " << wins << " enemies. \n";
        cout << "Thank you for playing! \n";
      }else{
        cout << "You have " << playerHealth << " health and " << playerGold << " gold. \n";
        cout << "You have defeated " << wins << " enemies. \n";
        cout << "Do you want to continue? (y/n) \n";

        char answerYN = ' '; //DOES PLAYER WANT TO CONTINUE
        cin >> answerYN;
        if(answerYN == 'y'){
          playerAdventure = true;
        } else {
          playerAdventure = false;
          cout << "You have retreated home with " << playerGold << " gold and " << playerHealth << " health. \n";
          cout << "Thanks for Playing!! \n";
        }
      }     
    } else { //OPPONENT BEATS PLAYER
      cout << "Your opponent evades your assault and deals a devestating blow. \n";
      cout << "You have been defeated by your adversary and lost " << damage << " health. \n";
      playerHealth = playerHealth - damage;
      if(playerHealth < 10){ //CHECK IF PLAYER NEEDS A MEDIC
        cout << "BEWARE!! You are critically wounded. You should see a medic! \n";
      }
      if(playerHealth <= 0){ //CHECK IF PLAYER IS DEAD
        cout << "You have been slain and lost " << playerGold << "gold. \n";
        cout << "Thanks for Playing!! \n";
        
      } else { //PLAYER IS ALIVE AND WELL. DO THEY WISH TO CONTINUE?
        cout << "You have " << playerHealth << " health and " << playerGold << " gold. \n";
        cout << "Do you want to continue? (y/n) \n";

        char answerYN = ' ';
        cin >> answerYN;
        if(answerYN == 'y'){
          playerAdventure = true;
        } else {
          playerAdventure = false;
          cout << "You have retreated home with " << playerGold << " gold and " << playerHealth << " health. \n";
          cout << "Thanks for Playing!! \n";
        }
      }
    }
  }
  

}
