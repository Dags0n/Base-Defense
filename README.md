# Base-Defense
> Programming Language I final project

## Game overview
> The game consists of a 2d map, where enemies appear randomly shooting at the base, and you are the soldier responsible for stopping the enemies and protecting the base

## Development instructions
1. The hero has a life limit of 100 points;
2. The hero has a limited number of projectiles;
3. The hero can move in any direction controlled by clicking the mouse on a "target" location. When you right-click on a point on the map, the hero has that location marked as "destination" and must walk in that direction;
4. The hero can freely leave the base;
5. The hero can fire projectiles by pressing the "Q" key. The projectile must have a maximum range and must point in the direction of the mouse cursor when fired;
6. Enemies appear on the edges of the map randomly at a fixed time interval (which can be decreased to increase the difficulty of the game);
7. The enemy walks towards the center of the base, or towards the hero (programmer's choice);
8. The enemy always fires projectiles towards the hero;
9. The projectiles can collide with the hero, another enemy or the base;
10. The base must withstand a limited number of shots and can regenerate its structure over time;
11. When shot down, the enemy leaves a limited random amount of projectiles on the map that can be collected by the hero if he passes over the item, or the item disappears after a certain time if the hero doesn't collect it;
12. The game should end if the base can be protected for a certain period of time or if it is destroyed.

Base video: https://www.youtube.com/watch?v=5NH7W2XgdwE

## Tools & Technologies
- C++
- SFML
- Git/Github
- Kanban

## How to compile the program
### Dependencies
- g++
- Make
- SFML
### Run
Simply run the following command in the terminal:
```bash
  make
```

## Authors
- [Rômulo](https://github.com/romuloAMR)
- [Dagson](https://github.com/Dags0n)
- [Erik](https://github.com/eriksmedeiros)
