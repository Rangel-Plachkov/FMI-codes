package models;

@SuppressWarnings("UnusedDeclaration")
public class Racer {
    private static final String DEFAULT_NAME = "Unknown";
    private static final Integer DEFAULT_AGE = 0;
    private static Integer nextID = 0;
    private Integer ID;
    private String firstName;
    private String lastName;
    private Integer age;

    public static void main(String[] args) {
        Racer racer1 = new Racer();
        racer1.setID();
        Racer racer2 = new Racer("John", "Doe", 25);
        racer2.setID();
        System.out.println(racer1);
        System.out.println(racer2);
    }

    public Racer() {
        setFirstName(DEFAULT_NAME);
        setLastName(DEFAULT_NAME);
        setAge(DEFAULT_AGE);
    }
    public Racer(String firstName, String lastName, Integer age) {
        setFirstName(firstName);
        setLastName(lastName);
        setAge(age);
    }
    public void setID() {
        ID = nextID;
        nextID++;
    }
    public Integer getID() {
        return ID;
    }
    public void setAge(Integer age) {
        this.age = (age > DEFAULT_AGE ? age : DEFAULT_AGE);
    }
    public Integer getAge() {
        return age;
    }
    public void setFirstName(String firstName) {
        this.firstName = convertToValidName(firstName);
    }
    public String getFirstName() {
        return firstName;
    }
    public void setLastName(String lastName) {
        this.lastName = convertToValidName(lastName);
    }
    public String getLastName() {
        return lastName;
    }
    private static String convertToValidName(String input) {
        if(input == null || input.isEmpty()) {
            return DEFAULT_NAME;
        }
        return input;
    }
    @Override
    public String toString() {
        return String.format("models.Racer %d: %s %s, %d years old", ID, firstName, lastName, age);
    }

}
