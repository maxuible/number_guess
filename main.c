#include <stdio.h>
#include <time.h>

//https://en.wikipedia.org/wiki/Linear_congruential_generator
#define a 6364136223846793005
#define c 1
#define m 4294967296

int* lcg(int* seed)
{
    *seed = (a * *seed + c) % m;

    return seed;

}

int main()
{
    int seed = time(NULL);
    printf("Welcome to the guessing game!\n");

    printf("I am thinking of a number 1-100\n");
    printf("You get 10 guesses\n");
    lcg(&seed);
    

    int random_number = seed % 100;

    if (random_number < 0) {
        random_number = random_number * -1;
    }

    for (int i = 0; i < 10; i++) {
        int guess = -1;
        printf("Guess #%d?\n", i + 1);
        scanf("%d", &guess);
        printf("You guessed :%d\n", guess);

        if (guess > random_number) {
            printf("You guessed too high!\n");
        } else if (guess < random_number) {
            printf("You guessed too low!\n");
        } else if (guess == random_number) {
            printf("YOU GUESSED CORRECTLY CONGRATULATIONS!!!\n");
            return 0;
        }

    }
    printf("You used all 10 guesses... try again.\n");

    return 0;
}



