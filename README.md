# cs224-fall2019-project-eco-planet
cs224-fall2019-project-eco-planet created by GitHub Classroom

**Title:** Eco Planet

**Team Members:** Omema Ahmed, Aiman Junaid, Anand Kumar, Fatima Zehra

**Resources:** Let&#39;s Make Games – YouTube

**YouTube Channel:** [https://www.youtube.com/channel/UC-CQ2UAKSGgZ5nK6S-mA-rg](https://www.youtube.com/channel/UC-CQ2UAKSGgZ5nK6S-mA-rg?view_as=subscriber)

**Game Description and Controls:**
- --Eco Planet is a game that aims to teach the player the effects of different things we use in our everyday lives on Earth. At the start of the game, the Earth will be polluted (with smoke and dead trees) and its life will keep decreasing as th game proceeds. When the enemy arrives, as the player kills the enemy by throwing the objects collects, the Earth's life will be restored and the background would become clean with green trees etc. On collection of non eco friendly objects, the Earth's life will decrease. 
- --Controls: 
Right Arrow: moves forward
Left Arrow: moves background
Arrow Up: jumps
Space bar: throws object

**Requirements Met:**
- --Polymorphism: Implemented in Screens, GameObjects and Enemies and classes
- --Design Patterns: Singleton (for Player class), Abstract Factory (for Screen class) and Template(for GameObjects class)
- --Menu with buttons: Implemented in Main screen, Game over screen, Instructions screen, Introduction Screen and Pause Screen classes
- --File I/O: Used to Save and Load game (savegame.txt attached)
- --Operator Overloading: SetX() function of GameObject class
- --Memory Management: All memory has been deallocated in class destructors

**Contributions:**

- --Omema Ahmed: Made Screen abstract and inherited classes, GameObject abstract class, Earth class, Life class, Game class, Texture class, Buttons class and implemented Abstract Factory and Template design patterns
- --Anand Kumar: Made Enemies abstract class and inherited classes and rendered random game objects on screen.
- --Aiman Junaid: Made player class using singleton design pattern and implemented all its functions
- --Fatima Zehra: Designed all screens and game objecs and implemented Tree, Smoke and RandomObject class

**Number of hours:** 200 hours

**Additional Notes:**
- --Please unzip Sprites and Screens zip folder and add to game folder before running
- --In case the game does not run, please run the exe file again (./a.exe).
- --On the start screen, the 'QUIT' button loads the game insetad of the 'LOAD' button
