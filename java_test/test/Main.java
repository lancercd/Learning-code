

public class Main{
    public static void main(String[] args) {
        Table table = new Table();
        table.put(10, "10");
        table.put(20, "20");
        table.put(30, "30");
        table.put(10, "20");
        table.put(20, "30");
        table.put(30, "40");

        table.show();
    }
}
