#include <vector>

class ListNode;

using namespace std;

class Solution {
public:
  enum { right = 0, down, left, up };

  vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
    vector<vector<int>> ret(m, vector<int>(n, -1));
    vector<vector<bool>> d(m, vector<b)
    vector<vector<bool>> ok(m, vector<int>(n, false));
    int x = 0, y = -1;
    int state = right;
    while (head) {
      ret[x][y] = head->val;
      ok[x][y] = true;
      head = head->next;

      switch (state) {
      case right:
        if (y == n - 1 || (y < n - 1 && y >= 0 && ok[x][y + 1])) {
          state = down;
          break;
        }
        y++;
        break;
      case down:
        if (x == m - 1 || (x < m - 1 && x >= 0 && ok[x + 1][y])) {
          state = left;
          break;
        }
        x++;
        break;
      case left:
        if (y == 0 || (y > 0 && y <= n - 1 && ok[x][y - 1])) {
          state = up;
          break;
        }
        y--;
        break;
      case up:
        if (x == 0 || (x > 0 && x <= m - 1 && ok[x - 1][y])) {
          state = right;
          break;
        }
        x--;
        break;
      }
    }

    return ret;
  }
};