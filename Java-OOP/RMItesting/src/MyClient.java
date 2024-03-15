import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
public class MyClient {
    public static void main(String[] args) {
        try {
            Registry registry = LocateRegistry.getRegistry("localhost", 1099);

            genCl remoteObject = (genCl) registry.lookup("MyRemoteObject");

            SudokuPuzzle temp = remoteObject.getPuzzle(32);

            System.out.println("Puzzle:");
            temp.printPuzzle();

            temp.printSolution();

            remoteObject.cleanUp();



            //System.out.println(stub.add(34,4));
        } catch (Exception e) {
            System.out.println(e);
        }finally {

            //System.out.println("Client is ready");
        }
    }
}
