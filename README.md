# Haunted Castle Escape

## Problem Description
This project involves creating a grid-based pathfinding program where an adventurer must escape a haunted castle. In the extended challenge, the adventurer can also collect treasures along the way, balancing the shortest escape path with maximum treasure collection.

## Part 1: Basic Escape
The objective is to help the adventurer find the shortest possible path out of the castle.

### Requirements
- **Grid-Based Movement**: Movement is limited to up, down, left, or right.
- **Pathfinding**: Find the minimum steps needed to reach the escape point.
- **Obstacles**: Account for walls or barriers in the path.
- **Starting Position**: The adventurer begins at position `(0,0)`.
- **Grid Size**: Maximum grid size is 10x10.
- **Edge Case**: Return `-1` if no valid escape path exists.

### Classes to Implement
- **Castle**: Manages the grid layout and grid operations.
- **Adventurer**: Tracks the adventurer's current position.
- **Wall**: Represents impassable barriers.
- **EscapePoint**: Marks the escape point of the castle (exactly one per castle).

### Sample Input
```
2          # Number of rows
2          # Number of columns
1          # Number of walls
2          # Number of coordinates for walls
0 1        # Wall at position (0,1)
2          # Number of escape points
1 1        # Escape point at (1,1)
```

### Sample Output
```
2          # Minimum steps required to escape
```

## Part 2: Treasure Hunt
This part extends the basic escape challenge by adding treasure collection objectives.

### Additional Requirements
- **Objective**: Find an optimal path balancing quick escape with maximum treasure collection.
- **Unique Treasure Collection**: Each treasure can only be collected once.
- **Movement Constraints**: Same as in Part 1.
- **Objective**: The adventurer must still reach the escape point.

### Additional Classes
- **Treasure**: Represents collectible items located at specified grid positions.

### Sample Input
```
3          # Number of rows
3          # Number of columns 
1          # Number of walls
2          # Number of coordinates for walls
1 1        # Wall at (1,1)
2          # Number of escape points
1 1        # Escape point at (1,1)
1          # Number of treasures
2          # Number of coordinates for treasures
0 1        # Treasure at (0,1)
```

### Sample Output
```
4 1        # Steps taken to escape, Treasures collected
```

## Implementation Notes
- **Pathfinding Algorithm**: Implement an efficient pathfinding algorithm such as BFS or A*.
- **State Management**: Keep track of treasures collected and visited positions to avoid redundant checks.
- **Movement Validation**: Ensure all moves are within boundaries and avoid walls.
- **Optimization**: Balance path length with treasure collection in Part 2.

## Getting Started
To run the program, clone the repository and execute the main script with sample inputs to see results for both parts of the challenge.

## License
This project is licensed under the MIT License.
```
