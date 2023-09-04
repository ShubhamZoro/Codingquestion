class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> subgrids(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char cell = board[i][j];
                if (cell == '.')
                    continue;

               
                if (rows[i].count(cell))
                    return false;
                rows[i].insert(cell);

                
                if (cols[j].count(cell))
                    return false;
                cols[j].insert(cell);

          
                int subgrid_index = (i / 3) * 3 + j / 3;
                if (subgrids[subgrid_index].count(cell))
                    return false;
                subgrids[subgrid_index].insert(cell);
            }
        }

        return true;
    }
};
