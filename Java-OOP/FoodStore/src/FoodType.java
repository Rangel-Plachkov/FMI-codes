
public enum FoodType {
    BAKERY("Bakery"),
    DAIRY("Dairy"),
    MEAT("Meat"),
    VEGAN("Vegan"),
    VEGETABLE_FRUIT("Vegetable/Fruit"),
    BEVERAGES("Beverages"),
    SOUP("Soup");
    private String foodType;
    private FoodType(String foodType) {
        this.foodType = foodType;
    }
    public String getFoodType() {
        return foodType;
    }
}
