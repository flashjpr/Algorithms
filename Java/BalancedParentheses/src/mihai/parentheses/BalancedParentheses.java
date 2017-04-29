package mihai.parentheses;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Stack;

public class BalancedParentheses {

    //  Given an input containing only "(" and ")", print out TRUE if the parentheses are properly balanced and nested
    // or NO otherwise. For full credit, identify the position of the first offending parenthesis if the string is not
    // properly nested and balanced.

    public static void main(String[] args) throws FileNotFoundException {

        File file = new File("input.txt");
        Scanner scanner = new Scanner(file);
        String input = scanner.next();

        System.out.println("Are the parentheses in the input: " + input + " balanced ?");
        System.out.println("Going through array method: " + evaluateParenthesis(input));
        System.out.println("Using a stack method      : " + balancedParentheses(input));
    }

    // First thing I could think of
    public static String evaluateParenthesis(String input) {
        int noOfOpening = 1;
        int noOfClosing = 0;

        if (input.charAt(0) == ')') return "NO";
        else {
            for (int i = 1; i < input.length(); i++) {
                if (input.charAt(i) == ')') noOfClosing++; else noOfOpening++;
                if (noOfClosing > noOfOpening) return "NO; Failure at position " + i;
            }
//            System.out.println("Closing:" + noOfClosing);
//            System.out.println("Opening:" + noOfOpening);
        }
        return (noOfClosing == noOfOpening) ? "YES":"NO";
    }

    //  A method that uses a stack
    public static boolean balancedParentheses(String s) {
        Stack<Character> stack  = new Stack<Character>();
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c == '(') {
                stack.push(c);
            }else if(c == ')') {
                if(stack.isEmpty()) return false;
                if(stack.pop() != '(') return false;
            }
        }
        return stack.isEmpty();
    }
}
