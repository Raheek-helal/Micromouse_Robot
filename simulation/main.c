/*
 * main.c
 *
 *  Created on: Sep 19, 2024
 *      Author: Raheek_Helal
 */

//#include <stdio.h>
#include <stdlib.h>
#include "API.h"

#define EMPTY 'E'
#define FILLED 'F'
#define WALL 'W'


 #include <stdio.h>

// Directions for movement: right, down, left, up (clockwise)
const int dx[] = {1, 0, -1, 0};  // x movement for right, down, left, up
const int dy[] = {0, 1, 0, -1};  // y movement for right, down, left, up

// The current facing direction of the robot (0 = right, 1 = down, etc.)
int currentDirection = 0;  // Start facing right

// Turning right and left
void turnRight() {
    API_turnRight();
    currentDirection = (currentDirection + 1) % 4;  // Update direction
}

void turnLeft() {
    API_turnLeft();
    currentDirection = (currentDirection + 3) % 4;  // Update direction
}

// Turn to a specific direction
void turnTo(int targetDirection) {
    while (currentDirection != targetDirection) {
        turnRight();
    }
}

// Move in the current direction
int moveForward() {
    return API_moveForward();  // Return if movement was successful
}

// Check for walls around the robot in any direction
int wallInDirection(int dir) {
    int deltaDir = (dir - currentDirection + 4) % 4;
    if (deltaDir == 0) return API_wallFront();
    if (deltaDir == 1) return API_wallRight();
    if (deltaDir == 3) return API_wallLeft();
    return 0;  // No wall detection for backward direction
}

// Flood fill function with improved backtracking and movement logic
void floodFill(int x, int y, int visited[16][16]) {
    if (visited[x][y]) {
        return;  // If already visited, stop
    }
    visited[x][y] = 1;  // Mark current cell as visited
    API_setColor(x, y, FILLED); // Visual representation

    // Try all four possible directions
    for (int dir = 0; dir < 4; dir++) {
        int newX = x + dx[dir];
        int newY = y + dy[dir];

        // If there's no wall and not visited, move to the new direction
        if (!wallInDirection(dir) && !visited[newX][newY]) {
            turnTo(dir);  // Turn to face the new direction

            // Move forward and explore the new cell
            if (moveForward()) {
                floodFill(newX, newY, visited);  // Recursive call to explore the next cell

                // Backtrack: Move back to the previous position
                turnTo((dir + 2) % 4);  // Turn around to face the opposite direction
                moveForward();  // Move back to the previous position
                turnTo(dir);  // Reset to the original direction before backtracking
            }
        }
    }
}

void startFloodFill() {
    int startX = 0, startY = 0;
    int visited[16][16] = {0};  // Array to track visited cells, assuming 16x16 maze
    floodFill(startX, startY, visited);
}

int main() {
    startFloodFill();
    return 0;
}
