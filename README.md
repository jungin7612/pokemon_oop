# Pokemon Battle Game

## Overview
This project is a simple command-line-based Pokemon battle simulation game implemented in C++. The program allows players to select Pokemon and use their unique skills in a turn-based battle.

The game includes core mechanics such as type effectiveness, health management, and skill usage limits. Players can also view detailed battle information, including skill effectiveness and remaining health, during gameplay.

---

## Features
- **Turn-based gameplay**: Players take turns selecting and using skills.
- **Skill management**: Each skill has a limited number of uses.
- **Type effectiveness**:
  - Super effective: Increases skill damage.
  - Not very effective: Decreases skill damage.
- **Battle display**: Detailed game state is displayed after each turn.
- **Win/Loss condition**: The game ends when a Pokemon's health drops to 0, and the result is displayed.

---

## How to Play
1. Compile the program:
   ```bash
   g++ -o main main.cpp
   ```

2. Run the program:
   ```bash
   ./main
   ```

3. Select two Pokemon for the battle by entering their respective numbers (0-4).

4. Players take turns choosing skills (0-3) to attack the opponent.

5. The game ends when one Pokemon's health reaches 0, and the winner is announced.

---

## Pokemon and Skills
Here are the predefined Pokemon and their skills:

### Pikachu
- **Tackle**: Normal, Damage: 4, Max Uses: 5
- **Grass Knot**: Grass, Damage: 8, Max Uses: 5
- **Thunderbolt**: Electric, Damage: 10, Max Uses: 5
- **Megabolt**: Electric, Damage: 15, Max Uses: 3

### Dratini
- **Wrap**: Normal, Damage: 4, Max Uses: 10
- **Aqua Tail**: Water, Damage: 3, Max Uses: 5
- **Water Pulse**: Water, Damage: 13, Max Uses: 2
- **Hyper Beam**: Normal, Damage: 20, Max Uses: 1

### Eevee
- **Tackle**: Normal, Damage: 4, Max Uses: 5
- **Sand Attack**: Ground, Damage: 8, Max Uses: 3
- **Bite**: Normal, Damage: 12, Max Uses: 3
- **Rain Dance**: Water, Damage: 15, Max Uses: 1

### Charmander
- **Tackle**: Normal, Damage: 4, Max Uses: 5
- **Flamethrower**: Fire, Damage: 11, Max Uses: 5
- **Dig**: Ground, Damage: 7, Max Uses: 5
- **Heat Wave**: Fire, Damage: 14, Max Uses: 5

### Palkia
- **Hydro Pump**: Water, Damage: 12, Max Uses: 10
- **Earth Power**: Ground, Damage: 15, Max Uses: 10
- **Surf**: Water, Damage: 13, Max Uses: 10
- **Spatial Rend**: Normal, Damage: 30, Max Uses: 10

---

## Game Mechanics

### Type Effectiveness
- **Super Effective**: Adds 5 bonus damage to the attack.
  - Example: Electric vs. Water.
- **Not Very Effective**: Reduces 3 damage from the attack.
  - Example: Electric vs. Ground.
- **Neutral Effectiveness**: No bonus or penalty.

### Victory Condition
- The game ends when one Pokemon's health reaches 0.
- The winner is announced with the message:
  ```
  ===============================================================
  Match Result: [Winning Pokemon] defeats [Losing Pokemon]!
  ```

---

## Example Gameplay
1. **Choose Pokemon**:
   - Player 1 chooses Pikachu (0).
   - Player 2 chooses Charmander (3).

2. **Battle Progression**:
   - Turn 1: Pikachu uses Thunderbolt (super effective against Charmander).
   - Turn 2: Charmander uses Flamethrower.
   - ...

3. **Game End**:
   - When Charmander's health reaches 0, Pikachu is declared the winner.

---

## Code Structure
### Classes
1. **Skill**:
   - Represents individual Pokemon skills.
   - Attributes: Name, Type, Damage, MaxTries, CurrentTries.

2. **Pokemon**:
   - Represents a Pokemon.
   - Attributes: Name, Type, Max HP, Current HP, Skills.
   - Methods:
     - Use skills.
     - Check type effectiveness.

### Helper Functions
- **drawRowLine**: Prints a line separator.
- **printTitle**: Displays the title.
- **printTwoColumnContent**: Shows the current state of both Pokemon in the battle.

---

## Known Limitations
- No support for additional Pokemon or skills without modifying the source code.
- Type effectiveness logic is hardcoded.
- Basic error handling for invalid input.

---

## Future Improvements
- Add more Pokemon and skills dynamically.
- Implement multiplayer or AI opponents.
- Improve input validation.
- Add graphical interface for better visualization.

---

## License
This project is open-source and available under the MIT License.

---

## Author
Developed as part of an Object-Oriented Programming exercise in C++. Feel free to contribute or modify!

