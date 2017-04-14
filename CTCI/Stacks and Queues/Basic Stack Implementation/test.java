public class test{
    public static void main(String[] args){
        Stack<String> st = new Stack<String>();
        for(int i = 0;i<25;i++) st.push(""+i);
        while (st.isEmpty()==false) {
            System.out.println("Poped"+st.pop());
        }
    }
}
