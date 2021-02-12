import java.util.Arrays;

public class test146{
    public static void main(String[] args) {
        int[] arr = new int[] {5,1,2,3,7,6};
        dobbleSort();
    }




    public static void dobbleSort(int[] arr){
        int len = arr.length;
        print(arr);

        for(int i=0; i<len - 1; ++i)
        {
            for(int j=1; j<len - i; ++j)
            {
                if(arr[j-1] < arr[j]) swap(arr, j-1, j);
            }
        }

        print(arr);
    }





    public static void print(int[] arr){
        System.out.println(Arrays.toString(arr));
    }

    public static void print(String str)
    {
        System.out.println(str);
    }


    public static void swap(int[] arr, int i, int j){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }



}
