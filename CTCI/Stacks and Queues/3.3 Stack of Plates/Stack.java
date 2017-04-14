public class Stack{

    private int capacity;
    private int size;
    private Node top,bottom;


    public Stack(int capacity){
        this.capacity = capacity;
    }

    private void join(Node above,Node below){
        if(below != null) below.above = above;
        if(above != null) above.below = below;
    }

    public boolean push(int v){
        if(size >= capacity) return false;
        size++;
        Node n = new Node(v);
        if(bottom==null) bottom = n;
        join(n,top);
        top = n;
        return true;
    }

    public int pop(){
        // if size < 0
        Node t = top;
        top = top.below;
        size--;
        return t.value;
    }
    public boolean isFull(){
        return size==capacity;
    }

    public boolean isEmpty(){
        return size==0;
    }

    public int removeBottom(){
        Node b = bottom;
        bottom = bottom.above;
        if(bottom != null) bottom.below = null;
        return b.value;
    }
    public int getSize(){
        return size;
    }
}
