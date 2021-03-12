

public class test179{
    public static void main(String[] args)
    {
        char[][] map = init();
        print(map);
        Solution solu = new Solution();
        solu.solve(map);
        print(map);
    }



    public static char[][] init(){
        char[][] arr = {
            {'X','X','X','X'},
            {'X','O','O','X'},
            {'X','X','O','X'},
            {'X','O','X','X'}
        };
        return arr;
    }

    public static void print(char[][] map){
        for(int i=0 ;i<map.length; ++i)
        {
            for(int j=0; j<map[i].length; ++j)
            {
                System.out.print(map[i][j]);
            }
            System.out.println();
        }
    }
}



class Solution {
    public void solve(char[][] arr) {
        int n = arr.length;
        int m = arr[0].length;
        for(int i=0; i<m; ++i)
        {
            dfs(0, i, true, arr);
            dfs(n-1, i, true, arr);
        }
        for(int i=0; i<n; ++i)
        {
            dfs(i, 0, true, arr);
            dfs(i, m-1, true, arr);
        }


        for(int i=1; i<n; ++i)
        {
            for(int j=1; j<m; ++j)
            {
                dfs(i, j, false ,arr);
            }
        }

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(arr[i][j] == 'A') arr[i][j] = 'O';
            }
        }



    }

    public void dfs(int x, int y, boolean flag, char[][] arr){
        if(x < 0 || y < 0 || x >= arr.length || y >= arr[0].length) return;
        if(arr[x][y] != 'O') return;
        arr[x][y] = flag? 'A' : 'X';
        dfs(x - 1, y, flag, arr);
        dfs(x, y - 1, flag, arr);
        dfs(x + 1, y, flag, arr);
        dfs(x, y + 1, flag, arr);
    }

}
