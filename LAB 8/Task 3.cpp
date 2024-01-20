#include <iostream>
#include <vector>

using namespace std;

// Define the dimensions of the grid
const int rows= 5;
const int cols= 5;

// Function to perform flood fill
void floodFill(vector<vector<int>>& grid, int x, int y, char targetColor, char replacementColor) {
    // Base cases for recursion
    if (x < 0 || x >= rows || y < 0 || y >= cols)
        return;
    if (grid[x][y] != targetColor)
        return;

    // Replace the current color with the replacement color
    grid[x][y] = replacementColor;

    // Recursive calls for neighboring cells
    floodFill(grid, x + 1, y, targetColor, replacementColor);
    floodFill(grid, x - 1, y, targetColor, replacementColor);
    floodFill(grid, x, y + 1, targetColor, replacementColor);
    floodFill(grid, x, y - 1, targetColor, replacementColor);
}

int main() {
    
    int m,n;
    char a,b;
    vector<vector<char> > grid;

    while (m!=0 && n!=0)
    {
        cin >> m >> n;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){

            }
        }
    }

    int count = 0;
    
    
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };

    int x = 2; // Starting row
    int y = 2; // Starting column
    int targetColor = 0; // Color to be replaced
    int replacementColor = 2; // Color to fill with

    // Call the flood fill function
    floodFill(grid, x, y, targetColor, replacementColor);

    // Print the modified grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
        count++;
    }

    cout<< count << endl;

    return 0;
}
