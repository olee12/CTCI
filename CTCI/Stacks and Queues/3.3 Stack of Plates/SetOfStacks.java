import java.util.ArrayList;
import java.util.EmptyStackException;

public class SetOfStacks{
    ArrayList<Stack> stacks = new ArrayList<Stack>();
    public int capacity;
    public SetOfStacks(int capacity) {
        this.capacity = capacity;
    }
    public void push(int v){
        Stack last = getLastStack();
        if(last != null && last.isFull()==false){
            last.push(v);
        }else{
            //System.out.println("setofstacks : "+stacks.size());
            last = new Stack(capacity);
            last.push(v);
            stacks.add(last);
        }
    }
    public int pop(){
        Stack last = getLastStack();
        if(last==null) throw new EmptyStackException();
        int v = last.pop();
        //System.out.println("Last Size"+last.getSize());
        if(last.getSize()==0) stacks.remove(stacks.size() - 1);
        return v;
    }
    public Stack getLastStack(){
        if(stacks.size()==0) return null;
        return stacks.get(stacks.size() - 1);
    }
    public boolean isEmpty(){
        Stack last = getLastStack();
        return last == null || last.isEmpty();
    }

    public int popAt(int index){
        return leftShift(index,true);
    }
    public int leftShift(int index,boolean removeTop){
        if(index < 0 || index >= stacks.size()) return -1;
        Stack stack = stacks.get(index);
        int removeItem;
        if(removeTop) removeItem = stack.pop();
        else removeItem = stack.removeBottom();

        if(stack.isEmpty()){
            stacks.remove(index);
        }else if(stacks.size() > index + 1){
            stack.push(leftShift(index+1,false));
        }
        return removeItem;
    }

}
