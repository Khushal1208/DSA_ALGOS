import java.util.*;

public class Main {

    public static int precedence(char op) {
        if(op == '+' || op == '-') return 1;
        return 2;
    }

    public static int solve(int v1, int v2, char op) {
        if(op == '+') return v1 + v2;
        if(op == '-') return v1 - v2;
        if(op == '*') return v1 * v2;
        return v1 / v2;
    }

    public static void work(Stack<Integer> val, Stack<Character> opr) {
        int v2 = val.pop();
        int v1 = val.pop();
        char op = opr.pop();
        val.push(solve(v1, v2, op));
    }

    public static void main(String[] args) {

        String str = "9-(5+3)*4/6";

        Stack<Integer> val = new Stack<>();
        Stack<Character> opr = new Stack<>();

        for(int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            if(Character.isDigit(ch)) {
                val.push(ch - '0');
            }
            else if(ch == '(') {
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
