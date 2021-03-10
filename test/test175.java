import java.lang.Integer;
import java.util.Set;
import java.util.HashSet;




public class test175{
    public static void main(String[] args)
    {
        int[][] map = getMap();
        int[] ans = table(map);


        for(int i=0; i<ans.length; ++i)
        {
            System.out.print(ans[i] + " ");
        }
    }


    public static int[] table(int[][] map){
        int len = map.length;
        int[] ans = new int[len];
        Set<Integer> set = new HashSet<>();
        for(int i=0; i<len ;++i) ans[i] = Integer.MAX_VALUE;
        ans[0] = 0;
        set.add(0);
        int minIndex = 0;
        int nextIndex = 1;

        for(int i=0; i<len; ++i)
        {


            for(int j=0; j<len; ++j)
            {
                if(ans[j] < ans[minIndex] && !set.contains(j)){
                    minIndex = j;
                }
            }


            for(int j=0; j<len; ++j)
            {
                if(map[minIndex][j] != -1){
                    ans[j] = Math.min(ans[j], map[minIndex][j] + ans[minIndex]);
                }
                if(ans[j] >= ans[nextIndex]) nextIndex = j;
            }

            set.add(minIndex);
            minIndex = nextIndex;
        }
        return ans;
    }



    public static int[][] getMap(){
        int[][] map = {
                {-1, 1, 7, 6, -1},
                {-1, -1, 2, -1, 170},
                {-1, -1, -1, 2, 23},
                {-1, -1, -1, -1, 4},
                {-1, -1, -1, -1, -1},
        };
        return map;
    }
}
