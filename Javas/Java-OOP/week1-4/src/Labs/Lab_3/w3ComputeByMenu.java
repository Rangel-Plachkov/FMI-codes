package Lab_3;

import java.util.Scanner;

public class w3ComputeByMenu {
    private double _x;
    private final Scanner _input = new Scanner(System.in);
    public w3ComputeByMenu(int x){
        _x = x;
    }
    public void displayMenu(){
        for(int i=0;i<60; i++){
            System.out.println();
        }
        System.out.println("""
                1. Въведи число x в плаваща запетая
                2. Пресметни и изведи exp(x)
                3. Пресметни и изведи sin(x0
                4. Пресметни и изведи floor(x)
                5. Край\n"""
        );
    }

    public void doSelection(int choice) {
        switch (choice) {
            case 1:
                System.out.print("Enter x: ");
                _x = Double.parseDouble((_input.nextLine()));
                break;
            case 2:
                System.out.printf("exp(x): %.2f", Math.exp(_x));
                break;
            case 3:
                System.out.printf("sin(x): %.2f", Math.sin(Math.toRadians(_x)));
                break;
            case 4:
                System.out.printf("floor(x): %.2f", Math.floor(_x));
                break;
            case 5:
                System.exit(0);
                break;
        }
    }
    public void getUserChoice(){
        int choice;
        while(true) {
            displayMenu();
            do {
                System.out.print("Enter choice: ");
                choice = Integer.parseInt(_input.nextLine());
            } while (choice < 1 || choice > 5);
            doSelection(choice);
            System.out.println("Press Enter to continue...");
            _input.nextLine();
        }

    }

}
