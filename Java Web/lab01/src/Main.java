import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Objects;
import java.util.Map;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        /*
        try{
            int n = task1(10, new ArrayList<>(List.of(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)));
            System.out.println(n);
        }catch (Exception e){
            System.out.println(e.getMessage());
        }*/
        /*
        ArrayList<Dog> dogList = new ArrayList<>();
        dogList.add(new Dog("Dog1", 10));
        dogList.add(new Dog("Dog3", 30));
        dogList.add(new Dog("Dog4", 40));
        dogList.add(new Dog("Dog2", 20));
        dogList.add(new Dog("Dog5", 50));
        dogList.sort(Dog::compareTo);
        dogList.sort(Comparator.comparing(Dog::getName));
        for (Dog dog : dogList) {
            System.out.println(dog.getName() + " " + dog.getWeight());
        }
        */
        task9();

    }
    private static int task1(int n, ArrayList<Integer> arr){
        int count = 0;
        for (Integer integer : arr) {
            if (integer % 2 == 1) {
                count++;
            }
            if(count == n){
                return integer;
            }
        }
        throw new IllegalArgumentException("No number found");
    }
    public static ArrayList<String> task3(ArrayList<String> arr, String str){
        String last = arr.get(arr.size()-1);
        for(int i = arr.size()-1; i > 0; i--){
            arr.set(i, arr.get(i-1));
        }
        arr.set(0, str);
        return arr;
    }
    public static int task4(int n,ArrayList<Integer> arr){
        return arr.get(n);
    }
    public static ArrayList<String> task5(ArrayList<String> arr){
        for(int i = 0; i < arr.size()-1; i++){
            if(i > 1){
                arr.set(i, arr.get(i+1));
            }
        }
        arr.remove(arr.size()-1);
        return arr;
    }
    public static int task6(String search , ArrayList<String> arr){
        for(int i = 0; i < arr.size(); i++){
            if(Objects.equals(arr.get(i), search)){
                return i;
            }
        }
        return -1;
    }
    public static void task9(){
        Map<String, Integer> map = new HashMap<>();
        map.put("a", 1);
        map.put("b", 2);
        map.put("c", 3);
        map.put("d", 4);
        map.put("e", 5);
        int sum = 0;
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            sum += entry.getValue();
        }
        System.out.println(sum);

    }
}