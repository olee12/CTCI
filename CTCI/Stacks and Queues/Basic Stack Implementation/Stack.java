import java.util.EmptyStackException;

public class Stack<T>{
    private int size;
    private StackNode<T> top;
    public static class StackNode<T> {
        private T data;
        StackNode<T> next;
        public StackNode(T data){
            this.data = data;
        }
    }

    public T pop() {
        if(top==null) throw new EmptyStackException();
        T data = top.data;
        top = top.next;
        return data;
    }


    public void push(T item) {
        StackNode<T> t = new StackNode<T>(item);
        t.next = top;
        top = t;
    }

    public T peek() {
        if(top==null) throw new EmptyStackException();
        return top.data;
    }

    public boolean isEmpty() {
        return top==null;
    }

}
