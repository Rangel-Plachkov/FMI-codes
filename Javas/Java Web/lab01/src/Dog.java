public class Dog implements Comparable{
    private String name;
    private int weight;

    public Dog(String name, int weight) {
        this.name = name;
        this.weight = weight;
    }
    int getWeight() {
        return weight;
    }
    String getName() {
        return name;
    }
    @Override
    public int compareTo(Object o) {
        return Integer.compare(this.weight, ((Dog) o).weight);
    }

}
