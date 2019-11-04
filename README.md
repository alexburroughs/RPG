# RPG
A basic role-playing game to mess around with game design.


## Items
Each item will have a unique identifier, a name, a description and any additional data for that item as parameters.

### Item Types

#### Equip
Items that characters can wear, improving the user's stats and abilities.

#### Consumable
Items that can be consumed by characters or enemies.

#### Miscellaneous
Items that have no particular use, such as sell-able items and quest items.


## Characters

### Stats
Each character will have a set of stats. Each stat improves different factors and aspects of your character.

#### Strength
Increases physical damage by 1 damage.

#### Dexerity
Increases critical rate by 0.5%.

#### Vitality
Increases health by 1% and defense by 2%.

#### Magic
Increase mana by 2% and magic power by 1 damage.

### Level
A character will have a level and gain experience through battles. Upon reaching the required amount of experience, your character will level up.

#### Level Up
A level up will let your character receive stat points that can be manually allocated into your character stats as you see fit.

### Inventory
All items will be set into a single scrollable list.


## Maps
Maps will be static and uses square tiles to be drawn on screen.

### Tiles & Tilesets
Each tile will have a fixed dimension.

### Loading
The whole map in which the player is in will be loaded into memory.

### Storing maps as files
Each map will be saved in its own file as binary data.
