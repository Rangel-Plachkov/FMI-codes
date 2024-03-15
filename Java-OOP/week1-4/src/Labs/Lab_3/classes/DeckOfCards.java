package Lab_3.classes;// Fig. 7.10: DeckOfCards.java
// DeckOfCards class represents a deck of playing cards.
import java.util.Random;
import java.util.concurrent.CancellationException;

public class DeckOfCards {
   private Card deck[];
   private int currentCard;
   private final int NUMBER_OF_CARDS = 52;
   private Random randomNumbers;
   private int[] numbers;
   private static final String faces[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six",
           "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
   private static final String suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
   public DeckOfCards() {

      deck = new Card[ NUMBER_OF_CARDS ];
      currentCard = 0;
      randomNumbers = new Random();

      for ( int count = 0; count < deck.length; count++ ) 
         deck[ count ] = 
            new Card( faces[ count % 13 ], suits[ count / 13 ] );
   }
   public void shuffle()
   {
      // after shuffling, dealing should start at deck[ 0 ] again
      currentCard = 0; // reinitialize currentCard

      // for each Card, pick another random Card and swap them
      for ( int first = 0; first < deck.length; first++ ) 
      {
         // select a random number between 0 and 51 
         int second =  randomNumbers.nextInt( NUMBER_OF_CARDS );
         
         // swap current Card with randomly selected Card
         Card temp = deck[ first ];        
         deck[ first ] = deck[ second ];   
         deck[ second ] = temp;            
      }
   }
   public Card dealCard() {
      // determine whether Cards remain to be dealt
      if ( currentCard < deck.length )
         return deck[ currentCard++ ]; // return current Card in array
      else        
         return null; // return null to indicate that all Cards were dealt
   }
   public void twoOfAKind(Card[] hand){
      numbers = totalHand(hand);
      int couples = couples(numbers);
      int triples = triples(numbers);
      if(couples == 1 && triples == 0){
         System.out.println("Two of a kind\n");
      }
   }
   public void twoPairs(Card[] hand){
      numbers = totalHand(hand);
      int couples = couples(numbers);
      if(couples == 2){
         System.out.println("Three of a kind\n");
      }
   }
   public void threeOfAKind(Card[] hand){
      numbers = totalHand(hand);
      int triples = triples(numbers);
      int couples = couples(numbers);
      if(triples == 1 && couples == 0){
         System.out.println("Three of a kind\n");
      }
   }
   public void fourOfAKind(Card[] hand){

   }
   public void flush(Card[] hand){

   }
   public void straigth(Card[] hand){

   }
   public void fullHouse(Card[] hand){

   }
   private int[] totalHand(Card[] hand){
      int[] numbers = new int [13];
      for(int i=0; i<numbers.length; i++){
         numbers[i] = 0;
      }
      for(int i=0; i<faces.length; i++){
         for(int j=0; j<hand.length; j++){
            if(faces[i].equals(hand[j].getFace())){
               numbers[i]++;
            }
         }
      }
      return numbers;
   }
   private int couples(int[] numbers){
      int couples = 0;
      for(int i=0; i<numbers.length;i++){
         if(numbers[i] == 2){
            couples++;
         }
      }
      return couples;
   }
   private int triples(int[] numbers){
      int couples = 0;
      for(int i=0; i<numbers.length;i++){
         if(numbers[i] == 3){
            return 1;
         }
      }
      return 0;
   }
}


