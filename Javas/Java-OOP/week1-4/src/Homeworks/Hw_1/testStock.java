package Hw_1;

public class testStock {
    public static void main(String[] args){

        Stock test1 = new Stock("^","ime");
        System.out.println("Sym: '" + test1.getSymbol() + "' Name: " +  test1.getName() );
        test1.setCurrPrice(10);
        test1.setPreviousClosingPrice(9);
        System.out.println("Current: " + test1.getCurrPrice() + " Previous: " +  test1.getPreviousClosingPrice() );
        System.out.printf("Change(Percent): %.2f\n\n" , test1.changePercent());

        test1.setPreviousClosingPrice(11);
        System.out.println("Current: " + test1.getCurrPrice() + " Previous: " +  test1.getPreviousClosingPrice() );
        System.out.println("Current: " + test1.getCurrPrice() + " Previous: " +  test1.getPreviousClosingPrice() );
        System.out.printf("Change(Percent): %.2f\n" , test1.changePercent());

    }
}
