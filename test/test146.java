import java.util.Arrays;

public class test146{
    public static void main(String[] args) {
        int[] arr = new int[] {5,1,2,3,7,6,1,3,5,7};
        // dobbleSort();
        // doubbleSortImprove(arr);
        // selectSort(arr);
        insertionSort(arr);

        // print(arr);
        // print("=====");


        // int[] arr = createArray();
        // long startTime = System.currentTimeMillis();
        //
        // doubbleSortImprove(arr.clone());
        // long endTime = System.currentTimeMillis();
        // print("doubbleSortImprove:" + (endTime - startTime));
        //
        //
        // startTime = System.currentTimeMillis();
        // dobbleSort(arr.clone());
        // endTime = System.currentTimeMillis();
        // print("dobbleSort:" + (endTime - startTime));
    }


    //选择排序
    public static void selectSort(int[] arr){
        int len = arr.length;
        // print(arr);
        for(int i=0; i<len - 1; ++i)
        {
            int index = i;
            for(int j=i + 1; j<len; ++j)
            {
                if(arr[index] < arr[j]){
                    index = j;
                }
            }
            swap(arr, i, index);
        }
        print(arr);
    }

    //冒泡排序
    public static void dobbleSort(int[] arr)
    {
        int len = arr.length;
        // print(arr);

        for(int i=0; i<len - 1; ++i)
        {
            for(int j=1; j<len - i; ++j)
            {
                if(arr[j-1] > arr[j]) swap(arr, j-1, j);
            }
        }
        print(arr);
    }

    public static void doubbleSortImprove(int[] arr)
    {
        int len = arr.length;
        // print(arr);
        boolean flag = false;
        for(int i=0; i<len - 1; ++i)
        {
            for(int j=1; j < (len - i); ++j)
            {
                if(arr[j] < arr[j-1]){
                    swap(arr, j, j-1);
                    flag = true;
                }
            }
            if(false == flag){
                break;
            }
        }

        print(arr);
    }



    public static void insertionSort(int[] arr)
    {
        print(arr);
        int len = arr.length;
        for(int i=0; i<len; ++i)
        {
            for(int j=i; j>0 && arr[j-1] > arr[j]; --j)
            {
                swap(arr, j, j-1);
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



    public static int[] createArray(){
        int len = (int)1e5, low = 0, up = (int)1e6;
        int[] arr = new int[len];
        for(int i=0; i<len; ++i)
        {
            // arr[i] = (int)(Math.random() * up);
            arr[i] = i;
        }
        return arr;
    }




}
