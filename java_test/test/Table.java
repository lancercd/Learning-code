

public class Table{
    Node[] table;
    int size;

    public Table(){
        table = new Node[16];
    }

    public void put(Object key, Object value)
    {
        Node node = new Node();
        node.key = key;
        node.value = value;
        node.next = null;
        int hash = hash(key.hashCode(), table.length);
        this.putIn(hash, node);
        System.out.println("hash:" + hash);
    }

    private void putIn(int pos, Node node){
        if(table[pos] == null){
            table[pos] = node;
        }else{
            Node endNode = table[pos];
            while(endNode.next != null && !endNode.next.key.equals(node.key)) endNode = endNode.next;
            if(endNode.next != null){
                System.out.println("1 : key : " + endNode.next.key + " value : " + endNode.next.value);
                endNode.next.value = node.value;
                System.out.println("2 : key : " + endNode.next.key + " value : " + endNode.next.value);
            }else{
                endNode.next = node;
            }

        }
    }

    public boolean has(Object key)
    {
        int pos = hash(key.hashCode(), table.length);
        if(table[pos] != null){
            Node node = table[pos];
            while(node != null)
            {
                if(node.key.equals(key)) return true;
            }
        }


        return false;
    }

    private int hash(int value, int length)
    {
        return value&(length - 1);
    }


    public void show(){
        for(int i=0; i<table.length; ++i)
        {
            Node tmp = table[i];
            while(tmp != null){
                System.out.println("key : " + tmp.key + " value : " + tmp.value);
                tmp = tmp.next;
            }
        }
    }
}
