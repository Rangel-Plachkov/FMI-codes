
import java.rmi.*;
import java.rmi.registry.*;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class MyServer {
    public static void main(String[] args) {

        try {
            SudokuGenerator stub = new SudokuGenerator();
            Registry registry = LocateRegistry.createRegistry(1099);
            registry.bind("MyRemoteObject", stub);

            System.out.println("Server is ready");

            //registry.unbind("MyRemoteObject");

            //UnicastRemoteObject.unexportObject(stub, true);

        } catch (Exception e) {
                //System.out.println(e);
        }
    }
}
