import classes.Card;
import classes.DeckOfCards;

import java.util.Objects;

public class Main {
    public static void main(String[] args) {
        DeckOfCards deck = new DeckOfCards();

        int counter = 0;
        boolean[] suits = new boolean[4];
        for(int i=0; i<4; i++){
            suits[i] = false;
        }

        while (!isAllTrue(suits)){
            deck.shuffle();
            Card curr = deck.dealCard();
            if(Objects.equals(curr.getSuit(), "Spades")){
                if(!suits[0]){
                    suits[0] = true;
                    System.out.println(curr.toString());
                }
            }else if(Objects.equals(curr.getSuit(), "Diamonds")){
                if(!suits[1]){
                    suits[1] = true;
                    System.out.println(curr.toString());
                }
            }else if(Objects.equals(curr.getSuit(), "Hearts")){
                if(!suits[2]){
                    suits[2] = true;
                    System.out.println(curr.toString());
                }
            }else{
                if(!suits[3]){
                    suits[3] = true;
                    System.out.println(curr.toString());
                }
            }
            counter++;

        }
        System.out.println(counter);
    }
    private static boolean isAllTrue(boolean[] arr){
        for (boolean b : arr) {
            if (!b) {
                return false;
            }
        }
        return true;
    }
}