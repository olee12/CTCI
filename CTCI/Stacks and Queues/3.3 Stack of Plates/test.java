public class test{
    public static void main(String[] args){
        int capacity = 5;
        SetOfStacks setOfStacks = new SetOfStacks(capacity);
        for(int i = 0;i<35;i++) setOfStacks.push(i);

        while(setOfStacks.isEmpty()==false){
            System.out.println("Poped : "+setOfStacks.pop());
        }
    }
}
