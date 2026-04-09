import java.util.*;

public class PostfixEvaluation {

    public static void main(String[] args) {

        String postfix = "953+4*6/-";

        Stack<Integer> val = new Stack<>();

        for(int i = 0; i < postfix.length(); i++) {
            char ch = postfix.charAt(i);

            if(Character.isDigit(ch)) {
                val.push(ch-'0');
            }
            else {
                int v2 = val.pop();
                int v1 = val.pop();
                if(ch == '+') val.push(v1+v2);
                if(ch == '-') val.push(v1-v2);
                if(ch == '/') val.push(v1/v2);
                if(ch == '*') val.push(v1*v2);
            }
        }

        System.out.println(val.peek());
    }
}
