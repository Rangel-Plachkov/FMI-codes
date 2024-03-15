package stock.java;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Supplier;

public interface IRandomStockSupplier extends Wrap.ICanRandomize, Supplier<List<Stock>> {
    default List<Stock> loadStock(int howMany, int priceLower, int priceUpper) {
        List<Stock> stocks = new ArrayList<>();
        for (int i = 0; i < howMany; i++) {
            Stock stock = new Stock(generateReorderData(), randGenerator(priceLower, priceUpper).getAsInt());
            stocks.add(stock);
        }
        return stocks;
    }
    private ReorderSupplier generateReorderData() {

        int suppliersCount = randGenerator(4).getAsInt();
        List<String> suppliers = new ArrayList<>();
        for (int i = 1; i <= suppliersCount; i++) {
            suppliers.add("Supplier " + i);
        }
        int reorderQty = randGenerator(1, 6).getAsInt();
        return new ReorderSupplier(reorderQty, suppliers);
    }
}
