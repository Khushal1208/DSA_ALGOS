import java.util.*;

public class InfixExpressionEvaluation {

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
		String str = " -12 + (23 * (4 + 5)) / 3 ";

		Stack<Integer> val = new Stack<>();
		Stack<Character> opr = new Stack<>();

		int n = str.length();

		for(int i = 0; i < n; i++) {
			char ch = str.charAt(i);

			// 1. Ignore spaces
			if(Character.isWhitespace(ch)) continue;

			// 2. Handle numbers (multi-digit)
			if(Character.isDigit(ch)) {
				int num = 0;

				while(i < n && Character.isDigit(str.charAt(i))) {
					num = num * 10 + (str.charAt(i) - '0');
					i++;
				}

				val.push(num);
				i--; // important
			}

			// 3. Handle '('
			else if(ch == '(') {
				opr.push(ch);
			}

			// 4. Handle ')'
			else if(ch == ')') {
				while(opr.peek() != '(') {
					work(val, opr);
				}
				opr.pop(); // remove '('
			}

			// 5. Handle operators
			else {
				// Handle negative number (VERY IMPORTANT)
				if(ch == '-' && (i == 0 || str.charAt(i-1) == '(' || str.charAt(i-1) == ' ')) {
					val.push(0);
				}

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
