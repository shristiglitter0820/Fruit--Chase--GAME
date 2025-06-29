#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define NUM_FRUITS 8
#define NUM_CHARACTERS 8

typedef struct {
    int x;
    int y;
} Position;

const char *fruit_emojis[NUM_FRUITS] = {
    "🍎", "🍇", "🫐", "🍓", "🍒", "🍌", "🥑", "🍍"
};

const char *character_emojis[NUM_CHARACTERS] = {
    "👻", "💀", "☠️", "👹", "👽", "🤡", "👺", "👾"
};

void print_position(Position pos) {
    printf("(%d, %d)", pos.x, pos.y);
}

void print_matrix(Position character, const char *character_symbol, Position fruit, const char *fruit_symbol) {
    printf("\nMatrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (character.x == i && character.y == j)
                printf(" %s ", character_symbol);
            else if (fruit.x == i && fruit.y == j)
                printf(" %s ", fruit_symbol);
            else
                printf(" ⬜ ");
        }
        printf("\n");
    }
}

Position get_random_position_exclude(Position exclude) {
    Position pos;
    do {
        pos.x = rand() % SIZE;
        pos.y = rand() % SIZE;
    } while (pos.x == exclude.x && pos.y == exclude.y);
    return pos;
}

int is_diagonal_move(Position from, Position to)//to make a diagonal move both the coordinates should not be matching,otherwise it becomes a non diagonal move
 {
    return (from.x != to.x && from.y != to.y);
}

int main() {
    srand(time(NULL));

    Position character = {0, 0};
    Position fruit = get_random_position_exclude(character);

    int fruit_index = 0;
    int character_index = 0;

    const char *fruit_symbol = fruit_emojis[fruit_index];
    const char *character_symbol = character_emojis[character_index];

    int score = 0;

    printf("Welcome to the Fruit Chase Game!\n");
    printf("You control spooky characters starting at (0,0).\n");
    printf("You have 2 moves per round. No diagonal moves allowed!\n");
    printf("Enter coordinates for each move (x y), between 0 and 4.\n");

    while (1) {
        print_matrix(character, character_symbol, fruit, fruit_symbol);
        printf("Current position: ");
        print_position(character);
        printf(" | Emoji: %s\n", character_symbol);
        printf("Your current score: %d\n", score);

        Position move;

        // Move 1
        printf("Enter coordinates for Move 1: ");
        if (scanf("%d %d", &move.x, &move.y) != 2)//checks whether the player has entered 2 moves or not
         {
            printf("Invalid input format. Game over.\n");
            break;
        }
        if (move.x < 0 || move.x >= SIZE || move.y < 0 || move.y >= SIZE)//checks whether the move is out of bounds or not
         {
            printf("Move 1 coordinates out of bounds. Game over.\n");
            break;
        }
        if (is_diagonal_move(character, move)) //checks whether it is a diagonal move or not
        {
            printf("❌ Invalid move: Diagonal movement not allowed. Move 1 used.\n");
        } else {
            character = move;//otherwise it moves the charcter to the position entered
        }

        print_matrix(character, character_symbol, fruit, fruit_symbol);
        printf("Character moved to ");
        print_position(character);
        printf("\n");
        
        //after it has moved it checks whether the charcter and fruit position matches 
        if (character.x == fruit.x && character.y == fruit.y) 
        {
            score++;
            printf("🎉 You caught the %s at ", fruit_symbol);
            print_position(fruit);
            printf("! Score: %d\n", score);

            // Advance to next fruit and character emoji
            fruit_index = (fruit_index + 1) % NUM_FRUITS;
            character_index = (character_index + 1) % NUM_CHARACTERS;

            fruit = get_random_position_exclude(character);
            fruit_symbol = fruit_emojis[fruit_index];
            character_symbol = character_emojis[character_index];
            continue;
        }

        // Move 2
        printf("Enter coordinates for Move 2: ");
        if (scanf("%d %d", &move.x, &move.y) != 2) {
            printf("Invalid input format. Game over.\n");
            break;
        }
        if (move.x < 0 || move.x >= SIZE || move.y < 0 || move.y >= SIZE) {
            printf("Move 2 coordinates out of bounds. Game over.\n");
            break;
        }
        if (is_diagonal_move(character, move)) {
            printf("❌ Invalid move: Diagonal movement not allowed. Move 2 used.\n");
        } else {
            character = move;
        }

        print_matrix(character, character_symbol, fruit, fruit_symbol);
        printf("Character moved to ");
        print_position(character);
        printf("\n");

        if (character.x == fruit.x && character.y == fruit.y) {
            score++;
            printf("🎉 You caught the %s at ", fruit_symbol);
            print_position(fruit);
            printf("! Score: %d\n", score);

            fruit_index = (fruit_index + 1) % NUM_FRUITS;
            character_index = (character_index + 1) % NUM_CHARACTERS;

            fruit = get_random_position_exclude(character);
            fruit_symbol = fruit_emojis[fruit_index];
            character_symbol = character_emojis[character_index];
        } else {
            printf("💀 You missed the fruit. Game over.\n");
            break;
        }
    }

    printf("🏁 Final score: %d. Thanks for playing!\n", score);
    return 0;
}