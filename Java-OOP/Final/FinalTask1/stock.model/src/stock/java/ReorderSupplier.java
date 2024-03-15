package stock.java;

import java.util.List;
public class ReorderSupplier {
        private final int reorderQty;
        private final List<String> suppliers;

        ReorderSupplier(int reorderQty, List<String> suppliers) {
            this.reorderQty = reorderQty;
            this.suppliers = suppliers;
        }

        public int getReorderQty() {
            return reorderQty;
        }
        public List<String> getSuppliers() {
            return suppliers;
        }
}
