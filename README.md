# 👾 Earth Defender: Void Assault

> Earth Defender is a space-themed base defense game where the player controls a ship and must face waves of alien enemies. The objective is to kill all the enemies, defeating them and collecting items that improve the base.
The game consists of a 2d map, where enemies appear randomly shooting at the base, and you are the soldier responsible for stopping the enemies and protecting the base

## Implemented Features
- `Moviment`: The player controls the spaceship using the **right mouse button**;
- `Shot`: The player's ship can shoot using the **Q** key. The shooting frequency is controlled by a time interval;
- `Attributes`: The base and boss have the life attribute, and the hero has life and ammunition;
- `Menu`: A main menu where player can start a **new game**, learn **how to play**, choose **difficulty**, and **exit** the game;
- `Base`: A base that the player must defend from incoming waves of enemies. The player can freely leave the base;
- `Sniper Enemy`: An enemy that randomly appears from the ledges that follow the player shoot towards it;
- `Kamikaze Enemy`: A special type of enemy that self-destructs upon colliding with something, causing significant damage;
- `Alien Boss`: This is the final challenge you will have to face to win the game;
- `Item Drop System`: When defeating enemies, there is a chance they will drop items. These could be **base upgrades, health, or ammo**;
- `Choice of Difficulty`: 3 difficulty levels, allowing players to choose between **Normal, Hard or Impossible**;
- `Automatic Difficulty Increase`: As the game progresses, the difficulty automatically increases;
- `Status Bar`: A status bar displayed on the screen, providing real-time information about the current state of entities.
- `Pause`: The game includes a pause feature that can be accessed during gameplay;
- `Restart Game`: When the players win or lose, they have the option to **restart the game**.

## Item Drop System
The Snipers enemies have a 40% drop chance and Kamikazes enemies have a 80% drop chance. These are the items that can be dropped:

<img width="40px" align="center" src="https://github.com/romuloAMR/Base-Defense/blob/main/Assets/Image/ammo.png" />: Ammunition Drop has 60% drop chance.

<img width="40px" align="center" src="https://github.com/romuloAMR/Base-Defense/blob/main/Assets/Image/life.png" />: Health Drop has 30% drop chance.

<img width="40px" align="center" src="https://github.com/romuloAMR/Base-Defense/blob/main/Assets/Image/base_upgrade.png" />: Upgrade Base Regeneration has 10% drop chance.

## How to Play
To win, you will need to kill all enemies before they destroy the base. So you will need to defend your base at any cost. In total there are 51 aliens, including the boss alien, that will be your last challenge.

### Game commands
- `Right mouse button`: To move to the clicked location;
- `Q`: To shoot in the direction of the mouse;
- `Space`: To pause the game;
- `Esc`: To exit the game.

## Tools & Technologies
- C++
- SFML
- Git/Github
- Kanban

## Compile and run on a Unix Machine
### Dependencies
- g++
- Make
- SFML

**If you don't have the dependencies, install them with**:
```bash
  sudo apt update
  sudo apt install build-essential
  sudo apt-get install libsfml-dev
```

## Compile and Run
**Clone the project**:
```bash
  git clone https://github.com/romuloAMR/Base-Defense
```

**Navigate to project directory**:
```bash
  cd Base-Defense
```

**Having the requirements, compile and run the code with**:
```bash
  make
```

## Gallery of art and photographs:
### Arts:
<img width="50px" align="center" src="https://github.com/romuloAMR/Base-Defense/blob/main/Assets/Image/spaceship_dark.png" />:  Hero art. <br>
<img width="50px" align="center" src="https://github.com/romuloAMR/Base-Defense/blob/main/Assets/Image/enemy.png" />:  Enemy art. <br>
<img width="50px" align="center" src="https://github.com/romuloAMR/Base-Defense/blob/main/Assets/Image/kamikaze.png" />:  Enemy kamikaze art. <br>
<img width="50px" align="center" src="https://github.com/romuloAMR/Base-Defense/blob/main/Assets/Image/boss1.png" />:  Boss art. <br>
<img width="50px" align="center" src="https://github.com/romuloAMR/Base-Defense/blob/main/Assets/Image/base.png" />:  Base art. <br>
<img width="50px" align="center" src="https://github.com/romuloAMR/Base-Defense/blob/main/Assets/Image/ammo.png" />:  Ammunition drop art. <br>
<img width="50px" align="center" src="https://github.com/romuloAMR/Base-Defense/blob/main/Assets/Image/life.png" />:  Life drop art. <br>
<img width="50px" align="center" src="https://github.com/romuloAMR/Base-Defense/blob/main/Assets/Image/base_upgrade.png" />:  Base upgrade drop art. <br>

### Photographs:
<div style="display: flex; flex-direction: column; align-items: center;">
  <img width="400px" src="https://github.com/user-attachments/assets/3930e138-ae43-474c-a17b-0b8c49770434" />
  <img width="400px" src="https://github.com/user-attachments/assets/6f5d02da-fddb-4048-817f-7a22df4a2bba" />
  <img width="400px" src="https://github.com/user-attachments/assets/397d7927-402d-4a52-8435-5895283e09c6" />
  <img width="400px" src="https://github.com/user-attachments/assets/11c58216-2f92-4222-b6e3-d229334c1b72" />
  <img width="400px" src="https://github.com/user-attachments/assets/3db66ae2-e053-4ec7-9463-9e638ad97468" />
  <img width="400px" src="https://github.com/user-attachments/assets/46bbc504-8bb3-4231-86ad-89869130cac9" />
</div>

## Authors
- [Rômulo Alves](https://github.com/romuloAMR)
- [Dagson Gabriel](https://github.com/Dags0n)
- [Erik Medeiros](https://github.com/eriksmedeiros)
  
  Honorable Mention: Maria Clara (Art)
