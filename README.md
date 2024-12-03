# Super Mario Game (SFML)

This project is a Super Mario-inspired game developed using SFML (Simple and Fast Multimedia Library) for C++. The game features custom graphics, audio effects for different collisions, and a main menu, while incorporating gameplay elements and mechanics similar to the classic Super Mario games.

## Features

### 1. **Custom Graphics and Audio**
   - The game includes custom graphics for all entities and backgrounds.
   - Audio effects are implemented for different types of collisions (e.g., player hitting an enemy, player jumping, etc.).
   - Background music plays both in the main menu and during gameplay, enhancing the gaming experience.

### 2. **Entity Hierarchy**
   - **Base Entity:** The `Entity` class represents common entities (player, enemies, objects) in the game.
   - **Player:** The `Player` class extends `Entity` and represents the main character of the game.
   - **Enemies:** The `Enemy` class is a base class for enemies, with specific derivatives like `Goomba` and `Koopa`.
     - **Goomba and Koopa Differences:** When the player jumps on both Goombas and Koopas, they are defeated. However, they take different amounts of damage based on their type, with each enemy having unique damage values to add variety to gameplay.

### 3. **Collision Detection**
   - **Screen Collision:** The player and enemies interact with the screen boundaries, ensuring that they stay within the visible area.
   - **Object Collision:** In addition to screen boundaries, collisions are detected between entities (e.g., player vs. enemies, player vs. objects).
   - **Enemy-Specific Collisions:** Different collision responses are implemented based on the type of enemy (e.g., Goomba, Koopa) to provide unique interactions when the player collides with them.

### 4. **Main Menu**
   - The main menu allows the player to choose between starting the game or quitting.
   - It features a background image, interactive buttons, and plays background music.

### 5. **Audio Integration**
   - The game includes background music that plays in both the main menu and during gameplay.
   - Different audio effects are played depending on the type of collision, such as when the player jumps on an enemy, collects a coin, or hits an object.



## Milestone #1

#### Cerințe
- [ ] definirea a minim **3-4 clase** folosind compunere cu clasele definite de voi
- [ ] constructori de inițializare cu parametri
- [ ] pentru o aceeași (singură) clasă: constructor de copiere, `operator=` de copiere, destructor
- [ ] `operator<<` pentru toate clasele pentru afișare (std::ostream)
- [ ] cât mai multe `const` (unde este cazul)
- [ ] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe
  - nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [ ] scenariu de utilizare a claselor definite:
  - preferabil sub formă de teste unitare, mai ales dacă vorbim de aplicații consolă 
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [ ] tag de `git`: de exemplu `v0.1`
- [ ] serviciu de integrare continuă (CI); exemplu: GitHub Actions

## Milestone #2

#### Cerințe
- [ ] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [ ] moșteniri:
  - minim o clasă de bază și **3 clase derivate** din aceeași ierarhie
  - ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
  - [ ] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
    - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
    - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
    - afișare virtuală, interfață non-virtuală
  - [ ] apelarea constructorului din clasa de bază din constructori din derivate
  - [ ] clasă cu atribut de tip pointer la o clasă de bază cu derivate; aici apelați funcțiile virtuale prin pointer de bază, eventual prin interfața non-virtuală din bază
    - [ ] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
    - [ ] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
    - [ ] smart pointers (recomandat, opțional)
- [ ] excepții
  - [ ] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim **3** clase pentru erori specifice
  - [ ] utilizare cu sens: de exemplu, `throw` în constructor (sau funcție care întoarce un obiect), `try`/`catch` în `main`
  - această ierarhie va fi complet independentă de ierarhia cu funcții virtuale
- [ ] funcții și atribute `static`
- [ ] STL
- [ ] cât mai multe `const`
- [ ] funcții *de nivel înalt*, de eliminat cât mai mulți getters/setters/funcții low-level
- [ ] tag de `git`: de exemplu `v0.2`

## Milestone #3

#### Cerințe
- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o clasă șablon cu sens; minim **2 instanțieri**
  - [ ] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri
- [ ] tag de `git`: de exemplu `v0.3` sau `v1.0`

## Resurse
- adăugați trimiteri către resursele externe care v-au ajutat sau pe care le-ați folosit
