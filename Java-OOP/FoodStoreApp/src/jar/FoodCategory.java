package jar;

public enum FoodCategory {
    BREAKFAST("Breakfast"),
    LUNCH("Lunch"),
    //Typo??? DESERTS -> DESSERTS
    DESERTS("Desserts"),
    DINNER("Dinner");

    private String categoryName;
    private FoodCategory(String categoryName) {
        this.categoryName = categoryName;
    }
    public String getCategoryName() {
        return categoryName;
    }
    @Override
    public String toString() {
        return name() + ": " + getCategoryName();
    }

}
