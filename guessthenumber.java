package pickthenumber;

import java.util.Scanner;

public class guessthenumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String result = "";
        int low = 0;
        int high = 1001;
        while(!result.equals("correct")){
        
            System.out.println(low + ((high - low) / 2));
            result = scanner.next();
            if(result.equals("lower")){
                high = (low + (high - low) / 2);
            }else if(result.equals("higher")){
                low = (low + (high - low) / 2);
            }

        }

        scanner.close();
    }
}
