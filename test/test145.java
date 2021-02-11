


public class test145{
    public static void main(String[] args) {
        System.out.println("ok");
        random(1);
    }


    public static void random(int N){
        // System.out.println(Math.random() * N);
        float flag = 0.1f;
        int count = 0;
        int time = 100000;
        for(int i=0; i<time; ++i)
        {
            if(Math.random() * N < flag){
                ++count;
            }
        }
        System.out.println((double)count / time);
    }
}
