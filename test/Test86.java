import java.util.Scanner;

public class Test86{
    static int N;
    static int[] arr = new int[10];
    static boolean[] used = new boolean[10];
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        N = input.nextInt;
        dfs(0, N);
    }
    public static void dfs(int count){
        if(count == N){

            return;
        }

    }
}
