# 🍓 Fruit Chase Game

A simple terminal-based game where a spooky character chases randomly placed fruits on a 5x5 grid. Built in **C**, this was my first hands-on attempt at combining game logic, user input, and basic grid visuals in the terminal.

---

## 🎮 Gameplay

- The player starts at position `(0, 0)` on a 5x5 grid.
- A random fruit appears elsewhere on the grid.
- You get **2 chances** to reach the fruit each round.
- **No diagonal moves** is allowed.
- Catch the fruit to score and move to the next round with a new emoji.

---

## 💡 Features

- Uses `struct` and position logic
- Randomized fruit placement using `rand()` and `time()`
- Emoji-based terminal output (fun + visual!)
- Score tracking and win/loss conditions
  
## 🛠️ How to Run (Windows Terminal)

1. Save the code (e.g., `fruit_chase.c`) in a folder  
2. Copy the path to that folder  
3. Open **Command Prompt**  
4. Navigate to the folder
5. Enable emoji support: chcp 65001
6. Compile the code: gcc -o game fruit_chase.c
7. Run the game: game
   ✅ That’s it — enjoy playing! 🎉

