#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int number, guess, attempts = 0;
    srand(time(0));
    number = rand() % 100 + 1; 

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100. Try to guess it!" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > number) {
            cout << "Too high! Try a smaller number." << endl;
        } else if (guess < number) {
            cout << "Too low! Try a larger number." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts!" << endl;
        }
    } while (guess != number);

    return 0;
}
