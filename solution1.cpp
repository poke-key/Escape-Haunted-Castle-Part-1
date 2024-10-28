#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'escape_castle' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER rows
 *  2. INTEGER columns
 *  3. 2D_INTEGER_ARRAY walls
 *  4. INTEGER_ARRAY escape_point
 */
 
 //class for the points, used in escape castle
class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

vector<int> escape_castle(int rows, int cols, vector<vector<int>>& walls, vector<int>& escape_point) {
    //create a grid for representing
    vector<vector<bool>> grid(rows, vector<bool>(cols, true));
    
    //mark the walls as obstacles
    for(const auto& wall : walls) {
        if(wall.size() >= 2) {
            int x = wall[0];
            int y = wall[1];
            if(x >= 0 && x < rows && y >= 0 && y < cols) 
                grid[x][y] = false;
        }
    }
    
    //check if start/end points are blocked
    if (!grid[0][0] || !grid[escape_point[0]][escape_point[1]]) {
        return vector<int>{-1};
    }
    
    //breathd first search queue
    queue<pair<int, int>> q;
    //create a distance matrix
    vector<vector<int>> dist(rows, vector<int>(cols, -1));
    
    //have an array for 4 possible direction movements
    const int dx[] = {-1, 1, 0, 0};  //up, down, left, right
    const int dy[] = {0, 0, -1, 1};
    
    //start the bfs from 0,0
    q.push({0, 0});
    dist[0][0] = 0;
    
    //breathd first search logic
    while (!q.empty()) {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        
        //check to see if reached end point
        if (currX == escape_point[0] && currY == escape_point[1]) {
            return vector<int>{dist[currX][currY]};
        }
        
        //try all four directions
        for (int i = 0; i < 4; i++) {
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            
            //check if new position is valid
            if (newX >= 0 && newX < rows && 
                newY >= 0 && newY < cols && 
                grid[newX][newY] && 
                dist[newX][newY] == -1) {
                
                dist[newX][newY] = dist[currX][currY] + 1;
                q.push({newX, newY});
            }
        }
    }
    
    //didn't reach the endpoint
    return vector<int>{-1};
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rows_temp;
    getline(cin, rows_temp);

    int rows = stoi(ltrim(rtrim(rows_temp)));

    string columns_temp;
    getline(cin, columns_temp);

    int columns = stoi(ltrim(rtrim(columns_temp)));

    string walls_rows_temp;
    getline(cin, walls_rows_temp);

    int walls_rows = stoi(ltrim(rtrim(walls_rows_temp)));

    string walls_columns_temp;
    getline(cin, walls_columns_temp);

    int walls_columns = stoi(ltrim(rtrim(walls_columns_temp)));

    vector<vector<int>> walls(walls_rows);

    for (int i = 0; i < walls_rows; i++) {
        walls[i].resize(walls_columns);

        string walls_row_temp_temp;
        getline(cin, walls_row_temp_temp);

        vector<string> walls_row_temp = split(rtrim(walls_row_temp_temp));

        for (int j = 0; j < walls_columns; j++) {
            int walls_row_item = stoi(walls_row_temp[j]);

            walls[i][j] = walls_row_item;
        }
    }

    string escape_point_count_temp;
    getline(cin, escape_point_count_temp);

    int escape_point_count = stoi(ltrim(rtrim(escape_point_count_temp)));

    vector<int> escape_point(escape_point_count);

    for (int i = 0; i < escape_point_count; i++) {
        string escape_point_item_temp;
        getline(cin, escape_point_item_temp);

        int escape_point_item = stoi(ltrim(rtrim(escape_point_item_temp)));

        escape_point[i] = escape_point_item;
    }

    vector<int> result = escape_castle(rows, columns, walls, escape_point);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
