public class test{
    public static void main(String[] args){
        MyQueue<String> queue = new MyQueue<String>();
        for(int i = 1;i<=15;i++) queue.push("olee : "+i);
        while(queue.isEmpty()==false){
            System.out.println(queue.pop());
        }
    }
}
