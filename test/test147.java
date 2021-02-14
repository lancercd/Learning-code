
public class test147{
    public static void main(String[] args) {
        int[] arr = new int[]{1,3,4,9,12,45,53,95,100};
        print(half(arr, 9));
    }

    public static int half(int[] arr, int  target)
    {
        if(null == arr || 0 == arr.length) return -1;
        int L=0, R = arr.length, mid = 0;

        while(L <= R)
        {
            mid = (L + R) >> 1;
            if(arr[mid] == target) return mid;
            if(arr[mid] > target){
                R = mid - 1;
            }else{
                L = mid + 1;
            }
        }
        return -1;
    }


    public static void print(String str)
    {
        System.out.println(str);
    }
    public static void print(int str)
    {
        System.out.println(str);
    }
}
