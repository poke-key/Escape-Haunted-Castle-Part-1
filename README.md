```markdown
# Haunted Castle Escape

## Problem Description
A grid-based pathfinding challenge where you must help an adventurer escape a haunted castle, with additional complexity for treasure collection.

## Part 1: Basic Escape
Create a program to help an adventurer escape from a haunted castle using the shortest possible path.

### Requirements
- Grid-based movement (up, down, left, right only)
- Find minimum steps to reach escape point
- Handle walls/barriers 
- Adventurer starts at position (0,0)
- Castle grid maximum size is 10x10
- Return -1 if no valid escape path exists

### Classes to Implement
- Castle: Manages the grid layout and grid operations
- Adventurer: Tracks current position
- Wall: Represents impassable barriers
- EscapePoint: Marks the castle exit (exactly one per castle)

### Sample Input
```
2        # rows
2        # cols
1        # number of walls coordinates to follow
2        # wall coordinate pairs to follow
0 1      # wall at position (0,1)
2        # number of escape coordinates
1 1      # escape point at (1,1)
```

### Sample Output
```
2        # minimum steps to escape
```

## Part 2: Treasure Hunt
Extends the basic escape challenge by adding treasure collection objectives.

### Additional Requirements
- Find optimal path balancing quick escape and maximum treasure collection
- Each treasure can only be collected once
- Must still reach the escape point
- Same movement constraints as Part 1

### Additional Classes
- Treasure: Represents collectible items with positions

### Sample Input
```
3        # rows
3        # cols 
1        # number of walls
2        # wall coordinate pairs
1 1      # wall at (1,1)
2        # escape point coordinates length
1 1      # escape point at (1,1)
1        # number of treasures coordinates
2        # treasure coordinate pairs
0 1      # treasure at (0,1)
```

### Sample Output
```
4 1      # steps taken, treasures collected
```

## Implementation Notes
- Must implement efficient pathfinding algorithm
- Consider state management for collected treasures
- Validate all movements against walls and boundaries
- Optimize for both path length and treasure collection in Part 2
```
