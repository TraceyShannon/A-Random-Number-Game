#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct players {
  char username[30][30];
};

void get_username (struct players *);

int random_num ();

int start_game (struct players *);

// ==== Begin Main Function ==== //
int main() {

  int res = -1;

  struct players player_1;
  get_username (&player_1);
  res = start_game(&player_1);

  if (res == 0) {
    printf("\nOh My God!! You Did It You Saved Us All!!!!!\n");
    printf("\nYou're A Real Hero!!\n\n");
  } else if (res == 1) {
    printf("\nAHHHHHHHHHHHHHHHH!!!!!!!!!\n");
    printf("\nI Cant Believe It... \n");
    printf("\nEverybody's dead...\n\n");
  } else {
    printf("What Happened?!?!?!\n");
  }


  return 0;
}
// ==== End Main Function ==== //

int random_num () {
  int num = 0;
  srand(time(0));

  num = rand() % 3;
  // printf("%d\n", num);
  return num;
}

void get_username (struct players *name) {
  printf("What Would You Like Your Username To Be: ");
  scanf("%s", *name->username);
}

int start_game (struct players *name) {

  int arr = 2;
  int guess[arr];
  int answer[arr];
  for (int i = 0; i < arr; i++) {
    answer[i] = random_num();
  }
  printf("Alright %s Let's Go!\n", *name->username);

  printf("\nYour Mission Is To Guess The Number The Bomber Set To Deactivate His Bomb!!\n");

  printf("\nWhat's The Deactivation Code?!?!\n");
  for (int i = 0; i < arr; i++) {
    scanf("%d", &guess[i]);
  }

  for (int i = 0; i < arr; i++) {
    printf("The Answer For Integer %d Is %d And Your Guess Is %d\n", i, answer[i], guess[i]);
    if (guess[i] != answer[i]) {
      return 1;
    }
  }

  return 0;
}
