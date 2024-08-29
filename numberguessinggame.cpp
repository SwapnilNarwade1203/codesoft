#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

class Game {
private:
    int targetNumber;
    int userGuess;
    int numberOfGuesses;

public:
    // Constructor to initialize the random number and seed
    Game() {
        srand(static_cast<unsigned>(time(0))); // Seed the random number generator
        generateRandomNumber();
        numberOfGuesses = 0;
    }

    // Generate a random number between 0 and 99
    void generateRandomNumber() {
        targetNumber = rand() % 100; // Generates a number between 0 and 99
    }

    // Get user input and provide hints
    void getUserInput() {
        do {
            std::cout << "Guess the number: ";
            std::cin >> userGuess;

            if (targetNumber > userGuess) {
                std::cout << "Think of a bigger number." << std::endl;
            } else if (targetNumber < userGuess) {
                std::cout << "Think of a smaller number." << std::endl;
            }

            numberOfGuesses++;
        } while (targetNumber != userGuess);
    }

    // Print the result when the user guesses correctly
    void printResult() const {
        std::cout << "Correct Guess!" << std::endl;
        std::cout << "Total number of guesses: " << numberOfGuesses << std::endl;
        if (numberOfGuesses <= 3) {
            std::cout << "Pro player" << std::endl;
        } else if (numberOfGuesses > 3 && numberOfGuesses < 7) {
            std::cout << "Good player" << std::endl;
        } else {
            std::cout << "Nice try but can do better" << std::endl;
        }
    }
};

int main() {
    std::cout << "LET'S GOOOOOOO!" << std::endl;
    Game player;
    player.getUserInput();
    player.printResult();
    return 0;
}
