import java.util.*;

public class InfixToPrefix {

    public static int precedence(char op) {
        if(op == '+' || op == '-') return 1;
        return 2;
    }

    public static void work(Stack<String> val, Stack<Character> opr) {
        String v2 = val.pop();
        String v1 = val.pop();
        char op = opr.pop();
        String t = op + v1 + v2;
        val.push(t);
    }

    public static void main(String[] args) {

        String infix = "9-(5+3)*4/6";

        Stack<String> val = new Stack<>();
        Stack<Character> opr = new Stack<>();

        for(int i = 0; i < infix.length(); i++) {
            char ch = infix.charAt(i);

            if(Character.isDigit(ch)) {
                String s = ""+ ch; // typecast char to string
                val.push(s);
            }
            else if(opr.isEmpty() || ch == '(' || opr.peek() == '(') {
                opr.push(ch);
            }
            else if(ch == ')') {
                while(opr.peek() != '(') {
                    work(val, opr);
                }
                opr.pop(); // remove '('
            }
            else {
                // operator (+, -, *, /)
                while(!opr.isEmpty() && opr.peek() != '(' &&
                      precedence(opr.peek()) >= precedence(ch)) {

                    work(val, opr);
                }
                opr.push(ch);
            }
        }

        // final processing
        while(!opr.isEmpty()) {
            work(val, opr);
        }

        System.out.println(val.peek());
    }
}
