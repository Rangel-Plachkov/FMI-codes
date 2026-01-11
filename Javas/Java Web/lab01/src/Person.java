public class Person {
    private String name;
    private int age;
    private final String DEFAULT_NAME = "No name";
    private final int DEFAULT_AGE = -1;

    public Person() {
        name = DEFAULT_NAME;
        age = DEFAULT_AGE;
    }
    public Person(String name) {
        this.name = name;
        age = DEFAULT_AGE;
    }
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setAge(int age) {
        this.age = age;
    }
    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}
