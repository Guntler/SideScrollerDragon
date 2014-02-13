# SideScrollerDragon #  
## Task List Number 1 ##  
1.  [&#10003;] Redesign classes according to new Class Structure
2.  [ ] Simple drawing of objects
3.  [ ] Simple commands for handling input
4.  [ ] Simple physics
5.  [ ] Improve initial classes design  
## Class Structure Draft (Template Mixin-Based) ##

*  GameObject
    * Represents a drawable object
*  Living
    * Represents an object that has HP
*  Moving
    * Represents an object that can move
*  Player
    * Represents an object over which the player has control (can be branched into what type of control)
*  Enemy
    * Represents an object that can hurt the player (can be branched into what type of enemy)