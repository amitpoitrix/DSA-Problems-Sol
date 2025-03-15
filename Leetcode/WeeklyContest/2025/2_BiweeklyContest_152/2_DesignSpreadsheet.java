/**
 * Q2. Design Spreadsheet
 * Link: https://leetcode.com/contest/biweekly-contest-152/problems/design-spreadsheet/?slug=unique-3-digit-even-numbers&region=global_v2
 */

class Spreadsheet {
    private int[][] grid;

    public Spreadsheet(int rows) {
        grid = new int[rows][26];
    }
    
    public void setCell(String cell, int value) {
        int col = cell.charAt(0) - 'A';
        int row = Integer.parseInt(cell.substring(1)) - 1;

        grid[row][col] = value;
    }
    
    public void resetCell(String cell) {
        int col = cell.charAt(0) - 'A';
        int row = Integer.parseInt(cell.substring(1)) - 1;

        grid[row][col] = 0;
    }
    
    public int getValue(String formula) {
        String[] cell = formula.split("[=+]");
        // cell[] = [1,2] OR [1, B1] OR [A1, 2] OR [A1, B1]

        int result = 0;
        
        for(String str: cell) {
            if(str.length() == 0) {
                // As first array element is coming out to be empty string
                continue;
            }
            else if(str.matches("\\d+")) {
                // its a number
                result += Integer.parseInt(str);
            } else {
                int col = str.charAt(0) - 'A';
                int row = Integer.parseInt(str.substring(1)) - 1;

                result += grid[row][col];
            }
        }

        return result;
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.setCell(cell,value);
 * obj.resetCell(cell);
 * int param_3 = obj.getValue(formula);
 */