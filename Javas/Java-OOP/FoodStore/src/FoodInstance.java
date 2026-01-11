

import java.util.Arrays;

public class FoodInstance implements Comparable<FoodInstance> {
    private int foodKey;
    private String foodName;
    private double foodPrice;
    public final String INSTANCE_ID = generateInstanceId();
    private static int idCounter = 0;
    private String generateInstanceId() {
        idCounter++;
        return String.format("%04d", idCounter);
    }
    @Override
    public String toString() {
        return foodName + INSTANCE_ID + ", Price: " + String.format("%.2f", foodPrice);
    }
    @Override
    public int compareTo(FoodInstance other) {
        return Double.compare(this.foodPrice, other.foodPrice);
    }
    public FoodInstance(int foodKey, String foodName, double foodPrice) {
        this.foodKey = foodKey;
        this.foodName = foodName;
        this.foodPrice = foodPrice;
    }

    public static void main(String[] args) {

        FoodInstance[] foodInstances = {
                new FoodInstance(0, "Biscuits", 2.5),
                new FoodInstance(1, "Paste", 8.0),
                new FoodInstance(2, "Cheese", 5.5),
                new FoodInstance(3, "Fried meat", 12.75),
                new FoodInstance(4, "Beans", 3.0),
                new FoodInstance(5, "Watermelon", 6.25)
        };

        Arrays.sort(foodInstances);

        for (FoodInstance foodInstance : foodInstances) {
            System.out.println(foodInstance.toString());
        }
    }


    public int getFoodKey() { return foodKey; }
    public void setFoodKey(int foodKey) { this.foodKey = foodKey; }
    public String getFoodName() { return foodName; }
    public void setFoodName(String foodName) { this.foodName = foodName; }
    public double getFoodPrice() { return foodPrice; }
    public void setFoodPrice(double foodPrice) { this.foodPrice = foodPrice; }
}

