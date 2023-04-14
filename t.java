package irepeatmyuself;
import java.util.Scanner;

public class t {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int statues = scanner.nextInt();
        int printers = 1;
        int statuesprinted = 0;
        int days = 0;

        while(statuesprinted < statues){
            if((statues-statuesprinted) > printers){
                days += 1;
                printers += printers;
            }
            else {
                days += 1;
                statuesprinted += printers;
            }
        }
        
        System.out.println(days);
        scanner.close();
    }
}