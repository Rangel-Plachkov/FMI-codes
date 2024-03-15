package jar;

public class Food {
    private String name;
    private FoodCategory foodCategory;
    private FoodType foodType;
    private boolean isSpicy;
    public static final Food[] FOOD_PRODUCTS = {
            new Food("Biscuits", FoodCategory.BREAKFAST, FoodType.BAKERY, false),
            new Food("Paste", FoodCategory.DESERTS, FoodType.VEGAN, false),
            new Food("Cheese", FoodCategory.BREAKFAST, FoodType.DAIRY, false),
            new Food("Fried meat", FoodCategory.LUNCH, FoodType.MEAT, true),
            new Food("Beans", FoodCategory.DINNER, FoodType.SOUP, true),
            new Food("Watermelon", FoodCategory.LUNCH, FoodType.VEGETABLE_FRUIT, true)
    };
    @Override
    public String toString() {
        String spicyStatus = isSpicy ? "Yes" : "No";
        return String.format("Food{ name: %s, category: %s, type: %s, spicy: %s }",
                name, foodCategory.getCategoryName(), foodType.getFoodType(), spicyStatus);
    }


    public Food(String name, FoodCategory foodCategory, FoodType foodType, boolean isSpicy) {
        this.name = name;
        this.foodCategory = foodCategory;
        this.foodType = foodType;
        this.isSpicy = isSpicy;
    }
    public Food(Food other) {
        this.name = other.name;
        this.foodCategory = other.foodCategory;
        this.foodType = other.foodType;
        this.isSpicy = other.isSpicy;
    }

    public String getName() { return name; }
    public void setName(String name) { this.name = name; }
    public FoodCategory getFoodCategory() { return foodCategory; }
    public void setFoodCategory(FoodCategory foodCategory) { this.foodCategory = foodCategory; }
    public FoodType getFoodType() { return foodType; }
    public void setFoodType(FoodType foodType) { this.foodType = foodType; }
    public boolean isSpicy() { return isSpicy; }
    public void setSpicy(boolean spicy) { isSpicy = spicy; }
}
