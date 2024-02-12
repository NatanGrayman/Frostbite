# Demo
[![Demo Video](https://img.youtube.com/vi/OvSKmZw93qI/0.jpg)](https://youtu.be/OvSKmZw93qI?si=aBMRRFjh8WilW2yo)


# Details
• Initially, a Splash Screen with game instructions has been implemented, where the user needs to press Enter to start the game.

•The game character, Bailey, is able to move horizontally whilst on ice block. 
•Bailey is able to move vertically, jumping from each ice block level towards the safe zone. 
•Bailey cannot exceed the boundaries of the game window.
 •If Bailey comes in contact with the 'water' he dies, and returns to initial position.

•Test cases were implemented to check the functionality of the game window, player positioning, player movement, ice block movement (including wrapping functionality) and game boundaries.

Building from the first release, the following has been implemented:

• Bailey changes direction when clicking left vs right key. 
• A Scoring system, which adds points to the total score when Bailey lands on additional ice-blocks.
 • A Temperature (time count down) , which 'freezes' Bailey if Bailey does not win in time.

• Multiple lives for Bailey. • When Bailey dies, and all lives have been utilised, the splashscreen appears.

• A row of enemies,moving across the screen, which can push Bailey into the water, therefore, killing him.
• An igloo which incremently appears when Bailey lands on additional iceblocks. • When the igloo is complete, bailey can enter the 'door' and the player wins. 
• Bailey can thereafter move to the next level, when he respawns in the initial position.

•Furthermore, testing functionality has been implemented for each additonal feauture.

Building from the second release:
 
•2 player mode functionality has been implemented where:
A new Splashscreen is shown which indicates the second player mode and respective keys needed to be used.
•A second Bailey, in red, spawns in the centre. 
•Each iceBlock is divided into a top and bottom half to represent which Bailey has landed.
•A new igloo for the second player is displayed incrementally on the left hand side of the screen. 
• Additionally, a particular splashscreen appears for the approrpriate winning player. 
• '-1' for lives indicates that player is dead. 
•Further testing of key functionality implementing. 
•Doxygen documentation has been implemented
