package stock.java;

public class Stock {
    private static int nextId = 1;
    private final int ID;
    private ReorderSupplier reorderData;
    private double price;
    private final String description;

    public Stock(ReorderSupplier reorderData, double price) {
        this.ID = nextId++;
        this.reorderData = reorderData;
        this.price = price;
        this.description = "Stock-" + this.ID;
    }

    public int getID() {
        return ID;
    }

    public ReorderSupplier getReorderData() {
        return reorderData;
    }

    public void setReorderData(ReorderSupplier reorderData) {
        this.reorderData = reorderData;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getDescription() {
        return description;
    }

    @Override
    public String toString() {
        return "Stock ID:"+ ID +
                "\n\treorder quantity:" + reorderData.getReorderQty() +
                "\n\tsuppliers:" + reorderData.getSuppliers() +
                "\n Price=" + price;

    }
}
