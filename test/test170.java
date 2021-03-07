import java.util.*;


public class test170{
    public static void main(String[] args){
        Solution solu = new Solution();

        List<List<String>> ans = solu.solveNQueens(4);

        for(int i=0; i<ans.size(); ++i)
        {
            List<String> str = ans.get(i);
            for(int j=0; j<str.size(); ++j){
                System.out.println(str.get(j));
            }
            System.out.println("-----");
        }
    }

}

class Solution {
    List<List<String>> list;

    public List<List<String>> solveNQueens(int n) {
        list = new ArrayList<>();
        int[] record = new int[n];
        dfs(0, record);

        return list;
    }


    public void dfs(int index, int[] record){
        int n = record.length;
        if(n == index) {
            buildAns(record);
            return;
        }
        for(int i=0; i<n; ++i)
        {
            if(isValidate( index, i, record)){
                record[index] = i;
                dfs(index + 1, record);
            }
        }
    }

    public boolean isValidate(int x, int y, int[] record){
        for(int i=0; i < x; ++i)
        {
            if(record[i] == y || Math.abs(i - x) == Math.abs(record[i] - y)) return false;
        }
        return true;
    }

    public void buildAns(int[] record){
        int n = record.length;
        List<String> ans = new ArrayList<>();

        for(int i=0; i<n; ++i){
            StringBuilder sb = new StringBuilder();
            for(int j=0; j<n; ++j){
                sb.append((record[i] == j)? 'Q' : '.');
            }
            ans.add(sb.toString());
        }
        list.add(ans);
    }
}
