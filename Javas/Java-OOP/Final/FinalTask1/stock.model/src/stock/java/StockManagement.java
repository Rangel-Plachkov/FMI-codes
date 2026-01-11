package stock.java;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.Comparator;
import java.util.Map;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class StockManagement {
    private final IRandomStockSupplier supplier;
    private final List<Stock> stocks;

    public StockManagement() {
        this.supplier = new IRandomStockSupplier() {
            public List<Stock> get() {
                return new ArrayList<>();
            }
        };
        this.stocks = supplier.loadStock(12, 10, 20);
    }
    public String showStocks() {
        return stocks.stream()
                .map(Stock::toString)
                .collect(Collectors.joining("\n"));
    }
    public double averagePrice() {
        if(stocks.isEmpty()) {
            return 0.0;
        }
        double sum = 0.0;
        int count = 0;
        for (Stock stock : stocks) {
            sum += stock.getPrice();
            count++;
        }
        return sum / count;
    }
    public void writeSerializable(File file) {
        try (ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(file))) {
            outputStream.writeObject(stocks);
        } catch (IOException e) {
            e.fillInStackTrace();
            System.out.println("Cannot serialise in file: " + e.getMessage());
        }
    }
    public List<String> sortStockByReorderQtyAndID() {
        return stocks.stream()
                .sorted(Comparator.comparing((Stock s) -> s.getReorderData().getReorderQty()).reversed()
                        .thenComparing(Stock::getID))
                .map(s -> "Reorder quantity " + s.getReorderData().getReorderQty() + ", Stock ID " + s.getID() + "\n")
                .collect(Collectors.toList());
    }
    public String groupByReorderQtyAndNumberSuppliers() {
        Map<Integer, Integer> maxSuppliersByReorderQty = stocks.stream()
                .collect(Collectors.groupingBy(stock -> stock.getReorderData().getReorderQty(),
                        Collectors.mapping(stock -> stock.getReorderData().getSuppliers().size(),
                                Collectors.collectingAndThen(Collectors.maxBy(Integer::compareTo), opt -> opt.orElse(0)))));

        StringBuilder result = new StringBuilder();
        maxSuppliersByReorderQty.forEach((reorderQty, maxSuppliers) ->
                result.append("ReorderQty: ").append(reorderQty)
                        .append(", Max Suppliers: ").append(maxSuppliers)
                        .append("\n"));

        return result.toString();
    }
    public static void main(String[] args) {
        StockManagement stockManagement = new StockManagement();
        //System.out.println(stockManagement.showStocks());
        //System.out.println("Average price: " + stockManagement.averagePrice());
        //stockManagement.writeSerializable(new File("stocks.ser"));
        //System.out.println(stockManagement.sortStockByReorderQtyAndID());
        System.out.println(stockManagement.groupByReorderQtyAndNumberSuppliers());
    }
}
