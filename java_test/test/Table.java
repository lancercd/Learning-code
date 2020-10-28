

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
            while(endNode.next != null) endNode = endNode.next;
            endNode.next = node;
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

    private int hash(int v, int length)
    {
        return v&(length - 1);
    }


    public void show(){
        for(int i=0; i<table.length; ++i)
        {
            if(table[i] != null){
                System.out.println("key : " + table[i].key + " value : " + table[i].value);
            }
        }
    }
}
