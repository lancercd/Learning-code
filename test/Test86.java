import java.util.Scanner;
// java dfs
public class Test86{
    static int N;
    static int[] arr = new int[10];
    static boolean[] used = new boolean[10];

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        N = input.nextInt();
        dfs(0);

    }
    public static void dfs(int count){
        if(count == N){
            for(int i=0; i<N; ++i){
                System.out.print(arr[i] + " ");
            }
            System.out.print("\n");
            return;
        }
        for(int i=0; i<N; ++i){
            if(used[i]) continue;
            used[i] = true;
            arr[count] = i + 1;
            dfs(count + 1);
            used[i] = false;
        }
    }
}
