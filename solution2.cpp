//PROBLEM PART 2

#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'escape_castle' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER rows
#  2. INTEGER cols
#  3. 2D_INTEGER_ARRAY walls
#  4. INTEGER_ARRAY escape_point
#  5. 2D_INTEGER_ARRAY treasures
#

#!/bin/python3
from collections import deque

def escape_castle(rows, cols, walls, escape_point, treasures):
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    wall_set = {tuple(wall) for wall in walls}
    treasure_set = {tuple(treasure) for treasure in treasures}
    escape_point = tuple(escape_point)
    
    #queue gets the row columns steps and the collected
    queue = deque([(0, 0, 0, 0)])
    #track the visited position with their treasure counts
    visited = {(0, 0): 0}  #(r,c): max_treasures_collected
    
    min_steps = float('inf')
    max_treasures = 0
    
    while queue:
        r, c, steps, collected = queue.popleft()
        
        #check for if we reached escape point
        if (r, c) == escape_point:
            if steps <= min_steps:  #counts for equal steps
                if steps < min_steps or collected > max_treasures:
                    min_steps = steps
                    max_treasures = collected
            continue
        
        #don't explore further if too many steps
        if min_steps != float('inf') and steps >= min_steps:
            continue
            
        #expore all the directions
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            
            if 0 <= nr < rows and 0 <= nc < cols and (nr, nc) not in wall_set:
                new_collected = collected
                if (nr, nc) in treasure_set:
                    new_collected += 1
                    
                #allow revisiting if we can collect more treasures
                if (nr, nc) not in visited or visited[(nr, nc)] < new_collected:
                    visited[(nr, nc)] = new_collected
                    queue.append((nr, nc, steps + 1, new_collected))
    
    if min_steps == float('inf'):
        return "-1 0"
    return f"{min_steps} {max_treasures}"
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    rows = int(input().strip())

    cols = int(input().strip())

    walls_rows = int(input().strip())
    walls_columns = int(input().strip())

    walls = []

    for _ in range(walls_rows):
        walls.append(list(map(int, input().rstrip().split())))

    escape_point_count = int(input().strip())

    escape_point = []

    for _ in range(escape_point_count):
        escape_point_item = int(input().strip())
        escape_point.append(escape_point_item)

    treasures_rows = int(input().strip())
    treasures_columns = int(input().strip())

    treasures = []

    for _ in range(treasures_rows):
        treasures.append(list(map(int, input().rstrip().split())))

    result = escape_castle(rows, cols, walls, escape_point, treasures)

    fptr.write(result)
    fptr.write('\n')

    fptr.close()