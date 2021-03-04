
public class test167{
    public static void main(String[] args)
    {
        // int[] arr = {1,2,3};
        int[] arr = {1,1,1,2,2,2,2,3,3,3,3,6,6,6,8,8,8,9,9,9,9,10};
        int index = binary(arr, 2);

        System.out.println(index);


    }



    public static int binary(int[] arr, int target){
        int left = 0, right = arr.length - 1, mid = 0;
        int index = -1;
        while(left <= right){
            mid = (left + right) >> 1;
            if(arr[mid] >= target){
                right = mid - 1;
                index = mid;
            }else{
                left = mid + 1;
            }
        }
        return index;

    }


}
