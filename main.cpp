#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main() {
    vector<vector<int>> grid(10, vector<int>(10));
    int start_r = -1, start_c = -1;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (!(cin >> grid[i][j])) return 0;
            if (grid[i][j] == 4) {
                start_r = i;
                start_c = j;
                grid[i][j] = 1; // treat start as empty
            }
        }
    }

    if (start_r == -1) return 0;

    int r = start_r;
    int c = start_c;
    int dir = 0; // UP
    int score = 0;

    bool visited[10][10][4] = {false};

    while (true) {
        if (visited[r][c][dir]) {
            cout << "Silly Pacman" << endl;
            return 0;
        }
        visited[r][c][dir] = true;

        int next_dir = -1;
        int next_r = -1, next_c = -1;

        int check_dirs[] = {(dir + 1) % 4, dir, (dir + 3) % 4, (dir + 2) % 4};

        for (int i = 0; i < 4; ++i) {
            int d = check_dirs[i];
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 0 && nr < 10 && nc >= 0 && nc < 10 && grid[nr][nc] != 0) {
                next_dir = d;
                next_r = nr;
                next_c = nc;
                break;
            }
        }

        if (next_dir == -1) {
            cout << "Silly Pacman" << endl;
            return 0;
        }

        r = next_r;
        c = next_c;
        dir = next_dir;

        if (grid[r][c] == 3) {
            score -= 500;
            cout << score << endl;
            return 0;
        } else if (grid[r][c] == 2) {
            score += 2;
            grid[r][c] = 1;
            for (int i = 0; i < 10; ++i)
                for (int j = 0; j < 10; ++j)
                    for (int k = 0; k < 4; ++k)
                        visited[i][j][k] = false;
        }
    }

    return 0;
}
